# 1 "scz_compress.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "scz_compress.c"



# 39 "scz_compress.c"


# 1 "scz_compress_lib.c" 1



# 52 "scz_compress_lib.c"





# 1 "scz_core.c" 1








# 1 "/usr/include/stdio.h" 1 3 4

# 23 "/usr/include/stdio.h" 3 4

# 60 "/usr/include/stdio.h" 3 4





# 1 "/usr/include/sys/cdefs.h" 1 3 4

# 28 "/usr/include/sys/cdefs.h" 3 4


# 66 "/usr/include/sys/cdefs.h" 3 4













# 105 "/usr/include/sys/cdefs.h" 3 4









# 128 "/usr/include/sys/cdefs.h" 3 4


# 155 "/usr/include/sys/cdefs.h" 3 4


# 166 "/usr/include/sys/cdefs.h" 3 4








# 186 "/usr/include/sys/cdefs.h" 3 4


# 204 "/usr/include/sys/cdefs.h" 3 4




















# 259 "/usr/include/sys/cdefs.h" 3 4








# 291 "/usr/include/sys/cdefs.h" 3 4

# 315 "/usr/include/sys/cdefs.h" 3 4

# 337 "/usr/include/sys/cdefs.h" 3 4

# 347 "/usr/include/sys/cdefs.h" 3 4






# 361 "/usr/include/sys/cdefs.h" 3 4

# 371 "/usr/include/sys/cdefs.h" 3 4

# 381 "/usr/include/sys/cdefs.h" 3 4





































# 1 "/usr/include/sys/_symbol_aliasing.h" 1 3 4

# 27 "/usr/include/sys/_symbol_aliasing.h" 3 4

















































































































# 418 "/usr/include/sys/cdefs.h" 2 3 4











# 447 "/usr/include/sys/cdefs.h" 3 4














# 473 "/usr/include/sys/cdefs.h" 3 4










# 492 "/usr/include/sys/cdefs.h" 3 4



# 1 "/usr/include/sys/_posix_availability.h" 1 3 4

# 27 "/usr/include/sys/_posix_availability.h" 3 4















































# 495 "/usr/include/sys/cdefs.h" 2 3 4































# 542 "/usr/include/sys/cdefs.h" 3 4






















# 572 "/usr/include/sys/cdefs.h" 3 4


























# 606 "/usr/include/sys/cdefs.h" 3 4

# 65 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/Availability.h" 1 3 4

# 23 "/usr/include/Availability.h" 3 4
 


 
# 118 "/usr/include/Availability.h" 3 4

# 128 "/usr/include/Availability.h" 3 4

# 140 "/usr/include/Availability.h" 3 4


# 1 "/usr/include/AvailabilityInternal.h" 1 3 4

# 23 "/usr/include/AvailabilityInternal.h" 3 4













    #ifdef __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
        
        #define __IPHONE_OS_VERSION_MIN_REQUIRED __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
    #endif









    #define __AVAILABILITY_INTERNAL_DEPRECATED         __attribute__((deprecated,visibility("default")))
    #define __AVAILABILITY_INTERNAL_UNAVAILABLE        __attribute__((unavailable,visibility("default")))
    #define __AVAILABILITY_INTERNAL_WEAK_IMPORT        __attribute__((weak_import,visibility("default")))
    #define __AVAILABILITY_INTERNAL_REGULAR            __attribute__((visibility("default")))


# 609 "/usr/include/AvailabilityInternal.h" 3 4
    
    #define __MAC_OS_X_VERSION_MIN_REQUIRED 1070
    
    #ifndef __MAC_OS_X_VERSION_MAX_ALLOWED
        #define __MAC_OS_X_VERSION_MAX_ALLOWED 1070
    #endif
    
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1070
        #define __AVAILABILITY_INTERNAL__MAC_10_7        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1070
        #define __AVAILABILITY_INTERNAL__MAC_10_7        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_7        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1060
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1060
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1050
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1050
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1040
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1040
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1030
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1030
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1020
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1020
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1010
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1010
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < 1000
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < 1000
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #define __AVAILABILITY_INTERNAL__MAC_NA             __AVAILABILITY_INTERNAL_UNAVAILABLE
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1010
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1        __AVAILABILITY_INTERNAL__MAC_10_0
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1020
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2        __AVAILABILITY_INTERNAL__MAC_10_1
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1030
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_2
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1040
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_3
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1050
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_4
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1060
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_5
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= 1070
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7        __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7        __AVAILABILITY_INTERNAL__MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7        __AVAILABILITY_INTERNAL__MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7        __AVAILABILITY_INTERNAL__MAC_10_6
    #endif
    #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_0
    #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_1
    #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_2
    #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_3
    #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_4
    #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_5
    #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_6
    #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_7
    #define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA               __AVAILABILITY_INTERNAL_UNAVAILABLE


# 142 "/usr/include/Availability.h" 2 3 4


# 155 "/usr/include/Availability.h" 3 4
    #define __OSX_AVAILABLE_STARTING(_mac, _iphone)
    #define __OSX_AVAILABLE_BUT_DEPRECATED(_macIntro, _macDep, _iphoneIntro, _iphoneDep) 



# 66 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/include/_types.h" 1 3 4

# 23 "/usr/include/_types.h" 3 4





# 1 "/usr/include/sys/_types.h" 1 3 4

# 28 "/usr/include/sys/_types.h" 3 4






# 1 "/usr/include/machine/_types.h" 1 3 4

# 30 "/usr/include/machine/_types.h" 3 4



# 1 "/usr/include/i386/_types.h" 1 3 4

# 30 "/usr/include/i386/_types.h" 3 4







typedef __signed char		__int8_t;



typedef unsigned char		__uint8_t;
typedef	short			__int16_t;
typedef	unsigned short		__uint16_t;
typedef int			__int32_t;
typedef unsigned int		__uint32_t;
typedef long long		__int64_t;
typedef unsigned long long	__uint64_t;

typedef long			__darwin_intptr_t;
typedef unsigned int		__darwin_natural_t;


# 69 "/usr/include/i386/_types.h" 3 4

typedef int			__darwin_ct_rune_t;	





typedef union {
	char		__mbstate8[128];
	long long	_mbstateL;			
} __mbstate_t;

typedef __mbstate_t		__darwin_mbstate_t;	


typedef long int	__darwin_ptrdiff_t;	





typedef long unsigned int		__darwin_size_t;	





typedef __builtin_va_list	__darwin_va_list;	





typedef int		__darwin_wchar_t;	




typedef __darwin_wchar_t	__darwin_rune_t;	


typedef int		__darwin_wint_t;	




typedef unsigned long		__darwin_clock_t;	
typedef __uint32_t		__darwin_socklen_t;	
typedef long			__darwin_ssize_t;	
typedef long			__darwin_time_t;	

# 33 "/usr/include/machine/_types.h" 2 3 4






# 34 "/usr/include/sys/_types.h" 2 3 4


# 57 "/usr/include/sys/_types.h" 3 4

struct __darwin_pthread_handler_rec
{
	void           (*__routine)(void *);	
	void           *__arg;			
	struct __darwin_pthread_handler_rec *__next;
};
struct _opaque_pthread_attr_t { long __sig; char __opaque[56]; };
struct _opaque_pthread_cond_t { long __sig; char __opaque[40]; };
struct _opaque_pthread_condattr_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_mutex_t { long __sig; char __opaque[56]; };
struct _opaque_pthread_mutexattr_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_once_t { long __sig; char __opaque[8]; };
struct _opaque_pthread_rwlock_t { long __sig; char __opaque[192]; };
struct _opaque_pthread_rwlockattr_t { long __sig; char __opaque[16]; };
struct _opaque_pthread_t { long __sig; struct __darwin_pthread_handler_rec  *__cleanup_stack; char __opaque[1168]; };







# 93 "/usr/include/sys/_types.h" 3 4

typedef	__int64_t	__darwin_blkcnt_t;	
typedef	__int32_t	__darwin_blksize_t;	
typedef __int32_t	__darwin_dev_t;		
typedef unsigned int	__darwin_fsblkcnt_t;	
typedef unsigned int	__darwin_fsfilcnt_t;	
typedef __uint32_t	__darwin_gid_t;		
typedef __uint32_t	__darwin_id_t;		
typedef __uint64_t	__darwin_ino64_t;	

typedef __darwin_ino64_t __darwin_ino_t;	



typedef __darwin_natural_t __darwin_mach_port_name_t; 
typedef __darwin_mach_port_name_t __darwin_mach_port_t; 
typedef __uint16_t	__darwin_mode_t;	
typedef __int64_t	__darwin_off_t;		
typedef __int32_t	__darwin_pid_t;		
typedef struct _opaque_pthread_attr_t
			__darwin_pthread_attr_t; 
typedef struct _opaque_pthread_cond_t
			__darwin_pthread_cond_t; 
typedef struct _opaque_pthread_condattr_t
			__darwin_pthread_condattr_t; 
typedef unsigned long	__darwin_pthread_key_t;	
typedef struct _opaque_pthread_mutex_t
			__darwin_pthread_mutex_t; 
typedef struct _opaque_pthread_mutexattr_t
			__darwin_pthread_mutexattr_t; 
typedef struct _opaque_pthread_once_t
			__darwin_pthread_once_t; 
typedef struct _opaque_pthread_rwlock_t
			__darwin_pthread_rwlock_t; 
typedef struct _opaque_pthread_rwlockattr_t
			__darwin_pthread_rwlockattr_t; 
typedef struct _opaque_pthread_t
			*__darwin_pthread_t;	
typedef __uint32_t	__darwin_sigset_t;	
typedef __int32_t	__darwin_suseconds_t;	
typedef __uint32_t	__darwin_uid_t;		
typedef __uint32_t	__darwin_useconds_t;	
typedef	unsigned char	__darwin_uuid_t[16];
typedef	char	__darwin_uuid_string_t[37];

# 28 "/usr/include/_types.h" 2 3 4

# 38 "/usr/include/_types.h" 3 4

typedef	int		__darwin_nl_item;
typedef	int		__darwin_wctrans_t;

typedef	__uint32_t	__darwin_wctype_t;

























# 68 "/usr/include/stdio.h" 2 3 4





typedef __darwin_va_list	va_list;




typedef	__darwin_size_t		size_t;






typedef __darwin_off_t		fpos_t;










struct __sbuf {
	unsigned char	*_base;
	int		_size;
};


struct __sFILEX;


# 130 "/usr/include/stdio.h" 3 4
typedef	struct __sFILE {
	unsigned char *_p;	
	int	_r;		
	int	_w;		
	short	_flags;		
	short	_file;		
	struct	__sbuf _bf;	
	int	_lbfsize;	

	
	void	*_cookie;	
	int	(*_close)(void *);
	int	(*_read) (void *, char *, int);
	fpos_t	(*_seek) (void *, fpos_t, int);
	int	(*_write)(void *, __const char *, int);

	
	struct	__sbuf _ub;	
	struct __sFILEX *_extra; 
	int	_ur;		

	
	unsigned char _ubuf[3];	
	unsigned char _nbuf[1];	

	
	struct	__sbuf _lb;	

	
	int	_blksize;	
	fpos_t	_offset;	
} FILE;


extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;






	
# 186 "/usr/include/stdio.h" 3 4


# 199 "/usr/include/stdio.h" 3 4




				










# 223 "/usr/include/stdio.h" 3 4
















void	 clearerr(FILE *);
int	 fclose(FILE *);
int	 feof(FILE *);
int	 ferror(FILE *);
int	 fflush(FILE *);
int	 fgetc(FILE *);
int	 fgetpos(FILE * , fpos_t *);
char	*fgets(char * , int, FILE *);



FILE	*fopen(__const char * , __const char * ) __DARWIN_ALIAS_STARTING_MAC_##1060( __asm("_" "fopen" ));

int	 fprintf(FILE * , __const char * , ...)  __attribute__((__format__ (__printf__, 2,  3)));
int	 fputc(int, FILE *);
int	 fputs(__const char * , FILE * ) __asm("_" "fputs" );
size_t	 fread(void * , size_t, size_t, FILE * );
FILE	*freopen(__const char * , __const char * ,
                 FILE * ) __asm("_" "freopen" );
int	 fscanf(FILE * , __const char * , ...)  __attribute__((__format__ (__scanf__, 2,  3)));
int	 fseek(FILE *, long, int);
int	 fsetpos(FILE *, __const fpos_t *);
long	 ftell(FILE *);
size_t	 fwrite(__const void * , size_t, size_t, FILE * ) __asm("_" "fwrite" );
int	 getc(FILE *);
int	 getchar(void);
char	*gets(char *);
void	 perror(__const char *);
int	 printf(__const char * , ...)  __attribute__((__format__ (__printf__, 1,  2)));
int	 putc(int, FILE *);
int	 putchar(int);
int	 puts(__const char *);
int	 remove(__const char *);
int	 rename (__const char *, __const char *);
void	 rewind(FILE *);
int	 scanf(__const char * , ...)  __attribute__((__format__ (__scanf__, 1,  2)));
void	 setbuf(FILE * , char * );
int	 setvbuf(FILE * , char * , int, size_t);
int	 sprintf(char * , __const char * , ...)  __attribute__((__format__ (__printf__, 2,  3)));
int	 sscanf(__const char * , __const char * , ...)  __attribute__((__format__ (__scanf__, 2,  3)));
FILE	*tmpfile(void);
char	*tmpnam(char *);
int	 ungetc(int, FILE *);
int	 vfprintf(FILE * , __const char * , va_list)  __attribute__((__format__ (__printf__, 2,  0)));
int	 vprintf(__const char * , va_list)  __attribute__((__format__ (__printf__, 1,  0)));
int	 vsprintf(char * , __const char * , va_list)  __attribute__((__format__ (__printf__, 2,  0)));















char	*ctermid(char *);





FILE	*fdopen(int, __const char *) __DARWIN_ALIAS_STARTING_MAC_##1060( __asm("_" "fdopen" ));

int	 fileno(FILE *);










int	 pclose(FILE *);



FILE	*popen(__const char *, __const char *) __DARWIN_ALIAS_STARTING_MAC_##1060( __asm("_" "popen" ));

















int	__srget(FILE *);
int	__svfscanf(FILE *, __const char *, va_list)  __attribute__((__format__ (__scanf__, 2,  0)));
int	__swbuf(int, FILE *);



# 359 "/usr/include/stdio.h" 3 4

# 371 "/usr/include/stdio.h" 3 4







void	 flockfile(FILE *);
int	 ftrylockfile(FILE *);
void	 funlockfile(FILE *);
int	 getc_unlocked(FILE *);
int	 getchar_unlocked(void);
int	 putc_unlocked(int, FILE *);
int	 putchar_unlocked(int);



int	 getw(FILE *);
int	 putw(int, FILE *);


char	*tempnam(__const char *, __const char *) __asm("_" "tempnam" );





















typedef	__darwin_off_t		off_t;



int	 fseeko(FILE *, off_t, int);
off_t	 ftello(FILE *);





int	 snprintf(char * , size_t, __const char * , ...)  __attribute__((__format__ (__printf__, 3,  4)));
int	 vfscanf(FILE * , __const char * , va_list)  __attribute__((__format__ (__scanf__, 2,  0)));
int	 vscanf(__const char * , va_list)  __attribute__((__format__ (__scanf__, 1,  0)));
int	 vsnprintf(char * , size_t, __const char * , va_list)  __attribute__((__format__ (__printf__, 3,  0)));
int	 vsscanf(__const char * , __const char * , va_list)  __attribute__((__format__ (__scanf__, 2,  0)));












typedef __darwin_ssize_t        ssize_t;



int	dprintf(int, __const char * , ...)  __attribute__((__format__ (__printf__, 2,  3))) __OSX_AVAILABLE_STARTING(1070, 40300);
int	vdprintf(int, __const char * , va_list)  __attribute__((__format__ (__printf__, 2,  0))) __OSX_AVAILABLE_STARTING(1070, 40300);
ssize_t getdelim(char ** , size_t * , int, FILE * ) __OSX_AVAILABLE_STARTING(1070, 40300);
ssize_t getline(char ** , size_t * , FILE * ) __OSX_AVAILABLE_STARTING(1070, 40300);









extern __const int sys_nerr;		
extern __const char *__const sys_errlist[];

int	 asprintf(char **, __const char *, ...)  __attribute__((__format__ (__printf__, 2,  3)));
char	*ctermid_r(char *);
char	*fgetln(FILE *, size_t *);
__const char *fmtcheck(__const char *, __const char *);
int	 fpurge(FILE *);
void	 setbuffer(FILE *, char *, int);
int	 setlinebuf(FILE *);
int	 vasprintf(char **, __const char *, va_list)  __attribute__((__format__ (__printf__, 2,  0)));
FILE	*zopen(__const char *, __const char *, int);





FILE	*funopen(__const void *,
                 int (*)(void *, char *, int),
                 int (*)(void *, __const char *, int),
                 fpos_t (*)(void *, fpos_t, int),
                 int (*)(void *));



















# 1 "/usr/include/secure/_stdio.h" 1 3 4

# 23 "/usr/include/secure/_stdio.h" 3 4









# 1 "/usr/include/secure/_common.h" 1 3 4

# 23 "/usr/include/secure/_common.h" 3 4




# 37 "/usr/include/secure/_common.h" 3 4




# 32 "/usr/include/secure/_stdio.h" 2 3 4













extern int __sprintf_chk (char * , int, size_t,
			  __const char * , ...)
  ;




extern int __snprintf_chk (char * , size_t, int, size_t,
			   __const char * , ...)
  ;





extern int __vsprintf_chk (char * , int, size_t,
			   __const char * , va_list)
  ;




extern int __vsnprintf_chk (char * , size_t, int, size_t,
			    __const char * , va_list)
  ;







# 500 "/usr/include/stdio.h" 2 3 4


# 9 "scz_core.c" 2

# 1 "/usr/include/stdlib.h" 1 3 4

# 23 "/usr/include/stdlib.h" 3 4

# 57 "/usr/include/stdlib.h" 3 4









# 1 "/usr/include/sys/wait.h" 1 3 4

# 28 "/usr/include/sys/wait.h" 3 4


# 63 "/usr/include/sys/wait.h" 3 4
 















typedef enum {
	P_ALL,
	P_PID,
	P_PGID
} idtype_t;






typedef __darwin_pid_t	pid_t;




typedef __darwin_id_t	id_t;




# 117 "/usr/include/sys/wait.h" 3 4
# 1 "/usr/include/sys/signal.h" 1 3 4

# 28 "/usr/include/sys/signal.h" 3 4


# 68 "/usr/include/sys/signal.h" 3 4






# 1 "/usr/include/sys/appleapiopts.h" 1 3 4

# 28 "/usr/include/sys/appleapiopts.h" 3 4



































# 74 "/usr/include/sys/signal.h" 2 3 4








# 1 "/usr/include/machine/signal.h" 1 3 4

# 30 "/usr/include/machine/signal.h" 3 4



# 1 "/usr/include/i386/signal.h" 1 3 4

# 28 "/usr/include/i386/signal.h" 3 4











typedef int sig_atomic_t; 








# 56 "/usr/include/i386/signal.h" 3 4
# 1 "/usr/include/i386/_structs.h" 1 3 4

# 28 "/usr/include/i386/_structs.h" 3 4














# 121 "/usr/include/i386/_structs.h" 3 4

# 135 "/usr/include/i386/_structs.h" 3 4







# 56 "/usr/include/i386/signal.h" 2 3 4







# 33 "/usr/include/machine/signal.h" 2 3 4






# 82 "/usr/include/sys/signal.h" 2 3 4

# 123 "/usr/include/sys/signal.h" 3 4



# 141 "/usr/include/sys/signal.h" 3 4








# 1 "/usr/include/sys/_structs.h" 1 3 4

# 28 "/usr/include/sys/_structs.h" 3 4






























# 1 "/usr/include/machine/_structs.h" 1 3 4

# 30 "/usr/include/machine/_structs.h" 3 4
# 1 "/usr/include/i386/_structs.h" 1 3 4

# 28 "/usr/include/i386/_structs.h" 3 4











# 1 "/usr/include/mach/i386/_structs.h" 1 3 4

# 28 "/usr/include/mach/i386/_structs.h" 3 4















struct __darwin_i386_thread_state
{
    unsigned int	__eax;
    unsigned int	__ebx;
    unsigned int	__ecx;
    unsigned int	__edx;
    unsigned int	__edi;
    unsigned int	__esi;
    unsigned int	__ebp;
    unsigned int	__esp;
    unsigned int	__ss;
    unsigned int	__eflags;
    unsigned int	__eip;
    unsigned int	__cs;
    unsigned int	__ds;
    unsigned int	__es;
    unsigned int	__fs;
    unsigned int	__gs;
};
# 84 "/usr/include/mach/i386/_structs.h" 3 4





struct __darwin_fp_control
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
						:2,
				__pc		:2,





				__rc		:2,






						:1,
						:3;
};
typedef struct __darwin_fp_control	__darwin_fp_control_t;
# 140 "/usr/include/mach/i386/_structs.h" 3 4







struct __darwin_fp_status
{
    unsigned short		__invalid	:1,
    				__denorm	:1,
				__zdiv		:1,
				__ovrfl		:1,
				__undfl		:1,
				__precis	:1,
				__stkflt	:1,
				__errsumm	:1,
				__c0		:1,
				__c1		:1,
				__c2		:1,
				__tos		:3,
				__c3		:1,
				__busy		:1;
};
typedef struct __darwin_fp_status	__darwin_fp_status_t;
# 186 "/usr/include/mach/i386/_structs.h" 3 4
				




struct __darwin_mmst_reg
{
	char	__mmst_reg[10];
	char	__mmst_rsrv[6];
};
# 204 "/usr/include/mach/i386/_structs.h" 3 4






struct __darwin_xmm_reg
{
	char		__xmm_reg[16];
};


















struct __darwin_i386_float_state
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;		
	struct __darwin_fp_status	__fpu_fsw;		
	__uint8_t		__fpu_ftw;		
	__uint8_t		__fpu_rsrv1;		 
	__uint16_t		__fpu_fop;		
	__uint32_t		__fpu_ip;		
	__uint16_t		__fpu_cs;		
	__uint16_t		__fpu_rsrv2;		
	__uint32_t		__fpu_dp;		
	__uint16_t		__fpu_ds;		
	__uint16_t		__fpu_rsrv3;		
	__uint32_t		__fpu_mxcsr;		
	__uint32_t		__fpu_mxcsrmask;	
	struct __darwin_mmst_reg	__fpu_stmm0;		
	struct __darwin_mmst_reg	__fpu_stmm1;		
	struct __darwin_mmst_reg	__fpu_stmm2;		
	struct __darwin_mmst_reg	__fpu_stmm3;		
	struct __darwin_mmst_reg	__fpu_stmm4;		
	struct __darwin_mmst_reg	__fpu_stmm5;		
	struct __darwin_mmst_reg	__fpu_stmm6;		
	struct __darwin_mmst_reg	__fpu_stmm7;		
	struct __darwin_xmm_reg		__fpu_xmm0;		
	struct __darwin_xmm_reg		__fpu_xmm1;		
	struct __darwin_xmm_reg		__fpu_xmm2;		
	struct __darwin_xmm_reg		__fpu_xmm3;		
	struct __darwin_xmm_reg		__fpu_xmm4;		
	struct __darwin_xmm_reg		__fpu_xmm5;		
	struct __darwin_xmm_reg		__fpu_xmm6;		
	struct __darwin_xmm_reg		__fpu_xmm7;		
	char			__fpu_rsrv4[14*16];	
	int 			__fpu_reserved1;
};


struct __darwin_i386_avx_state
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;		
	struct __darwin_fp_status	__fpu_fsw;		
	__uint8_t		__fpu_ftw;		
	__uint8_t		__fpu_rsrv1;		 
	__uint16_t		__fpu_fop;		
	__uint32_t		__fpu_ip;		
	__uint16_t		__fpu_cs;		
	__uint16_t		__fpu_rsrv2;		
	__uint32_t		__fpu_dp;		
	__uint16_t		__fpu_ds;		
	__uint16_t		__fpu_rsrv3;		
	__uint32_t		__fpu_mxcsr;		
	__uint32_t		__fpu_mxcsrmask;	
	struct __darwin_mmst_reg	__fpu_stmm0;		
	struct __darwin_mmst_reg	__fpu_stmm1;		
	struct __darwin_mmst_reg	__fpu_stmm2;		
	struct __darwin_mmst_reg	__fpu_stmm3;		
	struct __darwin_mmst_reg	__fpu_stmm4;		
	struct __darwin_mmst_reg	__fpu_stmm5;		
	struct __darwin_mmst_reg	__fpu_stmm6;		
	struct __darwin_mmst_reg	__fpu_stmm7;		
	struct __darwin_xmm_reg		__fpu_xmm0;		
	struct __darwin_xmm_reg		__fpu_xmm1;		
	struct __darwin_xmm_reg		__fpu_xmm2;		
	struct __darwin_xmm_reg		__fpu_xmm3;		
	struct __darwin_xmm_reg		__fpu_xmm4;		
	struct __darwin_xmm_reg		__fpu_xmm5;		
	struct __darwin_xmm_reg		__fpu_xmm6;		
	struct __darwin_xmm_reg		__fpu_xmm7;		
	char			__fpu_rsrv4[14*16];	
	int 			__fpu_reserved1;
	char			__avx_reserved1[64];
	struct __darwin_xmm_reg		__fpu_ymmh0;		
	struct __darwin_xmm_reg		__fpu_ymmh1;		
	struct __darwin_xmm_reg		__fpu_ymmh2;		
	struct __darwin_xmm_reg		__fpu_ymmh3;		
	struct __darwin_xmm_reg		__fpu_ymmh4;		
	struct __darwin_xmm_reg		__fpu_ymmh5;		
	struct __darwin_xmm_reg		__fpu_ymmh6;		
	struct __darwin_xmm_reg		__fpu_ymmh7;		
};

# 399 "/usr/include/mach/i386/_structs.h" 3 4



struct __darwin_i386_exception_state
{
	__uint16_t	__trapno;
	__uint16_t	__cpu;
	__uint32_t	__err;
	__uint32_t	__faultvaddr;
};
# 419 "/usr/include/mach/i386/_structs.h" 3 4



struct __darwin_x86_debug_state32
{
	unsigned int	__dr0;
	unsigned int	__dr1;
	unsigned int	__dr2;
	unsigned int	__dr3;
	unsigned int	__dr4;
	unsigned int	__dr5;
	unsigned int	__dr6;
	unsigned int	__dr7;
};
# 447 "/usr/include/mach/i386/_structs.h" 3 4







struct __darwin_x86_thread_state64
{
	__uint64_t	__rax;
	__uint64_t	__rbx;
	__uint64_t	__rcx;
	__uint64_t	__rdx;
	__uint64_t	__rdi;
	__uint64_t	__rsi;
	__uint64_t	__rbp;
	__uint64_t	__rsp;
	__uint64_t	__r8;
	__uint64_t	__r9;
	__uint64_t	__r10;
	__uint64_t	__r11;
	__uint64_t	__r12;
	__uint64_t	__r13;
	__uint64_t	__r14;
	__uint64_t	__r15;
	__uint64_t	__rip;
	__uint64_t	__rflags;
	__uint64_t	__cs;
	__uint64_t	__fs;
	__uint64_t	__gs;
};
# 505 "/usr/include/mach/i386/_structs.h" 3 4




struct __darwin_x86_float_state64
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;		
	struct __darwin_fp_status	__fpu_fsw;		
	__uint8_t		__fpu_ftw;		
	__uint8_t		__fpu_rsrv1;		 
	__uint16_t		__fpu_fop;		

	
	__uint32_t		__fpu_ip;		
	__uint16_t		__fpu_cs;		

	__uint16_t		__fpu_rsrv2;		

	
	__uint32_t		__fpu_dp;		
	__uint16_t		__fpu_ds;		

	__uint16_t		__fpu_rsrv3;		
	__uint32_t		__fpu_mxcsr;		
	__uint32_t		__fpu_mxcsrmask;	
	struct __darwin_mmst_reg	__fpu_stmm0;		
	struct __darwin_mmst_reg	__fpu_stmm1;		
	struct __darwin_mmst_reg	__fpu_stmm2;		
	struct __darwin_mmst_reg	__fpu_stmm3;		
	struct __darwin_mmst_reg	__fpu_stmm4;		
	struct __darwin_mmst_reg	__fpu_stmm5;		
	struct __darwin_mmst_reg	__fpu_stmm6;		
	struct __darwin_mmst_reg	__fpu_stmm7;		
	struct __darwin_xmm_reg		__fpu_xmm0;		
	struct __darwin_xmm_reg		__fpu_xmm1;		
	struct __darwin_xmm_reg		__fpu_xmm2;		
	struct __darwin_xmm_reg		__fpu_xmm3;		
	struct __darwin_xmm_reg		__fpu_xmm4;		
	struct __darwin_xmm_reg		__fpu_xmm5;		
	struct __darwin_xmm_reg		__fpu_xmm6;		
	struct __darwin_xmm_reg		__fpu_xmm7;		
	struct __darwin_xmm_reg		__fpu_xmm8;		
	struct __darwin_xmm_reg		__fpu_xmm9;		
	struct __darwin_xmm_reg		__fpu_xmm10;		
	struct __darwin_xmm_reg		__fpu_xmm11;		
	struct __darwin_xmm_reg		__fpu_xmm12;		
	struct __darwin_xmm_reg		__fpu_xmm13;		
	struct __darwin_xmm_reg		__fpu_xmm14;		
	struct __darwin_xmm_reg		__fpu_xmm15;		
	char			__fpu_rsrv4[6*16];	
	int 			__fpu_reserved1;
};


struct __darwin_x86_avx_state64
{
	int 			__fpu_reserved[2];
	struct __darwin_fp_control	__fpu_fcw;		
	struct __darwin_fp_status	__fpu_fsw;		
	__uint8_t		__fpu_ftw;		
	__uint8_t		__fpu_rsrv1;		 
	__uint16_t		__fpu_fop;		

	
	__uint32_t		__fpu_ip;		
	__uint16_t		__fpu_cs;		

	__uint16_t		__fpu_rsrv2;		

	
	__uint32_t		__fpu_dp;		
	__uint16_t		__fpu_ds;		

	__uint16_t		__fpu_rsrv3;		
	__uint32_t		__fpu_mxcsr;		
	__uint32_t		__fpu_mxcsrmask;	
	struct __darwin_mmst_reg	__fpu_stmm0;		
	struct __darwin_mmst_reg	__fpu_stmm1;		
	struct __darwin_mmst_reg	__fpu_stmm2;		
	struct __darwin_mmst_reg	__fpu_stmm3;		
	struct __darwin_mmst_reg	__fpu_stmm4;		
	struct __darwin_mmst_reg	__fpu_stmm5;		
	struct __darwin_mmst_reg	__fpu_stmm6;		
	struct __darwin_mmst_reg	__fpu_stmm7;		
	struct __darwin_xmm_reg		__fpu_xmm0;		
	struct __darwin_xmm_reg		__fpu_xmm1;		
	struct __darwin_xmm_reg		__fpu_xmm2;		
	struct __darwin_xmm_reg		__fpu_xmm3;		
	struct __darwin_xmm_reg		__fpu_xmm4;		
	struct __darwin_xmm_reg		__fpu_xmm5;		
	struct __darwin_xmm_reg		__fpu_xmm6;		
	struct __darwin_xmm_reg		__fpu_xmm7;		
	struct __darwin_xmm_reg		__fpu_xmm8;		
	struct __darwin_xmm_reg		__fpu_xmm9;		
	struct __darwin_xmm_reg		__fpu_xmm10;		
	struct __darwin_xmm_reg		__fpu_xmm11;		
	struct __darwin_xmm_reg		__fpu_xmm12;		
	struct __darwin_xmm_reg		__fpu_xmm13;		
	struct __darwin_xmm_reg		__fpu_xmm14;		
	struct __darwin_xmm_reg		__fpu_xmm15;		
	char			__fpu_rsrv4[6*16];	
	int 			__fpu_reserved1;
	char			__avx_reserved1[64];
	struct __darwin_xmm_reg		__fpu_ymmh0;		
	struct __darwin_xmm_reg		__fpu_ymmh1;		
	struct __darwin_xmm_reg		__fpu_ymmh2;		
	struct __darwin_xmm_reg		__fpu_ymmh3;		
	struct __darwin_xmm_reg		__fpu_ymmh4;		
	struct __darwin_xmm_reg		__fpu_ymmh5;		
	struct __darwin_xmm_reg		__fpu_ymmh6;		
	struct __darwin_xmm_reg		__fpu_ymmh7;		
	struct __darwin_xmm_reg		__fpu_ymmh8;		
	struct __darwin_xmm_reg		__fpu_ymmh9;		
	struct __darwin_xmm_reg		__fpu_ymmh10;		
	struct __darwin_xmm_reg		__fpu_ymmh11;		
	struct __darwin_xmm_reg		__fpu_ymmh12;		
	struct __darwin_xmm_reg		__fpu_ymmh13;		
	struct __darwin_xmm_reg		__fpu_ymmh14;		
	struct __darwin_xmm_reg		__fpu_ymmh15;		
};

# 748 "/usr/include/mach/i386/_structs.h" 3 4



struct __darwin_x86_exception_state64
{
    __uint16_t	__trapno;
    __uint16_t	__cpu;
    __uint32_t	__err;
    __uint64_t	__faultvaddr;
};
# 768 "/usr/include/mach/i386/_structs.h" 3 4



struct __darwin_x86_debug_state64
{
	__uint64_t	__dr0;
	__uint64_t	__dr1;
	__uint64_t	__dr2;
	__uint64_t	__dr3;
	__uint64_t	__dr4;
	__uint64_t	__dr5;
	__uint64_t	__dr6;
	__uint64_t	__dr7;
};
# 796 "/usr/include/mach/i386/_structs.h" 3 4

# 39 "/usr/include/i386/_structs.h" 2 3 4









struct __darwin_mcontext32
{
	struct __darwin_i386_exception_state	__es;
	struct __darwin_i386_thread_state	__ss;
	struct __darwin_i386_float_state	__fs;
};


struct __darwin_mcontext_avx32
{
	struct __darwin_i386_exception_state	__es;
	struct __darwin_i386_thread_state	__ss;
	struct __darwin_i386_avx_state		__fs;
};

# 82 "/usr/include/i386/_structs.h" 3 4




struct __darwin_mcontext64
{
	struct __darwin_x86_exception_state64	__es;
	struct __darwin_x86_thread_state64	__ss;
	struct __darwin_x86_float_state64	__fs;
};


struct __darwin_mcontext_avx64
{
	struct __darwin_x86_exception_state64	__es;
	struct __darwin_x86_thread_state64	__ss;
	struct __darwin_x86_avx_state64		__fs;
};

# 121 "/usr/include/i386/_structs.h" 3 4






typedef struct __darwin_mcontext64	*mcontext_t;














# 30 "/usr/include/machine/_structs.h" 2 3 4
# 58 "/usr/include/sys/_structs.h" 2 3 4

















struct __darwin_sigaltstack
{
	void		*ss_sp;		
	__darwin_size_t ss_size;	
	int		ss_flags;	
};



# 95 "/usr/include/sys/_structs.h" 3 4

# 107 "/usr/include/sys/_structs.h" 3 4

# 119 "/usr/include/sys/_structs.h" 3 4

# 128 "/usr/include/sys/_structs.h" 3 4
struct __darwin_ucontext
{
	int			uc_onstack;
	__darwin_sigset_t	uc_sigmask;	
	struct __darwin_sigaltstack 	uc_stack;	
	struct __darwin_ucontext	*uc_link;	
	__darwin_size_t		uc_mcsize;	
	struct __darwin_mcontext64	*uc_mcontext;	



};



# 162 "/usr/include/sys/_structs.h" 3 4


# 213 "/usr/include/sys/_structs.h" 3 4





typedef struct __darwin_sigaltstack	stack_t; 








typedef struct __darwin_ucontext	ucontext_t;	



# 149 "/usr/include/sys/signal.h" 2 3 4








typedef __darwin_pthread_attr_t		pthread_attr_t;




typedef __darwin_sigset_t		sigset_t;









typedef __darwin_uid_t			uid_t;


union sigval {
	
	int	sival_int;
	void	*sival_ptr;
};





struct sigevent {
	int				sigev_notify;				
	int				sigev_signo;				
	union sigval	sigev_value;				
	void			(*sigev_notify_function)(union sigval);	  
	pthread_attr_t	*sigev_notify_attributes;	
};


typedef struct __siginfo {
	int	si_signo;		
	int	si_errno;		
	int	si_code;		
	pid_t	si_pid;			
	uid_t	si_uid;			
	int	si_status;		
	void	*si_addr;		
	union sigval si_value;		
	long	si_band;		
	unsigned long	__pad[7];	
} siginfo_t;



# 218 "/usr/include/sys/signal.h" 3 4




# 233 "/usr/include/sys/signal.h" 3 4


# 246 "/usr/include/sys/signal.h" 3 4





















# 276 "/usr/include/sys/signal.h" 3 4










union __sigaction_u {
	void    (*__sa_handler)(int);
	void    (*__sa_sigaction)(int, struct __siginfo *,
		       void *);
};


struct	__sigaction {
	union __sigaction_u __sigaction_u;  
	void    (*sa_tramp)(void *, int, int, siginfo_t *, void *);
	sigset_t sa_mask;		
	int	sa_flags;		
};




struct	sigaction {
	union __sigaction_u __sigaction_u;  
	sigset_t sa_mask;		
	int	sa_flags;		
};







# 324 "/usr/include/sys/signal.h" 3 4
























typedef	void (*sig_t)(int);	
















struct	sigvec {
	void	(*sv_handler)(int);	
	int	sv_mask;		
	int	sv_flags;		
};














struct	sigstack {
	char	*ss_sp;			
	int	ss_onstack;		
};



















void	(*signal(int, void (*)(int)))(int);

# 117 "/usr/include/sys/wait.h" 2 3 4

# 1 "/usr/include/sys/resource.h" 1 3 4

# 28 "/usr/include/sys/resource.h" 3 4


# 63 "/usr/include/sys/resource.h" 3 4















# 1 "/usr/include/sys/_structs.h" 1 3 4

# 28 "/usr/include/sys/_structs.h" 3 4






































# 83 "/usr/include/sys/_structs.h" 3 4

# 95 "/usr/include/sys/_structs.h" 3 4





struct timeval
{
	__darwin_time_t		tv_sec;		
	__darwin_suseconds_t	tv_usec;	
};



# 119 "/usr/include/sys/_structs.h" 3 4

# 142 "/usr/include/sys/_structs.h" 3 4

# 162 "/usr/include/sys/_structs.h" 3 4


# 213 "/usr/include/sys/_structs.h" 3 4









# 230 "/usr/include/sys/_structs.h" 3 4

# 78 "/usr/include/sys/resource.h" 2 3 4











typedef __uint64_t	rlim_t;





















































# 151 "/usr/include/sys/resource.h" 3 4
struct	rusage {
	struct timeval ru_utime;	
	struct timeval ru_stime;	



	




	long	ru_maxrss;		

	long	ru_ixrss;		
	long	ru_idrss;		
	long	ru_isrss;		
	long	ru_minflt;		
	long	ru_majflt;		
	long	ru_nswap;		
	long	ru_inblock;		
	long	ru_oublock;		
	long	ru_msgsnd;		
	long	ru_msgrcv;		
	long	ru_nsignals;		
	long	ru_nvcsw;		
	long	ru_nivcsw;		


};


















# 217 "/usr/include/sys/resource.h" 3 4





struct rlimit {
	rlim_t	rlim_cur;		
	rlim_t	rlim_max;		
};



















int	getpriority(int, id_t);

int	getiopolicy_np(int, int) __OSX_AVAILABLE_STARTING(1050, 20000);

int	getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int	getrusage(int, struct rusage *);
int	setpriority(int, id_t, int);

int	setiopolicy_np(int, int, int) __OSX_AVAILABLE_STARTING(1050, 20000);

int	setrlimit(int, __const struct rlimit *) __asm("_" "setrlimit" );


# 118 "/usr/include/sys/wait.h" 2 3 4


# 130 "/usr/include/sys/wait.h" 3 4


# 141 "/usr/include/sys/wait.h" 3 4






# 155 "/usr/include/sys/wait.h" 3 4

# 164 "/usr/include/sys/wait.h" 3 4






























# 1 "/usr/include/machine/endian.h" 1 3 4

# 28 "/usr/include/machine/endian.h" 3 4








# 1 "/usr/include/i386/endian.h" 1 3 4

# 28 "/usr/include/i386/endian.h" 3 4




# 65 "/usr/include/i386/endian.h" 3 4



































# 1 "/usr/include/sys/_endian.h" 1 3 4

# 28 "/usr/include/sys/_endian.h" 3 4


# 57 "/usr/include/sys/_endian.h" 3 4

# 89 "/usr/include/sys/_endian.h" 3 4










# 123 "/usr/include/sys/_endian.h" 3 4


# 1 "/usr/include/libkern/_OSByteOrder.h" 1 3 4

# 28 "/usr/include/libkern/_OSByteOrder.h" 3 4

























# 62 "/usr/include/libkern/_OSByteOrder.h" 3 4





# 1 "/usr/include/libkern/i386/_OSByteOrder.h" 1 3 4

# 28 "/usr/include/libkern/i386/_OSByteOrder.h" 3 4




# 41 "/usr/include/libkern/i386/_OSByteOrder.h" 3 4



static __inline__
__uint16_t
_OSSwapInt16(
    __uint16_t        _data
)
{
    return ((_data << 8) | (_data >> 8));
}

static __inline__
__uint32_t
_OSSwapInt32(
    __uint32_t        _data
)
{

    return __builtin_bswap32(_data);




}


static __inline__
__uint64_t
_OSSwapInt64(
    __uint64_t        _data
)
{
    return __builtin_bswap64(_data);
}

# 103 "/usr/include/libkern/i386/_OSByteOrder.h" 3 4

# 67 "/usr/include/libkern/_OSByteOrder.h" 2 3 4
















# 132 "/usr/include/libkern/_OSByteOrder.h" 3 4

# 125 "/usr/include/sys/_endian.h" 2 3 4







# 100 "/usr/include/i386/endian.h" 2 3 4

# 36 "/usr/include/machine/endian.h" 2 3 4






# 194 "/usr/include/sys/wait.h" 2 3 4







union wait {
	int	w_status;		
	


	struct {

		unsigned int	w_Termsig:7,	
				w_Coredump:1,	
				w_Retcode:8,	
				w_Filler:16;	







	} w_T;
	




	struct {

		unsigned int	w_Stopval:8,	
				w_Stopsig:8,	
				w_Filler:16;	






	} w_S;
};

















pid_t	wait(int *) __asm("_" "wait"  );
pid_t	waitpid(pid_t, int *, int) __asm("_" "waitpid"  );

int	waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid"  );


pid_t	wait3(int *, int, struct rusage *);
pid_t	wait4(pid_t, int *, int, struct rusage *);


# 66 "/usr/include/stdlib.h" 2 3 4


# 1 "/usr/include/alloca.h" 1 3 4

# 23 "/usr/include/alloca.h" 3 4













void	*alloca(size_t);		










# 68 "/usr/include/stdlib.h" 2 3 4













typedef	__darwin_ct_rune_t	ct_rune_t;




typedef __darwin_rune_t   	rune_t;






typedef	__darwin_wchar_t	wchar_t;



typedef struct {
	int quot;		
	int rem;		
} div_t;

typedef struct {
	long quot;		
	long rem;		
} ldiv_t;


typedef struct {
	long long quot;
	long long rem;
} lldiv_t;






















extern int __mb_cur_max;










void	 abort(void) __attribute__((__noreturn__));
int	 abs(int) __attribute__((__const__));
int	 atexit(void (*)(void));
double	 atof(__const char *);
int	 atoi(__const char *);
long	 atol(__const char *);

long long
	 atoll(__const char *);

void	*bsearch(__const void *, __const void *, size_t,
	    size_t, int (*)(__const void *, __const void *));
void	*calloc(size_t, size_t);
div_t	 div(int, int) __attribute__((__const__));
void	 exit(int) __attribute__((__noreturn__));
void	 free(void *);
char	*getenv(__const char *);
long	 labs(long) __attribute__((__const__));
ldiv_t	 ldiv(long, long) __attribute__((__const__));

long long
	 llabs(long long);
lldiv_t	 lldiv(long long, long long);

void	*malloc(size_t);
int	 mblen(__const char *, size_t);
size_t	 mbstowcs(wchar_t *  , __const char * , size_t);
int	 mbtowc(wchar_t * , __const char * , size_t);
int 	 posix_memalign(void **, size_t, size_t) __OSX_AVAILABLE_STARTING(1060, 30000);
void	 qsort(void *, size_t, size_t,
	    int (*)(__const void *, __const void *));
int	 rand(void);
void	*realloc(void *, size_t);
void	 srand(unsigned);
double	 strtod(__const char *, char **) __asm("_" "strtod" );
float	 strtof(__const char *, char **) __asm("_" "strtof" );
long	 strtol(__const char *, char **, int);
long double
	 strtold(__const char *, char **) ;

long long 
	 strtoll(__const char *, char **, int);

unsigned long
	 strtoul(__const char *, char **, int);

unsigned long long
	 strtoull(__const char *, char **, int);

int	 system(__const char *) __asm("_" "system"  );
size_t	 wcstombs(char * , __const wchar_t * , size_t);
int	 wctomb(char *, wchar_t);


void	_Exit(int) __attribute__((__noreturn__));
long	 a64l(__const char *);
double	 drand48(void);
char	*ecvt(double, int, int *, int *); 
double	 erand48(unsigned short[3]); 
char	*fcvt(double, int, int *, int *); 
char	*gcvt(double, int, char *); 
int	 getsubopt(char **, char * __const *, char **);
int	 grantpt(int);

char	*initstate(unsigned, char *, size_t); 



long	 jrand48(unsigned short[3]);
char	*l64a(long);
void	 lcong48(unsigned short[7]);
long	 lrand48(void);
char	*mktemp(char *);
int	 mkstemp(char *);
long	 mrand48(void); 
long	 nrand48(unsigned short[3]);
int	 posix_openpt(int);
char	*ptsname(int);
int	 putenv(char *) __asm("_" "putenv" );
long	 random(void);
int	 rand_r(unsigned *);

char	*realpath(__const char * , char * ) __asm("_" "realpath" "$DARWIN_EXTSN");



unsigned short
	*seed48(unsigned short[3]);
int	 setenv(__const char *, __const char *, int) __asm("_" "setenv" );

void	 setkey(__const char *) __asm("_" "setkey" );



char	*setstate(__const char *);
void	 srand48(long);

void	 srandom(unsigned);



int	 unlockpt(int);

int	 unsetenv(__const char *) __asm("_" "unsetenv" );







# 1 "/usr/include/machine/types.h" 1 3 4

# 28 "/usr/include/machine/types.h" 3 4








# 1 "/usr/include/i386/types.h" 1 3 4

# 28 "/usr/include/i386/types.h" 3 4




# 65 "/usr/include/i386/types.h" 3 4






# 1 "/usr/include/i386/_types.h" 1 3 4

# 71 "/usr/include/i386/types.h" 2 3 4







typedef	__signed char		int8_t;

typedef	unsigned char		u_int8_t;


typedef	short			int16_t;

typedef	unsigned short		u_int16_t;


typedef	int			int32_t;

typedef	unsigned int		u_int32_t;


typedef	long long		int64_t;

typedef	unsigned long long	u_int64_t;


typedef int64_t			register_t;






typedef __darwin_intptr_t	intptr_t;



typedef unsigned long		uintptr_t;




typedef u_int64_t		user_addr_t;	
typedef u_int64_t		user_size_t;	
typedef int64_t			user_ssize_t;
typedef int64_t			user_long_t;
typedef u_int64_t		user_ulong_t;
typedef int64_t			user_time_t;
typedef int64_t			user_off_t;







typedef u_int64_t		syscall_arg_t;





# 36 "/usr/include/machine/types.h" 2 3 4






# 256 "/usr/include/stdlib.h" 2 3 4


typedef	__darwin_dev_t	dev_t;




typedef	__darwin_mode_t	mode_t;



u_int32_t
	 arc4random(void);
void	 arc4random_addrandom(unsigned char * , int );
void	 arc4random_buf(void * , size_t ) __OSX_AVAILABLE_STARTING(1070, 40300);
void	 arc4random_stir(void);
u_int32_t
	 arc4random_uniform(u_int32_t ) __OSX_AVAILABLE_STARTING(1070, 40300);

int	 atexit_b(void (^)(void)) __OSX_AVAILABLE_STARTING(1060, 30200);
void	*bsearch_b(__const void *, __const void *, size_t,
	    size_t, int (^)(__const void *, __const void *)) __OSX_AVAILABLE_STARTING(1060, 30200);


	 
char	*cgetcap(char *, __const char *, int);
int	 cgetclose(void);
int	 cgetent(char **, char **, __const char *);
int	 cgetfirst(char **, char **);
int	 cgetmatch(__const char *, __const char *);
int	 cgetnext(char **, char **);
int	 cgetnum(char *, __const char *, long *);
int	 cgetset(__const char *);
int	 cgetstr(char *, __const char *, char **);
int	 cgetustr(char *, __const char *, char **);

int	 daemon(int, int) __asm("_" "daemon" "$1050") __OSX_AVAILABLE_BUT_DEPRECATED(1000, 1050, 20000, 20000);
char	*devname(dev_t, mode_t);
char	*devname_r(dev_t, mode_t, char *buf, int len);
char	*getbsize(int *, long *);
int	 getloadavg(double [], int);
__const char
	*getprogname(void);

int	 heapsort(void *, size_t, size_t,
	    int (*)(__const void *, __const void *));

int	 heapsort_b(void *, size_t, size_t,
	    int (^)(__const void *, __const void *)) __OSX_AVAILABLE_STARTING(1060, 30200);

int	 mergesort(void *, size_t, size_t,
	    int (*)(__const void *, __const void *));

int	 mergesort_b(void *, size_t, size_t,
	    int (^)(__const void *, __const void *)) __OSX_AVAILABLE_STARTING(1060, 30200);

void	 psort(void *, size_t, size_t,
	    int (*)(__const void *, __const void *)) __OSX_AVAILABLE_STARTING(1060, 30200);

void	 psort_b(void *, size_t, size_t,
	    int (^)(__const void *, __const void *)) __OSX_AVAILABLE_STARTING(1060, 30200);

void	 psort_r(void *, size_t, size_t, void *,
	    int (*)(void *, __const void *, __const void *))  __OSX_AVAILABLE_STARTING(1060, 30200);

void	 qsort_b(void *, size_t, size_t,
	    int (^)(__const void *, __const void *)) __OSX_AVAILABLE_STARTING(1060, 30200);

void	 qsort_r(void *, size_t, size_t, void *,
	    int (*)(void *, __const void *, __const void *));
int	 radixsort(__const unsigned char **, int, __const unsigned char *,
	    unsigned);
void	 setprogname(__const char *);
int	 sradixsort(__const unsigned char **, int, __const unsigned char *,
	    unsigned);
void	 sranddev(void);
void	 srandomdev(void);
void	*reallocf(void *, size_t);

long long
	 strtoq(__const char *, char **, int);
unsigned long long
	 strtouq(__const char *, char **, int);

extern char *suboptarg;		
void	*valloc(size_t);












# 10 "scz_core.c" 2

# 1 "/usr/include/string.h" 1 3 4

# 23 "/usr/include/string.h" 3 4

# 57 "/usr/include/string.h" 3 4























void	*memchr(__const void *, int, size_t);
int	 memcmp(__const void *, __const void *, size_t);
void	*memcpy(void *, __const void *, size_t);
void	*memmove(void *, __const void *, size_t);
void	*memset(void *, int, size_t);
char	*strcat(char *, __const char *);
char	*strchr(__const char *, int);
int	 strcmp(__const char *, __const char *);
int	 strcoll(__const char *, __const char *);
char	*strcpy(char *, __const char *);
size_t	 strcspn(__const char *, __const char *);
char	*strerror(int) __asm("_" "strerror" );
size_t	 strlen(__const char *);
char	*strncat(char *, __const char *, size_t);
int	 strncmp(__const char *, __const char *, size_t);
char	*strncpy(char *, __const char *, size_t);
char	*strpbrk(__const char *, __const char *);
char	*strrchr(__const char *, int);
size_t	 strspn(__const char *, __const char *);
char	*strstr(__const char *, __const char *);
char	*strtok(char *, __const char *);
size_t	 strxfrm(char *, __const char *, size_t);












char	*strtok_r(char *, __const char *, char **);











int	 strerror_r(int, char *, size_t);
char	*strdup(__const char *);
void	*memccpy(void *, __const void *, int, size_t);











char	*stpcpy(char *, __const char *);
char    *stpncpy(char *, __const char *, size_t) __OSX_AVAILABLE_STARTING(1070, 40300);
char	*strndup(__const char *, size_t) __OSX_AVAILABLE_STARTING(1070, 40300);
size_t   strnlen(__const char *, size_t) __OSX_AVAILABLE_STARTING(1070, 40300);
char	*strsignal(int sig);














void	*memmem(__const void *, size_t, __const void *, size_t) __OSX_AVAILABLE_STARTING(1070, 40300);
void     memset_pattern4(void *, __const void *, size_t) __OSX_AVAILABLE_STARTING(1050, 30000);
void     memset_pattern8(void *, __const void *, size_t) __OSX_AVAILABLE_STARTING(1050, 30000);
void     memset_pattern16(void *, __const void *, size_t) __OSX_AVAILABLE_STARTING(1050, 30000);

char	*strcasestr(__const char *, __const char *);
char	*strnstr(__const char *, __const char *, size_t);
size_t	 strlcat(char *, __const char *, size_t);
size_t	 strlcpy(char *, __const char *, size_t);
void	 strmode(int, char *);
char	*strsep(char **, __const char *);


void	 swab(__const void * , void * , ssize_t);








# 1 "/usr/include/strings.h" 1 3 4

# 23 "/usr/include/strings.h" 3 4

# 57 "/usr/include/strings.h" 3 4

















int	 bcmp(__const void *, __const void *, size_t) ___POSIX_C_DEPRECATED_STARTING_##200112L;
void	 bcopy(__const void *, void *, size_t) ___POSIX_C_DEPRECATED_STARTING_##200112L;
void	 bzero(void *, size_t) ___POSIX_C_DEPRECATED_STARTING_##200112L;
char	*index(__const char *, int) ___POSIX_C_DEPRECATED_STARTING_##200112L;
char	*rindex(__const char *, int) ___POSIX_C_DEPRECATED_STARTING_##200112L;


int	 ffs(int);
int	 strcasecmp(__const char *, __const char *);
int	 strncasecmp(__const char *, __const char *, size_t);





int	 ffsl(long) __OSX_AVAILABLE_STARTING(1050, 20000);
int	 fls(int) __OSX_AVAILABLE_STARTING(1050, 20000);
int	 flsl(long) __OSX_AVAILABLE_STARTING(1050, 20000);



# 1 "/usr/include/string.h" 1 3 4

# 23 "/usr/include/string.h" 3 4

# 57 "/usr/include/string.h" 3 4

# 95 "/usr/include/strings.h" 2 3 4




# 181 "/usr/include/string.h" 2 3 4










# 1 "/usr/include/secure/_string.h" 1 3 4

# 23 "/usr/include/secure/_string.h" 3 4
















# 52 "/usr/include/secure/_string.h" 3 4






static __inline void *
__inline_memcpy_chk (void *__dest, __const void *__src, size_t __len)
{
  return __builtin___memcpy_chk (__dest, __src, __len, __builtin_object_size (__dest, 0));
}






static __inline void *
__inline_memmove_chk (void *__dest, __const void *__src, size_t __len)
{
  return __builtin___memmove_chk (__dest, __src, __len, __builtin_object_size (__dest, 0));
}






static __inline void *
__inline_memset_chk (void *__dest, int __val, size_t __len)
{
  return __builtin___memset_chk (__dest, __val, __len, __builtin_object_size (__dest, 0));
}






static __inline char *
__inline_strcpy_chk (char * __dest, __const char * __src)
{
  return __builtin___strcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}







static __inline char *
__inline_stpcpy_chk (char *__dest, __const char *__src)
{
  return __builtin___stpcpy_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}






static __inline char *
__inline_stpncpy_chk (char * __dest, __const char * __src,
		      size_t __len)
{
  return __builtin___stpncpy_chk (__dest, __src, __len, __builtin_object_size (__dest, 2 > 1));
}







static __inline char *
__inline_strncpy_chk (char * __dest, __const char * __src,
		      size_t __len)
{
  return __builtin___strncpy_chk (__dest, __src, __len, __builtin_object_size (__dest, 2 > 1));
}






static __inline char *
__inline_strcat_chk (char * __dest, __const char * __src)
{
  return __builtin___strcat_chk (__dest, __src, __builtin_object_size (__dest, 2 > 1));
}







static __inline char *
__inline_strncat_chk (char * __dest, __const char * __src,
		      size_t __len)
{
  return __builtin___strncat_chk (__dest, __src, __len, __builtin_object_size (__dest, 2 > 1));
}


# 191 "/usr/include/string.h" 2 3 4


# 11 "scz_core.c" 2



int sczbuflen = 4 * 1048576;

struct scz_item		
 {
   unsigned char ch;
   struct scz_item *nxt;
 } *sczfreelist1=0;

struct scz_amalgam	
 {
   unsigned char phrase[2];
   int value;
 };

struct scz_item2		
 {
   unsigned char ch;
   int j;
   struct scz_item2 *nxt;
 } *sczphrasefreq[256], *scztmpphrasefreq, *sczfreelist2=0;

struct scz_block_alloc		
{
 void *mem_block;
 struct scz_block_alloc *next_block;
} *scz_allocated_blocks = 0, *scz_tmpblockalloc;




struct scz_item *new_scz_item()
{
 int j;
 struct scz_item *tmppt;

 if (sczfreelist1==0)
  {
   sczfreelist1 = (struct scz_item *)malloc(2048 * sizeof(struct scz_item));
   tmppt = sczfreelist1;
   for (j=2048-1; j!=0; j--) 
    {
     tmppt->nxt = tmppt + 1;	
     tmppt = tmppt->nxt;
    }
   tmppt->nxt = 0;
   
   scz_tmpblockalloc = (struct scz_block_alloc *)malloc(sizeof(struct scz_block_alloc));
   scz_tmpblockalloc->mem_block = sczfreelist1;
   scz_tmpblockalloc->next_block = scz_allocated_blocks;
   scz_allocated_blocks = scz_tmpblockalloc;
  }
 tmppt = sczfreelist1;
 sczfreelist1 = sczfreelist1->nxt;
 return tmppt;
}

void sczfree( struct scz_item *tmppt )
{
 tmppt->nxt = sczfreelist1;
 sczfreelist1 = tmppt;
}


struct scz_item2 *new_scz_item2()
{
 int j;
 struct scz_item2 *tmppt;

 if (sczfreelist2==0)
  {
   sczfreelist2 = (struct scz_item2 *)malloc(2048 * sizeof(struct scz_item2));
   tmppt = sczfreelist2;
   for (j=2048-1; j!=0; j--) 
    {
     tmppt->nxt = tmppt + 1;	
     tmppt = tmppt->nxt;
    }
   tmppt->nxt = 0;
   
   scz_tmpblockalloc = (struct scz_block_alloc *)malloc(sizeof(struct scz_block_alloc));
   scz_tmpblockalloc->mem_block = sczfreelist2;
   scz_tmpblockalloc->next_block = scz_allocated_blocks;
   scz_allocated_blocks = scz_tmpblockalloc;
  }
 tmppt = sczfreelist2;
 sczfreelist2 = sczfreelist2->nxt;
 return tmppt;
}

void sczfree2( struct scz_item2 *tmppt )
{
 tmppt->nxt = sczfreelist2;
 sczfreelist2 = tmppt;
}


void scz_cleanup()	
{			
 while (scz_allocated_blocks!=0)
  {
   scz_tmpblockalloc = scz_allocated_blocks;
   scz_allocated_blocks = scz_allocated_blocks->next_block;
   free(scz_tmpblockalloc->mem_block);
   free(scz_tmpblockalloc);
  }
 sczfreelist1 = 0;
 sczfreelist2 = 0;
}





void scz_add_item( struct scz_item **hd, struct scz_item **tl, unsigned char ch )
{
 struct scz_item *tmppt;

 tmppt = new_scz_item();
 tmppt->ch = ch;
 tmppt->nxt = 0;
 if (*hd==0) *hd = tmppt; else (*tl)->nxt = tmppt;
 *tl = tmppt;
}

# 57 "scz_compress_lib.c" 2
int *scz_freq2=0; 






void scz_add_sorted_nmax( struct scz_amalgam *list, unsigned char *phrase, int lngth, int value, int N )
{
 int j, k=0, m;

 if (value <= list[N-1].value) return;
 while ((k<N) && (list[k].value >= value)) k++;
 if (k==N) return;
 j = N-2;
 while (j>=k)
  { 
   list[j+1].value = list[j].value;  
   for (m=0; m<lngth; m++) list[j+1].phrase[m] = list[j].phrase[m];  
   j--;
  }
 list[k].value = value;
 for (j=0; j<lngth; j++) list[k].phrase[j] = phrase[j];
}






void scz_add_sorted_nmin( struct scz_amalgam *list, unsigned char *phrase, int lngth, int value, int N )
{
 int j, k=0, m;

 while ((k<N) && (list[k].value <= value)) k++;
 if (k==N) return;
 j = N-2;
 while (j>=k) 
  { 
   list[j+1].value = list[j].value;
   for (m=0; m<lngth; m++) list[j+1].phrase[m] = list[j].phrase[m];
   j--;
  }
 list[k].value = value;
 for (j=0; j<lngth; j++) list[k].phrase[j] = phrase[j];
}





void scz_analyze( struct scz_item *buffer0_hd, int *freq1, int *freq2 )
{
 int j, k;
 struct scz_item *ptr;

 ((__builtin_object_size ( freq1, 0) != (size_t) -1)				   ? __builtin___memset_chk ( freq1,  0,  sizeof(int)*256 , __builtin_object_size ( freq1, 0))	   : __inline_memset_chk ( freq1,  0,  sizeof(int)*256 ));
 ((__builtin_object_size ( freq2, 0) != (size_t) -1)				   ? __builtin___memset_chk ( freq2,  0,  sizeof(int)*256*256 , __builtin_object_size ( freq2, 0))	   : __inline_memset_chk ( freq2,  0,  sizeof(int)*256*256 ));
 ptr = buffer0_hd;
 if (ptr==0) return;
 k = ptr->ch;
 freq1[k]++;
 ptr = ptr->nxt;
 while (ptr!=0)
  {
   j = k;
   k = ptr->ch;
   freq1[k]++;
   freq2[j*256+k]++;
   ptr = ptr->nxt;
  }
}







int scz_compress_iter( struct scz_item **buffer0_hd )
{
 int nreplace=250;
 int freq1[256], markerlist[256];
 int i, j, k, replaced, nreplaced, sz3=0, saved=0, saved_pairfreq[256], saved_charfreq[257];
 struct scz_item *head1, *head2, *bufpt, *tmpbuf, *cntpt;
 unsigned char word[10], forcingchar;
 struct scz_amalgam char_freq[257], phrase_freq_max[256];

 
 
 if (scz_freq2==0) scz_freq2 = (int *)malloc(256*256*sizeof(int));
 scz_analyze( *buffer0_hd, freq1, scz_freq2 );

 
 ((__builtin_object_size ( saved_pairfreq, 0) != (size_t) -1)				   ? __builtin___memset_chk ( saved_pairfreq,  0,  256 * sizeof(int) , __builtin_object_size ( saved_pairfreq, 0))	   : __inline_memset_chk ( saved_pairfreq,  0,  256 * sizeof(int) ));
 ((__builtin_object_size ( saved_charfreq, 0) != (size_t) -1)				   ? __builtin___memset_chk ( saved_charfreq,  0,  256 * sizeof(int) , __builtin_object_size ( saved_charfreq, 0))	   : __inline_memset_chk ( saved_charfreq,  0,  256 * sizeof(int) ));
 for (k=0; k<256; k++)
  {
   char_freq[k].value = 1073741824;
   phrase_freq_max[k].value = 0;
  }

 
 for (j=0; j!=256; j++) 
  {
   word[0] = j;
   scz_add_sorted_nmin( char_freq, word, 1, freq1[j], nreplace+1 );
  }

 
 i = 0;  
 for (k=0; k!=256; k++) 
  for (j=0; j!=256; j++) 
   if (scz_freq2[j*256+k]!=0)
    {
     word[0] = j;  word[1] = k;
     scz_add_sorted_nmax( phrase_freq_max, word, 2, scz_freq2[j*256+k], nreplace );
    }

 
 
 
 

 head1 = 0;	head2 = 0;
 forcingchar = char_freq[0].phrase[0];
 k = -1;  j = 0;
 while ((j<nreplace) && (char_freq[j+1].value < phrase_freq_max[j].value - 3))
  { j++;   k = k + phrase_freq_max[j].value - char_freq[j+1].value; }
 nreplaced = j;

 if (nreplaced == 0) return 0; 

 









((__builtin_object_size ( sczphrasefreq, 0) != (size_t) -1)				   ? __builtin___memset_chk ( sczphrasefreq,  0,  256 * sizeof(struct scz_item2 *) , __builtin_object_size ( sczphrasefreq, 0))	   : __inline_memset_chk ( sczphrasefreq,  0,  256 * sizeof(struct scz_item2 *) ));
for (j=0; j!=256; j++) markerlist[j] = nreplaced+1;
for (j=0; j!=nreplaced+1; j++) markerlist[ char_freq[j].phrase[0] ] = j;
for (j=0; j!=nreplaced; j++)
 if (phrase_freq_max[j].value>0)
  {
   scztmpphrasefreq = new_scz_item2();
   scztmpphrasefreq->ch = phrase_freq_max[j].phrase[1];
   scztmpphrasefreq->j = j;
   k = phrase_freq_max[j].phrase[0];
   scztmpphrasefreq->nxt = sczphrasefreq[k];
   sczphrasefreq[k] = scztmpphrasefreq;
  }


 
 bufpt = *buffer0_hd;
 if (nreplaced>0)
 while (bufpt!=0)
  {
   replaced = 0;
   if (bufpt->nxt!=0)
    {  
     k = bufpt->ch;
     if (sczphrasefreq[k]==0) j = nreplaced;
     else
      { unsigned char tmpch;
	tmpch = bufpt->nxt->ch; 
	scztmpphrasefreq = sczphrasefreq[k];
	while ((scztmpphrasefreq!=0) && (scztmpphrasefreq->ch != tmpch)) scztmpphrasefreq = scztmpphrasefreq->nxt;
        if (scztmpphrasefreq==0) j = nreplaced; else j = scztmpphrasefreq->j;
      }

     if (j<nreplaced)
      { 
	saved++;
	saved_pairfreq[j]++;		
	bufpt = bufpt->nxt->nxt;	
	replaced = 1;
      }
    }
   if (!replaced)
    {  
     j = markerlist[ bufpt->ch ];
     if (j<=nreplaced)
      {	
	saved--;
	saved_charfreq[j]--;		
      }
     bufpt = bufpt->nxt;
    }
  }

 // printf("%d saved\n", saved);
 if (saved<=1) return 0; 

 
 
 
 
 scz_add_item( &head1, &head2, char_freq[0].phrase[0] );	
 scz_add_item( &head1, &head2, 0 );	
 cntpt = head2;
 k = 0;  saved = 0;
 for (j=0; j<nreplaced; j++)
  if (saved_pairfreq[j] + saved_charfreq[j+1] > 3)
   { unsigned char ch;
    saved = saved + saved_pairfreq[j] + saved_charfreq[j+1] - 3;
    ch = char_freq[j+1].phrase[0];
    scz_add_item( &head1, &head2, ch );  
    char_freq[k+1].phrase[0] = ch;

    ch = phrase_freq_max[j].phrase[0];
    scz_add_item( &head1, &head2, ch );	 
    phrase_freq_max[k].phrase[0] = ch;

    ch = phrase_freq_max[j].phrase[1];
    scz_add_item( &head1, &head2, ch );	 
    phrase_freq_max[k].phrase[1] = ch;
    k++;
   }
 saved = saved + saved_charfreq[0];
 if ((k == 0) || (saved < 6)) 
  { 
   
   for (j=0; j!=256; j++) 
    while (sczphrasefreq[j] != 0)
     { scztmpphrasefreq = sczphrasefreq[j]; sczphrasefreq[j] = sczphrasefreq[j]->nxt; sczfree2(scztmpphrasefreq); }

      
   while (head1 != 0)
    {
     bufpt = head1->nxt;
     sczfree(head1);
     head1 = bufpt;
    }

   return 0; 
  }

 sz3 = 3 * (k + 1);
 cntpt->ch = k;		
 nreplaced = k;
 scz_add_item( &head1, &head2, 91 );	

 
 
 for (j=0; j!=256; j++) 
  while (sczphrasefreq[j] != 0)
   { scztmpphrasefreq = sczphrasefreq[j]; sczphrasefreq[j] = sczphrasefreq[j]->nxt; sczfree2(scztmpphrasefreq); }
 
 for (j=0; j!=nreplaced; j++)
  if (phrase_freq_max[j].value>0)
   {
    scztmpphrasefreq = new_scz_item2();
    scztmpphrasefreq->ch = phrase_freq_max[j].phrase[1];
    scztmpphrasefreq->j = j;
    k = phrase_freq_max[j].phrase[0];
    scztmpphrasefreq->nxt = sczphrasefreq[k];
    sczphrasefreq[k] = scztmpphrasefreq;
   }

for (j=0; j!=256; j++) markerlist[j] = nreplaced+1;
for (j=0; j!=nreplaced+1; j++) markerlist[ char_freq[j].phrase[0] ] = j;
// printf("Replacing %d\n", nreplaced);

 bufpt = *buffer0_hd;
 while (bufpt!=0)
  {
   sz3++;
   replaced = 0;
   if (bufpt->nxt!=0)
    {  
     k = bufpt->ch;
     if (sczphrasefreq[k]==0) j = nreplaced;
     else
      { unsigned char tmpch;
	tmpch = bufpt->nxt->ch; 
	scztmpphrasefreq = sczphrasefreq[k];
	while ((scztmpphrasefreq!=0) && (scztmpphrasefreq->ch != tmpch)) scztmpphrasefreq = scztmpphrasefreq->nxt;
        if (scztmpphrasefreq==0) j = nreplaced; else j = scztmpphrasefreq->j;
      }

     if (j<nreplaced)
      { 
	bufpt->ch = char_freq[j+1].phrase[0];
	tmpbuf = bufpt->nxt;
	bufpt->nxt = tmpbuf->nxt;
	sczfree( tmpbuf );
	replaced = 1;
      }
    }
   if (!replaced)
    {  
     j = markerlist[ bufpt->ch ];
     if (j<=nreplaced)
      {	
       tmpbuf = new_scz_item();
       tmpbuf->ch = bufpt->ch;
       tmpbuf->nxt = bufpt->nxt;
       bufpt->nxt = tmpbuf;
       bufpt->ch = forcingchar;
       bufpt = tmpbuf;
       sz3 = sz3 + 1;
      }
    }

   bufpt = bufpt->nxt;
  }

 
 head2->nxt = *buffer0_hd;
 *buffer0_hd = head1;

 
 for (j=0; j!=256; j++) 
  while (sczphrasefreq[j] != 0)
   { scztmpphrasefreq = sczphrasefreq[j]; sczphrasefreq[j] = sczphrasefreq[j]->nxt; sczfree2(scztmpphrasefreq); }

 return sz3;
}











int Scz_Compress_Seg( struct scz_item **buffer0_hd, int sz1 )
{
 struct scz_item *tmpbuf_hd=0, *tmpbuf_tl=0;
 int sz2, iter=0;

 
 sz2 = scz_compress_iter( buffer0_hd );
 while ((sz2!=0) && (iter<255))
  {
   sz1 = sz2;
   sz2 = scz_compress_iter( buffer0_hd );
   iter++;  
  }

 scz_add_item( &tmpbuf_hd, &tmpbuf_tl, 101 );   
 scz_add_item( &tmpbuf_hd, &tmpbuf_tl, 98 );
 scz_add_item( &tmpbuf_hd, &tmpbuf_tl, iter );  
 scz_add_item( &tmpbuf_hd, &tmpbuf_tl, sz1>>16 );         
 scz_add_item( &tmpbuf_hd, &tmpbuf_tl, (sz1>>8) & 255 );  
 scz_add_item( &tmpbuf_hd, &tmpbuf_tl, sz1 & 255 );       

 tmpbuf_tl->nxt = *buffer0_hd;
 *buffer0_hd = tmpbuf_hd;
 return 1;
}



long Scz_get_file_length( FILE *fp )
{
  long len, cur;
  cur = ftell( fp );            
  fseek( fp, 0L, 2 );    
  len = ftell( fp );            
  fseek( fp, cur, 0 );   
  return( len );
}










int Scz_Compress_File( char *infilename, char *outfilename )
{
 struct scz_item *buffer0_hd=0, *buffer0_tl=0, *bufpt;
 int sz1=0, sz2=0, szi, success=1, flen, buflen;
 unsigned char ch, chksum;
 FILE *infile=0, *outfile=0;

 infile = fopen(infilename,"rb");
 if (infile==0) {printf("ERROR: Cannot open input file '%s'.  Exiting\n", infilename); exit(1);}

 outfile = fopen(outfilename,"wb");
 if (outfile==0) {printf("ERROR: Cannot open output file '%s' for writing.  Exiting\n", outfilename); exit(1);}

 flen = Scz_get_file_length( infile );
 buflen = flen / sczbuflen + 1;
 buflen = flen / buflen + 1;
 if (buflen>=16777215) {printf("Error: Buffer length too large.\n"); exit(0);}

 
 ch = getc(infile);
 while (!feof(infile))
  { 

    chksum = 0;  szi = 0;
    buffer0_hd = 0;   buffer0_tl = 0;
    while ((!feof(infile)) && (szi < buflen))
     {
      scz_add_item( &buffer0_hd, &buffer0_tl, ch );
      sz1++;  szi++;  chksum += ch;  
      ch = getc(infile);
     }

   success = success & Scz_Compress_Seg( &buffer0_hd, szi );

   
   while (buffer0_hd!=0)
    {
     fputc( buffer0_hd->ch, outfile );
     sz2++;
     bufpt = buffer0_hd;
     buffer0_hd = buffer0_hd->nxt;
     sczfree(bufpt);
    }
   fprintf(outfile,"%c", chksum); 
   sz2++;
   if (feof(infile)) fprintf(outfile,"]");	
   else fprintf(outfile,"[");			
   sz2++;

  } 
 fclose(infile);
 fclose(outfile);

 printf("Initial size = %d,  Final size = %d\n", sz1, sz2);
 printf("Compression ratio = %g : 1\n", (float)sz1 / (float)sz2 );
 free(scz_freq2);
 scz_freq2 = 0;
 return success;
}














int Scz_Compress_Buffer2File( unsigned char *buffer, int N, char *outfilename )
{
 struct scz_item *buffer0_hd=0, *buffer0_tl=0, *bufpt;
 int sz1=0, sz2=0, szi, success=1, buflen;
 unsigned char chksum;
 FILE *outfile=0;

 outfile = fopen(outfilename,"wb");
 if (outfile==0) {printf("ERROR: Cannot open output file '%s' for writing.  Exiting\n", outfilename); exit(1);}

 buflen = N / sczbuflen + 1;
 buflen = N / buflen + 1;
 if (buflen>=16777215) {printf("Error: Buffer length too large.\n"); exit(0);}

 while (sz1 < N)
  { 

    chksum = 0;  szi = 0;
    if (N-sz1 < buflen) buflen = N-sz1;

    
    buffer0_hd = 0;   buffer0_tl = 0;
    while (szi < buflen)
     {
      scz_add_item( &buffer0_hd, &buffer0_tl, buffer[sz1] );
      chksum += buffer[sz1];  
      sz1++;  szi++;  
     }

   success = success & Scz_Compress_Seg( &buffer0_hd, szi );

   
   while (buffer0_hd!=0)
    {
     fputc( buffer0_hd->ch, outfile );
     sz2++;
     bufpt = buffer0_hd;
     buffer0_hd = buffer0_hd->nxt;
     sczfree(bufpt);
    }
   fprintf(outfile,"%c", chksum); 
   sz2++;
   if (sz1 >= N) fprintf(outfile,"]");	
   else fprintf(outfile,"[");		
   sz2++;

  } 
 fclose(outfile);

 printf("Initial size = %d,  Final size = %d\n", sz1, sz2);
 printf("Compression ratio = %g : 1\n", (float)sz1 / (float)sz2 );
 free(scz_freq2);
 scz_freq2 = 0;
 return success;
}












 


int Scz_Compress_Buffer2Buffer( char *inbuffer, int N, char **outbuffer, int *M, int lastbuf_flag )
{
 struct scz_item *buffer0_hd=0, *buffer0_tl=0, *bufpt;
 int sz1=0, sz2=0, szi, success=1, buflen;
 unsigned char chksum;

 buflen = N;
 if (buflen>=16777215) {printf("Error: Buffer length too large.\n"); exit(0);}

 chksum = 0;  szi = 0;
 if (N-szi < buflen) buflen = N-szi;
 
 buffer0_hd = 0;   buffer0_tl = 0;
 while (szi < buflen)
  {
   scz_add_item( &buffer0_hd, &buffer0_tl, inbuffer[sz1] );
   chksum += inbuffer[sz1];  
   sz1++;  szi++;
  }

 success = success & Scz_Compress_Seg( &buffer0_hd, szi );

 
 sz2 = 0;	
 bufpt = buffer0_hd;
 while (bufpt!=0) { sz2++;  bufpt = bufpt->nxt;  }
 *outbuffer = (char *)malloc((sz2+2)*sizeof(char));
 sz2 = 0;
 while (buffer0_hd!=0)
  {
   (*outbuffer)[sz2++] = buffer0_hd->ch;
   bufpt = buffer0_hd;
   buffer0_hd = buffer0_hd->nxt;
   sczfree(bufpt);
  }
 (*outbuffer)[sz2++] = chksum; 
 if (lastbuf_flag) (*outbuffer)[sz2++] = ']';	
 else (*outbuffer)[sz2++] = '[';			

 *M = sz2;

 // printf("Initial size = %d,  Final size = %d\n", sz1, sz2);
 // printf("Compression ratio = %g : 1\n", (float)sz1 / (float)sz2 );
 free(scz_freq2);
 scz_freq2 = 0;
 return success;
}

# 41 "scz_compress.c" 2







int main( int argc, char *argv[] )
{
 char outfname[4096];
 int j, k, verbose=0;

 
 j = 1;  k = 0;
 while (argc>j)
  { 
   if (argv[j][0]=='-')
    { 
     if (strcasecmp(argv[j],"-v")==0) verbose = 1;
     else
     if (strcasecmp(argv[j],"-b")==0) 
      {
	j++;
 	if (j==argc) {printf("Missing -b blocksize value.\n"); exit(0);}
	if (sscanf(argv[j],"%d",&sczbuflen)!=1) {printf("Bad -b blocksize value '%s'.\n",argv[j]); exit(0);}
      }
     else {printf("\nERROR:  Unknown command line option /%s/.\n", argv[j]); exit(0); }
    } 
   else
    { 
     k = k + 1;
     if (strlen(argv[j])>4090) {printf("Error: file name too long.\n"); exit(0);}
     ((__builtin_object_size (outfname, 0) != (size_t) -1)				   ? __builtin___strcpy_chk (outfname, argv[j], __builtin_object_size (outfname, 2 > 1))		   : __inline_strcpy_chk (outfname, argv[j]));	
     if (outfname[strlen(outfname)-1]=='.') outfname[strlen(outfname)-1] = '\0';
     ((__builtin_object_size (outfname, 0) != (size_t) -1)				   ? __builtin___strcat_chk (outfname,  ".scz", __builtin_object_size (outfname, 2 > 1))		   : __inline_strcat_chk (outfname,  ".scz"));
     printf("\n Writing output to file %s\n", outfname);
     Scz_Compress_File( argv[j], outfname );	
    } 
   j = j + 1;
  } 
 if (k==0) { printf("Error: Missing file name. Exiting."); exit(0); }
 
 return 0;
}
