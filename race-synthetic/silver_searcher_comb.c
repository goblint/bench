/* The Silver Searcher (https://github.com/ggreer/the_silver_searcher).
 * Revision: a61f1780b64266587e7bc30f0f5f71c6cca97c0f
 * License: https://github.com/ggreer/the_silver_searcher/blob/master/LICENSE 
 */

typedef long ptrdiff_t;
typedef unsigned long size_t;
typedef int wchar_t;
struct __anonstruct_max_align_t_896270833 {
   long long __max_align_ll __attribute__((__aligned__(__alignof__(long long )))) ;
   long double __max_align_ld __attribute__((__aligned__(__alignof__(long double )))) ;
};
typedef struct __anonstruct_max_align_t_896270833 max_align_t;
typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long __int64_t;
typedef unsigned long __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long __quad_t;
typedef unsigned long __u_quad_t;
typedef long __intmax_t;
typedef unsigned long __uintmax_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned long __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __off64_t;
typedef int __pid_t;
struct __anonstruct___fsid_t_109580352 {
   int __val[2] ;
};
typedef struct __anonstruct___fsid_t_109580352 __fsid_t;
typedef long __clock_t;
typedef unsigned long __rlim_t;
typedef unsigned long __rlim64_t;
typedef unsigned int __id_t;
typedef long __time_t;
typedef unsigned int __useconds_t;
typedef long __suseconds_t;
typedef long __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __blkcnt64_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsblkcnt64_t;
typedef unsigned long __fsfilcnt_t;
typedef unsigned long __fsfilcnt64_t;
typedef long __fsword_t;
typedef long __ssize_t;
typedef long __syscall_slong_t;
typedef unsigned long __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __time_t time_t;
struct timespec {
   __time_t tv_sec ;
   __syscall_slong_t tv_nsec ;
};
typedef __pid_t pid_t;
struct sched_param {
   int sched_priority ;
};
typedef unsigned long __cpu_mask;
struct __anonstruct_cpu_set_t_826868708 {
   __cpu_mask __bits[1024UL / (8UL * sizeof(__cpu_mask ))] ;
};
typedef struct __anonstruct_cpu_set_t_826868708 cpu_set_t;
typedef __clock_t clock_t;
struct tm {
   int tm_sec ;
   int tm_min ;
   int tm_hour ;
   int tm_mday ;
   int tm_mon ;
   int tm_year ;
   int tm_wday ;
   int tm_yday ;
   int tm_isdst ;
   long tm_gmtoff ;
   char const *tm_zone ;
};
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
struct itimerspec {
   struct timespec it_interval ;
   struct timespec it_value ;
};
struct sigevent ;
struct __locale_data ;
struct __locale_struct {
   struct __locale_data *__locales[13] ;
   unsigned short const *__ctype_b ;
   int const *__ctype_tolower ;
   int const *__ctype_toupper ;
   char const *__names[13] ;
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
struct __anonstruct___value32_817613185 {
   unsigned int __low ;
   unsigned int __high ;
};
union __anonunion___atomic_wide_counter_949521040 {
   unsigned long long __value64 ;
   struct __anonstruct___value32_817613185 __value32 ;
};
typedef union __anonunion___atomic_wide_counter_949521040 __atomic_wide_counter;
struct __pthread_internal_list {
   struct __pthread_internal_list *__prev ;
   struct __pthread_internal_list *__next ;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_internal_slist {
   struct __pthread_internal_slist *__next ;
};
typedef struct __pthread_internal_slist __pthread_slist_t;
struct __pthread_mutex_s {
   int __lock ;
   unsigned int __count ;
   int __owner ;
   unsigned int __nusers ;
   int __kind ;
   short __spins ;
   short __elision ;
   __pthread_list_t __list ;
};
struct __pthread_rwlock_arch_t {
   unsigned int __readers ;
   unsigned int __writers ;
   unsigned int __wrphase_futex ;
   unsigned int __writers_futex ;
   unsigned int __pad3 ;
   unsigned int __pad4 ;
   int __cur_writer ;
   int __shared ;
   signed char __rwelision ;
   unsigned char __pad1[7] ;
   unsigned long __pad2 ;
   unsigned int __flags ;
};
struct __pthread_cond_s {
   __atomic_wide_counter __wseq ;
   __atomic_wide_counter __g1_start ;
   unsigned int __g_refs[2] ;
   unsigned int __g_size[2] ;
   unsigned int __g1_orig_size ;
   unsigned int __wrefs ;
   unsigned int __g_signals[2] ;
};
typedef unsigned int __tss_t;
typedef unsigned long __thrd_t;
struct __anonstruct___once_flag_949521041 {
   int __data ;
};
typedef struct __anonstruct___once_flag_949521041 __once_flag;
typedef unsigned long pthread_t;
union __anonunion_pthread_mutexattr_t_488594144 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_mutexattr_t_488594144 pthread_mutexattr_t;
union __anonunion_pthread_condattr_t_488594145 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_condattr_t_488594145 pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t {
   char __size[56] ;
   long __align ;
};
typedef union pthread_attr_t pthread_attr_t;
union __anonunion_pthread_mutex_t_335460617 {
   struct __pthread_mutex_s __data ;
   char __size[40] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_335460617 pthread_mutex_t;
union __anonunion_pthread_cond_t_951761805 {
   struct __pthread_cond_s __data ;
   char __size[48] ;
   long long __align ;
};
typedef union __anonunion_pthread_cond_t_951761805 pthread_cond_t;
union __anonunion_pthread_rwlock_t_656928968 {
   struct __pthread_rwlock_arch_t __data ;
   char __size[56] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlock_t_656928968 pthread_rwlock_t;
union __anonunion_pthread_rwlockattr_t_145707745 {
   char __size[8] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlockattr_t_145707745 pthread_rwlockattr_t;
typedef int volatile pthread_spinlock_t;
union __anonunion_pthread_barrier_t_145707746 {
   char __size[32] ;
   long __align ;
};
typedef union __anonunion_pthread_barrier_t_145707746 pthread_barrier_t;
union __anonunion_pthread_barrierattr_t_951761806 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_barrierattr_t_951761806 pthread_barrierattr_t;
typedef long __jmp_buf[8];
struct __anonstruct___sigset_t_764561023 {
   unsigned long __val[1024UL / (8UL * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___sigset_t_764561023 __sigset_t;
struct __jmp_buf_tag {
   __jmp_buf __jmpbuf ;
   int __mask_was_saved ;
   __sigset_t __saved_mask ;
};
enum __anonenum_34415463 {
    PTHREAD_CREATE_JOINABLE = 0,
    PTHREAD_CREATE_DETACHED = 1
} ;
enum __anonenum_508643754 {
    PTHREAD_MUTEX_TIMED_NP = 0,
    PTHREAD_MUTEX_RECURSIVE_NP = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP = 3,
    PTHREAD_MUTEX_NORMAL = 0,
    PTHREAD_MUTEX_RECURSIVE = 1,
    PTHREAD_MUTEX_ERRORCHECK = 2,
    PTHREAD_MUTEX_DEFAULT = 0
} ;
enum __anonenum_931900394 {
    PTHREAD_MUTEX_STALLED = 0,
    PTHREAD_MUTEX_STALLED_NP = 0,
    PTHREAD_MUTEX_ROBUST = 1,
    PTHREAD_MUTEX_ROBUST_NP = 1
} ;
enum __anonenum_205214487 {
    PTHREAD_PRIO_NONE = 0,
    PTHREAD_PRIO_INHERIT = 1,
    PTHREAD_PRIO_PROTECT = 2
} ;
enum __anonenum_25043950 {
    PTHREAD_RWLOCK_PREFER_READER_NP = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP = 2,
    PTHREAD_RWLOCK_DEFAULT_NP = 0
} ;
enum __anonenum_436439511 {
    PTHREAD_INHERIT_SCHED = 0,
    PTHREAD_EXPLICIT_SCHED = 1
} ;
enum __anonenum_998661166 {
    PTHREAD_SCOPE_SYSTEM = 0,
    PTHREAD_SCOPE_PROCESS = 1
} ;
enum __anonenum_146137331 {
    PTHREAD_PROCESS_PRIVATE = 0,
    PTHREAD_PROCESS_SHARED = 1
} ;
struct _pthread_cleanup_buffer {
   void (*__routine)(void * ) ;
   void *__arg ;
   int __canceltype ;
   struct _pthread_cleanup_buffer *__prev ;
};
enum __anonenum_53396917 {
    PTHREAD_CANCEL_ENABLE = 0,
    PTHREAD_CANCEL_DISABLE = 1
} ;
enum __anonenum_904563783 {
    PTHREAD_CANCEL_DEFERRED = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS = 1
} ;
struct __cancel_jmp_buf_tag {
   __jmp_buf __cancel_jmp_buf ;
   int __mask_was_saved ;
};
struct __anonstruct___pthread_unwind_buf_t_530692248 {
   struct __cancel_jmp_buf_tag __cancel_jmp_buf[1] ;
   void *__pad[4] ;
};
typedef struct __anonstruct___pthread_unwind_buf_t_530692248 __attribute__((__aligned__)) __pthread_unwind_buf_t;
struct __pthread_cleanup_frame {
   void (*__cancel_routine)(void * ) ;
   void *__cancel_arg ;
   int __do_it ;
   int __cancel_type ;
};
enum __anonenum_18926444 {
    _ISupper = 256,
    _ISlower = 512,
    _ISalpha = 1024,
    _ISdigit = 2048,
    _ISxdigit = 4096,
    _ISspace = 8192,
    _ISprint = 16384,
    _ISgraph = 32768,
    _ISblank = 1,
    _IScntrl = 2,
    _ISpunct = 4,
    _ISalnum = 8
} ;
typedef __ino_t ino_t;
typedef __ino64_t ino64_t;
struct dirent {
   __ino_t d_ino ;
   __off_t d_off ;
   unsigned short d_reclen ;
   unsigned char d_type ;
   char d_name[256] ;
};
struct dirent64 {
   __ino64_t d_ino ;
   __off64_t d_off ;
   unsigned short d_reclen ;
   unsigned char d_type ;
   char d_name[256] ;
};
enum __anonenum_513775621 {
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
} ;
struct __dirstream ;
typedef struct __dirstream DIR;
typedef __builtin_va_list __gnuc_va_list;
union __anonunion___value_628077854 {
   unsigned int __wch ;
   char __wchb[4] ;
};
struct __anonstruct___mbstate_t_736174730 {
   int __count ;
   union __anonunion___value_628077854 __value ;
};
typedef struct __anonstruct___mbstate_t_736174730 __mbstate_t;
struct _G_fpos_t {
   __off_t __pos ;
   __mbstate_t __state ;
};
typedef struct _G_fpos_t __fpos_t;
struct _G_fpos64_t {
   __off64_t __pos ;
   __mbstate_t __state ;
};
typedef struct _G_fpos64_t __fpos64_t;
struct _IO_FILE ;
typedef struct _IO_FILE __FILE;
typedef struct _IO_FILE FILE;
struct _IO_marker ;
struct _IO_codecvt ;
struct _IO_wide_data ;
typedef void _IO_lock_t;
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   struct _IO_codecvt *_codecvt ;
   struct _IO_wide_data *_wide_data ;
   struct _IO_FILE *_freeres_list ;
   void *_freeres_buf ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
typedef __ssize_t cookie_read_function_t(void *__cookie , char *__buf , size_t __nbytes );
typedef __ssize_t cookie_write_function_t(void *__cookie , char const *__buf , size_t __nbytes );
typedef int cookie_seek_function_t(void *__cookie , __off64_t *__pos , int __w );
typedef int cookie_close_function_t(void *__cookie );
struct _IO_cookie_io_functions_t {
   cookie_read_function_t *read ;
   cookie_write_function_t *write ;
   cookie_seek_function_t *seek ;
   cookie_close_function_t *close ;
};
typedef struct _IO_cookie_io_functions_t cookie_io_functions_t;
typedef __gnuc_va_list va_list;
typedef __ssize_t ssize_t;
typedef __fpos_t fpos_t;
typedef __fpos64_t fpos64_t;
struct obstack ;
struct __anonstruct_div_t_773697287 {
   int quot ;
   int rem ;
};
typedef struct __anonstruct_div_t_773697287 div_t;
struct __anonstruct_ldiv_t_790849867 {
   long quot ;
   long rem ;
};
typedef struct __anonstruct_ldiv_t_790849867 ldiv_t;
struct __anonstruct_lldiv_t_103911545 {
   long long quot ;
   long long rem ;
};
typedef struct __anonstruct_lldiv_t_103911545 lldiv_t;
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t;
typedef __sigset_t sigset_t;
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
typedef long __fd_mask;
struct __anonstruct_fd_set_356711149 {
   __fd_mask fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef struct __anonstruct_fd_set_356711149 fd_set;
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
struct random_data {
   int32_t *fptr ;
   int32_t *rptr ;
   int32_t *state ;
   int rand_type ;
   int rand_deg ;
   int rand_sep ;
   int32_t *end_ptr ;
};
struct drand48_data {
   unsigned short __x[3] ;
   unsigned short __old_x[3] ;
   unsigned short __c ;
   unsigned short __init ;
   unsigned long long __a ;
};
typedef int (*__compar_fn_t)(void const * , void const * );
typedef int (*comparison_fn_t)(void const * , void const * );
typedef int (*__compar_d_fn_t)(void const * , void const * , void * );
struct stat {
   __dev_t st_dev ;
   __ino_t st_ino ;
   __nlink_t st_nlink ;
   __mode_t st_mode ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   int __pad0 ;
   __dev_t st_rdev ;
   __off_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   __syscall_slong_t __glibc_reserved[3] ;
};
struct stat64 {
   __dev_t st_dev ;
   __ino64_t st_ino ;
   __nlink_t st_nlink ;
   __mode_t st_mode ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   int __pad0 ;
   __dev_t st_rdev ;
   __off_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt64_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   __syscall_slong_t __glibc_reserved[3] ;
};
typedef signed char __s8;
typedef unsigned char __u8;
typedef short __s16;
typedef unsigned short __u16;
typedef int __s32;
typedef unsigned int __u32;
typedef long long __s64;
typedef unsigned long long __u64;
struct __anonstruct___kernel_fd_set_603278005 {
   unsigned long fds_bits[1024UL / (8UL * sizeof(long ))] ;
};
typedef struct __anonstruct___kernel_fd_set_603278005 __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int );
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned long __kernel_old_dev_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
struct __anonstruct___kernel_fsid_t_951761807 {
   int val[2] ;
};
typedef struct __anonstruct___kernel_fsid_t_951761807 __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char *__kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;
typedef __u16 __sum16;
typedef __u32 __wsum;
typedef unsigned int __poll_t;
struct statx_timestamp {
   __s64 tv_sec ;
   __u32 tv_nsec ;
   __s32 __reserved ;
};
struct statx {
   __u32 stx_mask ;
   __u32 stx_blksize ;
   __u64 stx_attributes ;
   __u32 stx_nlink ;
   __u32 stx_uid ;
   __u32 stx_gid ;
   __u16 stx_mode ;
   __u16 __spare0[1] ;
   __u64 stx_ino ;
   __u64 stx_size ;
   __u64 stx_blocks ;
   __u64 stx_attributes_mask ;
   struct statx_timestamp stx_atime ;
   struct statx_timestamp stx_btime ;
   struct statx_timestamp stx_ctime ;
   struct statx_timestamp stx_mtime ;
   __u32 stx_rdev_major ;
   __u32 stx_rdev_minor ;
   __u32 stx_dev_major ;
   __u32 stx_dev_minor ;
   __u64 stx_mnt_id ;
   __u64 __spare2 ;
   __u64 __spare3[12] ;
};
struct ignores {
   char **extensions ;
   size_t extensions_len ;
   char **names ;
   size_t names_len ;
   char **slash_names ;
   size_t slash_names_len ;
   char **regexes ;
   size_t regexes_len ;
   char **invert_regexes ;
   size_t invert_regexes_len ;
   char **slash_regexes ;
   size_t slash_regexes_len ;
   char const *dirname ;
   size_t dirname_len ;
   char *abs_path ;
   size_t abs_path_len ;
   struct ignores *parent ;
};
typedef struct ignores ignores;
struct timex {
   unsigned int modes ;
   __syscall_slong_t offset ;
   __syscall_slong_t freq ;
   __syscall_slong_t maxerror ;
   __syscall_slong_t esterror ;
   int status ;
   __syscall_slong_t constant ;
   __syscall_slong_t precision ;
   __syscall_slong_t tolerance ;
   struct timeval time ;
   __syscall_slong_t tick ;
   __syscall_slong_t ppsfreq ;
   __syscall_slong_t jitter ;
   int shift ;
   __syscall_slong_t stabil ;
   __syscall_slong_t jitcnt ;
   __syscall_slong_t calcnt ;
   __syscall_slong_t errcnt ;
   __syscall_slong_t stbcnt ;
   int tai ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
   int : 32 ;
};
enum __anonenum_34415463___0 {
    PTHREAD_CREATE_JOINABLE___0 = 0,
    PTHREAD_CREATE_DETACHED___0 = 1
} ;
enum __anonenum_303612439 {
    PTHREAD_MUTEX_TIMED_NP___0 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___0 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___0 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___0 = 3,
    PTHREAD_MUTEX_NORMAL___0 = 0,
    PTHREAD_MUTEX_RECURSIVE___0 = 1,
    PTHREAD_MUTEX_ERRORCHECK___0 = 2,
    PTHREAD_MUTEX_DEFAULT___0 = 0,
    PTHREAD_MUTEX_FAST_NP = 0
} ;
enum __anonenum_931900394___0 {
    PTHREAD_MUTEX_STALLED___0 = 0,
    PTHREAD_MUTEX_STALLED_NP___0 = 0,
    PTHREAD_MUTEX_ROBUST___0 = 1,
    PTHREAD_MUTEX_ROBUST_NP___0 = 1
} ;
enum __anonenum_205214487___0 {
    PTHREAD_PRIO_NONE___0 = 0,
    PTHREAD_PRIO_INHERIT___0 = 1,
    PTHREAD_PRIO_PROTECT___0 = 2
} ;
enum __anonenum_25043950___0 {
    PTHREAD_RWLOCK_PREFER_READER_NP___0 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___0 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___0 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___0 = 0
} ;
enum __anonenum_436439511___0 {
    PTHREAD_INHERIT_SCHED___0 = 0,
    PTHREAD_EXPLICIT_SCHED___0 = 1
} ;
enum __anonenum_998661166___0 {
    PTHREAD_SCOPE_SYSTEM___0 = 0,
    PTHREAD_SCOPE_PROCESS___0 = 1
} ;
enum __anonenum_146137331___0 {
    PTHREAD_PROCESS_PRIVATE___0 = 0,
    PTHREAD_PROCESS_SHARED___0 = 1
} ;
enum __anonenum_53396917___0 {
    PTHREAD_CANCEL_ENABLE___0 = 0,
    PTHREAD_CANCEL_DISABLE___0 = 1
} ;
enum __anonenum_904563783___0 {
    PTHREAD_CANCEL_DEFERRED___0 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___0 = 1
} ;
enum log_level {
    LOG_LEVEL_DEBUG = 10,
    LOG_LEVEL_MSG = 20,
    LOG_LEVEL_WARN = 30,
    LOG_LEVEL_ERR = 40,
    LOG_LEVEL_NONE = 100
} ;
struct option {
   char const *name ;
   int has_arg ;
   int *flag ;
   int val ;
};
struct real_pcre ;
typedef struct real_pcre pcre;
struct real_pcre16 ;
typedef struct real_pcre16 pcre16;
struct real_pcre32 ;
typedef struct real_pcre32 pcre32;
struct real_pcre_jit_stack ;
typedef struct real_pcre_jit_stack pcre_jit_stack;
struct real_pcre16_jit_stack ;
typedef struct real_pcre16_jit_stack pcre16_jit_stack;
struct real_pcre32_jit_stack ;
typedef struct real_pcre32_jit_stack pcre32_jit_stack;
struct pcre_extra {
   unsigned long flags ;
   void *study_data ;
   unsigned long match_limit ;
   void *callout_data ;
   unsigned char const *tables ;
   unsigned long match_limit_recursion ;
   unsigned char **mark ;
   void *executable_jit ;
};
typedef struct pcre_extra pcre_extra;
struct pcre16_extra {
   unsigned long flags ;
   void *study_data ;
   unsigned long match_limit ;
   void *callout_data ;
   unsigned char const *tables ;
   unsigned long match_limit_recursion ;
   unsigned short **mark ;
   void *executable_jit ;
};
typedef struct pcre16_extra pcre16_extra;
struct pcre32_extra {
   unsigned long flags ;
   void *study_data ;
   unsigned long match_limit ;
   void *callout_data ;
   unsigned char const *tables ;
   unsigned long match_limit_recursion ;
   unsigned int **mark ;
   void *executable_jit ;
};
typedef struct pcre32_extra pcre32_extra;
struct pcre_callout_block {
   int version ;
   int callout_number ;
   int *offset_vector ;
   char const *subject ;
   int subject_length ;
   int start_match ;
   int current_position ;
   int capture_top ;
   int capture_last ;
   void *callout_data ;
   int pattern_position ;
   int next_item_length ;
   unsigned char const *mark ;
};
typedef struct pcre_callout_block pcre_callout_block;
struct pcre16_callout_block {
   int version ;
   int callout_number ;
   int *offset_vector ;
   unsigned short const *subject ;
   int subject_length ;
   int start_match ;
   int current_position ;
   int capture_top ;
   int capture_last ;
   void *callout_data ;
   int pattern_position ;
   int next_item_length ;
   unsigned short const *mark ;
};
typedef struct pcre16_callout_block pcre16_callout_block;
struct pcre32_callout_block {
   int version ;
   int callout_number ;
   int *offset_vector ;
   unsigned int const *subject ;
   int subject_length ;
   int start_match ;
   int current_position ;
   int capture_top ;
   int capture_last ;
   void *callout_data ;
   int pattern_position ;
   int next_item_length ;
   unsigned int const *mark ;
};
typedef struct pcre32_callout_block pcre32_callout_block;
typedef pcre_jit_stack *(*pcre_jit_callback)(void * );
typedef pcre16_jit_stack *(*pcre16_jit_callback)(void * );
typedef pcre32_jit_stack *(*pcre32_jit_callback)(void * );
enum case_behavior {
    CASE_DEFAULT = 0,
    CASE_SENSITIVE = 1,
    CASE_INSENSITIVE = 2,
    CASE_SMART = 3,
    CASE_SENSITIVE_RETRY_INSENSITIVE = 4
} ;
enum path_print_behavior {
    PATH_PRINT_DEFAULT = 0,
    PATH_PRINT_DEFAULT_EACH_LINE = 1,
    PATH_PRINT_TOP = 2,
    PATH_PRINT_EACH_LINE = 3,
    PATH_PRINT_NOTHING = 4
} ;
struct __anonstruct_cli_options_661676448 {
   int ackmate ;
   pcre *ackmate_dir_filter ;
   pcre_extra *ackmate_dir_filter_extra ;
   size_t after ;
   size_t before ;
   enum case_behavior casing ;
   char const *file_search_string ;
   int match_files ;
   pcre *file_search_regex ;
   pcre_extra *file_search_regex_extra ;
   int color ;
   char *color_line_number ;
   char *color_match ;
   char *color_path ;
   int color_win_ansi ;
   int column ;
   int context ;
   int follow_symlinks ;
   int invert_match ;
   int literal ;
   int literal_starts_wordchar ;
   int literal_ends_wordchar ;
   size_t max_matches_per_file ;
   int max_search_depth ;
   int mmap ;
   int multiline ;
   int one_dev ;
   int only_matching ;
   char path_sep ;
   int path_to_ignore ;
   int print_break ;
   int print_count ;
   int print_filename_only ;
   int print_nonmatching_files ;
   int print_path ;
   int print_all_paths ;
   int print_line_numbers ;
   int print_long_lines ;
   int passthrough ;
   pcre *re ;
   pcre_extra *re_extra ;
   int recurse_dirs ;
   int search_all_files ;
   int skip_vcs_ignores ;
   int search_binary_files ;
   int search_zip_files ;
   int search_hidden_files ;
   int search_stream ;
   int stats ;
   size_t stream_line_num ;
   int match_found ;
   ino_t stdout_inode ;
   char *query ;
   int query_len ;
   char *pager ;
   int paths_len ;
   int parallel ;
   int use_thread_affinity ;
   int vimgrep ;
   size_t width ;
   int word_regexp ;
   int workers ;
};
typedef struct __anonstruct_cli_options_661676448 cli_options;
typedef struct option option_t;
struct __anonstruct_scandir_baton_t_387049375 {
   ignores const *ig ;
   char const *base_path ;
   size_t base_path_len ;
   char const *path_start ;
};
typedef struct __anonstruct_scandir_baton_t_387049375 scandir_baton_t;
typedef int (*filter_fp)(char const *path , struct dirent const * , void * );
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;
typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;
typedef signed char int_fast8_t;
typedef long int_fast16_t;
typedef long int_fast32_t;
typedef long int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long uint_fast16_t;
typedef unsigned long uint_fast32_t;
typedef unsigned long uint_fast64_t;
typedef long intptr_t;
typedef unsigned long uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
struct timezone {
   int tz_minuteswest ;
   int tz_dsttime ;
};
enum __itimer_which {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
} ;
struct itimerval {
   struct timeval it_interval ;
   struct timeval it_value ;
};
typedef enum __itimer_which __itimer_which_t;
struct __anonstruct_match_t_73278319 {
   size_t start ;
   size_t end ;
};
typedef struct __anonstruct_match_t_73278319 match_t;
struct __anonstruct_ag_stats_416475514 {
   size_t total_bytes ;
   size_t total_files ;
   size_t total_matches ;
   size_t total_file_matches ;
   struct timeval time_start ;
   struct timeval time_end ;
};
typedef struct __anonstruct_ag_stats_416475514 ag_stats;
union __anonunion_word_t_677777955 {
   char as_chars[sizeof(uint16_t )] ;
   uint16_t as_word ;
};
typedef union __anonunion_word_t_677777955 word_t;
enum __anonenum_34415463___1 {
    PTHREAD_CREATE_JOINABLE___1 = 0,
    PTHREAD_CREATE_DETACHED___1 = 1
} ;
enum __anonenum_303612439___0 {
    PTHREAD_MUTEX_TIMED_NP___1 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___1 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___1 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___1 = 3,
    PTHREAD_MUTEX_NORMAL___1 = 0,
    PTHREAD_MUTEX_RECURSIVE___1 = 1,
    PTHREAD_MUTEX_ERRORCHECK___1 = 2,
    PTHREAD_MUTEX_DEFAULT___1 = 0,
    PTHREAD_MUTEX_FAST_NP___0 = 0
} ;
enum __anonenum_931900394___1 {
    PTHREAD_MUTEX_STALLED___1 = 0,
    PTHREAD_MUTEX_STALLED_NP___1 = 0,
    PTHREAD_MUTEX_ROBUST___1 = 1,
    PTHREAD_MUTEX_ROBUST_NP___1 = 1
} ;
enum __anonenum_205214487___1 {
    PTHREAD_PRIO_NONE___1 = 0,
    PTHREAD_PRIO_INHERIT___1 = 1,
    PTHREAD_PRIO_PROTECT___1 = 2
} ;
enum __anonenum_25043950___1 {
    PTHREAD_RWLOCK_PREFER_READER_NP___1 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___1 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___1 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___1 = 0
} ;
enum __anonenum_436439511___1 {
    PTHREAD_INHERIT_SCHED___1 = 0,
    PTHREAD_EXPLICIT_SCHED___1 = 1
} ;
enum __anonenum_998661166___1 {
    PTHREAD_SCOPE_SYSTEM___1 = 0,
    PTHREAD_SCOPE_PROCESS___1 = 1
} ;
enum __anonenum_146137331___1 {
    PTHREAD_PROCESS_PRIVATE___1 = 0,
    PTHREAD_PROCESS_SHARED___1 = 1
} ;
enum __anonenum_53396917___1 {
    PTHREAD_CANCEL_ENABLE___1 = 0,
    PTHREAD_CANCEL_DISABLE___1 = 1
} ;
enum __anonenum_904563783___1 {
    PTHREAD_CANCEL_DEFERRED___1 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___1 = 1
} ;
enum __anonenum_513775621___0 {
    DT_UNKNOWN___0 = 0,
    DT_FIFO___0 = 1,
    DT_CHR___0 = 2,
    DT_DIR___0 = 4,
    DT_BLK___0 = 6,
    DT_REG___0 = 8,
    DT_LNK___0 = 10,
    DT_SOCK___0 = 12,
    DT_WHT___0 = 14
} ;
typedef int error_t;
typedef __sig_atomic_t sig_atomic_t;
union sigval {
   int sival_int ;
   void *sival_ptr ;
};
typedef union sigval __sigval_t;
struct __anonstruct__kill_244518854 {
   __pid_t si_pid ;
   __uid_t si_uid ;
};
struct __anonstruct__timer_490064738 {
   int si_tid ;
   int si_overrun ;
   __sigval_t si_sigval ;
};
struct __anonstruct__rt_619254530 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   __sigval_t si_sigval ;
};
struct __anonstruct__sigchld_284671705 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   int si_status ;
   __clock_t si_utime ;
   __clock_t si_stime ;
};
struct __anonstruct__addr_bnd_5259977 {
   void *_lower ;
   void *_upper ;
};
union __anonunion__bounds_74915469 {
   struct __anonstruct__addr_bnd_5259977 _addr_bnd ;
   __uint32_t _pkey ;
};
struct __anonstruct__sigfault_714026181 {
   void *si_addr ;
   short si_addr_lsb ;
   union __anonunion__bounds_74915469 _bounds ;
};
struct __anonstruct__sigpoll_386613454 {
   long si_band ;
   int si_fd ;
};
struct __anonstruct__sigsys_634745154 {
   void *_call_addr ;
   int _syscall ;
   unsigned int _arch ;
};
union __anonunion__sifields_395682476 {
   int _pad[128UL / sizeof(int ) - 4UL] ;
   struct __anonstruct__kill_244518854 _kill ;
   struct __anonstruct__timer_490064738 _timer ;
   struct __anonstruct__rt_619254530 _rt ;
   struct __anonstruct__sigchld_284671705 _sigchld ;
   struct __anonstruct__sigfault_714026181 _sigfault ;
   struct __anonstruct__sigpoll_386613454 _sigpoll ;
   struct __anonstruct__sigsys_634745154 _sigsys ;
};
struct __anonstruct_siginfo_t_803075889 {
   int si_signo ;
   int si_errno ;
   int si_code ;
   int __pad0 ;
   union __anonunion__sifields_395682476 _sifields ;
};
typedef struct __anonstruct_siginfo_t_803075889 siginfo_t;
enum __anonenum_556971655 {
    SI_ASYNCNL = -60,
    SI_DETHREAD = -7,
    SI_TKILL = -6,
    SI_SIGIO = -5,
    SI_ASYNCIO = -4,
    SI_MESGQ = -3,
    SI_TIMER = -2,
    SI_QUEUE = -1,
    SI_USER = 0,
    SI_KERNEL = 128
} ;
enum __anonenum_640648963 {
    ILL_ILLOPC = 1,
    ILL_ILLOPN = 2,
    ILL_ILLADR = 3,
    ILL_ILLTRP = 4,
    ILL_PRVOPC = 5,
    ILL_PRVREG = 6,
    ILL_COPROC = 7,
    ILL_BADSTK = 8,
    ILL_BADIADDR = 9
} ;
enum __anonenum_457704180 {
    FPE_INTDIV = 1,
    FPE_INTOVF = 2,
    FPE_FLTDIV = 3,
    FPE_FLTOVF = 4,
    FPE_FLTUND = 5,
    FPE_FLTRES = 6,
    FPE_FLTINV = 7,
    FPE_FLTSUB = 8,
    FPE_FLTUNK = 14,
    FPE_CONDTRAP = 15
} ;
enum __anonenum_180375148 {
    SEGV_MAPERR = 1,
    SEGV_ACCERR = 2,
    SEGV_BNDERR = 3,
    SEGV_PKUERR = 4,
    SEGV_ACCADI = 5,
    SEGV_ADIDERR = 6,
    SEGV_ADIPERR = 7,
    SEGV_MTEAERR = 8,
    SEGV_MTESERR = 9
} ;
enum __anonenum_1036286214 {
    BUS_ADRALN = 1,
    BUS_ADRERR = 2,
    BUS_OBJERR = 3,
    BUS_MCEERR_AR = 4,
    BUS_MCEERR_AO = 5
} ;
enum __anonenum_91015150 {
    TRAP_BRKPT = 1,
    TRAP_TRACE = 2,
    TRAP_BRANCH = 3,
    TRAP_HWBKPT = 4,
    TRAP_UNK = 5
} ;
enum __anonenum_23175539 {
    CLD_EXITED = 1,
    CLD_KILLED = 2,
    CLD_DUMPED = 3,
    CLD_TRAPPED = 4,
    CLD_STOPPED = 5,
    CLD_CONTINUED = 6
} ;
enum __anonenum_111643124 {
    POLL_IN = 1,
    POLL_OUT = 2,
    POLL_MSG = 3,
    POLL_ERR = 4,
    POLL_PRI = 5,
    POLL_HUP = 6
} ;
typedef __sigval_t sigval_t;
struct __anonstruct__sigev_thread_746770901 {
   void (*_function)(__sigval_t ) ;
   pthread_attr_t *_attribute ;
};
union __anonunion__sigev_un_567123932 {
   int _pad[64UL / sizeof(int ) - 4UL] ;
   __pid_t _tid ;
   struct __anonstruct__sigev_thread_746770901 _sigev_thread ;
};
struct sigevent {
   __sigval_t sigev_value ;
   int sigev_signo ;
   int sigev_notify ;
   union __anonunion__sigev_un_567123932 _sigev_un ;
};
typedef struct sigevent sigevent_t;
enum __anonenum_852341087 {
    SIGEV_SIGNAL = 0,
    SIGEV_NONE = 1,
    SIGEV_THREAD = 2,
    SIGEV_THREAD_ID = 4
} ;
typedef void (*__sighandler_t)(int );
typedef void (*sighandler_t)(int );
typedef void (*sig_t)(int );
union __anonunion___sigaction_handler_363639592 {
   void (*sa_handler)(int ) ;
   void (*sa_sigaction)(int , siginfo_t * , void * ) ;
};
struct sigaction {
   union __anonunion___sigaction_handler_363639592 __sigaction_handler ;
   __sigset_t sa_mask ;
   int sa_flags ;
   void (*sa_restorer)(void) ;
};
struct _fpx_sw_bytes {
   __uint32_t magic1 ;
   __uint32_t extended_size ;
   __uint64_t xstate_bv ;
   __uint32_t xstate_size ;
   __uint32_t __glibc_reserved1[7] ;
};
struct _fpreg {
   unsigned short significand[4] ;
   unsigned short exponent ;
};
struct _fpxreg {
   unsigned short significand[4] ;
   unsigned short exponent ;
   unsigned short __glibc_reserved1[3] ;
};
struct _xmmreg {
   __uint32_t element[4] ;
};
struct _fpstate {
   __uint16_t cwd ;
   __uint16_t swd ;
   __uint16_t ftw ;
   __uint16_t fop ;
   __uint64_t rip ;
   __uint64_t rdp ;
   __uint32_t mxcsr ;
   __uint32_t mxcr_mask ;
   struct _fpxreg _st[8] ;
   struct _xmmreg _xmm[16] ;
   __uint32_t __glibc_reserved1[24] ;
};
union __anonunion____missing_field_name_501150464 {
   struct _fpstate *fpstate ;
   __uint64_t __fpstate_word ;
};
struct sigcontext {
   __uint64_t r8 ;
   __uint64_t r9 ;
   __uint64_t r10 ;
   __uint64_t r11 ;
   __uint64_t r12 ;
   __uint64_t r13 ;
   __uint64_t r14 ;
   __uint64_t r15 ;
   __uint64_t rdi ;
   __uint64_t rsi ;
   __uint64_t rbp ;
   __uint64_t rbx ;
   __uint64_t rdx ;
   __uint64_t rax ;
   __uint64_t rcx ;
   __uint64_t rsp ;
   __uint64_t rip ;
   __uint64_t eflags ;
   unsigned short cs ;
   unsigned short gs ;
   unsigned short fs ;
   unsigned short __pad0 ;
   __uint64_t err ;
   __uint64_t trapno ;
   __uint64_t oldmask ;
   __uint64_t cr2 ;
   union __anonunion____missing_field_name_501150464 __annonCompField1 ;
   __uint64_t __reserved1[8] ;
};
struct _xsave_hdr {
   __uint64_t xstate_bv ;
   __uint64_t __glibc_reserved1[2] ;
   __uint64_t __glibc_reserved2[5] ;
};
struct _ymmh_state {
   __uint32_t ymmh_space[64] ;
};
struct _xstate {
   struct _fpstate fpstate ;
   struct _xsave_hdr xstate_hdr ;
   struct _ymmh_state ymmh ;
};
struct __anonstruct_stack_t_648343364 {
   void *ss_sp ;
   int ss_flags ;
   size_t ss_size ;
};
typedef struct __anonstruct_stack_t_648343364 stack_t;
typedef long long greg_t;
typedef greg_t gregset_t[23];
enum __anonenum_451154152 {
    REG_R8 = 0,
    REG_R9 = 1,
    REG_R10 = 2,
    REG_R11 = 3,
    REG_R12 = 4,
    REG_R13 = 5,
    REG_R14 = 6,
    REG_R15 = 7,
    REG_RDI = 8,
    REG_RSI = 9,
    REG_RBP = 10,
    REG_RBX = 11,
    REG_RDX = 12,
    REG_RAX = 13,
    REG_RCX = 14,
    REG_RSP = 15,
    REG_RIP = 16,
    REG_EFL = 17,
    REG_CSGSFS = 18,
    REG_ERR = 19,
    REG_TRAPNO = 20,
    REG_OLDMASK = 21,
    REG_CR2 = 22
} ;
struct _libc_fpxreg {
   unsigned short significand[4] ;
   unsigned short exponent ;
   unsigned short __glibc_reserved1[3] ;
};
struct _libc_xmmreg {
   __uint32_t element[4] ;
};
struct _libc_fpstate {
   __uint16_t cwd ;
   __uint16_t swd ;
   __uint16_t ftw ;
   __uint16_t fop ;
   __uint64_t rip ;
   __uint64_t rdp ;
   __uint32_t mxcsr ;
   __uint32_t mxcr_mask ;
   struct _libc_fpxreg _st[8] ;
   struct _libc_xmmreg _xmm[16] ;
   __uint32_t __glibc_reserved1[24] ;
};
typedef struct _libc_fpstate *fpregset_t;
struct __anonstruct_mcontext_t_5268627 {
   gregset_t gregs ;
   fpregset_t fpregs ;
   unsigned long long __reserved1[8] ;
};
typedef struct __anonstruct_mcontext_t_5268627 mcontext_t;
struct ucontext_t {
   unsigned long uc_flags ;
   struct ucontext_t *uc_link ;
   stack_t uc_stack ;
   mcontext_t uc_mcontext ;
   sigset_t uc_sigmask ;
   struct _libc_fpstate __fpregs_mem ;
   unsigned long long __ssp[4] ;
};
typedef struct ucontext_t ucontext_t;
typedef __socklen_t socklen_t;
enum __anonenum_437032235 {
    _PC_LINK_MAX = 0,
    _PC_MAX_CANON = 1,
    _PC_MAX_INPUT = 2,
    _PC_NAME_MAX = 3,
    _PC_PATH_MAX = 4,
    _PC_PIPE_BUF = 5,
    _PC_CHOWN_RESTRICTED = 6,
    _PC_NO_TRUNC = 7,
    _PC_VDISABLE = 8,
    _PC_SYNC_IO = 9,
    _PC_ASYNC_IO = 10,
    _PC_PRIO_IO = 11,
    _PC_SOCK_MAXBUF = 12,
    _PC_FILESIZEBITS = 13,
    _PC_REC_INCR_XFER_SIZE = 14,
    _PC_REC_MAX_XFER_SIZE = 15,
    _PC_REC_MIN_XFER_SIZE = 16,
    _PC_REC_XFER_ALIGN = 17,
    _PC_ALLOC_SIZE_MIN = 18,
    _PC_SYMLINK_MAX = 19,
    _PC_2_SYMLINKS = 20
} ;
enum __anonenum_315186338 {
    _SC_ARG_MAX = 0,
    _SC_CHILD_MAX = 1,
    _SC_CLK_TCK = 2,
    _SC_NGROUPS_MAX = 3,
    _SC_OPEN_MAX = 4,
    _SC_STREAM_MAX = 5,
    _SC_TZNAME_MAX = 6,
    _SC_JOB_CONTROL = 7,
    _SC_SAVED_IDS = 8,
    _SC_REALTIME_SIGNALS = 9,
    _SC_PRIORITY_SCHEDULING = 10,
    _SC_TIMERS = 11,
    _SC_ASYNCHRONOUS_IO = 12,
    _SC_PRIORITIZED_IO = 13,
    _SC_SYNCHRONIZED_IO = 14,
    _SC_FSYNC = 15,
    _SC_MAPPED_FILES = 16,
    _SC_MEMLOCK = 17,
    _SC_MEMLOCK_RANGE = 18,
    _SC_MEMORY_PROTECTION = 19,
    _SC_MESSAGE_PASSING = 20,
    _SC_SEMAPHORES = 21,
    _SC_SHARED_MEMORY_OBJECTS = 22,
    _SC_AIO_LISTIO_MAX = 23,
    _SC_AIO_MAX = 24,
    _SC_AIO_PRIO_DELTA_MAX = 25,
    _SC_DELAYTIMER_MAX = 26,
    _SC_MQ_OPEN_MAX = 27,
    _SC_MQ_PRIO_MAX = 28,
    _SC_VERSION = 29,
    _SC_PAGESIZE = 30,
    _SC_RTSIG_MAX = 31,
    _SC_SEM_NSEMS_MAX = 32,
    _SC_SEM_VALUE_MAX = 33,
    _SC_SIGQUEUE_MAX = 34,
    _SC_TIMER_MAX = 35,
    _SC_BC_BASE_MAX = 36,
    _SC_BC_DIM_MAX = 37,
    _SC_BC_SCALE_MAX = 38,
    _SC_BC_STRING_MAX = 39,
    _SC_COLL_WEIGHTS_MAX = 40,
    _SC_EQUIV_CLASS_MAX = 41,
    _SC_EXPR_NEST_MAX = 42,
    _SC_LINE_MAX = 43,
    _SC_RE_DUP_MAX = 44,
    _SC_CHARCLASS_NAME_MAX = 45,
    _SC_2_VERSION = 46,
    _SC_2_C_BIND = 47,
    _SC_2_C_DEV = 48,
    _SC_2_FORT_DEV = 49,
    _SC_2_FORT_RUN = 50,
    _SC_2_SW_DEV = 51,
    _SC_2_LOCALEDEF = 52,
    _SC_PII = 53,
    _SC_PII_XTI = 54,
    _SC_PII_SOCKET = 55,
    _SC_PII_INTERNET = 56,
    _SC_PII_OSI = 57,
    _SC_POLL = 58,
    _SC_SELECT = 59,
    _SC_UIO_MAXIOV = 60,
    _SC_IOV_MAX = 60,
    _SC_PII_INTERNET_STREAM = 61,
    _SC_PII_INTERNET_DGRAM = 62,
    _SC_PII_OSI_COTS = 63,
    _SC_PII_OSI_CLTS = 64,
    _SC_PII_OSI_M = 65,
    _SC_T_IOV_MAX = 66,
    _SC_THREADS = 67,
    _SC_THREAD_SAFE_FUNCTIONS = 68,
    _SC_GETGR_R_SIZE_MAX = 69,
    _SC_GETPW_R_SIZE_MAX = 70,
    _SC_LOGIN_NAME_MAX = 71,
    _SC_TTY_NAME_MAX = 72,
    _SC_THREAD_DESTRUCTOR_ITERATIONS = 73,
    _SC_THREAD_KEYS_MAX = 74,
    _SC_THREAD_STACK_MIN = 75,
    _SC_THREAD_THREADS_MAX = 76,
    _SC_THREAD_ATTR_STACKADDR = 77,
    _SC_THREAD_ATTR_STACKSIZE = 78,
    _SC_THREAD_PRIORITY_SCHEDULING = 79,
    _SC_THREAD_PRIO_INHERIT = 80,
    _SC_THREAD_PRIO_PROTECT = 81,
    _SC_THREAD_PROCESS_SHARED = 82,
    _SC_NPROCESSORS_CONF = 83,
    _SC_NPROCESSORS_ONLN = 84,
    _SC_PHYS_PAGES = 85,
    _SC_AVPHYS_PAGES = 86,
    _SC_ATEXIT_MAX = 87,
    _SC_PASS_MAX = 88,
    _SC_XOPEN_VERSION = 89,
    _SC_XOPEN_XCU_VERSION = 90,
    _SC_XOPEN_UNIX = 91,
    _SC_XOPEN_CRYPT = 92,
    _SC_XOPEN_ENH_I18N = 93,
    _SC_XOPEN_SHM = 94,
    _SC_2_CHAR_TERM = 95,
    _SC_2_C_VERSION = 96,
    _SC_2_UPE = 97,
    _SC_XOPEN_XPG2 = 98,
    _SC_XOPEN_XPG3 = 99,
    _SC_XOPEN_XPG4 = 100,
    _SC_CHAR_BIT = 101,
    _SC_CHAR_MAX = 102,
    _SC_CHAR_MIN = 103,
    _SC_INT_MAX = 104,
    _SC_INT_MIN = 105,
    _SC_LONG_BIT = 106,
    _SC_WORD_BIT = 107,
    _SC_MB_LEN_MAX = 108,
    _SC_NZERO = 109,
    _SC_SSIZE_MAX = 110,
    _SC_SCHAR_MAX = 111,
    _SC_SCHAR_MIN = 112,
    _SC_SHRT_MAX = 113,
    _SC_SHRT_MIN = 114,
    _SC_UCHAR_MAX = 115,
    _SC_UINT_MAX = 116,
    _SC_ULONG_MAX = 117,
    _SC_USHRT_MAX = 118,
    _SC_NL_ARGMAX = 119,
    _SC_NL_LANGMAX = 120,
    _SC_NL_MSGMAX = 121,
    _SC_NL_NMAX = 122,
    _SC_NL_SETMAX = 123,
    _SC_NL_TEXTMAX = 124,
    _SC_XBS5_ILP32_OFF32 = 125,
    _SC_XBS5_ILP32_OFFBIG = 126,
    _SC_XBS5_LP64_OFF64 = 127,
    _SC_XBS5_LPBIG_OFFBIG = 128,
    _SC_XOPEN_LEGACY = 129,
    _SC_XOPEN_REALTIME = 130,
    _SC_XOPEN_REALTIME_THREADS = 131,
    _SC_ADVISORY_INFO = 132,
    _SC_BARRIERS = 133,
    _SC_BASE = 134,
    _SC_C_LANG_SUPPORT = 135,
    _SC_C_LANG_SUPPORT_R = 136,
    _SC_CLOCK_SELECTION = 137,
    _SC_CPUTIME = 138,
    _SC_THREAD_CPUTIME = 139,
    _SC_DEVICE_IO = 140,
    _SC_DEVICE_SPECIFIC = 141,
    _SC_DEVICE_SPECIFIC_R = 142,
    _SC_FD_MGMT = 143,
    _SC_FIFO = 144,
    _SC_PIPE = 145,
    _SC_FILE_ATTRIBUTES = 146,
    _SC_FILE_LOCKING = 147,
    _SC_FILE_SYSTEM = 148,
    _SC_MONOTONIC_CLOCK = 149,
    _SC_MULTI_PROCESS = 150,
    _SC_SINGLE_PROCESS = 151,
    _SC_NETWORKING = 152,
    _SC_READER_WRITER_LOCKS = 153,
    _SC_SPIN_LOCKS = 154,
    _SC_REGEXP = 155,
    _SC_REGEX_VERSION = 156,
    _SC_SHELL = 157,
    _SC_SIGNALS = 158,
    _SC_SPAWN = 159,
    _SC_SPORADIC_SERVER = 160,
    _SC_THREAD_SPORADIC_SERVER = 161,
    _SC_SYSTEM_DATABASE = 162,
    _SC_SYSTEM_DATABASE_R = 163,
    _SC_TIMEOUTS = 164,
    _SC_TYPED_MEMORY_OBJECTS = 165,
    _SC_USER_GROUPS = 166,
    _SC_USER_GROUPS_R = 167,
    _SC_2_PBS = 168,
    _SC_2_PBS_ACCOUNTING = 169,
    _SC_2_PBS_LOCATE = 170,
    _SC_2_PBS_MESSAGE = 171,
    _SC_2_PBS_TRACK = 172,
    _SC_SYMLOOP_MAX = 173,
    _SC_STREAMS = 174,
    _SC_2_PBS_CHECKPOINT = 175,
    _SC_V6_ILP32_OFF32 = 176,
    _SC_V6_ILP32_OFFBIG = 177,
    _SC_V6_LP64_OFF64 = 178,
    _SC_V6_LPBIG_OFFBIG = 179,
    _SC_HOST_NAME_MAX = 180,
    _SC_TRACE = 181,
    _SC_TRACE_EVENT_FILTER = 182,
    _SC_TRACE_INHERIT = 183,
    _SC_TRACE_LOG = 184,
    _SC_LEVEL1_ICACHE_SIZE = 185,
    _SC_LEVEL1_ICACHE_ASSOC = 186,
    _SC_LEVEL1_ICACHE_LINESIZE = 187,
    _SC_LEVEL1_DCACHE_SIZE = 188,
    _SC_LEVEL1_DCACHE_ASSOC = 189,
    _SC_LEVEL1_DCACHE_LINESIZE = 190,
    _SC_LEVEL2_CACHE_SIZE = 191,
    _SC_LEVEL2_CACHE_ASSOC = 192,
    _SC_LEVEL2_CACHE_LINESIZE = 193,
    _SC_LEVEL3_CACHE_SIZE = 194,
    _SC_LEVEL3_CACHE_ASSOC = 195,
    _SC_LEVEL3_CACHE_LINESIZE = 196,
    _SC_LEVEL4_CACHE_SIZE = 197,
    _SC_LEVEL4_CACHE_ASSOC = 198,
    _SC_LEVEL4_CACHE_LINESIZE = 199,
    _SC_IPV6 = 235,
    _SC_RAW_SOCKETS = 236,
    _SC_V7_ILP32_OFF32 = 237,
    _SC_V7_ILP32_OFFBIG = 238,
    _SC_V7_LP64_OFF64 = 239,
    _SC_V7_LPBIG_OFFBIG = 240,
    _SC_SS_REPL_MAX = 241,
    _SC_TRACE_EVENT_NAME_MAX = 242,
    _SC_TRACE_NAME_MAX = 243,
    _SC_TRACE_SYS_MAX = 244,
    _SC_TRACE_USER_EVENT_MAX = 245,
    _SC_XOPEN_STREAMS = 246,
    _SC_THREAD_ROBUST_PRIO_INHERIT = 247,
    _SC_THREAD_ROBUST_PRIO_PROTECT = 248,
    _SC_MINSIGSTKSZ = 249,
    _SC_SIGSTKSZ = 250
} ;
enum __anonenum_875524036 {
    _CS_PATH = 0,
    _CS_V6_WIDTH_RESTRICTED_ENVS = 1,
    _CS_GNU_LIBC_VERSION = 2,
    _CS_GNU_LIBPTHREAD_VERSION = 3,
    _CS_V5_WIDTH_RESTRICTED_ENVS = 4,
    _CS_V7_WIDTH_RESTRICTED_ENVS = 5,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS = 1001,
    _CS_LFS_LIBS = 1002,
    _CS_LFS_LINTFLAGS = 1003,
    _CS_LFS64_CFLAGS = 1004,
    _CS_LFS64_LDFLAGS = 1005,
    _CS_LFS64_LIBS = 1006,
    _CS_LFS64_LINTFLAGS = 1007,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS = 1101,
    _CS_XBS5_ILP32_OFF32_LIBS = 1102,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS = 1103,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS = 1104,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS = 1105,
    _CS_XBS5_ILP32_OFFBIG_LIBS = 1106,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS = 1107,
    _CS_XBS5_LP64_OFF64_CFLAGS = 1108,
    _CS_XBS5_LP64_OFF64_LDFLAGS = 1109,
    _CS_XBS5_LP64_OFF64_LIBS = 1110,
    _CS_XBS5_LP64_OFF64_LINTFLAGS = 1111,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS = 1112,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS = 1113,
    _CS_XBS5_LPBIG_OFFBIG_LIBS = 1114,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS = 1115,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS = 1116,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS = 1117,
    _CS_POSIX_V6_ILP32_OFF32_LIBS = 1118,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS = 1119,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS = 1120,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS = 1121,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS = 1122,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS = 1123,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS = 1124,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS = 1125,
    _CS_POSIX_V6_LP64_OFF64_LIBS = 1126,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS = 1127,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS = 1128,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS = 1129,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS = 1130,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS = 1131,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS = 1132,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS = 1133,
    _CS_POSIX_V7_ILP32_OFF32_LIBS = 1134,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS = 1135,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS = 1136,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS = 1137,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS = 1138,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS = 1139,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS = 1140,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS = 1141,
    _CS_POSIX_V7_LP64_OFF64_LIBS = 1142,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS = 1143,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS = 1144,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS = 1145,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS = 1146,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS = 1147,
    _CS_V6_ENV = 1148,
    _CS_V7_ENV = 1149
} ;
enum __anonenum_57186863 {
    SS_ONSTACK = 1,
    SS_DISABLE = 2
} ;
struct sigstack {
   void *ss_sp ;
   int ss_onstack ;
};
enum __anonenum_513775621___1 {
    DT_UNKNOWN___1 = 0,
    DT_FIFO___1 = 1,
    DT_CHR___1 = 2,
    DT_DIR___1 = 4,
    DT_BLK___1 = 6,
    DT_REG___1 = 8,
    DT_LNK___1 = 10,
    DT_SOCK___1 = 12,
    DT_WHT___1 = 14
} ;
struct __anonstruct_lang_spec_t_527861670 {
   char const *name ;
   char const *extensions[12] ;
};
typedef struct __anonstruct_lang_spec_t_527861670 lang_spec_t;
enum __anonenum_34415463___2 {
    PTHREAD_CREATE_JOINABLE___2 = 0,
    PTHREAD_CREATE_DETACHED___2 = 1
} ;
enum __anonenum_303612439___1 {
    PTHREAD_MUTEX_TIMED_NP___2 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___2 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___2 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___2 = 3,
    PTHREAD_MUTEX_NORMAL___2 = 0,
    PTHREAD_MUTEX_RECURSIVE___2 = 1,
    PTHREAD_MUTEX_ERRORCHECK___2 = 2,
    PTHREAD_MUTEX_DEFAULT___2 = 0,
    PTHREAD_MUTEX_FAST_NP___1 = 0
} ;
enum __anonenum_931900394___2 {
    PTHREAD_MUTEX_STALLED___2 = 0,
    PTHREAD_MUTEX_STALLED_NP___2 = 0,
    PTHREAD_MUTEX_ROBUST___2 = 1,
    PTHREAD_MUTEX_ROBUST_NP___2 = 1
} ;
enum __anonenum_205214487___2 {
    PTHREAD_PRIO_NONE___2 = 0,
    PTHREAD_PRIO_INHERIT___2 = 1,
    PTHREAD_PRIO_PROTECT___2 = 2
} ;
enum __anonenum_25043950___2 {
    PTHREAD_RWLOCK_PREFER_READER_NP___2 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___2 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___2 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___2 = 0
} ;
enum __anonenum_436439511___2 {
    PTHREAD_INHERIT_SCHED___2 = 0,
    PTHREAD_EXPLICIT_SCHED___2 = 1
} ;
enum __anonenum_998661166___2 {
    PTHREAD_SCOPE_SYSTEM___2 = 0,
    PTHREAD_SCOPE_PROCESS___2 = 1
} ;
enum __anonenum_146137331___2 {
    PTHREAD_PROCESS_PRIVATE___2 = 0,
    PTHREAD_PROCESS_SHARED___2 = 1
} ;
enum __anonenum_53396917___2 {
    PTHREAD_CANCEL_ENABLE___2 = 0,
    PTHREAD_CANCEL_DISABLE___2 = 1
} ;
enum __anonenum_904563783___2 {
    PTHREAD_CANCEL_DEFERRED___2 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___2 = 1
} ;
enum __anonenum_513775621___2 {
    DT_UNKNOWN___2 = 0,
    DT_FIFO___2 = 1,
    DT_CHR___2 = 2,
    DT_DIR___2 = 4,
    DT_BLK___2 = 6,
    DT_REG___2 = 8,
    DT_LNK___2 = 10,
    DT_SOCK___2 = 12,
    DT_WHT___2 = 14
} ;
enum __anonenum_34415463___3 {
    PTHREAD_CREATE_JOINABLE___3 = 0,
    PTHREAD_CREATE_DETACHED___3 = 1
} ;
enum __anonenum_303612439___2 {
    PTHREAD_MUTEX_TIMED_NP___3 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___3 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___3 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___3 = 3,
    PTHREAD_MUTEX_NORMAL___3 = 0,
    PTHREAD_MUTEX_RECURSIVE___3 = 1,
    PTHREAD_MUTEX_ERRORCHECK___3 = 2,
    PTHREAD_MUTEX_DEFAULT___3 = 0,
    PTHREAD_MUTEX_FAST_NP___2 = 0
} ;
enum __anonenum_931900394___3 {
    PTHREAD_MUTEX_STALLED___3 = 0,
    PTHREAD_MUTEX_STALLED_NP___3 = 0,
    PTHREAD_MUTEX_ROBUST___3 = 1,
    PTHREAD_MUTEX_ROBUST_NP___3 = 1
} ;
enum __anonenum_205214487___3 {
    PTHREAD_PRIO_NONE___3 = 0,
    PTHREAD_PRIO_INHERIT___3 = 1,
    PTHREAD_PRIO_PROTECT___3 = 2
} ;
enum __anonenum_25043950___3 {
    PTHREAD_RWLOCK_PREFER_READER_NP___3 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___3 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___3 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___3 = 0
} ;
enum __anonenum_436439511___3 {
    PTHREAD_INHERIT_SCHED___3 = 0,
    PTHREAD_EXPLICIT_SCHED___3 = 1
} ;
enum __anonenum_998661166___3 {
    PTHREAD_SCOPE_SYSTEM___3 = 0,
    PTHREAD_SCOPE_PROCESS___3 = 1
} ;
enum __anonenum_146137331___3 {
    PTHREAD_PROCESS_PRIVATE___3 = 0,
    PTHREAD_PROCESS_SHARED___3 = 1
} ;
enum __anonenum_53396917___3 {
    PTHREAD_CANCEL_ENABLE___3 = 0,
    PTHREAD_CANCEL_DISABLE___3 = 1
} ;
enum __anonenum_904563783___3 {
    PTHREAD_CANCEL_DEFERRED___3 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___3 = 1
} ;
struct flock {
   short l_type ;
   short l_whence ;
   __off_t l_start ;
   __off_t l_len ;
   __pid_t l_pid ;
};
struct flock64 {
   short l_type ;
   short l_whence ;
   __off64_t l_start ;
   __off64_t l_len ;
   __pid_t l_pid ;
};
struct iovec {
   void *iov_base ;
   size_t iov_len ;
};
enum __pid_type {
    F_OWNER_TID = 0,
    F_OWNER_PID = 1,
    F_OWNER_PGRP = 2,
    F_OWNER_GID = 2
} ;
struct f_owner_ex {
   enum __pid_type type ;
   __pid_t pid ;
};
struct file_handle {
   unsigned int handle_bytes ;
   int handle_type ;
   unsigned char f_handle[0] ;
};
enum __anonenum_437032235___0 {
    _PC_LINK_MAX___0 = 0,
    _PC_MAX_CANON___0 = 1,
    _PC_MAX_INPUT___0 = 2,
    _PC_NAME_MAX___0 = 3,
    _PC_PATH_MAX___0 = 4,
    _PC_PIPE_BUF___0 = 5,
    _PC_CHOWN_RESTRICTED___0 = 6,
    _PC_NO_TRUNC___0 = 7,
    _PC_VDISABLE___0 = 8,
    _PC_SYNC_IO___0 = 9,
    _PC_ASYNC_IO___0 = 10,
    _PC_PRIO_IO___0 = 11,
    _PC_SOCK_MAXBUF___0 = 12,
    _PC_FILESIZEBITS___0 = 13,
    _PC_REC_INCR_XFER_SIZE___0 = 14,
    _PC_REC_MAX_XFER_SIZE___0 = 15,
    _PC_REC_MIN_XFER_SIZE___0 = 16,
    _PC_REC_XFER_ALIGN___0 = 17,
    _PC_ALLOC_SIZE_MIN___0 = 18,
    _PC_SYMLINK_MAX___0 = 19,
    _PC_2_SYMLINKS___0 = 20
} ;
enum __anonenum_315186338___0 {
    _SC_ARG_MAX___0 = 0,
    _SC_CHILD_MAX___0 = 1,
    _SC_CLK_TCK___0 = 2,
    _SC_NGROUPS_MAX___0 = 3,
    _SC_OPEN_MAX___0 = 4,
    _SC_STREAM_MAX___0 = 5,
    _SC_TZNAME_MAX___0 = 6,
    _SC_JOB_CONTROL___0 = 7,
    _SC_SAVED_IDS___0 = 8,
    _SC_REALTIME_SIGNALS___0 = 9,
    _SC_PRIORITY_SCHEDULING___0 = 10,
    _SC_TIMERS___0 = 11,
    _SC_ASYNCHRONOUS_IO___0 = 12,
    _SC_PRIORITIZED_IO___0 = 13,
    _SC_SYNCHRONIZED_IO___0 = 14,
    _SC_FSYNC___0 = 15,
    _SC_MAPPED_FILES___0 = 16,
    _SC_MEMLOCK___0 = 17,
    _SC_MEMLOCK_RANGE___0 = 18,
    _SC_MEMORY_PROTECTION___0 = 19,
    _SC_MESSAGE_PASSING___0 = 20,
    _SC_SEMAPHORES___0 = 21,
    _SC_SHARED_MEMORY_OBJECTS___0 = 22,
    _SC_AIO_LISTIO_MAX___0 = 23,
    _SC_AIO_MAX___0 = 24,
    _SC_AIO_PRIO_DELTA_MAX___0 = 25,
    _SC_DELAYTIMER_MAX___0 = 26,
    _SC_MQ_OPEN_MAX___0 = 27,
    _SC_MQ_PRIO_MAX___0 = 28,
    _SC_VERSION___0 = 29,
    _SC_PAGESIZE___0 = 30,
    _SC_RTSIG_MAX___0 = 31,
    _SC_SEM_NSEMS_MAX___0 = 32,
    _SC_SEM_VALUE_MAX___0 = 33,
    _SC_SIGQUEUE_MAX___0 = 34,
    _SC_TIMER_MAX___0 = 35,
    _SC_BC_BASE_MAX___0 = 36,
    _SC_BC_DIM_MAX___0 = 37,
    _SC_BC_SCALE_MAX___0 = 38,
    _SC_BC_STRING_MAX___0 = 39,
    _SC_COLL_WEIGHTS_MAX___0 = 40,
    _SC_EQUIV_CLASS_MAX___0 = 41,
    _SC_EXPR_NEST_MAX___0 = 42,
    _SC_LINE_MAX___0 = 43,
    _SC_RE_DUP_MAX___0 = 44,
    _SC_CHARCLASS_NAME_MAX___0 = 45,
    _SC_2_VERSION___0 = 46,
    _SC_2_C_BIND___0 = 47,
    _SC_2_C_DEV___0 = 48,
    _SC_2_FORT_DEV___0 = 49,
    _SC_2_FORT_RUN___0 = 50,
    _SC_2_SW_DEV___0 = 51,
    _SC_2_LOCALEDEF___0 = 52,
    _SC_PII___0 = 53,
    _SC_PII_XTI___0 = 54,
    _SC_PII_SOCKET___0 = 55,
    _SC_PII_INTERNET___0 = 56,
    _SC_PII_OSI___0 = 57,
    _SC_POLL___0 = 58,
    _SC_SELECT___0 = 59,
    _SC_UIO_MAXIOV___0 = 60,
    _SC_IOV_MAX___0 = 60,
    _SC_PII_INTERNET_STREAM___0 = 61,
    _SC_PII_INTERNET_DGRAM___0 = 62,
    _SC_PII_OSI_COTS___0 = 63,
    _SC_PII_OSI_CLTS___0 = 64,
    _SC_PII_OSI_M___0 = 65,
    _SC_T_IOV_MAX___0 = 66,
    _SC_THREADS___0 = 67,
    _SC_THREAD_SAFE_FUNCTIONS___0 = 68,
    _SC_GETGR_R_SIZE_MAX___0 = 69,
    _SC_GETPW_R_SIZE_MAX___0 = 70,
    _SC_LOGIN_NAME_MAX___0 = 71,
    _SC_TTY_NAME_MAX___0 = 72,
    _SC_THREAD_DESTRUCTOR_ITERATIONS___0 = 73,
    _SC_THREAD_KEYS_MAX___0 = 74,
    _SC_THREAD_STACK_MIN___0 = 75,
    _SC_THREAD_THREADS_MAX___0 = 76,
    _SC_THREAD_ATTR_STACKADDR___0 = 77,
    _SC_THREAD_ATTR_STACKSIZE___0 = 78,
    _SC_THREAD_PRIORITY_SCHEDULING___0 = 79,
    _SC_THREAD_PRIO_INHERIT___0 = 80,
    _SC_THREAD_PRIO_PROTECT___0 = 81,
    _SC_THREAD_PROCESS_SHARED___0 = 82,
    _SC_NPROCESSORS_CONF___0 = 83,
    _SC_NPROCESSORS_ONLN___0 = 84,
    _SC_PHYS_PAGES___0 = 85,
    _SC_AVPHYS_PAGES___0 = 86,
    _SC_ATEXIT_MAX___0 = 87,
    _SC_PASS_MAX___0 = 88,
    _SC_XOPEN_VERSION___0 = 89,
    _SC_XOPEN_XCU_VERSION___0 = 90,
    _SC_XOPEN_UNIX___0 = 91,
    _SC_XOPEN_CRYPT___0 = 92,
    _SC_XOPEN_ENH_I18N___0 = 93,
    _SC_XOPEN_SHM___0 = 94,
    _SC_2_CHAR_TERM___0 = 95,
    _SC_2_C_VERSION___0 = 96,
    _SC_2_UPE___0 = 97,
    _SC_XOPEN_XPG2___0 = 98,
    _SC_XOPEN_XPG3___0 = 99,
    _SC_XOPEN_XPG4___0 = 100,
    _SC_CHAR_BIT___0 = 101,
    _SC_CHAR_MAX___0 = 102,
    _SC_CHAR_MIN___0 = 103,
    _SC_INT_MAX___0 = 104,
    _SC_INT_MIN___0 = 105,
    _SC_LONG_BIT___0 = 106,
    _SC_WORD_BIT___0 = 107,
    _SC_MB_LEN_MAX___0 = 108,
    _SC_NZERO___0 = 109,
    _SC_SSIZE_MAX___0 = 110,
    _SC_SCHAR_MAX___0 = 111,
    _SC_SCHAR_MIN___0 = 112,
    _SC_SHRT_MAX___0 = 113,
    _SC_SHRT_MIN___0 = 114,
    _SC_UCHAR_MAX___0 = 115,
    _SC_UINT_MAX___0 = 116,
    _SC_ULONG_MAX___0 = 117,
    _SC_USHRT_MAX___0 = 118,
    _SC_NL_ARGMAX___0 = 119,
    _SC_NL_LANGMAX___0 = 120,
    _SC_NL_MSGMAX___0 = 121,
    _SC_NL_NMAX___0 = 122,
    _SC_NL_SETMAX___0 = 123,
    _SC_NL_TEXTMAX___0 = 124,
    _SC_XBS5_ILP32_OFF32___0 = 125,
    _SC_XBS5_ILP32_OFFBIG___0 = 126,
    _SC_XBS5_LP64_OFF64___0 = 127,
    _SC_XBS5_LPBIG_OFFBIG___0 = 128,
    _SC_XOPEN_LEGACY___0 = 129,
    _SC_XOPEN_REALTIME___0 = 130,
    _SC_XOPEN_REALTIME_THREADS___0 = 131,
    _SC_ADVISORY_INFO___0 = 132,
    _SC_BARRIERS___0 = 133,
    _SC_BASE___0 = 134,
    _SC_C_LANG_SUPPORT___0 = 135,
    _SC_C_LANG_SUPPORT_R___0 = 136,
    _SC_CLOCK_SELECTION___0 = 137,
    _SC_CPUTIME___0 = 138,
    _SC_THREAD_CPUTIME___0 = 139,
    _SC_DEVICE_IO___0 = 140,
    _SC_DEVICE_SPECIFIC___0 = 141,
    _SC_DEVICE_SPECIFIC_R___0 = 142,
    _SC_FD_MGMT___0 = 143,
    _SC_FIFO___0 = 144,
    _SC_PIPE___0 = 145,
    _SC_FILE_ATTRIBUTES___0 = 146,
    _SC_FILE_LOCKING___0 = 147,
    _SC_FILE_SYSTEM___0 = 148,
    _SC_MONOTONIC_CLOCK___0 = 149,
    _SC_MULTI_PROCESS___0 = 150,
    _SC_SINGLE_PROCESS___0 = 151,
    _SC_NETWORKING___0 = 152,
    _SC_READER_WRITER_LOCKS___0 = 153,
    _SC_SPIN_LOCKS___0 = 154,
    _SC_REGEXP___0 = 155,
    _SC_REGEX_VERSION___0 = 156,
    _SC_SHELL___0 = 157,
    _SC_SIGNALS___0 = 158,
    _SC_SPAWN___0 = 159,
    _SC_SPORADIC_SERVER___0 = 160,
    _SC_THREAD_SPORADIC_SERVER___0 = 161,
    _SC_SYSTEM_DATABASE___0 = 162,
    _SC_SYSTEM_DATABASE_R___0 = 163,
    _SC_TIMEOUTS___0 = 164,
    _SC_TYPED_MEMORY_OBJECTS___0 = 165,
    _SC_USER_GROUPS___0 = 166,
    _SC_USER_GROUPS_R___0 = 167,
    _SC_2_PBS___0 = 168,
    _SC_2_PBS_ACCOUNTING___0 = 169,
    _SC_2_PBS_LOCATE___0 = 170,
    _SC_2_PBS_MESSAGE___0 = 171,
    _SC_2_PBS_TRACK___0 = 172,
    _SC_SYMLOOP_MAX___0 = 173,
    _SC_STREAMS___0 = 174,
    _SC_2_PBS_CHECKPOINT___0 = 175,
    _SC_V6_ILP32_OFF32___0 = 176,
    _SC_V6_ILP32_OFFBIG___0 = 177,
    _SC_V6_LP64_OFF64___0 = 178,
    _SC_V6_LPBIG_OFFBIG___0 = 179,
    _SC_HOST_NAME_MAX___0 = 180,
    _SC_TRACE___0 = 181,
    _SC_TRACE_EVENT_FILTER___0 = 182,
    _SC_TRACE_INHERIT___0 = 183,
    _SC_TRACE_LOG___0 = 184,
    _SC_LEVEL1_ICACHE_SIZE___0 = 185,
    _SC_LEVEL1_ICACHE_ASSOC___0 = 186,
    _SC_LEVEL1_ICACHE_LINESIZE___0 = 187,
    _SC_LEVEL1_DCACHE_SIZE___0 = 188,
    _SC_LEVEL1_DCACHE_ASSOC___0 = 189,
    _SC_LEVEL1_DCACHE_LINESIZE___0 = 190,
    _SC_LEVEL2_CACHE_SIZE___0 = 191,
    _SC_LEVEL2_CACHE_ASSOC___0 = 192,
    _SC_LEVEL2_CACHE_LINESIZE___0 = 193,
    _SC_LEVEL3_CACHE_SIZE___0 = 194,
    _SC_LEVEL3_CACHE_ASSOC___0 = 195,
    _SC_LEVEL3_CACHE_LINESIZE___0 = 196,
    _SC_LEVEL4_CACHE_SIZE___0 = 197,
    _SC_LEVEL4_CACHE_ASSOC___0 = 198,
    _SC_LEVEL4_CACHE_LINESIZE___0 = 199,
    _SC_IPV6___0 = 235,
    _SC_RAW_SOCKETS___0 = 236,
    _SC_V7_ILP32_OFF32___0 = 237,
    _SC_V7_ILP32_OFFBIG___0 = 238,
    _SC_V7_LP64_OFF64___0 = 239,
    _SC_V7_LPBIG_OFFBIG___0 = 240,
    _SC_SS_REPL_MAX___0 = 241,
    _SC_TRACE_EVENT_NAME_MAX___0 = 242,
    _SC_TRACE_NAME_MAX___0 = 243,
    _SC_TRACE_SYS_MAX___0 = 244,
    _SC_TRACE_USER_EVENT_MAX___0 = 245,
    _SC_XOPEN_STREAMS___0 = 246,
    _SC_THREAD_ROBUST_PRIO_INHERIT___0 = 247,
    _SC_THREAD_ROBUST_PRIO_PROTECT___0 = 248,
    _SC_MINSIGSTKSZ___0 = 249,
    _SC_SIGSTKSZ___0 = 250
} ;
enum __anonenum_875524036___0 {
    _CS_PATH___0 = 0,
    _CS_V6_WIDTH_RESTRICTED_ENVS___0 = 1,
    _CS_GNU_LIBC_VERSION___0 = 2,
    _CS_GNU_LIBPTHREAD_VERSION___0 = 3,
    _CS_V5_WIDTH_RESTRICTED_ENVS___0 = 4,
    _CS_V7_WIDTH_RESTRICTED_ENVS___0 = 5,
    _CS_LFS_CFLAGS___0 = 1000,
    _CS_LFS_LDFLAGS___0 = 1001,
    _CS_LFS_LIBS___0 = 1002,
    _CS_LFS_LINTFLAGS___0 = 1003,
    _CS_LFS64_CFLAGS___0 = 1004,
    _CS_LFS64_LDFLAGS___0 = 1005,
    _CS_LFS64_LIBS___0 = 1006,
    _CS_LFS64_LINTFLAGS___0 = 1007,
    _CS_XBS5_ILP32_OFF32_CFLAGS___0 = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS___0 = 1101,
    _CS_XBS5_ILP32_OFF32_LIBS___0 = 1102,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS___0 = 1103,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS___0 = 1104,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS___0 = 1105,
    _CS_XBS5_ILP32_OFFBIG_LIBS___0 = 1106,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS___0 = 1107,
    _CS_XBS5_LP64_OFF64_CFLAGS___0 = 1108,
    _CS_XBS5_LP64_OFF64_LDFLAGS___0 = 1109,
    _CS_XBS5_LP64_OFF64_LIBS___0 = 1110,
    _CS_XBS5_LP64_OFF64_LINTFLAGS___0 = 1111,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS___0 = 1112,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS___0 = 1113,
    _CS_XBS5_LPBIG_OFFBIG_LIBS___0 = 1114,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS___0 = 1115,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS___0 = 1116,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS___0 = 1117,
    _CS_POSIX_V6_ILP32_OFF32_LIBS___0 = 1118,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS___0 = 1119,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS___0 = 1120,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS___0 = 1121,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS___0 = 1122,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS___0 = 1123,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS___0 = 1124,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS___0 = 1125,
    _CS_POSIX_V6_LP64_OFF64_LIBS___0 = 1126,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS___0 = 1127,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS___0 = 1128,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS___0 = 1129,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS___0 = 1130,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS___0 = 1131,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS___0 = 1132,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS___0 = 1133,
    _CS_POSIX_V7_ILP32_OFF32_LIBS___0 = 1134,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS___0 = 1135,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS___0 = 1136,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS___0 = 1137,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS___0 = 1138,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS___0 = 1139,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS___0 = 1140,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS___0 = 1141,
    _CS_POSIX_V7_LP64_OFF64_LIBS___0 = 1142,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS___0 = 1143,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS___0 = 1144,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS___0 = 1145,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS___0 = 1146,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS___0 = 1147,
    _CS_V6_ENV___0 = 1148,
    _CS_V7_ENV___0 = 1149
} ;
enum __anonenum_ag_compression_type_847750060 {
    AG_NO_COMPRESSION = 0,
    AG_GZIP = 1,
    AG_COMPRESS = 2,
    AG_ZIP = 3,
    AG_XZ = 4
} ;
typedef enum __anonenum_ag_compression_type_847750060 ag_compression_type;
struct UT_hash_handle ;
struct UT_hash_bucket {
   struct UT_hash_handle *hh_head ;
   unsigned int count ;
   unsigned int expand_mult ;
};
typedef struct UT_hash_bucket UT_hash_bucket;
struct UT_hash_table {
   UT_hash_bucket *buckets ;
   unsigned int num_buckets ;
   unsigned int log2_num_buckets ;
   unsigned int num_items ;
   struct UT_hash_handle *tail ;
   ptrdiff_t hho ;
   unsigned int ideal_chain_maxlen ;
   unsigned int nonideal_items ;
   unsigned int ineff_expands ;
   unsigned int noexpand ;
   uint32_t signature ;
};
typedef struct UT_hash_table UT_hash_table;
struct UT_hash_handle {
   struct UT_hash_table *tbl ;
   void *prev ;
   void *next ;
   struct UT_hash_handle *hh_prev ;
   struct UT_hash_handle *hh_next ;
   void *key ;
   unsigned int keylen ;
   unsigned int hashv ;
};
typedef struct UT_hash_handle UT_hash_handle;
struct work_queue_t {
   char *path ;
   struct work_queue_t *next ;
};
typedef struct work_queue_t work_queue_t;
struct __anonstruct_dirkey_t_583383409 {
   dev_t dev ;
   ino_t ino ;
};
typedef struct __anonstruct_dirkey_t_583383409 dirkey_t;
struct __anonstruct_symdir_t_545766974 {
   dirkey_t key ;
   UT_hash_handle hh ;
};
typedef struct __anonstruct_symdir_t_545766974 symdir_t;
struct print_context {
   size_t line ;
   char **context_prev_lines ;
   size_t prev_line ;
   size_t last_prev_line ;
   size_t prev_line_offset ;
   size_t line_preceding_current_match_offset ;
   size_t lines_since_last_match ;
   size_t last_printed_match ;
   int in_a_match ;
   int printing_a_match ;
};
enum __anonenum_513775621___3 {
    DT_UNKNOWN___3 = 0,
    DT_FIFO___3 = 1,
    DT_CHR___3 = 2,
    DT_DIR___3 = 4,
    DT_BLK___3 = 6,
    DT_REG___3 = 8,
    DT_LNK___3 = 10,
    DT_SOCK___3 = 12,
    DT_WHT___3 = 14
} ;
enum __anonenum_34415463___4 {
    PTHREAD_CREATE_JOINABLE___4 = 0,
    PTHREAD_CREATE_DETACHED___4 = 1
} ;
enum __anonenum_303612439___3 {
    PTHREAD_MUTEX_TIMED_NP___4 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___4 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___4 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___4 = 3,
    PTHREAD_MUTEX_NORMAL___4 = 0,
    PTHREAD_MUTEX_RECURSIVE___4 = 1,
    PTHREAD_MUTEX_ERRORCHECK___4 = 2,
    PTHREAD_MUTEX_DEFAULT___4 = 0,
    PTHREAD_MUTEX_FAST_NP___3 = 0
} ;
enum __anonenum_931900394___4 {
    PTHREAD_MUTEX_STALLED___4 = 0,
    PTHREAD_MUTEX_STALLED_NP___4 = 0,
    PTHREAD_MUTEX_ROBUST___4 = 1,
    PTHREAD_MUTEX_ROBUST_NP___4 = 1
} ;
enum __anonenum_205214487___4 {
    PTHREAD_PRIO_NONE___4 = 0,
    PTHREAD_PRIO_INHERIT___4 = 1,
    PTHREAD_PRIO_PROTECT___4 = 2
} ;
enum __anonenum_25043950___4 {
    PTHREAD_RWLOCK_PREFER_READER_NP___4 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___4 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___4 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___4 = 0
} ;
enum __anonenum_436439511___4 {
    PTHREAD_INHERIT_SCHED___4 = 0,
    PTHREAD_EXPLICIT_SCHED___4 = 1
} ;
enum __anonenum_998661166___4 {
    PTHREAD_SCOPE_SYSTEM___4 = 0,
    PTHREAD_SCOPE_PROCESS___4 = 1
} ;
enum __anonenum_146137331___4 {
    PTHREAD_PROCESS_PRIVATE___4 = 0,
    PTHREAD_PROCESS_SHARED___4 = 1
} ;
enum __anonenum_53396917___4 {
    PTHREAD_CANCEL_ENABLE___4 = 0,
    PTHREAD_CANCEL_DISABLE___4 = 1
} ;
enum __anonenum_904563783___4 {
    PTHREAD_CANCEL_DEFERRED___4 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___4 = 1
} ;
enum __anonenum_513775621___4 {
    DT_UNKNOWN___4 = 0,
    DT_FIFO___4 = 1,
    DT_CHR___4 = 2,
    DT_DIR___4 = 4,
    DT_BLK___4 = 6,
    DT_REG___4 = 8,
    DT_LNK___4 = 10,
    DT_SOCK___4 = 12,
    DT_WHT___4 = 14
} ;
enum __anonenum_437032235___1 {
    _PC_LINK_MAX___1 = 0,
    _PC_MAX_CANON___1 = 1,
    _PC_MAX_INPUT___1 = 2,
    _PC_NAME_MAX___1 = 3,
    _PC_PATH_MAX___1 = 4,
    _PC_PIPE_BUF___1 = 5,
    _PC_CHOWN_RESTRICTED___1 = 6,
    _PC_NO_TRUNC___1 = 7,
    _PC_VDISABLE___1 = 8,
    _PC_SYNC_IO___1 = 9,
    _PC_ASYNC_IO___1 = 10,
    _PC_PRIO_IO___1 = 11,
    _PC_SOCK_MAXBUF___1 = 12,
    _PC_FILESIZEBITS___1 = 13,
    _PC_REC_INCR_XFER_SIZE___1 = 14,
    _PC_REC_MAX_XFER_SIZE___1 = 15,
    _PC_REC_MIN_XFER_SIZE___1 = 16,
    _PC_REC_XFER_ALIGN___1 = 17,
    _PC_ALLOC_SIZE_MIN___1 = 18,
    _PC_SYMLINK_MAX___1 = 19,
    _PC_2_SYMLINKS___1 = 20
} ;
enum __anonenum_315186338___1 {
    _SC_ARG_MAX___1 = 0,
    _SC_CHILD_MAX___1 = 1,
    _SC_CLK_TCK___1 = 2,
    _SC_NGROUPS_MAX___1 = 3,
    _SC_OPEN_MAX___1 = 4,
    _SC_STREAM_MAX___1 = 5,
    _SC_TZNAME_MAX___1 = 6,
    _SC_JOB_CONTROL___1 = 7,
    _SC_SAVED_IDS___1 = 8,
    _SC_REALTIME_SIGNALS___1 = 9,
    _SC_PRIORITY_SCHEDULING___1 = 10,
    _SC_TIMERS___1 = 11,
    _SC_ASYNCHRONOUS_IO___1 = 12,
    _SC_PRIORITIZED_IO___1 = 13,
    _SC_SYNCHRONIZED_IO___1 = 14,
    _SC_FSYNC___1 = 15,
    _SC_MAPPED_FILES___1 = 16,
    _SC_MEMLOCK___1 = 17,
    _SC_MEMLOCK_RANGE___1 = 18,
    _SC_MEMORY_PROTECTION___1 = 19,
    _SC_MESSAGE_PASSING___1 = 20,
    _SC_SEMAPHORES___1 = 21,
    _SC_SHARED_MEMORY_OBJECTS___1 = 22,
    _SC_AIO_LISTIO_MAX___1 = 23,
    _SC_AIO_MAX___1 = 24,
    _SC_AIO_PRIO_DELTA_MAX___1 = 25,
    _SC_DELAYTIMER_MAX___1 = 26,
    _SC_MQ_OPEN_MAX___1 = 27,
    _SC_MQ_PRIO_MAX___1 = 28,
    _SC_VERSION___1 = 29,
    _SC_PAGESIZE___1 = 30,
    _SC_RTSIG_MAX___1 = 31,
    _SC_SEM_NSEMS_MAX___1 = 32,
    _SC_SEM_VALUE_MAX___1 = 33,
    _SC_SIGQUEUE_MAX___1 = 34,
    _SC_TIMER_MAX___1 = 35,
    _SC_BC_BASE_MAX___1 = 36,
    _SC_BC_DIM_MAX___1 = 37,
    _SC_BC_SCALE_MAX___1 = 38,
    _SC_BC_STRING_MAX___1 = 39,
    _SC_COLL_WEIGHTS_MAX___1 = 40,
    _SC_EQUIV_CLASS_MAX___1 = 41,
    _SC_EXPR_NEST_MAX___1 = 42,
    _SC_LINE_MAX___1 = 43,
    _SC_RE_DUP_MAX___1 = 44,
    _SC_CHARCLASS_NAME_MAX___1 = 45,
    _SC_2_VERSION___1 = 46,
    _SC_2_C_BIND___1 = 47,
    _SC_2_C_DEV___1 = 48,
    _SC_2_FORT_DEV___1 = 49,
    _SC_2_FORT_RUN___1 = 50,
    _SC_2_SW_DEV___1 = 51,
    _SC_2_LOCALEDEF___1 = 52,
    _SC_PII___1 = 53,
    _SC_PII_XTI___1 = 54,
    _SC_PII_SOCKET___1 = 55,
    _SC_PII_INTERNET___1 = 56,
    _SC_PII_OSI___1 = 57,
    _SC_POLL___1 = 58,
    _SC_SELECT___1 = 59,
    _SC_UIO_MAXIOV___1 = 60,
    _SC_IOV_MAX___1 = 60,
    _SC_PII_INTERNET_STREAM___1 = 61,
    _SC_PII_INTERNET_DGRAM___1 = 62,
    _SC_PII_OSI_COTS___1 = 63,
    _SC_PII_OSI_CLTS___1 = 64,
    _SC_PII_OSI_M___1 = 65,
    _SC_T_IOV_MAX___1 = 66,
    _SC_THREADS___1 = 67,
    _SC_THREAD_SAFE_FUNCTIONS___1 = 68,
    _SC_GETGR_R_SIZE_MAX___1 = 69,
    _SC_GETPW_R_SIZE_MAX___1 = 70,
    _SC_LOGIN_NAME_MAX___1 = 71,
    _SC_TTY_NAME_MAX___1 = 72,
    _SC_THREAD_DESTRUCTOR_ITERATIONS___1 = 73,
    _SC_THREAD_KEYS_MAX___1 = 74,
    _SC_THREAD_STACK_MIN___1 = 75,
    _SC_THREAD_THREADS_MAX___1 = 76,
    _SC_THREAD_ATTR_STACKADDR___1 = 77,
    _SC_THREAD_ATTR_STACKSIZE___1 = 78,
    _SC_THREAD_PRIORITY_SCHEDULING___1 = 79,
    _SC_THREAD_PRIO_INHERIT___1 = 80,
    _SC_THREAD_PRIO_PROTECT___1 = 81,
    _SC_THREAD_PROCESS_SHARED___1 = 82,
    _SC_NPROCESSORS_CONF___1 = 83,
    _SC_NPROCESSORS_ONLN___1 = 84,
    _SC_PHYS_PAGES___1 = 85,
    _SC_AVPHYS_PAGES___1 = 86,
    _SC_ATEXIT_MAX___1 = 87,
    _SC_PASS_MAX___1 = 88,
    _SC_XOPEN_VERSION___1 = 89,
    _SC_XOPEN_XCU_VERSION___1 = 90,
    _SC_XOPEN_UNIX___1 = 91,
    _SC_XOPEN_CRYPT___1 = 92,
    _SC_XOPEN_ENH_I18N___1 = 93,
    _SC_XOPEN_SHM___1 = 94,
    _SC_2_CHAR_TERM___1 = 95,
    _SC_2_C_VERSION___1 = 96,
    _SC_2_UPE___1 = 97,
    _SC_XOPEN_XPG2___1 = 98,
    _SC_XOPEN_XPG3___1 = 99,
    _SC_XOPEN_XPG4___1 = 100,
    _SC_CHAR_BIT___1 = 101,
    _SC_CHAR_MAX___1 = 102,
    _SC_CHAR_MIN___1 = 103,
    _SC_INT_MAX___1 = 104,
    _SC_INT_MIN___1 = 105,
    _SC_LONG_BIT___1 = 106,
    _SC_WORD_BIT___1 = 107,
    _SC_MB_LEN_MAX___1 = 108,
    _SC_NZERO___1 = 109,
    _SC_SSIZE_MAX___1 = 110,
    _SC_SCHAR_MAX___1 = 111,
    _SC_SCHAR_MIN___1 = 112,
    _SC_SHRT_MAX___1 = 113,
    _SC_SHRT_MIN___1 = 114,
    _SC_UCHAR_MAX___1 = 115,
    _SC_UINT_MAX___1 = 116,
    _SC_ULONG_MAX___1 = 117,
    _SC_USHRT_MAX___1 = 118,
    _SC_NL_ARGMAX___1 = 119,
    _SC_NL_LANGMAX___1 = 120,
    _SC_NL_MSGMAX___1 = 121,
    _SC_NL_NMAX___1 = 122,
    _SC_NL_SETMAX___1 = 123,
    _SC_NL_TEXTMAX___1 = 124,
    _SC_XBS5_ILP32_OFF32___1 = 125,
    _SC_XBS5_ILP32_OFFBIG___1 = 126,
    _SC_XBS5_LP64_OFF64___1 = 127,
    _SC_XBS5_LPBIG_OFFBIG___1 = 128,
    _SC_XOPEN_LEGACY___1 = 129,
    _SC_XOPEN_REALTIME___1 = 130,
    _SC_XOPEN_REALTIME_THREADS___1 = 131,
    _SC_ADVISORY_INFO___1 = 132,
    _SC_BARRIERS___1 = 133,
    _SC_BASE___1 = 134,
    _SC_C_LANG_SUPPORT___1 = 135,
    _SC_C_LANG_SUPPORT_R___1 = 136,
    _SC_CLOCK_SELECTION___1 = 137,
    _SC_CPUTIME___1 = 138,
    _SC_THREAD_CPUTIME___1 = 139,
    _SC_DEVICE_IO___1 = 140,
    _SC_DEVICE_SPECIFIC___1 = 141,
    _SC_DEVICE_SPECIFIC_R___1 = 142,
    _SC_FD_MGMT___1 = 143,
    _SC_FIFO___1 = 144,
    _SC_PIPE___1 = 145,
    _SC_FILE_ATTRIBUTES___1 = 146,
    _SC_FILE_LOCKING___1 = 147,
    _SC_FILE_SYSTEM___1 = 148,
    _SC_MONOTONIC_CLOCK___1 = 149,
    _SC_MULTI_PROCESS___1 = 150,
    _SC_SINGLE_PROCESS___1 = 151,
    _SC_NETWORKING___1 = 152,
    _SC_READER_WRITER_LOCKS___1 = 153,
    _SC_SPIN_LOCKS___1 = 154,
    _SC_REGEXP___1 = 155,
    _SC_REGEX_VERSION___1 = 156,
    _SC_SHELL___1 = 157,
    _SC_SIGNALS___1 = 158,
    _SC_SPAWN___1 = 159,
    _SC_SPORADIC_SERVER___1 = 160,
    _SC_THREAD_SPORADIC_SERVER___1 = 161,
    _SC_SYSTEM_DATABASE___1 = 162,
    _SC_SYSTEM_DATABASE_R___1 = 163,
    _SC_TIMEOUTS___1 = 164,
    _SC_TYPED_MEMORY_OBJECTS___1 = 165,
    _SC_USER_GROUPS___1 = 166,
    _SC_USER_GROUPS_R___1 = 167,
    _SC_2_PBS___1 = 168,
    _SC_2_PBS_ACCOUNTING___1 = 169,
    _SC_2_PBS_LOCATE___1 = 170,
    _SC_2_PBS_MESSAGE___1 = 171,
    _SC_2_PBS_TRACK___1 = 172,
    _SC_SYMLOOP_MAX___1 = 173,
    _SC_STREAMS___1 = 174,
    _SC_2_PBS_CHECKPOINT___1 = 175,
    _SC_V6_ILP32_OFF32___1 = 176,
    _SC_V6_ILP32_OFFBIG___1 = 177,
    _SC_V6_LP64_OFF64___1 = 178,
    _SC_V6_LPBIG_OFFBIG___1 = 179,
    _SC_HOST_NAME_MAX___1 = 180,
    _SC_TRACE___1 = 181,
    _SC_TRACE_EVENT_FILTER___1 = 182,
    _SC_TRACE_INHERIT___1 = 183,
    _SC_TRACE_LOG___1 = 184,
    _SC_LEVEL1_ICACHE_SIZE___1 = 185,
    _SC_LEVEL1_ICACHE_ASSOC___1 = 186,
    _SC_LEVEL1_ICACHE_LINESIZE___1 = 187,
    _SC_LEVEL1_DCACHE_SIZE___1 = 188,
    _SC_LEVEL1_DCACHE_ASSOC___1 = 189,
    _SC_LEVEL1_DCACHE_LINESIZE___1 = 190,
    _SC_LEVEL2_CACHE_SIZE___1 = 191,
    _SC_LEVEL2_CACHE_ASSOC___1 = 192,
    _SC_LEVEL2_CACHE_LINESIZE___1 = 193,
    _SC_LEVEL3_CACHE_SIZE___1 = 194,
    _SC_LEVEL3_CACHE_ASSOC___1 = 195,
    _SC_LEVEL3_CACHE_LINESIZE___1 = 196,
    _SC_LEVEL4_CACHE_SIZE___1 = 197,
    _SC_LEVEL4_CACHE_ASSOC___1 = 198,
    _SC_LEVEL4_CACHE_LINESIZE___1 = 199,
    _SC_IPV6___1 = 235,
    _SC_RAW_SOCKETS___1 = 236,
    _SC_V7_ILP32_OFF32___1 = 237,
    _SC_V7_ILP32_OFFBIG___1 = 238,
    _SC_V7_LP64_OFF64___1 = 239,
    _SC_V7_LPBIG_OFFBIG___1 = 240,
    _SC_SS_REPL_MAX___1 = 241,
    _SC_TRACE_EVENT_NAME_MAX___1 = 242,
    _SC_TRACE_NAME_MAX___1 = 243,
    _SC_TRACE_SYS_MAX___1 = 244,
    _SC_TRACE_USER_EVENT_MAX___1 = 245,
    _SC_XOPEN_STREAMS___1 = 246,
    _SC_THREAD_ROBUST_PRIO_INHERIT___1 = 247,
    _SC_THREAD_ROBUST_PRIO_PROTECT___1 = 248,
    _SC_MINSIGSTKSZ___1 = 249,
    _SC_SIGSTKSZ___1 = 250
} ;
enum __anonenum_875524036___1 {
    _CS_PATH___1 = 0,
    _CS_V6_WIDTH_RESTRICTED_ENVS___1 = 1,
    _CS_GNU_LIBC_VERSION___1 = 2,
    _CS_GNU_LIBPTHREAD_VERSION___1 = 3,
    _CS_V5_WIDTH_RESTRICTED_ENVS___1 = 4,
    _CS_V7_WIDTH_RESTRICTED_ENVS___1 = 5,
    _CS_LFS_CFLAGS___1 = 1000,
    _CS_LFS_LDFLAGS___1 = 1001,
    _CS_LFS_LIBS___1 = 1002,
    _CS_LFS_LINTFLAGS___1 = 1003,
    _CS_LFS64_CFLAGS___1 = 1004,
    _CS_LFS64_LDFLAGS___1 = 1005,
    _CS_LFS64_LIBS___1 = 1006,
    _CS_LFS64_LINTFLAGS___1 = 1007,
    _CS_XBS5_ILP32_OFF32_CFLAGS___1 = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS___1 = 1101,
    _CS_XBS5_ILP32_OFF32_LIBS___1 = 1102,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS___1 = 1103,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS___1 = 1104,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS___1 = 1105,
    _CS_XBS5_ILP32_OFFBIG_LIBS___1 = 1106,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS___1 = 1107,
    _CS_XBS5_LP64_OFF64_CFLAGS___1 = 1108,
    _CS_XBS5_LP64_OFF64_LDFLAGS___1 = 1109,
    _CS_XBS5_LP64_OFF64_LIBS___1 = 1110,
    _CS_XBS5_LP64_OFF64_LINTFLAGS___1 = 1111,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS___1 = 1112,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS___1 = 1113,
    _CS_XBS5_LPBIG_OFFBIG_LIBS___1 = 1114,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS___1 = 1115,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS___1 = 1116,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS___1 = 1117,
    _CS_POSIX_V6_ILP32_OFF32_LIBS___1 = 1118,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS___1 = 1119,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS___1 = 1120,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS___1 = 1121,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS___1 = 1122,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS___1 = 1123,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS___1 = 1124,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS___1 = 1125,
    _CS_POSIX_V6_LP64_OFF64_LIBS___1 = 1126,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS___1 = 1127,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS___1 = 1128,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS___1 = 1129,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS___1 = 1130,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS___1 = 1131,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS___1 = 1132,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS___1 = 1133,
    _CS_POSIX_V7_ILP32_OFF32_LIBS___1 = 1134,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS___1 = 1135,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS___1 = 1136,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS___1 = 1137,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS___1 = 1138,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS___1 = 1139,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS___1 = 1140,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS___1 = 1141,
    _CS_POSIX_V7_LP64_OFF64_LIBS___1 = 1142,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS___1 = 1143,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS___1 = 1144,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS___1 = 1145,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS___1 = 1146,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS___1 = 1147,
    _CS_V6_ENV___1 = 1148,
    _CS_V7_ENV___1 = 1149
} ;
enum __anonenum_34415463___5 {
    PTHREAD_CREATE_JOINABLE___5 = 0,
    PTHREAD_CREATE_DETACHED___5 = 1
} ;
enum __anonenum_303612439___4 {
    PTHREAD_MUTEX_TIMED_NP___5 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___5 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___5 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___5 = 3,
    PTHREAD_MUTEX_NORMAL___5 = 0,
    PTHREAD_MUTEX_RECURSIVE___5 = 1,
    PTHREAD_MUTEX_ERRORCHECK___5 = 2,
    PTHREAD_MUTEX_DEFAULT___5 = 0,
    PTHREAD_MUTEX_FAST_NP___4 = 0
} ;
enum __anonenum_931900394___5 {
    PTHREAD_MUTEX_STALLED___5 = 0,
    PTHREAD_MUTEX_STALLED_NP___5 = 0,
    PTHREAD_MUTEX_ROBUST___5 = 1,
    PTHREAD_MUTEX_ROBUST_NP___5 = 1
} ;
enum __anonenum_205214487___5 {
    PTHREAD_PRIO_NONE___5 = 0,
    PTHREAD_PRIO_INHERIT___5 = 1,
    PTHREAD_PRIO_PROTECT___5 = 2
} ;
enum __anonenum_25043950___5 {
    PTHREAD_RWLOCK_PREFER_READER_NP___5 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___5 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___5 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___5 = 0
} ;
enum __anonenum_436439511___5 {
    PTHREAD_INHERIT_SCHED___5 = 0,
    PTHREAD_EXPLICIT_SCHED___5 = 1
} ;
enum __anonenum_998661166___5 {
    PTHREAD_SCOPE_SYSTEM___5 = 0,
    PTHREAD_SCOPE_PROCESS___5 = 1
} ;
enum __anonenum_146137331___5 {
    PTHREAD_PROCESS_PRIVATE___5 = 0,
    PTHREAD_PROCESS_SHARED___5 = 1
} ;
enum __anonenum_53396917___5 {
    PTHREAD_CANCEL_ENABLE___5 = 0,
    PTHREAD_CANCEL_DISABLE___5 = 1
} ;
enum __anonenum_904563783___5 {
    PTHREAD_CANCEL_DEFERRED___5 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___5 = 1
} ;
enum __anonenum_513775621___5 {
    DT_UNKNOWN___5 = 0,
    DT_FIFO___5 = 1,
    DT_CHR___5 = 2,
    DT_DIR___5 = 4,
    DT_BLK___5 = 6,
    DT_REG___5 = 8,
    DT_LNK___5 = 10,
    DT_SOCK___5 = 12,
    DT_WHT___5 = 14
} ;
enum __anonenum_34415463___6 {
    PTHREAD_CREATE_JOINABLE___6 = 0,
    PTHREAD_CREATE_DETACHED___6 = 1
} ;
enum __anonenum_303612439___5 {
    PTHREAD_MUTEX_TIMED_NP___6 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___6 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___6 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___6 = 3,
    PTHREAD_MUTEX_NORMAL___6 = 0,
    PTHREAD_MUTEX_RECURSIVE___6 = 1,
    PTHREAD_MUTEX_ERRORCHECK___6 = 2,
    PTHREAD_MUTEX_DEFAULT___6 = 0,
    PTHREAD_MUTEX_FAST_NP___5 = 0
} ;
enum __anonenum_931900394___6 {
    PTHREAD_MUTEX_STALLED___6 = 0,
    PTHREAD_MUTEX_STALLED_NP___6 = 0,
    PTHREAD_MUTEX_ROBUST___6 = 1,
    PTHREAD_MUTEX_ROBUST_NP___6 = 1
} ;
enum __anonenum_205214487___6 {
    PTHREAD_PRIO_NONE___6 = 0,
    PTHREAD_PRIO_INHERIT___6 = 1,
    PTHREAD_PRIO_PROTECT___6 = 2
} ;
enum __anonenum_25043950___6 {
    PTHREAD_RWLOCK_PREFER_READER_NP___6 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___6 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___6 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___6 = 0
} ;
enum __anonenum_436439511___6 {
    PTHREAD_INHERIT_SCHED___6 = 0,
    PTHREAD_EXPLICIT_SCHED___6 = 1
} ;
enum __anonenum_998661166___6 {
    PTHREAD_SCOPE_SYSTEM___6 = 0,
    PTHREAD_SCOPE_PROCESS___6 = 1
} ;
enum __anonenum_146137331___6 {
    PTHREAD_PROCESS_PRIVATE___6 = 0,
    PTHREAD_PROCESS_SHARED___6 = 1
} ;
enum __anonenum_53396917___6 {
    PTHREAD_CANCEL_ENABLE___6 = 0,
    PTHREAD_CANCEL_DISABLE___6 = 1
} ;
enum __anonenum_904563783___6 {
    PTHREAD_CANCEL_DEFERRED___6 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___6 = 1
} ;
enum __anonenum_18926444___0 {
    _ISupper___0 = 256,
    _ISlower___0 = 512,
    _ISalpha___0 = 1024,
    _ISdigit___0 = 2048,
    _ISxdigit___0 = 4096,
    _ISspace___0 = 8192,
    _ISprint___0 = 16384,
    _ISgraph___0 = 32768,
    _ISblank___0 = 1,
    _IScntrl___0 = 2,
    _ISpunct___0 = 4,
    _ISalnum___0 = 8
} ;
enum __anonenum_513775621___6 {
    DT_UNKNOWN___6 = 0,
    DT_FIFO___6 = 1,
    DT_CHR___6 = 2,
    DT_DIR___6 = 4,
    DT_BLK___6 = 6,
    DT_REG___6 = 8,
    DT_LNK___6 = 10,
    DT_SOCK___6 = 12,
    DT_WHT___6 = 14
} ;
enum __anonenum_34415463___7 {
    PTHREAD_CREATE_JOINABLE___7 = 0,
    PTHREAD_CREATE_DETACHED___7 = 1
} ;
enum __anonenum_303612439___6 {
    PTHREAD_MUTEX_TIMED_NP___7 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___7 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___7 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___7 = 3,
    PTHREAD_MUTEX_NORMAL___7 = 0,
    PTHREAD_MUTEX_RECURSIVE___7 = 1,
    PTHREAD_MUTEX_ERRORCHECK___7 = 2,
    PTHREAD_MUTEX_DEFAULT___7 = 0,
    PTHREAD_MUTEX_FAST_NP___6 = 0
} ;
enum __anonenum_931900394___7 {
    PTHREAD_MUTEX_STALLED___7 = 0,
    PTHREAD_MUTEX_STALLED_NP___7 = 0,
    PTHREAD_MUTEX_ROBUST___7 = 1,
    PTHREAD_MUTEX_ROBUST_NP___7 = 1
} ;
enum __anonenum_205214487___7 {
    PTHREAD_PRIO_NONE___7 = 0,
    PTHREAD_PRIO_INHERIT___7 = 1,
    PTHREAD_PRIO_PROTECT___7 = 2
} ;
enum __anonenum_25043950___7 {
    PTHREAD_RWLOCK_PREFER_READER_NP___7 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___7 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___7 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___7 = 0
} ;
enum __anonenum_436439511___7 {
    PTHREAD_INHERIT_SCHED___7 = 0,
    PTHREAD_EXPLICIT_SCHED___7 = 1
} ;
enum __anonenum_998661166___7 {
    PTHREAD_SCOPE_SYSTEM___7 = 0,
    PTHREAD_SCOPE_PROCESS___7 = 1
} ;
enum __anonenum_146137331___7 {
    PTHREAD_PROCESS_PRIVATE___7 = 0,
    PTHREAD_PROCESS_SHARED___7 = 1
} ;
enum __anonenum_53396917___7 {
    PTHREAD_CANCEL_ENABLE___7 = 0,
    PTHREAD_CANCEL_DISABLE___7 = 1
} ;
enum __anonenum_904563783___7 {
    PTHREAD_CANCEL_DEFERRED___7 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___7 = 1
} ;
enum __anonenum_437032235___2 {
    _PC_LINK_MAX___2 = 0,
    _PC_MAX_CANON___2 = 1,
    _PC_MAX_INPUT___2 = 2,
    _PC_NAME_MAX___2 = 3,
    _PC_PATH_MAX___2 = 4,
    _PC_PIPE_BUF___2 = 5,
    _PC_CHOWN_RESTRICTED___2 = 6,
    _PC_NO_TRUNC___2 = 7,
    _PC_VDISABLE___2 = 8,
    _PC_SYNC_IO___2 = 9,
    _PC_ASYNC_IO___2 = 10,
    _PC_PRIO_IO___2 = 11,
    _PC_SOCK_MAXBUF___2 = 12,
    _PC_FILESIZEBITS___2 = 13,
    _PC_REC_INCR_XFER_SIZE___2 = 14,
    _PC_REC_MAX_XFER_SIZE___2 = 15,
    _PC_REC_MIN_XFER_SIZE___2 = 16,
    _PC_REC_XFER_ALIGN___2 = 17,
    _PC_ALLOC_SIZE_MIN___2 = 18,
    _PC_SYMLINK_MAX___2 = 19,
    _PC_2_SYMLINKS___2 = 20
} ;
enum __anonenum_315186338___2 {
    _SC_ARG_MAX___2 = 0,
    _SC_CHILD_MAX___2 = 1,
    _SC_CLK_TCK___2 = 2,
    _SC_NGROUPS_MAX___2 = 3,
    _SC_OPEN_MAX___2 = 4,
    _SC_STREAM_MAX___2 = 5,
    _SC_TZNAME_MAX___2 = 6,
    _SC_JOB_CONTROL___2 = 7,
    _SC_SAVED_IDS___2 = 8,
    _SC_REALTIME_SIGNALS___2 = 9,
    _SC_PRIORITY_SCHEDULING___2 = 10,
    _SC_TIMERS___2 = 11,
    _SC_ASYNCHRONOUS_IO___2 = 12,
    _SC_PRIORITIZED_IO___2 = 13,
    _SC_SYNCHRONIZED_IO___2 = 14,
    _SC_FSYNC___2 = 15,
    _SC_MAPPED_FILES___2 = 16,
    _SC_MEMLOCK___2 = 17,
    _SC_MEMLOCK_RANGE___2 = 18,
    _SC_MEMORY_PROTECTION___2 = 19,
    _SC_MESSAGE_PASSING___2 = 20,
    _SC_SEMAPHORES___2 = 21,
    _SC_SHARED_MEMORY_OBJECTS___2 = 22,
    _SC_AIO_LISTIO_MAX___2 = 23,
    _SC_AIO_MAX___2 = 24,
    _SC_AIO_PRIO_DELTA_MAX___2 = 25,
    _SC_DELAYTIMER_MAX___2 = 26,
    _SC_MQ_OPEN_MAX___2 = 27,
    _SC_MQ_PRIO_MAX___2 = 28,
    _SC_VERSION___2 = 29,
    _SC_PAGESIZE___2 = 30,
    _SC_RTSIG_MAX___2 = 31,
    _SC_SEM_NSEMS_MAX___2 = 32,
    _SC_SEM_VALUE_MAX___2 = 33,
    _SC_SIGQUEUE_MAX___2 = 34,
    _SC_TIMER_MAX___2 = 35,
    _SC_BC_BASE_MAX___2 = 36,
    _SC_BC_DIM_MAX___2 = 37,
    _SC_BC_SCALE_MAX___2 = 38,
    _SC_BC_STRING_MAX___2 = 39,
    _SC_COLL_WEIGHTS_MAX___2 = 40,
    _SC_EQUIV_CLASS_MAX___2 = 41,
    _SC_EXPR_NEST_MAX___2 = 42,
    _SC_LINE_MAX___2 = 43,
    _SC_RE_DUP_MAX___2 = 44,
    _SC_CHARCLASS_NAME_MAX___2 = 45,
    _SC_2_VERSION___2 = 46,
    _SC_2_C_BIND___2 = 47,
    _SC_2_C_DEV___2 = 48,
    _SC_2_FORT_DEV___2 = 49,
    _SC_2_FORT_RUN___2 = 50,
    _SC_2_SW_DEV___2 = 51,
    _SC_2_LOCALEDEF___2 = 52,
    _SC_PII___2 = 53,
    _SC_PII_XTI___2 = 54,
    _SC_PII_SOCKET___2 = 55,
    _SC_PII_INTERNET___2 = 56,
    _SC_PII_OSI___2 = 57,
    _SC_POLL___2 = 58,
    _SC_SELECT___2 = 59,
    _SC_UIO_MAXIOV___2 = 60,
    _SC_IOV_MAX___2 = 60,
    _SC_PII_INTERNET_STREAM___2 = 61,
    _SC_PII_INTERNET_DGRAM___2 = 62,
    _SC_PII_OSI_COTS___2 = 63,
    _SC_PII_OSI_CLTS___2 = 64,
    _SC_PII_OSI_M___2 = 65,
    _SC_T_IOV_MAX___2 = 66,
    _SC_THREADS___2 = 67,
    _SC_THREAD_SAFE_FUNCTIONS___2 = 68,
    _SC_GETGR_R_SIZE_MAX___2 = 69,
    _SC_GETPW_R_SIZE_MAX___2 = 70,
    _SC_LOGIN_NAME_MAX___2 = 71,
    _SC_TTY_NAME_MAX___2 = 72,
    _SC_THREAD_DESTRUCTOR_ITERATIONS___2 = 73,
    _SC_THREAD_KEYS_MAX___2 = 74,
    _SC_THREAD_STACK_MIN___2 = 75,
    _SC_THREAD_THREADS_MAX___2 = 76,
    _SC_THREAD_ATTR_STACKADDR___2 = 77,
    _SC_THREAD_ATTR_STACKSIZE___2 = 78,
    _SC_THREAD_PRIORITY_SCHEDULING___2 = 79,
    _SC_THREAD_PRIO_INHERIT___2 = 80,
    _SC_THREAD_PRIO_PROTECT___2 = 81,
    _SC_THREAD_PROCESS_SHARED___2 = 82,
    _SC_NPROCESSORS_CONF___2 = 83,
    _SC_NPROCESSORS_ONLN___2 = 84,
    _SC_PHYS_PAGES___2 = 85,
    _SC_AVPHYS_PAGES___2 = 86,
    _SC_ATEXIT_MAX___2 = 87,
    _SC_PASS_MAX___2 = 88,
    _SC_XOPEN_VERSION___2 = 89,
    _SC_XOPEN_XCU_VERSION___2 = 90,
    _SC_XOPEN_UNIX___2 = 91,
    _SC_XOPEN_CRYPT___2 = 92,
    _SC_XOPEN_ENH_I18N___2 = 93,
    _SC_XOPEN_SHM___2 = 94,
    _SC_2_CHAR_TERM___2 = 95,
    _SC_2_C_VERSION___2 = 96,
    _SC_2_UPE___2 = 97,
    _SC_XOPEN_XPG2___2 = 98,
    _SC_XOPEN_XPG3___2 = 99,
    _SC_XOPEN_XPG4___2 = 100,
    _SC_CHAR_BIT___2 = 101,
    _SC_CHAR_MAX___2 = 102,
    _SC_CHAR_MIN___2 = 103,
    _SC_INT_MAX___2 = 104,
    _SC_INT_MIN___2 = 105,
    _SC_LONG_BIT___2 = 106,
    _SC_WORD_BIT___2 = 107,
    _SC_MB_LEN_MAX___2 = 108,
    _SC_NZERO___2 = 109,
    _SC_SSIZE_MAX___2 = 110,
    _SC_SCHAR_MAX___2 = 111,
    _SC_SCHAR_MIN___2 = 112,
    _SC_SHRT_MAX___2 = 113,
    _SC_SHRT_MIN___2 = 114,
    _SC_UCHAR_MAX___2 = 115,
    _SC_UINT_MAX___2 = 116,
    _SC_ULONG_MAX___2 = 117,
    _SC_USHRT_MAX___2 = 118,
    _SC_NL_ARGMAX___2 = 119,
    _SC_NL_LANGMAX___2 = 120,
    _SC_NL_MSGMAX___2 = 121,
    _SC_NL_NMAX___2 = 122,
    _SC_NL_SETMAX___2 = 123,
    _SC_NL_TEXTMAX___2 = 124,
    _SC_XBS5_ILP32_OFF32___2 = 125,
    _SC_XBS5_ILP32_OFFBIG___2 = 126,
    _SC_XBS5_LP64_OFF64___2 = 127,
    _SC_XBS5_LPBIG_OFFBIG___2 = 128,
    _SC_XOPEN_LEGACY___2 = 129,
    _SC_XOPEN_REALTIME___2 = 130,
    _SC_XOPEN_REALTIME_THREADS___2 = 131,
    _SC_ADVISORY_INFO___2 = 132,
    _SC_BARRIERS___2 = 133,
    _SC_BASE___2 = 134,
    _SC_C_LANG_SUPPORT___2 = 135,
    _SC_C_LANG_SUPPORT_R___2 = 136,
    _SC_CLOCK_SELECTION___2 = 137,
    _SC_CPUTIME___2 = 138,
    _SC_THREAD_CPUTIME___2 = 139,
    _SC_DEVICE_IO___2 = 140,
    _SC_DEVICE_SPECIFIC___2 = 141,
    _SC_DEVICE_SPECIFIC_R___2 = 142,
    _SC_FD_MGMT___2 = 143,
    _SC_FIFO___2 = 144,
    _SC_PIPE___2 = 145,
    _SC_FILE_ATTRIBUTES___2 = 146,
    _SC_FILE_LOCKING___2 = 147,
    _SC_FILE_SYSTEM___2 = 148,
    _SC_MONOTONIC_CLOCK___2 = 149,
    _SC_MULTI_PROCESS___2 = 150,
    _SC_SINGLE_PROCESS___2 = 151,
    _SC_NETWORKING___2 = 152,
    _SC_READER_WRITER_LOCKS___2 = 153,
    _SC_SPIN_LOCKS___2 = 154,
    _SC_REGEXP___2 = 155,
    _SC_REGEX_VERSION___2 = 156,
    _SC_SHELL___2 = 157,
    _SC_SIGNALS___2 = 158,
    _SC_SPAWN___2 = 159,
    _SC_SPORADIC_SERVER___2 = 160,
    _SC_THREAD_SPORADIC_SERVER___2 = 161,
    _SC_SYSTEM_DATABASE___2 = 162,
    _SC_SYSTEM_DATABASE_R___2 = 163,
    _SC_TIMEOUTS___2 = 164,
    _SC_TYPED_MEMORY_OBJECTS___2 = 165,
    _SC_USER_GROUPS___2 = 166,
    _SC_USER_GROUPS_R___2 = 167,
    _SC_2_PBS___2 = 168,
    _SC_2_PBS_ACCOUNTING___2 = 169,
    _SC_2_PBS_LOCATE___2 = 170,
    _SC_2_PBS_MESSAGE___2 = 171,
    _SC_2_PBS_TRACK___2 = 172,
    _SC_SYMLOOP_MAX___2 = 173,
    _SC_STREAMS___2 = 174,
    _SC_2_PBS_CHECKPOINT___2 = 175,
    _SC_V6_ILP32_OFF32___2 = 176,
    _SC_V6_ILP32_OFFBIG___2 = 177,
    _SC_V6_LP64_OFF64___2 = 178,
    _SC_V6_LPBIG_OFFBIG___2 = 179,
    _SC_HOST_NAME_MAX___2 = 180,
    _SC_TRACE___2 = 181,
    _SC_TRACE_EVENT_FILTER___2 = 182,
    _SC_TRACE_INHERIT___2 = 183,
    _SC_TRACE_LOG___2 = 184,
    _SC_LEVEL1_ICACHE_SIZE___2 = 185,
    _SC_LEVEL1_ICACHE_ASSOC___2 = 186,
    _SC_LEVEL1_ICACHE_LINESIZE___2 = 187,
    _SC_LEVEL1_DCACHE_SIZE___2 = 188,
    _SC_LEVEL1_DCACHE_ASSOC___2 = 189,
    _SC_LEVEL1_DCACHE_LINESIZE___2 = 190,
    _SC_LEVEL2_CACHE_SIZE___2 = 191,
    _SC_LEVEL2_CACHE_ASSOC___2 = 192,
    _SC_LEVEL2_CACHE_LINESIZE___2 = 193,
    _SC_LEVEL3_CACHE_SIZE___2 = 194,
    _SC_LEVEL3_CACHE_ASSOC___2 = 195,
    _SC_LEVEL3_CACHE_LINESIZE___2 = 196,
    _SC_LEVEL4_CACHE_SIZE___2 = 197,
    _SC_LEVEL4_CACHE_ASSOC___2 = 198,
    _SC_LEVEL4_CACHE_LINESIZE___2 = 199,
    _SC_IPV6___2 = 235,
    _SC_RAW_SOCKETS___2 = 236,
    _SC_V7_ILP32_OFF32___2 = 237,
    _SC_V7_ILP32_OFFBIG___2 = 238,
    _SC_V7_LP64_OFF64___2 = 239,
    _SC_V7_LPBIG_OFFBIG___2 = 240,
    _SC_SS_REPL_MAX___2 = 241,
    _SC_TRACE_EVENT_NAME_MAX___2 = 242,
    _SC_TRACE_NAME_MAX___2 = 243,
    _SC_TRACE_SYS_MAX___2 = 244,
    _SC_TRACE_USER_EVENT_MAX___2 = 245,
    _SC_XOPEN_STREAMS___2 = 246,
    _SC_THREAD_ROBUST_PRIO_INHERIT___2 = 247,
    _SC_THREAD_ROBUST_PRIO_PROTECT___2 = 248,
    _SC_MINSIGSTKSZ___2 = 249,
    _SC_SIGSTKSZ___2 = 250
} ;
enum __anonenum_875524036___2 {
    _CS_PATH___2 = 0,
    _CS_V6_WIDTH_RESTRICTED_ENVS___2 = 1,
    _CS_GNU_LIBC_VERSION___2 = 2,
    _CS_GNU_LIBPTHREAD_VERSION___2 = 3,
    _CS_V5_WIDTH_RESTRICTED_ENVS___2 = 4,
    _CS_V7_WIDTH_RESTRICTED_ENVS___2 = 5,
    _CS_LFS_CFLAGS___2 = 1000,
    _CS_LFS_LDFLAGS___2 = 1001,
    _CS_LFS_LIBS___2 = 1002,
    _CS_LFS_LINTFLAGS___2 = 1003,
    _CS_LFS64_CFLAGS___2 = 1004,
    _CS_LFS64_LDFLAGS___2 = 1005,
    _CS_LFS64_LIBS___2 = 1006,
    _CS_LFS64_LINTFLAGS___2 = 1007,
    _CS_XBS5_ILP32_OFF32_CFLAGS___2 = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS___2 = 1101,
    _CS_XBS5_ILP32_OFF32_LIBS___2 = 1102,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS___2 = 1103,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS___2 = 1104,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS___2 = 1105,
    _CS_XBS5_ILP32_OFFBIG_LIBS___2 = 1106,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS___2 = 1107,
    _CS_XBS5_LP64_OFF64_CFLAGS___2 = 1108,
    _CS_XBS5_LP64_OFF64_LDFLAGS___2 = 1109,
    _CS_XBS5_LP64_OFF64_LIBS___2 = 1110,
    _CS_XBS5_LP64_OFF64_LINTFLAGS___2 = 1111,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS___2 = 1112,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS___2 = 1113,
    _CS_XBS5_LPBIG_OFFBIG_LIBS___2 = 1114,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS___2 = 1115,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS___2 = 1116,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS___2 = 1117,
    _CS_POSIX_V6_ILP32_OFF32_LIBS___2 = 1118,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS___2 = 1119,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS___2 = 1120,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS___2 = 1121,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS___2 = 1122,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS___2 = 1123,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS___2 = 1124,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS___2 = 1125,
    _CS_POSIX_V6_LP64_OFF64_LIBS___2 = 1126,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS___2 = 1127,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS___2 = 1128,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS___2 = 1129,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS___2 = 1130,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS___2 = 1131,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS___2 = 1132,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS___2 = 1133,
    _CS_POSIX_V7_ILP32_OFF32_LIBS___2 = 1134,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS___2 = 1135,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS___2 = 1136,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS___2 = 1137,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS___2 = 1138,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS___2 = 1139,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS___2 = 1140,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS___2 = 1141,
    _CS_POSIX_V7_LP64_OFF64_LIBS___2 = 1142,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS___2 = 1143,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS___2 = 1144,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS___2 = 1145,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS___2 = 1146,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS___2 = 1147,
    _CS_V6_ENV___2 = 1148,
    _CS_V7_ENV___2 = 1149
} ;
enum __anonenum_34415463___8 {
    PTHREAD_CREATE_JOINABLE___8 = 0,
    PTHREAD_CREATE_DETACHED___8 = 1
} ;
enum __anonenum_303612439___7 {
    PTHREAD_MUTEX_TIMED_NP___8 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___8 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___8 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___8 = 3,
    PTHREAD_MUTEX_NORMAL___8 = 0,
    PTHREAD_MUTEX_RECURSIVE___8 = 1,
    PTHREAD_MUTEX_ERRORCHECK___8 = 2,
    PTHREAD_MUTEX_DEFAULT___8 = 0,
    PTHREAD_MUTEX_FAST_NP___7 = 0
} ;
enum __anonenum_931900394___8 {
    PTHREAD_MUTEX_STALLED___8 = 0,
    PTHREAD_MUTEX_STALLED_NP___8 = 0,
    PTHREAD_MUTEX_ROBUST___8 = 1,
    PTHREAD_MUTEX_ROBUST_NP___8 = 1
} ;
enum __anonenum_205214487___8 {
    PTHREAD_PRIO_NONE___8 = 0,
    PTHREAD_PRIO_INHERIT___8 = 1,
    PTHREAD_PRIO_PROTECT___8 = 2
} ;
enum __anonenum_25043950___8 {
    PTHREAD_RWLOCK_PREFER_READER_NP___8 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___8 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___8 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___8 = 0
} ;
enum __anonenum_436439511___8 {
    PTHREAD_INHERIT_SCHED___8 = 0,
    PTHREAD_EXPLICIT_SCHED___8 = 1
} ;
enum __anonenum_998661166___8 {
    PTHREAD_SCOPE_SYSTEM___8 = 0,
    PTHREAD_SCOPE_PROCESS___8 = 1
} ;
enum __anonenum_146137331___8 {
    PTHREAD_PROCESS_PRIVATE___8 = 0,
    PTHREAD_PROCESS_SHARED___8 = 1
} ;
enum __anonenum_53396917___8 {
    PTHREAD_CANCEL_ENABLE___8 = 0,
    PTHREAD_CANCEL_DISABLE___8 = 1
} ;
enum __anonenum_904563783___8 {
    PTHREAD_CANCEL_DEFERRED___8 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___8 = 1
} ;
typedef int __gwchar_t;
struct __anonstruct_imaxdiv_t_847750061 {
   long quot ;
   long rem ;
};
typedef struct __anonstruct_imaxdiv_t_847750061 imaxdiv_t;
typedef unsigned char lzma_bool;
enum __anonenum_lzma_reserved_enum_264666109 {
    LZMA_RESERVED_ENUM = 0
} ;
typedef enum __anonenum_lzma_reserved_enum_264666109 lzma_reserved_enum;
enum __anonenum_lzma_ret_557241514 {
    LZMA_OK = 0,
    LZMA_STREAM_END = 1,
    LZMA_NO_CHECK = 2,
    LZMA_UNSUPPORTED_CHECK = 3,
    LZMA_GET_CHECK = 4,
    LZMA_MEM_ERROR = 5,
    LZMA_MEMLIMIT_ERROR = 6,
    LZMA_FORMAT_ERROR = 7,
    LZMA_OPTIONS_ERROR = 8,
    LZMA_DATA_ERROR = 9,
    LZMA_BUF_ERROR = 10,
    LZMA_PROG_ERROR = 11
} ;
typedef enum __anonenum_lzma_ret_557241514 lzma_ret;
enum __anonenum_lzma_action_853458044 {
    LZMA_RUN = 0,
    LZMA_SYNC_FLUSH = 1,
    LZMA_FULL_FLUSH = 2,
    LZMA_FULL_BARRIER = 4,
    LZMA_FINISH = 3
} ;
typedef enum __anonenum_lzma_action_853458044 lzma_action;
struct __anonstruct_lzma_allocator_1021999983 {
   void *(*alloc)(void *opaque , size_t nmemb , size_t size ) ;
   void (*free)(void *opaque , void *ptr ) ;
   void *opaque ;
};
typedef struct __anonstruct_lzma_allocator_1021999983 lzma_allocator;
struct lzma_internal_s ;
typedef struct lzma_internal_s lzma_internal;
struct __anonstruct_lzma_stream_354570162 {
   uint8_t const *next_in ;
   size_t avail_in ;
   uint64_t total_in ;
   uint8_t *next_out ;
   size_t avail_out ;
   uint64_t total_out ;
   lzma_allocator const *allocator ;
   lzma_internal *internal ;
   void *reserved_ptr1 ;
   void *reserved_ptr2 ;
   void *reserved_ptr3 ;
   void *reserved_ptr4 ;
   uint64_t reserved_int1 ;
   uint64_t reserved_int2 ;
   size_t reserved_int3 ;
   size_t reserved_int4 ;
   lzma_reserved_enum reserved_enum1 ;
   lzma_reserved_enum reserved_enum2 ;
};
typedef struct __anonstruct_lzma_stream_354570162 lzma_stream;
typedef uint64_t lzma_vli;
enum __anonenum_lzma_check_844779223 {
    LZMA_CHECK_NONE = 0,
    LZMA_CHECK_CRC32 = 1,
    LZMA_CHECK_CRC64 = 4,
    LZMA_CHECK_SHA256 = 10
} ;
typedef enum __anonenum_lzma_check_844779223 lzma_check;
struct __anonstruct_lzma_filter_138860627 {
   lzma_vli id ;
   void *options ;
};
typedef struct __anonstruct_lzma_filter_138860627 lzma_filter;
struct __anonstruct_lzma_options_bcj_346947711 {
   uint32_t start_offset ;
};
typedef struct __anonstruct_lzma_options_bcj_346947711 lzma_options_bcj;
enum __anonenum_lzma_delta_type_985368280 {
    LZMA_DELTA_TYPE_BYTE = 0
} ;
typedef enum __anonenum_lzma_delta_type_985368280 lzma_delta_type;
struct __anonstruct_lzma_options_delta_446687455 {
   lzma_delta_type type ;
   uint32_t dist ;
   uint32_t reserved_int1 ;
   uint32_t reserved_int2 ;
   uint32_t reserved_int3 ;
   uint32_t reserved_int4 ;
   void *reserved_ptr1 ;
   void *reserved_ptr2 ;
};
typedef struct __anonstruct_lzma_options_delta_446687455 lzma_options_delta;
enum __anonenum_lzma_match_finder_522834504 {
    LZMA_MF_HC3 = 3,
    LZMA_MF_HC4 = 4,
    LZMA_MF_BT2 = 18,
    LZMA_MF_BT3 = 19,
    LZMA_MF_BT4 = 20
} ;
typedef enum __anonenum_lzma_match_finder_522834504 lzma_match_finder;
enum __anonenum_lzma_mode_1033251532 {
    LZMA_MODE_FAST = 1,
    LZMA_MODE_NORMAL = 2
} ;
typedef enum __anonenum_lzma_mode_1033251532 lzma_mode;
struct __anonstruct_lzma_options_lzma_61363977 {
   uint32_t dict_size ;
   uint8_t const *preset_dict ;
   uint32_t preset_dict_size ;
   uint32_t lc ;
   uint32_t lp ;
   uint32_t pb ;
   lzma_mode mode ;
   uint32_t nice_len ;
   lzma_match_finder mf ;
   uint32_t depth ;
   uint32_t reserved_int1 ;
   uint32_t reserved_int2 ;
   uint32_t reserved_int3 ;
   uint32_t reserved_int4 ;
   uint32_t reserved_int5 ;
   uint32_t reserved_int6 ;
   uint32_t reserved_int7 ;
   uint32_t reserved_int8 ;
   lzma_reserved_enum reserved_enum1 ;
   lzma_reserved_enum reserved_enum2 ;
   lzma_reserved_enum reserved_enum3 ;
   lzma_reserved_enum reserved_enum4 ;
   void *reserved_ptr1 ;
   void *reserved_ptr2 ;
};
typedef struct __anonstruct_lzma_options_lzma_61363977 lzma_options_lzma;
struct __anonstruct_lzma_mt_815633320 {
   uint32_t flags ;
   uint32_t threads ;
   uint64_t block_size ;
   uint32_t timeout ;
   uint32_t preset ;
   lzma_filter const *filters ;
   lzma_check check ;
   lzma_reserved_enum reserved_enum1 ;
   lzma_reserved_enum reserved_enum2 ;
   lzma_reserved_enum reserved_enum3 ;
   uint32_t reserved_int1 ;
   uint32_t reserved_int2 ;
   uint32_t reserved_int3 ;
   uint32_t reserved_int4 ;
   uint64_t reserved_int5 ;
   uint64_t reserved_int6 ;
   uint64_t reserved_int7 ;
   uint64_t reserved_int8 ;
   void *reserved_ptr1 ;
   void *reserved_ptr2 ;
   void *reserved_ptr3 ;
   void *reserved_ptr4 ;
};
typedef struct __anonstruct_lzma_mt_815633320 lzma_mt;
struct __anonstruct_lzma_stream_flags_977547716 {
   uint32_t version ;
   lzma_vli backward_size ;
   lzma_check check ;
   lzma_reserved_enum reserved_enum1 ;
   lzma_reserved_enum reserved_enum2 ;
   lzma_reserved_enum reserved_enum3 ;
   lzma_reserved_enum reserved_enum4 ;
   lzma_bool reserved_bool1 ;
   lzma_bool reserved_bool2 ;
   lzma_bool reserved_bool3 ;
   lzma_bool reserved_bool4 ;
   lzma_bool reserved_bool5 ;
   lzma_bool reserved_bool6 ;
   lzma_bool reserved_bool7 ;
   lzma_bool reserved_bool8 ;
   uint32_t reserved_int1 ;
   uint32_t reserved_int2 ;
};
typedef struct __anonstruct_lzma_stream_flags_977547716 lzma_stream_flags;
struct __anonstruct_lzma_block_180122340 {
   uint32_t version ;
   uint32_t header_size ;
   lzma_check check ;
   lzma_vli compressed_size ;
   lzma_vli uncompressed_size ;
   lzma_filter *filters ;
   uint8_t raw_check[64] ;
   void *reserved_ptr1 ;
   void *reserved_ptr2 ;
   void *reserved_ptr3 ;
   uint32_t reserved_int1 ;
   uint32_t reserved_int2 ;
   lzma_vli reserved_int3 ;
   lzma_vli reserved_int4 ;
   lzma_vli reserved_int5 ;
   lzma_vli reserved_int6 ;
   lzma_vli reserved_int7 ;
   lzma_vli reserved_int8 ;
   lzma_reserved_enum reserved_enum1 ;
   lzma_reserved_enum reserved_enum2 ;
   lzma_reserved_enum reserved_enum3 ;
   lzma_reserved_enum reserved_enum4 ;
   lzma_bool ignore_check ;
   lzma_bool reserved_bool2 ;
   lzma_bool reserved_bool3 ;
   lzma_bool reserved_bool4 ;
   lzma_bool reserved_bool5 ;
   lzma_bool reserved_bool6 ;
   lzma_bool reserved_bool7 ;
   lzma_bool reserved_bool8 ;
};
typedef struct __anonstruct_lzma_block_180122340 lzma_block;
struct lzma_index_s ;
typedef struct lzma_index_s lzma_index;
struct __anonstruct_stream_210988227 {
   lzma_stream_flags const *flags ;
   void const *reserved_ptr1 ;
   void const *reserved_ptr2 ;
   void const *reserved_ptr3 ;
   lzma_vli number ;
   lzma_vli block_count ;
   lzma_vli compressed_offset ;
   lzma_vli uncompressed_offset ;
   lzma_vli compressed_size ;
   lzma_vli uncompressed_size ;
   lzma_vli padding ;
   lzma_vli reserved_vli1 ;
   lzma_vli reserved_vli2 ;
   lzma_vli reserved_vli3 ;
   lzma_vli reserved_vli4 ;
};
struct __anonstruct_block_152805203 {
   lzma_vli number_in_file ;
   lzma_vli compressed_file_offset ;
   lzma_vli uncompressed_file_offset ;
   lzma_vli number_in_stream ;
   lzma_vli compressed_stream_offset ;
   lzma_vli uncompressed_stream_offset ;
   lzma_vli uncompressed_size ;
   lzma_vli unpadded_size ;
   lzma_vli total_size ;
   lzma_vli reserved_vli1 ;
   lzma_vli reserved_vli2 ;
   lzma_vli reserved_vli3 ;
   lzma_vli reserved_vli4 ;
   void const *reserved_ptr1 ;
   void const *reserved_ptr2 ;
   void const *reserved_ptr3 ;
   void const *reserved_ptr4 ;
};
union __anonunion_internal_860375268 {
   void const *p ;
   size_t s ;
   lzma_vli v ;
};
struct __anonstruct_lzma_index_iter_609741751 {
   struct __anonstruct_stream_210988227 stream ;
   struct __anonstruct_block_152805203 block ;
   union __anonunion_internal_860375268 internal[6] ;
};
typedef struct __anonstruct_lzma_index_iter_609741751 lzma_index_iter;
enum __anonenum_lzma_index_iter_mode_360774870 {
    LZMA_INDEX_ITER_ANY = 0,
    LZMA_INDEX_ITER_STREAM = 1,
    LZMA_INDEX_ITER_BLOCK = 2,
    LZMA_INDEX_ITER_NONEMPTY_BLOCK = 3
} ;
typedef enum __anonenum_lzma_index_iter_mode_360774870 lzma_index_iter_mode;
struct lzma_index_hash_s ;
typedef struct lzma_index_hash_s lzma_index_hash;
typedef size_t z_size_t;
typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef Byte Bytef;
typedef char charf;
typedef int intf;
typedef uInt uIntf;
typedef uLong uLongf;
typedef void const *voidpc;
typedef void *voidpf;
typedef void *voidp;
typedef unsigned int z_crc_t;
typedef voidpf (*alloc_func)(voidpf opaque , uInt items , uInt size );
typedef void (*free_func)(voidpf opaque , voidpf address );
struct internal_state ;
struct z_stream_s {
   Bytef const *next_in ;
   uInt avail_in ;
   uLong total_in ;
   Bytef *next_out ;
   uInt avail_out ;
   uLong total_out ;
   char const *msg ;
   struct internal_state *state ;
   voidpf (*zalloc)(voidpf opaque , uInt items , uInt size ) ;
   void (*zfree)(voidpf opaque , voidpf address ) ;
   voidpf opaque ;
   int data_type ;
   uLong adler ;
   uLong reserved ;
};
typedef struct z_stream_s z_stream;
typedef z_stream *z_streamp;
struct gz_header_s {
   int text ;
   uLong time ;
   int xflags ;
   int os ;
   Bytef *extra ;
   uInt extra_len ;
   uInt extra_max ;
   Bytef *name ;
   uInt name_max ;
   Bytef *comment ;
   uInt comm_max ;
   int hcrc ;
   int done ;
};
typedef struct gz_header_s gz_header;
typedef gz_header *gz_headerp;
typedef unsigned int (*in_func)(void * , unsigned char const ** );
typedef int (*out_func)(void * , unsigned char * , unsigned int );
struct gzFile_s ;
typedef struct gzFile_s *gzFile;
struct gzFile_s {
   unsigned int have ;
   unsigned char *next ;
   __off64_t pos ;
};
enum __anonenum_18926444___1 {
    _ISupper___1 = 256,
    _ISlower___1 = 512,
    _ISalpha___1 = 1024,
    _ISdigit___1 = 2048,
    _ISxdigit___1 = 4096,
    _ISspace___1 = 8192,
    _ISprint___1 = 16384,
    _ISgraph___1 = 32768,
    _ISblank___1 = 1,
    _IScntrl___1 = 2,
    _ISpunct___1 = 4,
    _ISalnum___1 = 8
} ;
enum __anonenum_437032235___3 {
    _PC_LINK_MAX___3 = 0,
    _PC_MAX_CANON___3 = 1,
    _PC_MAX_INPUT___3 = 2,
    _PC_NAME_MAX___3 = 3,
    _PC_PATH_MAX___3 = 4,
    _PC_PIPE_BUF___3 = 5,
    _PC_CHOWN_RESTRICTED___3 = 6,
    _PC_NO_TRUNC___3 = 7,
    _PC_VDISABLE___3 = 8,
    _PC_SYNC_IO___3 = 9,
    _PC_ASYNC_IO___3 = 10,
    _PC_PRIO_IO___3 = 11,
    _PC_SOCK_MAXBUF___3 = 12,
    _PC_FILESIZEBITS___3 = 13,
    _PC_REC_INCR_XFER_SIZE___3 = 14,
    _PC_REC_MAX_XFER_SIZE___3 = 15,
    _PC_REC_MIN_XFER_SIZE___3 = 16,
    _PC_REC_XFER_ALIGN___3 = 17,
    _PC_ALLOC_SIZE_MIN___3 = 18,
    _PC_SYMLINK_MAX___3 = 19,
    _PC_2_SYMLINKS___3 = 20
} ;
enum __anonenum_315186338___3 {
    _SC_ARG_MAX___3 = 0,
    _SC_CHILD_MAX___3 = 1,
    _SC_CLK_TCK___3 = 2,
    _SC_NGROUPS_MAX___3 = 3,
    _SC_OPEN_MAX___3 = 4,
    _SC_STREAM_MAX___3 = 5,
    _SC_TZNAME_MAX___3 = 6,
    _SC_JOB_CONTROL___3 = 7,
    _SC_SAVED_IDS___3 = 8,
    _SC_REALTIME_SIGNALS___3 = 9,
    _SC_PRIORITY_SCHEDULING___3 = 10,
    _SC_TIMERS___3 = 11,
    _SC_ASYNCHRONOUS_IO___3 = 12,
    _SC_PRIORITIZED_IO___3 = 13,
    _SC_SYNCHRONIZED_IO___3 = 14,
    _SC_FSYNC___3 = 15,
    _SC_MAPPED_FILES___3 = 16,
    _SC_MEMLOCK___3 = 17,
    _SC_MEMLOCK_RANGE___3 = 18,
    _SC_MEMORY_PROTECTION___3 = 19,
    _SC_MESSAGE_PASSING___3 = 20,
    _SC_SEMAPHORES___3 = 21,
    _SC_SHARED_MEMORY_OBJECTS___3 = 22,
    _SC_AIO_LISTIO_MAX___3 = 23,
    _SC_AIO_MAX___3 = 24,
    _SC_AIO_PRIO_DELTA_MAX___3 = 25,
    _SC_DELAYTIMER_MAX___3 = 26,
    _SC_MQ_OPEN_MAX___3 = 27,
    _SC_MQ_PRIO_MAX___3 = 28,
    _SC_VERSION___3 = 29,
    _SC_PAGESIZE___3 = 30,
    _SC_RTSIG_MAX___3 = 31,
    _SC_SEM_NSEMS_MAX___3 = 32,
    _SC_SEM_VALUE_MAX___3 = 33,
    _SC_SIGQUEUE_MAX___3 = 34,
    _SC_TIMER_MAX___3 = 35,
    _SC_BC_BASE_MAX___3 = 36,
    _SC_BC_DIM_MAX___3 = 37,
    _SC_BC_SCALE_MAX___3 = 38,
    _SC_BC_STRING_MAX___3 = 39,
    _SC_COLL_WEIGHTS_MAX___3 = 40,
    _SC_EQUIV_CLASS_MAX___3 = 41,
    _SC_EXPR_NEST_MAX___3 = 42,
    _SC_LINE_MAX___3 = 43,
    _SC_RE_DUP_MAX___3 = 44,
    _SC_CHARCLASS_NAME_MAX___3 = 45,
    _SC_2_VERSION___3 = 46,
    _SC_2_C_BIND___3 = 47,
    _SC_2_C_DEV___3 = 48,
    _SC_2_FORT_DEV___3 = 49,
    _SC_2_FORT_RUN___3 = 50,
    _SC_2_SW_DEV___3 = 51,
    _SC_2_LOCALEDEF___3 = 52,
    _SC_PII___3 = 53,
    _SC_PII_XTI___3 = 54,
    _SC_PII_SOCKET___3 = 55,
    _SC_PII_INTERNET___3 = 56,
    _SC_PII_OSI___3 = 57,
    _SC_POLL___3 = 58,
    _SC_SELECT___3 = 59,
    _SC_UIO_MAXIOV___3 = 60,
    _SC_IOV_MAX___3 = 60,
    _SC_PII_INTERNET_STREAM___3 = 61,
    _SC_PII_INTERNET_DGRAM___3 = 62,
    _SC_PII_OSI_COTS___3 = 63,
    _SC_PII_OSI_CLTS___3 = 64,
    _SC_PII_OSI_M___3 = 65,
    _SC_T_IOV_MAX___3 = 66,
    _SC_THREADS___3 = 67,
    _SC_THREAD_SAFE_FUNCTIONS___3 = 68,
    _SC_GETGR_R_SIZE_MAX___3 = 69,
    _SC_GETPW_R_SIZE_MAX___3 = 70,
    _SC_LOGIN_NAME_MAX___3 = 71,
    _SC_TTY_NAME_MAX___3 = 72,
    _SC_THREAD_DESTRUCTOR_ITERATIONS___3 = 73,
    _SC_THREAD_KEYS_MAX___3 = 74,
    _SC_THREAD_STACK_MIN___3 = 75,
    _SC_THREAD_THREADS_MAX___3 = 76,
    _SC_THREAD_ATTR_STACKADDR___3 = 77,
    _SC_THREAD_ATTR_STACKSIZE___3 = 78,
    _SC_THREAD_PRIORITY_SCHEDULING___3 = 79,
    _SC_THREAD_PRIO_INHERIT___3 = 80,
    _SC_THREAD_PRIO_PROTECT___3 = 81,
    _SC_THREAD_PROCESS_SHARED___3 = 82,
    _SC_NPROCESSORS_CONF___3 = 83,
    _SC_NPROCESSORS_ONLN___3 = 84,
    _SC_PHYS_PAGES___3 = 85,
    _SC_AVPHYS_PAGES___3 = 86,
    _SC_ATEXIT_MAX___3 = 87,
    _SC_PASS_MAX___3 = 88,
    _SC_XOPEN_VERSION___3 = 89,
    _SC_XOPEN_XCU_VERSION___3 = 90,
    _SC_XOPEN_UNIX___3 = 91,
    _SC_XOPEN_CRYPT___3 = 92,
    _SC_XOPEN_ENH_I18N___3 = 93,
    _SC_XOPEN_SHM___3 = 94,
    _SC_2_CHAR_TERM___3 = 95,
    _SC_2_C_VERSION___3 = 96,
    _SC_2_UPE___3 = 97,
    _SC_XOPEN_XPG2___3 = 98,
    _SC_XOPEN_XPG3___3 = 99,
    _SC_XOPEN_XPG4___3 = 100,
    _SC_CHAR_BIT___3 = 101,
    _SC_CHAR_MAX___3 = 102,
    _SC_CHAR_MIN___3 = 103,
    _SC_INT_MAX___3 = 104,
    _SC_INT_MIN___3 = 105,
    _SC_LONG_BIT___3 = 106,
    _SC_WORD_BIT___3 = 107,
    _SC_MB_LEN_MAX___3 = 108,
    _SC_NZERO___3 = 109,
    _SC_SSIZE_MAX___3 = 110,
    _SC_SCHAR_MAX___3 = 111,
    _SC_SCHAR_MIN___3 = 112,
    _SC_SHRT_MAX___3 = 113,
    _SC_SHRT_MIN___3 = 114,
    _SC_UCHAR_MAX___3 = 115,
    _SC_UINT_MAX___3 = 116,
    _SC_ULONG_MAX___3 = 117,
    _SC_USHRT_MAX___3 = 118,
    _SC_NL_ARGMAX___3 = 119,
    _SC_NL_LANGMAX___3 = 120,
    _SC_NL_MSGMAX___3 = 121,
    _SC_NL_NMAX___3 = 122,
    _SC_NL_SETMAX___3 = 123,
    _SC_NL_TEXTMAX___3 = 124,
    _SC_XBS5_ILP32_OFF32___3 = 125,
    _SC_XBS5_ILP32_OFFBIG___3 = 126,
    _SC_XBS5_LP64_OFF64___3 = 127,
    _SC_XBS5_LPBIG_OFFBIG___3 = 128,
    _SC_XOPEN_LEGACY___3 = 129,
    _SC_XOPEN_REALTIME___3 = 130,
    _SC_XOPEN_REALTIME_THREADS___3 = 131,
    _SC_ADVISORY_INFO___3 = 132,
    _SC_BARRIERS___3 = 133,
    _SC_BASE___3 = 134,
    _SC_C_LANG_SUPPORT___3 = 135,
    _SC_C_LANG_SUPPORT_R___3 = 136,
    _SC_CLOCK_SELECTION___3 = 137,
    _SC_CPUTIME___3 = 138,
    _SC_THREAD_CPUTIME___3 = 139,
    _SC_DEVICE_IO___3 = 140,
    _SC_DEVICE_SPECIFIC___3 = 141,
    _SC_DEVICE_SPECIFIC_R___3 = 142,
    _SC_FD_MGMT___3 = 143,
    _SC_FIFO___3 = 144,
    _SC_PIPE___3 = 145,
    _SC_FILE_ATTRIBUTES___3 = 146,
    _SC_FILE_LOCKING___3 = 147,
    _SC_FILE_SYSTEM___3 = 148,
    _SC_MONOTONIC_CLOCK___3 = 149,
    _SC_MULTI_PROCESS___3 = 150,
    _SC_SINGLE_PROCESS___3 = 151,
    _SC_NETWORKING___3 = 152,
    _SC_READER_WRITER_LOCKS___3 = 153,
    _SC_SPIN_LOCKS___3 = 154,
    _SC_REGEXP___3 = 155,
    _SC_REGEX_VERSION___3 = 156,
    _SC_SHELL___3 = 157,
    _SC_SIGNALS___3 = 158,
    _SC_SPAWN___3 = 159,
    _SC_SPORADIC_SERVER___3 = 160,
    _SC_THREAD_SPORADIC_SERVER___3 = 161,
    _SC_SYSTEM_DATABASE___3 = 162,
    _SC_SYSTEM_DATABASE_R___3 = 163,
    _SC_TIMEOUTS___3 = 164,
    _SC_TYPED_MEMORY_OBJECTS___3 = 165,
    _SC_USER_GROUPS___3 = 166,
    _SC_USER_GROUPS_R___3 = 167,
    _SC_2_PBS___3 = 168,
    _SC_2_PBS_ACCOUNTING___3 = 169,
    _SC_2_PBS_LOCATE___3 = 170,
    _SC_2_PBS_MESSAGE___3 = 171,
    _SC_2_PBS_TRACK___3 = 172,
    _SC_SYMLOOP_MAX___3 = 173,
    _SC_STREAMS___3 = 174,
    _SC_2_PBS_CHECKPOINT___3 = 175,
    _SC_V6_ILP32_OFF32___3 = 176,
    _SC_V6_ILP32_OFFBIG___3 = 177,
    _SC_V6_LP64_OFF64___3 = 178,
    _SC_V6_LPBIG_OFFBIG___3 = 179,
    _SC_HOST_NAME_MAX___3 = 180,
    _SC_TRACE___3 = 181,
    _SC_TRACE_EVENT_FILTER___3 = 182,
    _SC_TRACE_INHERIT___3 = 183,
    _SC_TRACE_LOG___3 = 184,
    _SC_LEVEL1_ICACHE_SIZE___3 = 185,
    _SC_LEVEL1_ICACHE_ASSOC___3 = 186,
    _SC_LEVEL1_ICACHE_LINESIZE___3 = 187,
    _SC_LEVEL1_DCACHE_SIZE___3 = 188,
    _SC_LEVEL1_DCACHE_ASSOC___3 = 189,
    _SC_LEVEL1_DCACHE_LINESIZE___3 = 190,
    _SC_LEVEL2_CACHE_SIZE___3 = 191,
    _SC_LEVEL2_CACHE_ASSOC___3 = 192,
    _SC_LEVEL2_CACHE_LINESIZE___3 = 193,
    _SC_LEVEL3_CACHE_SIZE___3 = 194,
    _SC_LEVEL3_CACHE_ASSOC___3 = 195,
    _SC_LEVEL3_CACHE_LINESIZE___3 = 196,
    _SC_LEVEL4_CACHE_SIZE___3 = 197,
    _SC_LEVEL4_CACHE_ASSOC___3 = 198,
    _SC_LEVEL4_CACHE_LINESIZE___3 = 199,
    _SC_IPV6___3 = 235,
    _SC_RAW_SOCKETS___3 = 236,
    _SC_V7_ILP32_OFF32___3 = 237,
    _SC_V7_ILP32_OFFBIG___3 = 238,
    _SC_V7_LP64_OFF64___3 = 239,
    _SC_V7_LPBIG_OFFBIG___3 = 240,
    _SC_SS_REPL_MAX___3 = 241,
    _SC_TRACE_EVENT_NAME_MAX___3 = 242,
    _SC_TRACE_NAME_MAX___3 = 243,
    _SC_TRACE_SYS_MAX___3 = 244,
    _SC_TRACE_USER_EVENT_MAX___3 = 245,
    _SC_XOPEN_STREAMS___3 = 246,
    _SC_THREAD_ROBUST_PRIO_INHERIT___3 = 247,
    _SC_THREAD_ROBUST_PRIO_PROTECT___3 = 248,
    _SC_MINSIGSTKSZ___3 = 249,
    _SC_SIGSTKSZ___3 = 250
} ;
enum __anonenum_875524036___3 {
    _CS_PATH___3 = 0,
    _CS_V6_WIDTH_RESTRICTED_ENVS___3 = 1,
    _CS_GNU_LIBC_VERSION___3 = 2,
    _CS_GNU_LIBPTHREAD_VERSION___3 = 3,
    _CS_V5_WIDTH_RESTRICTED_ENVS___3 = 4,
    _CS_V7_WIDTH_RESTRICTED_ENVS___3 = 5,
    _CS_LFS_CFLAGS___3 = 1000,
    _CS_LFS_LDFLAGS___3 = 1001,
    _CS_LFS_LIBS___3 = 1002,
    _CS_LFS_LINTFLAGS___3 = 1003,
    _CS_LFS64_CFLAGS___3 = 1004,
    _CS_LFS64_LDFLAGS___3 = 1005,
    _CS_LFS64_LIBS___3 = 1006,
    _CS_LFS64_LINTFLAGS___3 = 1007,
    _CS_XBS5_ILP32_OFF32_CFLAGS___3 = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS___3 = 1101,
    _CS_XBS5_ILP32_OFF32_LIBS___3 = 1102,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS___3 = 1103,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS___3 = 1104,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS___3 = 1105,
    _CS_XBS5_ILP32_OFFBIG_LIBS___3 = 1106,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS___3 = 1107,
    _CS_XBS5_LP64_OFF64_CFLAGS___3 = 1108,
    _CS_XBS5_LP64_OFF64_LDFLAGS___3 = 1109,
    _CS_XBS5_LP64_OFF64_LIBS___3 = 1110,
    _CS_XBS5_LP64_OFF64_LINTFLAGS___3 = 1111,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS___3 = 1112,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS___3 = 1113,
    _CS_XBS5_LPBIG_OFFBIG_LIBS___3 = 1114,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS___3 = 1115,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS___3 = 1116,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS___3 = 1117,
    _CS_POSIX_V6_ILP32_OFF32_LIBS___3 = 1118,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS___3 = 1119,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS___3 = 1120,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS___3 = 1121,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS___3 = 1122,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS___3 = 1123,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS___3 = 1124,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS___3 = 1125,
    _CS_POSIX_V6_LP64_OFF64_LIBS___3 = 1126,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS___3 = 1127,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS___3 = 1128,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS___3 = 1129,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS___3 = 1130,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS___3 = 1131,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS___3 = 1132,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS___3 = 1133,
    _CS_POSIX_V7_ILP32_OFF32_LIBS___3 = 1134,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS___3 = 1135,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS___3 = 1136,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS___3 = 1137,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS___3 = 1138,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS___3 = 1139,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS___3 = 1140,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS___3 = 1141,
    _CS_POSIX_V7_LP64_OFF64_LIBS___3 = 1142,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS___3 = 1143,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS___3 = 1144,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS___3 = 1145,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS___3 = 1146,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS___3 = 1147,
    _CS_V6_ENV___3 = 1148,
    _CS_V7_ENV___3 = 1149
} ;
enum __anonenum_34415463___9 {
    PTHREAD_CREATE_JOINABLE___9 = 0,
    PTHREAD_CREATE_DETACHED___9 = 1
} ;
enum __anonenum_303612439___8 {
    PTHREAD_MUTEX_TIMED_NP___9 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___9 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___9 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___9 = 3,
    PTHREAD_MUTEX_NORMAL___9 = 0,
    PTHREAD_MUTEX_RECURSIVE___9 = 1,
    PTHREAD_MUTEX_ERRORCHECK___9 = 2,
    PTHREAD_MUTEX_DEFAULT___9 = 0,
    PTHREAD_MUTEX_FAST_NP___8 = 0
} ;
enum __anonenum_931900394___9 {
    PTHREAD_MUTEX_STALLED___9 = 0,
    PTHREAD_MUTEX_STALLED_NP___9 = 0,
    PTHREAD_MUTEX_ROBUST___9 = 1,
    PTHREAD_MUTEX_ROBUST_NP___9 = 1
} ;
enum __anonenum_205214487___9 {
    PTHREAD_PRIO_NONE___9 = 0,
    PTHREAD_PRIO_INHERIT___9 = 1,
    PTHREAD_PRIO_PROTECT___9 = 2
} ;
enum __anonenum_25043950___9 {
    PTHREAD_RWLOCK_PREFER_READER_NP___9 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___9 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___9 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___9 = 0
} ;
enum __anonenum_436439511___9 {
    PTHREAD_INHERIT_SCHED___9 = 0,
    PTHREAD_EXPLICIT_SCHED___9 = 1
} ;
enum __anonenum_998661166___9 {
    PTHREAD_SCOPE_SYSTEM___9 = 0,
    PTHREAD_SCOPE_PROCESS___9 = 1
} ;
enum __anonenum_146137331___9 {
    PTHREAD_PROCESS_PRIVATE___9 = 0,
    PTHREAD_PROCESS_SHARED___9 = 1
} ;
enum __anonenum_53396917___9 {
    PTHREAD_CANCEL_ENABLE___9 = 0,
    PTHREAD_CANCEL_DISABLE___9 = 1
} ;
enum __anonenum_904563783___9 {
    PTHREAD_CANCEL_DEFERRED___9 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___9 = 1
} ;
enum __anonenum_513775621___7 {
    DT_UNKNOWN___7 = 0,
    DT_FIFO___7 = 1,
    DT_CHR___7 = 2,
    DT_DIR___7 = 4,
    DT_BLK___7 = 6,
    DT_REG___7 = 8,
    DT_LNK___7 = 10,
    DT_SOCK___7 = 12,
    DT_WHT___7 = 14
} ;
struct __anonstruct_worker_t_846662689 {
   pthread_t thread ;
   int id ;
};
typedef struct __anonstruct_worker_t_846662689 worker_t;
enum __anonenum_437032235___4 {
    _PC_LINK_MAX___4 = 0,
    _PC_MAX_CANON___4 = 1,
    _PC_MAX_INPUT___4 = 2,
    _PC_NAME_MAX___4 = 3,
    _PC_PATH_MAX___4 = 4,
    _PC_PIPE_BUF___4 = 5,
    _PC_CHOWN_RESTRICTED___4 = 6,
    _PC_NO_TRUNC___4 = 7,
    _PC_VDISABLE___4 = 8,
    _PC_SYNC_IO___4 = 9,
    _PC_ASYNC_IO___4 = 10,
    _PC_PRIO_IO___4 = 11,
    _PC_SOCK_MAXBUF___4 = 12,
    _PC_FILESIZEBITS___4 = 13,
    _PC_REC_INCR_XFER_SIZE___4 = 14,
    _PC_REC_MAX_XFER_SIZE___4 = 15,
    _PC_REC_MIN_XFER_SIZE___4 = 16,
    _PC_REC_XFER_ALIGN___4 = 17,
    _PC_ALLOC_SIZE_MIN___4 = 18,
    _PC_SYMLINK_MAX___4 = 19,
    _PC_2_SYMLINKS___4 = 20
} ;
enum __anonenum_315186338___4 {
    _SC_ARG_MAX___4 = 0,
    _SC_CHILD_MAX___4 = 1,
    _SC_CLK_TCK___4 = 2,
    _SC_NGROUPS_MAX___4 = 3,
    _SC_OPEN_MAX___4 = 4,
    _SC_STREAM_MAX___4 = 5,
    _SC_TZNAME_MAX___4 = 6,
    _SC_JOB_CONTROL___4 = 7,
    _SC_SAVED_IDS___4 = 8,
    _SC_REALTIME_SIGNALS___4 = 9,
    _SC_PRIORITY_SCHEDULING___4 = 10,
    _SC_TIMERS___4 = 11,
    _SC_ASYNCHRONOUS_IO___4 = 12,
    _SC_PRIORITIZED_IO___4 = 13,
    _SC_SYNCHRONIZED_IO___4 = 14,
    _SC_FSYNC___4 = 15,
    _SC_MAPPED_FILES___4 = 16,
    _SC_MEMLOCK___4 = 17,
    _SC_MEMLOCK_RANGE___4 = 18,
    _SC_MEMORY_PROTECTION___4 = 19,
    _SC_MESSAGE_PASSING___4 = 20,
    _SC_SEMAPHORES___4 = 21,
    _SC_SHARED_MEMORY_OBJECTS___4 = 22,
    _SC_AIO_LISTIO_MAX___4 = 23,
    _SC_AIO_MAX___4 = 24,
    _SC_AIO_PRIO_DELTA_MAX___4 = 25,
    _SC_DELAYTIMER_MAX___4 = 26,
    _SC_MQ_OPEN_MAX___4 = 27,
    _SC_MQ_PRIO_MAX___4 = 28,
    _SC_VERSION___4 = 29,
    _SC_PAGESIZE___4 = 30,
    _SC_RTSIG_MAX___4 = 31,
    _SC_SEM_NSEMS_MAX___4 = 32,
    _SC_SEM_VALUE_MAX___4 = 33,
    _SC_SIGQUEUE_MAX___4 = 34,
    _SC_TIMER_MAX___4 = 35,
    _SC_BC_BASE_MAX___4 = 36,
    _SC_BC_DIM_MAX___4 = 37,
    _SC_BC_SCALE_MAX___4 = 38,
    _SC_BC_STRING_MAX___4 = 39,
    _SC_COLL_WEIGHTS_MAX___4 = 40,
    _SC_EQUIV_CLASS_MAX___4 = 41,
    _SC_EXPR_NEST_MAX___4 = 42,
    _SC_LINE_MAX___4 = 43,
    _SC_RE_DUP_MAX___4 = 44,
    _SC_CHARCLASS_NAME_MAX___4 = 45,
    _SC_2_VERSION___4 = 46,
    _SC_2_C_BIND___4 = 47,
    _SC_2_C_DEV___4 = 48,
    _SC_2_FORT_DEV___4 = 49,
    _SC_2_FORT_RUN___4 = 50,
    _SC_2_SW_DEV___4 = 51,
    _SC_2_LOCALEDEF___4 = 52,
    _SC_PII___4 = 53,
    _SC_PII_XTI___4 = 54,
    _SC_PII_SOCKET___4 = 55,
    _SC_PII_INTERNET___4 = 56,
    _SC_PII_OSI___4 = 57,
    _SC_POLL___4 = 58,
    _SC_SELECT___4 = 59,
    _SC_UIO_MAXIOV___4 = 60,
    _SC_IOV_MAX___4 = 60,
    _SC_PII_INTERNET_STREAM___4 = 61,
    _SC_PII_INTERNET_DGRAM___4 = 62,
    _SC_PII_OSI_COTS___4 = 63,
    _SC_PII_OSI_CLTS___4 = 64,
    _SC_PII_OSI_M___4 = 65,
    _SC_T_IOV_MAX___4 = 66,
    _SC_THREADS___4 = 67,
    _SC_THREAD_SAFE_FUNCTIONS___4 = 68,
    _SC_GETGR_R_SIZE_MAX___4 = 69,
    _SC_GETPW_R_SIZE_MAX___4 = 70,
    _SC_LOGIN_NAME_MAX___4 = 71,
    _SC_TTY_NAME_MAX___4 = 72,
    _SC_THREAD_DESTRUCTOR_ITERATIONS___4 = 73,
    _SC_THREAD_KEYS_MAX___4 = 74,
    _SC_THREAD_STACK_MIN___4 = 75,
    _SC_THREAD_THREADS_MAX___4 = 76,
    _SC_THREAD_ATTR_STACKADDR___4 = 77,
    _SC_THREAD_ATTR_STACKSIZE___4 = 78,
    _SC_THREAD_PRIORITY_SCHEDULING___4 = 79,
    _SC_THREAD_PRIO_INHERIT___4 = 80,
    _SC_THREAD_PRIO_PROTECT___4 = 81,
    _SC_THREAD_PROCESS_SHARED___4 = 82,
    _SC_NPROCESSORS_CONF___4 = 83,
    _SC_NPROCESSORS_ONLN___4 = 84,
    _SC_PHYS_PAGES___4 = 85,
    _SC_AVPHYS_PAGES___4 = 86,
    _SC_ATEXIT_MAX___4 = 87,
    _SC_PASS_MAX___4 = 88,
    _SC_XOPEN_VERSION___4 = 89,
    _SC_XOPEN_XCU_VERSION___4 = 90,
    _SC_XOPEN_UNIX___4 = 91,
    _SC_XOPEN_CRYPT___4 = 92,
    _SC_XOPEN_ENH_I18N___4 = 93,
    _SC_XOPEN_SHM___4 = 94,
    _SC_2_CHAR_TERM___4 = 95,
    _SC_2_C_VERSION___4 = 96,
    _SC_2_UPE___4 = 97,
    _SC_XOPEN_XPG2___4 = 98,
    _SC_XOPEN_XPG3___4 = 99,
    _SC_XOPEN_XPG4___4 = 100,
    _SC_CHAR_BIT___4 = 101,
    _SC_CHAR_MAX___4 = 102,
    _SC_CHAR_MIN___4 = 103,
    _SC_INT_MAX___4 = 104,
    _SC_INT_MIN___4 = 105,
    _SC_LONG_BIT___4 = 106,
    _SC_WORD_BIT___4 = 107,
    _SC_MB_LEN_MAX___4 = 108,
    _SC_NZERO___4 = 109,
    _SC_SSIZE_MAX___4 = 110,
    _SC_SCHAR_MAX___4 = 111,
    _SC_SCHAR_MIN___4 = 112,
    _SC_SHRT_MAX___4 = 113,
    _SC_SHRT_MIN___4 = 114,
    _SC_UCHAR_MAX___4 = 115,
    _SC_UINT_MAX___4 = 116,
    _SC_ULONG_MAX___4 = 117,
    _SC_USHRT_MAX___4 = 118,
    _SC_NL_ARGMAX___4 = 119,
    _SC_NL_LANGMAX___4 = 120,
    _SC_NL_MSGMAX___4 = 121,
    _SC_NL_NMAX___4 = 122,
    _SC_NL_SETMAX___4 = 123,
    _SC_NL_TEXTMAX___4 = 124,
    _SC_XBS5_ILP32_OFF32___4 = 125,
    _SC_XBS5_ILP32_OFFBIG___4 = 126,
    _SC_XBS5_LP64_OFF64___4 = 127,
    _SC_XBS5_LPBIG_OFFBIG___4 = 128,
    _SC_XOPEN_LEGACY___4 = 129,
    _SC_XOPEN_REALTIME___4 = 130,
    _SC_XOPEN_REALTIME_THREADS___4 = 131,
    _SC_ADVISORY_INFO___4 = 132,
    _SC_BARRIERS___4 = 133,
    _SC_BASE___4 = 134,
    _SC_C_LANG_SUPPORT___4 = 135,
    _SC_C_LANG_SUPPORT_R___4 = 136,
    _SC_CLOCK_SELECTION___4 = 137,
    _SC_CPUTIME___4 = 138,
    _SC_THREAD_CPUTIME___4 = 139,
    _SC_DEVICE_IO___4 = 140,
    _SC_DEVICE_SPECIFIC___4 = 141,
    _SC_DEVICE_SPECIFIC_R___4 = 142,
    _SC_FD_MGMT___4 = 143,
    _SC_FIFO___4 = 144,
    _SC_PIPE___4 = 145,
    _SC_FILE_ATTRIBUTES___4 = 146,
    _SC_FILE_LOCKING___4 = 147,
    _SC_FILE_SYSTEM___4 = 148,
    _SC_MONOTONIC_CLOCK___4 = 149,
    _SC_MULTI_PROCESS___4 = 150,
    _SC_SINGLE_PROCESS___4 = 151,
    _SC_NETWORKING___4 = 152,
    _SC_READER_WRITER_LOCKS___4 = 153,
    _SC_SPIN_LOCKS___4 = 154,
    _SC_REGEXP___4 = 155,
    _SC_REGEX_VERSION___4 = 156,
    _SC_SHELL___4 = 157,
    _SC_SIGNALS___4 = 158,
    _SC_SPAWN___4 = 159,
    _SC_SPORADIC_SERVER___4 = 160,
    _SC_THREAD_SPORADIC_SERVER___4 = 161,
    _SC_SYSTEM_DATABASE___4 = 162,
    _SC_SYSTEM_DATABASE_R___4 = 163,
    _SC_TIMEOUTS___4 = 164,
    _SC_TYPED_MEMORY_OBJECTS___4 = 165,
    _SC_USER_GROUPS___4 = 166,
    _SC_USER_GROUPS_R___4 = 167,
    _SC_2_PBS___4 = 168,
    _SC_2_PBS_ACCOUNTING___4 = 169,
    _SC_2_PBS_LOCATE___4 = 170,
    _SC_2_PBS_MESSAGE___4 = 171,
    _SC_2_PBS_TRACK___4 = 172,
    _SC_SYMLOOP_MAX___4 = 173,
    _SC_STREAMS___4 = 174,
    _SC_2_PBS_CHECKPOINT___4 = 175,
    _SC_V6_ILP32_OFF32___4 = 176,
    _SC_V6_ILP32_OFFBIG___4 = 177,
    _SC_V6_LP64_OFF64___4 = 178,
    _SC_V6_LPBIG_OFFBIG___4 = 179,
    _SC_HOST_NAME_MAX___4 = 180,
    _SC_TRACE___4 = 181,
    _SC_TRACE_EVENT_FILTER___4 = 182,
    _SC_TRACE_INHERIT___4 = 183,
    _SC_TRACE_LOG___4 = 184,
    _SC_LEVEL1_ICACHE_SIZE___4 = 185,
    _SC_LEVEL1_ICACHE_ASSOC___4 = 186,
    _SC_LEVEL1_ICACHE_LINESIZE___4 = 187,
    _SC_LEVEL1_DCACHE_SIZE___4 = 188,
    _SC_LEVEL1_DCACHE_ASSOC___4 = 189,
    _SC_LEVEL1_DCACHE_LINESIZE___4 = 190,
    _SC_LEVEL2_CACHE_SIZE___4 = 191,
    _SC_LEVEL2_CACHE_ASSOC___4 = 192,
    _SC_LEVEL2_CACHE_LINESIZE___4 = 193,
    _SC_LEVEL3_CACHE_SIZE___4 = 194,
    _SC_LEVEL3_CACHE_ASSOC___4 = 195,
    _SC_LEVEL3_CACHE_LINESIZE___4 = 196,
    _SC_LEVEL4_CACHE_SIZE___4 = 197,
    _SC_LEVEL4_CACHE_ASSOC___4 = 198,
    _SC_LEVEL4_CACHE_LINESIZE___4 = 199,
    _SC_IPV6___4 = 235,
    _SC_RAW_SOCKETS___4 = 236,
    _SC_V7_ILP32_OFF32___4 = 237,
    _SC_V7_ILP32_OFFBIG___4 = 238,
    _SC_V7_LP64_OFF64___4 = 239,
    _SC_V7_LPBIG_OFFBIG___4 = 240,
    _SC_SS_REPL_MAX___4 = 241,
    _SC_TRACE_EVENT_NAME_MAX___4 = 242,
    _SC_TRACE_NAME_MAX___4 = 243,
    _SC_TRACE_SYS_MAX___4 = 244,
    _SC_TRACE_USER_EVENT_MAX___4 = 245,
    _SC_XOPEN_STREAMS___4 = 246,
    _SC_THREAD_ROBUST_PRIO_INHERIT___4 = 247,
    _SC_THREAD_ROBUST_PRIO_PROTECT___4 = 248,
    _SC_MINSIGSTKSZ___4 = 249,
    _SC_SIGSTKSZ___4 = 250
} ;
enum __anonenum_875524036___4 {
    _CS_PATH___4 = 0,
    _CS_V6_WIDTH_RESTRICTED_ENVS___4 = 1,
    _CS_GNU_LIBC_VERSION___4 = 2,
    _CS_GNU_LIBPTHREAD_VERSION___4 = 3,
    _CS_V5_WIDTH_RESTRICTED_ENVS___4 = 4,
    _CS_V7_WIDTH_RESTRICTED_ENVS___4 = 5,
    _CS_LFS_CFLAGS___4 = 1000,
    _CS_LFS_LDFLAGS___4 = 1001,
    _CS_LFS_LIBS___4 = 1002,
    _CS_LFS_LINTFLAGS___4 = 1003,
    _CS_LFS64_CFLAGS___4 = 1004,
    _CS_LFS64_LDFLAGS___4 = 1005,
    _CS_LFS64_LIBS___4 = 1006,
    _CS_LFS64_LINTFLAGS___4 = 1007,
    _CS_XBS5_ILP32_OFF32_CFLAGS___4 = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS___4 = 1101,
    _CS_XBS5_ILP32_OFF32_LIBS___4 = 1102,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS___4 = 1103,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS___4 = 1104,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS___4 = 1105,
    _CS_XBS5_ILP32_OFFBIG_LIBS___4 = 1106,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS___4 = 1107,
    _CS_XBS5_LP64_OFF64_CFLAGS___4 = 1108,
    _CS_XBS5_LP64_OFF64_LDFLAGS___4 = 1109,
    _CS_XBS5_LP64_OFF64_LIBS___4 = 1110,
    _CS_XBS5_LP64_OFF64_LINTFLAGS___4 = 1111,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS___4 = 1112,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS___4 = 1113,
    _CS_XBS5_LPBIG_OFFBIG_LIBS___4 = 1114,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS___4 = 1115,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS___4 = 1116,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS___4 = 1117,
    _CS_POSIX_V6_ILP32_OFF32_LIBS___4 = 1118,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS___4 = 1119,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS___4 = 1120,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS___4 = 1121,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS___4 = 1122,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS___4 = 1123,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS___4 = 1124,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS___4 = 1125,
    _CS_POSIX_V6_LP64_OFF64_LIBS___4 = 1126,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS___4 = 1127,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS___4 = 1128,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS___4 = 1129,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS___4 = 1130,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS___4 = 1131,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS___4 = 1132,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS___4 = 1133,
    _CS_POSIX_V7_ILP32_OFF32_LIBS___4 = 1134,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS___4 = 1135,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS___4 = 1136,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS___4 = 1137,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS___4 = 1138,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS___4 = 1139,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS___4 = 1140,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS___4 = 1141,
    _CS_POSIX_V7_LP64_OFF64_LIBS___4 = 1142,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS___4 = 1143,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS___4 = 1144,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS___4 = 1145,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS___4 = 1146,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS___4 = 1147,
    _CS_V6_ENV___4 = 1148,
    _CS_V7_ENV___4 = 1149
} ;
struct z_stream_s___0 {
   Bytef *next_in ;
   uInt avail_in ;
   uLong total_in ;
   Bytef *next_out ;
   uInt avail_out ;
   uLong total_out ;
   char *msg ;
   struct internal_state *state ;
   voidpf (*zalloc)(voidpf opaque , uInt items , uInt size ) ;
   void (*zfree)(voidpf opaque , voidpf address ) ;
   voidpf opaque ;
   int data_type ;
   uLong adler ;
   uLong reserved ;
};
typedef struct z_stream_s___0 z_stream___0;
typedef z_stream___0 *z_streamp___0;
typedef unsigned int (*in_func___0)(void * , unsigned char ** );
enum __anonenum_34415463___10 {
    PTHREAD_CREATE_JOINABLE___10 = 0,
    PTHREAD_CREATE_DETACHED___10 = 1
} ;
enum __anonenum_303612439___9 {
    PTHREAD_MUTEX_TIMED_NP___10 = 0,
    PTHREAD_MUTEX_RECURSIVE_NP___10 = 1,
    PTHREAD_MUTEX_ERRORCHECK_NP___10 = 2,
    PTHREAD_MUTEX_ADAPTIVE_NP___10 = 3,
    PTHREAD_MUTEX_NORMAL___10 = 0,
    PTHREAD_MUTEX_RECURSIVE___10 = 1,
    PTHREAD_MUTEX_ERRORCHECK___10 = 2,
    PTHREAD_MUTEX_DEFAULT___10 = 0,
    PTHREAD_MUTEX_FAST_NP___9 = 0
} ;
enum __anonenum_931900394___10 {
    PTHREAD_MUTEX_STALLED___10 = 0,
    PTHREAD_MUTEX_STALLED_NP___10 = 0,
    PTHREAD_MUTEX_ROBUST___10 = 1,
    PTHREAD_MUTEX_ROBUST_NP___10 = 1
} ;
enum __anonenum_205214487___10 {
    PTHREAD_PRIO_NONE___10 = 0,
    PTHREAD_PRIO_INHERIT___10 = 1,
    PTHREAD_PRIO_PROTECT___10 = 2
} ;
enum __anonenum_25043950___10 {
    PTHREAD_RWLOCK_PREFER_READER_NP___10 = 0,
    PTHREAD_RWLOCK_PREFER_WRITER_NP___10 = 1,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP___10 = 2,
    PTHREAD_RWLOCK_DEFAULT_NP___10 = 0
} ;
enum __anonenum_436439511___10 {
    PTHREAD_INHERIT_SCHED___10 = 0,
    PTHREAD_EXPLICIT_SCHED___10 = 1
} ;
enum __anonenum_998661166___10 {
    PTHREAD_SCOPE_SYSTEM___10 = 0,
    PTHREAD_SCOPE_PROCESS___10 = 1
} ;
enum __anonenum_146137331___10 {
    PTHREAD_PROCESS_PRIVATE___10 = 0,
    PTHREAD_PROCESS_SHARED___10 = 1
} ;
enum __anonenum_53396917___10 {
    PTHREAD_CANCEL_ENABLE___10 = 0,
    PTHREAD_CANCEL_DISABLE___10 = 1
} ;
enum __anonenum_904563783___10 {
    PTHREAD_CANCEL_DEFERRED___10 = 0,
    PTHREAD_CANCEL_ASYNCHRONOUS___10 = 1
} ;
union __anonunion_stream_340362379 {
   z_stream___0 gz ;
   lzma_stream lzma ;
};
struct zfile {
   FILE *in ;
   uint64_t logic_offset ;
   uint64_t decode_offset ;
   uint64_t actual_len ;
   uint32_t outbuf_start ;
   ag_compression_type ctype ;
   union __anonunion_stream_340362379 stream ;
   uint8_t inbuf[32768] ;
   uint8_t outbuf[262144] ;
   _Bool eof ;
};
void ( __attribute__((__nonnull__(1,4))) qsort)(void *ptr , size_t count , size_t size ,
                                                int (*comp)(void const * , void const * ) ) __attribute__((__goblint_stub__)) ;
void ( __attribute__((__nonnull__(1,4))) qsort)(void *ptr , size_t count , size_t size ,
                                                int (*comp)(void const * , void const * ) ) __attribute__((__goblint_stub__)) ;
void ( __attribute__((__nonnull__(1,4))) qsort)(void *ptr , size_t count , size_t size ,
                                                int (*comp)(void const * , void const * ) )
{
  size_t i ;
  size_t j ;
  size_t i___0 ;
  size_t j___0 ;
  int r ;
  size_t k ;
  char *a ;
  char *b ;
  char c ;
  {
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < count)) {
      goto while_break;
    }
    j = (size_t )0;
    {
    while (1) {
      while_continue___0: ;
      if (! (j < count)) {
        goto while_break___0;
      }
      (*comp)((void const *)(ptr + i * size), (void const *)(ptr + j * size));
      j ++;
    }
    while_break___0: ;
    }
    i ++;
  }
  while_break: ;
  }
  i___0 = (size_t )0;
  {
  while (1) {
    while_continue___1: ;
    if (! (i___0 < count)) {
      goto while_break___1;
    }
    j___0 = (size_t )0;
    {
    while (1) {
      while_continue___2: ;
      if (! (j___0 < count)) {
        goto while_break___2;
      }
      if (r) {
        k = (size_t )0;
        {
        while (1) {
          while_continue___3: ;
          if (! (k < size)) {
            goto while_break___3;
          }
          a = (char *)((ptr + i___0 * size) + k);
          b = (char *)((ptr + j___0 * size) + k);
          c = *a;
          *a = *b;
          *b = c;
          k ++;
        }
        while_break___3: ;
        }
      }
      j___0 ++;
    }
    while_break___2: ;
    }
    i___0 ++;
  }
  while_break___1: ;
  }
  return;
}
}
void *( __attribute__((__warn_unused_result__, __nonnull__(1,2,5))) bsearch)(void const *key ,
                                                                             void const *ptr ,
                                                                             size_t count ,
                                                                             size_t size ,
                                                                             int (*comp)(void const * ,
                                                                                         void const * ) ) __attribute__((__goblint_stub__)) ;
void *( __attribute__((__warn_unused_result__, __nonnull__(1,2,5))) bsearch)(void const *key ,
                                                                             void const *ptr ,
                                                                             size_t count ,
                                                                             size_t size ,
                                                                             int (*comp)(void const * ,
                                                                                         void const * ) ) __attribute__((__goblint_stub__)) ;
void *( __attribute__((__warn_unused_result__, __nonnull__(1,2,5))) bsearch)(void const *key ,
                                                                             void const *ptr ,
                                                                             size_t count ,
                                                                             size_t size ,
                                                                             int (*comp)(void const * ,
                                                                                         void const * ) )
{
  size_t i ;
  void const *a ;
  int tmp ;
  {
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < count)) {
      goto while_break;
    }
    a = ptr + i * size;
    tmp = (*comp)(key, a);
    if (tmp == 0) {
      return ((void *)a);
    }
    i ++;
  }
  while_break: ;
  }
  return ((void *)0);
}
}
extern int ( __attribute__((__leaf__)) __sched_cpucount)(size_t __setsize , cpu_set_t const *__setp ) __attribute__((__nothrow__)) ;
extern cpu_set_t *( __attribute__((__warn_unused_result__, __leaf__)) __sched_cpualloc)(size_t __count ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) __sched_cpufree)(cpu_set_t *__set ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_setparam)(__pid_t __pid , struct sched_param const *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_getparam)(__pid_t __pid , struct sched_param *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_setscheduler)(__pid_t __pid , int __policy ,
                                                           struct sched_param const *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_getscheduler)(__pid_t __pid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_yield)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_get_priority_max)(int __algorithm ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_get_priority_min)(int __algorithm ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_rr_get_interval)(__pid_t __pid , struct timespec *__t ) __attribute__((__nothrow__)) ;
extern clock_t ( __attribute__((__leaf__)) clock)(void) __attribute__((__nothrow__)) ;
extern time_t ( __attribute__((__leaf__)) time)(time_t *__timer ) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__leaf__)) difftime)(time_t __time1 , time_t __time0 ) __attribute__((__nothrow__,
__const__)) ;
extern time_t ( __attribute__((__leaf__)) mktime)(struct tm *__tp ) __attribute__((__nothrow__)) ;
extern size_t ( __attribute__((__leaf__)) strftime)(char *__s , size_t __maxsize ,
                                                    char const *__format , struct tm const *__tp ) __attribute__((__nothrow__)) ;
extern size_t ( __attribute__((__leaf__)) strftime_l)(char *__s , size_t __maxsize ,
                                                      char const *__format , struct tm const *__tp ,
                                                      locale_t __loc ) __attribute__((__nothrow__)) ;
extern struct tm *( __attribute__((__leaf__)) gmtime)(time_t const *__timer ) __attribute__((__nothrow__)) ;
extern struct tm *( __attribute__((__leaf__)) localtime)(time_t const *__timer ) __attribute__((__nothrow__)) ;
extern struct tm *( __attribute__((__leaf__)) gmtime_r)(time_t const *__timer ,
                                                        struct tm *__tp ) __attribute__((__nothrow__)) ;
extern struct tm *( __attribute__((__leaf__)) localtime_r)(time_t const *__timer ,
                                                           struct tm *__tp ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) asctime)(struct tm const *__tp ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) ctime)(time_t const *__timer ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) asctime_r)(struct tm const *__tp , char *__buf ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) ctime_r)(time_t const *__timer , char *__buf ) __attribute__((__nothrow__)) ;
extern char *__tzname[2] ;
extern int __daylight ;
extern long __timezone ;
extern char *tzname[2] ;
extern void ( __attribute__((__leaf__)) tzset)(void) __attribute__((__nothrow__)) ;
extern int daylight ;
extern long timezone ;
extern time_t ( __attribute__((__leaf__)) timegm)(struct tm *__tp ) __attribute__((__nothrow__)) ;
extern time_t ( __attribute__((__leaf__)) timelocal)(struct tm *__tp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) dysize)(int __year ) __attribute__((__nothrow__,
__const__)) ;
extern int nanosleep(struct timespec const *__requested_time , struct timespec *__remaining ) ;
extern int ( __attribute__((__leaf__)) clock_getres)(clockid_t __clock_id , struct timespec *__res ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) clock_gettime)(clockid_t __clock_id , struct timespec *__tp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) clock_settime)(clockid_t __clock_id , struct timespec const *__tp ) __attribute__((__nothrow__)) ;
extern int clock_nanosleep(clockid_t __clock_id , int __flags , struct timespec const *__req ,
                           struct timespec *__rem ) ;
extern int ( __attribute__((__leaf__)) clock_getcpuclockid)(pid_t __pid , clockid_t *__clock_id ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) timer_create)(clockid_t __clock_id , struct sigevent *__evp ,
                                                     timer_t *__timerid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) timer_delete)(timer_t __timerid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) timer_settime)(timer_t __timerid , int __flags ,
                                                      struct itimerspec const *__value ,
                                                      struct itimerspec *__ovalue ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) timer_gettime)(timer_t __timerid , struct itimerspec *__value ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) timer_getoverrun)(timer_t __timerid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) timespec_get)(struct timespec *__ts ,
                                                                     int __base ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,3))) pthread_create)(pthread_t *__newthread ,
                                                               pthread_attr_t const *__attr ,
                                                               void *(*__start_routine)(void * ) ,
                                                               void *__arg ) __attribute__((__nothrow__)) ;
extern void pthread_exit(void *__retval ) __attribute__((__noreturn__)) ;
extern int pthread_join(pthread_t __th , void **__thread_return ) ;
extern int ( __attribute__((__leaf__)) pthread_detach)(pthread_t __th ) __attribute__((__nothrow__)) ;
extern pthread_t ( __attribute__((__leaf__)) pthread_self)(void) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__leaf__)) pthread_equal)(pthread_t __thread1 , pthread_t __thread2 ) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_init)(pthread_attr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_destroy)(pthread_attr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getdetachstate)(pthread_attr_t const *__attr ,
                                                                                      int *__detachstate ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setdetachstate)(pthread_attr_t *__attr ,
                                                                                    int __detachstate ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getguardsize)(pthread_attr_t const *__attr ,
                                                                                    size_t *__guardsize ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setguardsize)(pthread_attr_t *__attr ,
                                                                                  size_t __guardsize ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getschedparam)(pthread_attr_t const *__attr ,
                                                                                     struct sched_param *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_setschedparam)(pthread_attr_t *__attr ,
                                                                                     struct sched_param const *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getschedpolicy)(pthread_attr_t const *__attr ,
                                                                                      int *__policy ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setschedpolicy)(pthread_attr_t *__attr ,
                                                                                    int __policy ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getinheritsched)(pthread_attr_t const *__attr ,
                                                                                       int *__inherit ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setinheritsched)(pthread_attr_t *__attr ,
                                                                                     int __inherit ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getscope)(pthread_attr_t const *__attr ,
                                                                                int *__scope ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setscope)(pthread_attr_t *__attr ,
                                                                              int __scope ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getstackaddr)(pthread_attr_t const *__attr ,
                                                                                    void **__stackaddr ) __attribute__((__nothrow__,
__deprecated__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setstackaddr)(pthread_attr_t *__attr ,
                                                                                  void *__stackaddr ) __attribute__((__nothrow__,
__deprecated__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_attr_getstacksize)(pthread_attr_t const *__attr ,
                                                                                    size_t *__stacksize ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setstacksize)(pthread_attr_t *__attr ,
                                                                                  size_t __stacksize ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2,3), __leaf__)) pthread_attr_getstack)(pthread_attr_t const *__attr ,
                                                                                  void **__stackaddr ,
                                                                                  size_t *__stacksize ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_attr_setstack)(pthread_attr_t *__attr ,
                                                                              void *__stackaddr ,
                                                                              size_t __stacksize ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) pthread_setschedparam)(pthread_t __target_thread ,
                                                                              int __policy ,
                                                                              struct sched_param const *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,3), __leaf__)) pthread_getschedparam)(pthread_t __target_thread ,
                                                                                int *__policy ,
                                                                                struct sched_param *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_setschedprio)(pthread_t __target_thread ,
                                                             int __prio ) __attribute__((__nothrow__)) ;
int ( __attribute__((__nonnull__(1,2))) pthread_once)(pthread_once_t *once_control ,
                                                      void (*init_routine)(void) ) __attribute__((__goblint_stub__)) ;
extern int pthread_setcancelstate(int __state , int *__oldstate ) ;
extern int pthread_setcanceltype(int __type , int *__oldtype ) ;
extern int pthread_cancel(pthread_t __th ) ;
extern void pthread_testcancel(void) ;
extern void __pthread_register_cancel(__pthread_unwind_buf_t *__buf ) ;
extern void __pthread_unregister_cancel(__pthread_unwind_buf_t *__buf ) ;
extern void __pthread_unwind_next(__pthread_unwind_buf_t *__buf ) __attribute__((__weak__,
__noreturn__)) ;
extern int __sigsetjmp_cancel(struct __cancel_jmp_buf_tag *__env , int __savemask ) __asm__("__sigsetjmp") __attribute__((__returns_twice__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_init)(pthread_mutex_t *__mutex ,
                                                                           pthread_mutexattr_t const *__mutexattr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_destroy)(pthread_mutex_t *__mutex ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_mutex_trylock)(pthread_mutex_t *__mutex ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_mutex_lock)(pthread_mutex_t *__mutex ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2))) pthread_mutex_timedlock)(pthread_mutex_t *__mutex ,
                                                                        struct timespec const *__abstime ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_mutex_unlock)(pthread_mutex_t *__mutex ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_mutex_getprioceiling)(pthread_mutex_t const *__mutex ,
                                                                                       int *__prioceiling ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,3), __leaf__)) pthread_mutex_setprioceiling)(pthread_mutex_t *__mutex ,
                                                                                       int __prioceiling ,
                                                                                       int *__old_ceiling ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_consistent)(pthread_mutex_t *__mutex ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_init)(pthread_mutexattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_destroy)(pthread_mutexattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_mutexattr_getpshared)(pthread_mutexattr_t const *__attr ,
                                                                                       int *__pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_setpshared)(pthread_mutexattr_t *__attr ,
                                                                                     int __pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_mutexattr_gettype)(pthread_mutexattr_t const *__attr ,
                                                                                    int *__kind ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_settype)(pthread_mutexattr_t *__attr ,
                                                                                  int __kind ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_mutexattr_getprotocol)(pthread_mutexattr_t const *__attr ,
                                                                                        int *__protocol ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_setprotocol)(pthread_mutexattr_t *__attr ,
                                                                                      int __protocol ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_mutexattr_getprioceiling)(pthread_mutexattr_t const *__attr ,
                                                                                           int *__prioceiling ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_setprioceiling)(pthread_mutexattr_t *__attr ,
                                                                                         int __prioceiling ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_mutexattr_getrobust)(pthread_mutexattr_t const *__attr ,
                                                                                      int *__robustness ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_setrobust)(pthread_mutexattr_t *__attr ,
                                                                                    int __robustness ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_rwlock_init)(pthread_rwlock_t *__rwlock ,
                                                                            pthread_rwlockattr_t const *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_rwlock_destroy)(pthread_rwlock_t *__rwlock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_rwlock_rdlock)(pthread_rwlock_t *__rwlock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_rwlock_tryrdlock)(pthread_rwlock_t *__rwlock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2))) pthread_rwlock_timedrdlock)(pthread_rwlock_t *__rwlock ,
                                                                           struct timespec const *__abstime ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_rwlock_wrlock)(pthread_rwlock_t *__rwlock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_rwlock_trywrlock)(pthread_rwlock_t *__rwlock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2))) pthread_rwlock_timedwrlock)(pthread_rwlock_t *__rwlock ,
                                                                           struct timespec const *__abstime ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_rwlock_unlock)(pthread_rwlock_t *__rwlock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_rwlockattr_init)(pthread_rwlockattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_rwlockattr_destroy)(pthread_rwlockattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_rwlockattr_getpshared)(pthread_rwlockattr_t const *__attr ,
                                                                                        int *__pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_rwlockattr_setpshared)(pthread_rwlockattr_t *__attr ,
                                                                                      int __pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_rwlockattr_getkind_np)(pthread_rwlockattr_t const *__attr ,
                                                                                        int *__pref ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_rwlockattr_setkind_np)(pthread_rwlockattr_t *__attr ,
                                                                                      int __pref ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_cond_init)(pthread_cond_t *__cond ,
                                                                          pthread_condattr_t const *__cond_attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_cond_destroy)(pthread_cond_t *__cond ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_cond_signal)(pthread_cond_t *__cond ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_cond_broadcast)(pthread_cond_t *__cond ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2))) pthread_cond_wait)(pthread_cond_t *__cond ,
                                                                  pthread_mutex_t *__mutex ) ;
extern int ( __attribute__((__nonnull__(1,2,3))) pthread_cond_timedwait)(pthread_cond_t *__cond ,
                                                                         pthread_mutex_t *__mutex ,
                                                                         struct timespec const *__abstime ) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_condattr_init)(pthread_condattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_condattr_destroy)(pthread_condattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_condattr_getpshared)(pthread_condattr_t const *__attr ,
                                                                                      int *__pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_condattr_setpshared)(pthread_condattr_t *__attr ,
                                                                                    int __pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_condattr_getclock)(pthread_condattr_t const *__attr ,
                                                                                    __clockid_t *__clock_id ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_condattr_setclock)(pthread_condattr_t *__attr ,
                                                                                  __clockid_t __clock_id ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_spin_init)(pthread_spinlock_t *__lock ,
                                                                          int __pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_spin_destroy)(pthread_spinlock_t *__lock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_spin_lock)(pthread_spinlock_t *__lock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_spin_trylock)(pthread_spinlock_t *__lock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_spin_unlock)(pthread_spinlock_t *__lock ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_barrier_init)(pthread_barrier_t *__barrier ,
                                                                             pthread_barrierattr_t const *__attr ,
                                                                             unsigned int __count ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_barrier_destroy)(pthread_barrier_t *__barrier ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) pthread_barrier_wait)(pthread_barrier_t *__barrier ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_barrierattr_init)(pthread_barrierattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_barrierattr_destroy)(pthread_barrierattr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) pthread_barrierattr_getpshared)(pthread_barrierattr_t const *__attr ,
                                                                                         int *__pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_barrierattr_setpshared)(pthread_barrierattr_t *__attr ,
                                                                                       int __pshared ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_key_create)(pthread_key_t *__key ,
                                                                           void (*__destr_function)(void * ) ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_key_delete)(pthread_key_t __key ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__leaf__)) pthread_getspecific)(pthread_key_t __key ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_setspecific)(pthread_key_t __key ,
                                                            void const *__pointer ) __attribute__((__nothrow__,
__access__(__none__,2))) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) pthread_getcpuclockid)(pthread_t __thread_id ,
                                                                              __clockid_t *__clock_id ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_atfork)(void (*__prepare)(void) , void (*__parent)(void) ,
                                                       void (*__child)(void) ) __attribute__((__nothrow__)) ;
int ( __attribute__((__nonnull__(1,2))) pthread_once)(pthread_once_t *once_control ,
                                                      void (*init_routine)(void) ) __attribute__((__goblint_stub__)) ;
int ( __attribute__((__nonnull__(1,2))) pthread_once)(pthread_once_t *once_control ,
                                                      void (*init_routine)(void) )
{
  int top ;
  {
  (*init_routine)();
  return (top);
}
}
extern unsigned short const **( __attribute__((__leaf__)) __ctype_b_loc)(void) __attribute__((__nothrow__,
__const__)) ;
extern __int32_t const **( __attribute__((__leaf__)) __ctype_tolower_loc)(void) __attribute__((__nothrow__,
__const__)) ;
extern __int32_t const **( __attribute__((__leaf__)) __ctype_toupper_loc)(void) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__leaf__)) isalnum)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isalpha)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) iscntrl)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isdigit)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) islower)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isgraph)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isprint)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) ispunct)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isspace)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isupper)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isxdigit)(int ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__)) tolower)(int __c ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__)) toupper)(int __c ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isblank)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isctype)(int __c , int __mask ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isascii)(int __c ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) toascii)(int __c ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) _toupper)(int ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) _tolower)(int ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__)) tolower)(int __c ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__)) tolower)(int __c )
{
  __int32_t const **tmp ;
  __int32_t tmp___0 ;
  {
  if (__c >= -128) {
    if (__c < 256) {
      tmp = __ctype_tolower_loc();
      tmp___0 = *(*tmp + __c);
    } else {
      tmp___0 = (__int32_t const )__c;
    }
  } else {
    tmp___0 = (__int32_t const )__c;
  }
  return ((int )tmp___0);
}
}
__inline extern int ( __attribute__((__leaf__)) toupper)(int __c ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__)) toupper)(int __c )
{
  __int32_t const **tmp ;
  __int32_t tmp___0 ;
  {
  if (__c >= -128) {
    if (__c < 256) {
      tmp = __ctype_toupper_loc();
      tmp___0 = *(*tmp + __c);
    } else {
      tmp___0 = (__int32_t const )__c;
    }
  } else {
    tmp___0 = (__int32_t const )__c;
  }
  return ((int )tmp___0);
}
}
extern int ( __attribute__((__leaf__)) isalnum_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isalpha_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) iscntrl_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isdigit_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) islower_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isgraph_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isprint_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) ispunct_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isspace_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isupper_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isxdigit_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) isblank_l)(int , locale_t ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) __tolower_l)(int __c , locale_t __l ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) tolower_l)(int __c , locale_t __l ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) __toupper_l)(int __c , locale_t __l ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) toupper_l)(int __c , locale_t __l ) __attribute__((__nothrow__)) ;
extern DIR *( __attribute__((__nonnull__(1))) opendir)(char const *__name ) ;
extern DIR *fdopendir(int __fd ) ;
extern int ( __attribute__((__nonnull__(1))) closedir)(DIR *__dirp ) ;
extern struct dirent *( __attribute__((__nonnull__(1))) readdir)(DIR *__dirp ) ;
extern struct dirent64 *( __attribute__((__nonnull__(1))) readdir64)(DIR *__dirp ) ;
extern int ( __attribute__((__nonnull__(1,2,3))) readdir_r)(DIR *__dirp , struct dirent *__entry ,
                                                            struct dirent **__result ) __attribute__((__deprecated__)) ;
extern int ( __attribute__((__nonnull__(1,2,3))) readdir64_r)(DIR *__dirp , struct dirent64 *__entry ,
                                                              struct dirent64 **__result ) __attribute__((__deprecated__)) ;
extern void ( __attribute__((__nonnull__(1), __leaf__)) rewinddir)(DIR *__dirp ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__nonnull__(1), __leaf__)) seekdir)(DIR *__dirp , long __pos ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__nonnull__(1), __leaf__)) telldir)(DIR *__dirp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) dirfd)(DIR *__dirp ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__leaf__)) __sysconf)(int __name ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2))) scandir)(char const *__dir , struct dirent ***__namelist ,
                                                        int (*__selector)(struct dirent const * ) ,
                                                        int (*__cmp)(struct dirent const ** ,
                                                                     struct dirent const ** ) ) ;
extern int ( __attribute__((__nonnull__(1,2))) scandir64)(char const *__dir , struct dirent64 ***__namelist ,
                                                          int (*__selector)(struct dirent64 const * ) ,
                                                          int (*__cmp)(struct dirent64 const ** ,
                                                                       struct dirent64 const ** ) ) ;
extern int ( __attribute__((__nonnull__(2,3))) scandirat)(int __dfd , char const *__dir ,
                                                          struct dirent ***__namelist ,
                                                          int (*__selector)(struct dirent const * ) ,
                                                          int (*__cmp)(struct dirent const ** ,
                                                                       struct dirent const ** ) ) ;
extern int ( __attribute__((__nonnull__(2,3))) scandirat64)(int __dfd , char const *__dir ,
                                                            struct dirent64 ***__namelist ,
                                                            int (*__selector)(struct dirent64 const * ) ,
                                                            int (*__cmp)(struct dirent64 const ** ,
                                                                         struct dirent64 const ** ) ) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) alphasort)(struct dirent const **__e1 ,
                                                                    struct dirent const **__e2 ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) alphasort64)(struct dirent64 const **__e1 ,
                                                                      struct dirent64 const **__e2 ) __attribute__((__pure__,
__nothrow__)) ;
extern __ssize_t ( __attribute__((__nonnull__(2,4), __leaf__)) getdirentries)(int __fd ,
                                                                              char *__buf ,
                                                                              size_t __nbytes ,
                                                                              __off_t *__basep ) __attribute__((__nothrow__)) ;
extern __ssize_t ( __attribute__((__nonnull__(2,4), __leaf__)) getdirentries64)(int __fd ,
                                                                                char *__buf ,
                                                                                size_t __nbytes ,
                                                                                __off64_t *__basep ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) versionsort)(struct dirent const **__e1 ,
                                                                      struct dirent const **__e2 ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) versionsort64)(struct dirent64 const **__e1 ,
                                                                        struct dirent64 const **__e2 ) __attribute__((__pure__,
__nothrow__)) ;
extern __ssize_t ( __attribute__((__nonnull__(2), __leaf__)) getdents64)(int __fd ,
                                                                         void *__buffer ,
                                                                         size_t __length ) __attribute__((__nothrow__)) ;
extern FILE *stdin ;
extern FILE *stdout ;
extern FILE *stderr ;
extern int ( __attribute__((__leaf__)) remove)(char const *__filename ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) rename)(char const *__old , char const *__new ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) renameat)(int __oldfd , char const *__old ,
                                                 int __newfd , char const *__new ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) renameat2)(int __oldfd , char const *__old ,
                                                  int __newfd , char const *__new ,
                                                  unsigned int __flags ) __attribute__((__nothrow__)) ;
extern int fclose(FILE *__stream ) ;
extern FILE *( __attribute__((__warn_unused_result__)) tmpfile)(void) __attribute__((__malloc__(fclose,1),
__malloc__)) ;
extern FILE *( __attribute__((__warn_unused_result__)) tmpfile64)(void) __attribute__((__malloc__(fclose,1),
__malloc__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) tmpnam)(char * ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) tmpnam_r)(char *__s ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) tempnam)(char const *__dir ,
                                                                          char const *__pfx ) __attribute__((__nothrow__,
__malloc__(__builtin_free,1), __malloc__)) ;
extern int fflush(FILE *__stream ) ;
extern int fflush_unlocked(FILE *__stream ) ;
extern int fcloseall(void) ;
extern FILE *( __attribute__((__warn_unused_result__)) fopen)(char const *__filename ,
                                                              char const *__modes ) __attribute__((__malloc__(fclose,1),
__malloc__)) ;
extern FILE *( __attribute__((__warn_unused_result__)) freopen)(char const *__filename ,
                                                                char const *__modes ,
                                                                FILE *__stream ) ;
extern FILE *( __attribute__((__warn_unused_result__)) fopen64)(char const *__filename ,
                                                                char const *__modes ) __attribute__((__malloc__(fclose,1),
__malloc__)) ;
extern FILE *( __attribute__((__warn_unused_result__)) freopen64)(char const *__filename ,
                                                                  char const *__modes ,
                                                                  FILE *__stream ) ;
extern FILE *( __attribute__((__warn_unused_result__, __leaf__)) fdopen)(int __fd ,
                                                                         char const *__modes ) __attribute__((__nothrow__,
__malloc__(fclose,1), __malloc__)) ;
extern FILE *( __attribute__((__warn_unused_result__, __leaf__)) fopencookie)(void *__magic_cookie ,
                                                                              char const *__modes ,
                                                                              cookie_io_functions_t __io_funcs ) __attribute__((__nothrow__,
__malloc__(fclose,1), __malloc__)) ;
extern FILE *( __attribute__((__warn_unused_result__, __leaf__)) fmemopen)(void *__s ,
                                                                           size_t __len ,
                                                                           char const *__modes ) __attribute__((__nothrow__,
__malloc__(fclose,1), __malloc__)) ;
extern FILE *( __attribute__((__warn_unused_result__, __leaf__)) open_memstream)(char **__bufloc ,
                                                                                 size_t *__sizeloc ) __attribute__((__nothrow__,
__malloc__(fclose,1), __malloc__)) ;
extern void ( __attribute__((__leaf__)) setbuf)(FILE *__stream , char *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) setvbuf)(FILE *__stream , char *__buf , int __modes ,
                                                size_t __n ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) setbuffer)(FILE *__stream , char *__buf ,
                                                   size_t __size ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) setlinebuf)(FILE *__stream ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) fprintf)(FILE *__stream ,
                                                                                  char const *__fmt
                                                                                  , ...) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) printf)(char const *__fmt
                                                                                 , ...) ;
__inline extern int ( __attribute__((__leaf__, __artificial__, __always_inline__)) sprintf)(char *__s ,
                                                                                            char const *__fmt
                                                                                            , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) vfprintf)(FILE *__stream ,
                                                                                   char const *__fmt ,
                                                                                   __gnuc_va_list __ap ) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) vprintf)(char const *__fmt ,
                                                                                  __gnuc_va_list __ap ) ;
__inline extern int ( __attribute__((__leaf__, __artificial__, __always_inline__)) vsprintf)(char *__s ,
                                                                                             char const *__fmt ,
                                                                                             __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) snprintf)(char *__s , size_t __n , char const *__fmt , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) vsnprintf)(char *__s , size_t __n , char const *__fmt , __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__,
__leaf__, __artificial__, __always_inline__)) vasprintf)(char **__ptr , char const *__fmt ,
                                                         __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__,
__leaf__, __artificial__, __always_inline__)) __asprintf)(char **__ptr , char const *__fmt
                                                          , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__,
__leaf__, __artificial__, __always_inline__)) asprintf)(char **__ptr , char const *__fmt
                                                        , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) vdprintf)(int __fd ,
                                                                                                          char const *__fmt ,
                                                                                                          __gnuc_va_list __ap ) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) dprintf)(int __fd ,
                                                                                                         char const *__fmt
                                                                                                         , ...) ;
extern int ( __attribute__((__warn_unused_result__)) fscanf)(FILE *__stream , char const *__format
                                                             , ...) ;
extern int ( __attribute__((__warn_unused_result__)) scanf)(char const *__format
                                                            , ...) ;
extern int ( __attribute__((__leaf__)) sscanf)(char const *__s , char const *__format
                                               , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__)) vfscanf)(FILE *__s ,
                                                                                     char const *__format ,
                                                                                     __gnuc_va_list __arg ) ;
extern int ( __attribute__((__warn_unused_result__)) vscanf)(char const *__format ,
                                                                                    __gnuc_va_list __arg ) ;
extern int ( __attribute__((__leaf__)) vsscanf)(char const *__s ,
                                                                       char const *__format ,
                                                                       __gnuc_va_list __arg ) __attribute__((__nothrow__)) ;
extern int fgetc(FILE *__stream ) ;
extern int getc(FILE *__stream ) ;
__inline extern int getchar(void) ;
__inline extern int getc_unlocked(FILE *__fp ) ;
__inline extern int getchar_unlocked(void) ;
__inline extern int fgetc_unlocked(FILE *__fp ) ;
extern int fputc(int __c , FILE *__stream ) ;
extern int putc(int __c , FILE *__stream ) ;
__inline extern int putchar(int __c ) ;
__inline extern int fputc_unlocked(int __c , FILE *__stream ) ;
__inline extern int putc_unlocked(int __c , FILE *__stream ) ;
__inline extern int putchar_unlocked(int __c ) ;
extern int getw(FILE *__stream ) ;
extern int putw(int __w , FILE *__stream ) ;
__inline extern char __attribute__((__access__(__write_only__,1,2))) *( __attribute__((__warn_unused_result__,
__artificial__, __always_inline__)) fgets)(char *__s , int __n , FILE *__stream ) __attribute__((__access__(__write_only__,1,2))) ;
__inline extern char __attribute__((__access__(__write_only__,1,2))) *( __attribute__((__warn_unused_result__,
__artificial__, __always_inline__)) fgets_unlocked)(char *__s , int __n , FILE *__stream ) __attribute__((__access__(__write_only__,1,2))) ;
extern __ssize_t ( __attribute__((__warn_unused_result__)) __getdelim)(char **__lineptr ,
                                                                       size_t *__n ,
                                                                       int __delimiter ,
                                                                       FILE *__stream ) ;
extern __ssize_t ( __attribute__((__warn_unused_result__)) getdelim)(char **__lineptr ,
                                                                     size_t *__n ,
                                                                     int __delimiter ,
                                                                     FILE *__stream ) ;
__inline extern __ssize_t ( __attribute__((__warn_unused_result__)) getline)(char **__lineptr ,
                                                                             size_t *__n ,
                                                                             FILE *__stream ) ;
extern int fputs(char const *__s , FILE *__stream ) ;
extern int puts(char const *__s ) ;
extern int ungetc(int __c , FILE *__stream ) ;
__inline extern size_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) fread)(void *__ptr ,
                                                                                                           size_t __size ,
                                                                                                           size_t __n ,
                                                                                                           FILE *__stream ) ;
extern size_t fwrite(void const *__ptr , size_t __size , size_t __n , FILE *__s ) ;
extern int fputs_unlocked(char const *__s , FILE *__stream ) ;
__inline extern size_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) fread_unlocked)(void *__ptr ,
                                                                                                                    size_t __size ,
                                                                                                                    size_t __n ,
                                                                                                                    FILE *__stream ) ;
extern size_t fwrite_unlocked(void const *__ptr , size_t __size , size_t __n , FILE *__stream ) ;
extern int fseek(FILE *__stream , long __off , int __whence ) ;
extern long ( __attribute__((__warn_unused_result__)) ftell)(FILE *__stream ) ;
extern void rewind(FILE *__stream ) ;
extern int fseeko(FILE *__stream , __off_t __off , int __whence ) ;
extern __off_t ( __attribute__((__warn_unused_result__)) ftello)(FILE *__stream ) ;
extern int fgetpos(FILE *__stream , fpos_t *__pos ) ;
extern int fsetpos(FILE *__stream , fpos_t const *__pos ) ;
extern int fseeko64(FILE *__stream , __off64_t __off , int __whence ) ;
extern __off64_t ( __attribute__((__warn_unused_result__)) ftello64)(FILE *__stream ) ;
extern int fgetpos64(FILE *__stream , fpos64_t *__pos ) ;
extern int fsetpos64(FILE *__stream , fpos64_t const *__pos ) ;
extern void ( __attribute__((__leaf__)) clearerr)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) feof)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) ferror)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) clearerr_unlocked)(FILE *__stream ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__)) feof_unlocked)(FILE *__stream ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__)) ferror_unlocked)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern void perror(char const *__s ) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) fileno)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) fileno_unlocked)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern int pclose(FILE *__stream ) ;
extern FILE *( __attribute__((__warn_unused_result__)) popen)(char const *__command ,
                                                              char const *__modes ) __attribute__((__malloc__(pclose,1),
__malloc__)) ;
extern char *( __attribute__((__leaf__)) ctermid)(char *__s ) __attribute__((__nothrow__,
__access__(__write_only__,1))) ;
extern char *cuserid(char *__s ) __attribute__((__access__(__write_only__,1))) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) obstack_printf)(struct obstack *__obstack , char const *__fmt
                                    , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) obstack_vprintf)(struct obstack *__obstack , char const *__fmt ,
                                     __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) flockfile)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) ftrylockfile)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) funlockfile)(FILE *__stream ) __attribute__((__nothrow__)) ;
extern int __uflow(FILE * ) ;
extern int __overflow(FILE * , int ) ;
__inline extern int getchar(void)
{
  int tmp ;
  {
  tmp = getc(stdin);
  return (tmp);
}
}
__inline extern int fgetc_unlocked(FILE *__fp )
{
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  long tmp___3 ;
  {
  tmp___3 = __builtin_expect((long )((unsigned long )__fp->_IO_read_ptr >= (unsigned long )__fp->_IO_read_end),
                             0L);
  if (tmp___3) {
    tmp___0 = __uflow(__fp);
    tmp___2 = tmp___0;
  } else {
    tmp___1 = __fp->_IO_read_ptr;
    (__fp->_IO_read_ptr) ++;
    tmp___2 = (int )*((unsigned char *)tmp___1);
  }
  return (tmp___2);
}
}
__inline extern int getchar_unlocked(void)
{
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  long tmp___3 ;
  {
  tmp___3 = __builtin_expect((long )((unsigned long )stdin->_IO_read_ptr >= (unsigned long )stdin->_IO_read_end),
                             0L);
  if (tmp___3) {
    tmp___0 = __uflow(stdin);
    tmp___2 = tmp___0;
  } else {
    tmp___1 = stdin->_IO_read_ptr;
    (stdin->_IO_read_ptr) ++;
    tmp___2 = (int )*((unsigned char *)tmp___1);
  }
  return (tmp___2);
}
}
__inline extern int putchar(int __c )
{
  int tmp ;
  {
  tmp = putc(__c, stdout);
  return (tmp);
}
}
__inline extern int fputc_unlocked(int __c , FILE *__stream )
{
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  char tmp___2 ;
  int tmp___3 ;
  long tmp___4 ;
  {
  tmp___4 = __builtin_expect((long )((unsigned long )__stream->_IO_write_ptr >= (unsigned long )__stream->_IO_write_end),
                             0L);
  if (tmp___4) {
    tmp___0 = __overflow(__stream, (int )((unsigned char )__c));
    tmp___3 = tmp___0;
  } else {
    tmp___1 = __stream->_IO_write_ptr;
    (__stream->_IO_write_ptr) ++;
    tmp___2 = (char )__c;
    *tmp___1 = tmp___2;
    tmp___3 = (int )((unsigned char )tmp___2);
  }
  return (tmp___3);
}
}
__inline extern int putchar_unlocked(int __c )
{
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  char tmp___2 ;
  int tmp___3 ;
  long tmp___4 ;
  {
  tmp___4 = __builtin_expect((long )((unsigned long )stdout->_IO_write_ptr >= (unsigned long )stdout->_IO_write_end),
                             0L);
  if (tmp___4) {
    tmp___0 = __overflow(stdout, (int )((unsigned char )__c));
    tmp___3 = tmp___0;
  } else {
    tmp___1 = stdout->_IO_write_ptr;
    (stdout->_IO_write_ptr) ++;
    tmp___2 = (char )__c;
    *tmp___1 = tmp___2;
    tmp___3 = (int )((unsigned char )tmp___2);
  }
  return (tmp___3);
}
}
__inline extern __ssize_t ( __attribute__((__warn_unused_result__)) getline)(char **__lineptr ,
                                                                             size_t *__n ,
                                                                             FILE *__stream )
{
  __ssize_t tmp ;
  {
  tmp = __getdelim((char ** __restrict )__lineptr, (size_t * __restrict )__n, '\n',
                   (FILE * __restrict )__stream);
  return (tmp);
}
}
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__)) feof_unlocked)(FILE *__stream ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__)) feof_unlocked)(FILE *__stream )
{
  {
  return ((__stream->_flags & 0x0010) != 0);
}
}
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__)) ferror_unlocked)(FILE *__stream ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__)) ferror_unlocked)(FILE *__stream )
{
  {
  return ((__stream->_flags & 0x0020) != 0);
}
}
extern int ( __attribute__((__leaf__)) __sprintf_chk)(char *__s , int __flag , size_t __slen ,
                                                      char const *__format , ...) __attribute__((__nothrow__,
__access__(__write_only__,1,3))) ;
extern int ( __attribute__((__leaf__)) __vsprintf_chk)(char *__s , int __flag , size_t __slen ,
                                                       char const *__format , __gnuc_va_list __ap ) __attribute__((__nothrow__,
__access__(__write_only__,1,3))) ;
__inline extern int ( __attribute__((__leaf__, __artificial__, __always_inline__)) sprintf)(char *__s ,
                                                                                            char const *__fmt
                                                                                            , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__, __always_inline__)) sprintf)(char *__s ,
                                                                                            char const *__fmt
                                                                                            , ...)
{
  unsigned long tmp ;
  int tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__s, 1);
  tmp___0 = __builtin___sprintf_chk(__s, 1, tmp, __fmt, __builtin_va_arg_pack());
  return (tmp___0);
}
}
__inline extern int ( __attribute__((__leaf__, __artificial__, __always_inline__)) vsprintf)(char *__s ,
                                                                                             char const *__fmt ,
                                                                                             __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__, __always_inline__)) vsprintf)(char *__s ,
                                                                                             char const *__fmt ,
                                                                                             __gnuc_va_list __ap )
{
  unsigned long tmp ;
  int tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__s, 1);
  tmp___0 = __builtin___vsprintf_chk(__s, 1, tmp, __fmt, __ap);
  return (tmp___0);
}
}
extern int ( __attribute__((__leaf__)) __snprintf_chk)(char *__s , size_t __n , int __flag ,
                                                       size_t __slen , char const *__format
                                                       , ...) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__leaf__)) __vsnprintf_chk)(char *__s , size_t __n , int __flag ,
                                                        size_t __slen , char const *__format ,
                                                        __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) snprintf)(char *__s , size_t __n , char const *__fmt , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) snprintf)(char *__s , size_t __n , char const *__fmt , ...)
{
  unsigned long tmp ;
  int tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__s, 1);
  tmp___0 = __builtin___snprintf_chk(__s, __n, 1, tmp, __fmt, __builtin_va_arg_pack());
  return (tmp___0);
}
}
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) vsnprintf)(char *__s , size_t __n , char const *__fmt , __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) vsnprintf)(char *__s , size_t __n , char const *__fmt , __gnuc_va_list __ap )
{
  unsigned long tmp ;
  int tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__s, 1);
  tmp___0 = __builtin___vsnprintf_chk(__s, __n, 1, tmp, __fmt, __ap);
  return (tmp___0);
}
}
extern int __fprintf_chk(FILE *__stream , int __flag , char const *__format , ...) ;
extern int __printf_chk(int __flag , char const *__format , ...) ;
extern int __vfprintf_chk(FILE *__stream , int __flag , char const *__format , __gnuc_va_list __ap ) ;
extern int __vprintf_chk(int __flag , char const *__format , __gnuc_va_list __ap ) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) fprintf)(FILE *__stream ,
                                                                                  char const *__fmt
                                                                                  , ...)
{
  int tmp ;
  {
  tmp = __fprintf_chk((FILE * __restrict )__stream, 1, (char const * __restrict )__fmt,
                      __builtin_va_arg_pack());
  return (tmp);
}
}
__inline extern int ( __attribute__((__artificial__, __always_inline__)) printf)(char const *__fmt
                                                                                 , ...)
{
  int tmp ;
  {
  tmp = __printf_chk(1, (char const * __restrict )__fmt, __builtin_va_arg_pack());
  return (tmp);
}
}
__inline extern int ( __attribute__((__artificial__, __always_inline__)) vprintf)(char const *__fmt ,
                                                                                  __gnuc_va_list __ap )
{
  int tmp ;
  {
  tmp = __vfprintf_chk((FILE * __restrict )stdout, 1, (char const * __restrict )__fmt,
                       __ap);
  return (tmp);
}
}
__inline extern int ( __attribute__((__artificial__, __always_inline__)) vfprintf)(FILE *__stream ,
                                                                                   char const *__fmt ,
                                                                                   __gnuc_va_list __ap )
{
  int tmp ;
  {
  tmp = __vfprintf_chk((FILE * __restrict )__stream, 1, (char const * __restrict )__fmt,
                       __ap);
  return (tmp);
}
}
extern int ( __dprintf_chk)(int __fd , int __flag , char const *__fmt
                                                    , ...) ;
extern int ( __vdprintf_chk)(int __fd , int __flag , char const *__fmt ,
                                                     __gnuc_va_list __arg ) ;
__inline extern int ( __attribute__((__artificial__, __always_inline__)) dprintf)(int __fd ,
                                                                                                         char const *__fmt
                                                                                                         , ...)
{
  int tmp ;
  {
  tmp = __dprintf_chk(__fd, 1, (char const * __restrict )__fmt, __builtin_va_arg_pack());
  return (tmp);
}
}
__inline extern int ( __attribute__((__artificial__, __always_inline__)) vdprintf)(int __fd ,
                                                                                                          char const *__fmt ,
                                                                                                          __gnuc_va_list __ap )
{
  int tmp ;
  {
  tmp = __vdprintf_chk(__fd, 1, (char const * __restrict )__fmt, __ap);
  return (tmp);
}
}
extern int ( __attribute__((__warn_unused_result__, __leaf__)) __asprintf_chk)(char **__ptr ,
                                                                                                      int __flag ,
                                                                                                      char const *__fmt
                                                                                                      , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) __vasprintf_chk)(char **__ptr ,
                                                                                                       int __flag ,
                                                                                                       char const *__fmt ,
                                                                                                       __gnuc_va_list __arg ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) __obstack_printf_chk)(struct obstack *__obstack ,
                                                                                    int __flag ,
                                                                                    char const *__format
                                                                                    , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) __obstack_vprintf_chk)(struct obstack *__obstack ,
                                                                                     int __flag ,
                                                                                     char const *__format ,
                                                                                     __gnuc_va_list __args ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__,
__leaf__, __artificial__, __always_inline__)) asprintf)(char **__ptr , char const *__fmt
                                                        , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__,
__leaf__, __artificial__, __always_inline__)) asprintf)(char **__ptr , char const *__fmt
                                                        , ...)
{
  int tmp ;
  {
  tmp = __asprintf_chk((char ** __restrict )__ptr, 1, (char const * __restrict )__fmt,
                       __builtin_va_arg_pack());
  return (tmp);
}
}
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) obstack_printf)(struct obstack *__obstack , char const *__fmt
                                    , ...) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) obstack_printf)(struct obstack *__obstack , char const *__fmt
                                    , ...)
{
  int tmp ;
  {
  tmp = __obstack_printf_chk((struct obstack * __restrict )__obstack, 1, (char const * __restrict )__fmt,
                             __builtin_va_arg_pack());
  return (tmp);
}
}
__inline extern int ( __attribute__((__warn_unused_result__,
__leaf__, __artificial__, __always_inline__)) vasprintf)(char **__ptr , char const *__fmt ,
                                                         __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__,
__leaf__, __artificial__, __always_inline__)) vasprintf)(char **__ptr , char const *__fmt ,
                                                         __gnuc_va_list __ap )
{
  int tmp ;
  {
  tmp = __vasprintf_chk((char ** __restrict )__ptr, 1, (char const * __restrict )__fmt,
                        __ap);
  return (tmp);
}
}
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) obstack_vprintf)(struct obstack *__obstack , char const *__fmt ,
                                     __gnuc_va_list __ap ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__leaf__, __artificial__,
__always_inline__)) obstack_vprintf)(struct obstack *__obstack , char const *__fmt ,
                                     __gnuc_va_list __ap )
{
  int tmp ;
  {
  tmp = __obstack_vprintf_chk((struct obstack * __restrict )__obstack, 1, (char const * __restrict )__fmt,
                              __ap);
  return (tmp);
}
}
extern char *( __attribute__((__warn_unused_result__)) __fgets_chk)(char *__s , size_t __size ,
                                                                    int __n , FILE *__stream ) __attribute__((__access__(__write_only__,1,3))) ;
extern char *( __attribute__((__warn_unused_result__)) __fgets_alias)(char *__s ,
                                                                      int __n , FILE *__stream ) __asm__("fgets") __attribute__((__access__(__write_only__,1,2))) ;
extern char *( __attribute__((__warn_unused_result__)) __fgets_chk_warn)(char *__s ,
                                                                         size_t __size ,
                                                                         int __n ,
                                                                         FILE *__stream ) __asm__("__fgets_chk") __attribute__((__warning__("fgets called with bigger size than length of destination buffer"))) ;
__inline extern char __attribute__((__access__(__write_only__,1,2))) *( __attribute__((__warn_unused_result__,
__artificial__, __always_inline__)) fgets)(char *__s , int __n , FILE *__stream ) __attribute__((__access__(__write_only__,1,2))) ;
__inline extern char __attribute__((__access__(__write_only__,1,2))) *( __attribute__((__warn_unused_result__,
__artificial__, __always_inline__)) fgets)(char *__s , int __n , FILE *__stream )
{
  size_t sz ;
  unsigned long tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  {
  tmp = __builtin_object_size((void *)__s, 1);
  sz = tmp;
  tmp___2 = __fgets_chk((char * __restrict )__s, sz, __n, (FILE * __restrict )__stream);
  return ((char __attribute__((__access__(__write_only__,1,2))) *)tmp___2);
}
}
extern size_t ( __attribute__((__warn_unused_result__)) __fread_chk)(void *__ptr ,
                                                                     size_t __ptrlen ,
                                                                     size_t __size ,
                                                                     size_t __n ,
                                                                     FILE *__stream ) ;
extern size_t ( __attribute__((__warn_unused_result__)) __fread_alias)(void *__ptr ,
                                                                       size_t __size ,
                                                                       size_t __n ,
                                                                       FILE *__stream ) __asm__("fread") ;
extern size_t ( __attribute__((__warn_unused_result__)) __fread_chk_warn)(void *__ptr ,
                                                                          size_t __ptrlen ,
                                                                          size_t __size ,
                                                                          size_t __n ,
                                                                          FILE *__stream ) __asm__("__fread_chk") __attribute__((__warning__("fread called with bigger size * nmemb than length of destination buffer"))) ;
__inline extern size_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) fread)(void *__ptr ,
                                                                                                           size_t __size ,
                                                                                                           size_t __n ,
                                                                                                           FILE *__stream )
{
  size_t sz ;
  unsigned long tmp ;
  size_t tmp___0 ;
  size_t tmp___1 ;
  size_t tmp___2 ;
  {
  tmp = __builtin_object_size(__ptr, 0);
  sz = tmp;
  tmp___2 = __fread_chk((void * __restrict )__ptr, sz, __size, __n, (FILE * __restrict )__stream);
  return (tmp___2);
}
}
extern char *( __attribute__((__warn_unused_result__)) __fgets_unlocked_chk)(char *__s ,
                                                                             size_t __size ,
                                                                             int __n ,
                                                                             FILE *__stream ) __attribute__((__access__(__write_only__,1,3))) ;
extern char *( __attribute__((__warn_unused_result__)) __fgets_unlocked_alias)(char *__s ,
                                                                               int __n ,
                                                                               FILE *__stream ) __asm__("fgets_unlocked") __attribute__((__access__(__write_only__,1,2))) ;
extern char *( __attribute__((__warn_unused_result__)) __fgets_unlocked_chk_warn)(char *__s ,
                                                                                  size_t __size ,
                                                                                  int __n ,
                                                                                  FILE *__stream ) __asm__("__fgets_unlocked_chk") __attribute__((__warning__("fgets_unlocked called with bigger size than length of destination buffer"))) ;
__inline extern char __attribute__((__access__(__write_only__,1,2))) *( __attribute__((__warn_unused_result__,
__artificial__, __always_inline__)) fgets_unlocked)(char *__s , int __n , FILE *__stream ) __attribute__((__access__(__write_only__,1,2))) ;
__inline extern char __attribute__((__access__(__write_only__,1,2))) *( __attribute__((__warn_unused_result__,
__artificial__, __always_inline__)) fgets_unlocked)(char *__s , int __n , FILE *__stream )
{
  size_t sz ;
  unsigned long tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  {
  tmp = __builtin_object_size((void *)__s, 1);
  sz = tmp;
  tmp___2 = __fgets_unlocked_chk((char * __restrict )__s, sz, __n, (FILE * __restrict )__stream);
  return ((char __attribute__((__access__(__write_only__,1,2))) *)tmp___2);
}
}
extern size_t ( __attribute__((__warn_unused_result__)) __fread_unlocked_chk)(void *__ptr ,
                                                                              size_t __ptrlen ,
                                                                              size_t __size ,
                                                                              size_t __n ,
                                                                              FILE *__stream ) ;
extern size_t ( __attribute__((__warn_unused_result__)) __fread_unlocked_alias)(void *__ptr ,
                                                                                size_t __size ,
                                                                                size_t __n ,
                                                                                FILE *__stream ) __asm__("fread_unlocked") ;
extern size_t ( __attribute__((__warn_unused_result__)) __fread_unlocked_chk_warn)(void *__ptr ,
                                                                                   size_t __ptrlen ,
                                                                                   size_t __size ,
                                                                                   size_t __n ,
                                                                                   FILE *__stream ) __asm__("__fread_unlocked_chk") __attribute__((__warning__("fread_unlocked called with bigger size * nmemb than length of destination buffer"))) ;
__inline extern size_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) fread_unlocked)(void *__ptr ,
                                                                                                                    size_t __size ,
                                                                                                                    size_t __n ,
                                                                                                                    FILE *__stream )
{
  size_t sz ;
  unsigned long tmp ;
  size_t __cnt ;
  char *__cptr ;
  int __c ;
  int tmp___0 ;
  char *tmp___1 ;
  size_t tmp___2 ;
  size_t tmp___3 ;
  size_t tmp___4 ;
  {
  tmp = __builtin_object_size(__ptr, 0);
  sz = tmp;
  tmp___4 = __fread_unlocked_chk((void * __restrict )__ptr, sz, __size, __n, (FILE * __restrict )__stream);
  return (tmp___4);
}
}
extern size_t ( __attribute__((__warn_unused_result__, __leaf__)) __ctype_get_mb_cur_max)(void) __attribute__((__nothrow__)) ;
__inline extern double ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atof)(char const *__nptr ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atoi)(char const *__nptr ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern long ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atol)(char const *__nptr ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern long long ( __attribute__((__warn_unused_result__, __nonnull__(1),
__leaf__)) atoll)(char const *__nptr ) __attribute__((__pure__, __nothrow__)) ;
extern double ( __attribute__((__nonnull__(1), __leaf__)) strtod)(char const *__nptr ,
                                                                  char **__endptr ) __attribute__((__nothrow__)) ;
extern float ( __attribute__((__nonnull__(1), __leaf__)) strtof)(char const *__nptr ,
                                                                 char **__endptr ) __attribute__((__nothrow__)) ;
extern long double ( __attribute__((__nonnull__(1), __leaf__)) strtold)(char const *__nptr ,
                                                                        char **__endptr ) __attribute__((__nothrow__)) ;
extern float ( __attribute__((__nonnull__(1), __leaf__)) strtof32)(char const *__nptr ,
                                                                   char **__endptr ) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__nonnull__(1), __leaf__)) strtof64)(char const *__nptr ,
                                                                    char **__endptr ) __attribute__((__nothrow__)) ;
extern long double ( __attribute__((__nonnull__(1), __leaf__)) strtof128)(char const *__nptr ,
                                                                          char **__endptr ) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__nonnull__(1), __leaf__)) strtof32x)(char const *__nptr ,
                                                                     char **__endptr ) __attribute__((__nothrow__)) ;
extern long double ( __attribute__((__nonnull__(1), __leaf__)) strtof64x)(char const *__nptr ,
                                                                          char **__endptr ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__nonnull__(1), __leaf__)) strtol)(char const *__nptr ,
                                                                char **__endptr ,
                                                                int __base ) __attribute__((__nothrow__)) ;
extern unsigned long ( __attribute__((__nonnull__(1), __leaf__)) strtoul)(char const *__nptr ,
                                                                          char **__endptr ,
                                                                          int __base ) __attribute__((__nothrow__)) ;
extern long long ( __attribute__((__nonnull__(1), __leaf__)) strtoq)(char const *__nptr ,
                                                                     char **__endptr ,
                                                                     int __base ) __attribute__((__nothrow__)) ;
extern unsigned long long ( __attribute__((__nonnull__(1), __leaf__)) strtouq)(char const *__nptr ,
                                                                               char **__endptr ,
                                                                               int __base ) __attribute__((__nothrow__)) ;
extern long long ( __attribute__((__nonnull__(1), __leaf__)) strtoll)(char const *__nptr ,
                                                                      char **__endptr ,
                                                                      int __base ) __attribute__((__nothrow__)) ;
extern unsigned long long ( __attribute__((__nonnull__(1), __leaf__)) strtoull)(char const *__nptr ,
                                                                                char **__endptr ,
                                                                                int __base ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfromd)(char *__dest , size_t __size ,
                                                                 char const *__format ,
                                                                 double __f ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfromf)(char *__dest , size_t __size ,
                                                                 char const *__format ,
                                                                 float __f ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfroml)(char *__dest , size_t __size ,
                                                                 char const *__format ,
                                                                 long double __f ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfromf32)(char *__dest ,
                                                                   size_t __size ,
                                                                   char const *__format ,
                                                                   float __f ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfromf64)(char *__dest ,
                                                                   size_t __size ,
                                                                   char const *__format ,
                                                                   double __f ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfromf128)(char *__dest ,
                                                                    size_t __size ,
                                                                    char const *__format ,
                                                                    long double __f ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfromf32x)(char *__dest ,
                                                                    size_t __size ,
                                                                    char const *__format ,
                                                                    double __f ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) strfromf64x)(char *__dest ,
                                                                    size_t __size ,
                                                                    char const *__format ,
                                                                    long double __f ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__nonnull__(1,4), __leaf__)) strtol_l)(char const *__nptr ,
                                                                    char **__endptr ,
                                                                    int __base , locale_t __loc ) __attribute__((__nothrow__)) ;
extern unsigned long ( __attribute__((__nonnull__(1,4), __leaf__)) strtoul_l)(char const *__nptr ,
                                                                              char **__endptr ,
                                                                              int __base ,
                                                                              locale_t __loc ) __attribute__((__nothrow__)) ;
extern long long ( __attribute__((__nonnull__(1,4), __leaf__)) strtoll_l)(char const *__nptr ,
                                                                          char **__endptr ,
                                                                          int __base ,
                                                                          locale_t __loc ) __attribute__((__nothrow__)) ;
extern unsigned long long ( __attribute__((__nonnull__(1,4), __leaf__)) strtoull_l)(char const *__nptr ,
                                                                                    char **__endptr ,
                                                                                    int __base ,
                                                                                    locale_t __loc ) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__nonnull__(1,3), __leaf__)) strtod_l)(char const *__nptr ,
                                                                      char **__endptr ,
                                                                      locale_t __loc ) __attribute__((__nothrow__)) ;
extern float ( __attribute__((__nonnull__(1,3), __leaf__)) strtof_l)(char const *__nptr ,
                                                                     char **__endptr ,
                                                                     locale_t __loc ) __attribute__((__nothrow__)) ;
extern long double ( __attribute__((__nonnull__(1,3), __leaf__)) strtold_l)(char const *__nptr ,
                                                                            char **__endptr ,
                                                                            locale_t __loc ) __attribute__((__nothrow__)) ;
extern float ( __attribute__((__nonnull__(1,3), __leaf__)) strtof32_l)(char const *__nptr ,
                                                                       char **__endptr ,
                                                                       locale_t __loc ) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__nonnull__(1,3), __leaf__)) strtof64_l)(char const *__nptr ,
                                                                        char **__endptr ,
                                                                        locale_t __loc ) __attribute__((__nothrow__)) ;
extern long double ( __attribute__((__nonnull__(1,3), __leaf__)) strtof128_l)(char const *__nptr ,
                                                                              char **__endptr ,
                                                                              locale_t __loc ) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__nonnull__(1,3), __leaf__)) strtof32x_l)(char const *__nptr ,
                                                                         char **__endptr ,
                                                                         locale_t __loc ) __attribute__((__nothrow__)) ;
extern long double ( __attribute__((__nonnull__(1,3), __leaf__)) strtof64x_l)(char const *__nptr ,
                                                                              char **__endptr ,
                                                                              locale_t __loc ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atoi)(char const *__nptr ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atoi)(char const *__nptr )
{
  long tmp ;
  {
  tmp = strtol((char const * __restrict )__nptr, (char ** __restrict )((char **)((void *)0)),
               10);
  return ((int )tmp);
}
}
__inline extern long ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atol)(char const *__nptr ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern long ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atol)(char const *__nptr )
{
  long tmp ;
  {
  tmp = strtol((char const * __restrict )__nptr, (char ** __restrict )((char **)((void *)0)),
               10);
  return (tmp);
}
}
__inline extern long long ( __attribute__((__warn_unused_result__, __nonnull__(1),
__leaf__)) atoll)(char const *__nptr ) __attribute__((__pure__, __nothrow__)) ;
__inline extern long long ( __attribute__((__warn_unused_result__, __nonnull__(1),
__leaf__)) atoll)(char const *__nptr )
{
  long long tmp ;
  {
  tmp = strtoll((char const * __restrict )__nptr, (char ** __restrict )((char **)((void *)0)),
                10);
  return (tmp);
}
}
extern char *( __attribute__((__warn_unused_result__, __leaf__)) l64a)(long __n ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) a64l)(char const *__s ) __attribute__((__pure__,
__nothrow__)) ;
__inline static __uint16_t __bswap_16(__uint16_t __bsx )
{
  short tmp ;
  {
  tmp = __builtin_bswap16((short )__bsx);
  return ((__uint16_t )tmp);
}
}
__inline static __uint32_t __bswap_32(__uint32_t __bsx )
{
  int tmp ;
  {
  tmp = __builtin_bswap32((int )__bsx);
  return ((__uint32_t )tmp);
}
}
__inline static __uint64_t __bswap_64(__uint64_t __bsx )
{
  long tmp ;
  {
  tmp = __builtin_bswap64((long )__bsx);
  return ((__uint64_t )tmp);
}
}
__inline static __uint16_t __uint16_identity(__uint16_t __x )
{
  {
  return (__x);
}
}
__inline static __uint32_t __uint32_identity(__uint32_t __x )
{
  {
  return (__x);
}
}
__inline static __uint64_t __uint64_identity(__uint64_t __x )
{
  {
  return (__x);
}
}
extern int select(int __nfds , fd_set *__readfds , fd_set *__writefds , fd_set *__exceptfds ,
                  struct timeval *__timeout ) ;
extern int pselect(int __nfds , fd_set *__readfds , fd_set *__writefds , fd_set *__exceptfds ,
                   struct timespec const *__timeout , __sigset_t const *__sigmask ) ;
extern long __fdelt_chk(long __d ) ;
extern long __fdelt_warn(long __d ) __attribute__((__warning__("bit outside of fd_set selected"))) ;
extern long ( __attribute__((__leaf__)) random)(void) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) srandom)(unsigned int __seed ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(2), __leaf__)) initstate)(unsigned int __seed ,
                                                                    char *__statebuf ,
                                                                    size_t __statelen ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) setstate)(char *__statebuf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) random_r)(struct random_data *__buf ,
                                                                   int32_t *__result ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) srandom_r)(unsigned int __seed ,
                                                                  struct random_data *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,4), __leaf__)) initstate_r)(unsigned int __seed ,
                                                                      char *__statebuf ,
                                                                      size_t __statelen ,
                                                                      struct random_data *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) setstate_r)(char *__statebuf ,
                                                                     struct random_data *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) rand)(void) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) srand)(unsigned int __seed ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) rand_r)(unsigned int *__seed ) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__leaf__)) drand48)(void) __attribute__((__nothrow__)) ;
extern double ( __attribute__((__nonnull__(1), __leaf__)) erand48)(unsigned short *__xsubi ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__leaf__)) lrand48)(void) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__nonnull__(1), __leaf__)) nrand48)(unsigned short *__xsubi ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__leaf__)) mrand48)(void) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__nonnull__(1), __leaf__)) jrand48)(unsigned short *__xsubi ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) srand48)(long __seedval ) __attribute__((__nothrow__)) ;
extern unsigned short *( __attribute__((__nonnull__(1), __leaf__)) seed48)(unsigned short *__seed16v ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__nonnull__(1), __leaf__)) lcong48)(unsigned short *__param ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) drand48_r)(struct drand48_data *__buffer ,
                                                                    double *__result ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) erand48_r)(unsigned short *__xsubi ,
                                                                    struct drand48_data *__buffer ,
                                                                    double *__result ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) lrand48_r)(struct drand48_data *__buffer ,
                                                                    long *__result ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) nrand48_r)(unsigned short *__xsubi ,
                                                                    struct drand48_data *__buffer ,
                                                                    long *__result ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) mrand48_r)(struct drand48_data *__buffer ,
                                                                    long *__result ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) jrand48_r)(unsigned short *__xsubi ,
                                                                    struct drand48_data *__buffer ,
                                                                    long *__result ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) srand48_r)(long __seedval ,
                                                                  struct drand48_data *__buffer ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) seed48_r)(unsigned short *__seed16v ,
                                                                   struct drand48_data *__buffer ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) lcong48_r)(unsigned short *__param ,
                                                                    struct drand48_data *__buffer ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__warn_unused_result__, __leaf__)) malloc)(size_t __size ) __attribute__((__nothrow__,
__malloc__, __alloc_size__(1))) ;
extern void *( __attribute__((__warn_unused_result__, __leaf__)) calloc)(size_t __nmemb ,
                                                                         size_t __size ) __attribute__((__nothrow__,
__malloc__, __alloc_size__(1,2))) ;
extern void *( __attribute__((__warn_unused_result__, __leaf__)) realloc)(void *__ptr ,
                                                                          size_t __size ) __attribute__((__nothrow__,
__alloc_size__(2))) ;
extern void ( __attribute__((__leaf__)) free)(void *__ptr ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__warn_unused_result__, __leaf__)) reallocarray)(void *__ptr ,
                                                                               size_t __nmemb ,
                                                                               size_t __size ) __attribute__((__nothrow__,
__malloc__(__builtin_free,1), __malloc__(reallocarray,1), __alloc_size__(2,3))) ;
extern void *( __attribute__((__leaf__)) alloca)(size_t __size ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__warn_unused_result__, __leaf__)) valloc)(size_t __size ) __attribute__((__nothrow__,
__malloc__, __alloc_size__(1))) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) posix_memalign)(void **__memptr ,
                                                                                               size_t __alignment ,
                                                                                               size_t __size ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__warn_unused_result__, __leaf__)) aligned_alloc)(size_t __alignment ,
                                                                                size_t __size ) __attribute__((__nothrow__,
__malloc__, __alloc_size__(2), __alloc_align__(1))) ;
extern void ( __attribute__((__leaf__)) abort)(void) __attribute__((__nothrow__,
__noreturn__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) atexit)(void (*__func)(void) ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) at_quick_exit)(void (*__func)(void) ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) on_exit)(void (*__func)(int __status ,
                                                                               void *__arg ) ,
                                                                void *__arg ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) exit)(int __status ) __attribute__((__nothrow__,
__noreturn__)) ;
extern void ( __attribute__((__leaf__)) quick_exit)(int __status ) __attribute__((__nothrow__,
__noreturn__)) ;
extern void ( __attribute__((__leaf__)) _Exit)(int __status ) __attribute__((__nothrow__,
__noreturn__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) getenv)(char const *__name ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) secure_getenv)(char const *__name ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) putenv)(char *__string ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) setenv)(char const *__name ,
                                                               char const *__value ,
                                                               int __replace ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) unsetenv)(char const *__name ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) clearenv)(void) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) mktemp)(char *__template ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkstemp)(char *__template ) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkstemp64)(char *__template ) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkstemps)(char *__template ,
                                                                               int __suffixlen ) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkstemps64)(char *__template ,
                                                                                 int __suffixlen ) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) mkdtemp)(char *__template ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkostemp)(char *__template ,
                                                                               int __flags ) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkostemp64)(char *__template ,
                                                                                 int __flags ) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkostemps)(char *__template ,
                                                                                int __suffixlen ,
                                                                                int __flags ) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1))) mkostemps64)(char *__template ,
                                                                                  int __suffixlen ,
                                                                                  int __flags ) ;
extern int ( __attribute__((__warn_unused_result__)) system)(char const *__command ) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) canonicalize_file_name)(char const *__name ) __attribute__((__nothrow__,
__malloc__(__builtin_free,1), __malloc__)) ;
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) realpath)(char const *__name , char *__resolved ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__nonnull__(1,4))) qsort_r)(void *__base , size_t __nmemb ,
                                                         size_t __size , int (*__compar)(void const * ,
                                                                                         void const * ,
                                                                                         void * ) ,
                                                         void *__arg ) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) abs)(int __x ) __attribute__((__nothrow__,
__const__)) ;
extern long ( __attribute__((__warn_unused_result__, __leaf__)) labs)(long __x ) __attribute__((__nothrow__,
__const__)) ;
extern long long ( __attribute__((__warn_unused_result__, __leaf__)) llabs)(long long __x ) __attribute__((__nothrow__,
__const__)) ;
extern div_t ( __attribute__((__warn_unused_result__, __leaf__)) div)(int __numer ,
                                                                      int __denom ) __attribute__((__nothrow__,
__const__)) ;
extern ldiv_t ( __attribute__((__warn_unused_result__, __leaf__)) ldiv)(long __numer ,
                                                                        long __denom ) __attribute__((__nothrow__,
__const__)) ;
extern lldiv_t ( __attribute__((__warn_unused_result__, __leaf__)) lldiv)(long long __numer ,
                                                                          long long __denom ) __attribute__((__nothrow__,
__const__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(3,4), __leaf__)) ecvt)(double __value ,
                                                                                         int __ndigit ,
                                                                                         int *__decpt ,
                                                                                         int *__sign ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(3,4), __leaf__)) fcvt)(double __value ,
                                                                                         int __ndigit ,
                                                                                         int *__decpt ,
                                                                                         int *__sign ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(3), __leaf__)) gcvt)(double __value ,
                                                                                       int __ndigit ,
                                                                                       char *__buf ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(3,4), __leaf__)) qecvt)(long double __value ,
                                                                                          int __ndigit ,
                                                                                          int *__decpt ,
                                                                                          int *__sign ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(3,4), __leaf__)) qfcvt)(long double __value ,
                                                                                          int __ndigit ,
                                                                                          int *__decpt ,
                                                                                          int *__sign ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(3), __leaf__)) qgcvt)(long double __value ,
                                                                                        int __ndigit ,
                                                                                        char *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3,4,5), __leaf__)) ecvt_r)(double __value ,
                                                                   int __ndigit ,
                                                                   int *__decpt ,
                                                                   int *__sign , char *__buf ,
                                                                   size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3,4,5), __leaf__)) fcvt_r)(double __value ,
                                                                   int __ndigit ,
                                                                   int *__decpt ,
                                                                   int *__sign , char *__buf ,
                                                                   size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3,4,5), __leaf__)) qecvt_r)(long double __value ,
                                                                    int __ndigit ,
                                                                    int *__decpt ,
                                                                    int *__sign ,
                                                                    char *__buf ,
                                                                    size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3,4,5), __leaf__)) qfcvt_r)(long double __value ,
                                                                    int __ndigit ,
                                                                    int *__decpt ,
                                                                    int *__sign ,
                                                                    char *__buf ,
                                                                    size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) mblen)(char const *__s , size_t __n ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) mbtowc)(wchar_t *__pwc , char const *__s ,
                                               size_t __n ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) wctomb)(char *__s , wchar_t __wchar ) __attribute__((__nothrow__)) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) mbstowcs)(wchar_t *__dst ,
                                                                                                char const *__src ,
                                                                                                size_t __len ) __attribute__((__nothrow__,
__access__(__read_only__,2))) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) wcstombs)(char *__dst ,
                                                                                                wchar_t const *__src ,
                                                                                                size_t __len ) __attribute__((__nothrow__,
__access__(__read_only__,2), __access__(__write_only__,1,3))) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) rpmatch)(char const *__response ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1,2,3), __leaf__)) getsubopt)(char **__optionp ,
                                                                                              char **__tokens ,
                                                                                              char **__valuep ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__)) posix_openpt)(int __oflag ) ;
extern int ( __attribute__((__leaf__)) grantpt)(int __fd ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) unlockpt)(int __fd ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) ptsname)(int __fd ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__nonnull__(2), __leaf__, __artificial__, __always_inline__)) ptsname_r)(int __fd ,
                                                                                                              char *__buf ,
                                                                                                              size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern int getpt(void) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) getloadavg)(double *__loadavg ,
                                                                   int __nelem ) __attribute__((__nothrow__)) ;
__inline extern double ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atof)(char const *__nptr ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern double ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) atof)(char const *__nptr )
{
  double tmp ;
  {
  tmp = strtod((char const * __restrict )__nptr, (char ** __restrict )((char **)((void *)0)));
  return (tmp);
}
}
extern char *( __attribute__((__warn_unused_result__, __leaf__)) __realpath_chk)(char const *__name ,
                                                                                 char *__resolved ,
                                                                                 size_t __resolvedlen ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) __realpath_alias)(char const *__name ,
                                                                                   char *__resolved ) __asm__("realpath") __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) __realpath_chk_warn)(char const *__name ,
                                                                                      char *__resolved ,
                                                                                      size_t __resolvedlen ) __asm__("__realpath_chk") __attribute__((__warning__("second argument of realpath must be either NULL or at least PATH_MAX bytes long buffer"),
__nothrow__)) ;
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) realpath)(char const *__name , char *__resolved ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) realpath)(char const *__name , char *__resolved )
{
  size_t sz ;
  unsigned long tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  char *tmp___2 ;
  {
  tmp = __builtin_object_size((void *)__resolved, 1);
  sz = tmp;
  if (sz == 18446744073709551615UL) {
    tmp___0 = __realpath_alias((char const * __restrict )__name, (char * __restrict )__resolved);
    return (tmp___0);
  }
  tmp___2 = __realpath_chk((char const * __restrict )__name, (char * __restrict )__resolved,
                           sz);
  return (tmp___2);
}
}
extern int ( __attribute__((__nonnull__(2), __leaf__)) __ptsname_r_chk)(int __fd ,
                                                                        char *__buf ,
                                                                        size_t __buflen ,
                                                                        size_t __nreal ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) __ptsname_r_alias)(int __fd ,
                                                                          char *__buf ,
                                                                          size_t __buflen ) __asm__("ptsname_r") __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) __ptsname_r_chk_warn)(int __fd ,
                                                                             char *__buf ,
                                                                             size_t __buflen ,
                                                                             size_t __nreal ) __asm__("__ptsname_r_chk") __attribute__((__warning__("ptsname_r called with buflen bigger than size of buf"),
__nothrow__)) ;
__inline extern int ( __attribute__((__nonnull__(2), __leaf__, __artificial__, __always_inline__)) ptsname_r)(int __fd ,
                                                                                                              char *__buf ,
                                                                                                              size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
__inline extern int ( __attribute__((__nonnull__(2), __leaf__, __artificial__, __always_inline__)) ptsname_r)(int __fd ,
                                                                                                              char *__buf ,
                                                                                                              size_t __buflen )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  int tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  int tmp___5 ;
  unsigned long tmp___6 ;
  int tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __ptsname_r_chk(__fd, __buf, __buflen, tmp___6);
  return (tmp___7);
}
}
extern int ( __attribute__((__warn_unused_result__, __leaf__)) __wctomb_chk)(char *__s ,
                                                                             wchar_t __wchar ,
                                                                             size_t __buflen ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) __wctomb_alias)(char *__s ,
                                                                               wchar_t __wchar ) __asm__("wctomb") __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) wctomb)(char *__s , wchar_t __wchar ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) wctomb)(char *__s , wchar_t __wchar )
{
  unsigned long tmp ;
  int tmp___0 ;
  unsigned long tmp___1 ;
  unsigned long tmp___2 ;
  int tmp___3 ;
  {
  tmp___1 = __builtin_object_size((void *)__s, 1);
  if (tmp___1 != 18446744073709551615UL) {
    tmp___2 = __builtin_object_size((void *)__s, 1);
    if (16UL > tmp___2) {
      tmp = __builtin_object_size((void *)__s, 1);
      tmp___0 = __wctomb_chk(__s, __wchar, tmp);
      return (tmp___0);
    }
  }
  tmp___3 = __wctomb_alias(__s, __wchar);
  return (tmp___3);
}
}
extern size_t ( __attribute__((__leaf__)) __mbstowcs_chk)(wchar_t *__dst , char const *__src ,
                                                          size_t __len , size_t __dstlen ) __attribute__((__nothrow__,
__access__(__read_only__,2), __access__(__write_only__,1,3))) ;
extern size_t ( __attribute__((__leaf__)) __mbstowcs_alias)(wchar_t *__dst , char const *__src ,
                                                            size_t __len ) __asm__("mbstowcs") __attribute__((__nothrow__,
__access__(__read_only__,2), __access__(__write_only__,1,3))) ;
extern size_t ( __attribute__((__leaf__)) __mbstowcs_chk_warn)(wchar_t *__dst , char const *__src ,
                                                               size_t __len , size_t __dstlen ) __asm__("__mbstowcs_chk") __attribute__((__warning__("mbstowcs called with dst buffer smaller than len * sizeof (wchar_t)"),
__nothrow__)) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) mbstowcs)(wchar_t *__dst ,
                                                                                                char const *__src ,
                                                                                                size_t __len ) __attribute__((__nothrow__,
__access__(__read_only__,2))) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) mbstowcs)(wchar_t *__dst ,
                                                                                                char const *__src ,
                                                                                                size_t __len )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  size_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  size_t tmp___5 ;
  unsigned long tmp___6 ;
  size_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__dst, 1);
  tmp___7 = __mbstowcs_chk((wchar_t * __restrict )__dst, (char const * __restrict )__src,
                           __len, tmp___6 / sizeof(wchar_t ));
  return (tmp___7);
}
}
extern size_t ( __attribute__((__leaf__)) __wcstombs_chk)(char *__dst , wchar_t const *__src ,
                                                          size_t __len , size_t __dstlen ) __attribute__((__nothrow__,
__access__(__read_only__,2), __access__(__write_only__,1,3))) ;
extern size_t ( __attribute__((__leaf__)) __wcstombs_alias)(char *__dst , wchar_t const *__src ,
                                                            size_t __len ) __asm__("wcstombs") __attribute__((__nothrow__,
__access__(__read_only__,2), __access__(__write_only__,1,3))) ;
extern size_t ( __attribute__((__leaf__)) __wcstombs_chk_warn)(char *__dst , wchar_t const *__src ,
                                                               size_t __len , size_t __dstlen ) __asm__("__wcstombs_chk") __attribute__((__warning__("wcstombs called with dst buffer smaller than len"),
__nothrow__)) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) wcstombs)(char *__dst ,
                                                                                                wchar_t const *__src ,
                                                                                                size_t __len ) __attribute__((__nothrow__,
__access__(__read_only__,2), __access__(__write_only__,1,3))) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) wcstombs)(char *__dst ,
                                                                                                wchar_t const *__src ,
                                                                                                size_t __len )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  size_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  size_t tmp___5 ;
  unsigned long tmp___6 ;
  size_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__dst, 1);
  tmp___7 = __wcstombs_chk((char * __restrict )__dst, (wchar_t const * __restrict )__src,
                           __len, tmp___6);
  return (tmp___7);
}
}
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) memcpy)(void *__dest , void const *__src , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) memmove)(void *__dest , void const *__src , size_t __len ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__nonnull__(1,2), __leaf__)) memccpy)(void *__dest ,
                                                                    void const *__src ,
                                                                    int __c , size_t __n ) __attribute__((__nothrow__,
__access__(__write_only__,1,4))) ;
__inline extern void *( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) memset)(void *__dest ,
                                                                                                             int __ch ,
                                                                                                             size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) memcmp)(void const *__s1 ,
                                                                 void const *__s2 ,
                                                                 size_t __n ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) __memcmpeq)(void const *__s1 ,
                                                                     void const *__s2 ,
                                                                     size_t __n ) __attribute__((__pure__,
__nothrow__)) ;
extern void *( __attribute__((__nonnull__(1), __leaf__)) memchr)(void const *__s ,
                                                                 int __c , size_t __n ) __attribute__((__pure__,
__nothrow__)) ;
extern void *( __attribute__((__nonnull__(1), __leaf__)) rawmemchr)(void const *__s ,
                                                                    int __c ) __attribute__((__pure__,
__nothrow__)) ;
extern void *( __attribute__((__nonnull__(1), __leaf__)) memrchr)(void const *__s ,
                                                                  int __c , size_t __n ) __attribute__((__pure__,
__nothrow__, __access__(__read_only__,1,3))) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strcpy)(char *__dest , char const *__src ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strncpy)(char *__dest , char const *__src , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strcat)(char *__dest , char const *__src ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strncat)(char *__dest , char const *__src , size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) strcmp)(char const *__s1 ,
                                                                 char const *__s2 ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) strncmp)(char const *__s1 ,
                                                                  char const *__s2 ,
                                                                  size_t __n ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) strcoll)(char const *__s1 ,
                                                                  char const *__s2 ) __attribute__((__pure__,
__nothrow__)) ;
extern size_t ( __attribute__((__nonnull__(2), __leaf__)) strxfrm)(char *__dest ,
                                                                   char const *__src ,
                                                                   size_t __n ) __attribute__((__nothrow__,
__access__(__write_only__,1,3))) ;
extern int ( __attribute__((__nonnull__(1,2,3), __leaf__)) strcoll_l)(char const *__s1 ,
                                                                      char const *__s2 ,
                                                                      locale_t __l ) __attribute__((__pure__,
__nothrow__)) ;
extern size_t ( __attribute__((__nonnull__(2,4), __leaf__)) strxfrm_l)(char *__dest ,
                                                                       char const *__src ,
                                                                       size_t __n ,
                                                                       locale_t __l ) __attribute__((__nothrow__,
__access__(__write_only__,1,3))) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) strdup)(char const *__s ) __attribute__((__nothrow__,
__malloc__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) strndup)(char const *__string ,
                                                                  size_t __n ) __attribute__((__nothrow__,
__malloc__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) strchr)(char const *__s ,
                                                                 int __c ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s ,
                                                                  int __c ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) strchrnul)(char const *__s ,
                                                                    int __c ) __attribute__((__pure__,
__nothrow__)) ;
extern size_t ( __attribute__((__nonnull__(1,2), __leaf__)) strcspn)(char const *__s ,
                                                                     char const *__reject ) __attribute__((__pure__,
__nothrow__)) ;
extern size_t ( __attribute__((__nonnull__(1,2), __leaf__)) strspn)(char const *__s ,
                                                                    char const *__accept ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1,2), __leaf__)) strpbrk)(char const *__s ,
                                                                    char const *__accept ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1,2), __leaf__)) strstr)(char const *__haystack ,
                                                                   char const *__needle ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__nonnull__(2), __leaf__)) strtok)(char *__s , char const *__delim ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(2,3), __leaf__)) __strtok_r)(char *__s ,
                                                                       char const *__delim ,
                                                                       char **__save_ptr ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(2,3), __leaf__)) strtok_r)(char *__s , char const *__delim ,
                                                                     char **__save_ptr ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1,2), __leaf__)) strcasestr)(char const *__haystack ,
                                                                       char const *__needle ) __attribute__((__pure__,
__nothrow__)) ;
extern void *( __attribute__((__nonnull__(1,3), __leaf__)) memmem)(void const *__haystack ,
                                                                   size_t __haystacklen ,
                                                                   void const *__needle ,
                                                                   size_t __needlelen ) __attribute__((__pure__,
__nothrow__, __access__(__read_only__,3,4), __access__(__read_only__,1,2))) ;
extern void *( __attribute__((__nonnull__(1,2), __leaf__)) __mempcpy)(void *__dest ,
                                                                      void const *__src ,
                                                                      size_t __n ) __attribute__((__nothrow__)) ;
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) mempcpy)(void *__dest , void const *__src , size_t __len ) __attribute__((__nothrow__)) ;
extern size_t ( __attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s ) __attribute__((__pure__,
__nothrow__)) ;
extern size_t ( __attribute__((__nonnull__(1), __leaf__)) strnlen)(char const *__string ,
                                                                   size_t __maxlen ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__leaf__)) strerror)(int __errnum ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(2), __leaf__)) strerror_r)(int __errnum ,
                                                                                             char *__buf ,
                                                                                             size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern char const *( __attribute__((__leaf__)) strerrordesc_np)(int __err ) __attribute__((__nothrow__)) ;
extern char const *( __attribute__((__leaf__)) strerrorname_np)(int __err ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) strerror_l)(int __errnum , locale_t __l ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) bcmp)(void const *__s1 ,
                                                               void const *__s2 ,
                                                               size_t __n ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern void ( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) bcopy)(void const *__src , void *__dest , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) bzero)(void *__dest ,
                                                                                                           size_t __len ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) index)(char const *__s ,
                                                                int __c ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) rindex)(char const *__s ,
                                                                 int __c ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__leaf__)) ffs)(int __i ) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__leaf__)) ffsl)(long __l ) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__leaf__)) ffsll)(long long __ll ) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) strcasecmp)(char const *__s1 ,
                                                                     char const *__s2 ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) strncasecmp)(char const *__s1 ,
                                                                      char const *__s2 ,
                                                                      size_t __n ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2,3), __leaf__)) strcasecmp_l)(char const *__s1 ,
                                                                         char const *__s2 ,
                                                                         locale_t __loc ) __attribute__((__pure__,
__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2,4), __leaf__)) strncasecmp_l)(char const *__s1 ,
                                                                          char const *__s2 ,
                                                                          size_t __n ,
                                                                          locale_t __loc ) __attribute__((__pure__,
__nothrow__)) ;
__inline extern void ( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) bcopy)(void const *__src , void *__dest , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void ( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) bcopy)(void const *__src , void *__dest , size_t __len )
{
  unsigned long tmp ;
  {
  tmp = __builtin_object_size(__dest, 0);
  __builtin___memmove_chk(__dest, __src, __len, tmp);
  return;
}
}
__inline extern void ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) bzero)(void *__dest ,
                                                                                                           size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) bzero)(void *__dest ,
                                                                                                           size_t __len )
{
  unsigned long tmp ;
  {
  tmp = __builtin_object_size(__dest, 0);
  __builtin___memset_chk(__dest, '\000', __len, tmp);
  return;
}
}
__inline extern void ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) explicit_bzero)(void *__dest ,
                                                                                                                    size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern char *( __attribute__((__nonnull__(1,2), __leaf__)) strsep)(char **__stringp ,
                                                                   char const *__delim ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) strsignal)(int __sig ) __attribute__((__nothrow__)) ;
extern char const *( __attribute__((__leaf__)) sigabbrev_np)(int __sig ) __attribute__((__nothrow__)) ;
extern char const *( __attribute__((__leaf__)) sigdescr_np)(int __sig ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1,2), __leaf__)) __stpcpy)(char *__dest ,
                                                                     char const *__src ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) stpcpy)(char *__dest , char const *__src ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1,2), __leaf__)) __stpncpy)(char *__dest ,
                                                                      char const *__src ,
                                                                      size_t __n ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) stpncpy)(char *__dest , char const *__src , size_t __n ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) strverscmp)(char const *__s1 ,
                                                                     char const *__s2 ) __attribute__((__pure__,
__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) strfry)(char *__string ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__nonnull__(1), __leaf__)) memfrob)(void *__s , size_t __n ) __attribute__((__nothrow__,
__access__(__read_write__,1,2))) ;
extern char *( __attribute__((__nonnull__(1), __leaf__)) basename)(char const *__filename ) __attribute__((__nothrow__)) ;
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) memcpy)(void *__dest , void const *__src , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) memcpy)(void *__dest , void const *__src , size_t __len )
{
  unsigned long tmp ;
  void *tmp___0 ;
  {
  tmp = __builtin_object_size(__dest, 0);
  tmp___0 = __builtin___memcpy_chk(__dest, __src, __len, tmp);
  return (tmp___0);
}
}
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) memmove)(void *__dest , void const *__src , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) memmove)(void *__dest , void const *__src , size_t __len )
{
  unsigned long tmp ;
  void *tmp___0 ;
  {
  tmp = __builtin_object_size(__dest, 0);
  tmp___0 = __builtin___memmove_chk(__dest, __src, __len, tmp);
  return (tmp___0);
}
}
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) mempcpy)(void *__dest , void const *__src , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) mempcpy)(void *__dest , void const *__src , size_t __len )
{
  unsigned long tmp ;
  void *tmp___0 ;
  {
  tmp = __builtin_object_size(__dest, 0);
  tmp___0 = __builtin___mempcpy_chk(__dest, __src, __len, tmp);
  return (tmp___0);
}
}
__inline extern void *( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) memset)(void *__dest ,
                                                                                                             int __ch ,
                                                                                                             size_t __len ) __attribute__((__nothrow__)) ;
__inline extern void *( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) memset)(void *__dest ,
                                                                                                             int __ch ,
                                                                                                             size_t __len )
{
  unsigned long tmp ;
  void *tmp___0 ;
  {
  tmp = __builtin_object_size(__dest, 0);
  tmp___0 = __builtin___memset_chk(__dest, __ch, __len, tmp);
  return (tmp___0);
}
}
extern void ( __attribute__((__nonnull__(1), __leaf__)) __explicit_bzero_chk)(void *__dest ,
                                                                              size_t __len ,
                                                                              size_t __destlen ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
__inline extern void ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) explicit_bzero)(void *__dest ,
                                                                                                                    size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
__inline extern void ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) explicit_bzero)(void *__dest ,
                                                                                                                    size_t __len )
{
  unsigned long tmp ;
  {
  tmp = __builtin_object_size(__dest, 0);
  __explicit_bzero_chk(__dest, __len, tmp);
  return;
}
}
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strcpy)(char *__dest , char const *__src ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strcpy)(char *__dest , char const *__src )
{
  unsigned long tmp ;
  char *tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__dest, 1);
  tmp___0 = __builtin___strcpy_chk(__dest, __src, tmp);
  return (tmp___0);
}
}
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) stpcpy)(char *__dest , char const *__src ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) stpcpy)(char *__dest , char const *__src )
{
  unsigned long tmp ;
  char *tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__dest, 1);
  tmp___0 = __builtin___stpcpy_chk(__dest, __src, tmp);
  return (tmp___0);
}
}
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strncpy)(char *__dest , char const *__src , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strncpy)(char *__dest , char const *__src , size_t __len )
{
  unsigned long tmp ;
  char *tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__dest, 1);
  tmp___0 = __builtin___strncpy_chk(__dest, __src, __len, tmp);
  return (tmp___0);
}
}
extern int ( __builtin___stpncpy_chk)() ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) stpncpy)(char *__dest , char const *__src , size_t __n ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) stpncpy)(char *__dest , char const *__src , size_t __n )
{
  unsigned long tmp ;
  int tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__dest, 1);
  tmp___0 = __builtin___stpncpy_chk(__dest, __src, __n, tmp);
  return ((char *)tmp___0);
}
}
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strcat)(char *__dest , char const *__src ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strcat)(char *__dest , char const *__src )
{
  unsigned long tmp ;
  char *tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__dest, 1);
  tmp___0 = __builtin___strcat_chk(__dest, __src, tmp);
  return (tmp___0);
}
}
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strncat)(char *__dest , char const *__src , size_t __len ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__nonnull__(1,2), __leaf__, __artificial__,
__always_inline__)) strncat)(char *__dest , char const *__src , size_t __len )
{
  unsigned long tmp ;
  char *tmp___0 ;
  {
  tmp = __builtin_object_size((void *)__dest, 1);
  tmp___0 = __builtin___strncat_chk(__dest, __src, __len, tmp);
  return (tmp___0);
}
}
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) stat)(char const *__file ,
                                                               struct stat *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd , struct stat *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) stat64)(char const *__file ,
                                                                 struct stat64 *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) fstat64)(int __fd , struct stat64 *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,3), __leaf__)) fstatat)(int __fd , char const *__file ,
                                                                  struct stat *__buf ,
                                                                  int __flag ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,3), __leaf__)) fstatat64)(int __fd , char const *__file ,
                                                                    struct stat64 *__buf ,
                                                                    int __flag ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) lstat)(char const *__file ,
                                                                struct stat *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) lstat64)(char const *__file ,
                                                                  struct stat64 *__buf ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) chmod)(char const *__file ,
                                                              __mode_t __mode ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) lchmod)(char const *__file ,
                                                               __mode_t __mode ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) fchmod)(int __fd , __mode_t __mode ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(2), __leaf__)) fchmodat)(int __fd ,
                                                                                         char const *__file ,
                                                                                         __mode_t __mode ,
                                                                                         int __flag ) __attribute__((__nothrow__)) ;
extern __mode_t ( __attribute__((__leaf__)) umask)(__mode_t __mask ) __attribute__((__nothrow__)) ;
extern __mode_t ( __attribute__((__leaf__)) getumask)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) mkdir)(char const *__path ,
                                                              __mode_t __mode ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) mkdirat)(int __fd , char const *__path ,
                                                                __mode_t __mode ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) mknod)(char const *__path ,
                                                              __mode_t __mode , __dev_t __dev ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) mknodat)(int __fd , char const *__path ,
                                                                __mode_t __mode ,
                                                                __dev_t __dev ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) mkfifo)(char const *__path ,
                                                               __mode_t __mode ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) mkfifoat)(int __fd , char const *__path ,
                                                                 __mode_t __mode ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) utimensat)(int __fd , char const *__path ,
                                                                  struct timespec const *__times ,
                                                                  int __flags ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) futimens)(int __fd , struct timespec const *__times ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,5), __leaf__)) statx)(int __dirfd , char const *__path ,
                                                                int __flags , unsigned int __mask ,
                                                                struct statx *__buf ) __attribute__((__nothrow__)) ;
ignores *root_ignores ;
char const *evil_hardcoded_ignore_files[3] ;
char const *ignore_pattern_files[5] ;
ignores *init_ignore(ignores *parent , char const *dirname , size_t const dirname_len ) ;
void cleanup_ignore(ignores *ig ) ;
void add_ignore_pattern(ignores *ig , char const *pattern ) ;
void load_ignore_patterns(ignores *ig , char const *path ) ;
int filename_filter(char const *path , struct dirent const *dir , void *baton ) ;
int is_empty(ignores *ig ) ;
extern int ( __attribute__((__leaf__)) clone)(int (*__fn)(void *__arg ) , void *__child_stack ,
                                              int __flags , void *__arg , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) unshare)(int __flags ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_getcpu)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) getcpu)(unsigned int * , unsigned int * ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) setns)(int __fd , int __nstype ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_setaffinity)(__pid_t __pid , size_t __cpusetsize ,
                                                          cpu_set_t const *__cpuset ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sched_getaffinity)(__pid_t __pid , size_t __cpusetsize ,
                                                          cpu_set_t *__cpuset ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) clock_adjtime)(__clockid_t __clock_id , struct timex *__utx ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) strptime)(char const *__s , char const *__fmt ,
                                                   struct tm *__tp ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) strptime_l)(char const *__s , char const *__fmt ,
                                                     struct tm *__tp , locale_t __loc ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) timespec_getres)(struct timespec *__ts , int __base ) __attribute__((__nothrow__)) ;
extern int getdate_err ;
extern struct tm *getdate(char const *__string ) ;
extern int getdate_r(char const *__string , struct tm *__resbufp ) ;
extern int ( __attribute__((__leaf__)) pthread_tryjoin_np)(pthread_t __th , void **__thread_return ) __attribute__((__nothrow__)) ;
extern int pthread_timedjoin_np(pthread_t __th , void **__thread_return , struct timespec const *__abstime ) ;
extern int pthread_clockjoin_np(pthread_t __th , void **__thread_return , clockid_t __clockid ,
                                struct timespec const *__abstime ) ;
extern int ( __attribute__((__nonnull__(1,3), __leaf__)) pthread_attr_setaffinity_np)(pthread_attr_t *__attr ,
                                                                                      size_t __cpusetsize ,
                                                                                      cpu_set_t const *__cpuset ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,3), __leaf__)) pthread_attr_getaffinity_np)(pthread_attr_t const *__attr ,
                                                                                      size_t __cpusetsize ,
                                                                                      cpu_set_t *__cpuset ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_getattr_default_np)(pthread_attr_t *__attr ) __attribute__((__nothrow__)) ;
extern int pthread_attr_setsigmask_np(pthread_attr_t *__attr , __sigset_t const *sigmask ) ;
extern int pthread_attr_getsigmask_np(pthread_attr_t const *__attr , __sigset_t *sigmask ) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_setattr_default_np)(pthread_attr_t const *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) pthread_getattr_np)(pthread_t __th ,
                                                                           pthread_attr_t *__attr ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) pthread_getname_np)(pthread_t __target_thread ,
                                                                           char *__buf ,
                                                                           size_t __buflen ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) pthread_setname_np)(pthread_t __target_thread ,
                                                                           char const *__name ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_getconcurrency)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_setconcurrency)(int __level ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_yield)(void) __asm__("sched_yield") __attribute__((__nothrow__,
__deprecated__("pthread_yield is deprecated, use sched_yield instead"))) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) pthread_setaffinity_np)(pthread_t __th ,
                                                                               size_t __cpusetsize ,
                                                                               cpu_set_t const *__cpuset ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(3), __leaf__)) pthread_getaffinity_np)(pthread_t __th ,
                                                                               size_t __cpusetsize ,
                                                                               cpu_set_t *__cpuset ) __attribute__((__nothrow__)) ;
extern void __pthread_register_cancel_defer(__pthread_unwind_buf_t *__buf ) ;
extern void __pthread_unregister_cancel_restore(__pthread_unwind_buf_t *__buf ) ;
extern int ( __attribute__((__nonnull__(1,3))) pthread_mutex_clocklock)(pthread_mutex_t *__mutex ,
                                                                        clockid_t __clockid ,
                                                                        struct timespec const *__abstime ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_consistent_np)(pthread_mutex_t * ) __asm__("pthread_mutex_consistent") __attribute__((__nothrow__,
__deprecated__("pthread_mutex_consistent_np is deprecated, use pthread_mutex_consistent"))) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_getrobust_np)(pthread_mutexattr_t * ,
                                                                                       int * ) __asm__("pthread_mutexattr_getrobust") __attribute__((__nothrow__,
__deprecated__("pthread_mutexattr_getrobust_np is deprecated, use pthread_mutexattr_getrobust"))) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_setrobust_np)(pthread_mutexattr_t * ,
                                                                                       int ) __asm__("pthread_mutexattr_setrobust") __attribute__((__nothrow__,
__deprecated__("pthread_mutexattr_setrobust_np is deprecated, use pthread_mutexattr_setrobust"))) ;
extern int ( __attribute__((__nonnull__(1,3))) pthread_rwlock_clockrdlock)(pthread_rwlock_t *__rwlock ,
                                                                           clockid_t __clockid ,
                                                                           struct timespec const *__abstime ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,3))) pthread_rwlock_clockwrlock)(pthread_rwlock_t *__rwlock ,
                                                                           clockid_t __clockid ,
                                                                           struct timespec const *__abstime ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2,4))) pthread_cond_clockwait)(pthread_cond_t *__cond ,
                                                                         pthread_mutex_t *__mutex ,
                                                                         __clockid_t __clock_id ,
                                                                         struct timespec const *__abstime ) ;
extern int ( __attribute__((__leaf__)) pthread_equal)(pthread_t __thread1 , pthread_t __thread2 ) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__leaf__)) pthread_equal)(pthread_t __thread1 , pthread_t __thread2 )
{
  {
  return (__thread1 == __thread2);
}
}
pthread_mutex_t print_mtx ;
void set_log_level(enum log_level threshold ) ;
void log_debug(char const *fmt , ...) ;
void log_msg(char const *fmt , ...) ;
void log_warn(char const *fmt , ...) ;
void log_err(char const *fmt , ...) ;
void vplog(unsigned int const level , char const *fmt , va_list args ) ;
void plog(unsigned int const level , char const *fmt , ...) ;
extern char *optarg ;
extern int optind ;
extern int opterr ;
extern int optopt ;
extern int ( __attribute__((__nonnull__(2,3), __leaf__)) getopt)(int ___argc , char **___argv ,
                                                                 char const *__shortopts ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,3), __leaf__)) getopt_long)(int ___argc ,
                                                                      char **___argv ,
                                                                      char const *__shortopts ,
                                                                      struct option const *__longopts ,
                                                                      int *__longind ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,3), __leaf__)) getopt_long_only)(int ___argc ,
                                                                           char **___argv ,
                                                                           char const *__shortopts ,
                                                                           struct option const *__longopts ,
                                                                           int *__longind ) __attribute__((__nothrow__)) ;
extern void *(*pcre_malloc)(size_t ) ;
extern void (*pcre_free)(void * ) ;
extern void *(*pcre_stack_malloc)(size_t ) ;
extern void (*pcre_stack_free)(void * ) ;
extern int (*pcre_callout)(pcre_callout_block * ) ;
extern int (*pcre_stack_guard)(void) ;
extern void *(*pcre16_malloc)(size_t ) ;
extern void (*pcre16_free)(void * ) ;
extern void *(*pcre16_stack_malloc)(size_t ) ;
extern void (*pcre16_stack_free)(void * ) ;
extern int (*pcre16_callout)(pcre16_callout_block * ) ;
extern int (*pcre16_stack_guard)(void) ;
extern void *(*pcre32_malloc)(size_t ) ;
extern void (*pcre32_free)(void * ) ;
extern void *(*pcre32_stack_malloc)(size_t ) ;
extern void (*pcre32_stack_free)(void * ) ;
extern int (*pcre32_callout)(pcre32_callout_block * ) ;
extern int (*pcre32_stack_guard)(void) ;
extern pcre *pcre_compile(char const * , int , char const ** , int * , unsigned char const * ) ;
extern pcre16 *pcre16_compile(unsigned short const * , int , char const ** ,
                              int * , unsigned char const * ) ;
extern pcre32 *pcre32_compile(unsigned int const * , int , char const ** , int * ,
                              unsigned char const * ) ;
extern pcre *pcre_compile2(char const * , int , int * , char const ** , int * ,
                           unsigned char const * ) ;
extern pcre16 *pcre16_compile2(unsigned short const * , int , int * , char const ** ,
                               int * , unsigned char const * ) ;
extern pcre32 *pcre32_compile2(unsigned int const * , int , int * , char const ** ,
                               int * , unsigned char const * ) ;
extern int pcre_config(int , void * ) ;
extern int pcre16_config(int , void * ) ;
extern int pcre32_config(int , void * ) ;
extern int pcre_copy_named_substring(pcre const * , char const * , int * , int ,
                                     char const * , char * , int ) ;
extern int pcre16_copy_named_substring(pcre16 const * , unsigned short const * ,
                                       int * , int , unsigned short const * , unsigned short * ,
                                       int ) ;
extern int pcre32_copy_named_substring(pcre32 const * , unsigned int const * ,
                                       int * , int , unsigned int const * , unsigned int * ,
                                       int ) ;
extern int pcre_copy_substring(char const * , int * , int , int , char * , int ) ;
extern int pcre16_copy_substring(unsigned short const * , int * , int , int ,
                                 unsigned short * , int ) ;
extern int pcre32_copy_substring(unsigned int const * , int * , int , int , unsigned int * ,
                                 int ) ;
extern int pcre_dfa_exec(pcre const * , pcre_extra const * , char const * ,
                         int , int , int , int * , int , int * , int ) ;
extern int pcre16_dfa_exec(pcre16 const * , pcre16_extra const * , unsigned short const * ,
                           int , int , int , int * , int , int * , int ) ;
extern int pcre32_dfa_exec(pcre32 const * , pcre32_extra const * , unsigned int const * ,
                           int , int , int , int * , int , int * , int ) ;
extern int pcre_exec(pcre const * , pcre_extra const * , char const * , int ,
                     int , int , int * , int ) ;
extern int pcre16_exec(pcre16 const * , pcre16_extra const * , unsigned short const * ,
                       int , int , int , int * , int ) ;
extern int pcre32_exec(pcre32 const * , pcre32_extra const * , unsigned int const * ,
                       int , int , int , int * , int ) ;
extern int pcre_jit_exec(pcre const * , pcre_extra const * , char const * ,
                         int , int , int , int * , int , pcre_jit_stack * ) ;
extern int pcre16_jit_exec(pcre16 const * , pcre16_extra const * , unsigned short const * ,
                           int , int , int , int * , int , pcre16_jit_stack * ) ;
extern int pcre32_jit_exec(pcre32 const * , pcre32_extra const * , unsigned int const * ,
                           int , int , int , int * , int , pcre32_jit_stack * ) ;
extern void pcre_free_substring(char const * ) ;
extern void pcre16_free_substring(unsigned short const * ) ;
extern void pcre32_free_substring(unsigned int const * ) ;
extern void pcre_free_substring_list(char const ** ) ;
extern void pcre16_free_substring_list(unsigned short const ** ) ;
extern void pcre32_free_substring_list(unsigned int const ** ) ;
extern int pcre_fullinfo(pcre const * , pcre_extra const * , int , void * ) ;
extern int pcre16_fullinfo(pcre16 const * , pcre16_extra const * , int , void * ) ;
extern int pcre32_fullinfo(pcre32 const * , pcre32_extra const * , int , void * ) ;
extern int pcre_get_named_substring(pcre const * , char const * , int * , int ,
                                    char const * , char const ** ) ;
extern int pcre16_get_named_substring(pcre16 const * , unsigned short const * ,
                                      int * , int , unsigned short const * , unsigned short const ** ) ;
extern int pcre32_get_named_substring(pcre32 const * , unsigned int const * ,
                                      int * , int , unsigned int const * , unsigned int const ** ) ;
extern int pcre_get_stringnumber(pcre const * , char const * ) ;
extern int pcre16_get_stringnumber(pcre16 const * , unsigned short const * ) ;
extern int pcre32_get_stringnumber(pcre32 const * , unsigned int const * ) ;
extern int pcre_get_stringtable_entries(pcre const * , char const * , char ** ,
                                        char ** ) ;
extern int pcre16_get_stringtable_entries(pcre16 const * , unsigned short const * ,
                                          unsigned short ** , unsigned short ** ) ;
extern int pcre32_get_stringtable_entries(pcre32 const * , unsigned int const * ,
                                          unsigned int ** , unsigned int ** ) ;
extern int pcre_get_substring(char const * , int * , int , int , char const ** ) ;
extern int pcre16_get_substring(unsigned short const * , int * , int , int , unsigned short const ** ) ;
extern int pcre32_get_substring(unsigned int const * , int * , int , int , unsigned int const ** ) ;
extern int pcre_get_substring_list(char const * , int * , int , char const *** ) ;
extern int pcre16_get_substring_list(unsigned short const * , int * , int , unsigned short const *** ) ;
extern int pcre32_get_substring_list(unsigned int const * , int * , int , unsigned int const *** ) ;
extern unsigned char const *pcre_maketables(void) ;
extern unsigned char const *pcre16_maketables(void) ;
extern unsigned char const *pcre32_maketables(void) ;
extern int pcre_refcount(pcre * , int ) ;
extern int pcre16_refcount(pcre16 * , int ) ;
extern int pcre32_refcount(pcre32 * , int ) ;
extern pcre_extra *pcre_study(pcre const * , int , char const ** ) ;
extern pcre16_extra *pcre16_study(pcre16 const * , int , char const ** ) ;
extern pcre32_extra *pcre32_study(pcre32 const * , int , char const ** ) ;
extern void pcre_free_study(pcre_extra * ) ;
extern void pcre16_free_study(pcre16_extra * ) ;
extern void pcre32_free_study(pcre32_extra * ) ;
extern char const *pcre_version(void) ;
extern char const *pcre16_version(void) ;
extern char const *pcre32_version(void) ;
extern int pcre_pattern_to_host_byte_order(pcre * , pcre_extra * , unsigned char const * ) ;
extern int pcre16_pattern_to_host_byte_order(pcre16 * , pcre16_extra * , unsigned char const * ) ;
extern int pcre32_pattern_to_host_byte_order(pcre32 * , pcre32_extra * , unsigned char const * ) ;
extern int pcre16_utf16_to_host_byte_order(unsigned short * , unsigned short const * ,
                                           int , int * , int ) ;
extern int pcre32_utf32_to_host_byte_order(unsigned int * , unsigned int const * ,
                                           int , int * , int ) ;
extern pcre_jit_stack *pcre_jit_stack_alloc(int , int ) ;
extern pcre16_jit_stack *pcre16_jit_stack_alloc(int , int ) ;
extern pcre32_jit_stack *pcre32_jit_stack_alloc(int , int ) ;
extern void pcre_jit_stack_free(pcre_jit_stack * ) ;
extern void pcre16_jit_stack_free(pcre16_jit_stack * ) ;
extern void pcre32_jit_stack_free(pcre32_jit_stack * ) ;
extern void pcre_assign_jit_stack(pcre_extra * , pcre_jit_stack *(*)(void * ) , void * ) ;
extern void pcre16_assign_jit_stack(pcre16_extra * , pcre16_jit_stack *(*)(void * ) ,
                                    void * ) ;
extern void pcre32_assign_jit_stack(pcre32_extra * , pcre32_jit_stack *(*)(void * ) ,
                                    void * ) ;
extern void pcre_jit_free_unused_memory(void) ;
extern void pcre16_jit_free_unused_memory(void) ;
extern void pcre32_jit_free_unused_memory(void) ;
cli_options opts ;
void usage(void) ;
void print_version(void) ;
void init_options(void) ;
void parse_options(int argc , char **argv , char ***base_paths , char ***paths ) ;
void cleanup_options(void) ;
int ag_scandir(char const *dirname , struct dirent ***namelist , int (*filter)(char const *path ,
                                                                                 struct dirent const * ,
                                                                                 void * ) ,
               void *baton ) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) gettimeofday)(struct timeval *__tv ,
                                                                     void *__tz ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) settimeofday)(struct timeval const *__tv ,
                                                     struct timezone const *__tz ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) adjtime)(struct timeval const *__delta ,
                                                struct timeval *__olddelta ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) getitimer)(__itimer_which_t __which , struct itimerval *__value ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) setitimer)(__itimer_which_t __which , struct itimerval const *__new ,
                                                  struct itimerval *__old ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) utimes)(char const *__file ,
                                                               struct timeval const *__tvp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) lutimes)(char const *__file ,
                                                                struct timeval const *__tvp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) futimes)(int __fd , struct timeval const *__tvp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) futimesat)(int __fd , char const *__file ,
                                                  struct timeval const *__tvp ) __attribute__((__nothrow__)) ;
FILE *out_fd ;
void *ag_malloc(size_t size ) ;
void *ag_realloc(void *ptr , size_t size ) ;
void *ag_calloc(size_t count , size_t size ) ;
char *ag_strdup(char const *s ) ;
char *ag_strndup(char const *s , size_t size ) ;
ag_stats stats ;
void free_strings(char **strs , size_t const strs_len ) ;
void generate_alpha_skip(char const *find , size_t f_len , size_t *skip_lookup ,
                         int const case_sensitive ) ;
int is_prefix(char const *s , size_t const s_len , size_t const pos , int const case_sensitive ) ;
size_t suffix_len(char const *s , size_t const s_len , size_t const pos , int const case_sensitive ) ;
void generate_find_skip(char const *find , size_t const f_len , size_t **skip_lookup ,
                        int const case_sensitive ) ;
void generate_hash(char const *find , size_t const f_len , uint8_t *h_table___0 ,
                   int const case_sensitive ) ;
size_t ag_max(size_t a , size_t b ) ;
size_t ag_min(size_t a , size_t b ) ;
char const *boyer_moore_strnstr(char const *s , char const *find , size_t const s_len ,
                                  size_t const f_len , size_t const *alpha_skip_lookup___0 ,
                                  size_t const *find_skip_lookup___0 , int const case_insensitive ) ;
char const *hash_strnstr(char const *s , char const *find , size_t const s_len ,
                           size_t const f_len , uint8_t *h_table___0 , int const case_sensitive ) ;
size_t invert_matches(char const *buf , size_t const buf_len , match_t *matches ,
                      size_t matches_len ) ;
void realloc_matches(match_t **matches , size_t *matches_size , size_t matches_len ) ;
void compile_study(pcre **re , pcre_extra **re_extra , char *q , int const pcre_opts ,
                   int const study_opts ) ;
int is_binary(void const *buf , size_t const buf_len ) ;
int is_regex(char const *query ) ;
int is_fnmatch(char const *filename ) ;
int binary_search(char const *needle , char **haystack , int start , int end ) ;
void init_wordchar_table(void) ;
int is_wordchar(char ch ) ;
int is_lowercase(char const *s ) ;
int is_directory(char const *path , struct dirent const *d ) ;
int is_symlink(char const *path , struct dirent const *d ) ;
int is_named_pipe(char const *path , struct dirent const *d ) ;
void die(char const *fmt , ...) ;
void ag_asprintf(char **ret , char const *fmt , ...) ;
ssize_t buf_getline(char const **line , char const *buf , size_t const buf_len ,
                    size_t const buf_offset ) ;
char *fgetln(FILE *fp , size_t *lenp ) ;
size_t strlcpy(char *dst , char const *src , size_t size ) ;
extern int fnmatch(char const *__pattern , char const *__name , int __flags ) ;
int const fnmatch_flags = (int const )1;
char const *evil_hardcoded_ignore_files[3] = { (char const *)".", (char const *)"..", (char const *)((void *)0)};
char const *ignore_pattern_files[5] = { (char const *)".ignore", (char const *)".gitignore", (char const *)".git/info/exclude", (char const *)".hgignore",
        (char const *)((void *)0)};
int is_empty(ignores *ig )
{
  {
  return ((((ig->extensions_len + ig->names_len) + ig->slash_names_len) + ig->regexes_len) + ig->slash_regexes_len == 0UL);
}
}
ignores *init_ignore(ignores *parent , char const *dirname , size_t const dirname_len )
{
  ignores *ig ;
  void *tmp ;
  int tmp___0 ;
  void *tmp___1 ;
  {
  tmp = ag_malloc(sizeof(ignores ));
  ig = (ignores *)tmp;
  ig->extensions = (char **)((void *)0);
  ig->extensions_len = (size_t )0;
  ig->names = (char **)((void *)0);
  ig->names_len = (size_t )0;
  ig->slash_names = (char **)((void *)0);
  ig->slash_names_len = (size_t )0;
  ig->regexes = (char **)((void *)0);
  ig->regexes_len = (size_t )0;
  ig->invert_regexes = (char **)((void *)0);
  ig->invert_regexes_len = (size_t )0;
  ig->slash_regexes = (char **)((void *)0);
  ig->slash_regexes_len = (size_t )0;
  ig->dirname = dirname;
  ig->dirname_len = (size_t )dirname_len;
  if (parent) {
    tmp___0 = is_empty(parent);
    if (tmp___0) {
      if (parent->parent) {
        ig->parent = parent->parent;
      } else {
        ig->parent = parent;
      }
    } else {
      ig->parent = parent;
    }
  } else {
    ig->parent = parent;
  }
  if (parent) {
    if (parent->abs_path_len > 0UL) {
      ag_asprintf(& ig->abs_path, (char const *)"%s/%s", parent->abs_path, dirname);
      ig->abs_path_len = (parent->abs_path_len + 1UL) + (size_t )dirname_len;
    } else {
      goto _L;
    }
  } else
  _L:
  if (dirname_len == 1UL) {
    if ((int const )*(dirname + 0) == 46) {
      tmp___1 = ag_malloc(sizeof(char ));
      ig->abs_path = (char *)tmp___1;
      *(ig->abs_path + 0) = (char )'\000';
      ig->abs_path_len = (size_t )0;
    } else {
      ag_asprintf(& ig->abs_path, (char const *)"%s", dirname);
      ig->abs_path_len = (size_t )dirname_len;
    }
  } else {
    ag_asprintf(& ig->abs_path, (char const *)"%s", dirname);
    ig->abs_path_len = (size_t )dirname_len;
  }
  return (ig);
}
}
void cleanup_ignore(ignores *ig )
{
  {
  if ((unsigned long )ig == (unsigned long )((void *)0)) {
    return;
  }
  free_strings(ig->extensions, (size_t const )ig->extensions_len);
  free_strings(ig->names, (size_t const )ig->names_len);
  free_strings(ig->slash_names, (size_t const )ig->slash_names_len);
  free_strings(ig->regexes, (size_t const )ig->regexes_len);
  free_strings(ig->invert_regexes, (size_t const )ig->invert_regexes_len);
  free_strings(ig->slash_regexes, (size_t const )ig->slash_regexes_len);
  if (ig->abs_path) {
    free((void *)ig->abs_path);
  }
  free((void *)ig);
  return;
}
}
void add_ignore_pattern(ignores *ig , char const *pattern )
{
  int i ;
  int pattern_len ;
  int tmp ;
  size_t tmp___0 ;
  unsigned short const **tmp___1 ;
  char ***patterns_p ;
  size_t *patterns_len ;
  char *tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  char **patterns ;
  void *tmp___5 ;
  int tmp___6 ;
  char *tmp___7 ;
  {
  tmp = strncmp(pattern, (char const *)"./", (size_t )2);
  if (tmp == 0) {
    pattern ++;
  }
  tmp___0 = strlen(pattern);
  pattern_len = (int )tmp___0;
  {
  while (1) {
    while_continue: ;
    if (! (pattern_len > 0)) {
      goto while_break;
    }
    tmp___1 = __ctype_b_loc();
    if (! ((int const )*(*tmp___1 + (int )*(pattern + (pattern_len - 1))) & 8192)) {
      goto while_break;
    }
    pattern_len --;
  }
  while_break: ;
  }
  if (pattern_len == 0) {
    log_debug((char const *)"Pattern is empty. Not adding any ignores.");
    return;
  }
  tmp___4 = is_fnmatch(pattern);
  if (tmp___4) {
    if ((int const )*(pattern + 0) == 42) {
      if ((int const )*(pattern + 1) == 46) {
        tmp___2 = strchr(pattern + 2, '.');
        if (tmp___2) {
          tmp___3 = is_fnmatch(pattern + 2);
          if (tmp___3) {
            goto _L___1;
          } else {
            patterns_p = & ig->extensions;
            patterns_len = & ig->extensions_len;
            pattern += 2;
            pattern_len -= 2;
          }
        } else {
          goto _L___1;
        }
      } else {
        goto _L___1;
      }
    } else
    _L___1:
    _L___0:
    _L:
    if ((int const )*(pattern + 0) == 47) {
      patterns_p = & ig->slash_regexes;
      patterns_len = & ig->slash_regexes_len;
      pattern ++;
      pattern_len --;
    } else
    if ((int const )*(pattern + 0) == 33) {
      patterns_p = & ig->invert_regexes;
      patterns_len = & ig->invert_regexes_len;
      pattern ++;
      pattern_len --;
    } else {
      patterns_p = & ig->regexes;
      patterns_len = & ig->regexes_len;
    }
  } else
  if ((int const )*(pattern + 0) == 47) {
    patterns_p = & ig->slash_names;
    patterns_len = & ig->slash_names_len;
    pattern ++;
    pattern_len --;
  } else {
    patterns_p = & ig->names;
    patterns_len = & ig->names_len;
  }
  (*patterns_len) ++;
  tmp___5 = ag_realloc((void *)*patterns_p, *patterns_len * sizeof(char *));
  patterns = (char **)tmp___5;
  *patterns_p = patterns;
  i = (int )(*patterns_len - 1UL);
  {
  while (1) {
    while_continue___0: ;
    if (! (i > 0)) {
      goto while_break___0;
    }
    tmp___6 = strcmp(pattern, (char const *)*(patterns + (i - 1)));
    if (tmp___6 > 0) {
      goto while_break___0;
    }
    *(patterns + i) = *(patterns + (i - 1));
    i --;
  }
  while_break___0: ;
  }
  *(patterns + i) = ag_strndup(pattern, (size_t )pattern_len);
  if ((unsigned long )ig == (unsigned long )root_ignores) {
    tmp___7 = "root ignores";
  } else {
    tmp___7 = ig->abs_path;
  }
  log_debug((char const *)"added ignore pattern %s to %s", pattern, tmp___7);
  return;
}
}
void load_ignore_patterns(ignores *ig , char const *path )
{
  FILE *fp ;
  char *line ;
  ssize_t line_len ;
  size_t line_cap ;
  {
  fp = (FILE *)((void *)0);
  fp = fopen((char const * __restrict )path, (char const * __restrict )"r");
  if ((unsigned long )fp == (unsigned long )((void *)0)) {
    log_debug((char const *)"Skipping ignore file %s: not readable", path);
    return;
  }
  log_debug((char const *)"Loading ignore file %s.", path);
  line = (char *)((void *)0);
  line_len = (ssize_t )0;
  line_cap = (size_t )0;
  {
  while (1) {
    while_continue: ;
    line_len = getline(& line, & line_cap, fp);
    if (! (line_len > 0L)) {
      goto while_break;
    }
    if (line_len == 0L) {
      goto while_continue;
    } else
    if ((int )*(line + 0) == 10) {
      goto while_continue;
    } else
    if ((int )*(line + 0) == 35) {
      goto while_continue;
    }
    if ((int )*(line + (line_len - 1L)) == 10) {
      *(line + (line_len - 1L)) = (char )'\000';
    }
    add_ignore_pattern(ig, (char const *)line);
  }
  while_break: ;
  }
  free((void *)line);
  fclose(fp);
  return;
}
}
static int ackmate_dir_match(char const *dir_name )
{
  size_t tmp ;
  int tmp___0 ;
  {
  if ((unsigned long )opts.ackmate_dir_filter == (unsigned long )((void *)0)) {
    return (0);
  }
  tmp = strlen(dir_name);
  tmp___0 = pcre_exec((pcre const *)opts.ackmate_dir_filter, (pcre_extra const *)((void *)0),
                      dir_name, (int )tmp, 0, 0, (int *)((void *)0), 0);
  return (tmp___0);
}
}
static int path_ignore_search(ignores const *ig , char const *path , char const *filename )
{
  char *temp ;
  int temp_start_pos ;
  size_t i ;
  int match_pos ;
  char const *tmp ;
  char *slash_filename ;
  char *pos ;
  char *tmp___0 ;
  size_t tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int rv ;
  int tmp___6 ;
  {
  match_pos = binary_search(filename, (char **)ig->names, 0, (int )ig->names_len);
  if (match_pos >= 0) {
    log_debug((char const *)"file %s ignored because name matches static pattern %s",
              filename, *(ig->names + match_pos));
    return (1);
  }
  if ((int const )*(path + 0) == 46) {
    tmp = path + 1;
  } else {
    tmp = path;
  }
  ag_asprintf(& temp, (char const *)"%s/%s", tmp, filename);
  if ((int )*(temp + 0) == 47) {
    temp_start_pos = 1;
  } else {
    temp_start_pos = 0;
  }
  tmp___3 = strncmp((char const *)(temp + temp_start_pos), (char const *)ig->abs_path,
                    (size_t )ig->abs_path_len);
  if (tmp___3 == 0) {
    slash_filename = (temp + temp_start_pos) + ig->abs_path_len;
    if ((int )*(slash_filename + 0) == 47) {
      slash_filename ++;
    }
    match_pos = binary_search((char const *)slash_filename, (char **)ig->names,
                              0, (int )ig->names_len);
    if (match_pos >= 0) {
      log_debug((char const *)"file %s ignored because name matches static pattern %s",
                temp, *(ig->names + match_pos));
      free((void *)temp);
      return (1);
    }
    match_pos = binary_search((char const *)slash_filename, (char **)ig->slash_names,
                              0, (int )ig->slash_names_len);
    if (match_pos >= 0) {
      log_debug((char const *)"file %s ignored because name matches slash static pattern %s",
                slash_filename, *(ig->slash_names + match_pos));
      free((void *)temp);
      return (1);
    }
    i = (size_t )0;
    {
    while (1) {
      while_continue: ;
      if (! (i < (size_t )ig->names_len)) {
        goto while_break;
      }
      tmp___0 = strstr((char const *)slash_filename, (char const *)*(ig->names + i));
      pos = tmp___0;
      if ((unsigned long )pos == (unsigned long )slash_filename) {
        goto _L;
      } else
      if (pos) {
        if ((int )*(pos - 1) == 47) {
          _L:
          tmp___1 = strlen((char const *)*(ig->names + i));
          pos += tmp___1;
          if ((int )*pos == 0) {
            log_debug((char const *)"file %s ignored because path somewhere matches name %s",
                      slash_filename, *(ig->names + i));
            free((void *)temp);
            return (1);
          } else
          if ((int )*pos == 47) {
            log_debug((char const *)"file %s ignored because path somewhere matches name %s",
                      slash_filename, *(ig->names + i));
            free((void *)temp);
            return (1);
          }
        }
      }
      log_debug((char const *)"pattern %s doesn\'t match path %s", *(ig->names + i),
                slash_filename);
      i ++;
    }
    while_break: ;
    }
    i = (size_t )0;
    {
    while (1) {
      while_continue___0: ;
      if (! (i < (size_t )ig->slash_regexes_len)) {
        goto while_break___0;
      }
      tmp___2 = fnmatch((char const *)*(ig->slash_regexes + i), (char const *)slash_filename,
                        (int )fnmatch_flags);
      if (tmp___2 == 0) {
        log_debug((char const *)"file %s ignored because name matches slash regex pattern %s",
                  slash_filename, *(ig->slash_regexes + i));
        free((void *)temp);
        return (1);
      }
      log_debug((char const *)"pattern %s doesn\'t match slash file %s", *(ig->slash_regexes + i),
                slash_filename);
      i ++;
    }
    while_break___0: ;
    }
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue___1: ;
    if (! (i < (size_t )ig->invert_regexes_len)) {
      goto while_break___1;
    }
    tmp___4 = fnmatch((char const *)*(ig->invert_regexes + i), filename, (int )fnmatch_flags);
    if (tmp___4 == 0) {
      log_debug((char const *)"file %s not ignored because name matches regex pattern !%s",
                filename, *(ig->invert_regexes + i));
      free((void *)temp);
      return (0);
    }
    log_debug((char const *)"pattern !%s doesn\'t match file %s", *(ig->invert_regexes + i),
              filename);
    i ++;
  }
  while_break___1: ;
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue___2: ;
    if (! (i < (size_t )ig->regexes_len)) {
      goto while_break___2;
    }
    tmp___5 = fnmatch((char const *)*(ig->regexes + i), filename, (int )fnmatch_flags);
    if (tmp___5 == 0) {
      log_debug((char const *)"file %s ignored because name matches regex pattern %s",
                filename, *(ig->regexes + i));
      free((void *)temp);
      return (1);
    }
    log_debug((char const *)"pattern %s doesn\'t match file %s", *(ig->regexes + i),
              filename);
    i ++;
  }
  while_break___2: ;
  }
  tmp___6 = ackmate_dir_match((char const *)temp);
  rv = tmp___6;
  free((void *)temp);
  return (rv);
}
}
int filename_filter(char const *path , struct dirent const *dir , void *baton )
{
  char const *filename ;
  size_t i ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  scandir_baton_t *scandir_baton ;
  char const *path_start ;
  char const *extension ;
  char *tmp___2 ;
  size_t filename_len ;
  int tmp___3 ;
  ignores const *ig ;
  int match_pos ;
  int tmp___4 ;
  int tmp___5 ;
  char *temp ;
  int rv ;
  int tmp___6 ;
  int tmp___7 ;
  {
  filename = (char const *)(dir->d_name);
  if (! opts.search_hidden_files) {
    if ((int const )*(filename + 0) == 46) {
      return (0);
    }
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! ((unsigned long )evil_hardcoded_ignore_files[i] != (unsigned long )((void *)0))) {
      goto while_break;
    }
    tmp = strcmp(filename, evil_hardcoded_ignore_files[i]);
    if (tmp == 0) {
      return (0);
    }
    i ++;
  }
  while_break: ;
  }
  if (! opts.follow_symlinks) {
    tmp___0 = is_symlink(path, dir);
    if (tmp___0) {
      log_debug((char const *)"File %s ignored becaused it\'s a symlink", dir->d_name);
      return (0);
    }
  }
  tmp___1 = is_named_pipe(path, dir);
  if (tmp___1) {
    log_debug((char const *)"%s ignored because it\'s a named pipe or socket", path);
    return (0);
  }
  if (opts.search_all_files) {
    if (! opts.path_to_ignore) {
      return (1);
    }
  }
  scandir_baton = (scandir_baton_t *)baton;
  path_start = scandir_baton->path_start;
  tmp___2 = strchr(filename, '.');
  extension = (char const *)tmp___2;
  if (extension) {
    if (*(extension + 1)) {
      extension ++;
    } else {
      extension = (char const *)((void *)0);
    }
  }
  filename_len = (size_t )0;
  tmp___3 = strncmp(filename, (char const *)"./", (size_t )2);
  if (tmp___3 == 0) {
    filename_len = strlen(filename);
    filename ++;
    filename_len --;
  }
  ig = scandir_baton->ig;
  {
  while (1) {
    while_continue___0: ;
    if (! ((unsigned long )ig != (unsigned long )((void *)0))) {
      goto while_break___0;
    }
    if (extension) {
      tmp___4 = binary_search(extension, (char **)ig->extensions, 0, (int )ig->extensions_len);
      match_pos = tmp___4;
      if (match_pos >= 0) {
        log_debug((char const *)"file %s ignored because name matches extension %s",
                  filename, *(ig->extensions + match_pos));
        return (0);
      }
    }
    tmp___5 = path_ignore_search(ig, path_start, filename);
    if (tmp___5) {
      return (0);
    }
    tmp___7 = is_directory(path, dir);
    if (tmp___7) {
      if (! filename_len) {
        filename_len = strlen(filename);
      }
      if ((int const )*(filename + (filename_len - 1UL)) != 47) {
        ag_asprintf(& temp, (char const *)"%s/", filename);
        tmp___6 = path_ignore_search(ig, path_start, (char const *)temp);
        rv = tmp___6;
        free((void *)temp);
        if (rv) {
          return (0);
        }
      }
    }
    ig = (ignores const *)ig->parent;
  }
  while_break___0: ;
  }
  log_debug((char const *)"%s not ignored", filename);
  return (1);
}
}
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) realpath)(char const *__name , char *__resolved ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) realpath)(char const *__name , char *__resolved )
{
  size_t sz ;
  unsigned long tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  {
  tmp = __builtin_object_size((void *)__resolved, 1);
  sz = tmp;
  if (sz == 18446744073709551615UL) {
    tmp___0 = __realpath_alias((char const * __restrict )__name, (char * __restrict )__resolved);
    return (tmp___0);
  }
  tmp___1 = __realpath_chk((char const * __restrict )__name, (char * __restrict )__resolved,
                           sz);
  return (tmp___1);
}
}
pthread_mutex_t print_mtx = {{0, 0U, 0, 0U, 0, (short)0, (short)0, {(struct __pthread_internal_list *)0, (struct __pthread_internal_list *)0}}};
static enum log_level log_threshold = (enum log_level )40;
void set_log_level(enum log_level threshold )
{
  {
  log_threshold = threshold;
  return;
}
}
void log_debug(char const *fmt , ...)
{
  va_list args ;
  {
  __builtin_va_start(args, fmt);
  vplog((unsigned int const )10, fmt, args);
  __builtin_va_end(args);
  return;
}
}
void log_msg(char const *fmt , ...)
{
  va_list args ;
  {
  __builtin_va_start(args, fmt);
  vplog((unsigned int const )20, fmt, args);
  __builtin_va_end(args);
  return;
}
}
void log_warn(char const *fmt , ...)
{
  va_list args ;
  {
  __builtin_va_start(args, fmt);
  vplog((unsigned int const )30, fmt, args);
  __builtin_va_end(args);
  return;
}
}
void log_err(char const *fmt , ...)
{
  va_list args ;
  {
  __builtin_va_start(args, fmt);
  vplog((unsigned int const )40, fmt, args);
  __builtin_va_end(args);
  return;
}
}
void vplog(unsigned int const level , char const *fmt , va_list args )
{
  FILE *stream ;
  {
  if (level < (unsigned int const )log_threshold) {
    return;
  }
  pthread_mutex_lock(& print_mtx);
  stream = out_fd;
  {
  if (level == 10U) {
    goto case_10;
  }
  if (level == 20U) {
    goto case_20;
  }
  if (level == 30U) {
    goto case_30;
  }
  if (level == 40U) {
    goto case_40;
  }
  goto switch_break;
  case_10:
  fprintf(stream, (char const *)"DEBUG: ");
  goto switch_break;
  case_20:
  fprintf(stream, (char const *)"MSG: ");
  goto switch_break;
  case_30:
  fprintf(stream, (char const *)"WARN: ");
  goto switch_break;
  case_40:
  stream = stderr;
  fprintf(stream, (char const *)"ERR: ");
  goto switch_break;
  switch_break: ;
  }
  vfprintf(stream, fmt, args);
  fprintf(stream, (char const *)"\n");
  pthread_mutex_unlock(& print_mtx);
  return;
}
}
void plog(unsigned int const level , char const *fmt , ...)
{
  va_list args ;
  {
  __builtin_va_start(args, fmt);
  vplog(level, fmt, args);
  __builtin_va_end(args);
  return;
}
}
extern int *( __attribute__((__leaf__)) __errno_location)(void) __attribute__((__nothrow__,
__const__)) ;
extern char *program_invocation_name ;
extern char *program_invocation_short_name ;
extern __sighandler_t ( __attribute__((__leaf__)) __sysv_signal)(int __sig , void (*__handler)(int ) ) __attribute__((__nothrow__)) ;
extern __sighandler_t ( __attribute__((__leaf__)) sysv_signal)(int __sig , void (*__handler)(int ) ) __attribute__((__nothrow__)) ;
extern __sighandler_t ( __attribute__((__leaf__)) signal)(int __sig , void (*__handler)(int ) ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) kill)(__pid_t __pid , int __sig ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) killpg)(__pid_t __pgrp , int __sig ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) raise)(int __sig ) __attribute__((__nothrow__)) ;
extern __sighandler_t ( __attribute__((__leaf__)) ssignal)(int __sig , void (*__handler)(int ) ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) gsignal)(int __sig ) __attribute__((__nothrow__)) ;
extern void psignal(int __sig , char const *__s ) ;
extern void psiginfo(siginfo_t const *__pinfo , char const *__s ) ;
extern int sigpause(int __sig ) __asm__("__xpg_sigpause") __attribute__((__deprecated__("Use the sigsuspend function instead"))) ;
extern int ( __attribute__((__leaf__)) sigblock)(int __mask ) __attribute__((__nothrow__,
__deprecated__)) ;
extern int ( __attribute__((__leaf__)) sigsetmask)(int __mask ) __attribute__((__nothrow__,
__deprecated__)) ;
extern int ( __attribute__((__leaf__)) siggetmask)(void) __attribute__((__nothrow__,
__deprecated__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) sigemptyset)(sigset_t *__set ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) sigfillset)(sigset_t *__set ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) sigaddset)(sigset_t *__set ,
                                                                  int __signo ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) sigdelset)(sigset_t *__set ,
                                                                  int __signo ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) sigismember)(sigset_t const *__set ,
                                                                    int __signo ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) sigisemptyset)(sigset_t const *__set ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2,3), __leaf__)) sigandset)(sigset_t *__set ,
                                                                      sigset_t const *__left ,
                                                                      sigset_t const *__right ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2,3), __leaf__)) sigorset)(sigset_t *__set ,
                                                                     sigset_t const *__left ,
                                                                     sigset_t const *__right ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sigprocmask)(int __how , sigset_t const * __restrict __set ,
                                                    sigset_t * __restrict __oset ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1))) sigsuspend)(sigset_t const *__set ) ;
extern int ( __attribute__((__leaf__)) sigaction)(int __sig , struct sigaction const * __restrict __act ,
                                                  struct sigaction * __restrict __oact ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) sigpending)(sigset_t *__set ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2))) sigwait)(sigset_t const * __restrict __set ,
                                                        int * __restrict __sig ) ;
extern int ( __attribute__((__nonnull__(1))) sigwaitinfo)(sigset_t const * __restrict __set ,
                                                          siginfo_t * __restrict __info ) ;
extern int ( __attribute__((__nonnull__(1))) sigtimedwait)(sigset_t const * __restrict __set ,
                                                           siginfo_t * __restrict __info ,
                                                           struct timespec const * __restrict __timeout ) ;
extern int ( __attribute__((__leaf__)) sigqueue)(__pid_t __pid , int __sig , union sigval const __val ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sigreturn)(struct sigcontext *__scp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) siginterrupt)(int __sig , int __interrupt ) __attribute__((__nothrow__,
__deprecated__("Use sigaction with SA_RESTART instead"))) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) access)(char const *__name ,
                                                               int __type ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) euidaccess)(char const *__name ,
                                                                   int __type ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) eaccess)(char const *__name ,
                                                                int __type ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2,3), __leaf__)) execveat)(int __fd , char const *__path ,
                                                                   char **__argv ,
                                                                   char **__envp ,
                                                                   int __flags ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(2), __leaf__)) faccessat)(int __fd ,
                                                                                          char const *__file ,
                                                                                          int __type ,
                                                                                          int __flag ) __attribute__((__nothrow__)) ;
extern __off_t ( __attribute__((__leaf__)) lseek)(int __fd , __off_t __offset , int __whence ) __attribute__((__nothrow__)) ;
extern __off64_t ( __attribute__((__leaf__)) lseek64)(int __fd , __off64_t __offset ,
                                                      int __whence ) __attribute__((__nothrow__)) ;
extern int close(int __fd ) ;
extern void ( __attribute__((__leaf__)) closefrom)(int __lowfd ) __attribute__((__nothrow__)) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) read)(int __fd ,
                                                                                                           void *__buf ,
                                                                                                           size_t __nbytes ) __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) write)(int __fd , void const *__buf ,
                                                                size_t __n ) __attribute__((__access__(__read_only__,2,3))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) pread)(int __fd ,
                                                                                                            void *__buf ,
                                                                                                            size_t __nbytes ,
                                                                                                            __off_t __offset ) __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) pwrite)(int __fd , void const *__buf ,
                                                                 size_t __n , __off_t __offset ) __attribute__((__access__(__read_only__,2,3))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) pread64)(int __fd ,
                                                                                                              void *__buf ,
                                                                                                              size_t __nbytes ,
                                                                                                              __off64_t __offset ) __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) pwrite64)(int __fd , void const *__buf ,
                                                                   size_t __n , __off64_t __offset ) __attribute__((__access__(__read_only__,2,3))) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) pipe)(int *__pipedes ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) pipe2)(int *__pipedes ,
                                                                      int __flags ) __attribute__((__nothrow__)) ;
extern unsigned int ( __attribute__((__leaf__)) alarm)(unsigned int __seconds ) __attribute__((__nothrow__)) ;
extern unsigned int sleep(unsigned int __seconds ) ;
extern __useconds_t ( __attribute__((__leaf__)) ualarm)(__useconds_t __value , __useconds_t __interval ) __attribute__((__nothrow__)) ;
extern int usleep(__useconds_t __useconds ) ;
extern int pause(void) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) chown)(char const *__file ,
                                                                                      __uid_t __owner ,
                                                                                      __gid_t __group ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) fchown)(int __fd ,
                                                                       __uid_t __owner ,
                                                                       __gid_t __group ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) lchown)(char const *__file ,
                                                                                       __uid_t __owner ,
                                                                                       __gid_t __group ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(2), __leaf__)) fchownat)(int __fd ,
                                                                                         char const *__file ,
                                                                                         __uid_t __owner ,
                                                                                         __gid_t __group ,
                                                                                         int __flag ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) chdir)(char const *__path ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) fchdir)(int __fd ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) getcwd)(char *__buf , size_t __size ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) get_current_dir_name)(void) __attribute__((__nothrow__)) ;
__inline extern char __attribute__((__deprecated__)) *( __attribute__((__warn_unused_result__,
__nonnull__(1), __leaf__, __artificial__, __always_inline__)) getwd)(char *__buf ) __attribute__((__nothrow__,
__deprecated__, __access__(__write_only__,1))) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) dup)(int __fd ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) dup2)(int __fd , int __fd2 ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) dup3)(int __fd , int __fd2 , int __flags ) __attribute__((__nothrow__)) ;
extern char **__environ ;
extern char **environ ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) execve)(char const *__path ,
                                                                 char **__argv , char **__envp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) fexecve)(int __fd , char **__argv ,
                                                                char **__envp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) execv)(char const *__path ,
                                                                char **__argv ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) execle)(char const *__path ,
                                                                 char const *__arg
                                                                 , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) execl)(char const *__path ,
                                                                char const *__arg
                                                                , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) execvp)(char const *__file ,
                                                                 char **__argv ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) execlp)(char const *__file ,
                                                                 char const *__arg
                                                                 , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1,2), __leaf__)) execvpe)(char const *__file ,
                                                                  char **__argv ,
                                                                  char **__envp ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) nice)(int __inc ) __attribute__((__nothrow__)) ;
extern void _exit(int __status ) __attribute__((__noreturn__)) ;
extern long ( __attribute__((__nonnull__(1), __leaf__)) pathconf)(char const *__path ,
                                                                  int __name ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__leaf__)) fpathconf)(int __fd , int __name ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__leaf__)) sysconf)(int __name ) __attribute__((__nothrow__)) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) confstr)(int __name ,
                                                                                               char *__buf ,
                                                                                               size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern __pid_t ( __attribute__((__leaf__)) getpid)(void) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) getppid)(void) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) getpgrp)(void) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) __getpgid)(__pid_t __pid ) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) getpgid)(__pid_t __pid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) setpgid)(__pid_t __pid , __pid_t __pgid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) setpgrp)(void) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) setsid)(void) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) getsid)(__pid_t __pid ) __attribute__((__nothrow__)) ;
extern __uid_t ( __attribute__((__leaf__)) getuid)(void) __attribute__((__nothrow__)) ;
extern __uid_t ( __attribute__((__leaf__)) geteuid)(void) __attribute__((__nothrow__)) ;
extern __gid_t ( __attribute__((__leaf__)) getgid)(void) __attribute__((__nothrow__)) ;
extern __gid_t ( __attribute__((__leaf__)) getegid)(void) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) getgroups)(int __size , __gid_t *__list ) __attribute__((__nothrow__,
__access__(__write_only__,2,1))) ;
extern int ( __attribute__((__leaf__)) group_member)(__gid_t __gid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) setuid)(__uid_t __uid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) setreuid)(__uid_t __ruid ,
                                                                         __uid_t __euid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) seteuid)(__uid_t __uid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) setgid)(__gid_t __gid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) setregid)(__gid_t __rgid ,
                                                                         __gid_t __egid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) setegid)(__gid_t __gid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) getresuid)(__uid_t *__ruid , __uid_t *__euid ,
                                                  __uid_t *__suid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) getresgid)(__gid_t *__rgid , __gid_t *__egid ,
                                                  __gid_t *__sgid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) setresuid)(__uid_t __ruid ,
                                                                          __uid_t __euid ,
                                                                          __uid_t __suid ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) setresgid)(__gid_t __rgid ,
                                                                          __gid_t __egid ,
                                                                          __gid_t __sgid ) __attribute__((__nothrow__)) ;
extern __pid_t fork(void) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) vfork)(void) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) _Fork)(void) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) ttyname)(int __fd ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(2), __leaf__,
__artificial__, __always_inline__)) ttyname_r)(int __fd , char *__buf , size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern int ( __attribute__((__leaf__)) isatty)(int __fd ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) ttyslot)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1,2), __leaf__)) link)(char const *__from ,
                                                                                       char const *__to ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(2,4), __leaf__)) linkat)(int __fromfd ,
                                                                                         char const *__from ,
                                                                                         int __tofd ,
                                                                                         char const *__to ,
                                                                                         int __flags ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1,2), __leaf__)) symlink)(char const *__from ,
                                                                                          char const *__to ) __attribute__((__nothrow__)) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(1,2),
__leaf__, __artificial__, __always_inline__)) readlink)(char const *__path , char *__buf ,
                                                        size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1,3), __leaf__)) symlinkat)(char const *__from ,
                                                                                            int __tofd ,
                                                                                            char const *__to ) __attribute__((__nothrow__)) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(2,3),
__leaf__, __artificial__, __always_inline__)) readlinkat)(int __fd , char const *__path ,
                                                          char *__buf , size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,3,4))) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) unlink)(char const *__name ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) unlinkat)(int __fd , char const *__name ,
                                                                 int __flag ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) rmdir)(char const *__path ) __attribute__((__nothrow__)) ;
extern __pid_t ( __attribute__((__leaf__)) tcgetpgrp)(int __fd ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) tcsetpgrp)(int __fd , __pid_t __pgrp_id ) __attribute__((__nothrow__)) ;
extern char *getlogin(void) ;
__inline extern int ( __attribute__((__nonnull__(1), __artificial__, __always_inline__)) getlogin_r)(char *__buf ,
                                                                                                     size_t __buflen ) __attribute__((__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) setlogin)(char const *__name ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) gethostname)(char *__buf ,
                                                                                                                size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) sethostname)(char const *__name ,
                                                                                            size_t __len ) __attribute__((__nothrow__,
__access__(__read_only__,1,2))) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) sethostid)(long __id ) __attribute__((__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__,
__artificial__, __always_inline__)) getdomainname)(char *__buf , size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) setdomainname)(char const *__name ,
                                                                                              size_t __len ) __attribute__((__nothrow__,
__access__(__read_only__,1,2))) ;
extern int ( __attribute__((__leaf__)) vhangup)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) revoke)(char const *__file ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) profil)(unsigned short *__sample_buffer ,
                                                               size_t __size , size_t __offset ,
                                                               unsigned int __scale ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) acct)(char const *__name ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__leaf__)) getusershell)(void) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) endusershell)(void) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__leaf__)) setusershell)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) daemon)(int __nochdir ,
                                                                       int __noclose ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) chroot)(char const *__path ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__nonnull__(1))) getpass)(char const *__prompt ) ;
extern int fsync(int __fd ) ;
extern int ( __attribute__((__leaf__)) syncfs)(int __fd ) __attribute__((__nothrow__)) ;
extern long gethostid(void) ;
extern void ( __attribute__((__leaf__)) sync)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) getpagesize)(void) __attribute__((__nothrow__,
__const__)) ;
extern int ( __attribute__((__leaf__)) getdtablesize)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) truncate)(char const *__file ,
                                                                                         __off_t __length ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) truncate64)(char const *__file ,
                                                                                           __off64_t __length ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) ftruncate)(int __fd ,
                                                                          __off_t __length ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) ftruncate64)(int __fd ,
                                                                            __off64_t __length ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) brk)(void *__addr ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__leaf__)) sbrk)(intptr_t __delta ) __attribute__((__nothrow__)) ;
extern long ( __attribute__((__leaf__)) syscall)(long __sysno , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__warn_unused_result__)) lockf)(int __fd , int __cmd ,
                                                            __off_t __len ) ;
extern int ( __attribute__((__warn_unused_result__)) lockf64)(int __fd , int __cmd ,
                                                              __off64_t __len ) ;
extern ssize_t copy_file_range(int __infd , __off64_t *__pinoff , int __outfd , __off64_t *__poutoff ,
                               size_t __length , unsigned int __flags ) ;
extern int fdatasync(int __fildes ) ;
extern char *( __attribute__((__nonnull__(1,2), __leaf__)) crypt)(char const *__key ,
                                                                  char const *__salt ) __attribute__((__nothrow__)) ;
extern void ( __attribute__((__nonnull__(1,2), __leaf__)) swab)(void const *__from ,
                                                                void *__to , ssize_t __n ) __attribute__((__nothrow__,
__access__(__write_only__,2,3), __access__(__read_only__,1,3))) ;
extern int ( __attribute__((__warn_unused_result__)) getentropy)(void *__buffer ,
                                                                 size_t __length ) __attribute__((__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__leaf__)) close_range)(unsigned int __fd , unsigned int __max_fd ,
                                                    int __flags ) __attribute__((__nothrow__)) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __read_chk)(int __fd , void *__buf ,
                                                                     size_t __nbytes ,
                                                                     size_t __buflen ) __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __read_alias)(int __fd ,
                                                                       void *__buf ,
                                                                       size_t __nbytes ) __asm__("read") __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __read_chk_warn)(int __fd ,
                                                                          void *__buf ,
                                                                          size_t __nbytes ,
                                                                          size_t __buflen ) __asm__("__read_chk") __attribute__((__warning__("read called with bigger length than size of the destination buffer"))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) read)(int __fd ,
                                                                                                           void *__buf ,
                                                                                                           size_t __nbytes ) __attribute__((__access__(__write_only__,2,3))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) read)(int __fd ,
                                                                                                           void *__buf ,
                                                                                                           size_t __nbytes )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  ssize_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  ssize_t tmp___5 ;
  unsigned long tmp___6 ;
  ssize_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size(__buf, 0);
  tmp___7 = __read_chk(__fd, __buf, __nbytes, tmp___6);
  return (tmp___7);
}
}
extern ssize_t ( __attribute__((__warn_unused_result__)) __pread_chk)(int __fd , void *__buf ,
                                                                      size_t __nbytes ,
                                                                      __off_t __offset ,
                                                                      size_t __bufsize ) __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __pread64_chk)(int __fd ,
                                                                        void *__buf ,
                                                                        size_t __nbytes ,
                                                                        __off64_t __offset ,
                                                                        size_t __bufsize ) __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __pread_alias)(int __fd ,
                                                                        void *__buf ,
                                                                        size_t __nbytes ,
                                                                        __off_t __offset ) __asm__("pread") __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __pread64_alias)(int __fd ,
                                                                          void *__buf ,
                                                                          size_t __nbytes ,
                                                                          __off64_t __offset ) __asm__("pread64") __attribute__((__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __pread_chk_warn)(int __fd ,
                                                                           void *__buf ,
                                                                           size_t __nbytes ,
                                                                           __off_t __offset ,
                                                                           size_t __bufsize ) __asm__("__pread_chk") __attribute__((__warning__("pread called with bigger length than size of the destination buffer"))) ;
extern ssize_t ( __attribute__((__warn_unused_result__)) __pread64_chk_warn)(int __fd ,
                                                                             void *__buf ,
                                                                             size_t __nbytes ,
                                                                             __off64_t __offset ,
                                                                             size_t __bufsize ) __asm__("__pread64_chk") __attribute__((__warning__("pread64 called with bigger length than size of the destination buffer"))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) pread)(int __fd ,
                                                                                                            void *__buf ,
                                                                                                            size_t __nbytes ,
                                                                                                            __off_t __offset ) __attribute__((__access__(__write_only__,2,3))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) pread)(int __fd ,
                                                                                                            void *__buf ,
                                                                                                            size_t __nbytes ,
                                                                                                            __off_t __offset )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  ssize_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  ssize_t tmp___5 ;
  unsigned long tmp___6 ;
  ssize_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size(__buf, 0);
  tmp___7 = __pread_chk(__fd, __buf, __nbytes, __offset, tmp___6);
  return (tmp___7);
}
}
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) pread64)(int __fd ,
                                                                                                              void *__buf ,
                                                                                                              size_t __nbytes ,
                                                                                                              __off64_t __offset ) __attribute__((__access__(__write_only__,2,3))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __artificial__, __always_inline__)) pread64)(int __fd ,
                                                                                                              void *__buf ,
                                                                                                              size_t __nbytes ,
                                                                                                              __off64_t __offset )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  ssize_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  ssize_t tmp___5 ;
  unsigned long tmp___6 ;
  ssize_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size(__buf, 0);
  tmp___7 = __pread64_chk(__fd, __buf, __nbytes, __offset, tmp___6);
  return (tmp___7);
}
}
extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(1,2), __leaf__)) __readlink_chk)(char const *__path ,
                                                                                                     char *__buf ,
                                                                                                     size_t __len ,
                                                                                                     size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(1,2), __leaf__)) __readlink_alias)(char const *__path ,
                                                                                                       char *__buf ,
                                                                                                       size_t __len ) __asm__("readlink") __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(1,2), __leaf__)) __readlink_chk_warn)(char const *__path ,
                                                                                                          char *__buf ,
                                                                                                          size_t __len ,
                                                                                                          size_t __buflen ) __asm__("__readlink_chk") __attribute__((__warning__("readlink called with bigger length than size of destination buffer"),
__nothrow__)) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(1,2),
__leaf__, __artificial__, __always_inline__)) readlink)(char const *__path , char *__buf ,
                                                        size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(1,2),
__leaf__, __artificial__, __always_inline__)) readlink)(char const *__path , char *__buf ,
                                                        size_t __len )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  ssize_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  ssize_t tmp___5 ;
  unsigned long tmp___6 ;
  ssize_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __readlink_chk((char const * __restrict )__path, (char * __restrict )__buf,
                           __len, tmp___6);
  return (tmp___7);
}
}
extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(2,3), __leaf__)) __readlinkat_chk)(int __fd ,
                                                                                                       char const *__path ,
                                                                                                       char *__buf ,
                                                                                                       size_t __len ,
                                                                                                       size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,3,4))) ;
extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(2,3), __leaf__)) __readlinkat_alias)(int __fd ,
                                                                                                         char const *__path ,
                                                                                                         char *__buf ,
                                                                                                         size_t __len ) __asm__("readlinkat") __attribute__((__nothrow__,
__access__(__write_only__,3,4))) ;
extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(2,3), __leaf__)) __readlinkat_chk_warn)(int __fd ,
                                                                                                            char const *__path ,
                                                                                                            char *__buf ,
                                                                                                            size_t __len ,
                                                                                                            size_t __buflen ) __asm__("__readlinkat_chk") __attribute__((__warning__("readlinkat called with bigger length than size of destination buffer"),
__nothrow__)) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(2,3),
__leaf__, __artificial__, __always_inline__)) readlinkat)(int __fd , char const *__path ,
                                                          char *__buf , size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,3,4))) ;
__inline extern ssize_t ( __attribute__((__warn_unused_result__, __nonnull__(2,3),
__leaf__, __artificial__, __always_inline__)) readlinkat)(int __fd , char const *__path ,
                                                          char *__buf , size_t __len )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  ssize_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  ssize_t tmp___5 ;
  unsigned long tmp___6 ;
  ssize_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __readlinkat_chk(__fd, (char const * __restrict )__path, (char * __restrict )__buf,
                             __len, tmp___6);
  return (tmp___7);
}
}
extern char *( __attribute__((__warn_unused_result__, __leaf__)) __getcwd_chk)(char *__buf ,
                                                                               size_t __size ,
                                                                               size_t __buflen ) __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) __getcwd_alias)(char *__buf ,
                                                                                 size_t __size ) __asm__("getcwd") __attribute__((__nothrow__)) ;
extern char *( __attribute__((__warn_unused_result__, __leaf__)) __getcwd_chk_warn)(char *__buf ,
                                                                                    size_t __size ,
                                                                                    size_t __buflen ) __asm__("__getcwd_chk") __attribute__((__warning__("getcwd caller with bigger length than size of destination buffer"),
__nothrow__)) ;
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) getcwd)(char *__buf , size_t __size ) __attribute__((__nothrow__)) ;
__inline extern char *( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) getcwd)(char *__buf , size_t __size )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  char *tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  char *tmp___5 ;
  unsigned long tmp___6 ;
  char *tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __getcwd_chk(__buf, __size, tmp___6);
  return (tmp___7);
}
}
extern char *( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) __getwd_chk)(char *__buf ,
                                                                                              size_t buflen ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern char *( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) __getwd_warn)(char *__buf ) __asm__("getwd") __attribute__((__warning__("please use getcwd instead, as getwd doesn\'t specify buffer size"),
__nothrow__)) ;
__inline extern char __attribute__((__deprecated__)) *( __attribute__((__warn_unused_result__,
__nonnull__(1), __leaf__, __artificial__, __always_inline__)) getwd)(char *__buf ) __attribute__((__nothrow__,
__deprecated__, __access__(__write_only__,1))) ;
__inline extern char __attribute__((__deprecated__)) *( __attribute__((__warn_unused_result__,
__nonnull__(1), __leaf__, __artificial__, __always_inline__)) getwd)(char *__buf )
{
  unsigned long tmp ;
  char *tmp___0 ;
  unsigned long tmp___1 ;
  char *tmp___2 ;
  {
  tmp___1 = __builtin_object_size((void *)__buf, 1);
  if (tmp___1 != 18446744073709551615UL) {
    tmp = __builtin_object_size((void *)__buf, 1);
    tmp___0 = __getwd_chk(__buf, tmp);
    return ((char __attribute__((__deprecated__)) *)tmp___0);
  }
  tmp___2 = __getwd_warn(__buf);
  return ((char __attribute__((__deprecated__)) *)tmp___2);
}
}
extern size_t ( __attribute__((__leaf__)) __confstr_chk)(int __name , char *__buf ,
                                                         size_t __len , size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern size_t ( __attribute__((__leaf__)) __confstr_alias)(int __name , char *__buf ,
                                                           size_t __len ) __asm__("confstr") __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern size_t ( __attribute__((__leaf__)) __confstr_chk_warn)(int __name , char *__buf ,
                                                              size_t __len , size_t __buflen ) __asm__("__confstr_chk") __attribute__((__warning__("confstr called with bigger length than size of destination buffer"),
__nothrow__)) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) confstr)(int __name ,
                                                                                               char *__buf ,
                                                                                               size_t __len ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
__inline extern size_t ( __attribute__((__leaf__, __artificial__, __always_inline__)) confstr)(int __name ,
                                                                                               char *__buf ,
                                                                                               size_t __len )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  size_t tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  size_t tmp___5 ;
  unsigned long tmp___6 ;
  size_t tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __confstr_chk(__name, __buf, __len, tmp___6);
  return (tmp___7);
}
}
extern int ( __attribute__((__warn_unused_result__, __leaf__)) __getgroups_chk)(int __size ,
                                                                                __gid_t *__list ,
                                                                                size_t __listlen ) __attribute__((__nothrow__,
__access__(__write_only__,2,1))) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) __getgroups_alias)(int __size ,
                                                                                  __gid_t *__list ) __asm__("getgroups") __attribute__((__nothrow__,
__access__(__write_only__,2,1))) ;
extern int ( __attribute__((__warn_unused_result__, __leaf__)) __getgroups_chk_warn)(int __size ,
                                                                                     __gid_t *__list ,
                                                                                     size_t __listlen ) __asm__("__getgroups_chk") __attribute__((__warning__("getgroups called with bigger group count than what can fit into destination buffer"),
__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) getgroups)(int __size , __gid_t *__list ) __attribute__((__nothrow__,
__access__(__write_only__,2,1))) ;
__inline extern int ( __attribute__((__warn_unused_result__, __leaf__, __artificial__,
__always_inline__)) getgroups)(int __size , __gid_t *__list )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  int tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  int tmp___5 ;
  unsigned long tmp___6 ;
  int tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__list, 1);
  tmp___7 = __getgroups_chk(__size, __list, tmp___6);
  return (tmp___7);
}
}
extern int ( __attribute__((__nonnull__(2), __leaf__)) __ttyname_r_chk)(int __fd ,
                                                                        char *__buf ,
                                                                        size_t __buflen ,
                                                                        size_t __nreal ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) __ttyname_r_alias)(int __fd ,
                                                                          char *__buf ,
                                                                          size_t __buflen ) __asm__("ttyname_r") __attribute__((__nothrow__)) ;
extern int ( __attribute__((__nonnull__(2), __leaf__)) __ttyname_r_chk_warn)(int __fd ,
                                                                             char *__buf ,
                                                                             size_t __buflen ,
                                                                             size_t __nreal ) __asm__("__ttyname_r_chk") __attribute__((__warning__("ttyname_r called with bigger buflen than size of destination buffer"),
__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(2), __leaf__,
__artificial__, __always_inline__)) ttyname_r)(int __fd , char *__buf , size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,2,3))) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(2), __leaf__,
__artificial__, __always_inline__)) ttyname_r)(int __fd , char *__buf , size_t __buflen )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  int tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  int tmp___5 ;
  unsigned long tmp___6 ;
  int tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __ttyname_r_chk(__fd, __buf, __buflen, tmp___6);
  return (tmp___7);
}
}
extern int ( __attribute__((__nonnull__(1))) __getlogin_r_chk)(char *__buf , size_t __buflen ,
                                                               size_t __nreal ) __attribute__((__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__nonnull__(1))) __getlogin_r_alias)(char *__buf , size_t __buflen ) __asm__("getlogin_r") ;
extern int ( __attribute__((__nonnull__(1))) __getlogin_r_chk_warn)(char *__buf ,
                                                                    size_t __buflen ,
                                                                    size_t __nreal ) __asm__("__getlogin_r_chk") __attribute__((__warning__("getlogin_r called with bigger buflen than size of destination buffer"))) ;
__inline extern int ( __attribute__((__nonnull__(1), __artificial__, __always_inline__)) getlogin_r)(char *__buf ,
                                                                                                     size_t __buflen ) __attribute__((__access__(__write_only__,1,2))) ;
__inline extern int ( __attribute__((__nonnull__(1), __artificial__, __always_inline__)) getlogin_r)(char *__buf ,
                                                                                                     size_t __buflen )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  int tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  int tmp___5 ;
  unsigned long tmp___6 ;
  int tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __getlogin_r_chk(__buf, __buflen, tmp___6);
  return (tmp___7);
}
}
extern int ( __attribute__((__nonnull__(1), __leaf__)) __gethostname_chk)(char *__buf ,
                                                                          size_t __buflen ,
                                                                          size_t __nreal ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) __gethostname_alias)(char *__buf ,
                                                                            size_t __buflen ) __asm__("gethostname") __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__nonnull__(1), __leaf__)) __gethostname_chk_warn)(char *__buf ,
                                                                               size_t __buflen ,
                                                                               size_t __nreal ) __asm__("__gethostname_chk") __attribute__((__warning__("gethostname called with bigger buflen than size of destination buffer"),
__nothrow__)) ;
__inline extern int ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) gethostname)(char *__buf ,
                                                                                                                size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
__inline extern int ( __attribute__((__nonnull__(1), __leaf__, __artificial__, __always_inline__)) gethostname)(char *__buf ,
                                                                                                                size_t __buflen )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  int tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  int tmp___5 ;
  unsigned long tmp___6 ;
  int tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __gethostname_chk(__buf, __buflen, tmp___6);
  return (tmp___7);
}
}
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) __getdomainname_chk)(char *__buf ,
                                                                                                    size_t __buflen ,
                                                                                                    size_t __nreal ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) __getdomainname_alias)(char *__buf ,
                                                                                                      size_t __buflen ) __asm__("getdomainname") __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__)) __getdomainname_chk_warn)(char *__buf ,
                                                                                                         size_t __buflen ,
                                                                                                         size_t __nreal ) __asm__("__getdomainname_chk") __attribute__((__warning__("getdomainname called with bigger buflen than size of destination buffer"),
__nothrow__)) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__,
__artificial__, __always_inline__)) getdomainname)(char *__buf , size_t __buflen ) __attribute__((__nothrow__,
__access__(__write_only__,1,2))) ;
__inline extern int ( __attribute__((__warn_unused_result__, __nonnull__(1), __leaf__,
__artificial__, __always_inline__)) getdomainname)(char *__buf , size_t __buflen )
{
  unsigned long tmp ;
  unsigned long tmp___0 ;
  int tmp___1 ;
  unsigned long tmp___2 ;
  unsigned long tmp___3 ;
  unsigned long tmp___4 ;
  int tmp___5 ;
  unsigned long tmp___6 ;
  int tmp___7 ;
  {
  tmp___6 = __builtin_object_size((void *)__buf, 1);
  tmp___7 = __getdomainname_chk(__buf, __buflen, tmp___6);
  return (tmp___7);
}
}
extern __pid_t ( __attribute__((__leaf__)) gettid)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sigaltstack)(stack_t const * __restrict __ss ,
                                                    stack_t * __restrict __oss ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) sigstack)(struct sigstack *__ss , struct sigstack *__oss ) __attribute__((__nothrow__,
__deprecated__)) ;
extern int ( __attribute__((__leaf__)) sighold)(int __sig ) __attribute__((__nothrow__,
__deprecated__("Use the sigprocmask function instead"))) ;
extern int ( __attribute__((__leaf__)) sigrelse)(int __sig ) __attribute__((__nothrow__,
__deprecated__("Use the sigprocmask function instead"))) ;
extern int ( __attribute__((__leaf__)) sigignore)(int __sig ) __attribute__((__nothrow__,
__deprecated__("Use the signal function instead"))) ;
extern __sighandler_t ( __attribute__((__leaf__)) sigset)(int __sig , void (*__disp)(int ) ) __attribute__((__nothrow__,
__deprecated__("Use the signal and sigprocmask functions instead"))) ;
extern int ( __attribute__((__leaf__)) pthread_sigmask)(int __how , __sigset_t const * __restrict __newmask ,
                                                        __sigset_t * __restrict __oldmask ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_kill)(pthread_t __threadid , int __signo ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pthread_sigqueue)(pthread_t __threadid , int __signo ,
                                                         union sigval const __value ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) __libc_current_sigrtmin)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) __libc_current_sigrtmax)(void) __attribute__((__nothrow__)) ;
extern int tgkill(__pid_t __tgid , __pid_t __tid , int __signal ) ;
lang_spec_t langs[138] ;
size_t get_lang_count(void) ;
char *make_lang_regex(char *ext_array , size_t num_exts ) ;
size_t combine_file_extensions(size_t *extension_index , size_t len , char **exts ) ;
cli_options opts ;
void print_init_context(void) ;
void print_cleanup_context(void) ;
void print_context_append(char const *line , size_t len ) ;
void print_trailing_context(char const *path , char const *buf , size_t n ) ;
void print_path(char const *path , char const sep ) ;
void print_path_count(char const *path , char const sep , size_t const count ) ;
void print_line(char const *buf , size_t buf_pos , size_t prev_line_offset ) ;
void print_binary_file_matches(char const *path ) ;
void print_file_matches(char const *path , char const *buf , size_t const buf_len ,
                        match_t const *matches , size_t const matches_len ) ;
void print_line_number(size_t line , char const sep ) ;
void print_column_number(match_t const *matches , size_t last_printed_match , size_t prev_line_offset ,
                         char const sep ) ;
void print_file_separator(void) ;
char const *normalize_path(char const *path ) ;
char const *color_line_number = (char const *)"\033[1;33m";
char const *color_match = (char const *)"\033[30;43m";
char const *color_path = (char const *)"\033[1;32m";
void usage(void)
{
  {
  printf((char const *)"\n");
  printf((char const *)"Usage: ag [FILE-TYPE] [OPTIONS] PATTERN [PATH]\n\n");
  printf((char const *)"  Recursively search for PATTERN in PATH.\n");
  printf((char const *)"  Like grep or ack, but faster.\n\n");
  printf((char const *)"Example:\n  ag -i foo /bar/\n\n");
  printf((char const *)"Output Options:\n     --ackmate            Print results in AckMate-parseable format\n  -A --after [LINES]      Print lines after match (Default: 2)\n  -B --before [LINES]     Print lines before match (Default: 2)\n     --[no]break          Print newlines between matches in different files\n                          (Enabled by default)\n  -c --count              Only print the number of matches in each file.\n                          (This often differs from the number of matching lines)\n     --[no]color          Print color codes in results (Enabled by default)\n     --color-line-number  Color codes for line numbers (Default: 1;33)\n     --color-match        Color codes for result match numbers (Default: 30;43)\n     --color-path         Color codes for path names (Default: 1;32)\n");
  printf((char const *)"     --column             Print column numbers in results\n     --[no]filename       Print file names (Enabled unless searching a single file)\n  -H --[no]heading        Print file names before each file\'s matches\n                          (Enabled by default)\n  -C --context [LINES]    Print lines before and after matches (Default: 2)\n     --[no]group          Same as --[no]break --[no]heading\n  -g --filename-pattern PATTERN\n                          Print filenames matching PATTERN\n  -l --files-with-matches Only print filenames that contain matches\n                          (don\'t print the matching lines)\n  -L --files-without-matches\n                          Only print filenames that don\'t contain matches\n     --print-all-files    Print headings for all files searched, even those that\n                          don\'t contain matches\n     --[no]numbers        Print line numbers. Default is to omit line numbers\n                          when searching streams\n  -o --only-matching      Prints only the matching part of the lines\n     --print-long-lines   Print matches on very long lines (Default: >2k characters)\n     --passthrough        When searching a stream, print all lines even if they\n                          don\'t match\n     --silent             Suppress all log messages, including errors\n     --stats              Print stats (files scanned, time taken, etc.)\n     --stats-only         Print stats and nothing else.\n                          (Same as --count when searching a single file)\n     --vimgrep            Print results like vim\'s :vimgrep /pattern/g would\n                          (it reports every match on the line)\n  -0 --null --print0      Separate filenames with null (for \'xargs -0\')\n\nSearch Options:\n  -a --all-types          Search all files (doesn\'t include hidden files\n                          or patterns from ignore files)\n  -D --debug              Ridiculous debugging (probably not useful)\n     --depth NUM          Search up to NUM directories deep (Default: 25)\n  -f --follow             Follow symlinks\n  -F --fixed-strings      Alias for --literal for compatibility with grep\n  -G --file-search-regex  PATTERN Limit search to filenames matching PATTERN\n     --hidden             Search hidden files (obeys .*ignore files)\n  -i --ignore-case        Match case insensitively\n     --ignore PATTERN     Ignore files/directories matching PATTERN\n                          (literal file/directory names also allowed)\n     --ignore-dir NAME    Alias for --ignore for compatibility with ack.\n  -m --max-count NUM      Skip the rest of a file after NUM matches (Default: 10,000)\n     --one-device         Don\'t follow links to other devices.\n  -p --path-to-ignore STRING\n                          Use .ignore file at STRING\n  -Q --literal            Don\'t parse PATTERN as a regular expression\n  -s --case-sensitive     Match case sensitively\n  -S --smart-case         Match case insensitively unless PATTERN contains\n                          uppercase characters (Enabled by default)\n     --search-binary      Search binary files for matches\n  -t --all-text           Search all text files (doesn\'t include hidden files)\n  -u --unrestricted       Search all files (ignore .ignore, .gitignore, etc.;\n                          searches binary and hidden files as well)\n  -U --skip-vcs-ignores   Ignore VCS ignore files\n                          (.gitignore, .hgignore; still obey .ignore)\n  -v --invert-match\n  -w --word-regexp        Only match whole words\n  -W --width NUM          Truncate match lines after NUM characters\n  -z --search-zip         Search contents of compressed (e.g., gzip) files\n\n");
  printf((char const *)"File Types:\nThe search can be restricted to certain types of files. Example:\n  ag --html needle\n  - Searches for \'needle\' in files with suffix .htm, .html, .shtml or .xhtml.\n\nFor a list of supported file types run:\n  ag --list-file-types\n\nag was originally created by Geoff Greer. More information (and the latest release)\ncan be found at http://geoff.greer.fm/ag\n");
  return;
}
}
void print_version(void)
{
  char jit ;
  char lzma ;
  char zlib ;
  {
  jit = (char )'-';
  lzma = (char )'-';
  zlib = (char )'-';
  jit = (char )'+';
  lzma = (char )'+';
  zlib = (char )'+';
  printf((char const *)"ag version %s\n\n", "2.2.0");
  printf((char const *)"Features:\n");
  printf((char const *)"  %cjit %clzma %czlib\n", (int )jit, (int )lzma, (int )zlib);
  return;
}
}
void init_options(void)
{
  char *term ;
  char *tmp ;
  int tmp___0 ;
  {
  tmp = getenv((char const *)"TERM");
  term = tmp;
  memset((void *)(& opts), 0, sizeof(opts));
  opts.casing = (enum case_behavior )0;
  opts.color = 1;
  if (term) {
    tmp___0 = strcmp((char const *)term, (char const *)"dumb");
    if (! tmp___0) {
      opts.color = 0;
    }
  }
  opts.color_win_ansi = 0;
  opts.max_matches_per_file = (size_t )0;
  opts.max_search_depth = 25;
  opts.mmap = 1;
  opts.multiline = 1;
  opts.width = (size_t )0;
  opts.path_sep = (char )'\n';
  opts.print_break = 1;
  opts.print_path = 0;
  opts.print_all_paths = 0;
  opts.print_line_numbers = 1;
  opts.recurse_dirs = 1;
  opts.color_path = ag_strdup(color_path);
  opts.color_match = ag_strdup(color_match);
  opts.color_line_number = ag_strdup(color_line_number);
  opts.use_thread_affinity = 1;
  return;
}
}
void cleanup_options(void)
{
  {
  free((void *)opts.color_path);
  free((void *)opts.color_match);
  free((void *)opts.color_line_number);
  if (opts.query) {
    free((void *)opts.query);
  }
  (*pcre_free)((void *)opts.re);
  if (opts.re_extra) {
    (*pcre_free)((void *)opts.re_extra);
  }
  if (opts.ackmate_dir_filter) {
    (*pcre_free)((void *)opts.ackmate_dir_filter);
  }
  if (opts.ackmate_dir_filter_extra) {
    (*pcre_free)((void *)opts.ackmate_dir_filter_extra);
  }
  if (opts.file_search_regex) {
    (*pcre_free)((void *)opts.file_search_regex);
  }
  if (opts.file_search_regex_extra) {
    (*pcre_free)((void *)opts.file_search_regex_extra);
  }
  return;
}
}
void parse_options(int argc , char **argv , char ***base_paths , char ***paths )
{
  int ch ;
  size_t i ;
  int path_len ;
  int base_path_len ;
  int useless ;
  int group ;
  int help ;
  int version ;
  int list_file_types ;
  int opt_index ;
  char *num_end ;
  char const *home_dir ;
  char *tmp ;
  char *ignore_file_path ;
  int accepts_query ;
  int needs_query ;
  struct stat statbuf ;
  int rv ;
  size_t lang_count ;
  size_t lang_num ;
  int has_filetype ;
  size_t longopts_len ;
  size_t full_len ;
  option_t *longopts ;
  char *lang_regex ;
  size_t *ext_index ;
  char *extensions ;
  size_t num_exts ;
  option_t base_longopts[92] ;
  void *tmp___0 ;
  void *tmp___1 ;
  option_t opt ;
  option_t __constr_expr_0 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  char *file_search_regex ;
  long tmp___6 ;
  int *tmp___7 ;
  long tmp___8 ;
  int *tmp___9 ;
  long tmp___10 ;
  int *tmp___11 ;
  int tmp___12 ;
  long tmp___13 ;
  int *tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  int tmp___28 ;
  int tmp___29 ;
  int tmp___30 ;
  int tmp___31 ;
  size_t tmp___32 ;
  int tmp___33 ;
  int pcre_opts ;
  int tmp___34 ;
  char *old_file_search_regex ;
  size_t lang_index ;
  int j ;
  FILE *gitconfig_file ;
  size_t buf_len ;
  char *gitconfig_res ;
  void *tmp___35 ;
  size_t tmp___36 ;
  int tmp___37 ;
  char const *config_home ;
  char *tmp___38 ;
  size_t tmp___39 ;
  size_t tmp___40 ;
  int tmp___41 ;
  char *path ;
  char *base_path ;
  char *tmp___42 ;
  void *tmp___43 ;
  void *tmp___44 ;
  size_t tmp___45 ;
  void *tmp___46 ;
  size_t tmp___47 ;
  void *tmp___48 ;
  void *tmp___49 ;
  void *tmp___50 ;
  void *tmp___51 ;
  {
  path_len = 0;
  base_path_len = 0;
  useless = 0;
  group = 1;
  help = 0;
  version = 0;
  list_file_types = 0;
  opt_index = 0;
  tmp = getenv((char const *)"HOME");
  home_dir = (char const *)tmp;
  ignore_file_path = (char *)((void *)0);
  accepts_query = 1;
  needs_query = 1;
  lang_num = (size_t )0;
  has_filetype = 0;
  lang_regex = (char *)((void *)0);
  ext_index = (size_t *)((void *)0);
  extensions = (char *)((void *)0);
  num_exts = (size_t )0;
  init_options();
  base_longopts[0].name = (char const *)"ackmate";
  base_longopts[0].has_arg = 0;
  base_longopts[0].flag = & opts.ackmate;
  base_longopts[0].val = 1;
  base_longopts[1].name = (char const *)"ackmate-dir-filter";
  base_longopts[1].has_arg = 1;
  base_longopts[1].flag = (int *)((void *)0);
  base_longopts[1].val = 0;
  base_longopts[2].name = (char const *)"affinity";
  base_longopts[2].has_arg = 0;
  base_longopts[2].flag = & opts.use_thread_affinity;
  base_longopts[2].val = 1;
  base_longopts[3].name = (char const *)"after";
  base_longopts[3].has_arg = 2;
  base_longopts[3].flag = (int *)((void *)0);
  base_longopts[3].val = 'A';
  base_longopts[4].name = (char const *)"all-text";
  base_longopts[4].has_arg = 0;
  base_longopts[4].flag = (int *)((void *)0);
  base_longopts[4].val = 't';
  base_longopts[5].name = (char const *)"all-types";
  base_longopts[5].has_arg = 0;
  base_longopts[5].flag = (int *)((void *)0);
  base_longopts[5].val = 'a';
  base_longopts[6].name = (char const *)"before";
  base_longopts[6].has_arg = 2;
  base_longopts[6].flag = (int *)((void *)0);
  base_longopts[6].val = 'B';
  base_longopts[7].name = (char const *)"break";
  base_longopts[7].has_arg = 0;
  base_longopts[7].flag = & opts.print_break;
  base_longopts[7].val = 1;
  base_longopts[8].name = (char const *)"case-sensitive";
  base_longopts[8].has_arg = 0;
  base_longopts[8].flag = (int *)((void *)0);
  base_longopts[8].val = 's';
  base_longopts[9].name = (char const *)"color";
  base_longopts[9].has_arg = 0;
  base_longopts[9].flag = & opts.color;
  base_longopts[9].val = 1;
  base_longopts[10].name = (char const *)"color-line-number";
  base_longopts[10].has_arg = 1;
  base_longopts[10].flag = (int *)((void *)0);
  base_longopts[10].val = 0;
  base_longopts[11].name = (char const *)"color-match";
  base_longopts[11].has_arg = 1;
  base_longopts[11].flag = (int *)((void *)0);
  base_longopts[11].val = 0;
  base_longopts[12].name = (char const *)"color-path";
  base_longopts[12].has_arg = 1;
  base_longopts[12].flag = (int *)((void *)0);
  base_longopts[12].val = 0;
  base_longopts[13].name = (char const *)"color-win-ansi";
  base_longopts[13].has_arg = 0;
  base_longopts[13].flag = & opts.color_win_ansi;
  base_longopts[13].val = 1;
  base_longopts[14].name = (char const *)"column";
  base_longopts[14].has_arg = 0;
  base_longopts[14].flag = & opts.column;
  base_longopts[14].val = 1;
  base_longopts[15].name = (char const *)"context";
  base_longopts[15].has_arg = 2;
  base_longopts[15].flag = (int *)((void *)0);
  base_longopts[15].val = 'C';
  base_longopts[16].name = (char const *)"count";
  base_longopts[16].has_arg = 0;
  base_longopts[16].flag = (int *)((void *)0);
  base_longopts[16].val = 'c';
  base_longopts[17].name = (char const *)"debug";
  base_longopts[17].has_arg = 0;
  base_longopts[17].flag = (int *)((void *)0);
  base_longopts[17].val = 'D';
  base_longopts[18].name = (char const *)"depth";
  base_longopts[18].has_arg = 1;
  base_longopts[18].flag = (int *)((void *)0);
  base_longopts[18].val = 0;
  base_longopts[19].name = (char const *)"filename";
  base_longopts[19].has_arg = 0;
  base_longopts[19].flag = (int *)((void *)0);
  base_longopts[19].val = 0;
  base_longopts[20].name = (char const *)"filename-pattern";
  base_longopts[20].has_arg = 1;
  base_longopts[20].flag = (int *)((void *)0);
  base_longopts[20].val = 'g';
  base_longopts[21].name = (char const *)"file-search-regex";
  base_longopts[21].has_arg = 1;
  base_longopts[21].flag = (int *)((void *)0);
  base_longopts[21].val = 'G';
  base_longopts[22].name = (char const *)"files-with-matches";
  base_longopts[22].has_arg = 0;
  base_longopts[22].flag = (int *)((void *)0);
  base_longopts[22].val = 'l';
  base_longopts[23].name = (char const *)"files-without-matches";
  base_longopts[23].has_arg = 0;
  base_longopts[23].flag = (int *)((void *)0);
  base_longopts[23].val = 'L';
  base_longopts[24].name = (char const *)"fixed-strings";
  base_longopts[24].has_arg = 0;
  base_longopts[24].flag = (int *)((void *)0);
  base_longopts[24].val = 'F';
  base_longopts[25].name = (char const *)"follow";
  base_longopts[25].has_arg = 0;
  base_longopts[25].flag = & opts.follow_symlinks;
  base_longopts[25].val = 1;
  base_longopts[26].name = (char const *)"group";
  base_longopts[26].has_arg = 0;
  base_longopts[26].flag = & group;
  base_longopts[26].val = 1;
  base_longopts[27].name = (char const *)"heading";
  base_longopts[27].has_arg = 0;
  base_longopts[27].flag = & opts.print_path;
  base_longopts[27].val = 2;
  base_longopts[28].name = (char const *)"help";
  base_longopts[28].has_arg = 0;
  base_longopts[28].flag = (int *)((void *)0);
  base_longopts[28].val = 'h';
  base_longopts[29].name = (char const *)"hidden";
  base_longopts[29].has_arg = 0;
  base_longopts[29].flag = & opts.search_hidden_files;
  base_longopts[29].val = 1;
  base_longopts[30].name = (char const *)"ignore";
  base_longopts[30].has_arg = 1;
  base_longopts[30].flag = (int *)((void *)0);
  base_longopts[30].val = 0;
  base_longopts[31].name = (char const *)"ignore-case";
  base_longopts[31].has_arg = 0;
  base_longopts[31].flag = (int *)((void *)0);
  base_longopts[31].val = 'i';
  base_longopts[32].name = (char const *)"ignore-dir";
  base_longopts[32].has_arg = 1;
  base_longopts[32].flag = (int *)((void *)0);
  base_longopts[32].val = 0;
  base_longopts[33].name = (char const *)"invert-match";
  base_longopts[33].has_arg = 0;
  base_longopts[33].flag = (int *)((void *)0);
  base_longopts[33].val = 'v';
  base_longopts[34].name = (char const *)"line-numbers";
  base_longopts[34].has_arg = 0;
  base_longopts[34].flag = & opts.print_line_numbers;
  base_longopts[34].val = 2;
  base_longopts[35].name = (char const *)"list-file-types";
  base_longopts[35].has_arg = 0;
  base_longopts[35].flag = & list_file_types;
  base_longopts[35].val = 1;
  base_longopts[36].name = (char const *)"literal";
  base_longopts[36].has_arg = 0;
  base_longopts[36].flag = (int *)((void *)0);
  base_longopts[36].val = 'Q';
  base_longopts[37].name = (char const *)"match";
  base_longopts[37].has_arg = 0;
  base_longopts[37].flag = & useless;
  base_longopts[37].val = 0;
  base_longopts[38].name = (char const *)"max-count";
  base_longopts[38].has_arg = 1;
  base_longopts[38].flag = (int *)((void *)0);
  base_longopts[38].val = 'm';
  base_longopts[39].name = (char const *)"mmap";
  base_longopts[39].has_arg = 0;
  base_longopts[39].flag = & opts.mmap;
  base_longopts[39].val = 1;
  base_longopts[40].name = (char const *)"multiline";
  base_longopts[40].has_arg = 0;
  base_longopts[40].flag = & opts.multiline;
  base_longopts[40].val = 1;
  base_longopts[41].name = (char const *)"no-affinity";
  base_longopts[41].has_arg = 0;
  base_longopts[41].flag = & opts.use_thread_affinity;
  base_longopts[41].val = 0;
  base_longopts[42].name = (char const *)"noaffinity";
  base_longopts[42].has_arg = 0;
  base_longopts[42].flag = & opts.use_thread_affinity;
  base_longopts[42].val = 0;
  base_longopts[43].name = (char const *)"no-break";
  base_longopts[43].has_arg = 0;
  base_longopts[43].flag = & opts.print_break;
  base_longopts[43].val = 0;
  base_longopts[44].name = (char const *)"nobreak";
  base_longopts[44].has_arg = 0;
  base_longopts[44].flag = & opts.print_break;
  base_longopts[44].val = 0;
  base_longopts[45].name = (char const *)"no-color";
  base_longopts[45].has_arg = 0;
  base_longopts[45].flag = & opts.color;
  base_longopts[45].val = 0;
  base_longopts[46].name = (char const *)"nocolor";
  base_longopts[46].has_arg = 0;
  base_longopts[46].flag = & opts.color;
  base_longopts[46].val = 0;
  base_longopts[47].name = (char const *)"no-filename";
  base_longopts[47].has_arg = 0;
  base_longopts[47].flag = (int *)((void *)0);
  base_longopts[47].val = 0;
  base_longopts[48].name = (char const *)"nofilename";
  base_longopts[48].has_arg = 0;
  base_longopts[48].flag = (int *)((void *)0);
  base_longopts[48].val = 0;
  base_longopts[49].name = (char const *)"no-follow";
  base_longopts[49].has_arg = 0;
  base_longopts[49].flag = & opts.follow_symlinks;
  base_longopts[49].val = 0;
  base_longopts[50].name = (char const *)"nofollow";
  base_longopts[50].has_arg = 0;
  base_longopts[50].flag = & opts.follow_symlinks;
  base_longopts[50].val = 0;
  base_longopts[51].name = (char const *)"no-group";
  base_longopts[51].has_arg = 0;
  base_longopts[51].flag = & group;
  base_longopts[51].val = 0;
  base_longopts[52].name = (char const *)"nogroup";
  base_longopts[52].has_arg = 0;
  base_longopts[52].flag = & group;
  base_longopts[52].val = 0;
  base_longopts[53].name = (char const *)"no-heading";
  base_longopts[53].has_arg = 0;
  base_longopts[53].flag = & opts.print_path;
  base_longopts[53].val = 3;
  base_longopts[54].name = (char const *)"noheading";
  base_longopts[54].has_arg = 0;
  base_longopts[54].flag = & opts.print_path;
  base_longopts[54].val = 3;
  base_longopts[55].name = (char const *)"no-mmap";
  base_longopts[55].has_arg = 0;
  base_longopts[55].flag = & opts.mmap;
  base_longopts[55].val = 0;
  base_longopts[56].name = (char const *)"nommap";
  base_longopts[56].has_arg = 0;
  base_longopts[56].flag = & opts.mmap;
  base_longopts[56].val = 0;
  base_longopts[57].name = (char const *)"no-multiline";
  base_longopts[57].has_arg = 0;
  base_longopts[57].flag = & opts.multiline;
  base_longopts[57].val = 0;
  base_longopts[58].name = (char const *)"nomultiline";
  base_longopts[58].has_arg = 0;
  base_longopts[58].flag = & opts.multiline;
  base_longopts[58].val = 0;
  base_longopts[59].name = (char const *)"no-numbers";
  base_longopts[59].has_arg = 0;
  base_longopts[59].flag = & opts.print_line_numbers;
  base_longopts[59].val = 0;
  base_longopts[60].name = (char const *)"nonumbers";
  base_longopts[60].has_arg = 0;
  base_longopts[60].flag = & opts.print_line_numbers;
  base_longopts[60].val = 0;
  base_longopts[61].name = (char const *)"no-pager";
  base_longopts[61].has_arg = 0;
  base_longopts[61].flag = (int *)((void *)0);
  base_longopts[61].val = 0;
  base_longopts[62].name = (char const *)"nopager";
  base_longopts[62].has_arg = 0;
  base_longopts[62].flag = (int *)((void *)0);
  base_longopts[62].val = 0;
  base_longopts[63].name = (char const *)"no-recurse";
  base_longopts[63].has_arg = 0;
  base_longopts[63].flag = (int *)((void *)0);
  base_longopts[63].val = 'n';
  base_longopts[64].name = (char const *)"norecurse";
  base_longopts[64].has_arg = 0;
  base_longopts[64].flag = (int *)((void *)0);
  base_longopts[64].val = 'n';
  base_longopts[65].name = (char const *)"null";
  base_longopts[65].has_arg = 0;
  base_longopts[65].flag = (int *)((void *)0);
  base_longopts[65].val = '0';
  base_longopts[66].name = (char const *)"numbers";
  base_longopts[66].has_arg = 0;
  base_longopts[66].flag = & opts.print_line_numbers;
  base_longopts[66].val = 2;
  base_longopts[67].name = (char const *)"only-matching";
  base_longopts[67].has_arg = 0;
  base_longopts[67].flag = (int *)((void *)0);
  base_longopts[67].val = 'o';
  base_longopts[68].name = (char const *)"one-device";
  base_longopts[68].has_arg = 0;
  base_longopts[68].flag = & opts.one_dev;
  base_longopts[68].val = 1;
  base_longopts[69].name = (char const *)"pager";
  base_longopts[69].has_arg = 1;
  base_longopts[69].flag = (int *)((void *)0);
  base_longopts[69].val = 0;
  base_longopts[70].name = (char const *)"parallel";
  base_longopts[70].has_arg = 0;
  base_longopts[70].flag = & opts.parallel;
  base_longopts[70].val = 1;
  base_longopts[71].name = (char const *)"passthrough";
  base_longopts[71].has_arg = 0;
  base_longopts[71].flag = & opts.passthrough;
  base_longopts[71].val = 1;
  base_longopts[72].name = (char const *)"passthru";
  base_longopts[72].has_arg = 0;
  base_longopts[72].flag = & opts.passthrough;
  base_longopts[72].val = 1;
  base_longopts[73].name = (char const *)"path-to-ignore";
  base_longopts[73].has_arg = 1;
  base_longopts[73].flag = (int *)((void *)0);
  base_longopts[73].val = 'p';
  base_longopts[74].name = (char const *)"print0";
  base_longopts[74].has_arg = 0;
  base_longopts[74].flag = (int *)((void *)0);
  base_longopts[74].val = '0';
  base_longopts[75].name = (char const *)"print-all-files";
  base_longopts[75].has_arg = 0;
  base_longopts[75].flag = (int *)((void *)0);
  base_longopts[75].val = 0;
  base_longopts[76].name = (char const *)"print-long-lines";
  base_longopts[76].has_arg = 0;
  base_longopts[76].flag = & opts.print_long_lines;
  base_longopts[76].val = 1;
  base_longopts[77].name = (char const *)"recurse";
  base_longopts[77].has_arg = 0;
  base_longopts[77].flag = (int *)((void *)0);
  base_longopts[77].val = 'r';
  base_longopts[78].name = (char const *)"search-binary";
  base_longopts[78].has_arg = 0;
  base_longopts[78].flag = & opts.search_binary_files;
  base_longopts[78].val = 1;
  base_longopts[79].name = (char const *)"search-files";
  base_longopts[79].has_arg = 0;
  base_longopts[79].flag = & opts.search_stream;
  base_longopts[79].val = 0;
  base_longopts[80].name = (char const *)"search-zip";
  base_longopts[80].has_arg = 0;
  base_longopts[80].flag = & opts.search_zip_files;
  base_longopts[80].val = 1;
  base_longopts[81].name = (char const *)"silent";
  base_longopts[81].has_arg = 0;
  base_longopts[81].flag = (int *)((void *)0);
  base_longopts[81].val = 0;
  base_longopts[82].name = (char const *)"skip-vcs-ignores";
  base_longopts[82].has_arg = 0;
  base_longopts[82].flag = (int *)((void *)0);
  base_longopts[82].val = 'U';
  base_longopts[83].name = (char const *)"smart-case";
  base_longopts[83].has_arg = 0;
  base_longopts[83].flag = (int *)((void *)0);
  base_longopts[83].val = 'S';
  base_longopts[84].name = (char const *)"stats";
  base_longopts[84].has_arg = 0;
  base_longopts[84].flag = & opts.stats;
  base_longopts[84].val = 1;
  base_longopts[85].name = (char const *)"stats-only";
  base_longopts[85].has_arg = 0;
  base_longopts[85].flag = (int *)((void *)0);
  base_longopts[85].val = 0;
  base_longopts[86].name = (char const *)"unrestricted";
  base_longopts[86].has_arg = 0;
  base_longopts[86].flag = (int *)((void *)0);
  base_longopts[86].val = 'u';
  base_longopts[87].name = (char const *)"version";
  base_longopts[87].has_arg = 0;
  base_longopts[87].flag = & version;
  base_longopts[87].val = 1;
  base_longopts[88].name = (char const *)"vimgrep";
  base_longopts[88].has_arg = 0;
  base_longopts[88].flag = & opts.vimgrep;
  base_longopts[88].val = 1;
  base_longopts[89].name = (char const *)"width";
  base_longopts[89].has_arg = 1;
  base_longopts[89].flag = (int *)((void *)0);
  base_longopts[89].val = 'W';
  base_longopts[90].name = (char const *)"word-regexp";
  base_longopts[90].has_arg = 0;
  base_longopts[90].flag = (int *)((void *)0);
  base_longopts[90].val = 'w';
  base_longopts[91].name = (char const *)"workers";
  base_longopts[91].has_arg = 1;
  base_longopts[91].flag = (int *)((void *)0);
  base_longopts[91].val = 0;
  lang_count = get_lang_count();
  longopts_len = sizeof(base_longopts) / sizeof(option_t );
  full_len = (longopts_len + lang_count) + 1UL;
  tmp___0 = ag_malloc(full_len * sizeof(option_t ));
  longopts = (option_t *)tmp___0;
  memcpy((void *)longopts, (void const *)(base_longopts), sizeof(base_longopts));
  tmp___1 = ag_malloc(sizeof(size_t ) * lang_count);
  ext_index = (size_t *)tmp___1;
  memset((void *)ext_index, 0, sizeof(size_t ) * lang_count);
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < lang_count)) {
      goto while_break;
    }
    opt.name = langs[i].name;
    opt.has_arg = 0;
    opt.flag = (int *)((void *)0);
    opt.val = 0;
    *(longopts + (i + longopts_len)) = opt;
    i ++;
  }
  while_break: ;
  }
  __constr_expr_0.name = (char const *)((void *)0);
  __constr_expr_0.has_arg = 0;
  __constr_expr_0.flag = (int *)((void *)0);
  __constr_expr_0.val = 0;
  *(longopts + (full_len - 1UL)) = __constr_expr_0;
  if (argc < 2) {
    usage();
    cleanup_ignore(root_ignores);
    cleanup_options();
    exit(1);
  }
  tmp___2 = fileno(stdin);
  rv = fstat(tmp___2, & statbuf);
  if (rv == 0) {
    if ((statbuf.st_mode & 61440U) == 4096U) {
      opts.search_stream = 1;
    } else
    if ((statbuf.st_mode & 61440U) == 32768U) {
      opts.search_stream = 1;
    }
  }
  tmp___4 = fileno(stdout);
  tmp___5 = isatty(tmp___4);
  if (! tmp___5) {
    opts.color = 0;
    group = 0;
    tmp___3 = fileno(stdout);
    rv = fstat(tmp___3, & statbuf);
    if (rv != 0) {
      die((char const *)"Error fstat()ing stdout");
    }
    opts.stdout_inode = statbuf.st_ino;
  }
  file_search_regex = (char *)((void *)0);
  {
  while (1) {
    while_continue___0: ;
    ch = getopt_long(argc, (char **)argv, (char const *)"A:aB:C:cDG:g:FfHhiLlm:nop:QRrSsvVtuUwW:z0",
                     (struct option const *)longopts, & opt_index);
    if (! (ch != -1)) {
      goto while_break___0;
    }
    {
    if (ch == 65) {
      goto case_65;
    }
    if (ch == 97) {
      goto case_97;
    }
    if (ch == 66) {
      goto case_66;
    }
    if (ch == 67) {
      goto case_67;
    }
    if (ch == 99) {
      goto case_99;
    }
    if (ch == 68) {
      goto case_68;
    }
    if (ch == 102) {
      goto case_102;
    }
    if (ch == 103) {
      goto case_103;
    }
    if (ch == 71) {
      goto case_71;
    }
    if (ch == 72) {
      goto case_72;
    }
    if (ch == 104) {
      goto case_104;
    }
    if (ch == 105) {
      goto case_105;
    }
    if (ch == 76) {
      goto case_76;
    }
    if (ch == 108) {
      goto case_108;
    }
    if (ch == 109) {
      goto case_109;
    }
    if (ch == 110) {
      goto case_110;
    }
    if (ch == 112) {
      goto case_112;
    }
    if (ch == 111) {
      goto case_111;
    }
    if (ch == 81) {
      goto case_81;
    }
    if (ch == 70) {
      goto case_81;
    }
    if (ch == 114) {
      goto case_114;
    }
    if (ch == 82) {
      goto case_114;
    }
    if (ch == 83) {
      goto case_83;
    }
    if (ch == 115) {
      goto case_115;
    }
    if (ch == 116) {
      goto case_116;
    }
    if (ch == 117) {
      goto case_117;
    }
    if (ch == 85) {
      goto case_85;
    }
    if (ch == 118) {
      goto case_118;
    }
    if (ch == 86) {
      goto case_86;
    }
    if (ch == 119) {
      goto case_119;
    }
    if (ch == 87) {
      goto case_87;
    }
    if (ch == 122) {
      goto case_122;
    }
    if (ch == 48) {
      goto case_48;
    }
    if (ch == 0) {
      goto case_0;
    }
    goto switch_default;
    case_65:
    if (optarg) {
      tmp___6 = strtol((char const * __restrict )optarg, (char ** __restrict )(& num_end),
                       10);
      opts.after = (size_t )tmp___6;
      if ((unsigned long )num_end == (unsigned long )optarg) {
        optind --;
        opts.after = (size_t )2;
      } else
      if ((int )*num_end != 0) {
        optind --;
        opts.after = (size_t )2;
      } else {
        tmp___7 = __errno_location();
        if (*tmp___7 == 34) {
          optind --;
          opts.after = (size_t )2;
        }
      }
    } else {
      opts.after = (size_t )2;
    }
    goto switch_break;
    case_97:
    opts.search_all_files = 1;
    opts.search_binary_files = 1;
    goto switch_break;
    case_66:
    if (optarg) {
      tmp___8 = strtol((char const * __restrict )optarg, (char ** __restrict )(& num_end),
                       10);
      opts.before = (size_t )tmp___8;
      if ((unsigned long )num_end == (unsigned long )optarg) {
        optind --;
        opts.before = (size_t )2;
      } else
      if ((int )*num_end != 0) {
        optind --;
        opts.before = (size_t )2;
      } else {
        tmp___9 = __errno_location();
        if (*tmp___9 == 34) {
          optind --;
          opts.before = (size_t )2;
        }
      }
    } else {
      opts.before = (size_t )2;
    }
    goto switch_break;
    case_67:
    if (optarg) {
      tmp___10 = strtol((char const * __restrict )optarg, (char ** __restrict )(& num_end),
                        10);
      opts.context = (int )tmp___10;
      if ((unsigned long )num_end == (unsigned long )optarg) {
        optind --;
        opts.context = 2;
      } else
      if ((int )*num_end != 0) {
        optind --;
        opts.context = 2;
      } else {
        tmp___11 = __errno_location();
        if (*tmp___11 == 34) {
          optind --;
          opts.context = 2;
        }
      }
    } else {
      opts.context = 2;
    }
    goto switch_break;
    case_99:
    opts.print_count = 1;
    opts.print_filename_only = 1;
    goto switch_break;
    case_68:
    set_log_level((enum log_level )10);
    goto switch_break;
    case_102:
    opts.follow_symlinks = 1;
    goto switch_break;
    case_103:
    accepts_query = 0;
    needs_query = accepts_query;
    opts.match_files = 1;
    case_71:
    if (file_search_regex) {
      log_err((char const *)"File search regex (-g or -G) already specified.");
      usage();
      exit(1);
    }
    file_search_regex = ag_strdup((char const *)optarg);
    goto switch_break;
    case_72:
    opts.print_path = 2;
    goto switch_break;
    case_104:
    help = 1;
    goto switch_break;
    case_105:
    opts.casing = (enum case_behavior )2;
    goto switch_break;
    case_76:
    opts.print_nonmatching_files = 1;
    opts.print_path = 2;
    goto switch_break;
    case_108:
    needs_query = 0;
    opts.print_filename_only = 1;
    opts.print_path = 2;
    goto switch_break;
    case_109:
    tmp___12 = atoi((char const *)optarg);
    opts.max_matches_per_file = (size_t )tmp___12;
    goto switch_break;
    case_110:
    opts.recurse_dirs = 0;
    goto switch_break;
    case_112:
    opts.path_to_ignore = 1;
    load_ignore_patterns(root_ignores, (char const *)optarg);
    goto switch_break;
    case_111:
    opts.only_matching = 1;
    goto switch_break;
    case_81:
    case_70:
    opts.literal = 1;
    goto switch_break;
    case_114:
    case_82:
    opts.recurse_dirs = 1;
    goto switch_break;
    case_83:
    opts.casing = (enum case_behavior )3;
    goto switch_break;
    case_115:
    opts.casing = (enum case_behavior )1;
    goto switch_break;
    case_116:
    opts.search_all_files = 1;
    goto switch_break;
    case_117:
    opts.search_binary_files = 1;
    opts.search_all_files = 1;
    opts.search_hidden_files = 1;
    goto switch_break;
    case_85:
    opts.skip_vcs_ignores = 1;
    goto switch_break;
    case_118:
    opts.invert_match = 1;
    opts.color = 0;
    goto switch_break;
    case_86:
    version = 1;
    goto switch_break;
    case_119:
    opts.word_regexp = 1;
    goto switch_break;
    case_87:
    tmp___13 = strtol((char const * __restrict )optarg, (char ** __restrict )(& num_end),
                      10);
    opts.width = (size_t )tmp___13;
    if ((unsigned long )num_end == (unsigned long )optarg) {
      die((char const *)"Invalid width\n");
    } else
    if ((int )*num_end != 0) {
      die((char const *)"Invalid width\n");
    } else {
      tmp___14 = __errno_location();
      if (*tmp___14 == 34) {
        die((char const *)"Invalid width\n");
      }
    }
    goto switch_break;
    case_122:
    opts.search_zip_files = 1;
    goto switch_break;
    case_48:
    opts.path_sep = (char )'\000';
    goto switch_break;
    case_0:
    tmp___31 = strcmp((longopts + opt_index)->name, (char const *)"ackmate-dir-filter");
    if (tmp___31 == 0) {
      compile_study(& opts.ackmate_dir_filter, & opts.ackmate_dir_filter_extra, optarg,
                    (int const )0, (int const )0);
      goto switch_break;
    } else {
      tmp___30 = strcmp((longopts + opt_index)->name, (char const *)"depth");
      if (tmp___30 == 0) {
        opts.max_search_depth = atoi((char const *)optarg);
        goto switch_break;
      } else {
        tmp___29 = strcmp((longopts + opt_index)->name, (char const *)"filename");
        if (tmp___29 == 0) {
          opts.print_path = 0;
          opts.print_line_numbers = 1;
          goto switch_break;
        } else {
          tmp___28 = strcmp((longopts + opt_index)->name, (char const *)"ignore-dir");
          if (tmp___28 == 0) {
            add_ignore_pattern(root_ignores, (char const *)optarg);
            goto switch_break;
          } else {
            tmp___27 = strcmp((longopts + opt_index)->name, (char const *)"ignore");
            if (tmp___27 == 0) {
              add_ignore_pattern(root_ignores, (char const *)optarg);
              goto switch_break;
            } else {
              tmp___25 = strcmp((longopts + opt_index)->name, (char const *)"no-filename");
              if (tmp___25 == 0) {
                opts.print_path = 4;
                opts.print_line_numbers = 0;
                goto switch_break;
              } else {
                tmp___26 = strcmp((longopts + opt_index)->name, (char const *)"nofilename");
                if (tmp___26 == 0) {
                  opts.print_path = 4;
                  opts.print_line_numbers = 0;
                  goto switch_break;
                } else {
                  tmp___23 = strcmp((longopts + opt_index)->name, (char const *)"no-pager");
                  if (tmp___23 == 0) {
                    out_fd = stdout;
                    opts.pager = (char *)((void *)0);
                    goto switch_break;
                  } else {
                    tmp___24 = strcmp((longopts + opt_index)->name, (char const *)"nopager");
                    if (tmp___24 == 0) {
                      out_fd = stdout;
                      opts.pager = (char *)((void *)0);
                      goto switch_break;
                    } else {
                      tmp___22 = strcmp((longopts + opt_index)->name, (char const *)"pager");
                      if (tmp___22 == 0) {
                        opts.pager = optarg;
                        goto switch_break;
                      } else {
                        tmp___21 = strcmp((longopts + opt_index)->name, (char const *)"print-all-files");
                        if (tmp___21 == 0) {
                          opts.print_all_paths = 1;
                          goto switch_break;
                        } else {
                          tmp___20 = strcmp((longopts + opt_index)->name, (char const *)"workers");
                          if (tmp___20 == 0) {
                            opts.workers = atoi((char const *)optarg);
                            goto switch_break;
                          } else {
                            tmp___19 = strcmp((longopts + opt_index)->name, (char const *)"color-line-number");
                            if (tmp___19 == 0) {
                              free((void *)opts.color_line_number);
                              ag_asprintf(& opts.color_line_number, (char const *)"\033[%sm",
                                          optarg);
                              goto switch_break;
                            } else {
                              tmp___18 = strcmp((longopts + opt_index)->name, (char const *)"color-match");
                              if (tmp___18 == 0) {
                                free((void *)opts.color_match);
                                ag_asprintf(& opts.color_match, (char const *)"\033[%sm",
                                            optarg);
                                goto switch_break;
                              } else {
                                tmp___17 = strcmp((longopts + opt_index)->name, (char const *)"color-path");
                                if (tmp___17 == 0) {
                                  free((void *)opts.color_path);
                                  ag_asprintf(& opts.color_path, (char const *)"\033[%sm",
                                              optarg);
                                  goto switch_break;
                                } else {
                                  tmp___16 = strcmp((longopts + opt_index)->name,
                                                    (char const *)"silent");
                                  if (tmp___16 == 0) {
                                    set_log_level((enum log_level )100);
                                    goto switch_break;
                                  } else {
                                    tmp___15 = strcmp((longopts + opt_index)->name,
                                                      (char const *)"stats-only");
                                    if (tmp___15 == 0) {
                                      opts.print_filename_only = 1;
                                      opts.print_path = 4;
                                      opts.stats = 1;
                                      goto switch_break;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ((unsigned long )(longopts + opt_index)->flag != (unsigned long )((int *)0)) {
      goto switch_break;
    }
    i = (size_t )0;
    {
    while (1) {
      while_continue___1: ;
      if (! (i < lang_count)) {
        goto while_break___1;
      }
      tmp___33 = strcmp((longopts + opt_index)->name, langs[i].name);
      if (tmp___33 == 0) {
        has_filetype = 1;
        tmp___32 = lang_num;
        lang_num ++;
        *(ext_index + tmp___32) = i;
        goto while_break___1;
      }
      i ++;
    }
    while_break___1: ;
    }
    if (i != lang_count) {
      goto switch_break;
    }
    log_err((char const *)"option %s does not take a value", (longopts + opt_index)->name);
    switch_default:
    usage();
    exit(1);
    switch_break: ;
    }
  }
  while_break___0: ;
  }
  if ((unsigned int )opts.casing == 0U) {
    opts.casing = (enum case_behavior )3;
  }
  if (file_search_regex) {
    pcre_opts = 0;
    if ((unsigned int )opts.casing == 2U) {
      pcre_opts |= 0x00000001;
    } else
    if ((unsigned int )opts.casing == 3U) {
      tmp___34 = is_lowercase((char const *)file_search_regex);
      if (tmp___34) {
        pcre_opts |= 0x00000001;
      }
    }
    if (opts.word_regexp) {
      old_file_search_regex = file_search_regex;
      ag_asprintf(& file_search_regex, (char const *)"\\b%s\\b", file_search_regex);
      free((void *)old_file_search_regex);
    }
    compile_study(& opts.file_search_regex, & opts.file_search_regex_extra, file_search_regex,
                  (int const )pcre_opts, (int const )0);
    free((void *)file_search_regex);
  }
  if (has_filetype) {
    num_exts = combine_file_extensions(ext_index, lang_num, & extensions);
    lang_regex = make_lang_regex(extensions, num_exts);
    compile_study(& opts.file_search_regex, & opts.file_search_regex_extra, lang_regex,
                  (int const )0, (int const )0);
  }
  if (extensions) {
    free((void *)extensions);
  }
  free((void *)ext_index);
  if (lang_regex) {
    free((void *)lang_regex);
  }
  free((void *)longopts);
  argc -= optind;
  argv += optind;
  if (opts.pager) {
    out_fd = popen((char const *)opts.pager, (char const *)"w");
    if (! out_fd) {
      perror((char const *)"Failed to run pager");
      exit(1);
    }
  }
  if (help) {
    usage();
    exit(0);
  }
  if (version) {
    print_version();
    exit(0);
  }
  if (list_file_types) {
    printf((char const *)"The following file types are supported:\n");
    lang_index = (size_t )0;
    {
    while (1) {
      while_continue___2: ;
      if (! (lang_index < lang_count)) {
        goto while_break___2;
      }
      printf((char const *)"  --%s\n    ", langs[lang_index].name);
      j = 0;
      {
      while (1) {
        while_continue___3: ;
        if (j < 12) {
          if (! langs[lang_index].extensions[j]) {
            goto while_break___3;
          }
        } else {
          goto while_break___3;
        }
        printf((char const *)"  .%s", langs[lang_index].extensions[j]);
        j ++;
      }
      while_break___3: ;
      }
      printf((char const *)"\n\n");
      lang_index ++;
    }
    while_break___2: ;
    }
    exit(0);
  }
  if (needs_query) {
    if (argc == 0) {
      log_err((char const *)"What do you want to search for?");
      exit(1);
    }
  }
  if (home_dir) {
    if (! opts.search_all_files) {
      log_debug((char const *)"Found user\'s home dir: %s", home_dir);
      ag_asprintf(& ignore_file_path, (char const *)"%s/.agignore", home_dir);
      load_ignore_patterns(root_ignores, (char const *)ignore_file_path);
      free((void *)ignore_file_path);
    }
  }
  if (! opts.skip_vcs_ignores) {
    gitconfig_file = (FILE *)((void *)0);
    buf_len = (size_t )0;
    gitconfig_res = (char *)((void *)0);
    gitconfig_file = popen((char const *)"git config -z --path --get core.excludesfile 2>/dev/null",
                           (char const *)"r");
    if ((unsigned long )gitconfig_file != (unsigned long )((void *)0)) {
      {
      while (1) {
        while_continue___4: ;
        tmp___35 = ag_realloc((void *)gitconfig_res, buf_len + 65UL);
        gitconfig_res = (char *)tmp___35;
        tmp___36 = fread((void *)(gitconfig_res + buf_len), (size_t )1, (size_t )64,
                         gitconfig_file);
        buf_len += tmp___36;
        tmp___37 = feof(gitconfig_file);
        if (tmp___37) {
          goto while_break___4;
        } else
        if (buf_len > 0UL) {
          if (! (buf_len % 64UL == 0UL)) {
            goto while_break___4;
          }
        } else {
          goto while_break___4;
        }
      }
      while_break___4: ;
      }
      *(gitconfig_res + buf_len) = (char )'\000';
      if (buf_len == 0UL) {
        free((void *)gitconfig_res);
        tmp___38 = getenv((char const *)"XDG_CONFIG_HOME");
        config_home = (char const *)tmp___38;
        if (config_home) {
          ag_asprintf(& gitconfig_res, (char const *)"%s/%s", config_home, "git/ignore");
        } else
        if (home_dir) {
          ag_asprintf(& gitconfig_res, (char const *)"%s/%s", home_dir, ".config/git/ignore");
        } else {
          gitconfig_res = ag_strdup((char const *)"");
        }
      }
      log_debug((char const *)"global core.excludesfile: %s", gitconfig_res);
      load_ignore_patterns(root_ignores, (char const *)gitconfig_res);
      free((void *)gitconfig_res);
      pclose(gitconfig_file);
    }
  }
  if (opts.context > 0) {
    opts.before = (size_t )opts.context;
    opts.after = (size_t )opts.context;
  }
  if (opts.ackmate) {
    opts.color = 0;
    opts.print_break = 1;
    group = 1;
    opts.search_stream = 0;
  }
  if (opts.vimgrep) {
    opts.color = 0;
    opts.print_break = 0;
    group = 1;
    opts.search_stream = 0;
    opts.print_path = 4;
  }
  if (opts.parallel) {
    opts.search_stream = 0;
  }
  if (! (opts.print_path != 0)) {
    if (! (opts.print_break == 0)) {
      if (group) {
        opts.print_break = 1;
      } else {
        opts.print_path = 1;
        opts.print_break = 0;
      }
    }
  }
  if (opts.search_stream) {
    opts.print_break = 0;
    opts.print_path = 4;
    if (opts.print_line_numbers != 2) {
      opts.print_line_numbers = 0;
    }
  }
  if (accepts_query) {
    if (argc > 0) {
      if (! needs_query) {
        tmp___39 = strlen((char const *)*(argv + 0));
        if (tmp___39 == 0UL) {
          opts.query = ag_strdup((char const *)".");
        } else {
          opts.query = ag_strdup((char const *)*(argv + 0));
        }
      } else {
        opts.query = ag_strdup((char const *)*(argv + 0));
      }
      argc --;
      argv ++;
    } else {
      goto _L;
    }
  } else
  _L:
  if (! needs_query) {
    opts.query = ag_strdup((char const *)".");
  }
  tmp___40 = strlen((char const *)opts.query);
  opts.query_len = (int )tmp___40;
  log_debug((char const *)"Query is %s", opts.query);
  if (opts.query_len == 0) {
    log_err((char const *)"Error: No query. What do you want to search for?");
    exit(1);
  }
  tmp___41 = is_regex((char const *)opts.query);
  if (! tmp___41) {
    opts.literal = 1;
  }
  path = (char *)((void *)0);
  base_path = (char *)((void *)0);
  tmp___42 = (char *)((void *)0);
  opts.paths_len = argc;
  if (argc > 0) {
    tmp___43 = ag_calloc(sizeof(char *), (size_t )(argc + 1));
    *paths = (char **)tmp___43;
    tmp___44 = ag_calloc(sizeof(char *), (size_t )(argc + 1));
    *base_paths = (char **)tmp___44;
    i = (size_t )0;
    {
    while (1) {
      while_continue___5: ;
      if (! (i < (size_t )argc)) {
        goto while_break___5;
      }
      path = ag_strdup((char const *)*(argv + i));
      tmp___45 = strlen((char const *)path);
      path_len = (int )tmp___45;
      if (path_len > 1) {
        if ((int )*(path + (path_len - 1)) == 47) {
          *(path + (path_len - 1)) = (char )'\000';
        }
      }
      *(*paths + i) = path;
      tmp___46 = ag_malloc((size_t )4096);
      tmp___42 = (char *)tmp___46;
      base_path = realpath((char const *)path, tmp___42);
      if (base_path) {
        tmp___47 = strlen((char const *)base_path);
        base_path_len = (int )tmp___47;
        if (base_path_len > 1) {
          if ((int )*(base_path + (base_path_len - 1)) != 47) {
            tmp___48 = ag_realloc((void *)base_path, (size_t )(base_path_len + 2));
            base_path = (char *)tmp___48;
            *(base_path + base_path_len) = (char )'/';
            *(base_path + (base_path_len + 1)) = (char )'\000';
          }
        }
      }
      *(*base_paths + i) = base_path;
      i ++;
    }
    while_break___5: ;
    }
    opts.search_stream = 0;
  } else {
    path = ag_strdup((char const *)".");
    tmp___49 = ag_malloc(sizeof(char *) * 2UL);
    *paths = (char **)tmp___49;
    tmp___50 = ag_malloc(sizeof(char *) * 2UL);
    *base_paths = (char **)tmp___50;
    *(*paths + 0) = path;
    tmp___51 = ag_malloc((size_t )4096);
    tmp___42 = (char *)tmp___51;
    *(*base_paths + 0) = realpath((char const *)path, tmp___42);
    i = (size_t )1;
  }
  *(*paths + i) = (char *)((void *)0);
  *(*base_paths + i) = (char *)((void *)0);
  return;
}
}
extern __ssize_t ( __attribute__((__leaf__)) readahead)(int __fd , __off64_t __offset ,
                                                        size_t __count ) __attribute__((__nothrow__)) ;
extern int sync_file_range(int __fd , __off64_t __offset , __off64_t __count , unsigned int __flags ) ;
extern __ssize_t vmsplice(int __fdout , struct iovec const *__iov , size_t __count ,
                          unsigned int __flags ) ;
extern __ssize_t splice(int __fdin , __off64_t *__offin , int __fdout , __off64_t *__offout ,
                        size_t __len , unsigned int __flags ) ;
extern __ssize_t tee(int __fdin , int __fdout , size_t __len , unsigned int __flags ) ;
extern int fallocate(int __fd , int __mode , __off_t __offset , __off_t __len ) ;
extern int fallocate64(int __fd , int __mode , __off64_t __offset , __off64_t __len ) ;
extern int ( __attribute__((__leaf__)) name_to_handle_at)(int __dfd , char const *__name ,
                                                          struct file_handle *__handle ,
                                                          int *__mnt_id , int __flags ) __attribute__((__nothrow__)) ;
extern int open_by_handle_at(int __mountdirfd , struct file_handle *__handle , int __flags ) ;
extern int fcntl(int __fd , int __cmd , ...) ;
extern int fcntl64(int __fd , int __cmd , ...) ;
__inline extern int ( __attribute__((__nonnull__(1), __artificial__, __always_inline__)) open)(char const *__path ,
                                                                                               int __oflag
                                                                                               , ...) ;
__inline extern int ( __attribute__((__nonnull__(1), __artificial__, __always_inline__)) open64)(char const *__path ,
                                                                                                 int __oflag
                                                                                                 , ...) ;
__inline extern int ( __attribute__((__nonnull__(2), __artificial__, __always_inline__)) openat)(int __fd ,
                                                                                                 char const *__path ,
                                                                                                 int __oflag
                                                                                                 , ...) ;
__inline extern int ( __attribute__((__nonnull__(2), __artificial__, __always_inline__)) openat64)(int __fd ,
                                                                                                   char const *__path ,
                                                                                                   int __oflag
                                                                                                   , ...) ;
extern int ( __attribute__((__nonnull__(1))) creat)(char const *__file , mode_t __mode ) ;
extern int ( __attribute__((__nonnull__(1))) creat64)(char const *__file , mode_t __mode ) ;
extern int ( __attribute__((__leaf__)) posix_fadvise)(int __fd , __off_t __offset ,
                                                      __off_t __len , int __advise ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) posix_fadvise64)(int __fd , __off64_t __offset ,
                                                        __off64_t __len , int __advise ) __attribute__((__nothrow__)) ;
extern int posix_fallocate(int __fd , __off_t __offset , __off_t __len ) ;
extern int posix_fallocate64(int __fd , __off64_t __offset , __off64_t __len ) ;
extern int ( __attribute__((__nonnull__(1))) __open_2)(char const *__path , int __oflag ) ;
extern int ( __attribute__((__nonnull__(1))) __open_alias)(char const *__path ,
                                                           int __oflag , ...) __asm__("open") ;
extern void __open_too_many_args(void) __attribute__((__error__("open can be called either with 2 or 3 arguments, not more"))) ;
extern void __open_missing_mode(void) __attribute__((__error__("open with O_CREAT or O_TMPFILE in second argument needs 3 arguments"))) ;
__inline extern int ( __attribute__((__nonnull__(1), __artificial__, __always_inline__)) open)(char const *__path ,
                                                                                               int __oflag
                                                                                               , ...)
{
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  {
  tmp = __builtin_va_arg_pack_len();
  if (tmp > 1) {
    __open_too_many_args();
  }
  if (0) {
    if ((__oflag & 0100) != 0) {
      goto _L;
    } else
    if ((__oflag & 4259840) == 4259840) {
      _L:
      tmp___1 = __builtin_va_arg_pack_len();
      if (tmp___1 < 1) {
        __open_missing_mode();
        tmp___0 = __open_2(__path, __oflag);
        return (tmp___0);
      }
    }
    tmp___2 = __open_alias(__path, __oflag, __builtin_va_arg_pack());
    return (tmp___2);
  }
  tmp___4 = __builtin_va_arg_pack_len();
  if (tmp___4 < 1) {
    tmp___3 = __open_2(__path, __oflag);
    return (tmp___3);
  }
  tmp___5 = __open_alias(__path, __oflag, __builtin_va_arg_pack());
  return (tmp___5);
}
}
extern int ( __attribute__((__nonnull__(1))) __open64_2)(char const *__path , int __oflag ) ;
extern int ( __attribute__((__nonnull__(1))) __open64_alias)(char const *__path ,
                                                             int __oflag , ...) __asm__("open64") ;
extern void __open64_too_many_args(void) __attribute__((__error__("open64 can be called either with 2 or 3 arguments, not more"))) ;
extern void __open64_missing_mode(void) __attribute__((__error__("open64 with O_CREAT or O_TMPFILE in second argument needs 3 arguments"))) ;
__inline extern int ( __attribute__((__nonnull__(1), __artificial__, __always_inline__)) open64)(char const *__path ,
                                                                                                 int __oflag
                                                                                                 , ...)
{
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  {
  tmp = __builtin_va_arg_pack_len();
  if (tmp > 1) {
    __open64_too_many_args();
  }
  if (0) {
    if ((__oflag & 0100) != 0) {
      goto _L;
    } else
    if ((__oflag & 4259840) == 4259840) {
      _L:
      tmp___1 = __builtin_va_arg_pack_len();
      if (tmp___1 < 1) {
        __open64_missing_mode();
        tmp___0 = __open64_2(__path, __oflag);
        return (tmp___0);
      }
    }
    tmp___2 = __open64_alias(__path, __oflag, __builtin_va_arg_pack());
    return (tmp___2);
  }
  tmp___4 = __builtin_va_arg_pack_len();
  if (tmp___4 < 1) {
    tmp___3 = __open64_2(__path, __oflag);
    return (tmp___3);
  }
  tmp___5 = __open64_alias(__path, __oflag, __builtin_va_arg_pack());
  return (tmp___5);
}
}
extern int ( __attribute__((__nonnull__(2))) __openat_2)(int __fd , char const *__path ,
                                                         int __oflag ) ;
extern int ( __attribute__((__nonnull__(2))) __openat_alias)(int __fd , char const *__path ,
                                                             int __oflag , ...) __asm__("openat") ;
extern void __openat_too_many_args(void) __attribute__((__error__("openat can be called either with 3 or 4 arguments, not more"))) ;
extern void __openat_missing_mode(void) __attribute__((__error__("openat with O_CREAT or O_TMPFILE in third argument needs 4 arguments"))) ;
__inline extern int ( __attribute__((__nonnull__(2), __artificial__, __always_inline__)) openat)(int __fd ,
                                                                                                 char const *__path ,
                                                                                                 int __oflag
                                                                                                 , ...)
{
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  {
  tmp = __builtin_va_arg_pack_len();
  if (tmp > 1) {
    __openat_too_many_args();
  }
  if (0) {
    if ((__oflag & 0100) != 0) {
      goto _L;
    } else
    if ((__oflag & 4259840) == 4259840) {
      _L:
      tmp___1 = __builtin_va_arg_pack_len();
      if (tmp___1 < 1) {
        __openat_missing_mode();
        tmp___0 = __openat_2(__fd, __path, __oflag);
        return (tmp___0);
      }
    }
    tmp___2 = __openat_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
    return (tmp___2);
  }
  tmp___4 = __builtin_va_arg_pack_len();
  if (tmp___4 < 1) {
    tmp___3 = __openat_2(__fd, __path, __oflag);
    return (tmp___3);
  }
  tmp___5 = __openat_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
  return (tmp___5);
}
}
extern int ( __attribute__((__nonnull__(2))) __openat64_2)(int __fd , char const *__path ,
                                                           int __oflag ) ;
extern int ( __attribute__((__nonnull__(2))) __openat64_alias)(int __fd , char const *__path ,
                                                               int __oflag , ...) __asm__("openat64") ;
extern void __openat64_too_many_args(void) __attribute__((__error__("openat64 can be called either with 3 or 4 arguments, not more"))) ;
extern void __openat64_missing_mode(void) __attribute__((__error__("openat64 with O_CREAT or O_TMPFILE in third argument needs 4 arguments"))) ;
__inline extern int ( __attribute__((__nonnull__(2), __artificial__, __always_inline__)) openat64)(int __fd ,
                                                                                                   char const *__path ,
                                                                                                   int __oflag
                                                                                                   , ...)
{
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  {
  tmp = __builtin_va_arg_pack_len();
  if (tmp > 1) {
    __openat64_too_many_args();
  }
  if (0) {
    if ((__oflag & 0100) != 0) {
      goto _L;
    } else
    if ((__oflag & 4259840) == 4259840) {
      _L:
      tmp___1 = __builtin_va_arg_pack_len();
      if (tmp___1 < 1) {
        __openat64_missing_mode();
        tmp___0 = __openat64_2(__fd, __path, __oflag);
        return (tmp___0);
      }
    }
    tmp___2 = __openat64_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
    return (tmp___2);
  }
  tmp___4 = __builtin_va_arg_pack_len();
  if (tmp___4 < 1) {
    tmp___3 = __openat64_2(__fd, __path, __oflag);
    return (tmp___3);
  }
  tmp___5 = __openat64_alias(__fd, __path, __oflag, __builtin_va_arg_pack());
  return (tmp___5);
}
}
extern int ( __attribute__((__leaf__)) memfd_create)(char const *__name , unsigned int __flags ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) mlock2)(void const *__addr , size_t __length ,
                                               unsigned int __flags ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pkey_alloc)(unsigned int __flags , unsigned int __access_rights ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pkey_set)(int __key , unsigned int __access_rights ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pkey_get)(int __key ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pkey_free)(int __key ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) pkey_mprotect)(void *__addr , size_t __len ,
                                                      int __prot , int __pkey ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__leaf__)) mmap)(void *__addr , size_t __len , int __prot ,
                                               int __flags , int __fd , __off_t __offset ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__leaf__)) mmap64)(void *__addr , size_t __len , int __prot ,
                                                 int __flags , int __fd , __off64_t __offset ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) munmap)(void *__addr , size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) mprotect)(void *__addr , size_t __len , int __prot ) __attribute__((__nothrow__)) ;
extern int msync(void *__addr , size_t __len , int __flags ) ;
extern int ( __attribute__((__leaf__)) madvise)(void *__addr , size_t __len , int __advice ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) posix_madvise)(void *__addr , size_t __len ,
                                                      int __advice ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) mlock)(void const *__addr , size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) munlock)(void const *__addr , size_t __len ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) mlockall)(int __flags ) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) munlockall)(void) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) mincore)(void *__start , size_t __len , unsigned char *__vec ) __attribute__((__nothrow__)) ;
extern void *( __attribute__((__leaf__)) mremap)(void *__addr , size_t __old_len ,
                                                 size_t __new_len , int __flags , ...) __attribute__((__nothrow__)) ;
extern int ( __attribute__((__leaf__)) remap_file_pages)(void *__start , size_t __size ,
                                                         int __prot , size_t __pgoff ,
                                                         int __flags ) __attribute__((__nothrow__)) ;
extern int shm_open(char const *__name , int __oflag , mode_t __mode ) ;
extern int shm_unlink(char const *__name ) ;
ag_compression_type is_zipped(void const *buf , int const buf_len ) ;
void *decompress(ag_compression_type const zip_type , void const *buf , int const buf_len ,
                 char const *dir_full_path , int *new_buf_len ) ;
FILE *decompress_open(int fd , char const *mode , ag_compression_type ctype ) ;
size_t alpha_skip_lookup[256] ;
size_t *find_skip_lookup ;
uint8_t h_table[65536] __attribute__((__aligned__(64))) ;
work_queue_t *work_queue ;
work_queue_t *work_queue_tail ;
int done_adding_files ;
pthread_cond_t files_ready ;
pthread_mutex_t stats_mtx ;
pthread_mutex_t work_queue_mtx ;
symdir_t *symhash ;
ssize_t search_buf(char const *buf , size_t const buf_len , char const *dir_full_path ) ;
ssize_t search_stream(FILE *stream , char const *path ) ;
void search_file(char const *file_full_path ) ;
void *search_file_worker(void *i ) ;
void search_dir(ignores *ig , char const *base_path , char const *path , int const depth ,
                dev_t original_dev ) ;
int first_file_match = 1;
char const *color_reset = (char const *)"\033[0m\033[K";
char const *truncate_marker = (char const *)" [...]";
struct print_context print_context __thread ;
void print_init_context(void)
{
  void *tmp ;
  {
  if ((unsigned long )print_context.context_prev_lines != (unsigned long )((void *)0)) {
    return;
  }
  tmp = ag_calloc(sizeof(char *), opts.before + 1UL);
  print_context.context_prev_lines = (char **)tmp;
  print_context.line = (size_t )1;
  print_context.prev_line = (size_t )0;
  print_context.last_prev_line = (size_t )0;
  print_context.prev_line_offset = (size_t )0;
  print_context.line_preceding_current_match_offset = (size_t )0;
  print_context.lines_since_last_match = (size_t )0x7fffffff;
  print_context.last_printed_match = (size_t )0;
  print_context.in_a_match = 0;
  print_context.printing_a_match = 0;
  return;
}
}
void print_cleanup_context(void)
{
  size_t i ;
  {
  if ((unsigned long )print_context.context_prev_lines == (unsigned long )((void *)0)) {
    return;
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < opts.before)) {
      goto while_break;
    }
    if ((unsigned long )*(print_context.context_prev_lines + i) != (unsigned long )((void *)0)) {
      free((void *)*(print_context.context_prev_lines + i));
    }
    i ++;
  }
  while_break: ;
  }
  free((void *)print_context.context_prev_lines);
  print_context.context_prev_lines = (char **)((void *)0);
  return;
}
}
void print_context_append(char const *line , size_t len )
{
  {
  if (opts.before == 0UL) {
    return;
  }
  if ((unsigned long )*(print_context.context_prev_lines + print_context.last_prev_line) != (unsigned long )((void *)0)) {
    free((void *)*(print_context.context_prev_lines + print_context.last_prev_line));
  }
  *(print_context.context_prev_lines + print_context.last_prev_line) = ag_strndup(line,
                                                                                  len);
  print_context.last_prev_line = (print_context.last_prev_line + 1UL) % opts.before;
  return;
}
}
void print_trailing_context(char const *path , char const *buf , size_t n )
{
  char sep ;
  {
  sep = (char )'-';
  if (opts.ackmate) {
    sep = (char )':';
  } else
  if (opts.vimgrep) {
    sep = (char )':';
  }
  if (print_context.lines_since_last_match != 0UL) {
    if (print_context.lines_since_last_match <= opts.after) {
      if (opts.print_path == 3) {
        print_path(path, (char const )':');
      }
      print_line_number(print_context.line, (char const )sep);
      fwrite((void const * __restrict )buf, (size_t )1, n, (FILE * __restrict )out_fd);
      fputc('\n', out_fd);
    }
  }
  (print_context.line) ++;
  if (! print_context.in_a_match) {
    if (print_context.lines_since_last_match < 2147483647UL) {
      (print_context.lines_since_last_match) ++;
    }
  }
  return;
}
}
void print_path(char const *path , char const sep )
{
  {
  if (opts.print_path == 4) {
    if (! opts.vimgrep) {
      return;
    }
  }
  path = normalize_path(path);
  if (opts.ackmate) {
    fprintf(out_fd, (char const *)":%s%c", path, (int const )sep);
  } else
  if (opts.vimgrep) {
    fprintf(out_fd, (char const *)"%s%c", path, (int const )sep);
  } else
  if (opts.color) {
    fprintf(out_fd, (char const *)"%s%s%s%c", opts.color_path, path, color_reset,
            (int const )sep);
  } else {
    fprintf(out_fd, (char const *)"%s%c", path, (int const )sep);
  }
  return;
}
}
void print_path_count(char const *path , char const sep , size_t const count )
{
  {
  if (*path) {
    print_path(path, (char const )':');
  }
  if (opts.color) {
    fprintf(out_fd, (char const *)"%s%lu%s%c", opts.color_line_number, (unsigned long )count,
            color_reset, (int const )sep);
  } else {
    fprintf(out_fd, (char const *)"%lu%c", (unsigned long )count, (int const )sep);
  }
  return;
}
}
void print_line(char const *buf , size_t buf_pos , size_t prev_line_offset )
{
  size_t write_chars ;
  {
  write_chars = (buf_pos - prev_line_offset) + 1UL;
  if (opts.width > 0UL) {
    if (opts.width < write_chars) {
      write_chars = opts.width;
    }
  }
  fwrite((void const * __restrict )(buf + prev_line_offset), (size_t )1, write_chars,
         (FILE * __restrict )out_fd);
  return;
}
}
void print_binary_file_matches(char const *path )
{
  {
  path = normalize_path(path);
  print_file_separator();
  fprintf(out_fd, (char const *)"Binary file %s matches.\n", path);
  return;
}
}
void print_file_matches(char const *path , char const *buf , size_t const buf_len ,
                        match_t const *matches , size_t const matches_len )
{
  size_t cur_match ;
  ssize_t lines_to_print ;
  char sep ;
  size_t i ;
  size_t j ;
  int blanks_between_matches ;
  int tmp ;
  size_t start ;
  int printed_match ;
  {
  cur_match = (size_t )0;
  lines_to_print = (ssize_t )0;
  sep = (char )'-';
  if (opts.context) {
    tmp = 1;
  } else
  if (opts.after) {
    tmp = 1;
  } else
  if (opts.before) {
    tmp = 1;
  } else {
    tmp = 0;
  }
  blanks_between_matches = tmp;
  if (opts.ackmate) {
    sep = (char )':';
  } else
  if (opts.vimgrep) {
    sep = (char )':';
  }
  print_file_separator();
  if (opts.print_path == 0) {
    opts.print_path = 2;
  } else
  if (opts.print_path == 1) {
    opts.print_path = 3;
  }
  if (opts.print_path == 2) {
    if (opts.print_count) {
      print_path_count(path, (char const )opts.path_sep, matches_len);
    } else {
      print_path(path, (char const )opts.path_sep);
    }
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (i <= (size_t )buf_len) {
      if (! (cur_match < (size_t )matches_len)) {
        if (! (print_context.lines_since_last_match <= opts.after)) {
          goto while_break;
        }
      }
    } else {
      goto while_break;
    }
    if (cur_match < (size_t )matches_len) {
      if (i == (size_t )(matches + cur_match)->start) {
        print_context.in_a_match = 1;
        if (cur_match > 0UL) {
          if (blanks_between_matches) {
            if (print_context.lines_since_last_match > (opts.before + opts.after) + 1UL) {
              fprintf(out_fd, (char const *)"--\n");
            }
          }
        }
        if (print_context.lines_since_last_match > 0UL) {
          if (opts.before > 0UL) {
            lines_to_print = (ssize_t )(print_context.lines_since_last_match - (opts.after + 1UL));
            if (lines_to_print < 0L) {
              lines_to_print = (ssize_t )0;
            } else
            if ((size_t )lines_to_print > opts.before) {
              lines_to_print = (ssize_t )opts.before;
            }
            j = opts.before - (size_t )lines_to_print;
            {
            while (1) {
              while_continue___0: ;
              if (! (j < opts.before)) {
                goto while_break___0;
              }
              print_context.prev_line = (print_context.last_prev_line + j) % opts.before;
              if ((unsigned long )*(print_context.context_prev_lines + print_context.prev_line) != (unsigned long )((void *)0)) {
                if (opts.print_path == 3) {
                  print_path(path, (char const )':');
                }
                print_line_number(print_context.line - (opts.before - j), (char const )sep);
                fprintf(out_fd, (char const *)"%s\n", *(print_context.context_prev_lines + print_context.prev_line));
              }
              j ++;
            }
            while_break___0: ;
            }
          }
        }
        print_context.lines_since_last_match = (size_t )0;
      }
    }
    if (cur_match < (size_t )matches_len) {
      if (i == (size_t )(matches + cur_match)->end) {
        cur_match ++;
        print_context.in_a_match = 0;
      }
    }
    if (i == (size_t )buf_len) {
      goto _L;
    } else
    if ((int const )*(buf + i) == 10) {
      _L:
      if (opts.before > 0UL) {
        print_context_append(buf + print_context.prev_line_offset, i - print_context.prev_line_offset);
      }
    }
    if (i == (size_t )buf_len) {
      goto _L___1;
    } else
    if ((int const )*(buf + i) == 10) {
      _L___1:
      if (print_context.lines_since_last_match == 0UL) {
        if (opts.print_path == 3) {
          if (! opts.search_stream) {
            print_path(path, (char const )':');
          }
        }
        if (opts.ackmate) {
          print_line_number(print_context.line, (char const )';');
          {
          while (1) {
            while_continue___1: ;
            if (! (print_context.last_printed_match < cur_match)) {
              goto while_break___1;
            }
            start = (size_t )((matches + print_context.last_printed_match)->start - (size_t )print_context.line_preceding_current_match_offset);
            fprintf(out_fd, (char const *)"%lu %lu", start, (matches + print_context.last_printed_match)->end - (matches + print_context.last_printed_match)->start);
            if (print_context.last_printed_match == cur_match - 1UL) {
              fputc(':', out_fd);
            } else {
              fputc(',', out_fd);
            }
            (print_context.last_printed_match) ++;
          }
          while_break___1: ;
          }
          print_line(buf, i, print_context.prev_line_offset);
        } else
        if (opts.vimgrep) {
          {
          while (1) {
            while_continue___2: ;
            if (! (print_context.last_printed_match < cur_match)) {
              goto while_break___2;
            }
            print_path(path, (char const )sep);
            print_line_number(print_context.line, (char const )sep);
            print_column_number(matches, print_context.last_printed_match, print_context.prev_line_offset,
                                (char const )sep);
            print_line(buf, i, print_context.prev_line_offset);
            (print_context.last_printed_match) ++;
          }
          while_break___2: ;
          }
        } else {
          print_line_number(print_context.line, (char const )':');
          printed_match = 0;
          if (opts.column) {
            print_column_number(matches, print_context.last_printed_match, print_context.prev_line_offset,
                                (char const )':');
          }
          if (print_context.printing_a_match) {
            if (opts.color) {
              fprintf(out_fd, (char const *)"%s", opts.color_match);
            }
          }
          j = print_context.prev_line_offset;
          {
          while (1) {
            while_continue___3: ;
            if (! (j <= i)) {
              goto while_break___3;
            }
            if (print_context.last_printed_match < (size_t )matches_len) {
              if (j == (size_t )(matches + print_context.last_printed_match)->end) {
                if (opts.color) {
                  fprintf(out_fd, (char const *)"%s", color_reset);
                }
                print_context.printing_a_match = 0;
                (print_context.last_printed_match) ++;
                printed_match = 1;
                if (opts.only_matching) {
                  fputc('\n', out_fd);
                }
              }
            }
            if (j < (size_t )buf_len) {
              if (opts.width > 0UL) {
                if (j - print_context.prev_line_offset >= opts.width) {
                  if (j < i) {
                    fputs((char const * __restrict )truncate_marker, (FILE * __restrict )out_fd);
                  }
                  fputc('\n', out_fd);
                  j = i;
                  print_context.last_printed_match = (size_t )matches_len;
                }
              }
            }
            if (print_context.last_printed_match < (size_t )matches_len) {
              if (j == (size_t )(matches + print_context.last_printed_match)->start) {
                if (opts.only_matching) {
                  if (printed_match) {
                    if (opts.print_path == 3) {
                      print_path(path, (char const )':');
                    }
                    print_line_number(print_context.line, (char const )':');
                    if (opts.column) {
                      print_column_number(matches, print_context.last_printed_match,
                                          print_context.prev_line_offset, (char const )':');
                    }
                  }
                }
                if (opts.color) {
                  fprintf(out_fd, (char const *)"%s", opts.color_match);
                }
                print_context.printing_a_match = 1;
              }
            }
            if (j < (size_t )buf_len) {
              if (! opts.only_matching) {
                goto _L___0;
              } else
              if (print_context.printing_a_match) {
                _L___0:
                if (opts.width == 0UL) {
                  fputc((int )*(buf + j), out_fd);
                } else
                if (j - print_context.prev_line_offset < opts.width) {
                  fputc((int )*(buf + j), out_fd);
                }
              }
            }
            j ++;
          }
          while_break___3: ;
          }
          if (print_context.printing_a_match) {
            if (opts.color) {
              fprintf(out_fd, (char const *)"%s", color_reset);
            }
          }
        }
      }
      if (opts.search_stream) {
        print_context.last_printed_match = (size_t )0;
        goto while_break;
      }
      print_trailing_context(path, buf + print_context.prev_line_offset, i - print_context.prev_line_offset);
      print_context.prev_line_offset = i + 1UL;
      if (! print_context.in_a_match) {
        print_context.line_preceding_current_match_offset = i + 1UL;
      }
      if (i == (size_t )buf_len) {
        if ((int const )*(buf + (i - 1UL)) != 10) {
          fputc('\n', out_fd);
        }
      }
    }
    i ++;
  }
  while_break: ;
  }
  if (opts.stdout_inode) {
    fflush(out_fd);
  }
  return;
}
}
void print_line_number(size_t line , char const sep )
{
  {
  if (! opts.print_line_numbers) {
    return;
  }
  if (opts.color) {
    fprintf(out_fd, (char const *)"%s%lu%s%c", opts.color_line_number, line, color_reset,
            (int const )sep);
  } else {
    fprintf(out_fd, (char const *)"%lu%c", line, (int const )sep);
  }
  return;
}
}
void print_column_number(match_t const *matches , size_t last_printed_match , size_t prev_line_offset ,
                         char const sep )
{
  size_t column ;
  {
  column = (size_t )0;
  if (prev_line_offset <= (size_t )(matches + last_printed_match)->start) {
    column = (size_t )(((matches + last_printed_match)->start - (size_t )prev_line_offset) + 1UL);
  }
  fprintf(out_fd, (char const *)"%lu%c", column, (int const )sep);
  return;
}
}
void print_file_separator(void)
{
  {
  if (first_file_match == 0) {
    if (opts.print_break) {
      fprintf(out_fd, (char const *)"\n");
    }
  }
  first_file_match = 0;
  return;
}
}
char const *normalize_path(char const *path )
{
  size_t tmp ;
  {
  tmp = strlen(path);
  if (tmp < 3UL) {
    return (path);
  }
  if ((int const )*(path + 0) == 46) {
    if ((int const )*(path + 1) == 47) {
      return (path + 2);
    }
  }
  if ((int const )*(path + 0) == 47) {
    if ((int const )*(path + 1) == 47) {
      return (path + 1);
    }
  }
  return (path);
}
}
int ag_scandir(char const *dirname , struct dirent ***namelist , int (*filter)(char const *path ,
                                                                                 struct dirent const * ,
                                                                                 void * ) ,
               void *baton )
{
  DIR *dirp ;
  struct dirent **names ;
  struct dirent *entry ;
  struct dirent *d ;
  int names_len ;
  int results_len ;
  void *tmp ;
  int tmp___0 ;
  struct dirent **tmp_names ;
  void *tmp___1 ;
  void *tmp___2 ;
  int i ;
  {
  dirp = (DIR *)((void *)0);
  names = (struct dirent **)((void *)0);
  names_len = 32;
  results_len = 0;
  dirp = opendir(dirname);
  if ((unsigned long )dirp == (unsigned long )((void *)0)) {
    goto fail;
  }
  tmp = malloc(sizeof(struct dirent *) * (unsigned long )names_len);
  names = (struct dirent **)tmp;
  if ((unsigned long )names == (unsigned long )((void *)0)) {
    goto fail;
  }
  {
  while (1) {
    while_continue: ;
    entry = readdir(dirp);
    if (! ((unsigned long )entry != (unsigned long )((void *)0))) {
      goto while_break;
    }
    tmp___0 = (*filter)(dirname, (struct dirent const *)entry, baton);
    if (tmp___0 == 0) {
      goto while_continue;
    }
    if (results_len >= names_len) {
      tmp_names = names;
      names_len *= 2;
      tmp___1 = realloc((void *)names, sizeof(struct dirent *) * (unsigned long )names_len);
      names = (struct dirent **)tmp___1;
      if ((unsigned long )names == (unsigned long )((void *)0)) {
        free((void *)tmp_names);
        goto fail;
      }
    }
    tmp___2 = malloc((size_t )entry->d_reclen);
    d = (struct dirent *)tmp___2;
    if ((unsigned long )d == (unsigned long )((void *)0)) {
      goto fail;
    }
    memcpy((void *)d, (void const *)entry, (size_t )entry->d_reclen);
    *(names + results_len) = d;
    results_len ++;
  }
  while_break: ;
  }
  closedir(dirp);
  *namelist = names;
  return (results_len);
  fail:
  if (dirp) {
    closedir(dirp);
  }
  if ((unsigned long )names != (unsigned long )((void *)0)) {
    i = 0;
    {
    while (1) {
      while_continue___0: ;
      if (! (i < results_len)) {
        goto while_break___0;
      }
      free((void *)*(names + i));
      i ++;
    }
    while_break___0: ;
    }
    free((void *)names);
  }
  return (-1);
}
}
size_t alpha_skip_lookup[256] ;
size_t *find_skip_lookup ;
uint8_t h_table[65536] __attribute__((__aligned__(64))) ;
work_queue_t *work_queue = (work_queue_t *)((void *)0);
work_queue_t *work_queue_tail = (work_queue_t *)((void *)0);
int done_adding_files = 0;
pthread_cond_t files_ready = {{{0ULL}, {0ULL}, {0U, 0U}, {0U, 0U}, 0U, 0U, {0U, 0U}}};
pthread_mutex_t stats_mtx = {{0, 0U, 0, 0U, 0, (short)0, (short)0, {(struct __pthread_internal_list *)0, (struct __pthread_internal_list *)0}}};
pthread_mutex_t work_queue_mtx = {{0, 0U, 0, 0U, 0, (short)0, (short)0, {(struct __pthread_internal_list *)0, (struct __pthread_internal_list *)0}}};
symdir_t *symhash = (symdir_t *)((void *)0);
ssize_t search_buf(char const *buf , size_t const buf_len , char const *dir_full_path )
{
  int binary ;
  size_t buf_offset ;
  size_t matches_len ;
  match_t *matches ;
  size_t matches_size ;
  size_t matches_spare ;
  void *tmp ;
  void *tmp___0 ;
  char const *match_ptr ;
  char const *start ;
  char const *end ;
  int tmp___1 ;
  int tmp___2 ;
  int offset_vector[3] ;
  int tmp___3 ;
  char const *line ;
  size_t line_len ;
  ssize_t tmp___4 ;
  size_t line_offset ;
  int rv ;
  int tmp___5 ;
  size_t line_to_buf ;
  {
  binary = -1;
  buf_offset = (size_t )0;
  if (opts.search_stream) {
    binary = 0;
  } else
  if (! opts.search_binary_files) {
    if (opts.mmap) {
      binary = is_binary((void const *)buf, (size_t const )buf_len);
      if (binary) {
        log_debug((char const *)"File %s is binary. Skipping...", dir_full_path);
        return ((ssize_t )-1);
      }
    }
  }
  matches_len = (size_t )0;
  if (opts.invert_match) {
    matches_size = (size_t )100;
    tmp = ag_malloc(matches_size * sizeof(match_t ));
    matches = (match_t *)tmp;
    matches_spare = (size_t )1;
  } else {
    matches_size = (size_t )0;
    matches = (match_t *)((void *)0);
    matches_spare = (size_t )0;
  }
  if (! opts.literal) {
    if (opts.query_len == 1) {
      if ((int )*(opts.query + 0) == 46) {
        matches_size = (size_t )1;
        if ((unsigned long )matches == (unsigned long )((void *)0)) {
          tmp___0 = ag_malloc(matches_size * sizeof(match_t ));
          matches = (match_t *)tmp___0;
        } else {
          matches = matches;
        }
        (matches + 0)->start = (size_t )0;
        (matches + 0)->end = (size_t )buf_len;
        matches_len = (size_t )1;
      } else {
        goto _L___1;
      }
    } else {
      goto _L___1;
    }
  } else
  _L___1:
  _L___0:
  if (opts.literal) {
    match_ptr = buf;
    {
    while (1) {
      while_continue: ;
      if (! (buf_offset < (size_t )buf_len)) {
        goto while_break;
      }
      if ((size_t )opts.query_len < 2UL * sizeof(uint16_t ) - 1UL) {
        match_ptr = boyer_moore_strnstr(match_ptr, (char const *)opts.query, (size_t const )(buf_len - (size_t const )buf_offset),
                                        (size_t const )opts.query_len, (size_t const *)(alpha_skip_lookup),
                                        (size_t const *)find_skip_lookup, (int const )((unsigned int )opts.casing == 2U));
      } else
      if (opts.query_len >= 255) {
        match_ptr = boyer_moore_strnstr(match_ptr, (char const *)opts.query, (size_t const )(buf_len - (size_t const )buf_offset),
                                        (size_t const )opts.query_len, (size_t const *)(alpha_skip_lookup),
                                        (size_t const *)find_skip_lookup, (int const )((unsigned int )opts.casing == 2U));
      } else {
        match_ptr = hash_strnstr(match_ptr, (char const *)opts.query, (size_t const )(buf_len - (size_t const )buf_offset),
                                 (size_t const )opts.query_len, h_table, (int const )((unsigned int )opts.casing == 1U));
      }
      if ((unsigned long )match_ptr == (unsigned long )((void *)0)) {
        goto while_break;
      }
      if (opts.word_regexp) {
        start = match_ptr;
        end = match_ptr + opts.query_len;
        if ((unsigned long )start == (unsigned long )buf) {
          goto _L;
        } else {
          tmp___1 = is_wordchar((char )*(start - 1));
          if (tmp___1 != opts.literal_starts_wordchar) {
            _L:
            if (! ((unsigned long )end == (unsigned long )(buf + buf_len))) {
              tmp___2 = is_wordchar((char )*end);
              if (! (tmp___2 != opts.literal_ends_wordchar)) {
                match_ptr += (*(find_skip_lookup + 0) - (size_t )opts.query_len) + 1UL;
                buf_offset = (size_t )(match_ptr - buf);
                goto while_continue;
              }
            }
          } else {
            match_ptr += (*(find_skip_lookup + 0) - (size_t )opts.query_len) + 1UL;
            buf_offset = (size_t )(match_ptr - buf);
            goto while_continue;
          }
        }
      }
      realloc_matches(& matches, & matches_size, matches_len + matches_spare);
      (matches + matches_len)->start = (size_t )(match_ptr - buf);
      (matches + matches_len)->end = (matches + matches_len)->start + (size_t )opts.query_len;
      buf_offset = (matches + matches_len)->end;
      log_debug((char const *)"Match found. File %s, offset %lu bytes.", dir_full_path,
                (matches + matches_len)->start);
      matches_len ++;
      match_ptr += opts.query_len;
      if (opts.max_matches_per_file > 0UL) {
        if (matches_len >= opts.max_matches_per_file) {
          log_err((char const *)"Too many matches in %s. Skipping the rest of this file.",
                  dir_full_path);
          goto while_break;
        }
      }
    }
    while_break: ;
    }
  } else
  if (opts.multiline) {
    {
    while (1) {
      while_continue___0: ;
      if (buf_offset < (size_t )buf_len) {
        tmp___3 = pcre_exec((pcre const *)opts.re, (pcre_extra const *)opts.re_extra,
                            buf, (int )buf_len, (int )buf_offset, 0, offset_vector,
                            3);
        if (! (tmp___3 >= 0)) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      log_debug((char const *)"Regex match found. File %s, offset %i bytes.", dir_full_path,
                offset_vector[0]);
      buf_offset = (size_t )offset_vector[1];
      if (offset_vector[0] == offset_vector[1]) {
        buf_offset ++;
        log_debug((char const *)"Regex match is of length zero. Advancing offset one byte.");
      }
      realloc_matches(& matches, & matches_size, matches_len + matches_spare);
      (matches + matches_len)->start = (size_t )offset_vector[0];
      (matches + matches_len)->end = (size_t )offset_vector[1];
      matches_len ++;
      if (opts.max_matches_per_file > 0UL) {
        if (matches_len >= opts.max_matches_per_file) {
          log_err((char const *)"Too many matches in %s. Skipping the rest of this file.",
                  dir_full_path);
          goto while_break___0;
        }
      }
    }
    while_break___0: ;
    }
  } else {
    {
    while (1) {
      while_continue___1: ;
      if (! (buf_offset < (size_t )buf_len)) {
        goto while_break___1;
      }
      tmp___4 = buf_getline(& line, buf, (size_t const )buf_len, (size_t const )buf_offset);
      line_len = (size_t )tmp___4;
      if (! line) {
        goto while_break___1;
      }
      line_offset = (size_t )0;
      {
      while (1) {
        while_continue___2: ;
        if (! (line_offset < line_len)) {
          goto while_break___2;
        }
        tmp___5 = pcre_exec((pcre const *)opts.re, (pcre_extra const *)opts.re_extra,
                            line, (int )line_len, (int )line_offset, 0, offset_vector,
                            3);
        rv = tmp___5;
        if (rv < 0) {
          goto while_break___2;
        }
        line_to_buf = buf_offset + line_offset;
        log_debug((char const *)"Regex match found. File %s, offset %i bytes.",
                  dir_full_path, offset_vector[0]);
        line_offset = (size_t )offset_vector[1];
        if (offset_vector[0] == offset_vector[1]) {
          line_offset ++;
          log_debug((char const *)"Regex match is of length zero. Advancing offset one byte.");
        }
        realloc_matches(& matches, & matches_size, matches_len + matches_spare);
        (matches + matches_len)->start = (size_t )offset_vector[0] + line_to_buf;
        (matches + matches_len)->end = (size_t )offset_vector[1] + line_to_buf;
        matches_len ++;
        if (opts.max_matches_per_file > 0UL) {
          if (matches_len >= opts.max_matches_per_file) {
            log_err((char const *)"Too many matches in %s. Skipping the rest of this file.",
                    dir_full_path);
            goto multiline_done;
          }
        }
      }
      while_break___2: ;
      }
      buf_offset += line_len + 1UL;
    }
    while_break___1: ;
    }
  }
  multiline_done:
  if (opts.invert_match) {
    matches_len = invert_matches(buf, (size_t const )buf_len, matches, matches_len);
  }
  if (opts.stats) {
    pthread_mutex_lock(& stats_mtx);
    stats.total_bytes += (size_t )buf_len;
    (stats.total_files) ++;
    stats.total_matches += matches_len;
    if (matches_len > 0UL) {
      (stats.total_file_matches) ++;
    }
    pthread_mutex_unlock(& stats_mtx);
  }
  if (! opts.print_nonmatching_files) {
    if (matches_len > 0UL) {
      goto _L___3;
    } else
    if (opts.print_all_paths) {
      _L___3:
      if (binary == -1) {
        if (! opts.print_filename_only) {
          binary = is_binary((void const *)buf, (size_t const )buf_len);
        }
      }
      pthread_mutex_lock(& print_mtx);
      if (opts.print_filename_only) {
        if (opts.print_count) {
          print_path_count(dir_full_path, (char const )opts.path_sep, (size_t const )matches_len);
        } else {
          print_path(dir_full_path, (char const )opts.path_sep);
        }
      } else
      if (binary) {
        print_binary_file_matches(dir_full_path);
      } else {
        print_file_matches(dir_full_path, buf, (size_t const )buf_len, (match_t const *)matches,
                           (size_t const )matches_len);
      }
      pthread_mutex_unlock(& print_mtx);
      opts.match_found = 1;
    } else {
      goto _L___2;
    }
  } else
  _L___2:
  if (opts.search_stream) {
    if (opts.passthrough) {
      fprintf(out_fd, (char const *)"%s", buf);
    } else {
      log_debug((char const *)"No match in %s", dir_full_path);
    }
  } else {
    log_debug((char const *)"No match in %s", dir_full_path);
  }
  if (matches_len == 0UL) {
    if (opts.search_stream) {
      print_context_append(buf, (size_t )(buf_len - 1UL));
    }
  }
  if (matches_size > 0UL) {
    free((void *)matches);
  }
  return ((ssize_t )matches_len);
}
}
ssize_t search_stream(FILE *stream , char const *path )
{
  char *line ;
  ssize_t matches_count ;
  ssize_t line_len ;
  size_t line_cap ;
  size_t i ;
  ssize_t result ;
  {
  line = (char *)((void *)0);
  matches_count = (ssize_t )0;
  line_len = (ssize_t )0;
  line_cap = (size_t )0;
  print_init_context();
  i = (size_t )1;
  {
  while (1) {
    while_continue: ;
    line_len = getline(& line, & line_cap, stream);
    if (! (line_len > 0L)) {
      goto while_break;
    }
    opts.stream_line_num = i;
    result = search_buf((char const *)line, (size_t const )line_len, path);
    if (result > 0L) {
      if (matches_count == -1L) {
        matches_count = (ssize_t )0;
      }
      matches_count += result;
    } else
    if (matches_count <= 0L) {
      if (result == -1L) {
        matches_count = (ssize_t )-1;
      }
    }
    if ((int )*(line + (line_len - 1L)) == 10) {
      line_len --;
    }
    print_trailing_context(path, (char const *)line, (size_t )line_len);
    i ++;
  }
  while_break: ;
  }
  free((void *)line);
  print_cleanup_context();
  return (matches_count);
}
}
void search_file(char const *file_full_path )
{
  int fd ;
  __off_t f_len ;
  char *buf ;
  struct stat statbuf ;
  int rv ;
  int matches_count ;
  FILE *fp ;
  int *tmp ;
  char *tmp___0 ;
  ssize_t tmp___1 ;
  ssize_t tmp___2 ;
  void *tmp___3 ;
  int *tmp___4 ;
  char *tmp___5 ;
  void *tmp___6 ;
  ssize_t bytes_read ;
  size_t tmp___7 ;
  ssize_t tmp___8 ;
  int tmp___9 ;
  ssize_t tmp___10 ;
  ag_compression_type zip_type ;
  ag_compression_type tmp___11 ;
  ssize_t tmp___12 ;
  ssize_t tmp___13 ;
  {
  fd = -1;
  f_len = (__off_t )0;
  buf = (char *)((void *)0);
  rv = 0;
  matches_count = -1;
  fp = (FILE *)((void *)0);
  rv = stat((char const * __restrict )file_full_path, (struct stat * __restrict )(& statbuf));
  if (rv != 0) {
    log_err((char const *)"Skipping %s: Error fstat()ing file.", file_full_path);
    goto cleanup;
  }
  if (opts.stdout_inode != 0UL) {
    if (opts.stdout_inode == statbuf.st_ino) {
      log_debug((char const *)"Skipping %s: stdout is redirected to it", file_full_path);
      goto cleanup;
    }
  }
  if (! ((statbuf.st_mode & 61440U) == 32768U)) {
    if (! ((statbuf.st_mode & 61440U) == 4096U)) {
      log_err((char const *)"Skipping %s: Mode %u is not a file.", file_full_path,
              statbuf.st_mode);
      goto cleanup;
    }
  }
  fd = open(file_full_path, 00);
  if (fd < 0) {
    tmp = __errno_location();
    tmp___0 = strerror(*tmp);
    log_err((char const *)"Skipping %s: Error opening file: %s", file_full_path,
            tmp___0);
    goto cleanup;
  }
  rv = fstat(fd, & statbuf);
  if (rv != 0) {
    log_err((char const *)"Skipping %s: Error fstat()ing file.", file_full_path);
    goto cleanup;
  }
  if (opts.stdout_inode != 0UL) {
    if (opts.stdout_inode == statbuf.st_ino) {
      log_debug((char const *)"Skipping %s: stdout is redirected to it", file_full_path);
      goto cleanup;
    }
  }
  if (! ((statbuf.st_mode & 61440U) == 32768U)) {
    if (! ((statbuf.st_mode & 61440U) == 4096U)) {
      log_err((char const *)"Skipping %s: Mode %u is not a file.", file_full_path,
              statbuf.st_mode);
      goto cleanup;
    }
  }
  print_init_context();
  if (statbuf.st_mode & 4096U) {
    log_debug((char const *)"%s is a named pipe. stream searching", file_full_path);
    fp = fdopen(fd, (char const *)"r");
    tmp___1 = search_stream(fp, file_full_path);
    matches_count = (int )tmp___1;
    fclose(fp);
    goto cleanup;
  }
  f_len = statbuf.st_size;
  if (f_len == 0L) {
    if ((int )*(opts.query + 0) == 46) {
      if (opts.query_len == 1) {
        if (! opts.literal) {
          if (opts.search_all_files) {
            tmp___2 = search_buf((char const *)buf, (size_t const )f_len, file_full_path);
            matches_count = (int )tmp___2;
          } else {
            log_debug((char const *)"Skipping %s: file is empty.", file_full_path);
          }
        } else {
          log_debug((char const *)"Skipping %s: file is empty.", file_full_path);
        }
      } else {
        log_debug((char const *)"Skipping %s: file is empty.", file_full_path);
      }
    } else {
      log_debug((char const *)"Skipping %s: file is empty.", file_full_path);
    }
    goto cleanup;
  }
  if (! opts.literal) {
    if (f_len > 2147483647L) {
      log_err((char const *)"Skipping %s: pcre_exec() can\'t handle files larger than %i bytes.",
              file_full_path, 0x7fffffff);
      goto cleanup;
    }
  }
  if (opts.mmap) {
    tmp___3 = mmap((void *)0, (size_t )f_len, 0x1, 0x02, fd, (__off_t )0);
    buf = (char *)tmp___3;
    if ((unsigned long )buf == (unsigned long )((void *)-1)) {
      tmp___4 = __errno_location();
      tmp___5 = strerror(*tmp___4);
      log_err((char const *)"File %s failed to load: %s.", file_full_path, tmp___5);
      goto cleanup;
    }
    madvise((void *)buf, (size_t )f_len, 2);
  } else {
    tmp___6 = ag_malloc((size_t )f_len);
    buf = (char *)tmp___6;
    bytes_read = (ssize_t )0;
    if (! opts.search_binary_files) {
      tmp___7 = ag_min((size_t )f_len, (size_t )512);
      tmp___8 = read(fd, (void *)buf, tmp___7);
      bytes_read += tmp___8;
      tmp___9 = is_binary((void const *)buf, (size_t const )f_len);
      if (tmp___9) {
        log_debug((char const *)"File %s is binary. Skipping...", file_full_path);
        goto cleanup;
      }
    }
    {
    while (1) {
      while_continue: ;
      if (! (bytes_read < f_len)) {
        goto while_break;
      }
      tmp___10 = read(fd, (void *)(buf + bytes_read), (size_t )f_len);
      bytes_read += tmp___10;
    }
    while_break: ;
    }
    if (bytes_read != f_len) {
      die((char const *)"File %s read(): expected to read %u bytes but read %u",
          file_full_path, f_len, bytes_read);
    }
  }
  if (opts.search_zip_files) {
    tmp___11 = is_zipped((void const *)buf, (int const )f_len);
    zip_type = tmp___11;
    if ((unsigned int )zip_type != 0U) {
      log_debug((char const *)"%s is a compressed file. stream searching", file_full_path);
      fp = decompress_open(fd, (char const *)"r", zip_type);
      tmp___12 = search_stream(fp, file_full_path);
      matches_count = (int )tmp___12;
      fclose(fp);
      goto cleanup;
    }
  }
  tmp___13 = search_buf((char const *)buf, (size_t const )f_len, file_full_path);
  matches_count = (int )tmp___13;
  cleanup:
  if (opts.print_nonmatching_files) {
    if (matches_count == 0) {
      pthread_mutex_lock(& print_mtx);
      print_path(file_full_path, (char const )opts.path_sep);
      pthread_mutex_unlock(& print_mtx);
      opts.match_found = 1;
    }
  }
  print_cleanup_context();
  if ((unsigned long )buf != (unsigned long )((void *)0)) {
    if (opts.mmap) {
      if ((unsigned long )buf != (unsigned long )((void *)-1)) {
        munmap((void *)buf, (size_t )f_len);
      }
    } else {
      free((void *)buf);
    }
  }
  if (fd != -1) {
    close(fd);
  }
  return;
}
}
void *search_file_worker(void *i )
{
  work_queue_t *queue_item ;
  int worker_id ;
  {
  worker_id = *((int *)i);
  log_debug((char const *)"Worker %i started", worker_id);
  {
  while (1) {
    while_continue: ;
    pthread_mutex_lock(& work_queue_mtx);
    {
    while (1) {
      while_continue___0: ;
      if (! ((unsigned long )work_queue == (unsigned long )((void *)0))) {
        goto while_break___0;
      }
      if (done_adding_files) {
        pthread_mutex_unlock(& work_queue_mtx);
        log_debug((char const *)"Worker %i finished.", worker_id);
        pthread_exit((void *)0);
      }
      pthread_cond_wait((pthread_cond_t * __restrict )(& files_ready), (pthread_mutex_t * __restrict )(& work_queue_mtx));
    }
    while_break___0: ;
    }
    queue_item = work_queue;
    work_queue = work_queue->next;
    if ((unsigned long )work_queue == (unsigned long )((void *)0)) {
      work_queue_tail = (work_queue_t *)((void *)0);
    }
    pthread_mutex_unlock(& work_queue_mtx);
    search_file((char const *)queue_item->path);
    free((void *)queue_item->path);
    free((void *)queue_item);
  }
  while_break: ;
  }
}
}
static int check_symloop_enter(char const *path , dirkey_t *outkey )
{
  struct stat buf ;
  symdir_t *item_found ;
  symdir_t *new_item ;
  int res ;
  int tmp ;
  unsigned int _hf_bkt ;
  unsigned int _hf_hashv ;
  unsigned int _hj_i ;
  unsigned int _hj_j ;
  unsigned int _hj_k ;
  unsigned char *_hj_key ;
  int tmp___0 ;
  void *tmp___1 ;
  unsigned int _ha_bkt ;
  void *tmp___2 ;
  void *tmp___3 ;
  unsigned int _hj_i___0 ;
  unsigned int _hj_j___0 ;
  unsigned int _hj_k___0 ;
  unsigned char *_hj_key___0 ;
  unsigned int _he_bkt ;
  unsigned int _he_bkt_i ;
  struct UT_hash_handle *_he_thh ;
  struct UT_hash_handle *_he_hh_nxt ;
  UT_hash_bucket *_he_new_buckets ;
  UT_hash_bucket *_he_newbkt ;
  void *tmp___4 ;
  int tmp___5 ;
  {
  item_found = (symdir_t *)((void *)0);
  new_item = (symdir_t *)((void *)0);
  memset((void *)outkey, 0, sizeof(dirkey_t ));
  outkey->dev = (dev_t )0;
  outkey->ino = (ino_t )0;
  tmp = stat((char const * __restrict )path, (struct stat * __restrict )(& buf));
  res = tmp;
  if (res != 0) {
    log_err((char const *)"Error stat()ing: %s", path);
    return (-1);
  }
  outkey->dev = buf.st_dev;
  outkey->ino = buf.st_ino;
  {
  while (1) {
    while_continue: ;
    item_found = (symdir_t *)((void *)0);
    if (symhash) {
      {
      while (1) {
        while_continue___0: ;
        _hj_key = (unsigned char *)outkey;
        _hf_hashv = 0xfeedbeef;
        _hj_j = 0x9e3779b9;
        _hj_i = _hj_j;
        _hj_k = (unsigned int )sizeof(dirkey_t );
        {
        while (1) {
          while_continue___1: ;
          if (! (_hj_k >= 12U)) {
            goto while_break___1;
          }
          _hj_i += (((unsigned int )*(_hj_key + 0) + ((unsigned int )*(_hj_key + 1) << 8)) + ((unsigned int )*(_hj_key + 2) << 16)) + ((unsigned int )*(_hj_key + 3) << 24);
          _hj_j += (((unsigned int )*(_hj_key + 4) + ((unsigned int )*(_hj_key + 5) << 8)) + ((unsigned int )*(_hj_key + 6) << 16)) + ((unsigned int )*(_hj_key + 7) << 24);
          _hf_hashv += (((unsigned int )*(_hj_key + 8) + ((unsigned int )*(_hj_key + 9) << 8)) + ((unsigned int )*(_hj_key + 10) << 16)) + ((unsigned int )*(_hj_key + 11) << 24);
          {
          while (1) {
            while_continue___2: ;
            _hj_i -= _hj_j;
            _hj_i -= _hf_hashv;
            _hj_i ^= _hf_hashv >> 13;
            _hj_j -= _hf_hashv;
            _hj_j -= _hj_i;
            _hj_j ^= _hj_i << 8;
            _hf_hashv -= _hj_i;
            _hf_hashv -= _hj_j;
            _hf_hashv ^= _hj_j >> 13;
            _hj_i -= _hj_j;
            _hj_i -= _hf_hashv;
            _hj_i ^= _hf_hashv >> 12;
            _hj_j -= _hf_hashv;
            _hj_j -= _hj_i;
            _hj_j ^= _hj_i << 16;
            _hf_hashv -= _hj_i;
            _hf_hashv -= _hj_j;
            _hf_hashv ^= _hj_j >> 5;
            _hj_i -= _hj_j;
            _hj_i -= _hf_hashv;
            _hj_i ^= _hf_hashv >> 3;
            _hj_j -= _hf_hashv;
            _hj_j -= _hj_i;
            _hj_j ^= _hj_i << 10;
            _hf_hashv -= _hj_i;
            _hf_hashv -= _hj_j;
            _hf_hashv ^= _hj_j >> 15;
            goto while_break___2;
          }
          while_break___2: ;
          }
          _hj_key += 12;
          _hj_k -= 12U;
        }
        while_break___1: ;
        }
        _hf_hashv = (unsigned int )((unsigned long )_hf_hashv + sizeof(dirkey_t ));
        {
        if (_hj_k == 11U) {
          goto case_11;
        }
        if (_hj_k == 10U) {
          goto case_10;
        }
        if (_hj_k == 9U) {
          goto case_9;
        }
        if (_hj_k == 8U) {
          goto case_8;
        }
        if (_hj_k == 7U) {
          goto case_7;
        }
        if (_hj_k == 6U) {
          goto case_6;
        }
        if (_hj_k == 5U) {
          goto case_5;
        }
        if (_hj_k == 4U) {
          goto case_4;
        }
        if (_hj_k == 3U) {
          goto case_3;
        }
        if (_hj_k == 2U) {
          goto case_2;
        }
        if (_hj_k == 1U) {
          goto case_1;
        }
        goto switch_break;
        case_11:
        _hf_hashv += (unsigned int )*(_hj_key + 10) << 24;
        case_10:
        _hf_hashv += (unsigned int )*(_hj_key + 9) << 16;
        case_9:
        _hf_hashv += (unsigned int )*(_hj_key + 8) << 8;
        case_8:
        _hj_j += (unsigned int )*(_hj_key + 7) << 24;
        case_7:
        _hj_j += (unsigned int )*(_hj_key + 6) << 16;
        case_6:
        _hj_j += (unsigned int )*(_hj_key + 5) << 8;
        case_5:
        _hj_j += (unsigned int )*(_hj_key + 4);
        case_4:
        _hj_i += (unsigned int )*(_hj_key + 3) << 24;
        case_3:
        _hj_i += (unsigned int )*(_hj_key + 2) << 16;
        case_2:
        _hj_i += (unsigned int )*(_hj_key + 1) << 8;
        case_1:
        _hj_i += (unsigned int )*(_hj_key + 0);
        switch_break: ;
        }
        {
        while (1) {
          while_continue___3: ;
          _hj_i -= _hj_j;
          _hj_i -= _hf_hashv;
          _hj_i ^= _hf_hashv >> 13;
          _hj_j -= _hf_hashv;
          _hj_j -= _hj_i;
          _hj_j ^= _hj_i << 8;
          _hf_hashv -= _hj_i;
          _hf_hashv -= _hj_j;
          _hf_hashv ^= _hj_j >> 13;
          _hj_i -= _hj_j;
          _hj_i -= _hf_hashv;
          _hj_i ^= _hf_hashv >> 12;
          _hj_j -= _hf_hashv;
          _hj_j -= _hj_i;
          _hj_j ^= _hj_i << 16;
          _hf_hashv -= _hj_i;
          _hf_hashv -= _hj_j;
          _hf_hashv ^= _hj_j >> 5;
          _hj_i -= _hj_j;
          _hj_i -= _hf_hashv;
          _hj_i ^= _hf_hashv >> 3;
          _hj_j -= _hf_hashv;
          _hj_j -= _hj_i;
          _hj_j ^= _hj_i << 10;
          _hf_hashv -= _hj_i;
          _hf_hashv -= _hj_j;
          _hf_hashv ^= _hj_j >> 15;
          goto while_break___3;
        }
        while_break___3: ;
        }
        _hf_bkt = _hf_hashv & ((symhash->hh.tbl)->num_buckets - 1U);
        goto while_break___0;
      }
      while_break___0: ;
      }
      {
      while (1) {
        while_continue___4: ;
        if (((symhash->hh.tbl)->buckets + _hf_bkt)->hh_head) {
          {
          while (1) {
            while_continue___5: ;
            item_found = (symdir_t *)((void *)((char *)((symhash->hh.tbl)->buckets + _hf_bkt)->hh_head - (symhash->hh.tbl)->hho));
            goto while_break___5;
          }
          while_break___5: ;
          }
        } else {
          item_found = (symdir_t *)((void *)0);
        }
        {
        while (1) {
          while_continue___6: ;
          if (! item_found) {
            goto while_break___6;
          }
          if ((unsigned long )item_found->hh.keylen == sizeof(dirkey_t )) {
            tmp___0 = memcmp((void const *)item_found->hh.key, (void const *)outkey,
                             sizeof(dirkey_t ));
            if (tmp___0 == 0) {
              goto while_break___6;
            }
          }
          if (item_found->hh.hh_next) {
            {
            while (1) {
              while_continue___7: ;
              item_found = (symdir_t *)((void *)((char *)item_found->hh.hh_next - (symhash->hh.tbl)->hho));
              goto while_break___7;
            }
            while_break___7: ;
            }
          } else {
            item_found = (symdir_t *)((void *)0);
          }
        }
        while_break___6: ;
        }
        goto while_break___4;
      }
      while_break___4: ;
      }
    }
    goto while_break;
  }
  while_break: ;
  }
  if (item_found) {
    return (1);
  }
  tmp___1 = ag_malloc(sizeof(symdir_t ));
  new_item = (symdir_t *)tmp___1;
  memcpy((void *)(& new_item->key), (void const *)outkey, sizeof(dirkey_t ));
  {
  while (1) {
    while_continue___8: ;
    new_item->hh.next = (void *)0;
    new_item->hh.key = (void *)((char *)(& new_item->key));
    new_item->hh.keylen = (unsigned int )sizeof(dirkey_t );
    if (! symhash) {
      symhash = new_item;
      symhash->hh.prev = (void *)0;
      {
      while (1) {
        while_continue___9: ;
        tmp___2 = malloc(sizeof(UT_hash_table ));
        symhash->hh.tbl = (UT_hash_table *)tmp___2;
        if (! symhash->hh.tbl) {
          exit(-1);
        }
        memset((void *)symhash->hh.tbl, 0, sizeof(UT_hash_table ));
        (symhash->hh.tbl)->tail = & symhash->hh;
        (symhash->hh.tbl)->num_buckets = 32U;
        (symhash->hh.tbl)->log2_num_buckets = 5U;
        (symhash->hh.tbl)->hho = (char *)(& symhash->hh) - (char *)symhash;
        tmp___3 = malloc(32UL * sizeof(struct UT_hash_bucket ));
        (symhash->hh.tbl)->buckets = (UT_hash_bucket *)tmp___3;
        if (! (symhash->hh.tbl)->buckets) {
          exit(-1);
        }
        memset((void *)(symhash->hh.tbl)->buckets, 0, 32UL * sizeof(struct UT_hash_bucket ));
        (symhash->hh.tbl)->signature = 0xa0111fe1;
        goto while_break___9;
      }
      while_break___9: ;
      }
    } else {
      ((symhash->hh.tbl)->tail)->next = (void *)new_item;
      new_item->hh.prev = (void *)((char *)(symhash->hh.tbl)->tail - (symhash->hh.tbl)->hho);
      (symhash->hh.tbl)->tail = & new_item->hh;
    }
    ((symhash->hh.tbl)->num_items) ++;
    new_item->hh.tbl = symhash->hh.tbl;
    {
    while (1) {
      while_continue___10: ;
      _hj_key___0 = (unsigned char *)(& new_item->key);
      new_item->hh.hashv = 0xfeedbeef;
      _hj_j___0 = 0x9e3779b9;
      _hj_i___0 = _hj_j___0;
      _hj_k___0 = (unsigned int )sizeof(dirkey_t );
      {
      while (1) {
        while_continue___11: ;
        if (! (_hj_k___0 >= 12U)) {
          goto while_break___11;
        }
        _hj_i___0 += (((unsigned int )*(_hj_key___0 + 0) + ((unsigned int )*(_hj_key___0 + 1) << 8)) + ((unsigned int )*(_hj_key___0 + 2) << 16)) + ((unsigned int )*(_hj_key___0 + 3) << 24);
        _hj_j___0 += (((unsigned int )*(_hj_key___0 + 4) + ((unsigned int )*(_hj_key___0 + 5) << 8)) + ((unsigned int )*(_hj_key___0 + 6) << 16)) + ((unsigned int )*(_hj_key___0 + 7) << 24);
        new_item->hh.hashv += (((unsigned int )*(_hj_key___0 + 8) + ((unsigned int )*(_hj_key___0 + 9) << 8)) + ((unsigned int )*(_hj_key___0 + 10) << 16)) + ((unsigned int )*(_hj_key___0 + 11) << 24);
        {
        while (1) {
          while_continue___12: ;
          _hj_i___0 -= _hj_j___0;
          _hj_i___0 -= new_item->hh.hashv;
          _hj_i___0 ^= new_item->hh.hashv >> 13;
          _hj_j___0 -= new_item->hh.hashv;
          _hj_j___0 -= _hj_i___0;
          _hj_j___0 ^= _hj_i___0 << 8;
          new_item->hh.hashv -= _hj_i___0;
          new_item->hh.hashv -= _hj_j___0;
          new_item->hh.hashv ^= _hj_j___0 >> 13;
          _hj_i___0 -= _hj_j___0;
          _hj_i___0 -= new_item->hh.hashv;
          _hj_i___0 ^= new_item->hh.hashv >> 12;
          _hj_j___0 -= new_item->hh.hashv;
          _hj_j___0 -= _hj_i___0;
          _hj_j___0 ^= _hj_i___0 << 16;
          new_item->hh.hashv -= _hj_i___0;
          new_item->hh.hashv -= _hj_j___0;
          new_item->hh.hashv ^= _hj_j___0 >> 5;
          _hj_i___0 -= _hj_j___0;
          _hj_i___0 -= new_item->hh.hashv;
          _hj_i___0 ^= new_item->hh.hashv >> 3;
          _hj_j___0 -= new_item->hh.hashv;
          _hj_j___0 -= _hj_i___0;
          _hj_j___0 ^= _hj_i___0 << 10;
          new_item->hh.hashv -= _hj_i___0;
          new_item->hh.hashv -= _hj_j___0;
          new_item->hh.hashv ^= _hj_j___0 >> 15;
          goto while_break___12;
        }
        while_break___12: ;
        }
        _hj_key___0 += 12;
        _hj_k___0 -= 12U;
      }
      while_break___11: ;
      }
      new_item->hh.hashv = (unsigned int )((unsigned long )new_item->hh.hashv + sizeof(dirkey_t ));
      {
      if (_hj_k___0 == 11U) {
        goto case_11___0;
      }
      if (_hj_k___0 == 10U) {
        goto case_10___0;
      }
      if (_hj_k___0 == 9U) {
        goto case_9___0;
      }
      if (_hj_k___0 == 8U) {
        goto case_8___0;
      }
      if (_hj_k___0 == 7U) {
        goto case_7___0;
      }
      if (_hj_k___0 == 6U) {
        goto case_6___0;
      }
      if (_hj_k___0 == 5U) {
        goto case_5___0;
      }
      if (_hj_k___0 == 4U) {
        goto case_4___0;
      }
      if (_hj_k___0 == 3U) {
        goto case_3___0;
      }
      if (_hj_k___0 == 2U) {
        goto case_2___0;
      }
      if (_hj_k___0 == 1U) {
        goto case_1___0;
      }
      goto switch_break___0;
      case_11___0:
      new_item->hh.hashv += (unsigned int )*(_hj_key___0 + 10) << 24;
      case_10___0:
      new_item->hh.hashv += (unsigned int )*(_hj_key___0 + 9) << 16;
      case_9___0:
      new_item->hh.hashv += (unsigned int )*(_hj_key___0 + 8) << 8;
      case_8___0:
      _hj_j___0 += (unsigned int )*(_hj_key___0 + 7) << 24;
      case_7___0:
      _hj_j___0 += (unsigned int )*(_hj_key___0 + 6) << 16;
      case_6___0:
      _hj_j___0 += (unsigned int )*(_hj_key___0 + 5) << 8;
      case_5___0:
      _hj_j___0 += (unsigned int )*(_hj_key___0 + 4);
      case_4___0:
      _hj_i___0 += (unsigned int )*(_hj_key___0 + 3) << 24;
      case_3___0:
      _hj_i___0 += (unsigned int )*(_hj_key___0 + 2) << 16;
      case_2___0:
      _hj_i___0 += (unsigned int )*(_hj_key___0 + 1) << 8;
      case_1___0:
      _hj_i___0 += (unsigned int )*(_hj_key___0 + 0);
      switch_break___0: ;
      }
      {
      while (1) {
        while_continue___13: ;
        _hj_i___0 -= _hj_j___0;
        _hj_i___0 -= new_item->hh.hashv;
        _hj_i___0 ^= new_item->hh.hashv >> 13;
        _hj_j___0 -= new_item->hh.hashv;
        _hj_j___0 -= _hj_i___0;
        _hj_j___0 ^= _hj_i___0 << 8;
        new_item->hh.hashv -= _hj_i___0;
        new_item->hh.hashv -= _hj_j___0;
        new_item->hh.hashv ^= _hj_j___0 >> 13;
        _hj_i___0 -= _hj_j___0;
        _hj_i___0 -= new_item->hh.hashv;
        _hj_i___0 ^= new_item->hh.hashv >> 12;
        _hj_j___0 -= new_item->hh.hashv;
        _hj_j___0 -= _hj_i___0;
        _hj_j___0 ^= _hj_i___0 << 16;
        new_item->hh.hashv -= _hj_i___0;
        new_item->hh.hashv -= _hj_j___0;
        new_item->hh.hashv ^= _hj_j___0 >> 5;
        _hj_i___0 -= _hj_j___0;
        _hj_i___0 -= new_item->hh.hashv;
        _hj_i___0 ^= new_item->hh.hashv >> 3;
        _hj_j___0 -= new_item->hh.hashv;
        _hj_j___0 -= _hj_i___0;
        _hj_j___0 ^= _hj_i___0 << 10;
        new_item->hh.hashv -= _hj_i___0;
        new_item->hh.hashv -= _hj_j___0;
        new_item->hh.hashv ^= _hj_j___0 >> 15;
        goto while_break___13;
      }
      while_break___13: ;
      }
      _ha_bkt = new_item->hh.hashv & ((symhash->hh.tbl)->num_buckets - 1U);
      goto while_break___10;
    }
    while_break___10: ;
    }
    {
    while (1) {
      while_continue___14: ;
      (((symhash->hh.tbl)->buckets + _ha_bkt)->count) ++;
      new_item->hh.hh_next = ((symhash->hh.tbl)->buckets + _ha_bkt)->hh_head;
      new_item->hh.hh_prev = (struct UT_hash_handle *)((void *)0);
      if (((symhash->hh.tbl)->buckets + _ha_bkt)->hh_head) {
        (((symhash->hh.tbl)->buckets + _ha_bkt)->hh_head)->hh_prev = & new_item->hh;
      }
      ((symhash->hh.tbl)->buckets + _ha_bkt)->hh_head = & new_item->hh;
      if (((symhash->hh.tbl)->buckets + _ha_bkt)->count >= (((symhash->hh.tbl)->buckets + _ha_bkt)->expand_mult + 1U) * 10U) {
        if ((new_item->hh.tbl)->noexpand != 1U) {
          {
          while (1) {
            while_continue___15: ;
            tmp___4 = malloc((unsigned long )(2U * (new_item->hh.tbl)->num_buckets) * sizeof(struct UT_hash_bucket ));
            _he_new_buckets = (UT_hash_bucket *)tmp___4;
            if (! _he_new_buckets) {
              exit(-1);
            }
            memset((void *)_he_new_buckets, 0, (unsigned long )(2U * (new_item->hh.tbl)->num_buckets) * sizeof(struct UT_hash_bucket ));
            if ((new_item->hh.tbl)->num_items & ((new_item->hh.tbl)->num_buckets * 2U - 1U)) {
              tmp___5 = 1;
            } else {
              tmp___5 = 0;
            }
            (new_item->hh.tbl)->ideal_chain_maxlen = ((new_item->hh.tbl)->num_items >> ((new_item->hh.tbl)->log2_num_buckets + 1U)) + (unsigned int )tmp___5;
            (new_item->hh.tbl)->nonideal_items = 0U;
            _he_bkt_i = 0U;
            {
            while (1) {
              while_continue___16: ;
              if (! (_he_bkt_i < (new_item->hh.tbl)->num_buckets)) {
                goto while_break___16;
              }
              _he_thh = ((new_item->hh.tbl)->buckets + _he_bkt_i)->hh_head;
              {
              while (1) {
                while_continue___17: ;
                if (! _he_thh) {
                  goto while_break___17;
                }
                _he_hh_nxt = _he_thh->hh_next;
                {
                while (1) {
                  while_continue___18: ;
                  _he_bkt = _he_thh->hashv & ((new_item->hh.tbl)->num_buckets * 2U - 1U);
                  goto while_break___18;
                }
                while_break___18: ;
                }
                _he_newbkt = _he_new_buckets + _he_bkt;
                (_he_newbkt->count) ++;
                if (_he_newbkt->count > (new_item->hh.tbl)->ideal_chain_maxlen) {
                  ((new_item->hh.tbl)->nonideal_items) ++;
                  _he_newbkt->expand_mult = _he_newbkt->count / (new_item->hh.tbl)->ideal_chain_maxlen;
                }
                _he_thh->hh_prev = (struct UT_hash_handle *)((void *)0);
                _he_thh->hh_next = _he_newbkt->hh_head;
                if (_he_newbkt->hh_head) {
                  (_he_newbkt->hh_head)->hh_prev = _he_thh;
                }
                _he_newbkt->hh_head = _he_thh;
                _he_thh = _he_hh_nxt;
              }
              while_break___17: ;
              }
              _he_bkt_i ++;
            }
            while_break___16: ;
            }
            free((void *)(new_item->hh.tbl)->buckets);
            (new_item->hh.tbl)->num_buckets *= 2U;
            ((new_item->hh.tbl)->log2_num_buckets) ++;
            (new_item->hh.tbl)->buckets = _he_new_buckets;
            if ((new_item->hh.tbl)->nonideal_items > (new_item->hh.tbl)->num_items >> 1) {
              ((new_item->hh.tbl)->ineff_expands) ++;
            } else {
              (new_item->hh.tbl)->ineff_expands = 0U;
            }
            if ((new_item->hh.tbl)->ineff_expands > 1U) {
              (new_item->hh.tbl)->noexpand = 1U;
            }
            goto while_break___15;
          }
          while_break___15: ;
          }
        }
      }
      goto while_break___14;
    }
    while_break___14: ;
    }
    goto while_break___8;
  }
  while_break___8: ;
  }
  return (0);
}
}
static int check_symloop_leave(dirkey_t *dirkey )
{
  symdir_t *item_found ;
  unsigned int _hf_bkt ;
  unsigned int _hf_hashv ;
  unsigned int _hj_i ;
  unsigned int _hj_j ;
  unsigned int _hj_k ;
  unsigned char *_hj_key ;
  int tmp ;
  unsigned int _hd_bkt ;
  struct UT_hash_handle *_hd_hh_del ;
  {
  item_found = (symdir_t *)((void *)0);
  if (dirkey->dev == 0UL) {
    if (dirkey->ino == 0UL) {
      return (-1);
    }
  }
  {
  while (1) {
    while_continue: ;
    item_found = (symdir_t *)((void *)0);
    if (symhash) {
      {
      while (1) {
        while_continue___0: ;
        _hj_key = (unsigned char *)dirkey;
        _hf_hashv = 0xfeedbeef;
        _hj_j = 0x9e3779b9;
        _hj_i = _hj_j;
        _hj_k = (unsigned int )sizeof(dirkey_t );
        {
        while (1) {
          while_continue___1: ;
          if (! (_hj_k >= 12U)) {
            goto while_break___1;
          }
          _hj_i += (((unsigned int )*(_hj_key + 0) + ((unsigned int )*(_hj_key + 1) << 8)) + ((unsigned int )*(_hj_key + 2) << 16)) + ((unsigned int )*(_hj_key + 3) << 24);
          _hj_j += (((unsigned int )*(_hj_key + 4) + ((unsigned int )*(_hj_key + 5) << 8)) + ((unsigned int )*(_hj_key + 6) << 16)) + ((unsigned int )*(_hj_key + 7) << 24);
          _hf_hashv += (((unsigned int )*(_hj_key + 8) + ((unsigned int )*(_hj_key + 9) << 8)) + ((unsigned int )*(_hj_key + 10) << 16)) + ((unsigned int )*(_hj_key + 11) << 24);
          {
          while (1) {
            while_continue___2: ;
            _hj_i -= _hj_j;
            _hj_i -= _hf_hashv;
            _hj_i ^= _hf_hashv >> 13;
            _hj_j -= _hf_hashv;
            _hj_j -= _hj_i;
            _hj_j ^= _hj_i << 8;
            _hf_hashv -= _hj_i;
            _hf_hashv -= _hj_j;
            _hf_hashv ^= _hj_j >> 13;
            _hj_i -= _hj_j;
            _hj_i -= _hf_hashv;
            _hj_i ^= _hf_hashv >> 12;
            _hj_j -= _hf_hashv;
            _hj_j -= _hj_i;
            _hj_j ^= _hj_i << 16;
            _hf_hashv -= _hj_i;
            _hf_hashv -= _hj_j;
            _hf_hashv ^= _hj_j >> 5;
            _hj_i -= _hj_j;
            _hj_i -= _hf_hashv;
            _hj_i ^= _hf_hashv >> 3;
            _hj_j -= _hf_hashv;
            _hj_j -= _hj_i;
            _hj_j ^= _hj_i << 10;
            _hf_hashv -= _hj_i;
            _hf_hashv -= _hj_j;
            _hf_hashv ^= _hj_j >> 15;
            goto while_break___2;
          }
          while_break___2: ;
          }
          _hj_key += 12;
          _hj_k -= 12U;
        }
        while_break___1: ;
        }
        _hf_hashv = (unsigned int )((unsigned long )_hf_hashv + sizeof(dirkey_t ));
        {
        if (_hj_k == 11U) {
          goto case_11;
        }
        if (_hj_k == 10U) {
          goto case_10;
        }
        if (_hj_k == 9U) {
          goto case_9;
        }
        if (_hj_k == 8U) {
          goto case_8;
        }
        if (_hj_k == 7U) {
          goto case_7;
        }
        if (_hj_k == 6U) {
          goto case_6;
        }
        if (_hj_k == 5U) {
          goto case_5;
        }
        if (_hj_k == 4U) {
          goto case_4;
        }
        if (_hj_k == 3U) {
          goto case_3;
        }
        if (_hj_k == 2U) {
          goto case_2;
        }
        if (_hj_k == 1U) {
          goto case_1;
        }
        goto switch_break;
        case_11:
        _hf_hashv += (unsigned int )*(_hj_key + 10) << 24;
        case_10:
        _hf_hashv += (unsigned int )*(_hj_key + 9) << 16;
        case_9:
        _hf_hashv += (unsigned int )*(_hj_key + 8) << 8;
        case_8:
        _hj_j += (unsigned int )*(_hj_key + 7) << 24;
        case_7:
        _hj_j += (unsigned int )*(_hj_key + 6) << 16;
        case_6:
        _hj_j += (unsigned int )*(_hj_key + 5) << 8;
        case_5:
        _hj_j += (unsigned int )*(_hj_key + 4);
        case_4:
        _hj_i += (unsigned int )*(_hj_key + 3) << 24;
        case_3:
        _hj_i += (unsigned int )*(_hj_key + 2) << 16;
        case_2:
        _hj_i += (unsigned int )*(_hj_key + 1) << 8;
        case_1:
        _hj_i += (unsigned int )*(_hj_key + 0);
        switch_break: ;
        }
        {
        while (1) {
          while_continue___3: ;
          _hj_i -= _hj_j;
          _hj_i -= _hf_hashv;
          _hj_i ^= _hf_hashv >> 13;
          _hj_j -= _hf_hashv;
          _hj_j -= _hj_i;
          _hj_j ^= _hj_i << 8;
          _hf_hashv -= _hj_i;
          _hf_hashv -= _hj_j;
          _hf_hashv ^= _hj_j >> 13;
          _hj_i -= _hj_j;
          _hj_i -= _hf_hashv;
          _hj_i ^= _hf_hashv >> 12;
          _hj_j -= _hf_hashv;
          _hj_j -= _hj_i;
          _hj_j ^= _hj_i << 16;
          _hf_hashv -= _hj_i;
          _hf_hashv -= _hj_j;
          _hf_hashv ^= _hj_j >> 5;
          _hj_i -= _hj_j;
          _hj_i -= _hf_hashv;
          _hj_i ^= _hf_hashv >> 3;
          _hj_j -= _hf_hashv;
          _hj_j -= _hj_i;
          _hj_j ^= _hj_i << 10;
          _hf_hashv -= _hj_i;
          _hf_hashv -= _hj_j;
          _hf_hashv ^= _hj_j >> 15;
          goto while_break___3;
        }
        while_break___3: ;
        }
        _hf_bkt = _hf_hashv & ((symhash->hh.tbl)->num_buckets - 1U);
        goto while_break___0;
      }
      while_break___0: ;
      }
      {
      while (1) {
        while_continue___4: ;
        if (((symhash->hh.tbl)->buckets + _hf_bkt)->hh_head) {
          {
          while (1) {
            while_continue___5: ;
            item_found = (symdir_t *)((void *)((char *)((symhash->hh.tbl)->buckets + _hf_bkt)->hh_head - (symhash->hh.tbl)->hho));
            goto while_break___5;
          }
          while_break___5: ;
          }
        } else {
          item_found = (symdir_t *)((void *)0);
        }
        {
        while (1) {
          while_continue___6: ;
          if (! item_found) {
            goto while_break___6;
          }
          if ((unsigned long )item_found->hh.keylen == sizeof(dirkey_t )) {
            tmp = memcmp((void const *)item_found->hh.key, (void const *)dirkey,
                         sizeof(dirkey_t ));
            if (tmp == 0) {
              goto while_break___6;
            }
          }
          if (item_found->hh.hh_next) {
            {
            while (1) {
              while_continue___7: ;
              item_found = (symdir_t *)((void *)((char *)item_found->hh.hh_next - (symhash->hh.tbl)->hho));
              goto while_break___7;
            }
            while_break___7: ;
            }
          } else {
            item_found = (symdir_t *)((void *)0);
          }
        }
        while_break___6: ;
        }
        goto while_break___4;
      }
      while_break___4: ;
      }
    }
    goto while_break;
  }
  while_break: ;
  }
  if (! item_found) {
    log_err((char const *)"item not found! weird stuff...\n");
    return (-1);
  }
  {
  while (1) {
    while_continue___8: ;
    if ((unsigned long )item_found->hh.prev == (unsigned long )((void *)0)) {
      if ((unsigned long )item_found->hh.next == (unsigned long )((void *)0)) {
        free((void *)(symhash->hh.tbl)->buckets);
        free((void *)symhash->hh.tbl);
        symhash = (symdir_t *)((void *)0);
      } else {
        goto _L;
      }
    } else {
      _L:
      _hd_hh_del = & item_found->hh;
      if ((unsigned long )item_found == (unsigned long )((void *)((char *)(symhash->hh.tbl)->tail - (symhash->hh.tbl)->hho))) {
        (symhash->hh.tbl)->tail = (UT_hash_handle *)((ptrdiff_t )item_found->hh.prev + (symhash->hh.tbl)->hho);
      }
      if (item_found->hh.prev) {
        ((UT_hash_handle *)((ptrdiff_t )item_found->hh.prev + (symhash->hh.tbl)->hho))->next = item_found->hh.next;
      } else {
        {
        while (1) {
          while_continue___9: ;
          symhash = (symdir_t *)item_found->hh.next;
          goto while_break___9;
        }
        while_break___9: ;
        }
      }
      if (_hd_hh_del->next) {
        ((UT_hash_handle *)((ptrdiff_t )_hd_hh_del->next + (symhash->hh.tbl)->hho))->prev = _hd_hh_del->prev;
      }
      {
      while (1) {
        while_continue___10: ;
        _hd_bkt = _hd_hh_del->hashv & ((symhash->hh.tbl)->num_buckets - 1U);
        goto while_break___10;
      }
      while_break___10: ;
      }
      (((symhash->hh.tbl)->buckets + _hd_bkt)->count) --;
      if ((unsigned long )((symhash->hh.tbl)->buckets + _hd_bkt)->hh_head == (unsigned long )_hd_hh_del) {
        ((symhash->hh.tbl)->buckets + _hd_bkt)->hh_head = _hd_hh_del->hh_next;
      }
      if (_hd_hh_del->hh_prev) {
        (_hd_hh_del->hh_prev)->hh_next = _hd_hh_del->hh_next;
      }
      if (_hd_hh_del->hh_next) {
        (_hd_hh_del->hh_next)->hh_prev = _hd_hh_del->hh_prev;
      }
      ((symhash->hh.tbl)->num_items) --;
    }
    goto while_break___8;
  }
  while_break___8: ;
  }
  free((void *)item_found);
  return (0);
}
}
void search_dir(ignores *ig , char const *base_path , char const *path , int const depth ,
                dev_t original_dev )
{
  struct dirent **dir_list ;
  struct dirent *dir ;
  scandir_baton_t scandir_baton ;
  int results ;
  size_t base_path_len ;
  char const *path_start ;
  char *dir_full_path ;
  char const *ignore_file ;
  int i ;
  int symres ;
  dirkey_t current_dirkey ;
  int tmp ;
  size_t tmp___0 ;
  int *tmp___1 ;
  char *tmp___2 ;
  int *tmp___3 ;
  int offset_vector[3] ;
  int rc ;
  work_queue_t *queue_item ;
  struct stat s ;
  int tmp___4 ;
  int tmp___5 ;
  size_t tmp___6 ;
  void *tmp___7 ;
  ignores *child_ig ;
  size_t tmp___8 ;
  int tmp___9 ;
  {
  dir_list = (struct dirent **)((void *)0);
  dir = (struct dirent *)((void *)0);
  results = 0;
  base_path_len = (size_t )0;
  path_start = path;
  dir_full_path = (char *)((void *)0);
  ignore_file = (char const *)((void *)0);
  symres = check_symloop_enter(path, & current_dirkey);
  if (symres == 1) {
    log_err((char const *)"Recursive directory loop: %s", path);
    return;
  }
  i = 0;
  {
  while (1) {
    while_continue: ;
    if (opts.skip_vcs_ignores) {
      tmp = i == 0;
    } else {
      tmp = (unsigned long )ignore_pattern_files[i] != (unsigned long )((void *)0);
    }
    if (! tmp) {
      goto while_break;
    }
    ignore_file = ignore_pattern_files[i];
    ag_asprintf(& dir_full_path, (char const *)"%s/%s", path, ignore_file);
    load_ignore_patterns(ig, (char const *)dir_full_path);
    free((void *)dir_full_path);
    dir_full_path = (char *)((void *)0);
    i ++;
  }
  while_break: ;
  }
  if (base_path) {
    tmp___0 = strlen(base_path);
    base_path_len = tmp___0;
  } else {
    base_path_len = (size_t )0;
  }
  i = 0;
  {
  while (1) {
    while_continue___0: ;
    if ((size_t )i < base_path_len) {
      if (*(path + i)) {
        if (! ((int const )*(base_path + i) == (int const )*(path + i))) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
    } else {
      goto while_break___0;
    }
    path_start = (path + i) + 1;
    i ++;
  }
  while_break___0: ;
  }
  log_debug((char const *)"search_dir: path is \'%s\', base_path is \'%s\', path_start is \'%s\'",
            path, base_path, path_start);
  scandir_baton.ig = (ignores const *)ig;
  scandir_baton.base_path = base_path;
  scandir_baton.base_path_len = base_path_len;
  scandir_baton.path_start = path_start;
  results = ag_scandir(path, & dir_list, & filename_filter, (void *)(& scandir_baton));
  if (results == 0) {
    log_debug((char const *)"No results found in directory %s", path);
    goto search_dir_cleanup;
  } else
  if (results == -1) {
    tmp___3 = __errno_location();
    if (*tmp___3 == 20) {
      if (depth == 0) {
        if (opts.paths_len == 1) {
          if (opts.print_path == 0) {
            opts.print_path = 4;
          } else
          if (opts.print_path == 1) {
            opts.print_path = 4;
          }
          if (opts.only_matching) {
            if (opts.print_path == 4) {
              opts.print_line_numbers = 0;
            }
          }
        }
      }
      search_file(path);
    } else {
      tmp___1 = __errno_location();
      tmp___2 = strerror(*tmp___1);
      log_err((char const *)"Error opening directory %s: %s", path, tmp___2);
    }
    goto search_dir_cleanup;
  }
  rc = 0;
  i = 0;
  {
  while (1) {
    while_continue___1: ;
    if (! (i < results)) {
      goto while_break___1;
    }
    queue_item = (work_queue_t *)((void *)0);
    dir = *(dir_list + i);
    ag_asprintf(& dir_full_path, (char const *)"%s/%s", path, dir->d_name);
    if (opts.one_dev) {
      tmp___4 = lstat((char const * __restrict )dir_full_path, (struct stat * __restrict )(& s));
      if (tmp___4 != 0) {
        log_err((char const *)"Failed to get device information for %s. Skipping...",
                dir->d_name);
        goto cleanup;
      }
      if (s.st_dev != original_dev) {
        log_debug((char const *)"File %s crosses a device boundary (is probably a mount point.) Skipping...",
                  dir->d_name);
        goto cleanup;
      }
    }
    if (! opts.follow_symlinks) {
      tmp___5 = is_symlink(path, (struct dirent const *)dir);
      if (tmp___5) {
        log_debug((char const *)"File %s ignored becaused it\'s a symlink", dir->d_name);
        goto cleanup;
      }
    }
    tmp___9 = is_directory(path, (struct dirent const *)dir);
    if (tmp___9) {
      if (opts.recurse_dirs) {
        if (depth < (int const )opts.max_search_depth) {
          log_debug((char const *)"Searching dir %s", dir_full_path);
          tmp___8 = strlen((char const *)(dir->d_name));
          child_ig = init_ignore(ig, (char const *)(dir->d_name), (size_t const )tmp___8);
          search_dir(child_ig, base_path, (char const *)dir_full_path, depth + 1,
                     original_dev);
          cleanup_ignore(child_ig);
        } else
        if (opts.max_search_depth == -1) {
          log_debug((char const *)"Searching dir %s", dir_full_path);
          tmp___8 = strlen((char const *)(dir->d_name));
          child_ig = init_ignore(ig, (char const *)(dir->d_name), (size_t const )tmp___8);
          search_dir(child_ig, base_path, (char const *)dir_full_path, depth + 1,
                     original_dev);
          cleanup_ignore(child_ig);
        } else
        if (opts.max_search_depth == 25) {
          log_err((char const *)"Skipping %s. Use the --depth option to search deeper.",
                  dir_full_path);
        } else {
          log_debug((char const *)"Skipping %s. Use the --depth option to search deeper.",
                    dir_full_path);
        }
      }
    } else {
      if (opts.file_search_regex) {
        tmp___6 = strlen((char const *)dir_full_path);
        rc = pcre_exec((pcre const *)opts.file_search_regex, (pcre_extra const *)((void *)0),
                       (char const *)dir_full_path, (int )tmp___6, 0, 0, offset_vector,
                       3);
        if (rc < 0) {
          log_debug((char const *)"Skipping %s due to file_search_regex.", dir_full_path);
          goto cleanup;
        } else
        if (opts.match_files) {
          log_debug((char const *)"match_files: file_search_regex matched for %s.",
                    dir_full_path);
          pthread_mutex_lock(& print_mtx);
          print_path((char const *)dir_full_path, (char const )opts.path_sep);
          pthread_mutex_unlock(& print_mtx);
          opts.match_found = 1;
          goto cleanup;
        }
      }
      tmp___7 = ag_malloc(sizeof(work_queue_t ));
      queue_item = (work_queue_t *)tmp___7;
      queue_item->path = dir_full_path;
      queue_item->next = (struct work_queue_t *)((void *)0);
      pthread_mutex_lock(& work_queue_mtx);
      if ((unsigned long )work_queue_tail == (unsigned long )((void *)0)) {
        work_queue = queue_item;
      } else {
        work_queue_tail->next = queue_item;
      }
      work_queue_tail = queue_item;
      pthread_cond_signal(& files_ready);
      pthread_mutex_unlock(& work_queue_mtx);
      log_debug((char const *)"%s added to work queue", dir_full_path);
    }
    cleanup:
    free((void *)dir);
    dir = (struct dirent *)((void *)0);
    if ((unsigned long )queue_item == (unsigned long )((void *)0)) {
      free((void *)dir_full_path);
      dir_full_path = (char *)((void *)0);
    }
    i ++;
  }
  while_break___1: ;
  }
  search_dir_cleanup:
  check_symloop_leave(& current_dirkey);
  free((void *)dir_list);
  dir_list = (struct dirent **)((void *)0);
  return;
}
}
lang_spec_t langs[138] =
  { {(char const *)"actionscript", {(char const *)"as", (char const *)"mxml"}},
        {(char const *)"ada",
      {(char const *)"ada", (char const *)"adb", (char const *)"ads"}},
        {(char const *)"asciidoc", {(char const *)"adoc", (char const *)"ad", (char const *)"asc",
                                   (char const *)"asciidoc"}},
        {(char const *)"apl", {(char const *)"apl"}},
        {(char const *)"asm", {(char const *)"asm", (char const *)"s"}},
        {(char const *)"asp", {(char const *)"asp", (char const *)"asa", (char const *)"aspx",
                              (char const *)"asax", (char const *)"ashx", (char const *)"ascx",
                              (char const *)"asmx"}},
        {(char const *)"aspx", {(char const *)"asp", (char const *)"asa", (char const *)"aspx",
                               (char const *)"asax", (char const *)"ashx", (char const *)"ascx",
                               (char const *)"asmx"}},
        {(char const *)"batch", {(char const *)"bat", (char const *)"cmd"}},
        {(char const *)"bazel", {(char const *)"bazel"}},
        {(char const *)"bitbake", {(char const *)"bb", (char const *)"bbappend",
                                  (char const *)"bbclass", (char const *)"inc"}},
        {(char const *)"cc",
      {(char const *)"c", (char const *)"h", (char const *)"xs"}},
        {(char const *)"cfmx", {(char const *)"cfc", (char const *)"cfm", (char const *)"cfml"}},
        {(char const *)"chpl",
      {(char const *)"chpl"}},
        {(char const *)"clojure", {(char const *)"clj", (char const *)"cljs", (char const *)"cljc",
                                  (char const *)"cljx", (char const *)"edn"}},
        {(char const *)"coffee",
      {(char const *)"coffee", (char const *)"cjsx"}},
        {(char const *)"config", {(char const *)"config"}},
        {(char const *)"coq", {(char const *)"coq", (char const *)"g", (char const *)"v"}},
        {(char const *)"cpp",
      {(char const *)"cpp", (char const *)"cc", (char const *)"C", (char const *)"cxx",
       (char const *)"m", (char const *)"hpp", (char const *)"hh", (char const *)"h",
       (char const *)"H", (char const *)"hxx", (char const *)"tpp"}},
        {(char const *)"crystal", {(char const *)"cr", (char const *)"ecr"}},
        {(char const *)"csharp", {(char const *)"cs"}},
        {(char const *)"cshtml", {(char const *)"cshtml"}},
        {(char const *)"css", {(char const *)"css"}},
        {(char const *)"cython", {(char const *)"pyx", (char const *)"pxd", (char const *)"pxi"}},
        {(char const *)"delphi",
      {(char const *)"pas", (char const *)"int", (char const *)"dfm", (char const *)"nfm",
       (char const *)"dof", (char const *)"dpk", (char const *)"dpr", (char const *)"dproj",
       (char const *)"groupproj", (char const *)"bdsgroup", (char const *)"bdsproj"}},
        {(char const *)"dlang",
      {(char const *)"d", (char const *)"di"}},
        {(char const *)"dot", {(char const *)"dot", (char const *)"gv"}},
        {(char const *)"dts", {(char const *)"dts", (char const *)"dtsi"}},
        {(char const *)"ebuild", {(char const *)"ebuild", (char const *)"eclass"}},
        {(char const *)"elisp",
      {(char const *)"el"}},
        {(char const *)"elixir", {(char const *)"ex", (char const *)"eex", (char const *)"exs"}},
        {(char const *)"elm",
      {(char const *)"elm"}},
        {(char const *)"erlang", {(char const *)"erl", (char const *)"hrl"}},
        {(char const *)"factor", {(char const *)"factor"}},
        {(char const *)"fortran", {(char const *)"f", (char const *)"F", (char const *)"f77",
                                  (char const *)"f90", (char const *)"F90", (char const *)"f95",
                                  (char const *)"f03", (char const *)"for", (char const *)"ftn",
                                  (char const *)"fpp", (char const *)"FPP"}},
        {(char const *)"fsharp", {(char const *)"fs", (char const *)"fsi", (char const *)"fsx"}},
        {(char const *)"gettext",
      {(char const *)"po", (char const *)"pot", (char const *)"mo"}},
        {(char const *)"glsl", {(char const *)"vert", (char const *)"tesc", (char const *)"tese",
                               (char const *)"geom", (char const *)"frag", (char const *)"comp"}},
        {(char const *)"go",
      {(char const *)"go"}},
        {(char const *)"gradle", {(char const *)"gradle"}},
        {(char const *)"groovy", {(char const *)"groovy", (char const *)"gtmpl",
                                 (char const *)"gpp", (char const *)"grunit",
                                 (char const *)"gradle"}},
        {(char const *)"haml", {(char const *)"haml"}},
        {(char const *)"handlebars", {(char const *)"hbs"}},
        {(char const *)"haskell", {(char const *)"hs", (char const *)"hsig", (char const *)"lhs"}},
        {(char const *)"haxe",
      {(char const *)"hx"}},
        {(char const *)"hh", {(char const *)"h"}},
        {(char const *)"html", {(char const *)"htm", (char const *)"html", (char const *)"shtml",
                               (char const *)"xhtml"}},
        {(char const *)"idris", {(char const *)"idr", (char const *)"ipkg", (char const *)"lidr"}},
        {(char const *)"ini",
      {(char const *)"ini"}},
        {(char const *)"ipython", {(char const *)"ipynb"}},
        {(char const *)"isabelle", {(char const *)"thy"}},
        {(char const *)"j", {(char const *)"ijs"}},
        {(char const *)"jade", {(char const *)"jade"}},
        {(char const *)"java", {(char const *)"java", (char const *)"properties"}},
        {(char const *)"jinja2",
      {(char const *)"j2"}},
        {(char const *)"js", {(char const *)"es6", (char const *)"js", (char const *)"jsx",
                             (char const *)"vue"}},
        {(char const *)"json", {(char const *)"json"}},
        {(char const *)"jsp", {(char const *)"jsp", (char const *)"jspx", (char const *)"jhtm",
                              (char const *)"jhtml", (char const *)"jspf", (char const *)"tag",
                              (char const *)"tagf"}},
        {(char const *)"julia", {(char const *)"jl"}},
        {(char const *)"kotlin", {(char const *)"kt"}},
        {(char const *)"less", {(char const *)"less"}},
        {(char const *)"liquid", {(char const *)"liquid"}},
        {(char const *)"lisp", {(char const *)"lisp", (char const *)"lsp"}},
        {(char const *)"log", {(char const *)"log"}},
        {(char const *)"lua", {(char const *)"lua"}},
        {(char const *)"m4", {(char const *)"m4"}},
        {(char const *)"make", {(char const *)"Makefiles", (char const *)"mk",
                               (char const *)"mak"}},
        {(char const *)"mako", {(char const *)"mako"}},
        {(char const *)"markdown", {(char const *)"markdown", (char const *)"mdown",
                                   (char const *)"mdwn", (char const *)"mkdn",
                                   (char const *)"mkd", (char const *)"md"}},
        {(char const *)"mason", {(char const *)"mas", (char const *)"mhtml", (char const *)"mpl",
                                (char const *)"mtxt"}},
        {(char const *)"matlab", {(char const *)"m"}},
        {(char const *)"mathematica", {(char const *)"m", (char const *)"wl"}},
        {(char const *)"md",
      {(char const *)"markdown", (char const *)"mdown", (char const *)"mdwn",
       (char const *)"mkdn", (char const *)"mkd", (char const *)"md"}},
        {(char const *)"mercury", {(char const *)"m", (char const *)"moo"}},
        {(char const *)"naccess", {(char const *)"asa", (char const *)"rsa"}},
        {(char const *)"nim", {(char const *)"nim"}},
        {(char const *)"nix", {(char const *)"nix"}},
        {(char const *)"objc", {(char const *)"m", (char const *)"h"}},
        {(char const *)"objcpp", {(char const *)"mm", (char const *)"h"}},
        {(char const *)"ocaml", {(char const *)"ml", (char const *)"mli", (char const *)"mll",
                                (char const *)"mly"}},
        {(char const *)"octave", {(char const *)"m"}},
        {(char const *)"org", {(char const *)"org"}},
        {(char const *)"parrot", {(char const *)"pir", (char const *)"pasm", (char const *)"pmc",
                                 (char const *)"ops", (char const *)"pod", (char const *)"pg",
                                 (char const *)"tg"}},
        {(char const *)"pdb", {(char const *)"pdb"}},
        {(char const *)"perl", {(char const *)"pl", (char const *)"pm", (char const *)"pm6",
                               (char const *)"pod", (char const *)"t"}},
        {(char const *)"php", {(char const *)"php", (char const *)"phpt", (char const *)"php3",
                              (char const *)"php4", (char const *)"php5", (char const *)"phtml"}},
        {(char const *)"pike",
      {(char const *)"pike", (char const *)"pmod"}},
        {(char const *)"plist", {(char const *)"plist"}},
        {(char const *)"plone", {(char const *)"pt", (char const *)"cpt", (char const *)"metadata",
                                (char const *)"cpy", (char const *)"py", (char const *)"xml",
                                (char const *)"zcml"}},
        {(char const *)"powershell", {(char const *)"ps1"}},
        {(char const *)"proto", {(char const *)"proto"}},
        {(char const *)"ps1", {(char const *)"ps1"}},
        {(char const *)"pug", {(char const *)"pug"}},
        {(char const *)"puppet", {(char const *)"pp"}},
        {(char const *)"python", {(char const *)"py"}},
        {(char const *)"qml", {(char const *)"qml"}},
        {(char const *)"racket", {(char const *)"rkt", (char const *)"ss", (char const *)"scm"}},
        {(char const *)"rake",
      {(char const *)"Rakefile"}},
        {(char const *)"razor", {(char const *)"cshtml"}},
        {(char const *)"restructuredtext", {(char const *)"rst"}},
        {(char const *)"rs", {(char const *)"rs"}},
        {(char const *)"r", {(char const *)"r", (char const *)"R", (char const *)"Rmd",
                            (char const *)"Rnw", (char const *)"Rtex", (char const *)"Rrst"}},
        {(char const *)"rdoc",
      {(char const *)"rdoc"}},
        {(char const *)"ruby", {(char const *)"rb", (char const *)"rhtml", (char const *)"rjs",
                               (char const *)"rxml", (char const *)"erb", (char const *)"rake",
                               (char const *)"spec"}},
        {(char const *)"rust", {(char const *)"rs"}},
        {(char const *)"salt", {(char const *)"sls"}},
        {(char const *)"sass", {(char const *)"sass", (char const *)"scss"}},
        {(char const *)"scala", {(char const *)"scala"}},
        {(char const *)"scheme", {(char const *)"scm", (char const *)"ss"}},
        {(char const *)"shell", {(char const *)"sh", (char const *)"bash", (char const *)"csh",
                                (char const *)"tcsh", (char const *)"ksh", (char const *)"zsh",
                                (char const *)"fish"}},
        {(char const *)"smalltalk", {(char const *)"st"}},
        {(char const *)"sml", {(char const *)"sml", (char const *)"fun", (char const *)"mlb",
                              (char const *)"sig"}},
        {(char const *)"sql", {(char const *)"sql", (char const *)"ctl"}},
        {(char const *)"stata", {(char const *)"do", (char const *)"ado"}},
        {(char const *)"stylus", {(char const *)"styl"}},
        {(char const *)"swift", {(char const *)"swift"}},
        {(char const *)"tcl", {(char const *)"tcl", (char const *)"itcl", (char const *)"itk"}},
        {(char const *)"terraform",
      {(char const *)"tf", (char const *)"tfvars"}},
        {(char const *)"tex", {(char const *)"tex", (char const *)"cls", (char const *)"sty"}},
        {(char const *)"thrift",
      {(char const *)"thrift"}},
        {(char const *)"tla", {(char const *)"tla"}},
        {(char const *)"tt", {(char const *)"tt", (char const *)"tt2", (char const *)"ttml"}},
        {(char const *)"toml",
      {(char const *)"toml"}},
        {(char const *)"ts", {(char const *)"ts", (char const *)"tsx"}},
        {(char const *)"twig", {(char const *)"twig"}},
        {(char const *)"vala", {(char const *)"vala", (char const *)"vapi"}},
        {(char const *)"vb", {(char const *)"bas", (char const *)"cls", (char const *)"frm",
                             (char const *)"ctl", (char const *)"vb", (char const *)"resx"}},
        {(char const *)"velocity",
      {(char const *)"vm", (char const *)"vtl", (char const *)"vsl"}},
        {(char const *)"verilog", {(char const *)"v", (char const *)"vh", (char const *)"sv",
                                  (char const *)"svh"}},
        {(char const *)"vhdl", {(char const *)"vhd", (char const *)"vhdl"}},
        {(char const *)"vim", {(char const *)"vim"}},
        {(char const *)"vue", {(char const *)"vue"}},
        {(char const *)"wix", {(char const *)"wxi", (char const *)"wxs"}},
        {(char const *)"wsdl", {(char const *)"wsdl"}},
        {(char const *)"wadl", {(char const *)"wadl"}},
        {(char const *)"xml", {(char const *)"xml", (char const *)"dtd", (char const *)"xsl",
                              (char const *)"xslt", (char const *)"xsd", (char const *)"ent",
                              (char const *)"tld", (char const *)"plist", (char const *)"wsdl"}},
        {(char const *)"yaml",
      {(char const *)"yaml", (char const *)"yml"}},
        {(char const *)"zeek", {(char const *)"zeek", (char const *)"bro", (char const *)"bif"}},
        {(char const *)"zephir",
      {(char const *)"zep"}}};
size_t get_lang_count(void)
{
  {
  return (sizeof(langs) / sizeof(lang_spec_t ));
}
}
char *make_lang_regex(char *ext_array , size_t num_exts )
{
  int regex_capacity ;
  char *regex ;
  void *tmp ;
  int regex_length ;
  int subsequent ;
  char *extension ;
  size_t i ;
  int extension_length ;
  size_t tmp___0 ;
  void *tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  {
  regex_capacity = 100;
  tmp = ag_malloc((size_t )regex_capacity);
  regex = (char *)tmp;
  regex_length = 3;
  subsequent = 0;
  strcpy(regex, (char const *)"\\.(");
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < num_exts)) {
      goto while_break;
    }
    extension = ext_array + i * 20UL;
    tmp___0 = strlen((char const *)extension);
    extension_length = (int )tmp___0;
    {
    while (1) {
      while_continue___0: ;
      if (! (((regex_length + extension_length) + 3) + subsequent > regex_capacity)) {
        goto while_break___0;
      }
      regex_capacity *= 2;
      tmp___1 = ag_realloc((void *)regex, (size_t )regex_capacity);
      regex = (char *)tmp___1;
    }
    while_break___0: ;
    }
    if (subsequent) {
      tmp___2 = regex_length;
      regex_length ++;
      *(regex + tmp___2) = (char )'|';
    } else {
      subsequent = 1;
    }
    strcpy(regex + regex_length, (char const *)extension);
    regex_length += extension_length;
    i ++;
  }
  while_break: ;
  }
  tmp___3 = regex_length;
  regex_length ++;
  *(regex + tmp___3) = (char )')';
  tmp___4 = regex_length;
  regex_length ++;
  *(regex + tmp___4) = (char )'$';
  tmp___5 = regex_length;
  regex_length ++;
  *(regex + tmp___5) = (char)0;
  return (regex);
}
}
size_t combine_file_extensions(size_t *extension_index , size_t len , char **exts )
{
  size_t ext_capacity ;
  void *tmp ;
  size_t num_of_extensions ;
  size_t i ;
  size_t j ;
  char const *ext ;
  char *pos ;
  size_t tmp___0 ;
  {
  ext_capacity = (size_t )100;
  tmp = ag_malloc(ext_capacity * 20UL);
  *exts = (char *)tmp;
  memset((void *)*exts, 0, ext_capacity * 20UL);
  num_of_extensions = (size_t )0;
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < len)) {
      goto while_break;
    }
    j = (size_t )0;
    ext = langs[*(extension_index + i)].extensions[j];
    {
    while (1) {
      while_continue___0: ;
      if (num_of_extensions == ext_capacity) {
        goto while_break___0;
      }
      pos = *exts + num_of_extensions * 20UL;
      tmp___0 = strlen(ext);
      strncpy(pos, ext, tmp___0);
      num_of_extensions ++;
      j ++;
      ext = langs[*(extension_index + i)].extensions[j];
      if (! ext) {
        goto while_break___0;
      }
    }
    while_break___0: ;
    }
    i ++;
  }
  while_break: ;
  }
  return (num_of_extensions);
}
}
ag_stats stats ;
FILE *out_fd = (FILE *)((void *)0);
void *ag_malloc(size_t size )
{
  void *ptr ;
  void *tmp ;
  {
  tmp = malloc(size);
  ptr = tmp;
  if ((unsigned long )ptr == (unsigned long )((void *)0)) {
    die((char const *)"Memory allocation failed.");
  }
  return (ptr);
}
}
void *ag_realloc(void *ptr , size_t size )
{
  void *new_ptr ;
  void *tmp ;
  {
  tmp = realloc(ptr, size);
  new_ptr = tmp;
  if ((unsigned long )new_ptr == (unsigned long )((void *)0)) {
    die((char const *)"Memory allocation failed.");
  }
  return (new_ptr);
}
}
void *ag_calloc(size_t count , size_t size )
{
  void *ptr ;
  void *tmp ;
  {
  tmp = calloc(count, size);
  ptr = tmp;
  if ((unsigned long )ptr == (unsigned long )((void *)0)) {
    die((char const *)"Memory allocation failed.");
  }
  return (ptr);
}
}
char *ag_strdup(char const *s )
{
  char *str ;
  char *tmp ;
  {
  tmp = strdup(s);
  str = tmp;
  if ((unsigned long )str == (unsigned long )((void *)0)) {
    die((char const *)"Memory allocation failed.");
  }
  return (str);
}
}
char *ag_strndup(char const *s , size_t size )
{
  char *str ;
  {
  str = (char *)((void *)0);
  str = strndup(s, size);
  if ((unsigned long )str == (unsigned long )((void *)0)) {
    die((char const *)"Memory allocation failed.");
  }
  return (str);
}
}
void free_strings(char **strs , size_t const strs_len )
{
  size_t i ;
  {
  if ((unsigned long )strs == (unsigned long )((void *)0)) {
    return;
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < (size_t )strs_len)) {
      goto while_break;
    }
    free((void *)*(strs + i));
    i ++;
  }
  while_break: ;
  }
  free((void *)strs);
  return;
}
}
void generate_alpha_skip(char const *find , size_t f_len , size_t *skip_lookup ,
                         int const case_sensitive )
{
  size_t i ;
  int __res ;
  int __c ;
  __int32_t const **tmp ;
  __int32_t const **tmp___0 ;
  int __res___0 ;
  int __c___0 ;
  __int32_t const **tmp___1 ;
  __int32_t const **tmp___2 ;
  {
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < 256UL)) {
      goto while_break;
    }
    *(skip_lookup + i) = f_len;
    i ++;
  }
  while_break: ;
  }
  f_len --;
  i = (size_t )0;
  {
  while (1) {
    while_continue___0: ;
    if (! (i < f_len)) {
      goto while_break___0;
    }
    if (case_sensitive) {
      *(skip_lookup + (unsigned char )*(find + i)) = f_len - i;
    } else {
      if (sizeof(*(find + i)) > 1UL) {
        __res = tolower((int )*(find + i));
      } else {
        tmp___0 = __ctype_tolower_loc();
        __res = (int )*(*tmp___0 + (int )*(find + i));
      }
      *(skip_lookup + (unsigned char )__res) = f_len - i;
      if (sizeof(*(find + i)) > 1UL) {
        __res___0 = toupper((int )*(find + i));
      } else {
        tmp___2 = __ctype_toupper_loc();
        __res___0 = (int )*(*tmp___2 + (int )*(find + i));
      }
      *(skip_lookup + (unsigned char )__res___0) = f_len - i;
    }
    i ++;
  }
  while_break___0: ;
  }
  return;
}
}
int is_prefix(char const *s , size_t const s_len , size_t const pos , int const case_sensitive )
{
  size_t i ;
  int __res ;
  int __c ;
  __int32_t const **tmp ;
  __int32_t const **tmp___0 ;
  int __res___0 ;
  int __c___0 ;
  __int32_t const **tmp___1 ;
  __int32_t const **tmp___2 ;
  {
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (pos + (size_t const )i < s_len)) {
      goto while_break;
    }
    if (case_sensitive) {
      if ((int const )*(s + i) != (int const )*(s + (i + (size_t )pos))) {
        return (0);
      }
    } else {
      if (sizeof(*(s + i)) > 1UL) {
        __res = tolower((int )*(s + i));
      } else {
        tmp___0 = __ctype_tolower_loc();
        __res = (int )*(*tmp___0 + (int )*(s + i));
      }
      if (sizeof(*(s + (i + (size_t )pos))) > 1UL) {
        __res___0 = tolower((int )*(s + (i + (size_t )pos)));
      } else {
        tmp___2 = __ctype_tolower_loc();
        __res___0 = (int )*(*tmp___2 + (int )*(s + (i + (size_t )pos)));
      }
      if (__res != __res___0) {
        return (0);
      }
    }
    i ++;
  }
  while_break: ;
  }
  return (1);
}
}
size_t suffix_len(char const *s , size_t const s_len , size_t const pos , int const case_sensitive )
{
  size_t i ;
  int __res ;
  int __c ;
  __int32_t const **tmp ;
  __int32_t const **tmp___0 ;
  int __res___0 ;
  int __c___0 ;
  __int32_t const **tmp___1 ;
  __int32_t const **tmp___2 ;
  {
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < (size_t )pos)) {
      goto while_break;
    }
    if (case_sensitive) {
      if ((int const )*(s + (pos - (size_t const )i)) != (int const )*(s + ((s_len - (size_t const )i) - 1UL))) {
        goto while_break;
      }
    } else {
      if (sizeof(*(s + (pos - (size_t const )i))) > 1UL) {
        __res = tolower((int )*(s + (pos - (size_t const )i)));
      } else {
        tmp___0 = __ctype_tolower_loc();
        __res = (int )*(*tmp___0 + (int )*(s + (pos - (size_t const )i)));
      }
      if (sizeof(*(s + ((s_len - (size_t const )i) - 1UL))) > 1UL) {
        __res___0 = tolower((int )*(s + ((s_len - (size_t const )i) - 1UL)));
      } else {
        tmp___2 = __ctype_tolower_loc();
        __res___0 = (int )*(*tmp___2 + (int )*(s + ((s_len - (size_t const )i) - 1UL)));
      }
      if (__res != __res___0) {
        goto while_break;
      }
    }
    i ++;
  }
  while_break: ;
  }
  return (i);
}
}
void generate_find_skip(char const *find , size_t const f_len , size_t **skip_lookup ,
                        int const case_sensitive )
{
  size_t i ;
  size_t s_len ;
  size_t *sl ;
  void *tmp ;
  size_t last_prefix ;
  int tmp___0 ;
  {
  tmp = ag_malloc((size_t )(f_len * (size_t const )sizeof(size_t )));
  sl = (size_t *)tmp;
  *skip_lookup = sl;
  last_prefix = (size_t )f_len;
  i = last_prefix;
  {
  while (1) {
    while_continue: ;
    if (! (i > 0UL)) {
      goto while_break;
    }
    tmp___0 = is_prefix(find, f_len, (size_t const )i, case_sensitive);
    if (tmp___0) {
      last_prefix = i;
    }
    *(sl + (i - 1UL)) = last_prefix + (size_t )(f_len - (size_t const )i);
    i --;
  }
  while_break: ;
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue___0: ;
    if (! (i < (size_t )f_len)) {
      goto while_break___0;
    }
    s_len = suffix_len(find, f_len, (size_t const )i, case_sensitive);
    if ((int const )*(find + (i - s_len)) != (int const )*(find + ((f_len - 1UL) - (size_t const )s_len))) {
      *(sl + ((f_len - 1UL) - (size_t const )s_len)) = (size_t )(((f_len - 1UL) - (size_t const )i) + (size_t const )s_len);
    }
    i ++;
  }
  while_break___0: ;
  }
  return;
}
}
size_t ag_max(size_t a , size_t b )
{
  {
  if (b > a) {
    return (b);
  }
  return (a);
}
}
size_t ag_min(size_t a , size_t b )
{
  {
  if (b < a) {
    return (b);
  }
  return (a);
}
}
void generate_hash(char const *find , size_t const f_len , uint8_t *h_table___0 ,
                   int const case_sensitive )
{
  int i ;
  int caps_set ;
  word_t word ;
  int cap_index ;
  size_t h ;
  {
  i = (int )(f_len - (size_t const )sizeof(uint16_t ));
  {
  while (1) {
    while_continue: ;
    if (! (i >= 0)) {
      goto while_break;
    }
    caps_set = 0;
    {
    while (1) {
      while_continue___0: ;
      if (! (caps_set < 1 << sizeof(uint16_t ))) {
        goto while_break___0;
      }
      memcpy((void *)(& word.as_chars), (void const *)(find + i), sizeof(uint16_t ));
      cap_index = 0;
      {
      while (1) {
        while_continue___1: ;
        if (! (caps_set >> cap_index)) {
          goto while_break___1;
        }
        if ((caps_set >> cap_index) & 1) {
          word.as_chars[cap_index] = (char )((int )word.as_chars[cap_index] - 32);
        }
        cap_index ++;
      }
      while_break___1: ;
      }
      h = (size_t )((int )word.as_word % 65536);
      {
      while (1) {
        while_continue___2: ;
        if (! *(h_table___0 + h)) {
          goto while_break___2;
        }
        h = (h + 1UL) % 65536UL;
      }
      while_break___2: ;
      }
      *(h_table___0 + h) = (uint8_t )(i + 1);
      if (case_sensitive) {
        goto while_break___0;
      }
      caps_set ++;
    }
    while_break___0: ;
    }
    i --;
  }
  while_break: ;
  }
  return;
}
}
char const *boyer_moore_strnstr(char const *s , char const *find , size_t const s_len ,
                                  size_t const f_len , size_t const *alpha_skip_lookup___0 ,
                                  size_t const *find_skip_lookup___0 , int const case_insensitive )
{
  ssize_t i ;
  size_t pos ;
  int __res ;
  int __c ;
  __int32_t const **tmp ;
  __int32_t const **tmp___0 ;
  int tmp___1 ;
  size_t tmp___2 ;
  {
  pos = (size_t )(f_len - 1UL);
  {
  while (1) {
    while_continue: ;
    if (! (pos < (size_t )s_len)) {
      goto while_break;
    }
    i = (ssize_t )(f_len - 1UL);
    {
    while (1) {
      while_continue___0: ;
      if (i >= 0L) {
        if (case_insensitive) {
          if (sizeof(*(s + pos)) > 1UL) {
            __res = tolower((int )*(s + pos));
          } else {
            tmp___0 = __ctype_tolower_loc();
            __res = (int )*(*tmp___0 + (int )*(s + pos));
          }
          tmp___1 = __res;
        } else {
          tmp___1 = (int )*(s + pos);
        }
        if (! (tmp___1 == (int )*(find + i))) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      pos --;
      i --;
    }
    while_break___0: ;
    }
    if (i < 0L) {
      return ((s + pos) + 1);
    }
    tmp___2 = ag_max((size_t )*(alpha_skip_lookup___0 + (unsigned char )*(s + pos)),
                     (size_t )*(find_skip_lookup___0 + i));
    pos += tmp___2;
  }
  while_break: ;
  }
  return ((char const *)((void *)0));
}
}
char const *hash_strnstr(char const *s , char const *find , size_t const s_len ,
                           size_t const f_len , uint8_t *h_table___0 , int const case_sensitive )
{
  size_t step ;
  size_t s_i ;
  size_t h ;
  char const *R ;
  size_t i ;
  int __res ;
  int __c ;
  __int32_t const **tmp ;
  __int32_t const **tmp___0 ;
  int tmp___1 ;
  size_t i___0 ;
  char const *R___0 ;
  char s_c ;
  int __res___0 ;
  int __c___0 ;
  __int32_t const **tmp___2 ;
  __int32_t const **tmp___3 ;
  int tmp___4 ;
  {
  if (s_len < f_len) {
    return ((char const *)((void *)0));
  }
  step = (size_t )((f_len - (size_t const )sizeof(uint16_t )) + 1UL);
  s_i = (size_t )(f_len - (size_t const )sizeof(uint16_t ));
  {
  while (1) {
    while_continue: ;
    if (! (s_i <= (size_t )(s_len - f_len))) {
      goto while_break;
    }
    h = (size_t )((int const )*((uint16_t const *)(s + s_i)) % 65536);
    {
    while (1) {
      while_continue___0: ;
      if (! *(h_table___0 + h)) {
        goto while_break___0;
      }
      R = (s + s_i) - ((int )*(h_table___0 + h) - 1);
      i = (size_t )0;
      {
      while (1) {
        while_continue___1: ;
        if (! (i < (size_t )f_len)) {
          goto while_break___1;
        }
        if (case_sensitive) {
          tmp___1 = (int const )*(R + i);
        } else {
          if (sizeof(*(R + i)) > 1UL) {
            __res = tolower((int )*(R + i));
          } else {
            tmp___0 = __ctype_tolower_loc();
            __res = (int )*(*tmp___0 + (int )*(R + i));
          }
          tmp___1 = (int const )__res;
        }
        if (tmp___1 != (int const )*(find + i)) {
          goto next_hash_cell;
        }
        i ++;
      }
      while_break___1: ;
      }
      return (R);
      next_hash_cell:
      h = (h + 1UL) % 65536UL;
    }
    while_break___0: ;
    }
    s_i += (size_t )step;
  }
  while_break: ;
  }
  s_i = (s_i - (size_t )step) + 1UL;
  {
  while (1) {
    while_continue___2: ;
    if (! (s_i <= (size_t )(s_len - f_len))) {
      goto while_break___2;
    }
    R___0 = s + s_i;
    i___0 = (size_t )0;
    {
    while (1) {
      while_continue___3: ;
      if (! (i___0 < (size_t )f_len)) {
        goto while_break___3;
      }
      if (case_sensitive) {
        tmp___4 = (int const )*(R___0 + i___0);
      } else {
        if (sizeof(*(R___0 + i___0)) > 1UL) {
          __res___0 = tolower((int )*(R___0 + i___0));
        } else {
          tmp___3 = __ctype_tolower_loc();
          __res___0 = (int )*(*tmp___3 + (int )*(R___0 + i___0));
        }
        tmp___4 = (int const )__res___0;
      }
      s_c = (char )tmp___4;
      if ((int )s_c != (int )*(find + i___0)) {
        goto next_start;
      }
      i___0 ++;
    }
    while_break___3: ;
    }
    return (R___0);
    next_start:
    s_i ++;
  }
  while_break___2: ;
  }
  return ((char const *)((void *)0));
}
}
size_t invert_matches(char const *buf , size_t const buf_len , match_t *matches ,
                      size_t matches_len )
{
  size_t i ;
  size_t match_read_index ;
  size_t inverted_match_count ;
  size_t inverted_match_start ;
  size_t last_line_end ;
  int in_inverted_match ;
  match_t next_match ;
  {
  match_read_index = (size_t )0;
  inverted_match_count = (size_t )0;
  inverted_match_start = (size_t )0;
  last_line_end = (size_t )0;
  in_inverted_match = 1;
  log_debug((char const *)"Inverting %u matches.", matches_len);
  if (matches_len > 0UL) {
    next_match = *(matches + 0);
  } else {
    next_match.start = (size_t )(buf_len + 1UL);
  }
  if (matches_len == 0UL) {
    (matches + 0)->start = (size_t )0;
    (matches + 0)->end = (size_t )(buf_len - 1UL);
    return ((size_t )1);
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < (size_t )buf_len)) {
      goto while_break;
    }
    if (i == next_match.start) {
      i = next_match.end - 1UL;
      match_read_index ++;
      if (match_read_index < matches_len) {
        next_match = *(matches + match_read_index);
      }
      if (in_inverted_match) {
        if (last_line_end > inverted_match_start) {
          (matches + inverted_match_count)->start = inverted_match_start;
          (matches + inverted_match_count)->end = last_line_end - 1UL;
          inverted_match_count ++;
        }
      }
      in_inverted_match = 0;
    } else
    if (i == (size_t )(buf_len - 1UL)) {
      if (in_inverted_match) {
        (matches + inverted_match_count)->start = inverted_match_start;
        (matches + inverted_match_count)->end = i;
        inverted_match_count ++;
      } else {
        goto _L;
      }
    } else
    _L:
    if ((int const )*(buf + i) == 10) {
      last_line_end = i + 1UL;
      if (! in_inverted_match) {
        inverted_match_start = last_line_end;
      }
      in_inverted_match = 1;
    }
    i ++;
  }
  while_break: ;
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue___0: ;
    if (! (i < matches_len)) {
      goto while_break___0;
    }
    log_debug((char const *)"Inverted match %i start %i end %i.", i, (matches + i)->start,
              (matches + i)->end);
    i ++;
  }
  while_break___0: ;
  }
  return (inverted_match_count);
}
}
void realloc_matches(match_t **matches , size_t *matches_size , size_t matches_len )
{
  void *tmp ;
  {
  if (matches_len < *matches_size) {
    return;
  }
  if (*matches) {
    *matches_size *= 2UL;
  } else {
    *matches_size = (size_t )100;
  }
  tmp = ag_realloc((void *)*matches, *matches_size * sizeof(match_t ));
  *matches = (match_t *)tmp;
  return;
}
}
void compile_study(pcre **re , pcre_extra **re_extra , char *q , int const pcre_opts ,
                   int const study_opts )
{
  char const *pcre_err ;
  int pcre_err_offset ;
  {
  pcre_err = (char const *)((void *)0);
  pcre_err_offset = 0;
  *re = pcre_compile((char const *)q, (int )pcre_opts, & pcre_err, & pcre_err_offset,
                     (unsigned char const *)((void *)0));
  if ((unsigned long )*re == (unsigned long )((void *)0)) {
    die((char const *)"Bad regex! pcre_compile() failed at position %i: %s\nIf you meant to search for a literal string, run ag with -Q",
        pcre_err_offset, pcre_err);
  }
  *re_extra = pcre_study((pcre const *)*re, (int )study_opts, & pcre_err);
  if ((unsigned long )*re_extra == (unsigned long )((void *)0)) {
    log_debug((char const *)"pcre_study returned nothing useful. Error: %s", pcre_err);
  }
  return;
}
}
int is_binary(void const *buf , size_t const buf_len )
{
  size_t suspicious_bytes ;
  size_t total_bytes ;
  size_t tmp ;
  unsigned char const *buf_c ;
  size_t i ;
  int tmp___0 ;
  {
  suspicious_bytes = (size_t )0;
  if (buf_len > 512UL) {
    tmp = (size_t const )512;
  } else {
    tmp = buf_len;
  }
  total_bytes = (size_t )tmp;
  buf_c = (unsigned char const *)buf;
  if (buf_len == 0UL) {
    return (0);
  }
  if (buf_len >= 3UL) {
    if ((int const )*(buf_c + 0) == 239) {
      if ((int const )*(buf_c + 1) == 187) {
        if ((int const )*(buf_c + 2) == 191) {
          return (0);
        }
      }
    }
  }
  if (buf_len >= 5UL) {
    tmp___0 = strncmp((char const *)buf, (char const *)"%PDF-", (size_t )5);
    if (tmp___0 == 0) {
      return (1);
    }
  }
  i = (size_t )0;
  {
  while (1) {
    while_continue: ;
    if (! (i < total_bytes)) {
      goto while_break;
    }
    if ((int const )*(buf_c + i) == 0) {
      return (1);
    } else
    if ((int const )*(buf_c + i) < 7) {
      goto _L___2;
    } else
    if ((int const )*(buf_c + i) > 14) {
      _L___2:
      if ((int const )*(buf_c + i) < 32) {
        goto _L___1;
      } else
      if ((int const )*(buf_c + i) > 127) {
        _L___1:
        if ((int const )*(buf_c + i) > 193) {
          if ((int const )*(buf_c + i) < 224) {
            if (i + 1UL < total_bytes) {
              i ++;
              if ((int const )*(buf_c + i) > 127) {
                if ((int const )*(buf_c + i) < 192) {
                  goto __Cont;
                }
              }
            } else {
              goto _L___0;
            }
          } else {
            goto _L___0;
          }
        } else
        _L___0:
        _L:
        if ((int const )*(buf_c + i) > 223) {
          if ((int const )*(buf_c + i) < 240) {
            if (i + 2UL < total_bytes) {
              i ++;
              if ((int const )*(buf_c + i) > 127) {
                if ((int const )*(buf_c + i) < 192) {
                  if ((int const )*(buf_c + (i + 1UL)) > 127) {
                    if ((int const )*(buf_c + (i + 1UL)) < 192) {
                      i ++;
                      goto __Cont;
                    }
                  }
                }
              }
            }
          }
        }
        suspicious_bytes ++;
        if (i >= 32UL) {
          if ((suspicious_bytes * 100UL) / total_bytes > 10UL) {
            return (1);
          }
        }
      }
    }
    __Cont:
    i ++;
  }
  while_break: ;
  }
  if ((suspicious_bytes * 100UL) / total_bytes > 10UL) {
    return (1);
  }
  return (0);
}
}
int is_regex(char const *query )
{
  char regex_chars[13] ;
  char *tmp ;
  {
  regex_chars[0] = (char )'$';
  regex_chars[1] = (char )'(';
  regex_chars[2] = (char )')';
  regex_chars[3] = (char )'*';
  regex_chars[4] = (char )'+';
  regex_chars[5] = (char )'.';
  regex_chars[6] = (char )'?';
  regex_chars[7] = (char )'[';
  regex_chars[8] = (char )'\\';
  regex_chars[9] = (char )'^';
  regex_chars[10] = (char )'{';
  regex_chars[11] = (char )'|';
  regex_chars[12] = (char )'\000';
  tmp = strpbrk(query, (char const *)(regex_chars));
  return ((unsigned long )tmp != (unsigned long )((void *)0));
}
}
int is_fnmatch(char const *filename )
{
  char fnmatch_chars[6] ;
  char *tmp ;
  {
  fnmatch_chars[0] = (char )'!';
  fnmatch_chars[1] = (char )'*';
  fnmatch_chars[2] = (char )'?';
  fnmatch_chars[3] = (char )'[';
  fnmatch_chars[4] = (char )']';
  fnmatch_chars[5] = (char )'\000';
  tmp = strpbrk(filename, (char const *)(fnmatch_chars));
  return ((unsigned long )tmp != (unsigned long )((void *)0));
}
}
int binary_search(char const *needle , char **haystack , int start , int end )
{
  int mid ;
  int rc ;
  int tmp ;
  int tmp___0 ;
  {
  if (start == end) {
    return (-1);
  }
  mid = start + (end - start) / 2;
  rc = strcmp(needle, (char const *)*(haystack + mid));
  if (rc < 0) {
    tmp = binary_search(needle, haystack, start, mid);
    return (tmp);
  } else
  if (rc > 0) {
    tmp___0 = binary_search(needle, haystack, mid + 1, end);
    return (tmp___0);
  }
  return (mid);
}
}
static int wordchar_table[256] ;
void init_wordchar_table(void)
{
  int i ;
  char ch ;
  int tmp ;
  {
  i = 0;
  {
  while (1) {
    while_continue: ;
    if (! (i < 256)) {
      goto while_break;
    }
    ch = (char )i;
    if (97 <= (int )ch) {
      if ((int )ch <= 122) {
        tmp = 1;
      } else {
        goto _L___1;
      }
    } else
    _L___1:
    if (65 <= (int )ch) {
      if ((int )ch <= 90) {
        tmp = 1;
      } else {
        goto _L___0;
      }
    } else
    _L___0:
    if (48 <= (int )ch) {
      if ((int )ch <= 57) {
        tmp = 1;
      } else {
        goto _L;
      }
    } else
    _L:
    if ((int )ch == 95) {
      tmp = 1;
    } else {
      tmp = 0;
    }
    wordchar_table[i] = tmp;
    i ++;
  }
  while_break: ;
  }
  return;
}
}
int is_wordchar(char ch )
{
  {
  return (wordchar_table[(unsigned char )ch]);
}
}
int is_lowercase(char const *s )
{
  int i ;
  unsigned short const **tmp ;
  {
  i = 0;
  {
  while (1) {
    while_continue: ;
    if (! ((int const )*(s + i) != 0)) {
      goto while_break;
    }
    if (! (((int const )*(s + i) & -128) == 0)) {
      return (0);
    } else {
      tmp = __ctype_b_loc();
      if ((int const )*(*tmp + (int )*(s + i)) & 256) {
        return (0);
      }
    }
    i ++;
  }
  while_break: ;
  }
  return (1);
}
}
int is_directory(char const *path , struct dirent const *d )
{
  char *full_path ;
  struct stat s ;
  int tmp ;
  int is_dir ;
  {
  if ((int )d->d_type != 0) {
    if ((int )d->d_type != 10) {
      return ((int )d->d_type == 4);
    }
  }
  ag_asprintf(& full_path, (char const *)"%s/%s", path, d->d_name);
  tmp = stat((char const * __restrict )full_path, (struct stat * __restrict )(& s));
  if (tmp != 0) {
    free((void *)full_path);
    return (0);
  }
  is_dir = (s.st_mode & 61440U) == 16384U;
  free((void *)full_path);
  return (is_dir);
}
}
int is_symlink(char const *path , struct dirent const *d )
{
  char *full_path ;
  struct stat s ;
  int tmp ;
  {
  if ((int )d->d_type != 0) {
    return ((int )d->d_type == 10);
  }
  ag_asprintf(& full_path, (char const *)"%s/%s", path, d->d_name);
  tmp = lstat((char const * __restrict )full_path, (struct stat * __restrict )(& s));
  if (tmp != 0) {
    free((void *)full_path);
    return (0);
  }
  free((void *)full_path);
  return ((s.st_mode & 61440U) == 40960U);
}
}
int is_named_pipe(char const *path , struct dirent const *d )
{
  int tmp ;
  char *full_path ;
  struct stat s ;
  int tmp___0 ;
  int tmp___1 ;
  {
  if ((int )d->d_type != 0) {
    if ((int )d->d_type != 10) {
      if ((int )d->d_type == 1) {
        tmp = 1;
      } else
      if ((int )d->d_type == 12) {
        tmp = 1;
      } else {
        tmp = 0;
      }
      return (tmp);
    }
  }
  ag_asprintf(& full_path, (char const *)"%s/%s", path, d->d_name);
  tmp___0 = stat((char const * __restrict )full_path, (struct stat * __restrict )(& s));
  if (tmp___0 != 0) {
    free((void *)full_path);
    return (0);
  }
  free((void *)full_path);
  if ((s.st_mode & 61440U) == 4096U) {
    tmp___1 = 1;
  } else
  if ((s.st_mode & 61440U) == 49152U) {
    tmp___1 = 1;
  } else {
    tmp___1 = 0;
  }
  return (tmp___1);
}
}
void ag_asprintf(char **ret , char const *fmt , ...)
{
  va_list args ;
  int tmp ;
  {
  __builtin_va_start(args, fmt);
  tmp = vasprintf(ret, fmt, args);
  if (tmp == -1) {
    die((char const *)"vasprintf returned -1");
  }
  __builtin_va_end(args);
  return;
}
}
void die(char const *fmt , ...)
{
  va_list args ;
  {
  __builtin_va_start(args, fmt);
  vplog((unsigned int const )40, fmt, args);
  __builtin_va_end(args);
  exit(2);
}
}
char *fgetln(FILE *fp , size_t *lenp )
{
  char *buf ;
  int c ;
  int used ;
  int len ;
  size_t nsize ;
  char *newbuf ;
  void *tmp ;
  int tmp___0 ;
  {
  buf = (char *)((void *)0);
  used = 0;
  len = 0;
  flockfile(fp);
  {
  while (1) {
    while_continue: ;
    c = getc_unlocked(fp);
    if (! (c != -1)) {
      goto while_break;
    }
    if (! buf) {
      goto _L;
    } else
    if (len >= used) {
      _L:
      nsize = (size_t )(used + 8192);
      tmp = realloc((void *)buf, nsize);
      newbuf = (char *)tmp;
      if (! newbuf) {
        funlockfile(fp);
        if (buf) {
          free((void *)buf);
        }
        return ((char *)((void *)0));
      }
      buf = newbuf;
      used = (int )nsize;
    }
    tmp___0 = len;
    len ++;
    *(buf + tmp___0) = (char )c;
    if (c == 10) {
      goto while_break;
    }
  }
  while_break: ;
  }
  funlockfile(fp);
  *lenp = (size_t )len;
  return (buf);
}
}
ssize_t buf_getline(char const **line , char const *buf , size_t const buf_len ,
                    size_t const buf_offset )
{
  char const *cur ;
  ssize_t i ;
  {
  cur = buf + buf_offset;
  i = (ssize_t )0;
  {
  while (1) {
    while_continue: ;
    if (buf_offset + (size_t const )i < buf_len) {
      if (! ((int const )*(cur + i) != 10)) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    i ++;
  }
  while_break: ;
  }
  *line = cur;
  return (i);
}
}
size_t strlcpy(char *dst , char const *src , size_t size )
{
  char *d ;
  char const *s ;
  size_t n ;
  char *tmp ;
  char tmp___0 ;
  char const *tmp___1 ;
  char const *tmp___2 ;
  {
  d = dst;
  s = src;
  n = size;
  if (n != 0UL) {
    {
    while (1) {
      while_continue: ;
      n --;
      if (! (n != 0UL)) {
        goto while_break;
      }
      tmp = d;
      d ++;
      tmp___1 = s;
      s ++;
      tmp___0 = (char )*tmp___1;
      *tmp = tmp___0;
      if ((int )tmp___0 == 0) {
        goto while_break;
      }
    }
    while_break: ;
    }
  }
  if (n == 0UL) {
    if (size != 0UL) {
      *d = (char )'\000';
    }
    {
    while (1) {
      while_continue___0: ;
      tmp___2 = s;
      s ++;
      if (! *tmp___2) {
        goto while_break___0;
      }
    }
    while_break___0: ;
    }
  }
  return ((size_t )((s - src) - 1L));
}
}
extern intmax_t ( __attribute__((__leaf__)) imaxabs)(intmax_t __n ) __attribute__((__nothrow__,
__const__)) ;
extern imaxdiv_t ( __attribute__((__leaf__)) imaxdiv)(intmax_t __numer , intmax_t __denom ) __attribute__((__nothrow__,
__const__)) ;
extern intmax_t ( __attribute__((__leaf__)) strtoimax)(char const *__nptr , char **__endptr ,
                                                       int __base ) __attribute__((__nothrow__)) ;
extern uintmax_t ( __attribute__((__leaf__)) strtoumax)(char const *__nptr , char **__endptr ,
                                                        int __base ) __attribute__((__nothrow__)) ;
extern intmax_t ( __attribute__((__leaf__)) wcstoimax)(__gwchar_t const *__nptr ,
                                                       __gwchar_t **__endptr , int __base ) __attribute__((__nothrow__)) ;
extern uintmax_t ( __attribute__((__leaf__)) wcstoumax)(__gwchar_t const *__nptr ,
                                                        __gwchar_t **__endptr , int __base ) __attribute__((__nothrow__)) ;
extern uint32_t lzma_version_number(void) __attribute__((__nothrow__, __const__)) ;
extern char const *lzma_version_string(void) __attribute__((__nothrow__, __const__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_code)(lzma_stream *strm ,
                                                                     lzma_action action ) __attribute__((__nothrow__)) ;
extern void lzma_end(lzma_stream *strm ) __attribute__((__nothrow__)) ;
extern void lzma_get_progress(lzma_stream *strm , uint64_t *progress_in , uint64_t *progress_out ) __attribute__((__nothrow__)) ;
extern uint64_t lzma_memusage(lzma_stream const *strm ) __attribute__((__pure__,
__nothrow__)) ;
extern uint64_t lzma_memlimit_get(lzma_stream const *strm ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_ret lzma_memlimit_set(lzma_stream *strm , uint64_t memlimit ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_vli_encode(lzma_vli vli , size_t *vli_pos , uint8_t *out , size_t *out_pos ,
                                size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_vli_decode(lzma_vli *vli , size_t *vli_pos , uint8_t const *in ,
                                size_t *in_pos , size_t in_size ) __attribute__((__nothrow__)) ;
extern uint32_t lzma_vli_size(lzma_vli vli ) __attribute__((__pure__, __nothrow__)) ;
extern lzma_bool lzma_check_is_supported(lzma_check check ) __attribute__((__nothrow__,
__const__)) ;
extern uint32_t lzma_check_size(lzma_check check ) __attribute__((__nothrow__, __const__)) ;
extern uint32_t lzma_crc32(uint8_t const *buf , size_t size , uint32_t crc ) __attribute__((__pure__,
__nothrow__)) ;
extern uint64_t lzma_crc64(uint8_t const *buf , size_t size , uint64_t crc ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_check lzma_get_check(lzma_stream const *strm ) __attribute__((__nothrow__)) ;
extern lzma_bool lzma_filter_encoder_is_supported(lzma_vli id ) __attribute__((__nothrow__,
__const__)) ;
extern lzma_bool lzma_filter_decoder_is_supported(lzma_vli id ) __attribute__((__nothrow__,
__const__)) ;
extern lzma_ret lzma_filters_copy(lzma_filter const *src , lzma_filter *dest , lzma_allocator const *allocator ) __attribute__((__nothrow__)) ;
extern uint64_t lzma_raw_encoder_memusage(lzma_filter const *filters ) __attribute__((__pure__,
__nothrow__)) ;
extern uint64_t lzma_raw_decoder_memusage(lzma_filter const *filters ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_raw_encoder)(lzma_stream *strm ,
                                                                            lzma_filter const *filters ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_raw_decoder)(lzma_stream *strm ,
                                                                            lzma_filter const *filters ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_filters_update(lzma_stream *strm , lzma_filter const *filters ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_raw_buffer_encode(lzma_filter const *filters , lzma_allocator const *allocator ,
                                       uint8_t const *in , size_t in_size , uint8_t *out ,
                                       size_t *out_pos , size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_raw_buffer_decode(lzma_filter const *filters , lzma_allocator const *allocator ,
                                       uint8_t const *in , size_t *in_pos , size_t in_size ,
                                       uint8_t *out , size_t *out_pos , size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_properties_size(uint32_t *size , lzma_filter const *filter ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_properties_encode(lzma_filter const *filter , uint8_t *props ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_properties_decode(lzma_filter *filter , lzma_allocator const *allocator ,
                                       uint8_t const *props , size_t props_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_filter_flags_size)(uint32_t *size ,
                                                                                  lzma_filter const *filter ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_filter_flags_encode)(lzma_filter const *filter ,
                                                                                    uint8_t *out ,
                                                                                    size_t *out_pos ,
                                                                                    size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_filter_flags_decode)(lzma_filter *filter ,
                                                                                    lzma_allocator const *allocator ,
                                                                                    uint8_t const *in ,
                                                                                    size_t *in_pos ,
                                                                                    size_t in_size ) __attribute__((__nothrow__)) ;
extern lzma_bool lzma_mf_is_supported(lzma_match_finder match_finder ) __attribute__((__nothrow__,
__const__)) ;
extern lzma_bool lzma_mode_is_supported(lzma_mode mode ) __attribute__((__nothrow__,
__const__)) ;
extern lzma_bool lzma_lzma_preset(lzma_options_lzma *options , uint32_t preset ) __attribute__((__nothrow__)) ;
extern uint64_t lzma_easy_encoder_memusage(uint32_t preset ) __attribute__((__pure__,
__nothrow__)) ;
extern uint64_t lzma_easy_decoder_memusage(uint32_t preset ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_easy_encoder)(lzma_stream *strm ,
                                                                             uint32_t preset ,
                                                                             lzma_check check ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_easy_buffer_encode(uint32_t preset , lzma_check check , lzma_allocator const *allocator ,
                                        uint8_t const *in , size_t in_size , uint8_t *out ,
                                        size_t *out_pos , size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_encoder)(lzma_stream *strm ,
                                                                               lzma_filter const *filters ,
                                                                               lzma_check check ) __attribute__((__nothrow__)) ;
extern uint64_t lzma_stream_encoder_mt_memusage(lzma_mt const *options ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_encoder_mt)(lzma_stream *strm ,
                                                                                  lzma_mt const *options ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_alone_encoder)(lzma_stream *strm ,
                                                                              lzma_options_lzma const *options ) __attribute__((__nothrow__)) ;
extern size_t lzma_stream_buffer_bound(size_t uncompressed_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_buffer_encode)(lzma_filter *filters ,
                                                                                     lzma_check check ,
                                                                                     lzma_allocator const *allocator ,
                                                                                     uint8_t const *in ,
                                                                                     size_t in_size ,
                                                                                     uint8_t *out ,
                                                                                     size_t *out_pos ,
                                                                                     size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_decoder)(lzma_stream *strm ,
                                                                               uint64_t memlimit ,
                                                                               uint32_t flags ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_auto_decoder)(lzma_stream *strm ,
                                                                             uint64_t memlimit ,
                                                                             uint32_t flags ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_alone_decoder)(lzma_stream *strm ,
                                                                              uint64_t memlimit ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_buffer_decode)(uint64_t *memlimit ,
                                                                                     uint32_t flags ,
                                                                                     lzma_allocator const *allocator ,
                                                                                     uint8_t const *in ,
                                                                                     size_t *in_pos ,
                                                                                     size_t in_size ,
                                                                                     uint8_t *out ,
                                                                                     size_t *out_pos ,
                                                                                     size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_header_encode)(lzma_stream_flags const *options ,
                                                                                     uint8_t *out ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_footer_encode)(lzma_stream_flags const *options ,
                                                                                     uint8_t *out ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_header_decode)(lzma_stream_flags *options ,
                                                                                     uint8_t const *in ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_stream_footer_decode)(lzma_stream_flags *options ,
                                                                                     uint8_t const *in ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_stream_flags_compare(lzma_stream_flags const *a , lzma_stream_flags const *b ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_header_size)(lzma_block *block ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_header_encode)(lzma_block const *block ,
                                                                                    uint8_t *out ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_header_decode)(lzma_block *block ,
                                                                                    lzma_allocator const *allocator ,
                                                                                    uint8_t const *in ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_compressed_size)(lzma_block *block ,
                                                                                      lzma_vli unpadded_size ) __attribute__((__nothrow__)) ;
extern lzma_vli lzma_block_unpadded_size(lzma_block const *block ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_vli lzma_block_total_size(lzma_block const *block ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_encoder)(lzma_stream *strm ,
                                                                              lzma_block *block ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_decoder)(lzma_stream *strm ,
                                                                              lzma_block *block ) __attribute__((__nothrow__)) ;
extern size_t lzma_block_buffer_bound(size_t uncompressed_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_buffer_encode)(lzma_block *block ,
                                                                                    lzma_allocator const *allocator ,
                                                                                    uint8_t const *in ,
                                                                                    size_t in_size ,
                                                                                    uint8_t *out ,
                                                                                    size_t *out_pos ,
                                                                                    size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_block_uncomp_encode)(lzma_block *block ,
                                                                                    uint8_t const *in ,
                                                                                    size_t in_size ,
                                                                                    uint8_t *out ,
                                                                                    size_t *out_pos ,
                                                                                    size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_block_buffer_decode(lzma_block *block , lzma_allocator const *allocator ,
                                         uint8_t const *in , size_t *in_pos , size_t in_size ,
                                         uint8_t *out , size_t *out_pos , size_t out_size ) __attribute__((__nothrow__)) ;
extern uint64_t lzma_index_memusage(lzma_vli streams , lzma_vli blocks ) __attribute__((__nothrow__)) ;
extern uint64_t lzma_index_memused(lzma_index const *i ) __attribute__((__nothrow__)) ;
extern lzma_index *lzma_index_init(lzma_allocator const *allocator ) __attribute__((__nothrow__)) ;
extern void lzma_index_end(lzma_index *i , lzma_allocator const *allocator ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_append)(lzma_index *i ,
                                                                             lzma_allocator const *allocator ,
                                                                             lzma_vli unpadded_size ,
                                                                             lzma_vli uncompressed_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_stream_flags)(lzma_index *i ,
                                                                                   lzma_stream_flags const *stream_flags ) __attribute__((__nothrow__)) ;
extern uint32_t lzma_index_checks(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_stream_padding)(lzma_index *i ,
                                                                                     lzma_vli stream_padding ) __attribute__((__nothrow__)) ;
extern lzma_vli lzma_index_stream_count(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_vli lzma_index_block_count(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_vli lzma_index_size(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_vli lzma_index_stream_size(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_vli lzma_index_total_size(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_vli lzma_index_file_size(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern lzma_vli lzma_index_uncompressed_size(lzma_index const *i ) __attribute__((__pure__,
__nothrow__)) ;
extern void lzma_index_iter_init(lzma_index_iter *iter , lzma_index const *i ) __attribute__((__nothrow__)) ;
extern void lzma_index_iter_rewind(lzma_index_iter *iter ) __attribute__((__nothrow__)) ;
extern lzma_bool ( __attribute__((__warn_unused_result__)) lzma_index_iter_next)(lzma_index_iter *iter ,
                                                                                 lzma_index_iter_mode mode ) __attribute__((__nothrow__)) ;
extern lzma_bool lzma_index_iter_locate(lzma_index_iter *iter , lzma_vli target ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_cat)(lzma_index *dest ,
                                                                          lzma_index *src ,
                                                                          lzma_allocator const *allocator ) __attribute__((__nothrow__)) ;
extern lzma_index *( __attribute__((__warn_unused_result__)) lzma_index_dup)(lzma_index const *i ,
                                                                             lzma_allocator const *allocator ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_encoder)(lzma_stream *strm ,
                                                                              lzma_index const *i ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_decoder)(lzma_stream *strm ,
                                                                              lzma_index **i ,
                                                                              uint64_t memlimit ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_index_buffer_encode(lzma_index const *i , uint8_t *out , size_t *out_pos ,
                                         size_t out_size ) __attribute__((__nothrow__)) ;
extern lzma_ret lzma_index_buffer_decode(lzma_index **i , uint64_t *memlimit , lzma_allocator const *allocator ,
                                         uint8_t const *in , size_t *in_pos , size_t in_size ) __attribute__((__nothrow__)) ;
extern lzma_index_hash *( __attribute__((__warn_unused_result__)) lzma_index_hash_init)(lzma_index_hash *index_hash ,
                                                                                        lzma_allocator const *allocator ) __attribute__((__nothrow__)) ;
extern void lzma_index_hash_end(lzma_index_hash *index_hash , lzma_allocator const *allocator ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_hash_append)(lzma_index_hash *index_hash ,
                                                                                  lzma_vli unpadded_size ,
                                                                                  lzma_vli uncompressed_size ) __attribute__((__nothrow__)) ;
extern lzma_ret ( __attribute__((__warn_unused_result__)) lzma_index_hash_decode)(lzma_index_hash *index_hash ,
                                                                                  uint8_t const *in ,
                                                                                  size_t *in_pos ,
                                                                                  size_t in_size ) __attribute__((__nothrow__)) ;
extern lzma_vli lzma_index_hash_size(lzma_index_hash const *index_hash ) __attribute__((__pure__,
__nothrow__)) ;
extern uint64_t lzma_physmem(void) __attribute__((__nothrow__)) ;
extern uint32_t lzma_cputhreads(void) __attribute__((__nothrow__)) ;
uint8_t const XZ_HEADER_MAGIC[6] = { (uint8_t const )0xFD, (uint8_t const )'7', (uint8_t const )'z', (uint8_t const )'X',
        (uint8_t const )'Z', (uint8_t const )0x00};
uint8_t const LZMA_HEADER_SOMETIMES[3] = { (uint8_t const )0x5D, (uint8_t const )0x00, (uint8_t const )0x00};
extern char const *zlibVersion(void) ;
extern int deflate(z_streamp strm , int flush ) ;
extern int deflateEnd(z_streamp strm ) ;
extern int inflate(z_streamp strm , int flush ) ;
extern int inflateEnd(z_streamp strm ) ;
extern int deflateSetDictionary(z_streamp strm , Bytef const *dictionary , uInt dictLength ) ;
extern int deflateGetDictionary(z_streamp strm , Bytef *dictionary , uInt *dictLength ) ;
extern int deflateCopy(z_streamp dest , z_streamp source ) ;
extern int deflateReset(z_streamp strm ) ;
extern int deflateParams(z_streamp strm , int level , int strategy ) ;
extern int deflateTune(z_streamp strm , int good_length , int max_lazy , int nice_length ,
                       int max_chain ) ;
extern uLong deflateBound(z_streamp strm , uLong sourceLen ) ;
extern int deflatePending(z_streamp strm , unsigned int *pending , int *bits ) ;
extern int deflatePrime(z_streamp strm , int bits , int value ) ;
extern int deflateSetHeader(z_streamp strm , gz_headerp head ) ;
extern int inflateSetDictionary(z_streamp strm , Bytef const *dictionary , uInt dictLength ) ;
extern int inflateGetDictionary(z_streamp strm , Bytef *dictionary , uInt *dictLength ) ;
extern int inflateSync(z_streamp strm ) ;
extern int inflateCopy(z_streamp dest , z_streamp source ) ;
extern int inflateReset(z_streamp strm ) ;
extern int inflateReset2(z_streamp strm , int windowBits ) ;
extern int inflatePrime(z_streamp strm , int bits , int value ) ;
extern long inflateMark(z_streamp strm ) ;
extern int inflateGetHeader(z_streamp strm , gz_headerp head ) ;
extern int inflateBack(z_streamp strm , unsigned int (*in)(void * , unsigned char const ** ) ,
                       void *in_desc , int (*out)(void * , unsigned char * , unsigned int ) ,
                       void *out_desc ) ;
extern int inflateBackEnd(z_streamp strm ) ;
extern uLong zlibCompileFlags(void) ;
extern int compress(Bytef *dest , uLongf *destLen , Bytef const *source , uLong sourceLen ) ;
extern int compress2(Bytef *dest , uLongf *destLen , Bytef const *source , uLong sourceLen ,
                     int level ) ;
extern uLong compressBound(uLong sourceLen ) ;
extern int uncompress(Bytef *dest , uLongf *destLen , Bytef const *source , uLong sourceLen ) ;
extern int uncompress2(Bytef *dest , uLongf *destLen , Bytef const *source , uLong *sourceLen ) ;
extern gzFile gzdopen(int fd , char const *mode ) ;
extern int gzbuffer(gzFile file , unsigned int size ) ;
extern int gzsetparams(gzFile file , int level , int strategy ) ;
extern int gzread(gzFile file , voidp buf , unsigned int len ) ;
extern z_size_t gzfread(voidp buf , z_size_t size , z_size_t nitems , gzFile file ) ;
extern int gzwrite(gzFile file , voidpc buf , unsigned int len ) ;
extern z_size_t gzfwrite(voidpc buf , z_size_t size , z_size_t nitems , gzFile file ) ;
extern int gzprintf(gzFile file , char const *format , ...) ;
extern int gzputs(gzFile file , char const *s ) ;
extern char *gzgets(gzFile file , char *buf , int len ) ;
extern int gzputc(gzFile file , int c ) ;
extern int gzgetc(gzFile file ) ;
extern int gzungetc(int c , gzFile file ) ;
extern int gzflush(gzFile file , int flush ) ;
extern int gzrewind(gzFile file ) ;
extern int gzeof(gzFile file ) ;
extern int gzdirect(gzFile file ) ;
extern int gzclose(gzFile file ) ;
extern int gzclose_r(gzFile file ) ;
extern int gzclose_w(gzFile file ) ;
extern char const *gzerror(gzFile file , int *errnum ) ;
extern void gzclearerr(gzFile file ) ;
extern uLong adler32(uLong adler , Bytef const *buf , uInt len ) ;
extern uLong adler32_z(uLong adler , Bytef const *buf , z_size_t len ) ;
extern uLong crc32(uLong crc , Bytef const *buf , uInt len ) ;
extern uLong crc32_z(uLong adler , Bytef const *buf , z_size_t len ) ;
extern int deflateInit_(z_streamp strm , int level , char const *version , int stream_size ) ;
extern int inflateInit_(z_streamp strm , char const *version , int stream_size ) ;
extern int deflateInit2_(z_streamp strm , int level , int method , int windowBits ,
                         int memLevel , int strategy , char const *version , int stream_size ) ;
extern int inflateInit2_(z_streamp strm , int windowBits , char const *version ,
                         int stream_size ) ;
extern int inflateBackInit_(z_streamp strm , int windowBits , unsigned char *window ,
                            char const *version , int stream_size ) ;
extern int gzgetc_(gzFile file ) ;
extern gzFile gzopen64(char const * , char const * ) ;
extern __off64_t gzseek64(gzFile , __off64_t , int ) ;
extern __off64_t gztell64(gzFile ) ;
extern __off64_t gzoffset64(gzFile ) ;
extern uLong adler32_combine64(uLong , uLong , __off64_t ) ;
extern uLong crc32_combine64(uLong , uLong , __off64_t ) ;
extern gzFile gzopen(char const * , char const * ) ;
extern __off_t gzseek(gzFile , __off_t , int ) ;
extern __off_t gztell(gzFile ) ;
extern __off_t gzoffset(gzFile ) ;
extern uLong adler32_combine(uLong , uLong , __off_t ) ;
extern uLong crc32_combine(uLong , uLong , __off_t ) ;
extern char const *zError(int ) ;
extern int inflateSyncPoint(z_streamp ) ;
extern z_crc_t const *get_crc_table(void) ;
extern int inflateUndermine(z_streamp , int ) ;
extern int inflateValidate(z_streamp , int ) ;
extern unsigned long inflateCodesUsed(z_streamp ) ;
extern int inflateResetKeep(z_streamp ) ;
extern int deflateResetKeep(z_streamp ) ;
extern int gzvprintf(gzFile file , char const *format , va_list va ) ;
static void *decompress_zlib(void const *buf , int const buf_len , char const *dir_full_path ,
                             int *new_buf_len )
{
  int ret ;
  unsigned char *result ;
  size_t result_size ;
  size_t pagesize ;
  z_stream stream ;
  int tmp ;
  int tmp___0 ;
  unsigned char *tmp_result ;
  void *tmp___1 ;
  {
  ret = 0;
  result = (unsigned char *)((void *)0);
  result_size = (size_t )0;
  pagesize = (size_t )0;
  log_debug((char const *)"Decompressing zlib file %s", dir_full_path);
  stream.zalloc = (voidpf (*)(voidpf opaque , uInt items , uInt size ))0;
  stream.zfree = (void (*)(voidpf opaque , voidpf address ))0;
  stream.opaque = (voidpf )0;
  stream.avail_in = (uInt )0;
  stream.next_in = (Bytef const *)0;
  tmp = inflateInit2_(& stream, 47, (char const *)"1.2.11", (int )sizeof(z_stream ));
  if (tmp != 0) {
    log_err((char const *)"Unable to initialize zlib: %s", stream.msg);
    goto error_out;
  }
  stream.avail_in = (uInt )buf_len;
  stream.next_in = (Bytef const *)((Bytef *)buf);
  tmp___0 = getpagesize();
  pagesize = (size_t )tmp___0;
  result_size = (((size_t )buf_len + pagesize) - 1UL) & ~ (pagesize - 1UL);
  {
  while (1) {
    while_continue: ;
    {
    while (1) {
      while_continue___0: ;
      tmp_result = result;
      result_size *= 2UL;
      tmp___1 = realloc((void *)result, result_size * sizeof(unsigned char ));
      result = (unsigned char *)tmp___1;
      if ((unsigned long )result == (unsigned long )((void *)0)) {
        free((void *)tmp_result);
        log_err((char const *)"Unable to allocate %d bytes to decompress file %s",
                result_size * sizeof(unsigned char ), dir_full_path);
        inflateEnd(& stream);
        goto error_out;
      }
      stream.avail_out = (uInt )(result_size / 2UL);
      stream.next_out = result + stream.total_out;
      ret = inflate(& stream, 2);
      log_debug((char const *)"inflate ret = %d", ret);
      {
      if (ret == -2) {
        goto case_neg_2;
      }
      if (ret == -4) {
        goto case_neg_4;
      }
      if (ret == -3) {
        goto case_neg_4;
      }
      if (ret == 2) {
        goto case_neg_4;
      }
      goto switch_break;
      case_neg_2:
      log_err((char const *)"Found stream error while decompressing zlib stream: %s",
              stream.msg);
      inflateEnd(& stream);
      goto error_out;
      case_neg_4:
      case_neg_3:
      case_2:
      log_err((char const *)"Found mem/data error while decompressing zlib stream: %s",
              stream.msg);
      inflateEnd(& stream);
      goto error_out;
      switch_break: ;
      }
      if (! (stream.avail_out == 0U)) {
        goto while_break___0;
      }
    }
    while_break___0: ;
    }
    if (! (ret == 0)) {
      goto while_break;
    }
  }
  while_break: ;
  }
  *new_buf_len = (int )stream.total_out;
  inflateEnd(& stream);
  if (ret == 1) {
    return ((void *)result);
  }
  error_out:
  *new_buf_len = 0;
  return ((void *)0);
}
}
static void *decompress_lzw(void const *buf , int const buf_len , char const *dir_full_path ,
                            int *new_buf_len )
{
  {
  log_err((char const *)"LZW (UNIX compress) files not yet supported: %s", dir_full_path);
  *new_buf_len = 0;
  return ((void *)0);
}
}
static void *decompress_zip(void const *buf , int const buf_len , char const *dir_full_path ,
                            int *new_buf_len )
{
  {
  log_err((char const *)"Zip files not yet supported: %s", dir_full_path);
  *new_buf_len = 0;
  return ((void *)0);
}
}
static void *decompress_lzma(void const *buf , int const buf_len , char const *dir_full_path ,
                             int *new_buf_len )
{
  lzma_stream stream ;
  lzma_ret lzrt ;
  unsigned char *result ;
  size_t result_size ;
  size_t pagesize ;
  int tmp ;
  unsigned char *tmp_result ;
  void *tmp___0 ;
  {
  stream.next_in = (uint8_t const *)((void *)0);
  stream.avail_in = (size_t )0;
  stream.total_in = (uint64_t )0;
  stream.next_out = (uint8_t *)((void *)0);
  stream.avail_out = (size_t )0;
  stream.total_out = (uint64_t )0;
  stream.allocator = (lzma_allocator const *)((void *)0);
  stream.internal = (lzma_internal *)((void *)0);
  stream.reserved_ptr1 = (void *)0;
  stream.reserved_ptr2 = (void *)0;
  stream.reserved_ptr3 = (void *)0;
  stream.reserved_ptr4 = (void *)0;
  stream.reserved_int1 = (uint64_t )0;
  stream.reserved_int2 = (uint64_t )0;
  stream.reserved_int3 = (size_t )0;
  stream.reserved_int4 = (size_t )0;
  stream.reserved_enum1 = (lzma_reserved_enum )0;
  stream.reserved_enum2 = (lzma_reserved_enum )0;
  result = (unsigned char *)((void *)0);
  result_size = (size_t )0;
  pagesize = (size_t )0;
  stream.avail_in = (size_t )buf_len;
  stream.next_in = (uint8_t const *)buf;
  lzrt = lzma_auto_decoder(& stream, (uint64_t )-1, (uint32_t )0);
  if ((unsigned int )lzrt != 0U) {
    log_err((char const *)"Unable to initialize lzma_auto_decoder: %d", (unsigned int )lzrt);
    goto error_out;
  }
  tmp = getpagesize();
  pagesize = (size_t )tmp;
  result_size = (((size_t )buf_len + pagesize) - 1UL) & ~ (pagesize - 1UL);
  {
  while (1) {
    while_continue: ;
    {
    while (1) {
      while_continue___0: ;
      tmp_result = result;
      result_size *= 2UL;
      tmp___0 = realloc((void *)result, result_size * sizeof(unsigned char ));
      result = (unsigned char *)tmp___0;
      if ((unsigned long )result == (unsigned long )((void *)0)) {
        free((void *)tmp_result);
        log_err((char const *)"Unable to allocate %d bytes to decompress file %s",
                result_size * sizeof(unsigned char ), dir_full_path);
        goto error_out;
      }
      stream.avail_out = result_size / 2UL;
      stream.next_out = result + stream.total_out;
      lzrt = lzma_code(& stream, (lzma_action )0);
      log_debug((char const *)"lzma_code ret = %d", (unsigned int )lzrt);
      {
      if ((unsigned int )lzrt == 1U) {
        goto case_1;
      }
      if ((unsigned int )lzrt == 0U) {
        goto case_1;
      }
      goto switch_default;
      case_1:
      case_0:
      goto switch_break;
      switch_default:
      log_err((char const *)"Found mem/data error while decompressing xz/lzma stream: %d",
              (unsigned int )lzrt);
      goto error_out;
      switch_break: ;
      }
      if (! (stream.avail_out == 0UL)) {
        goto while_break___0;
      }
    }
    while_break___0: ;
    }
    if (! ((unsigned int )lzrt == 0U)) {
      goto while_break;
    }
  }
  while_break: ;
  }
  *new_buf_len = (int )stream.total_out;
  if ((unsigned int )lzrt == 1U) {
    lzma_end(& stream);
    return ((void *)result);
  }
  error_out:
  lzma_end(& stream);
  *new_buf_len = 0;
  if (result) {
    free((void *)result);
  }
  return ((void *)0);
}
}
void *decompress(ag_compression_type const zip_type , void const *buf , int const buf_len ,
                 char const *dir_full_path , int *new_buf_len )
{
  void *tmp ;
  void *tmp___0 ;
  void *tmp___1 ;
  void *tmp___2 ;
  {
  {
  if ((unsigned int const )zip_type == 1U) {
    goto case_1;
  }
  if ((unsigned int const )zip_type == 2U) {
    goto case_2;
  }
  if ((unsigned int const )zip_type == 3U) {
    goto case_3;
  }
  if ((unsigned int const )zip_type == 4U) {
    goto case_4;
  }
  if ((unsigned int const )zip_type == 0U) {
    goto case_0;
  }
  goto switch_default;
  case_1:
  tmp = decompress_zlib(buf, (int const )buf_len, dir_full_path, new_buf_len);
  return (tmp);
  case_2:
  tmp___0 = decompress_lzw(buf, (int const )buf_len, dir_full_path, new_buf_len);
  return (tmp___0);
  case_3:
  tmp___1 = decompress_zip(buf, (int const )buf_len, dir_full_path, new_buf_len);
  return (tmp___1);
  case_4:
  tmp___2 = decompress_lzma(buf, (int const )buf_len, dir_full_path, new_buf_len);
  return (tmp___2);
  case_0:
  log_err((char const *)"File %s is not compressed", dir_full_path);
  goto switch_break;
  switch_default:
  log_err((char const *)"Unsupported compression type: %d", (unsigned int const )zip_type);
  switch_break: ;
  }
  *new_buf_len = 0;
  return ((void *)0);
}
}
ag_compression_type is_zipped(void const *buf , int const buf_len )
{
  unsigned char const *buf_c ;
  int tmp ;
  int tmp___0 ;
  {
  buf_c = (unsigned char const *)buf;
  if (buf_len == 0) {
    return ((ag_compression_type )0);
  }
  if (buf_len >= 2) {
    if ((int const )*(buf_c + 0) == 31) {
      if ((int const )*(buf_c + 1) == 139) {
        log_debug((char const *)"Found gzip-based stream");
        return ((ag_compression_type )1);
      } else
      if ((int const )*(buf_c + 1) == 155) {
        log_debug((char const *)"Found compress-based stream");
        return ((ag_compression_type )2);
      }
    }
  }
  if (buf_len >= 4) {
    if ((int const )*(buf_c + 0) == 80) {
      if ((int const )*(buf_c + 1) == 75) {
        if ((int const )*(buf_c + 2) == 3) {
          if ((int const )*(buf_c + 3) == 4) {
            log_debug((char const *)"Found zip-based stream");
            return ((ag_compression_type )3);
          }
        }
      }
    }
  }
  if (buf_len >= 6) {
    tmp = memcmp((void const *)(XZ_HEADER_MAGIC), (void const *)buf_c, (size_t )6);
    if (tmp == 0) {
      log_debug((char const *)"Found xz based stream");
      return ((ag_compression_type )4);
    }
  }
  if (buf_len >= 3) {
    tmp___0 = memcmp((void const *)(LZMA_HEADER_SOMETIMES), (void const *)buf_c,
                     (size_t )3);
    if (tmp___0 == 0) {
      log_debug((char const *)"Found lzma-based stream");
      return ((ag_compression_type )4);
    }
  }
  return ((ag_compression_type )0);
}
}
int main(int argc , char **argv )
{
  char **base_paths ;
  char **paths ;
  int i ;
  int pcre_opts ;
  int study_opts ;
  worker_t *workers ;
  int workers_len ;
  int num_cores ;
  char const *tmp ;
  int has_jit ;
  long tmp___0 ;
  void *tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  char *c ;
  int __res ;
  int __c ;
  __int32_t const **tmp___8 ;
  __int32_t const **tmp___9 ;
  char *word_regexp_query ;
  size_t tmp___10 ;
  int rv ;
  int tmp___11 ;
  char *tmp___12 ;
  cpu_set_t cpu_set ;
  size_t __cpu ;
  char *tmp___13 ;
  ignores *ig ;
  ignores *tmp___14 ;
  struct stat s ;
  int tmp___15 ;
  int tmp___16 ;
  double time_diff ;
  {
  base_paths = (char **)((void *)0);
  paths = (char **)((void *)0);
  pcre_opts = 0x00000002;
  study_opts = 0;
  workers = (worker_t *)((void *)0);
  set_log_level((enum log_level )30);
  work_queue = (work_queue_t *)((void *)0);
  work_queue_tail = (work_queue_t *)((void *)0);
  root_ignores = init_ignore((ignores *)((void *)0), (char const *)"", (size_t const )0);
  out_fd = stdout;
  parse_options(argc, argv, & base_paths, & paths);
  tmp = pcre_version();
  log_debug((char const *)"PCRE Version: %s", tmp);
  if (opts.stats) {
    memset((void *)(& stats), 0, sizeof(stats));
    gettimeofday((struct timeval * __restrict )(& stats.time_start), (void * __restrict )((void *)0));
  }
  has_jit = 0;
  pcre_config(9, (void *)(& has_jit));
  if (has_jit) {
    study_opts |= 0x0001;
  }
  tmp___0 = sysconf(84);
  num_cores = (int )tmp___0;
  if (num_cores < 8) {
    workers_len = num_cores;
  } else {
    workers_len = 8;
  }
  if (opts.literal) {
    workers_len --;
  }
  if (opts.workers) {
    workers_len = opts.workers;
  }
  if (workers_len < 1) {
    workers_len = 1;
  }
  log_debug((char const *)"Using %i workers", workers_len);
  done_adding_files = 0;
  tmp___1 = ag_calloc((size_t )workers_len, sizeof(worker_t ));
  workers = (worker_t *)tmp___1;
  tmp___2 = pthread_cond_init((pthread_cond_t * __restrict )(& files_ready), (pthread_condattr_t const * __restrict )((void *)0));
  if (tmp___2) {
    die((char const *)"pthread_cond_init failed!");
  }
  tmp___3 = pthread_mutex_init(& print_mtx, (pthread_mutexattr_t const *)((void *)0));
  if (tmp___3) {
    die((char const *)"pthread_mutex_init failed!");
  }
  if (opts.stats) {
    tmp___4 = pthread_mutex_init(& stats_mtx, (pthread_mutexattr_t const *)((void *)0));
    if (tmp___4) {
      die((char const *)"pthread_mutex_init failed!");
    }
  }
  tmp___5 = pthread_mutex_init(& work_queue_mtx, (pthread_mutexattr_t const *)((void *)0));
  if (tmp___5) {
    die((char const *)"pthread_mutex_init failed!");
  }
  if ((unsigned int )opts.casing == 3U) {
    tmp___7 = is_lowercase((char const *)opts.query);
    if (tmp___7) {
      opts.casing = (enum case_behavior )2;
    } else {
      opts.casing = (enum case_behavior )1;
    }
  }
  if (opts.literal) {
    if ((unsigned int )opts.casing == 2U) {
      c = opts.query;
      {
      while (1) {
        while_continue: ;
        if (! ((int )*c != 0)) {
          goto while_break;
        }
        if (sizeof(*c) > 1UL) {
          __res = tolower((int )*c);
        } else {
          tmp___9 = __ctype_tolower_loc();
          __res = (int )*(*tmp___9 + (int )*c);
        }
        *c = (char )__res;
        c ++;
      }
      while_break: ;
      }
    }
    generate_alpha_skip((char const *)opts.query, (size_t )opts.query_len, alpha_skip_lookup,
                        (int const )((unsigned int )opts.casing == 1U));
    find_skip_lookup = (size_t *)((void *)0);
    generate_find_skip((char const *)opts.query, (size_t const )opts.query_len,
                       & find_skip_lookup, (int const )((unsigned int )opts.casing == 1U));
    generate_hash((char const *)opts.query, (size_t const )opts.query_len, h_table,
                  (int const )((unsigned int )opts.casing == 1U));
    if (opts.word_regexp) {
      init_wordchar_table();
      opts.literal_starts_wordchar = is_wordchar(*(opts.query + 0));
      opts.literal_ends_wordchar = is_wordchar(*(opts.query + (opts.query_len - 1)));
    }
  } else {
    if ((unsigned int )opts.casing == 2U) {
      pcre_opts |= 0x00000001;
    }
    if (opts.word_regexp) {
      ag_asprintf(& word_regexp_query, (char const *)"\\b(?:%s)\\b", opts.query);
      free((void *)opts.query);
      opts.query = word_regexp_query;
      tmp___10 = strlen((char const *)opts.query);
      opts.query_len = (int )tmp___10;
    }
    compile_study(& opts.re, & opts.re_extra, opts.query, (int const )pcre_opts,
                  (int const )study_opts);
  }
  if (opts.search_stream) {
    search_stream(stdin, (char const *)"");
  } else {
    i = 0;
    {
    while (1) {
      while_continue___0: ;
      if (! (i < workers_len)) {
        goto while_break___0;
      }
      (workers + i)->id = i;
      tmp___11 = pthread_create((pthread_t * __restrict )(& (workers + i)->thread),
                                (pthread_attr_t const * __restrict )((void *)0),
                                & search_file_worker, (void * __restrict )(& (workers + i)->id));
      rv = tmp___11;
      if (rv != 0) {
        tmp___12 = strerror(rv);
        die((char const *)"Error in pthread_create(): %s", tmp___12);
      }
      if (opts.use_thread_affinity) {
        {
        while (1) {
          while_continue___1: ;
          __builtin_memset((void *)(& cpu_set), '\000', (int )sizeof(cpu_set_t ));
          goto while_break___1;
        }
        while_break___1: ;
        }
        __cpu = (size_t )(i % num_cores);
        if (__cpu / 8UL < sizeof(cpu_set_t )) {
          cpu_set.__bits[__cpu / (8UL * sizeof(__cpu_mask ))] |= 1UL << __cpu % (8UL * sizeof(__cpu_mask ));
        }
        rv = pthread_setaffinity_np((workers + i)->thread, sizeof(cpu_set), (cpu_set_t const *)(& cpu_set));
        if (rv) {
          tmp___13 = strerror(rv);
          log_err((char const *)"Error in pthread_setaffinity_np(): %s", tmp___13);
          log_err((char const *)"Performance may be affected. Use --noaffinity to suppress this message.");
        } else {
          log_debug((char const *)"Thread %i set to CPU %i", i, i);
        }
      } else {
        log_debug((char const *)"Thread affinity disabled.");
      }
      i ++;
    }
    while_break___0: ;
    }
    i = 0;
    {
    while (1) {
      while_continue___2: ;
      if (! ((unsigned long )*(paths + i) != (unsigned long )((void *)0))) {
        goto while_break___2;
      }
      log_debug((char const *)"searching path %s for %s", *(paths + i), opts.query);
      symhash = (symdir_t *)((void *)0);
      tmp___14 = init_ignore(root_ignores, (char const *)"", (size_t const )0);
      ig = tmp___14;
      s.st_dev = (__dev_t )0;
      s.st_ino = 0UL;
      s.st_nlink = 0UL;
      s.st_mode = 0U;
      s.st_uid = 0U;
      s.st_gid = 0U;
      s.__pad0 = 0;
      s.st_rdev = 0UL;
      s.st_size = 0L;
      s.st_blksize = 0L;
      s.st_blocks = 0L;
      s.st_atim.tv_sec = 0L;
      s.st_atim.tv_nsec = 0L;
      s.st_mtim.tv_sec = 0L;
      s.st_mtim.tv_nsec = 0L;
      s.st_ctim.tv_sec = 0L;
      s.st_ctim.tv_nsec = 0L;
      s.__glibc_reserved[0] = 0L;
      s.__glibc_reserved[1] = 0L;
      s.__glibc_reserved[2] = 0L;
      if (opts.one_dev) {
        tmp___15 = lstat((char const * __restrict )*(paths + i), (struct stat * __restrict )(& s));
        if (tmp___15 == -1) {
          log_err((char const *)"Failed to get device information for path %s. Skipping...",
                  *(paths + i));
        }
      }
      search_dir(ig, (char const *)*(base_paths + i), (char const *)*(paths + i),
                 (int const )0, s.st_dev);
      cleanup_ignore(ig);
      i ++;
    }
    while_break___2: ;
    }
    pthread_mutex_lock(& work_queue_mtx);
    done_adding_files = 1;
    pthread_cond_broadcast(& files_ready);
    pthread_mutex_unlock(& work_queue_mtx);
    i = 0;
    {
    while (1) {
      while_continue___3: ;
      if (! (i < workers_len)) {
        goto while_break___3;
      }
      tmp___16 = pthread_join((workers + i)->thread, (void **)((void *)0));
      if (tmp___16) {
        die((char const *)"pthread_join failed!");
      }
      i ++;
    }
    while_break___3: ;
    }
  }
  if (opts.stats) {
    gettimeofday((struct timeval * __restrict )(& stats.time_end), (void * __restrict )((void *)0));
    time_diff = (double )((stats.time_end.tv_sec * 1000000L + stats.time_end.tv_usec) - (stats.time_start.tv_sec * 1000000L + stats.time_start.tv_usec));
    time_diff /= (double )1000000;
    printf((char const *)"%zu matches\n%zu files contained matches\n%zu files searched\n%zu bytes searched\n%f seconds\n",
           stats.total_matches, stats.total_file_matches, stats.total_files, stats.total_bytes,
           time_diff);
    pthread_mutex_destroy(& stats_mtx);
  }
  if (opts.pager) {
    pclose(out_fd);
  }
  cleanup_options();
  pthread_cond_destroy(& files_ready);
  pthread_mutex_destroy(& work_queue_mtx);
  pthread_mutex_destroy(& print_mtx);
  cleanup_ignore(root_ignores);
  free((void *)workers);
  i = 0;
  {
  while (1) {
    while_continue___4: ;
    if (! ((unsigned long )*(paths + i) != (unsigned long )((void *)0))) {
      goto while_break___4;
    }
    free((void *)*(paths + i));
    free((void *)*(base_paths + i));
    i ++;
  }
  while_break___4: ;
  }
  free((void *)base_paths);
  free((void *)paths);
  if (find_skip_lookup) {
    free((void *)find_skip_lookup);
  }
  return (! opts.match_found);
}
}
extern void assert(int expression ) ;
extern void ( warn)(char const *__format , ...) ;
extern void ( vwarn)(char const *__format , __gnuc_va_list ) ;
extern void ( warnx)(char const *__format , ...) ;
extern void ( vwarnx)(char const *__format , __gnuc_va_list ) ;
extern void ( err)(int __status , char const *__format
                                           , ...) __attribute__((__noreturn__)) ;
extern void ( verr)(int __status , char const *__format ,
                                            __gnuc_va_list ) __attribute__((__noreturn__)) ;
extern void ( errx)(int __status , char const *__format
                                            , ...) __attribute__((__noreturn__)) ;
extern void ( verrx)(int __status , char const * , __gnuc_va_list ) __attribute__((__noreturn__)) ;
static __ssize_t zfile_read(void *cookie_ , char *buf , size_t size ) ;
static int zfile_seek(void *cookie_ , __off64_t *offset_ , int whence ) ;
static int zfile_close(void *cookie_ ) ;
static struct _IO_cookie_io_functions_t const zfile_io = {& zfile_read, (cookie_write_function_t *)((void *)0), & zfile_seek, & zfile_close};
static int zfile_cookie_init(struct zfile *cookie )
{
  lzma_ret lzrc ;
  int rc ;
  char const *tmp ;
  lzma_stream __constr_expr_0 ;
  {
  assert(cookie->logic_offset == 0UL);
  assert(cookie->decode_offset == 0UL);
  cookie->actual_len = (uint64_t )0;
  {
  if ((unsigned int )cookie->ctype == 1U) {
    goto case_1;
  }
  if ((unsigned int )cookie->ctype == 4U) {
    goto case_4;
  }
  goto switch_default;
  case_1:
  memset((void *)(& cookie->stream.gz), 0, sizeof(cookie->stream.gz));
  rc = inflateInit2_(& cookie->stream.gz, 47, (char const *)"1.2.11", (int )sizeof(z_stream___0 ));
  if (rc != 0) {
    tmp = zError(rc);
    log_err((char const *)"Unable to initialize zlib: %s", tmp);
    return (5);
  }
  cookie->stream.gz.next_in = (Bytef *)((void *)0);
  cookie->stream.gz.avail_in = (uInt )0;
  cookie->stream.gz.next_out = cookie->outbuf;
  cookie->stream.gz.avail_out = (uInt )sizeof(cookie->outbuf);
  goto switch_break;
  case_4:
  __constr_expr_0.next_in = (uint8_t const *)((void *)0);
  __constr_expr_0.avail_in = (size_t )0;
  __constr_expr_0.total_in = (uint64_t )0;
  __constr_expr_0.next_out = (uint8_t *)((void *)0);
  __constr_expr_0.avail_out = (size_t )0;
  __constr_expr_0.total_out = (uint64_t )0;
  __constr_expr_0.allocator = (lzma_allocator const *)((void *)0);
  __constr_expr_0.internal = (lzma_internal *)((void *)0);
  __constr_expr_0.reserved_ptr1 = (void *)0;
  __constr_expr_0.reserved_ptr2 = (void *)0;
  __constr_expr_0.reserved_ptr3 = (void *)0;
  __constr_expr_0.reserved_ptr4 = (void *)0;
  __constr_expr_0.reserved_int1 = (uint64_t )0;
  __constr_expr_0.reserved_int2 = (uint64_t )0;
  __constr_expr_0.reserved_int3 = (size_t )0;
  __constr_expr_0.reserved_int4 = (size_t )0;
  __constr_expr_0.reserved_enum1 = (lzma_reserved_enum )0;
  __constr_expr_0.reserved_enum2 = (lzma_reserved_enum )0;
  cookie->stream.lzma = __constr_expr_0;
  lzrc = lzma_auto_decoder(& cookie->stream.lzma, (uint64_t )-1, (uint32_t )0);
  if ((unsigned int )lzrc != 0U) {
    log_err((char const *)"Unable to initialize lzma_auto_decoder: %d", (unsigned int )lzrc);
    return (5);
  }
  cookie->stream.lzma.next_in = (uint8_t const *)((void *)0);
  cookie->stream.lzma.avail_in = (size_t )0;
  cookie->stream.lzma.next_out = cookie->outbuf;
  cookie->stream.lzma.avail_out = sizeof(cookie->outbuf);
  goto switch_break;
  switch_default:
  log_err((char const *)"Unsupported compression type: %d", (unsigned int )cookie->ctype);
  return (22);
  switch_break: ;
  }
  cookie->outbuf_start = (uint32_t )0;
  cookie->eof = (_Bool)0;
  return (0);
}
}
static void zfile_cookie_cleanup(struct zfile *cookie )
{
  {
  {
  if ((unsigned int )cookie->ctype == 1U) {
    goto case_1;
  }
  if ((unsigned int )cookie->ctype == 4U) {
    goto case_4;
  }
  goto switch_default;
  case_1:
  inflateEnd(& cookie->stream.gz);
  goto switch_break;
  case_4:
  lzma_end(& cookie->stream.lzma);
  goto switch_break;
  switch_default:
  goto switch_break;
  switch_break: ;
  }
  return;
}
}
FILE *decompress_open(int fd , char const *mode , ag_compression_type ctype )
{
  struct zfile *cookie ;
  FILE *res ;
  FILE *in ;
  int error ;
  int *tmp ;
  char *tmp___0 ;
  char *tmp___1 ;
  void *tmp___2 ;
  int *tmp___3 ;
  int *tmp___4 ;
  {
  cookie = (struct zfile *)((void *)0);
  res = (FILE *)((void *)0);
  in = res;
  tmp___0 = strstr(mode, (char const *)"w");
  if (tmp___0) {
    tmp = __errno_location();
    *tmp = 22;
    goto out;
  } else {
    tmp___1 = strstr(mode, (char const *)"a");
    if (tmp___1) {
      tmp = __errno_location();
      *tmp = 22;
      goto out;
    }
  }
  in = fdopen(fd, mode);
  if ((unsigned long )in == (unsigned long )((void *)0)) {
    goto out;
  }
  tmp___2 = malloc(sizeof(*cookie));
  cookie = (struct zfile *)tmp___2;
  if ((unsigned long )cookie == (unsigned long )((void *)0)) {
    tmp___3 = __errno_location();
    *tmp___3 = 12;
    goto out;
  }
  cookie->in = in;
  cookie->logic_offset = (uint64_t )0;
  cookie->decode_offset = (uint64_t )0;
  cookie->ctype = ctype;
  error = zfile_cookie_init(cookie);
  if (error != 0) {
    tmp___4 = __errno_location();
    *tmp___4 = error;
    goto out;
  }
  res = fopencookie((void * __restrict )cookie, (char const * __restrict )mode,
                    (cookie_io_functions_t )zfile_io);
  out:
  if ((unsigned long )res == (unsigned long )((void *)0)) {
    if ((unsigned long )in != (unsigned long )((void *)0)) {
      fclose(in);
    }
    if ((unsigned long )cookie != (unsigned long )((void *)0)) {
      free((void *)cookie);
    }
  }
  return (res);
}
}
static __ssize_t zfile_read(void *cookie_ , char *buf , size_t size )
{
  struct zfile *cookie ;
  size_t nb ;
  size_t ignorebytes ;
  ssize_t total ;
  lzma_ret lzret ;
  int ret ;
  size_t inflated ;
  size_t left ;
  Bytef *tmp ;
  size_t ignoreskip ;
  size_t _a ;
  size_t _b ;
  size_t tmp___0 ;
  size_t toread ;
  size_t _a___0 ;
  size_t _b___0 ;
  size_t tmp___1 ;
  Bytef *tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  size_t tmp___5 ;
  char const *tmp___6 ;
  Bytef *tmp___7 ;
  int tmp___8 ;
  {
  cookie = (struct zfile *)cookie_;
  total = (ssize_t )0;
  assert(size <= 9223372036854775807UL);
  if (size == 0UL) {
    return ((__ssize_t )0);
  }
  if (cookie->eof) {
    return ((__ssize_t )0);
  }
  ret = 0;
  lzret = (lzma_ret )0;
  ignorebytes = cookie->logic_offset - cookie->decode_offset;
  assert(ignorebytes == 0UL);
  {
  while (1) {
    while_continue: ;
    {
    while (1) {
      while_continue___0: ;
      if ((unsigned int )cookie->ctype == 1U) {
        tmp___2 = cookie->stream.gz.next_out;
      } else {
        tmp___2 = cookie->stream.lzma.next_out;
      }
      if (! ((unsigned long )tmp___2 > (unsigned long )(& cookie->outbuf[cookie->outbuf_start]))) {
        goto while_break___0;
      }
      if ((unsigned int )cookie->ctype == 1U) {
        tmp = cookie->stream.gz.next_out;
      } else {
        tmp = cookie->stream.lzma.next_out;
      }
      left = (size_t )(tmp - & cookie->outbuf[cookie->outbuf_start]);
      _a = ignorebytes;
      _b = left;
      if (_a < _b) {
        tmp___0 = _a;
      } else {
        tmp___0 = _b;
      }
      ignoreskip = tmp___0;
      if (ignoreskip > 0UL) {
        ignorebytes -= ignoreskip;
        left -= ignoreskip;
        cookie->outbuf_start = (uint32_t )((size_t )cookie->outbuf_start + ignoreskip);
        cookie->decode_offset += ignoreskip;
      }
      if (ignorebytes > 0UL) {
        goto while_break___0;
      }
      _a___0 = left;
      _b___0 = size;
      if (_a___0 < _b___0) {
        tmp___1 = _a___0;
      } else {
        tmp___1 = _b___0;
      }
      toread = tmp___1;
      memcpy((void *)buf, (void const *)(& cookie->outbuf[cookie->outbuf_start]),
             toread);
      buf += toread;
      size -= toread;
      left -= toread;
      cookie->outbuf_start = (uint32_t )((size_t )cookie->outbuf_start + toread);
      cookie->decode_offset += toread;
      cookie->logic_offset += toread;
      total = (ssize_t )((size_t )total + toread);
      if (size == 0UL) {
        goto while_break___0;
      }
    }
    while_break___0: ;
    }
    if (size == 0UL) {
      goto while_break;
    }
    assert((unsigned long )cookie->stream.gz.next_out == (unsigned long )(& cookie->outbuf[cookie->outbuf_start]));
    if ((unsigned int )cookie->ctype == 4U) {
      if ((unsigned int )lzret == 1U) {
        cookie->eof = (_Bool)1;
        goto while_break;
      } else {
        goto _L;
      }
    } else
    _L:
    if ((unsigned int )cookie->ctype == 1U) {
      if (ret == 1) {
        cookie->eof = (_Bool)1;
        goto while_break;
      }
    }
    if ((unsigned int )cookie->ctype == 1U) {
      tmp___5 = (size_t )cookie->stream.gz.avail_in;
    } else {
      tmp___5 = cookie->stream.lzma.avail_in;
    }
    if (tmp___5 == 0UL) {
      nb = fread((void *)(cookie->inbuf), (size_t )1, sizeof(cookie->inbuf), cookie->in);
      tmp___3 = ferror(cookie->in);
      if (tmp___3) {
        warn((char const *)"error read core");
        exit(1);
      }
      if (nb == 0UL) {
        tmp___4 = feof(cookie->in);
        if (tmp___4) {
          warn((char const *)"truncated file");
          exit(1);
        }
      }
      if ((unsigned int )cookie->ctype == 4U) {
        cookie->stream.lzma.avail_in = nb;
        cookie->stream.lzma.next_in = (uint8_t const *)(cookie->inbuf);
      } else {
        cookie->stream.gz.avail_in = (uInt )nb;
        cookie->stream.gz.next_in = cookie->inbuf;
      }
    }
    if ((unsigned int )cookie->ctype == 4U) {
      cookie->stream.lzma.next_out = cookie->outbuf;
      cookie->stream.lzma.avail_out = sizeof(cookie->outbuf);
    } else {
      cookie->stream.gz.next_out = cookie->outbuf;
      cookie->stream.gz.avail_out = (uInt )sizeof(cookie->outbuf);
    }
    cookie->outbuf_start = (uint32_t )0;
    if ((unsigned int )cookie->ctype == 1U) {
      ret = inflate(& cookie->stream.gz, 0);
      if (ret != 0) {
        if (ret != 1) {
          tmp___6 = zError(ret);
          log_err((char const *)"Found mem/data error while decompressing zlib stream: %s",
                  tmp___6);
          return ((__ssize_t )-1);
        }
      }
    } else {
      lzret = lzma_code(& cookie->stream.lzma, (lzma_action )0);
      if ((unsigned int )lzret != 0U) {
        if ((unsigned int )lzret != 1U) {
          log_err((char const *)"Found mem/data error while decompressing xz/lzma stream: %d",
                  (unsigned int )lzret);
          return ((__ssize_t )-1);
        }
      }
    }
    if ((unsigned int )cookie->ctype == 1U) {
      tmp___7 = cookie->stream.gz.next_out;
    } else {
      tmp___7 = cookie->stream.lzma.next_out;
    }
    inflated = (size_t )(tmp___7 - & cookie->outbuf[0]);
    cookie->actual_len += inflated;
    tmp___8 = ferror(cookie->in);
    if (tmp___8) {
      goto while_break;
    } else
    if (! (size > 0UL)) {
      goto while_break;
    }
  }
  while_break: ;
  }
  assert(total <= 0x7fffffffffffffffL);
  return (total);
}
}
static int zfile_seek(void *cookie_ , __off64_t *offset_ , int whence )
{
  struct zfile *cookie ;
  __off64_t new_offset ;
  __off64_t offset ;
  char *buf ;
  size_t bsz ;
  void *tmp ;
  size_t diff ;
  size_t _a ;
  uint64_t _b ;
  size_t tmp___0 ;
  ssize_t err___0 ;
  __ssize_t tmp___1 ;
  {
  cookie = (struct zfile *)cookie_;
  new_offset = (__off64_t )0;
  offset = *offset_;
  if (whence == 0) {
    new_offset = offset;
  } else
  if (whence == 1) {
    new_offset = (__off64_t )cookie->logic_offset + offset;
  } else {
    return (-1);
  }
  if (new_offset < 0L) {
    return (-1);
  }
  if (new_offset < (__off64_t )cookie->logic_offset) {
    if (new_offset != 0L) {
      return (-1);
    }
  }
  if (new_offset == 0L) {
    cookie->decode_offset = (uint64_t )0;
    cookie->logic_offset = (uint64_t )0;
    zfile_cookie_cleanup(cookie);
    zfile_cookie_init(cookie);
  } else
  if ((uint64_t )new_offset > cookie->logic_offset) {
    bsz = (size_t )32768;
    tmp = malloc((size_t )bsz);
    buf = (char *)tmp;
    {
    while (1) {
      while_continue: ;
      if (! ((uint64_t )new_offset > cookie->logic_offset)) {
        goto while_break;
      }
      _a = bsz;
      _b = (uint64_t )new_offset - cookie->logic_offset;
      if (_a < (size_t )_b) {
        tmp___0 = _a;
      } else {
        tmp___0 = (size_t )_b;
      }
      diff = (size_t )tmp___0;
      tmp___1 = zfile_read(cookie_, buf, diff);
      err___0 = tmp___1;
      if (err___0 < 0L) {
        free((void *)buf);
        return (-1);
      }
      if (err___0 == 0L) {
        assert((int )cookie->eof);
        new_offset = (__off64_t )cookie->logic_offset;
        goto while_break;
      }
    }
    while_break: ;
    }
    free((void *)buf);
  }
  assert(cookie->logic_offset == (uint64_t )new_offset);
  *offset_ = new_offset;
  return (0);
}
}
static int zfile_close(void *cookie_ )
{
  struct zfile *cookie ;
  {
  cookie = (struct zfile *)cookie_;
  zfile_cookie_cleanup(cookie);
  fclose(cookie->in);
  free((void *)cookie);
  return (0);
}
}
