#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <regex.h>
#include <sys/types.h>
#include <dirent.h>


/*
 *
 *  you have the power ;-)
 *  stuff to play with
 *
 */

// fuzzy user-visible crap
char figfile[255]    = "/home/groups/m/mu/multiseek/multiseek.ini";
char filthmhome[255] = "/home/groups/m/mu/multiseek/htdocs/demo/themes/";
char webrelhome[255] = "/demo";
char webabshome[255] = "http://multiseek.sourceforge.net/demo/";

// config file defaults
char def_agent[48]   = "Mozilla/4.0 (compatible; MSIE 5.01; Windows 98)";
char def_name[8]     = "Unknown";
char def_prot[5]     = "http";
int  def_port        = 80;
int  def_link        = 0;
char def_theme[11]   = "beachfence";



/*
 *
 *  universal structures 
 *
 */

struct engine {
  char tag[256];
  char name[512];
  char home[512];
  char proto[32];
  char host[512];
  int port;
  char referer[512];
  char cgistring[BUFSIZ];
  char res_list_start[256];
  char res_item_start[256];
  char res_item_stop[256];
  char res_list_stop[256];
  int link_order[6];
  char link_href_start[256];
  char link_href_stop[256];
  char link_text_start[256];
  char link_text_stop[256];
  char link_desc_start[256];
  char link_desc_stop[256];
  char link_size_start[256];
  char link_size_stop[256];
  char link_rela_start[256];
  char link_rela_stop[256];
  struct engine *next;
  unsigned int lnkcount;
  unsigned int dupcount;
};

struct themed {
  char name[256];
  struct themed *next;
};

struct result {
  char href[BUFSIZ];
  char text[BUFSIZ];
  char desc[BUFSIZ];
  char size[BUFSIZ];
  char rela[BUFSIZ];
  char engt[256];
  struct result *next;
};

char ascii[257] = "       \a\b\t\n\v\f\r                   !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVQXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~                                                                                                                                  ";


/*
 *
 *  universal variables
 *
 */ 

struct engine *engine_ptr;
struct themed *themed_ptr;
struct result *result_ptr;

int HREF=1;
int TEXT=2;
int DESC=3;
int SIZE=4;
int RELA=5;
int KILL=7;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

unsigned int totalcount;
unsigned int duplicount;
unsigned int resltcount;

char html_taggo[2] = "<";
char html_tagwo[2] = ">";

int debug = 0;

char vernam[128]     = "multiseek";
char vernum[6]       = "0.97";


/*
 *
 *  and some buffers
 *
 */

char searchraw[BUFSIZ];
char searchtxt[BUFSIZ];
char theme[BUFSIZ];
char config[BUFSIZ];
char buf[BUFSIZ];
char agent[BUFSIZ];




int parseline(char *line)
{
	char *dup = strdup(line);
	char *s = dup;
	char *src, *dst;
	char *w, *a, *c;
	char *ptr;
	int dif = 0;
	int ord = 0;
	struct engine *Engine;
	struct conf *cfg, *x;
	int n = -1;

	/*
	 *	Remove the trailing newline.
	 */

	for(w = s; *w; w++)
		;
	while(--w >= s && *w == '\n')
		*w = 0;

	/*
	 *	Get word (w), command (c) and argument (a).
	 */

	while(isspace(*s)) s++;
	w = s;
	while(*s && !isspace(*s)) s++;
	if (*w == 0) {
parseline_error:
		free(dup);
		return -1;
	}
	if (*s) *s++ = 0;
	while(isspace(*s)) s++;
	a = s;

	/*
	 *	Restore pneumonics \r\n etc ..
	 */

	src = s;

	while (*src != '\0') {
		dst = src - dif;
		if(*src == '\\') {
			src++;
			if(*src == 'n') {
				*dst = '\n';
				dif++;
			} else if(*src == 'r') {
				*dst = '\r';
				dif++;
			} else if(*src == '\\') {
				*dst = '\\';
				dif++;
			} else if(*src == 'f') {
				*dst = '\f';
				dif++;
			} else if(*src == 'v') {
				*dst = '\v';
				dif++;
			} else if(*src == 't') {
				*dst = '\t';
				dif++;
			} else if(*src == 'b') {
				*dst = '\b';
				dif++;
			} else if(*src == 'a') {
				*dst = '\a';
				dif++;
			} else {
				src--;
				*dst = *src;
			}
		} else {
			*dst = *src;
		}
		src++;
	}
	dst = src - dif;
	while (dif > 0) {
		*dst = '\0';
		dst++;
		dif--;
	}


	if ((c = strchr(w, '.')) == NULL || c[1] == 0)
		goto parseline_error;
	*c++ = 0;

	// printf("Word [%s], Command [%s], Argument [%s]\n", w, c, a);


	/*
	 *	See what class of command this is.
	 */
	Engine = engine_ptr;
	if (strcmp(w, "new") == 0) {

		if (strcmp(c, "engine") == 0) {
			while (Engine->next != NULL) {
				Engine = Engine->next;
			}
			strcpy(Engine->tag, a);

			// establish engine defaults
			strcpy(Engine->name,  def_name);
			strcpy(Engine->proto, def_prot);
			Engine->port = def_port;
			ord=0;
			while(ord<6) {
				Engine->link_order[ord] = def_link;
				ord++;
			}
			ord=0;
		
			Engine->next = (struct engine *) malloc(sizeof(struct engine));
			Engine = Engine->next;
		}

	} else if (strcmp(w, "set") == 0) {

		if (strcmp(c, "agent") == 0) {
			strcpy(agent, a);
		}

	} else if (strlen(w)==0) {
		goto parseline_error;

	} else {
		while (strcmp(Engine->tag, w) != 0) {
			if(Engine->next == NULL) goto parseline_error;
			Engine = Engine->next;
		}

		if (strcmp(c, "label") == 0) {
			strcpy(Engine->name, a);

	        } else if (strcmp(c, "home") == 0) {
			strcpy(Engine->home, a);

	        } else if (strcmp(c, "search_prot") == 0) {
			strcpy(Engine->proto, a);

	        } else if (strcmp(c, "search_host") == 0) {
			strcpy(Engine->host, a);
			if(strlen(Engine->home) == 0) {
				strcpy(Engine->home, a);
			}

	        } else if (strcmp(c, "search_port") == 0) {
			Engine->port = atoi(a);

	        } else if (strcmp(c, "search_path") == 0) {
			strcpy(Engine->cgistring, a);

	        } else if (strcmp(c, "search_refr") == 0) {
			strcpy(Engine->referer, a);

	        } else if (strcmp(c, "list_start") == 0) {
			strcpy(Engine->res_list_start, a);

	        } else if (strcmp(c, "item_start") == 0) {
			strcpy(Engine->res_item_start, a);

	        } else if (strcmp(c, "item_stop") == 0) {
			strcpy(Engine->res_item_stop, a);

	        } else if (strcmp(c, "list_stop") == 0) {
			strcpy(Engine->res_list_stop, a);

	        } else if (strcmp(c, "item_structure") == 0) {
			ord=0;
			while (*a != '\0') {
				if(*a == 'h') {
					Engine->link_order[ord]  = HREF;
					ord++;
				} else if (*a == 't') {
					Engine->link_order[ord]  = TEXT;
					ord++;
				} else if (*a == 'd') {
					Engine->link_order[ord]  = DESC;
					ord++;
				} else if (*a == 's') {
					Engine->link_order[ord]  = SIZE;
					ord++;
				} else if (*a == 'r') {
					Engine->link_order[ord]  = RELA;
					ord++;
				}
				a++;
			}

	        } else if (strcmp(c, "link_href_start") == 0) {
			strcpy(Engine->link_href_start, a);

	        } else if (strcmp(c, "link_href_stop") == 0) {
			strcpy(Engine->link_href_stop, a);

	        } else if (strcmp(c, "link_text_start") == 0) {
			strcpy(Engine->link_text_start, a);

	        } else if (strcmp(c, "link_text_stop") == 0) {
			strcpy(Engine->link_text_stop, a);

	        } else if (strcmp(c, "link_desc_start") == 0) {
			strcpy(Engine->link_desc_start, a);

	        } else if (strcmp(c, "link_desc_stop") == 0) {
			strcpy(Engine->link_desc_stop, a);

	        } else if (strcmp(c, "link_size_start") == 0) {
			strcpy(Engine->link_size_start, a);

	        } else if (strcmp(c, "link_size_stop") == 0) {
			strcpy(Engine->link_size_stop, a);

	        } else if (strcmp(c, "link_rela_start") == 0) {
			strcpy(Engine->link_rela_start, a);

	        } else if (strcmp(c, "link_rela_stop") == 0) {
			strcpy(Engine->link_rela_stop, a);

		} else {
			goto parseline_error;
		}
	}

	return 0;
}


int readcfg(int what)
{
	FILE *fp;
	char buf[2048];
	int lineno = 0;
	char *s, *p;

	if ((fp = fopen(figfile, "r")) == NULL) {
		printf("%s: unable to open.", figfile);
		return -1;
	}
	// set global defaults
	strcpy(agent, def_agent);

	p = buf;
	while(fgets(p, sizeof(buf) - (p - buf), fp)) {
		if(what == 1) {
			printf("%s", p);
		} else {
			lineno++;
			if (p[0] == '#' || p[0] == '\n') continue;
			s = p + strlen(p);
			if (s > p && *--s == '\n' && *--s == '\\') {
				p = s;
				continue;
			}
			if (buf[0] == '\n' || buf[0] == 0) {
				p = buf;
				continue;
			}
			if (parseline(buf) < 0) {
				printf("%s[%d]: syntax error\n", figfile, lineno);
			}
			p = buf;
		}
	}
	return 0;
}


void get_query(void)
{
	char *cp, querystring[BUFSIZ];
	char *st, submittype[BUFSIZ];
	char *src, *dst;
	char *vargo;
	char *valgo;
	char hexval[3];
	char *hexptr = hexval;
	int hexidx;
	int term = 0;


	/*
	 *  GET or POST - needed to avoid ?var=val overrides
	 */
	if (st = getenv("REQUEST_METHOD")) {
		strcpy(submittype, st);
	}
	st = submittype;

	if (strcmp(st, "GET") == 0) {
		if (cp = getenv("QUERY_STRING")) {
			strcpy(querystring, cp);
		}
	} else {
		fgets(querystring, BUFSIZ, stdin);
	}

	cp = querystring;
	vargo = querystring;

	while (term != 1) { 
		if(*cp == '=' ) {
			*(cp) = '\0';
			valgo = cp + 1;
		} else if(*cp == '&' || *cp == '\0' ) {
			if(*cp == '\0') term++;
			*(cp) = '\0';
			if(strcmp(vargo, "theme") == 0 && strlen(valgo) > 0) {
				strcpy(theme, valgo);

			} else if(strcmp(vargo, "debug") == 0 && strlen(valgo) > 0) {
				debug = atoi(valgo);

			} else if(strcmp(vargo, "config") == 0 && strlen(valgo) > 0) {
				strcpy(config, valgo);

			} else if(strcmp(vargo, "query") == 0) {
				memset(searchraw, 0, sizeof(searchraw));
				memset(searchtxt, 0, sizeof(searchtxt));
				strcpy(searchraw, valgo);
				src = searchraw;
				dst = searchtxt;
				while (*src != '\0') {
					if (*src == '+') {
						*dst = ' ';
					} else if (*src == '%') {
						src++;
						strncpy(hexval, src, 2);
  						hexidx = strtol(hexval, (char **)NULL, 16);
						*dst = *(ascii + hexidx);
						*src++;
					} else {
						*dst = *src;
					}
					src++;
					dst++;
				}
				dst = '\0';
			}
			vargo = cp + 1;
		}
		cp++;
	}

	if(strlen(theme)==0) strcpy(theme, def_theme);

}


void spout(char *data, struct engine *Engine)
{
	int ord = 0;
	int diff = 0;
	int regflags = REG_ICASE | REG_EXTENDED;
	char href_buf[BUFSIZ];
	char text_buf[BUFSIZ];
	char desc_buf[BUFSIZ];
	char size_buf[BUFSIZ];
	char rela_buf[BUFSIZ];
	char rinz_buf[BUFSIZ];
	char *href = href_buf;
	char *text = text_buf;
	char *desc = desc_buf;
	char *size = size_buf;
	char *rela = rela_buf;
	char *rinz = rinz_buf;
	char *stop = data;
	char *hreflng;
	char *hrefsht;
	struct result *Result;
	regex_t reg_start;
	regex_t reg_stop;
	regmatch_t reg_pm_start[256];
	regmatch_t reg_pm_stop[256];



	memset(href, 0, sizeof(href_buf));
	memset(text, 0, sizeof(text_buf));
	memset(desc, 0, sizeof(desc_buf));
	memset(size, 0, sizeof(size_buf));
	memset(rela, 0, sizeof(rela_buf));
	memset(rinz, 0, sizeof(rinz_buf));

	if(Engine->link_order[0] == 0) {
		pthread_mutex_lock(&counter_mutex);
		totalcount++;
		resltcount++;
		printf("%s <a href=\"http://%s/\" target=\"_blank\">", data, Engine->host);
		printf("<font color=\"#CCCCCC\">[%s]</font></a><br><br>\n", Engine->name);
		pthread_mutex_unlock(&counter_mutex);
		return;
	}

	do{
		switch (Engine->link_order[ord]) {
			case 0:
				ord++;
				break;

			case 1:
				regcomp(&reg_start, Engine->link_href_start, regflags);
				regcomp(&reg_stop,  Engine->link_href_stop,  regflags);
				if (regexec (&reg_start, data, reg_start.re_nsub + 1, reg_pm_start, 0) == 0) {
					data += reg_pm_start[0].rm_eo;
					if (regexec (&reg_stop, data, reg_stop.re_nsub + 1, reg_pm_stop, 0) == 0) {
						strncpy(href, data, reg_pm_stop[0].rm_so);
						*(href + reg_pm_stop[0].rm_so) = '\0';
						data += reg_pm_stop[0].rm_so;
						ord++;
					} else {
						ord=KILL;
					}
				} else {
				  ord=KILL;
				}
				regfree(&reg_start);
				regfree(&reg_stop);
				break;

			case 2:
				regcomp(&reg_start, Engine->link_text_start, regflags);
				regcomp(&reg_stop,  Engine->link_text_stop,  regflags);
				if (regexec (&reg_start, data, reg_start.re_nsub + 1, reg_pm_start, 0) == 0) {
					data += reg_pm_start[0].rm_eo;
					if (regexec (&reg_stop, data, reg_stop.re_nsub + 1, reg_pm_stop, 0) == 0) {
						strncpy(text, data, reg_pm_stop[0].rm_so);
						*(text + reg_pm_stop[0].rm_so) = '\0';
						data += reg_pm_stop[0].rm_so;
						ord++;
					} else {
						ord=KILL;
					}
				} else {
				  ord=KILL;
				}
				regfree(&reg_start);
				regfree(&reg_stop);
				break;

			case 3:
				regcomp(&reg_start, Engine->link_desc_start, regflags);
				regcomp(&reg_stop,  Engine->link_desc_stop,  regflags);
				if (regexec (&reg_start, data, reg_start.re_nsub + 1, reg_pm_start, 0) == 0) {
					data += reg_pm_start[0].rm_eo;
					if (regexec (&reg_stop, data, reg_stop.re_nsub + 1, reg_pm_stop, 0) == 0) {
						strncpy(desc, data, reg_pm_stop[0].rm_so);
						*(desc + reg_pm_stop[0].rm_so) = '\0';
						data += reg_pm_stop[0].rm_so;
						ord++;
					} else {
						ord=KILL;
					}
				} else {
				  ord=KILL;
				}
				regfree(&reg_start);
				regfree(&reg_stop);
				break;

			case 4:
				regcomp(&reg_start, Engine->link_size_start, regflags);
				regcomp(&reg_stop,  Engine->link_size_stop,  regflags);
				if (regexec (&reg_start, data, reg_start.re_nsub + 1, reg_pm_start, 0) == 0) {
					data += reg_pm_start[0].rm_eo;
					if (regexec (&reg_stop, data, reg_stop.re_nsub + 1, reg_pm_stop, 0) == 0) {
						strncpy(size, data, reg_pm_stop[0].rm_so);
						*(size + reg_pm_stop[0].rm_so) = '\0';
						data += reg_pm_stop[0].rm_so;
						ord++;
					} else {
						ord=KILL;
					}
				} else {
				  ord=KILL;
				}
				regfree(&reg_start);
				regfree(&reg_stop);
				break;

			case 5:
				regcomp(&reg_start, Engine->link_rela_start, regflags);
				regcomp(&reg_stop,  Engine->link_rela_stop,  regflags);
				if (regexec (&reg_start, data, reg_start.re_nsub + 1, reg_pm_start, 0) == 0) {
					data += reg_pm_start[0].rm_eo;
					if (regexec (&reg_stop, data, reg_stop.re_nsub + 1, reg_pm_stop, 0) == 0) {
						strncpy(rela, data, reg_pm_stop[0].rm_so);
						*(rela + reg_pm_stop[0].rm_so) = '\0';
						data += reg_pm_stop[0].rm_so;
						ord++;
					} else {
						ord=KILL;
					}
				} else {
				  ord=KILL;
				}
				regfree(&reg_start);
				regfree(&reg_stop);
				break;

			default:
				ord++;
				break;


		}
	} while(ord<6);


	pthread_mutex_lock(&counter_mutex);

	Result = result_ptr;
	totalcount++;


	/*
	 *
	 *  strip duplicates
	 *
	 */

	while(Result->next != NULL) {
		// assume their gunna be different
		diff = 1;

		// exact match
		if(strcmp(Result->href, href) == 0) {
			diff = 0;

		} else {
		// partial match ... see if the diff is insignficant
			if (strlen(href) > strlen(Result->href)) {
				hreflng = href;
				hrefsht = Result->href;
			} else {
				hreflng = Result->href;
				hrefsht = href;
			}

			// ensure the bulk is the same
			if(strncmp(hreflng, hrefsht, strlen(hrefsht)) == 0) {
				hreflng += strlen(hrefsht);

				// assume they're the same
				diff = 0;

				while(*hreflng != '\0' && diff == 0) {
					if(*hreflng != '/' && \
				   	*hreflng != '?' && \
				   	*hreflng != '+' && \
				   	*hreflng != '&') diff = 1;
					hreflng++;
				}
			}
		}

		// same-same?  clock up a duplicate, piss it off
		if (diff == 0) {
			// printf("<span class=\"linkdesc\"><br>DUPLICATE: ");
			// printf("new [%s]  old [%s]<br><br></span>\n", href, Result->href);
			duplicount++;
			Engine->dupcount++;
			pthread_mutex_unlock(&counter_mutex);
			return;

		}

		Result = Result->next;
	}

	resltcount++;


	/*
	 *
	 * strip html tags from description <.....>  (prolly should be a func)
	 *
	 */

	rinz = rinz_buf;
	desc = desc_buf;

	regcomp(&reg_start, html_taggo, regflags);
	regcomp(&reg_stop, html_tagwo, regflags);
	while ((regexec (&reg_start, desc, reg_start.re_nsub + 1, reg_pm_start, 0)) == 0) {
		if ((regexec (&reg_stop, desc, reg_stop.re_nsub + 1, reg_pm_stop, 0)) == 0) {
			strncpy(rinz, desc, reg_pm_start[0].rm_so);
			rinz += reg_pm_start[0].rm_so;
			desc += reg_pm_stop[0].rm_eo;
		}
	}

	regfree(&reg_start);
	regfree(&reg_stop);

	if(*desc != '\0') {
		strcpy(rinz, desc);
		rinz += strlen(desc);
	}

	*rinz = '\0';

	desc = desc_buf;
	rinz = rinz_buf;
	strcpy(desc, rinz);


	/*
	 *
	 * store result (prevent future duplicates)
	 *
	 */

	Result->next = (struct result *) malloc(sizeof(struct result));
	Result = Result->next;
	strcpy(Result->href,  href);
	strcpy(Result->text,  text);
	strcpy(Result->desc,  desc);
	strcpy(Result->size,  size);
	strcpy(Result->rela,  rela);
	strcpy(Result->engt,  Engine->tag);


	/*
	 *
	 * display the master-piece!
	 *
	 */

	printf("<span class=\"linkprime\">%u.</span> ", resltcount);
	printf("<a href=\"%s\" target=\"_blank\" class=\"linkprime\">%s</a><br>\n", href, text);
	if(strlen(desc)>0) printf("<span class=\"linkdesc\">%s</span><br>\n", desc);
	printf("<a href=\"%s\" target=\"_blank\" class=\"linkrecap\">%s</a>", href, href);
	if(strlen(size)>0) printf("<span class=\"linkrecap\"> (%s)</span>", size);
	printf("&nbsp; <span class=\"linkengine\">[");
	printf("<a href=\"http://%s\" target=\"_blank\" class=\"linkengine\">%s</a>", Engine->home, Engine->name);
	printf("]</span>\n"); 
	printf("<br><br>\n");
	pthread_mutex_unlock(&counter_mutex);

	return;
}


void *search(void *engine_no)
{
	int s, i, depth, regflags, same_string;
	char string[BUFSIZ], finalstring[BUFSIZ];
	char enginereqbuf[BUFSIZ];
	char *enginerequest = enginereqbuf;
	struct sockaddr_in sa;
	struct hostent *hp;
	struct engine *Engine;
	FILE *searchengine;
	regex_t reg_compiled;
	regmatch_t reg_pmatch[256];

	regflags = REG_ICASE | REG_EXTENDED;
	Engine = engine_ptr;


	while(engine_no>0) {
		Engine = Engine->next;
		engine_no--;
	}

	sprintf(enginerequest,		"GET %s%s HTTP/1.1\r\n",	Engine->cgistring, searchraw);
	enginerequest = enginereqbuf + strlen(enginereqbuf);
	sprintf(enginerequest,		"Host: %s\r\n",			Engine->host);
	enginerequest = enginereqbuf + strlen(enginereqbuf);
	if(strlen(Engine->referer) != 0) {
		sprintf(enginerequest,	"Referer: %s\r\n",		Engine->referer);
		enginerequest = enginereqbuf + strlen(enginereqbuf);
	}
	sprintf(enginerequest,		"User-agent: %s\r\n",		agent);
	enginerequest = enginereqbuf + strlen(enginereqbuf);
	sprintf(enginerequest,		"Pragma: no-cache\r\n"		);
	enginerequest = enginereqbuf + strlen(enginereqbuf);
	sprintf(enginerequest,		"Accept: */*\r\n"		);
	enginerequest = enginereqbuf + strlen(enginereqbuf);
	sprintf(enginerequest,		"Connection: close\r\n"		);
	enginerequest = enginereqbuf;

	if(debug >= 300) {
		printf("<br><hr><br>{300} Engine [%s]<br>", Engine->name);
		printf("<pre>[%s]</pre><br>\n", enginerequest);
	}


	s = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(Engine->port);
	if ((hp = gethostbyname(Engine->host)) == NULL) {
		printf("Cannot resolv hostname %s<br>\n", Engine->host);
		return;
	}
	memcpy(&sa.sin_addr, hp->h_addr, sizeof(struct in_addr));
	if (connect(s, (struct sockaddr *) &sa, sizeof(sa)) == 0) {
		searchengine = fdopen(s, "r+");

		fprintf(searchengine, "%s\r\n", enginerequest);

		depth = 0;
		while (fgets(string, BUFSIZ, searchengine)) {
		do {
			if(debug >= 410) {
				printf("<br><hr><br>{410} Engine [%s]<br>", Engine->name);
				printf("<pre>%s</pre><br>\n", string);
			}
			same_string = 0;
			switch (depth) {
				case 0:
					regcomp(&reg_compiled, Engine->res_list_start, regflags);
					if (regexec (&reg_compiled, string, reg_compiled.re_nsub + 1, reg_pmatch, 0) == 0) {
							depth++;
							same_string++;
							if(debug >= 460) {
								printf("<br><hr><br>{460} Engine [%s]<br>", Engine->name);
								printf("<pre>FOUND: [%s]</pre><br>\n", Engine->res_list_start);
							}
					}
					break;

				case 1:
					regcomp(&reg_compiled, Engine->res_item_start, regflags);
					if (regexec (&reg_compiled, string, reg_compiled.re_nsub + 1, reg_pmatch, 0) == 0) {
						depth++;
						same_string++;
						strcpy(string, string + reg_pmatch[0].rm_so);
						finalstring[0] = 0;
						if(debug >= 461) {
							printf("<br><hr><br>{461} Engine [%s]<br>", Engine->name);
							printf("<pre>FOUND: [%s]</pre><br>\n", Engine->res_item_start);
						}
					}

					regcomp(&reg_compiled, Engine->res_list_stop, regflags);
					if (regexec (&reg_compiled, string, reg_compiled.re_nsub + 1, reg_pmatch, 0) == 0) {
						depth--;
						same_string++;
						*(string + reg_pmatch[0].rm_so) = 0;
						if(debug >= 462) {
							printf("<br><hr><br>{462} Engine [%s]<br>", Engine->name);
							printf("<pre>FOUND: [%s]</pre><br>\n", Engine->res_item_stop);
						}
					}
					break;

				case 2:
					regcomp(&reg_compiled, Engine->res_item_stop, regflags);
					if (regexec (&reg_compiled, string, reg_compiled.re_nsub + 1, reg_pmatch, 0) == 0) {
						*(string + reg_pmatch[0].rm_so) = 0;
						strcat(finalstring, string);
						strcpy(string, string + reg_pmatch[0].rm_eo + 1);
						if(debug >= 463) {
							printf("<br><hr><br>{463} Engine [%s]<br>", Engine->name);
							printf("<pre>FOUND: [%s]</pre><br>\n", Engine->res_list_stop);
						}
						if(debug >= 470) {
							printf("<br><hr><br>{470} Engine [%s]<br>", Engine->name);
							printf("<pre>[%s]</pre><br>\n", finalstring);
						}
						spout(finalstring, Engine);
						depth--;
						same_string++;
						Engine->lnkcount++;
					} else {
						strcat(finalstring, string);
					}
					break;

				default:
					break;

			}

		} while (same_string);
		}

	fclose(searchengine);
	close(s);
	}
	return;
}


int main(void)
{
	pthread_t thr_pid[1024] = { 0 };
	int i, total_threads;
	struct engine *Engine;
	struct themed *Theme;
	struct dirent **themedirent;
	int n;

	printf("Content-type: text/html\n\n");

	totalcount = 0;
	duplicount = 0;
	resltcount = 0;

	themed_ptr = (struct themed *) malloc(sizeof(struct themed));
	Theme = themed_ptr;

	if((n = scandir(filthmhome, &themedirent, 0, alphasort)) >= 0) {
		while(n--) {
			if( index(themedirent[n]->d_name, 46) == NULL) {
       				strcpy(Theme->name,  themedirent[n]->d_name);
				Theme->next = (struct themed *) malloc(sizeof(struct themed));
				Theme = Theme->next;
			}
		}
	}

	result_ptr = (struct result *) malloc(sizeof(struct result));


	get_query();

	setvbuf(stdout, (char *) NULL, _IONBF, 0);


	engine_ptr = (struct engine *) malloc(sizeof(struct engine));
	Engine = engine_ptr;
	readcfg(0);

	printf("<html>\n<head>\n");
	if(strlen(searchraw)==0) {
		printf("  <title>%s</title>\n", vernam);
	} else {
		printf("  <title>%s: Search results for `%s`</title>\n", vernam, searchtxt);
	}

	if(strlen(theme)>0) {
		printf("  <link rel=\"stylesheet\" href=\"%s/themes/%s/main.css\" type=\"text/css\">\n", webrelhome, theme);
	} else {
		printf("  <link rel=\"stylesheet\" href=\"%s/themes/main.css\" type=\"text/css\">\n", webrelhome);
	}

	printf("</head>\n");

	if(strlen(theme)==0 && strlen(searchraw)==0) {
		printf("<body OnLoad=\"document.search.themes.focus();\">\n");
	} else if(strlen(searchraw)==0) {
		printf("<body OnLoad=\"document.search.query.focus();\">\n");
	} else {
		printf("<body>\n");
	}



	/*
	 *
	 *  render nav space
	 *
	 */

	printf("<table border=\"0\" cellpadding=\"0\" cellspacing=\"0\" width=\"98%\">\n<tr>\n");
	printf("  <td align=\"left\" valign=\"bottom\">");
	printf("<a href=\"%s/about/\" target=\"_top\" class=\"maintitle\">", webrelhome);
	printf("%s <sup>%s</sup></a></td>\n", vernam, vernum);
	printf("  <td align=\"right\" valign=\"bottom\">");
	printf("<form method=\"GET\" name=\"search\">\n");
	printf("<select name=\"themes\" class=\"themedrop\">");

	Theme = themed_ptr;
	while (Theme->next != NULL) {
		if(strcmp(theme, Theme->name) == 0) {
			printf("<option selected>%s</option>", Theme->name);
		} else {
			printf("<option>%s</option>", Theme->name);
		}
		Theme=Theme->next;
	}

	printf("</select> &nbsp; ");
	printf("<input type=\"button\" name=\"reload\" value=\" load \" class=\"searchbut\" ");
	printf("OnClick=\"parent.location.href='%s/?theme='", webrelhome);
	printf("+document.search.themes.options[document.search.themes.selectedIndex].text;return true;\">");
	printf("<span class=\"searchpad\">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; </span>");
	printf("<input name=\"theme\" type=\"hidden\" value=\"%s\">", theme);
	printf("<input name=\"query\" type=\"text\" value=\"%s\" size=\"30\" class=\"searchbox\"> &nbsp; ", searchtxt);
	printf("<input type=\"submit\" value=\"search\" class=\"searchbut\"></td>\n");
	printf("</tr>\n</table>\n");
	printf("<hr size=\"1\" width=\"98%\">\n");



	/*
	 *
	 *  render the engine results
	 *
	 */

	if(strlen(searchraw)!=0 && strcmp(config, "dump")!=0) {
		i = 0;
		Engine = engine_ptr;
		while (Engine->next != NULL) {
			pthread_create(&(thr_pid[i]), NULL, &search, (void *)i);
			i++;
			Engine = Engine->next;
		}

		total_threads = i;
		for (i = 0; i < total_threads; i++) {
			pthread_join(thr_pid[i], NULL);
		}

		printf("<hr size=\"1\" width=\"98%\">\n");



		/*
 		 *
	 	 *  render per-engine stats (with correct punctuation)
	 	 *
	 	 */

		printf("<table border=\"0\" cellpadding=\"0\" cellspacing=\"4\">\n<tr>\n");
		printf("  <td nowrap=\"true\"><span class=\"enginesum\">Result summary: ");
		if (totalcount == 0) {
			printf("no links found", totalcount);
		} else {
			if (totalcount == 1) {
				printf("%u link less ", totalcount);
			} else if (totalcount > 1) {
				printf("%u links less ", totalcount);
			}
			if (duplicount == 0) {
				printf("no duplicates, left ");
			} else if (duplicount == 1) {
				printf("%u duplicate, left ", duplicount);
			} else if (duplicount > 1) {
				printf("%u duplicates, left ", duplicount);
			}
			if (resltcount == 0) {
				printf("no results");
			} else if (resltcount == 1) {
				printf("%u result", resltcount);
			} else if (resltcount > 1) {
				printf("%u results", resltcount);
			}
		}

		printf("</span></td>\n</tr>\n<tr>\n  <td>\n");
		printf("    <table width=\"100%\" border=\"0\" cellpadding=\"1\" cellspacing=\"2\">\n    <tr>\n");
		// printf("      <th align=\"left\">Engine</th>\n");
		// printf("      <th align=\"right\">Hits</th>\n    </tr>\n");

		Engine = engine_ptr;
		for (i = 0; i < total_threads; i++) {
			printf("    <tr>\n");
			printf("      <td align=\"left\"><a href=\"http://%s\"", Engine->home);
			printf(" target=\"_blank\" class=\"enginenam\">%s</span></td>\n", Engine->name);
			printf("      <td align=\"right\"><span class=\"enginenum\"> &nbsp; ");
			if(Engine->dupcount == 0 && Engine->lnkcount > 0) {
				printf("no duplicates in ");
			} else if(Engine->dupcount == 1) {
				printf("%u duplicate in ", Engine->dupcount);
			} else if(Engine->dupcount > 1) {
				printf("%u duplicates in ", Engine->dupcount);
			}
			if(Engine->lnkcount == 0) {
				printf("no links");
			} else if(Engine->lnkcount == 1) {
				printf("%u link", Engine->lnkcount);
			} else if(Engine->lnkcount > 1) {
				printf("%u links", Engine->lnkcount);
			}
			printf(" &nbsp; </span></td>\n");
			printf("    </tr>\n");
			Engine = Engine->next;
		}
		printf("    </table>\n  </td>\n</tr>\n</table>\n");
	} else if (strcmp(config, "dump")==0) {
		printf("<span class=\"linkdesc\">\n");
		readcfg(1);
		printf("</span>\n");
		printf("<hr size=\"1\" width=\"98%\">\n");
	}

	printf("</body>\n</html>\n");

	return 0;
}


