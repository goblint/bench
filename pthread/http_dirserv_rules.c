/*
 * Handle reading and parsing of rule file.
 *
 *    int htds_parse_elements ( int limit, char *line, string *elements );
 *    int htds_read_rules ( char *rule_file );
 *    int htds_get_rules ( void *control_file, dir_opt *options );
 *
 * Author: David Jones
 * Date: 1-DEC-1994
 * Revised: 5-SEP-1995		cleanup for use in MST directory server
 */
#include "pthread_1c_np.h"
#include "ctype_np.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/* #include "decnet_searchlist.h" */
#include "tutil.h"
#include "file_access.h"
#include "dirserv_options.h"
#define ERROR_FAIL(s,text) if (s == -1) perror(text);

#ifdef DYNAMIC_MST
#include "mst_share.h"
#else
int http_log_level, tlog_putlog();	/* Global variable, logger detail level */
#endif

typedef struct { int l; char *s; } string;
char **http_index_filename;		/* Filename for index files */

static int index_file_alloc=0, index_file_count = 0;
static pthread_once_t dir_rules_setup = PTHREAD_ONCE_INIT;
static pthread_mutex_t opt_ctl;
static char *default_index_file[] = { "index.html", "index.htmlx", "" };
static dir_opt default_options, global_options;
static int load_rules ( int mask, void *first, dir_opt *options );
static int preprocess_rule ( int count, int limit, string *elem );
/***********************************************************************/
/*
 * Parse line into whitespace-delimited tokens, trimming leading and trailing
 * whitespace.  Each token parse is explicitly null-terminataed.  Function 
 * value returned is number of elements found.  May be 1 more than limit if 
 * last element does not end line.
 */
int htds_parse_elements (
	int limit,	    /* Max number of element to delimit */
	char *line,	    /* input line to parse */
	string *elem )	    /* Output array. */
{
    int tcnt, in_token, length, i;
    char *ptr;
    /* Delimit up to three tokens */
    for ( in_token = tcnt = length = 0, ptr = line; *ptr; ptr++ ) {
	if ( in_token ) {
	    if ( isspace ( *ptr ) ) {
		/* End current token */
		*ptr = '\0';  /* terminate string */
		elem[tcnt++].l = length;
		in_token = 0;
	    }
	    else length++;
	} else {
	    if ( !isspace ( *ptr ) ) {
		/* start next token */
		if ( tcnt >= limit ) {
		    /* more tokens than expected */
		    tcnt++;
		    break;
		}
		elem[tcnt].s = ptr;
		in_token = 1;
		length = 1;
	    }
        }
    }
    /*
     * Make final adjust to element count and make remaining elment null.
     */
    if ( in_token ) { elem[tcnt++].l = length; }
    for ( i = tcnt; i < limit; i++ ) { elem[i].l = 0; elem[i].s = ptr; }
    return tcnt;
}
/***********************************************************************/
/* Read next line from nested stack of input file.
 */
static char *read_nested ( char *line, int linesize, void **fp, int *sp )
{
    int length;
    for ( ; ; ) {
	length = tf_getline ( fp[*sp], line, linesize-1, 1 );
	if ( length > 0 ) { line[length] = '\0'; return line; }
	/*
	 * Read error, return error if at top of stack, otherwise pop file
	 */
	if ( *sp == 0 ) return (char *) 0;
	tf_close ( fp[*sp] );
	*sp = *sp - 1;
    }
}
/***********************************************************************/
/*  Append filename to list of index files (welcome pages) to search for
 *  when doing directory listings.
 */
static void add_index_file ( char *fname )
{
    /*  Allocate enough for all names plus a null */
    if ( index_file_count+2 >= index_file_alloc ) {
	index_file_alloc += 20;
	if ( index_file_alloc == 20 ) 		/* first call */
	    http_index_filename = (char **) malloc ( sizeof(char *)*index_file_alloc );
	else
	    http_index_filename = (char **) realloc ( http_index_filename, 
		sizeof(char *)*index_file_alloc );

	if ( !http_index_filename ) {
	   tlog_putlog ( 0, "error allocating index file list!/");
	   index_file_alloc = 0;
	   http_index_filename = default_index_file;
	   return;
	}
    }
    /*
     * Copy string and append to list.  Mark end of list with null.
     */
    http_index_filename[index_file_count] = malloc (tu_strlen(fname)+1);
    tu_strcpy ( http_index_filename[index_file_count], fname );
    index_file_count++;
    http_index_filename[index_file_count] = "";
}
/***********************************************************************/
/* One-time setup for module.
 */
static void init_globals() {
    int status;
    /*
     * Initialize DECthreads objects.
     */
    status = INITIALIZE_MUTEX ( &opt_ctl );
    ERROR_FAIL(status,"Error creating tcp_io mutex" )
    /*
     * Initialize global variables.
     */
    http_index_filename = default_index_file;
    /*
     * Initialize default options.
     */
    default_options.access = 0;
    default_options.readme = 1;		/* Insert at top */
    default_options.showminlength = 15;
    default_options.showmaxlength = 80;
    default_options.showicons = 0;
    default_options.showdate = 1;
    default_options.showsize = 1;
    default_options.showbytes = 0;
    default_options.showdescription = 0;
    default_options.showhtmltitles = 0;
    default_options.descriptionlength = 40;
    default_options.showbrackets = 1;
    default_options.showhidden = 1;
    default_options.showowner = 0;
    default_options.showgroup = 0;
    default_options.showprot = 0;
    default_options.addhref = 0;
    tu_strnzcpy ( default_options.control_file, ".www_browsable", 80 );
    tu_strnzcpy ( default_options.readme_file, "README.", 80 );
    default_options.iconpath = "";
    default_options.iconblank = "";
    default_options.iconunknown = "";
    default_options.icondir = "";
    default_options.iconparent = "";
}
/***********************************************************************/
/*
 * Initialize rules and load rules database from file.
 */
int htds_read_rules ( char *rule_file )
{
    void *rf;
    string token[8];
    char errmsg[512];
    int length, status;
    dir_opt dummy;
    /*
     * Initialize module.  The opt_ctl mutex protects the global variables.
     */
    pthread_once ( &dir_rules_setup, init_globals );
    pthread_mutex_lock ( &opt_ctl );
    global_options = default_options;
    pthread_mutex_unlock ( &opt_ctl );
    if ( http_log_level > 1 ) tlog_putlog ( 2,
	"Set global options: '!AZ' '!AZ'!/", global_options.control_file,
		default_options.control_file );
    /*
     * See if rule file specified.
     */
    if ( !(*rule_file) ) {
	tlog_putlog ( 0, "No rule file specified, abort.!/" );
	return 20;
    } else {
	if ( http_log_level > 1 ) tlog_putlog ( 0,
		"Loading configuration/rules file !AZ!/", rule_file );
	rf = tf_open ( rule_file, "r", errmsg );
	if ( rf ) {
	    /*
	     * We found file, load into dummy struct and do atomic copy
	     * into global structure.
	     */
	    dummy = default_options;
	    status = load_rules ( 0, rf, &dummy );

	    pthread_mutex_lock ( &opt_ctl );
	    global_options = dummy;
	    pthread_mutex_unlock ( &opt_ctl );

	} else {
	    tlog_putlog ( 0, "Error opening rule file: !AZ!/", errmsg );
	    status = 20;
	}
    }
    return status;
}
/***********************************************************************/
/* Copy globals into callers argument
 */
int htds_get_rules ( void *rf, dir_opt *options ) {
    int status;
    pthread_once ( &dir_rules_setup, init_globals );
    if ( rf ) {
	status = load_rules ( 1, rf, options );
    } else {
	pthread_mutex_lock ( &opt_ctl );
	*options = global_options;
	pthread_mutex_unlock ( &opt_ctl );
	status = 1;
    }
    return status;
}
/***********************************************************************/
/* Internal routine to check parsed tokens for boolean switch values.
 * Return value is non-zero if a match!
 */
static int check_on_off ( string token[8],	/* parsed command line */
    char *name, int *outval )
{
    if ( tu_strncmp ( token[0].s, name, 40 ) == 0 ) {
	tu_strupcase ( token[1].s, token[1].s );
	if ( tu_strncmp ( token[1].s, "OFF", 4 ) == 0 ) {
	    *outval = 0;
	} else if ( tu_strncmp ( token[1].s, "ON", 3 ) == 0 ) {
	    *outval = 1;
	} else {
	    tlog_putlog (0, 
		"Bad value for !AZ directive!/", name );
	}
	return 1;
    }
    return 0;
}
/***********************************************************************/
/* Internal routine to process config files and browser control files.
 * If mask is true, restricted subset recognized.
 */
static int load_rules ( int mask, void *first, dir_opt *options ) {
    void *rf[20];
    string token[8];
    char line[512], tline[512], fname[256];
    int length, count, colon, lnum[20], pass_count, sp;
    /*
     * Process rule file lines, read_nested reads the next line from the
     * file at the top of the include file stack.
     */
    rf[0] = first;
    sp = lnum[0] = 0;
    while ( read_nested ( line, sizeof(line)-1, rf, &sp ) ) {
	/*
	 * Trim line of comments and line-feed and parse into tokens.
	 */
	lnum[sp]++;			/* track position in file */
	for ( length = 0; (line[length] != '#') && line[length] &&
	    (line[length] != '\n'); length++ ) tline[length] = line[length];
	if ( length > 0 ) if ( tline[length-1] == '\r' ) --length;
	tline[length] = line[length] = '\0';
	if ( length > 0 ) count = htds_parse_elements ( 7, tline, token );
	else count = 0;
	/*
	 * Process record based upon first token.
	 */
	if ( count > 0 ) {
		tu_strupcase ( token[0].s, token[0].s );
	        while ( (count > 0) && (token[0].s[0] == '.') ) {
		    /* Rescan line */
		    count = preprocess_rule ( count, 7, token );
		}
	}
	if ( count <= 0 ) {
		/* Ignore null line */
	} else if ( !mask && 	/* Don't allow includes on control files */
			(tu_strncmp ( token[0].s, "INCLUDE", 10 ) == 0 )) {
		if ( count < 2 ) {
		    tlog_putlog ( 0, "Missing filename in Include rule!/" );
		} else if ( sp > 18 ) {
		    tlog_putlog ( 0, "Nesting level too deep to include file!/");
		} else {
		    lnum[++sp] = 0;
		    if ( !(rf[sp] = fopen ( 
				token[1].s, "r", "mbc=64", "dna=.conf" )) ) {
			tlog_putlog ( 0, "Error openning include file '!AZ'!/",
				token[1].s );
			--sp;
		    }
		}	
	} else if ( !mask &&
			tu_strncmp ( token[0].s, "TRACELEVEL", 10 ) == 0 ) {
#ifndef DYNAMIC_MST
		char temp[300]; int status, tlog_initlog();
		if ( count < 2 ) {
		    tlog_putlog ( 0, "Missing argument for TraceLevel rule!/" );
		    http_log_level = 1;
		} else {
		    tu_strnzcpy ( temp, token[1].s, token[1].l );
		    if ( (temp[0] < '0') || (temp[0] > '9') ) {
			char *val = getenv(temp);
			if ( !val ) tlog_putlog(0,
			    "Invalid variable name in TraceLevel rule: '!AZ'!/",
			    temp );
			tu_strcpy ( temp, val ? val : "1" );
		    }
		    http_log_level = atoi ( temp );
		}
		tu_strnzcpy ( temp, token[2].s, token[1].l );
		status = tlog_initlog ( http_log_level, temp );
		if ( (status&1) == 0 ) tlog_putlog ( 0, 
			"Error opening trace log file, '!AZ'!/", temp );
		else tlog_putlog ( 0, "Opened trace file, '!AZ', level: !SL!/",
			temp, http_log_level );
#endif

	} else if ( tu_strncmp ( token[0].s, "WELCOME", 8 ) == 0 ) {
		if ( (index_file_alloc == 0) || (token[1].l > 0) ) {
		    add_index_file ( token[1].s );
		    if ( token[1].l == 0 ) {
			free ( http_index_filename[0] );
			http_index_filename[0] = "";
			tlog_putlog (1,"Disabled search for WELCOME files.!/" );
		    }
		} else {
		   tlog_putlog ( 0, 
		   "Missing filename on WELCOME directive, line !SL of rule file!/",
			lnum[sp] );
		}
	} else if ( tu_strncmp ( token[0].s, "DIRACCESS", 10 ) == 0 ) {
		tu_strupcase ( token[1].s, token[1].s );
		if ( tu_strncmp ( token[1].s, "OFF", 4 ) == 0 ) {
		    options->access = -1;	/* Fully restricted (none) */
		} else if ( tu_strncmp ( token[1].s, "ON", 3 ) == 0 ) {
		    options->access = 0;
		} else if ( tu_strncmp ( token[1].s, "SELECTIVE", 10 ) == 0 ) {
		    options->access = 1;
		    if ( (token[2].l > 0) && !mask ) {
		 	/* Override filename that flags browsable directories */
			tu_strnzcpy(options->control_file,token[2].s,
				token[2].l < sizeof(options->control_file) ?
				token[2].l : sizeof(options->control_file) );
			tu_strupcase ( token[3].s, token[3].s );
			if ( tu_strncmp(token[3].s,"OVERRIDE", 9 ) == 0 ) {
			    options->access = 2;
			} else if ( token[3].l > 0 ) {
			    tlog_putlog(0, "Bad option for DirAccess Select!/");
		        }
		    }
		} else {
		    tlog_putlog (0, 
			"Bad value for DirAccess directive, line !SL of rule file!/",
			lnum[sp] );
		}
	} else if ( tu_strncmp ( token[0].s, "DIRREADME", 10 ) == 0 ) {
		tu_strupcase ( token[1].s, token[1].s );
		if ( tu_strncmp ( token[1].s, "OFF", 4 ) == 0 ) {
		    options->readme = 0;	/* Dont include readme file */
		} else if ( tu_strncmp ( token[1].s, "TOP", 4 ) == 0 ) {
		    options->readme = 1;
		} else if ( tu_strncmp ( token[1].s, "BOTTOM", 7 ) == 0 ) {
		    options->readme = 2;
		} else {
		    options->readme = 0;
		    tlog_putlog (0, 
			"Bad value for DirReadme directive, line !SL of rule file!/",
			lnum[sp] );
		}
		if ( options->readme > 0 ) {
		    /*
		     * Check for optional argument, readme filename.
		     */
		    if ( (token[2].l > 0) ) {
			tu_strnzcpy(options->readme_file,token[2].s,
				token[2].l < sizeof(options->readme_file) ?
				token[2].l : sizeof(options->readme_file) );
		    }
		}
	} else if (check_on_off(token, "DIRSHOWDATE",&options->showdate)) {
	} else if (check_on_off(token, "DIRSHOWSIZE",&options->showsize)) {
	} else if (check_on_off(token, "DIRSHOWBYTES",&options->showbytes)) {
	} else if (check_on_off(token, "DIRSHOWHIDDEN", &options->showhidden)) {

	} else if ( !mask ) {
	    tlog_putlog (0, "Unrecognized data, line !SL of rule file: !AZ!/",
			lnum[sp], line );
	}
    }
    while ( sp >= 0 ) tf_close ( rf[sp--] );
    return 1;
}
/*****************************************************************************/
/* Handle preprocessor operations, rewriting element list.
 * Directives:
 *    .DEFINE symbol elem1 [elem2 [elem3...]]
 *    .EXPAND [string|$symbol] ...
 *    .IGNORE directive [directive [directive...]]
 *    .ITERATE [string|$dummyarg] ...
 *     .NEXT arg ...
 *
 * Function value returned is new size of resulting list or -1 for error.
 */
static int preprocess_rule ( int count, int limit, string *elem )
{
    struct keydef {
	struct keydef *next;
	int count;
        string elem[1];
    } *sym;
    static struct keydef *symlist = (struct keydef *) 0;
    static struct keydef *ignore_list = (struct keydef *) 0;
    static work_limit = 0, pattern_count = 0;
    static string *work_elem, *pattern;
    int i, j, k;

    if ( limit > work_limit ) {
	if ( http_log_level > 14 ) tlog_putlog(14,
		"Expanding pre-processor work list to !SL!/", limit );
	if ( work_limit == 0 ) work_elem = malloc(sizeof(string)*limit);
	else work_elem = realloc(work_elem,sizeof(string)*limit);
	if ( work_limit == 0 ) pattern = malloc(sizeof(string)*limit);
	else work_elem = realloc(pattern,sizeof(string)*limit);
	work_limit = limit;
    }

    if ( (count > 1 ) && (tu_strncmp(elem[0].s,".DEFINE", 8) == 0) ) {
	/*
	 * make duplicate of elem list and add to symbol table.
	 */
	tu_strupcase ( elem[1].s, elem[1].s );
	sym = (struct keydef *) malloc ( sizeof(struct keydef) +
		sizeof(string)*count-2 );
	sym->next = symlist;
	symlist = sym;
	sym->count = count-1;

	for ( i = 0; i < count-1; i++ ) {
	    sym->elem[i].l = elem[i+1].l;
	    sym->elem[i].s = (char *) malloc ( elem[i+1].l + 1 );
	    tu_strcpy ( sym->elem[i].s, elem[i+1].s );
	}
	return 0;
    } else if ( tu_strncmp(elem[0].s,".EXPAND",8) == 0 ) {
	/*
	 * Copy elements to temporary work array.
	 *   i - input index, j - output index.
	 */
	for ( i =1, j = 0; i < count; i++ ) {
	    if ( elem[i].s[0] == '$' ) {
		/*
		 * String following $ is symbol name to match.
		 */
		tu_strupcase(elem[i].s, elem[i].s);
		for ( sym = symlist; sym; sym = sym->next ) {
		    if ( tu_strncmp(sym->elem[0].s, &elem[i].s[1],
				sym->elem[0].l) == 0 ) {
			if ( '\0' == elem[i].s[1+sym->elem[0].l] ) break;
		    }
		}
		if ( !sym ) {
		    tlog_putlog(0, "Undefined symbol in expansion: !AZ!/",
			elem[i].s );
		    return -1;		/* error */
		}
		/*
		 * append to output, null definition terminates expansion
		 */
		if ( sym->count < 1 ) break;
		if ( sym->elem[1].l <= 0 ) break;
		for ( k = 1; k < sym->count; k++ ) {
		    work_elem[j++] = sym->elem[k];
		}
	    } else {
		/* Copy element with no expansion */
		work_elem[j++] = elem[i];
	    }
	}
	/*
	 * Copy result back, re-upcase first token.
	 */
	for ( i = 0; i < j; i++ ) elem[i] = work_elem[i];
	if ( j > 0 ) tu_strupcase ( elem[0].s, elem[0].s );
	for ( i = j; i < limit; i++ ) elem[j].l = 0;

	if ( http_log_level > 14 ) {
	   tlog_putlog(14,"Pre-processor expansion:" );
	    for ( i = 0; i < j; i++ ) tlog_putlog(14," '!AZ'", elem[i].s );
	    tlog_putlog(14,"!/");
	}
	return j;
    } else if ( tu_strncmp(elem[0].s,".NEXT",8) == 0 ) {
	/*
	 * Build work array drawing each element from pattern.
	 */
	for ( j = 0, i = 1; j < pattern_count; j++ ) {
	    if ( pattern[j].s[0] == '$' ) {
		/* Truncate pattern if null element */
		if ( i >= count ) break;
		work_elem[j] = elem[i++];
	    } else {
		work_elem[j] = pattern[j];
	    }
	}
	/*
	 * Copy result back, re-upcase first token.
	 */
	for ( i = 0; i < j; i++ ) elem[i] = work_elem[i];
	if ( j > 0 ) tu_strupcase ( elem[0].s, elem[0].s );
	for ( i = j; i < limit; i++ ) elem[j].l = 0;

	if ( http_log_level > 14 ) {
	   tlog_putlog(14,"Pre-processor iteration:" );
	    for ( i = 0; i < j; i++ ) tlog_putlog(14," '!AZ'", elem[i].s );
	    tlog_putlog(14,"!/");
	}
	return j;
    } else if ( tu_strncmp(elem[0].s,".ITERATE",8) == 0 ) {
	/*
	 * Save elements in pattern buffer.
	 */
	pattern_count = count - 1;
	for ( i = 0; i < pattern_count; i++ ) {
	    pattern[i].l = elem[i+1].l;
	    pattern[i].s = (char *) malloc ( elem[i+1].l + 1 );
	    tu_strcpy ( pattern[i].s, elem[i+1].s );
	}
tlog_putlog(15,"/rule_file/ Iterate's pattern count: !SL!/", pattern_count );
	return 0;
    } else if ( tu_strncmp(elem[0].s,".IGNORE",8) == 0 ) {
	/*
	 * Append symbols to ignore_list.
	 */
	tu_strupcase ( elem[1].s, elem[1].s );
	sym = (struct keydef *) malloc ( sizeof(struct keydef) +
		sizeof(string)*count-1 );
	sym->next = ignore_list;
	ignore_list = sym;
	sym->count = count-1;

	for ( i = 0; i < count-1; i++ ) {
	    sym->elem[i].l = elem[i+1].l;
	    sym->elem[i].s = (char *) malloc ( elem[i+1].l + 1 );
	    tu_strupcase ( sym->elem[i].s, elem[i+1].s );
	}
	return 0;
    } else {
	/*
	 * See if directive was on one of the ignore lists and return 0 if
	 * found, which effectively ignores the line.
	 */
	for ( sym = ignore_list; sym; sym = sym->next ) {
	    for ( i = 0; i < sym->count; i++ ) {
		if ( 0 == tu_strncmp ( elem[0].s, sym->elem[i].s,
			sym->elem[i].l+1 ) ) return 0;
	    }
	}
	return -1;		/* unknown directive */
    }
    return count;
}
