typedef struct {
        unsigned long fds_bits [(1024/(8 * sizeof(unsigned long)))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned long __kernel_ino_t;
typedef unsigned short __kernel_mode_t;
typedef unsigned short __kernel_nlink_t;
typedef long __kernel_off_t;
typedef int __kernel_pid_t;
typedef unsigned short __kernel_ipc_pid_t;
typedef unsigned short __kernel_uid_t;
typedef unsigned short __kernel_gid_t;
typedef unsigned int __kernel_size_t;
typedef int __kernel_ssize_t;
typedef int __kernel_ptrdiff_t;
typedef long __kernel_time_t;
typedef long __kernel_suseconds_t;
typedef long __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef int __kernel_daddr_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned short __kernel_old_dev_t;
typedef long long __kernel_loff_t;
typedef struct {
        int val[2];
} __kernel_fsid_t;
typedef unsigned short umode_t;
typedef __signed__ char __s8;
typedef unsigned char __u8;
typedef __signed__ short __s16;
typedef unsigned short __u16;
typedef __signed__ int __s32;
typedef unsigned int __u32;
typedef __signed__ long long __s64;
typedef unsigned long long __u64;
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef u64 dma_addr_t;
typedef u64 dma64_addr_t;
typedef __u32 __kernel_dev_t;
typedef __kernel_fd_set fd_set;
typedef __kernel_dev_t dev_t;
typedef __kernel_ino_t ino_t;
typedef __kernel_mode_t mode_t;
typedef __kernel_nlink_t nlink_t;
typedef __kernel_off_t off_t;
typedef __kernel_pid_t pid_t;
typedef __kernel_daddr_t daddr_t;
typedef __kernel_key_t key_t;
typedef __kernel_suseconds_t suseconds_t;
typedef __kernel_timer_t timer_t;
typedef __kernel_clockid_t clockid_t;
typedef __kernel_mqd_t mqd_t;
typedef __kernel_uid32_t uid_t;
typedef __kernel_gid32_t gid_t;
typedef __kernel_uid16_t uid16_t;
typedef __kernel_gid16_t gid16_t;
typedef __kernel_old_uid_t old_uid_t;
typedef __kernel_old_gid_t old_gid_t;
typedef __kernel_loff_t loff_t;
typedef __kernel_size_t size_t;
typedef __kernel_ssize_t ssize_t;
typedef __kernel_ptrdiff_t ptrdiff_t;
typedef __kernel_time_t time_t;
typedef __kernel_clock_t clock_t;
typedef __kernel_caddr_t caddr_t;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef unsigned char unchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef __u8 u_int8_t;
typedef __s8 int8_t;
typedef __u16 u_int16_t;
typedef __s16 int16_t;
typedef __u32 u_int32_t;
typedef __s32 int32_t;
typedef __u8 uint8_t;
typedef __u16 uint16_t;
typedef __u32 uint32_t;
typedef __u64 uint64_t;
typedef __u64 u_int64_t;
typedef __s64 int64_t;
typedef unsigned long sector_t;
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;
typedef unsigned gfp_t;
struct ustat {
        __kernel_daddr_t f_tfree;
        __kernel_ino_t f_tinode;
        char f_fname[6];
        char f_fpack[6];
};
typedef struct __user_cap_header_struct {
        __u32 version;
        int pid;
} *cap_user_header_t;
typedef struct __user_cap_data_struct {
        __u32 effective;
        __u32 permitted;
        __u32 inheritable;
} *cap_user_data_t;
struct restart_block {
        long (*fn)(struct restart_block *);
        unsigned long arg0, arg1, arg2, arg3;
};
extern long do_no_restart_syscall(struct restart_block *parm);
static inline __attribute__((always_inline)) int generic_ffs(int x)
{
        int r = 1;
        if (!x)
                return 0;
        if (!(x & 0xffff)) {
                x >>= 16;
                r += 16;
        }
        if (!(x & 0xff)) {
                x >>= 8;
                r += 8;
        }
        if (!(x & 0xf)) {
                x >>= 4;
                r += 4;
        }
        if (!(x & 3)) {
                x >>= 2;
                r += 2;
        }
        if (!(x & 1)) {
                x >>= 1;
                r += 1;
        }
        return r;
}
static __inline__ __attribute__((always_inline)) int generic_fls(int x)
{
        int r = 32;
        if (!x)
                return 0;
        if (!(x & 0xffff0000u)) {
                x <<= 16;
                r -= 16;
        }
        if (!(x & 0xff000000u)) {
                x <<= 8;
                r -= 8;
        }
        if (!(x & 0xf0000000u)) {
                x <<= 4;
                r -= 4;
        }
        if (!(x & 0xc0000000u)) {
                x <<= 2;
                r -= 2;
        }
        if (!(x & 0x80000000u)) {
                x <<= 1;
                r -= 1;
        }
        return r;
}
static inline __attribute__((always_inline)) void set_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__( "lock ; "
                "btsl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
static inline __attribute__((always_inline)) void __set_bit(int nr, volatile unsigned long * addr)
{
        __asm__(
                "btsl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
static inline __attribute__((always_inline)) void clear_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__( "lock ; "
                "btrl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
static inline __attribute__((always_inline)) void __clear_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__(
                "btrl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
static inline __attribute__((always_inline)) void __change_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__(
                "btcl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
static inline __attribute__((always_inline)) void change_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__( "lock ; "
                "btcl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
static inline __attribute__((always_inline)) int test_and_set_bit(int nr, volatile unsigned long * addr)
{
        int oldbit;
        __asm__ __volatile__( "lock ; "
                "btsl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr) : "memory");
        return oldbit;
}
static inline __attribute__((always_inline)) int __test_and_set_bit(int nr, volatile unsigned long * addr)
{
        int oldbit;
        __asm__(
                "btsl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
        return oldbit;
}
static inline __attribute__((always_inline)) int test_and_clear_bit(int nr, volatile unsigned long * addr)
{
        int oldbit;
        __asm__ __volatile__( "lock ; "
                "btrl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr) : "memory");
        return oldbit;
}
static inline __attribute__((always_inline)) int __test_and_clear_bit(int nr, volatile unsigned long *addr)
{
        int oldbit;
        __asm__(
                "btrl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
        return oldbit;
}
static inline __attribute__((always_inline)) int __test_and_change_bit(int nr, volatile unsigned long *addr)
{
        int oldbit;
        __asm__ __volatile__(
                "btcl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr) : "memory");
        return oldbit;
}
static inline __attribute__((always_inline)) int test_and_change_bit(int nr, volatile unsigned long* addr)
{
        int oldbit;
        __asm__ __volatile__( "lock ; "
                "btcl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr) : "memory");
        return oldbit;
}
static inline __attribute__((always_inline)) int constant_test_bit(int nr, const volatile unsigned long *addr)
{
        return ((1UL << (nr & 31)) & (addr[nr >> 5])) != 0;
}
static inline __attribute__((always_inline)) int variable_test_bit(int nr, const volatile unsigned long * addr)
{
        int oldbit;
        __asm__ __volatile__(
                "btl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit)
                :"m" ((*(volatile long *) addr)),"Ir" (nr));
        return oldbit;
}
static inline __attribute__((always_inline)) int find_first_zero_bit(const unsigned long *addr, unsigned size)
{
        int d0, d1, d2;
        int res;
        if (!size)
                return 0;
        __asm__ __volatile__(
                "movl $-1,%%eax\n\t"
                "xorl %%edx,%%edx\n\t"
                "repe; scasl\n\t"
                "je 1f\n\t"
                "xorl -4(%%edi),%%eax\n\t"
                "subl $4,%%edi\n\t"
                "bsfl %%eax,%%edx\n"
                "1:\tsubl %%ebx,%%edi\n\t"
                "shll $3,%%edi\n\t"
                "addl %%edi,%%edx"
                :"=d" (res), "=&c" (d0), "=&D" (d1), "=&a" (d2)
                :"1" ((size + 31) >> 5), "2" (addr), "b" (addr) : "memory");
        return res;
}
int find_next_zero_bit(const unsigned long *addr, int size, int offset);
static inline __attribute__((always_inline)) unsigned long __ffs(unsigned long word)
{
        __asm__("bsfl %1,%0"
                :"=r" (word)
                :"rm" (word));
        return word;
}
static inline __attribute__((always_inline)) int find_first_bit(const unsigned long *addr, unsigned size)
{
        int x = 0;
        while (x < size) {
                unsigned long val = *addr++;
                if (val)
                        return __ffs(val) + x;
                x += (sizeof(*addr)<<3);
        }
        return x;
}
int find_next_bit(const unsigned long *addr, int size, int offset);
static inline __attribute__((always_inline)) unsigned long ffz(unsigned long word)
{
        __asm__("bsfl %1,%0"
                :"=r" (word)
                :"r" (~word));
        return word;
}
static inline __attribute__((always_inline)) int sched_find_first_bit(const unsigned long *b)
{
        if (__builtin_expect(!!(b[0]), 0))
                return __ffs(b[0]);
        if (__builtin_expect(!!(b[1]), 0))
                return __ffs(b[1]) + 32;
        if (__builtin_expect(!!(b[2]), 0))
                return __ffs(b[2]) + 64;
        if (b[3])
                return __ffs(b[3]) + 96;
        return __ffs(b[4]) + 128;
}
static inline __attribute__((always_inline)) int ffs(int x)
{
        int r;
        __asm__("bsfl %1,%0\n\t"
                "jnz 1f\n\t"
                "movl $-1,%0\n"
                "1:" : "=r" (r) : "rm" (x));
        return r+1;
}
static __inline__ __attribute__((always_inline)) int get_bitmask_order(unsigned int count)
{
        int order;
        order = generic_fls(count);
        return order;
}
static inline __attribute__((always_inline)) unsigned int generic_hweight32(unsigned int w)
{
        unsigned int res = (w & 0x55555555) + ((w >> 1) & 0x55555555);
        res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
        res = (res & 0x0F0F0F0F) + ((res >> 4) & 0x0F0F0F0F);
        res = (res & 0x00FF00FF) + ((res >> 8) & 0x00FF00FF);
        return (res & 0x0000FFFF) + ((res >> 16) & 0x0000FFFF);
}
static inline __attribute__((always_inline)) unsigned int generic_hweight16(unsigned int w)
{
        unsigned int res = (w & 0x5555) + ((w >> 1) & 0x5555);
        res = (res & 0x3333) + ((res >> 2) & 0x3333);
        res = (res & 0x0F0F) + ((res >> 4) & 0x0F0F);
        return (res & 0x00FF) + ((res >> 8) & 0x00FF);
}
static inline __attribute__((always_inline)) unsigned int generic_hweight8(unsigned int w)
{
        unsigned int res = (w & 0x55) + ((w >> 1) & 0x55);
        res = (res & 0x33) + ((res >> 2) & 0x33);
        return (res & 0x0F) + ((res >> 4) & 0x0F);
}
static inline __attribute__((always_inline)) unsigned long generic_hweight64(__u64 w)
{
        return generic_hweight32((unsigned int)(w >> 32)) +
                                generic_hweight32((unsigned int)w);
}
static inline __attribute__((always_inline)) unsigned long hweight_long(unsigned long w)
{
        return sizeof(w) == 4 ? generic_hweight32(w) : generic_hweight64(w);
}
static inline __attribute__((always_inline)) __u32 rol32(__u32 word, unsigned int shift)
{
        return (word << shift) | (word >> (32 - shift));
}
static inline __attribute__((always_inline)) __u32 ror32(__u32 word, unsigned int shift)
{
        return (word >> shift) | (word << (32 - shift));
}
extern int nx_enabled;
extern unsigned long long __supported_pte_mask;
typedef struct { unsigned long pte_low, pte_high; } pte_t;
typedef struct { unsigned long long pmd; } pmd_t;
typedef struct { unsigned long long pgd; } pgd_t;
typedef struct { unsigned long long pgprot; } pgprot_t;
extern unsigned int __VMALLOC_RESERVE;
extern int sysctl_legacy_va_layout;
extern int page_is_ram(unsigned long pagenr);
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) int get_order(unsigned long size)
{
        int order;
        size = (size - 1) >> (12 - 1);
        order = -1;
        do {
                size >>= 1;
                order++;
        } while (size);
        return order;
}
struct vm86_regs {
        long ebx;
        long ecx;
        long edx;
        long esi;
        long edi;
        long ebp;
        long eax;
        long __null_ds;
        long __null_es;
        long __null_fs;
        long __null_gs;
        long orig_eax;
        long eip;
        unsigned short cs, __csh;
        long eflags;
        long esp;
        unsigned short ss, __ssh;
        unsigned short es, __esh;
        unsigned short ds, __dsh;
        unsigned short fs, __fsh;
        unsigned short gs, __gsh;
};
struct revectored_struct {
        unsigned long __map[8];
};
struct vm86_struct {
        struct vm86_regs regs;
        unsigned long flags;
        unsigned long screen_bitmap;
        unsigned long cpu_type;
        struct revectored_struct int_revectored;
        struct revectored_struct int21_revectored;
};
struct vm86plus_info_struct {
        unsigned long force_return_for_pic:1;
        unsigned long vm86dbg_active:1;
        unsigned long vm86dbg_TFpendig:1;
        unsigned long unused:28;
        unsigned long is_vm86pus:1;
        unsigned char vm86dbg_intxxtab[32];
};
struct vm86plus_struct {
        struct vm86_regs regs;
        unsigned long flags;
        unsigned long screen_bitmap;
        unsigned long cpu_type;
        struct revectored_struct int_revectored;
        struct revectored_struct int21_revectored;
        struct vm86plus_info_struct vm86plus;
};
struct kernel_vm86_regs {
        long ebx;
        long ecx;
        long edx;
        long esi;
        long edi;
        long ebp;
        long eax;
        long __null_ds;
        long __null_es;
        long orig_eax;
        long eip;
        unsigned short cs, __csh;
        long eflags;
        long esp;
        unsigned short ss, __ssh;
        unsigned short es, __esh;
        unsigned short ds, __dsh;
        unsigned short fs, __fsh;
        unsigned short gs, __gsh;
};
struct kernel_vm86_struct {
        struct kernel_vm86_regs regs;
        unsigned long flags;
        unsigned long screen_bitmap;
        unsigned long cpu_type;
        struct revectored_struct int_revectored;
        struct revectored_struct int21_revectored;
        struct vm86plus_info_struct vm86plus;
        struct pt_regs *regs32;
};
void handle_vm86_fault(struct kernel_vm86_regs *, long);
int handle_vm86_trap(struct kernel_vm86_regs *, long, int);
struct _fpreg {
        unsigned short significand[4];
        unsigned short exponent;
};
struct _fpxreg {
        unsigned short significand[4];
        unsigned short exponent;
        unsigned short padding[3];
};
struct _xmmreg {
        unsigned long element[4];
};
struct _fpstate {
        unsigned long cw;
        unsigned long sw;
        unsigned long tag;
        unsigned long ipoff;
        unsigned long cssel;
        unsigned long dataoff;
        unsigned long datasel;
        struct _fpreg _st[8];
        unsigned short status;
        unsigned short magic;
        unsigned long _fxsr_env[6];
        unsigned long mxcsr;
        unsigned long reserved;
        struct _fpxreg _fxsr_st[8];
        struct _xmmreg _xmm[8];
        unsigned long padding[56];
};
struct sigcontext {
        unsigned short gs, __gsh;
        unsigned short fs, __fsh;
        unsigned short es, __esh;
        unsigned short ds, __dsh;
        unsigned long edi;
        unsigned long esi;
        unsigned long ebp;
        unsigned long esp;
        unsigned long ebx;
        unsigned long edx;
        unsigned long ecx;
        unsigned long eax;
        unsigned long trapno;
        unsigned long err;
        unsigned long eip;
        unsigned short cs, __csh;
        unsigned long eflags;
        unsigned long esp_at_signal;
        unsigned short ss, __ssh;
        struct _fpstate * fpstate;
        unsigned long oldmask;
        unsigned long cr2;
};
int restore_i387_soft(void *s387, struct _fpstate *buf);
int save_i387_soft(void *s387, struct _fpstate *buf);
struct info {
        long ___orig_eip;
        long ___ebx;
        long ___ecx;
        long ___edx;
        long ___esi;
        long ___edi;
        long ___ebp;
        long ___eax;
        long ___ds;
        long ___es;
        long ___orig_eax;
        long ___eip;
        long ___cs;
        long ___eflags;
        long ___esp;
        long ___ss;
        long ___vm86_es;
        long ___vm86_ds;
        long ___vm86_fs;
        long ___vm86_gs;
};
static inline __attribute__((always_inline)) void wrmsrl (unsigned long msr, unsigned long long val)
{
        unsigned long lo, hi;
        lo = (unsigned long) val;
        hi = val >> 32;
        __asm__ __volatile__("wrmsr" : : "c" (msr), "a" (lo), "d" (hi));
}
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u32 ___arch__swab32(__u32 x)
{
        __asm__("xchgb %b0,%h0\n\t"
                "rorl $16,%0\n\t"
                "xchgb %b0,%h0"
                :"=q" (x)
                : "0" (x));
        return x;
}
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u64 ___arch__swab64(__u64 val)
{
        union {
                struct { __u32 a,b; } s;
                __u64 u;
        } v;
        v.u = val;
   v.s.a = ___arch__swab32(v.s.a);
        v.s.b = ___arch__swab32(v.s.b);
        asm("xchgl %0,%1" : "=r" (v.s.a), "=r" (v.s.b) : "0" (v.s.a), "1" (v.s.b));
        return v.u;
}
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u16 __fswab16(__u16 x)
{
        return ({ __u16 __tmp = (x) ; ({ __u16 __x = (__tmp); ((__u16)( (((__u16)(__x) & (__u16)0x00ffU) << 8) | (((__u16)(__x) & (__u16)0xff00U) >> 8) )); }); });
}
static __inline__ __attribute__((always_inline)) __u16 __swab16p(const __u16 *x)
{
        return ({ __u16 __tmp = (*(x)) ; ({ __u16 __x = (__tmp); ((__u16)( (((__u16)(__x) & (__u16)0x00ffU) << 8) | (((__u16)(__x) & (__u16)0xff00U) >> 8) )); }); });
}
static __inline__ __attribute__((always_inline)) void __swab16s(__u16 *addr)
{
        do { *(addr) = ({ __u16 __tmp = (*((addr))) ; ({ __u16 __x = (__tmp); ((__u16)( (((__u16)(__x) & (__u16)0x00ffU) << 8) | (((__u16)(__x) & (__u16)0xff00U) >> 8) )); }); }); } while (0);
}
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u32 __fswab32(__u32 x)
{
        return ___arch__swab32(x);
}
static __inline__ __attribute__((always_inline)) __u32 __swab32p(const __u32 *x)
{
        return ___arch__swab32(*(x));
}
static __inline__ __attribute__((always_inline)) void __swab32s(__u32 *addr)
{
        do { *(addr) = ___arch__swab32(*((addr))); } while (0);
}
static __inline__ __attribute__((always_inline)) __attribute__((__const__)) __u64 __fswab64(__u64 x)
{
        return ___arch__swab64(x);
}
static __inline__ __attribute__((always_inline)) __u64 __swab64p(const __u64 *x)
{
        return ___arch__swab64(*(x));
}
static __inline__ __attribute__((always_inline)) void __swab64s(__u64 *addr)
{
        do { *(addr) = ___arch__swab64(*((addr))); } while (0);
}
static inline __attribute__((always_inline)) __le64 __cpu_to_le64p(const __u64 *p)
{
        return ( __le64)*p;
}
static inline __attribute__((always_inline)) __u64 __le64_to_cpup(const __le64 *p)
{
        return ( __u64)*p;
}
static inline __attribute__((always_inline)) __le32 __cpu_to_le32p(const __u32 *p)
{
        return ( __le32)*p;
}
static inline __attribute__((always_inline)) __u32 __le32_to_cpup(const __le32 *p)
{
        return ( __u32)*p;
}
static inline __attribute__((always_inline)) __le16 __cpu_to_le16p(const __u16 *p)
{
        return ( __le16)*p;
}
static inline __attribute__((always_inline)) __u16 __le16_to_cpup(const __le16 *p)
{
        return ( __u16)*p;
}
static inline __attribute__((always_inline)) __be64 __cpu_to_be64p(const __u64 *p)
{
        return ( __be64)__swab64p(p);
}
static inline __attribute__((always_inline)) __u64 __be64_to_cpup(const __be64 *p)
{
        return __swab64p((__u64 *)p);
}
static inline __attribute__((always_inline)) __be32 __cpu_to_be32p(const __u32 *p)
{
        return ( __be32)__swab32p(p);
}
static inline __attribute__((always_inline)) __u32 __be32_to_cpup(const __be32 *p)
{
        return __swab32p((__u32 *)p);
}
static inline __attribute__((always_inline)) __be16 __cpu_to_be16p(const __u16 *p)
{
        return ( __be16)__swab16p(p);
}
static inline __attribute__((always_inline)) __u16 __be16_to_cpup(const __be16 *p)
{
        return __swab16p((__u16 *)p);
}
extern __u32 ntohl(__be32);
extern __be32 htonl(__u32);
extern __u16 ntohs(__be16);
extern __be16 htons(__u16);
extern const char linux_banner[];
extern int console_printk[];
struct completion;
extern struct notifier_block *panic_notifier_list;
extern long (*panic_blink)(long time);
 void panic(const char * fmt, ...)
        __attribute__ ((noreturn, format (printf, 1, 2)));
__attribute__((regparm(3))) void do_exit(long error_code)
        __attribute__((noreturn));
 void complete_and_exit(struct completion *, long)
        __attribute__((noreturn));
extern unsigned long simple_strtoul(const char *,char **,unsigned int);
extern long simple_strtol(const char *,char **,unsigned int);
extern unsigned long long simple_strtoull(const char *,char **,unsigned int);
extern long long simple_strtoll(const char *,char **,unsigned int);
extern int sprintf(char * buf, const char * fmt, ...)
        __attribute__ ((format (printf, 2, 3)));
extern int vsprintf(char *buf, const char *, va_list)
        __attribute__ ((format (printf, 2, 0)));
extern int snprintf(char * buf, size_t size, const char * fmt, ...)
        __attribute__ ((format (printf, 3, 4)));
extern int vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
        __attribute__ ((format (printf, 3, 0)));
extern int scnprintf(char * buf, size_t size, const char * fmt, ...)
        __attribute__ ((format (printf, 3, 4)));
extern int vscnprintf(char *buf, size_t size, const char *fmt, va_list args)
        __attribute__ ((format (printf, 3, 0)));
extern int sscanf(const char *, const char *, ...)
        __attribute__ ((format (scanf, 2, 3)));
extern int vsscanf(const char *, const char *, va_list)
        __attribute__ ((format (scanf, 2, 0)));
extern int get_option(char **str, int *pint);
extern char *get_options(const char *str, int nints, int *ints);
extern unsigned long long memparse(char *ptr, char **retptr);
extern int __kernel_text_address(unsigned long addr);
extern int kernel_text_address(unsigned long addr);
extern int session_of_pgrp(int pgrp);
 __attribute__((regparm(0))) int vprintk(const char *fmt, va_list args)
        __attribute__ ((format (printf, 1, 0)));
 __attribute__((regparm(0))) int printk(const char * fmt, ...)
        __attribute__ ((format (printf, 1, 2)));
unsigned long int_sqrt(unsigned long);
static inline __attribute__((always_inline)) int __attribute__((pure)) long_log2(unsigned long x)
{
        int r = 0;
        for (x >>= 1; x > 0; x >>= 1)
                r++;
        return r;
}
static inline __attribute__((always_inline)) unsigned long __attribute__((__const__)) roundup_pow_of_two(unsigned long x)
{
        return (1UL << generic_fls(x - 1));
}
extern int printk_ratelimit(void);
extern int __printk_ratelimit(int ratelimit_jiffies, int ratelimit_burst);
static inline __attribute__((always_inline)) void console_silent(void)
{
        (console_printk[0]) = 0;
}
static inline __attribute__((always_inline)) void console_verbose(void)
{
        if ((console_printk[0]))
                (console_printk[0]) = 15;
}
extern void bust_spinlocks(int yes);
extern int oops_in_progress;
extern int panic_timeout;
extern int panic_on_oops;
extern int tainted;
extern const char *print_tainted(void);
extern void add_taint(unsigned);
extern enum system_states {
        SYSTEM_BOOTING,
        SYSTEM_RUNNING,
        SYSTEM_HALT,
        SYSTEM_POWER_OFF,
        SYSTEM_RESTART,
} system_state;
extern void dump_stack(void);
struct sysinfo {
        long uptime;
        unsigned long loads[3];
        unsigned long totalram;
        unsigned long freeram;
        unsigned long sharedram;
        unsigned long bufferram;
        unsigned long totalswap;
        unsigned long freeswap;
        unsigned short procs;
        unsigned short pad;
        unsigned long totalhigh;
        unsigned long freehigh;
        unsigned int mem_unit;
        char _f[20-2*sizeof(long)-sizeof(int)];
};
extern int randomize_va_space;
struct task_struct;
extern struct task_struct * __switch_to(struct task_struct *prev, struct task_struct *next) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) unsigned long _get_base(char * addr)
{
        unsigned long __base;
        __asm__("movb %3,%%dh\n\t"
                "movb %2,%%dl\n\t"
                "shll $16,%%edx\n\t"
                "movw %1,%%dx"
                :"=&d" (__base)
                :"m" (*((addr)+2)),
                 "m" (*((addr)+4)),
                 "m" (*((addr)+7)));
        return __base;
}
static inline __attribute__((always_inline)) unsigned long get_limit(unsigned long segment)
{
        unsigned long __limit;
        __asm__("lsll %1,%0"
                :"=r" (__limit):"r" (segment));
        return __limit+1;
}
struct __xchg_dummy { unsigned long a[100]; };
static inline __attribute__((always_inline)) void __set_64bit (unsigned long long * ptr,
                unsigned int low, unsigned int high)
{
        __asm__ __volatile__ (
                "\n1:\t"
                "movl (%0), %%eax\n\t"
                "movl 4(%0), %%edx\n\t"
                "lock cmpxchg8b (%0)\n\t"
                "jnz 1b"
                :
                : "D"(ptr),
                        "b"(low),
                        "c"(high)
                : "ax","dx","memory");
}
static inline __attribute__((always_inline)) void __set_64bit_constant (unsigned long long *ptr,
                                                 unsigned long long value)
{
        __set_64bit(ptr,(unsigned int)(value), (unsigned int)((value)>>32ULL));
}
static inline __attribute__((always_inline)) void __set_64bit_var (unsigned long long *ptr,
                         unsigned long long value)
{
        __set_64bit(ptr,*(((unsigned int*)&(value))+0), *(((unsigned int*)&(value))+1));
}
static inline __attribute__((always_inline)) unsigned long __xchg(unsigned long x, volatile void * ptr, int size)
{
        switch (size) {
                case 1:
                        __asm__ __volatile__("xchgb %b0,%1"
                                :"=q" (x)
                                :"m" (*((struct __xchg_dummy *)(ptr))), "0" (x)
                                :"memory");
                        break;
                case 2:
                        __asm__ __volatile__("xchgw %w0,%1"
                                :"=r" (x)
                                :"m" (*((struct __xchg_dummy *)(ptr))), "0" (x)
                                :"memory");
                        break;
                case 4:
                        __asm__ __volatile__("xchgl %0,%1"
                                :"=r" (x)
                                :"m" (*((struct __xchg_dummy *)(ptr))), "0" (x)
                                :"memory");
                        break;
        }
        return x;
}
static inline __attribute__((always_inline)) unsigned long __cmpxchg(volatile void *ptr, unsigned long old,
                                      unsigned long new, int size)
{
        unsigned long prev;
        switch (size) {
        case 1:
                __asm__ __volatile__("lock ; " "cmpxchgb %b1,%2"
                                     : "=a"(prev)
                                     : "q"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
                                     : "memory");
                return prev;
        case 2:
                __asm__ __volatile__("lock ; " "cmpxchgw %w1,%2"
                                     : "=a"(prev)
                                     : "q"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
                                     : "memory");
                return prev;
        case 4:
                __asm__ __volatile__("lock ; " "cmpxchgl %1,%2"
                                     : "=a"(prev)
                                     : "q"(new), "m"(*((struct __xchg_dummy *)(ptr))), "0"(old)
                                     : "memory");
                return prev;
        }
        return old;
}
struct alt_instr {
        __u8 *instr;
        __u8 *replacement;
        __u8 cpuid;
        __u8 instrlen;
        __u8 replacementlen;
        __u8 pad;
};
void disable_hlt(void);
void enable_hlt(void);
extern int es7000_plat;
void cpu_idle_wait(void);
extern unsigned long arch_align_stack(unsigned long sp);
extern unsigned long __per_cpu_offset[8];
extern int tsc_disable;
struct desc_struct {
        unsigned long a,b;
};
struct cpuinfo_x86 {
        __u8 x86;
        __u8 x86_vendor;
        __u8 x86_model;
        __u8 x86_mask;
        char wp_works_ok;
        char hlt_works_ok;
        char hard_math;
        char rfu;
        int cpuid_level;
        unsigned long x86_capability[7];
        char x86_vendor_id[16];
        char x86_model_id[64];
        int x86_cache_size;
        int x86_cache_alignment;
        int fdiv_bug;
        int f00f_bug;
        int coma_bug;
        unsigned long loops_per_jiffy;
        unsigned char x86_num_cores;
} __attribute__((__aligned__((1 << (4)))));
extern struct cpuinfo_x86 boot_cpu_data;
extern struct cpuinfo_x86 new_cpu_data;
extern struct tss_struct doublefault_tss;
extern __typeof__(struct tss_struct) per_cpu__init_tss;
extern struct cpuinfo_x86 cpu_data[];
extern int phys_proc_id[8];
extern int cpu_core_id[8];
extern char ignore_fpu_irq;
extern void identify_cpu(struct cpuinfo_x86 *);
extern void print_cpu_info(struct cpuinfo_x86 *);
extern unsigned int init_intel_cacheinfo(struct cpuinfo_x86 *c);
extern void detect_ht(struct cpuinfo_x86 *c);
static inline __attribute__((always_inline)) void cpuid(unsigned int op, unsigned int *eax, unsigned int *ebx, unsigned int *ecx, unsigned int *edx)
{
        __asm__("cpuid"
                : "=a" (*eax),
                  "=b" (*ebx),
                  "=c" (*ecx),
                  "=d" (*edx)
                : "0" (op), "c"(0));
}
static inline __attribute__((always_inline)) void cpuid_count(int op, int count, int *eax, int *ebx, int *ecx,
                int *edx)
{
        __asm__("cpuid"
                : "=a" (*eax),
                  "=b" (*ebx),
                  "=c" (*ecx),
                  "=d" (*edx)
                : "0" (op), "c" (count));
}
static inline __attribute__((always_inline)) unsigned int cpuid_eax(unsigned int op)
{
        unsigned int eax;
        __asm__("cpuid"
                : "=a" (eax)
                : "0" (op)
                : "bx", "cx", "dx");
        return eax;
}
static inline __attribute__((always_inline)) unsigned int cpuid_ebx(unsigned int op)
{
        unsigned int eax, ebx;
        __asm__("cpuid"
                : "=a" (eax), "=b" (ebx)
                : "0" (op)
                : "cx", "dx" );
        return ebx;
}
static inline __attribute__((always_inline)) unsigned int cpuid_ecx(unsigned int op)
{
        unsigned int eax, ecx;
        __asm__("cpuid"
                : "=a" (eax), "=c" (ecx)
                : "0" (op)
                : "bx", "dx" );
        return ecx;
}
static inline __attribute__((always_inline)) unsigned int cpuid_edx(unsigned int op)
{
        unsigned int eax, edx;
        __asm__("cpuid"
                : "=a" (eax), "=d" (edx)
                : "0" (op)
                : "bx", "cx");
        return edx;
}
extern unsigned long mmu_cr4_features;
static inline __attribute__((always_inline)) void set_in_cr4 (unsigned long mask)
{
        unsigned cr4;
        mmu_cr4_features |= mask;
        cr4 = ({ unsigned int __dummy; __asm__( "movl %%cr4,%0\n\t" :"=r" (__dummy)); __dummy; });
        cr4 |= mask;
        __asm__ __volatile__("movl %0,%%cr4": :"r" (cr4));;
}
static inline __attribute__((always_inline)) void clear_in_cr4 (unsigned long mask)
{
        unsigned cr4;
        mmu_cr4_features &= ~mask;
        cr4 = ({ unsigned int __dummy; __asm__( "movl %%cr4,%0\n\t" :"=r" (__dummy)); __dummy; });
        cr4 &= ~mask;
        __asm__ __volatile__("movl %0,%%cr4": :"r" (cr4));;
}
static inline __attribute__((always_inline)) void serialize_cpu(void)
{
         __asm__ __volatile__ ("cpuid" : : : "ax", "bx", "cx", "dx");
}
static inline __attribute__((always_inline)) void __monitor(const void *eax, unsigned long ecx,
                unsigned long edx)
{
        asm volatile(
                ".byte 0x0f,0x01,0xc8;"
                : :"a" (eax), "c" (ecx), "d"(edx));
}
static inline __attribute__((always_inline)) void __mwait(unsigned long eax, unsigned long ecx)
{
        asm volatile(
                ".byte 0x0f,0x01,0xc9;"
                : :"a" (eax), "c" (ecx));
}
extern unsigned int machine_id;
extern unsigned int machine_submodel_id;
extern unsigned int BIOS_revision;
extern unsigned int mca_pentium_flag;
extern int bootloader_type;
struct i387_fsave_struct {
        long cwd;
        long swd;
        long twd;
        long fip;
        long fcs;
        long foo;
        long fos;
        long st_space[20];
        long status;
};
struct i387_fxsave_struct {
        unsigned short cwd;
        unsigned short swd;
        unsigned short twd;
        unsigned short fop;
        long fip;
        long fcs;
        long foo;
        long fos;
        long mxcsr;
        long mxcsr_mask;
        long st_space[32];
        long xmm_space[32];
        long padding[56];
} __attribute__ ((aligned (16)));
struct i387_soft_struct {
        long cwd;
        long swd;
        long twd;
        long fip;
        long fcs;
        long foo;
        long fos;
        long st_space[20];
        unsigned char ftop, changed, lookahead, no_update, rm, alimit;
        struct info *info;
        unsigned long entry_eip;
};
union i387_union {
        struct i387_fsave_struct fsave;
        struct i387_fxsave_struct fxsave;
        struct i387_soft_struct soft;
};
typedef struct {
        unsigned long seg;
} mm_segment_t;
struct thread_struct;
struct tss_struct {
        unsigned short back_link,__blh;
        unsigned long esp0;
        unsigned short ss0,__ss0h;
        unsigned long esp1;
        unsigned short ss1,__ss1h;
        unsigned long esp2;
        unsigned short ss2,__ss2h;
        unsigned long __cr3;
        unsigned long eip;
        unsigned long eflags;
        unsigned long eax,ecx,edx,ebx;
        unsigned long esp;
        unsigned long ebp;
        unsigned long esi;
        unsigned long edi;
        unsigned short es, __esh;
        unsigned short cs, __csh;
        unsigned short ss, __ssh;
        unsigned short ds, __dsh;
        unsigned short fs, __fsh;
        unsigned short gs, __gsh;
        unsigned short ldt, __ldth;
        unsigned short trace, io_bitmap_base;
        unsigned long io_bitmap[((65536/8)/sizeof(long)) + 1];
        unsigned long io_bitmap_max;
        struct thread_struct *io_bitmap_owner;
        unsigned long __cacheline_filler[35];
        unsigned long stack[64];
} __attribute__((packed));
struct thread_struct {
        struct desc_struct tls_array[3];
        unsigned long esp0;
        unsigned long sysenter_cs;
        unsigned long eip;
        unsigned long esp;
        unsigned long fs;
        unsigned long gs;
        unsigned long debugreg[8];
        unsigned long cr2, trap_no, error_code;
        union i387_union i387;
        struct vm86_struct * vm86_info;
        unsigned long screen_bitmap;
        unsigned long v86flags, v86mask, saved_esp0;
        unsigned int saved_fs, saved_gs;
        unsigned long *io_bitmap_ptr;
        unsigned long iopl;
        unsigned long io_bitmap_max;
};
static inline __attribute__((always_inline)) void load_esp0(struct tss_struct *tss, struct thread_struct *thread)
{
        tss->esp0 = thread->esp0;
        if (__builtin_expect(!!(tss->ss1 != thread->sysenter_cs), 0)) {
                tss->ss1 = thread->sysenter_cs;
                __asm__ __volatile__("wrmsr" : : "c" (0x174), "a" (thread->sysenter_cs), "d" (0));
        }
}
static inline __attribute__((always_inline)) void set_iopl_mask(unsigned mask)
{
        unsigned int reg;
        __asm__ __volatile__ ("pushfl;"
                              "popl %0;"
                              "andl %1, %0;"
                              "orl %2, %0;"
                              "pushl %0;"
                              "popfl"
                                : "=&r" (reg)
                                : "i" (~0x00003000), "r" (mask));
}
struct task_struct;
struct mm_struct;
extern void release_thread(struct task_struct *);
extern void prepare_to_copy(struct task_struct *tsk);
extern int kernel_thread(int (*fn)(void *), void * arg, unsigned long flags);
extern unsigned long thread_saved_pc(struct task_struct *tsk);
void show_trace(struct task_struct *task, unsigned long *stack);
unsigned long get_wchan(struct task_struct *p);
struct microcode_header {
        unsigned int hdrver;
        unsigned int rev;
        unsigned int date;
        unsigned int sig;
        unsigned int cksum;
        unsigned int ldrver;
        unsigned int pf;
        unsigned int datasize;
        unsigned int totalsize;
        unsigned int reserved[3];
};
struct microcode {
        struct microcode_header hdr;
        unsigned int bits[0];
};
typedef struct microcode microcode_t;
typedef struct microcode_header microcode_header_t;
struct extended_signature {
        unsigned int sig;
        unsigned int pf;
        unsigned int cksum;
};
struct extended_sigtable {
        unsigned int count;
        unsigned int cksum;
        unsigned int reserved[3];
        struct extended_signature sigs[0];
};
static inline __attribute__((always_inline)) void rep_nop(void)
{
        __asm__ __volatile__("rep;nop": : :"memory");
}
static inline __attribute__((always_inline)) void prefetch(const void *x)
{
        asm volatile ("661:\n\t" ".byte 0x8d,0x74,0x26,0x00\n" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "prefetchnta (%1)" "\n664:\n" ".previous" :: "i" ((0*32+25)), "r" (x));
}
static inline __attribute__((always_inline)) void prefetchw(const void *x)
{
        asm volatile ("661:\n\t" ".byte 0x8d,0x74,0x26,0x00\n" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "prefetchw (%1)" "\n664:\n" ".previous" :: "i" ((1*32+31)), "r" (x));
}
extern void select_idle_routine(const struct cpuinfo_x86 *c);
extern unsigned long boot_option_idle_override;
extern void enable_sep_cpu(void);
extern int sysenter_setup(void);
extern void mtrr_ap_init(void);
extern void mtrr_bp_init(void);
struct thread_info {
        struct task_struct *task;
        struct exec_domain *exec_domain;
        unsigned long flags;
        unsigned long status;
        __u32 cpu;
        int preempt_count;
        mm_segment_t addr_limit;
        struct restart_block restart_block;
        unsigned long previous_esp;
        __u8 supervisor_stack[0];
};
static inline __attribute__((always_inline)) struct thread_info *current_thread_info(void)
{
        struct thread_info *ti;
        __asm__("andl %%esp,%0; ":"=r" (ti) : "0" (~((8192) - 1)));
        return ti;
}
register unsigned long current_stack_pointer asm("esp") __attribute__((__unused__));
static inline __attribute__((always_inline)) void set_thread_flag(int flag)
{
        set_bit(flag,&current_thread_info()->flags);
}
static inline __attribute__((always_inline)) void clear_thread_flag(int flag)
{
        clear_bit(flag,&current_thread_info()->flags);
}
static inline __attribute__((always_inline)) int test_and_set_thread_flag(int flag)
{
        return test_and_set_bit(flag,&current_thread_info()->flags);
}
static inline __attribute__((always_inline)) int test_and_clear_thread_flag(int flag)
{
        return test_and_clear_bit(flag,&current_thread_info()->flags);
}
static inline __attribute__((always_inline)) int test_thread_flag(int flag)
{
        return (__builtin_constant_p(flag) ? constant_test_bit((flag),(&current_thread_info()->flags)) : variable_test_bit((flag),(&current_thread_info()->flags)));
}
static inline __attribute__((always_inline)) void set_ti_thread_flag(struct thread_info *ti, int flag)
{
        set_bit(flag,&ti->flags);
}
static inline __attribute__((always_inline)) void clear_ti_thread_flag(struct thread_info *ti, int flag)
{
        clear_bit(flag,&ti->flags);
}
static inline __attribute__((always_inline)) int test_and_set_ti_thread_flag(struct thread_info *ti, int flag)
{
        return test_and_set_bit(flag,&ti->flags);
}
static inline __attribute__((always_inline)) int test_and_clear_ti_thread_flag(struct thread_info *ti, int flag)
{
        return test_and_clear_bit(flag,&ti->flags);
}
static inline __attribute__((always_inline)) int test_ti_thread_flag(struct thread_info *ti, int flag)
{
        return (__builtin_constant_p(flag) ? constant_test_bit((flag),(&ti->flags)) : variable_test_bit((flag),(&ti->flags)));
}
static inline __attribute__((always_inline)) void set_need_resched(void)
{
        set_thread_flag(3);
}
static inline __attribute__((always_inline)) void clear_need_resched(void)
{
        clear_thread_flag(3);
}
typedef struct {
        volatile unsigned int slock;
} raw_spinlock_t;
typedef struct {
        volatile unsigned int lock;
} raw_rwlock_t;
typedef struct {
        raw_spinlock_t raw_lock;
} spinlock_t;
typedef struct {
        raw_rwlock_t raw_lock;
} rwlock_t;
extern int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) generic__raw_read_trylock(raw_rwlock_t *lock);
typedef struct { volatile int counter; } atomic_t;
static __inline__ __attribute__((always_inline)) void atomic_add(int i, atomic_t *v)
{
        __asm__ __volatile__(
                "lock ; " "addl %1,%0"
                :"=m" (v->counter)
                :"ir" (i), "m" (v->counter));
}
static __inline__ __attribute__((always_inline)) void atomic_sub(int i, atomic_t *v)
{
        __asm__ __volatile__(
                "lock ; " "subl %1,%0"
                :"=m" (v->counter)
                :"ir" (i), "m" (v->counter));
}
static __inline__ __attribute__((always_inline)) int atomic_sub_and_test(int i, atomic_t *v)
{
        unsigned char c;
        __asm__ __volatile__(
                "lock ; " "subl %2,%0; sete %1"
                :"=m" (v->counter), "=qm" (c)
                :"ir" (i), "m" (v->counter) : "memory");
        return c;
}
static __inline__ __attribute__((always_inline)) void atomic_inc(atomic_t *v)
{
        __asm__ __volatile__(
                "lock ; " "incl %0"
                :"=m" (v->counter)
                :"m" (v->counter));
}
static __inline__ __attribute__((always_inline)) void atomic_dec(atomic_t *v)
{
        __asm__ __volatile__(
                "lock ; " "decl %0"
                :"=m" (v->counter)
                :"m" (v->counter));
}
static __inline__ __attribute__((always_inline)) int atomic_dec_and_test(atomic_t *v)
{
        unsigned char c;
        __asm__ __volatile__(
                "lock ; " "decl %0; sete %1"
                :"=m" (v->counter), "=qm" (c)
                :"m" (v->counter) : "memory");
        return c != 0;
}
static __inline__ __attribute__((always_inline)) int atomic_inc_and_test(atomic_t *v)
{
        unsigned char c;
        __asm__ __volatile__(
                "lock ; " "incl %0; sete %1"
                :"=m" (v->counter), "=qm" (c)
                :"m" (v->counter) : "memory");
        return c != 0;
}
static __inline__ __attribute__((always_inline)) int atomic_add_negative(int i, atomic_t *v)
{
        unsigned char c;
        __asm__ __volatile__(
                "lock ; " "addl %2,%0; sets %1"
                :"=m" (v->counter), "=qm" (c)
                :"ir" (i), "m" (v->counter) : "memory");
        return c;
}
static __inline__ __attribute__((always_inline)) int atomic_add_return(int i, atomic_t *v)
{
        int __i;
        if(__builtin_expect(!!(boot_cpu_data.x86==3), 0))
                goto no_xadd;
        __i = i;
        __asm__ __volatile__(
                "lock ; " "xaddl %0, %1;"
                :"=r"(i)
                :"m"(v->counter), "0"(i));
        return i + __i;
no_xadd:
        __asm__ __volatile__("cli": : :"memory");
        __i = ((v)->counter);
        (((v)->counter) = (i + __i));
        __asm__ __volatile__("sti": : :"memory");
        return i + __i;
}
static __inline__ __attribute__((always_inline)) int atomic_sub_return(int i, atomic_t *v)
{
        return atomic_add_return(-i,v);
}
static inline __attribute__((always_inline)) void __raw_spin_lock(raw_spinlock_t *lock)
{
        __asm__ __volatile__(
                "\n1:\t" "lock ; decb %0\n\t" "jns 3f\n" "2:\t" "rep;nop\n\t" "cmpb $0,%0\n\t" "jle 2b\n\t" "jmp 1b\n" "3:\n\t"
                :"=m" (lock->slock) : : "memory");
}
static inline __attribute__((always_inline)) void __raw_spin_lock_flags(raw_spinlock_t *lock, unsigned long flags)
{
        __asm__ __volatile__(
                "\n1:\t" "lock ; decb %0\n\t" "jns 4f\n\t" "2:\t" "testl $0x200, %1\n\t" "jz 3f\n\t" "sti\n\t" "3:\t" "rep;nop\n\t" "cmpb $0, %0\n\t" "jle 3b\n\t" "cli\n\t" "jmp 1b\n" "4:\n\t"
                :"=m" (lock->slock) : "r" (flags) : "memory");
}
static inline __attribute__((always_inline)) int __raw_spin_trylock(raw_spinlock_t *lock)
{
        char oldval;
        __asm__ __volatile__(
                "xchgb %b0,%1"
                :"=q" (oldval), "=m" (lock->slock)
                :"0" (0) : "memory");
        return oldval > 0;
}
static inline __attribute__((always_inline)) void __raw_spin_unlock(raw_spinlock_t *lock)
{
        char oldval = 1;
        __asm__ __volatile__(
                "xchgb %b0, %1" :"=q" (oldval), "=m" (lock->slock) :"0" (oldval) : "memory"
        );
}
static inline __attribute__((always_inline)) void __raw_read_lock(raw_rwlock_t *rw)
{
        do { if (__builtin_constant_p(rw)) asm volatile("lock ; " "subl $1,%0\n\t" "jns 1f\n" "pushl %%eax\n\t" "leal %0,%%eax\n\t" "call " "__read_lock_failed" "\n\t" "popl %%eax\n\t" "1:\n" :"=m" (*(volatile int *)rw) : : "memory"); else asm volatile("lock ; " "subl $1,(%0)\n\t" "jns 1f\n" "call " "__read_lock_failed" "\n\t" "1:\n" ::"a" (rw) : "memory"); } while (0);
}
static inline __attribute__((always_inline)) void __raw_write_lock(raw_rwlock_t *rw)
{
        do { if (__builtin_constant_p(rw)) asm volatile("lock ; " "subl $" "0x01000000" ",%0\n\t" "jz 1f\n" "pushl %%eax\n\t" "leal %0,%%eax\n\t" "call " "__write_lock_failed" "\n\t" "popl %%eax\n\t" "1:\n" :"=m" (*(volatile int *)rw) : : "memory"); else asm volatile("lock ; " "subl $" "0x01000000" ",(%0)\n\t" "jz 1f\n" "call " "__write_lock_failed" "\n\t" "1:\n" ::"a" (rw) : "memory"); } while (0);
}
static inline __attribute__((always_inline)) int __raw_read_trylock(raw_rwlock_t *lock)
{
        atomic_t *count = (atomic_t *)lock;
        atomic_dec(count);
        if (((count)->counter) >= 0)
                return 1;
        atomic_inc(count);
        return 0;
}
static inline __attribute__((always_inline)) int __raw_write_trylock(raw_rwlock_t *lock)
{
        atomic_t *count = (atomic_t *)lock;
        if (atomic_sub_and_test(0x01000000, count))
                return 1;
        atomic_add(0x01000000, count);
        return 0;
}
static inline __attribute__((always_inline)) void __raw_read_unlock(raw_rwlock_t *rw)
{
        asm volatile("lock ; incl %0" :"=m" (rw->lock) : : "memory");
}
static inline __attribute__((always_inline)) void __raw_write_unlock(raw_rwlock_t *rw)
{
        asm volatile("lock ; addl $" "0x01000000" ", %0"
                                 : "=m" (rw->lock) : : "memory");
}
void spin_lock_init(spinlock_t *lock);
int in_lock_functions(unsigned long addr);
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_bh(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_irq(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock_irq(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock_irq(rwlock_t *lock) ;
unsigned long __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_lock_irqsave(spinlock_t *lock)
                                                        ;
unsigned long __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_lock_irqsave(rwlock_t *lock)
                                                        ;
unsigned long __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_lock_irqsave(rwlock_t *lock)
                                                        ;
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_trylock(spinlock_t *lock);
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_trylock(rwlock_t *lock);
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_trylock(rwlock_t *lock);
int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_trylock_bh(spinlock_t *lock);
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock_bh(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock_bh(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock_irq(spinlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock_irq(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock_irq(rwlock_t *lock) ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags)
                                                        ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _read_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
                                                        ;
void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) _write_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
                                                        ;
extern int _atomic_dec_and_lock(atomic_t *atomic, spinlock_t *lock);
typedef __u32 kernel_cap_t;
extern kernel_cap_t cap_bset;
static inline __attribute__((always_inline)) kernel_cap_t cap_combine(kernel_cap_t a, kernel_cap_t b)
{
     kernel_cap_t dest;
     (dest) = (a) | (b);
     return dest;
}
static inline __attribute__((always_inline)) kernel_cap_t cap_intersect(kernel_cap_t a, kernel_cap_t b)
{
     kernel_cap_t dest;
     (dest) = (a) & (b);
     return dest;
}
static inline __attribute__((always_inline)) kernel_cap_t cap_drop(kernel_cap_t a, kernel_cap_t drop)
{
     kernel_cap_t dest;
     (dest) = (a) & ~(drop);
     return dest;
}
static inline __attribute__((always_inline)) kernel_cap_t cap_invert(kernel_cap_t c)
{
     kernel_cap_t dest;
     (dest) = ~(c);
     return dest;
}
typedef struct {
        unsigned sequence;
        spinlock_t lock;
} seqlock_t;
static inline __attribute__((always_inline)) void write_seqlock(seqlock_t *sl)
{
        _spin_lock(&sl->lock);
        ++sl->sequence;
        __asm__ __volatile__ ("": : :"memory");
}
static inline __attribute__((always_inline)) void write_sequnlock(seqlock_t *sl)
{
        __asm__ __volatile__ ("": : :"memory");
        sl->sequence++;
        _spin_unlock(&sl->lock);
}
static inline __attribute__((always_inline)) int write_tryseqlock(seqlock_t *sl)
{
        int ret = (_spin_trylock(&sl->lock));
        if (ret) {
                ++sl->sequence;
                __asm__ __volatile__ ("": : :"memory");
        }
        return ret;
}
static inline __attribute__((always_inline)) unsigned read_seqbegin(const seqlock_t *sl)
{
        unsigned ret = sl->sequence;
        asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
        return ret;
}
static inline __attribute__((always_inline)) int read_seqretry(const seqlock_t *sl, unsigned iv)
{
        asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
        return (iv & 1) | (sl->sequence ^ iv);
}
typedef struct seqcount {
        unsigned sequence;
} seqcount_t;
static inline __attribute__((always_inline)) unsigned read_seqcount_begin(const seqcount_t *s)
{
        unsigned ret = s->sequence;
        asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
        return ret;
}
static inline __attribute__((always_inline)) int read_seqcount_retry(const seqcount_t *s, unsigned iv)
{
        asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
        return (iv & 1) | (s->sequence ^ iv);
}
static inline __attribute__((always_inline)) void write_seqcount_begin(seqcount_t *s)
{
        s->sequence++;
        __asm__ __volatile__ ("": : :"memory");
}
static inline __attribute__((always_inline)) void write_seqcount_end(seqcount_t *s)
{
        __asm__ __volatile__ ("": : :"memory");
        s->sequence++;
}
struct timespec {
        time_t tv_sec;
        long tv_nsec;
};
struct timeval {
        time_t tv_sec;
        suseconds_t tv_usec;
};
struct timezone {
        int tz_minuteswest;
        int tz_dsttime;
};
static __inline__ __attribute__((always_inline)) int timespec_equal(struct timespec *a, struct timespec *b)
{
        return (a->tv_sec == b->tv_sec) && (a->tv_nsec == b->tv_nsec);
}
static inline __attribute__((always_inline)) unsigned long
mktime (unsigned int year, unsigned int mon,
        unsigned int day, unsigned int hour,
        unsigned int min, unsigned int sec)
{
        if (0 >= (int) (mon -= 2)) {
                mon += 12;
                year -= 1;
        }
        return (((
                (unsigned long) (year/4 - year/100 + year/400 + 367*mon/12 + day) +
                        year*365 - 719499
            )*24 + hour
          )*60 + min
        )*60 + sec;
}
extern struct timespec xtime;
extern struct timespec wall_to_monotonic;
extern seqlock_t xtime_lock;
static inline __attribute__((always_inline)) unsigned long get_seconds(void)
{
        return xtime.tv_sec;
}
struct timespec current_kernel_time(void);
extern void do_gettimeofday(struct timeval *tv);
extern int do_settimeofday(struct timespec *tv);
extern int do_sys_settimeofday(struct timespec *tv, struct timezone *tz);
extern void clock_was_set(void);
extern int do_posix_clock_monotonic_gettime(struct timespec *tp);
extern long do_utimes(char * filename, struct timeval * times);
struct itimerval;
extern int do_setitimer(int which, struct itimerval *value, struct itimerval *ovalue);
extern int do_getitimer(int which, struct itimerval *value);
extern void getnstimeofday (struct timespec *tv);
extern struct timespec timespec_trunc(struct timespec t, unsigned gran);
static inline __attribute__((always_inline)) void
set_normalized_timespec (struct timespec *ts, time_t sec, long nsec)
{
        while (nsec > (1000000000L)) {
                nsec -= (1000000000L);
                ++sec;
        }
        while (nsec < 0) {
                nsec += (1000000000L);
                --sec;
        }
        ts->tv_sec = sec;
        ts->tv_nsec = nsec;
}
struct itimerspec {
        struct timespec it_interval;
        struct timespec it_value;
};
struct itimerval {
        struct timeval it_interval;
        struct timeval it_value;
};
typedef unsigned long long cycles_t;
static inline __attribute__((always_inline)) cycles_t get_cycles (void)
{
        unsigned long long ret=0;
        if (!(__builtin_constant_p((0*32+ 4)) ? constant_test_bit(((0*32+ 4)),(boot_cpu_data.x86_capability)) : variable_test_bit(((0*32+ 4)),(boot_cpu_data.x86_capability))))
                return 0;
        return ret;
}
extern unsigned int cpu_khz;
extern int read_current_timer(unsigned long *timer_value);
struct timex {
        unsigned int modes;
        long offset;
        long freq;
        long maxerror;
        long esterror;
        int status;
        long constant;
        long precision;
        long tolerance;
        struct timeval time;
        long tick;
        long ppsfreq;
        long jitter;
        int shift;
        long stabil;
        long jitcnt;
        long calcnt;
        long errcnt;
        long stbcnt;
        int :32; int :32; int :32; int :32;
        int :32; int :32; int :32; int :32;
        int :32; int :32; int :32; int :32;
};
extern unsigned long tick_usec;
extern unsigned long tick_nsec;
extern int tickadj;
extern int time_state;
extern int time_status;
extern long time_offset;
extern long time_constant;
extern long time_tolerance;
extern long time_precision;
extern long time_maxerror;
extern long time_esterror;
extern long time_freq;
extern long time_reftime;
extern long time_adjust;
extern long time_next_adjust;
extern long pps_offset;
extern long pps_jitter;
extern long pps_freq;
extern long pps_stabil;
extern long pps_valid;
extern int pps_shift;
extern long pps_jitcnt;
extern long pps_calcnt;
extern long pps_errcnt;
extern long pps_stbcnt;
static inline __attribute__((always_inline)) void ntp_clear(void)
{
        time_adjust = 0;
        time_status |= 0x0040;
        time_maxerror = (512000L << 5);
        time_esterror = (512000L << 5);
}
static inline __attribute__((always_inline)) int ntp_synced(void)
{
        return !(time_status & 0x0040);
}
static inline __attribute__((always_inline)) void
time_interpolator_reset(void)
{
}
static inline __attribute__((always_inline)) long
div_ll_X_l_rem(long long divs, long div, long *rem)
{
        long dum2;
      __asm__("divl %2":"=a"(dum2), "=d"(*rem)
      : "rm"(div), "A"(divs));
        return dum2;
}
extern u64 __attribute__((section(".data"))) jiffies_64;
extern unsigned long volatile __attribute__((section(".data"))) jiffies;
u64 get_jiffies_64(void);
static inline __attribute__((always_inline)) unsigned int jiffies_to_msecs(const unsigned long j)
{
        return ((1000L) / 250) * j;
}
static inline __attribute__((always_inline)) unsigned int jiffies_to_usecs(const unsigned long j)
{
        return ((1000000L) / 250) * j;
}
static inline __attribute__((always_inline)) unsigned long msecs_to_jiffies(const unsigned int m)
{
        if (m > jiffies_to_msecs(((~0UL >> 1)-1)))
                return ((~0UL >> 1)-1);
        return (m + ((1000L) / 250) - 1) / ((1000L) / 250);
}
static inline __attribute__((always_inline)) unsigned long usecs_to_jiffies(const unsigned int u)
{
        if (u > jiffies_to_usecs(((~0UL >> 1)-1)))
                return ((~0UL >> 1)-1);
        return (u + ((1000000L) / 250) - 1) / ((1000000L) / 250);
}
static __inline__ __attribute__((always_inline)) unsigned long
timespec_to_jiffies(const struct timespec *value)
{
        unsigned long sec = value->tv_sec;
        long nsec = value->tv_nsec + (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))))) - 1;
        if (sec >= (long)((u64)((u64)((~0UL >> 1)-1) * (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))))) / (1000000000L))){
                sec = (long)((u64)((u64)((~0UL >> 1)-1) * (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))))) / (1000000000L));
                nsec = 0;
        }
        return (((u64)sec * ((unsigned long)((((u64)(1000000000L) << (32 - 8)) + (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))))) -1) / (u64)(( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))))))) +
                (((u64)nsec * ((unsigned long)((((u64)1 << ((32 - 8) + 29)) + (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))))) -1) / (u64)(( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))))))) >>
                 (((32 - 8) + 29) - (32 - 8)))) >> (32 - 8);
}
static __inline__ __attribute__((always_inline)) void
jiffies_to_timespec(const unsigned long jiffies, struct timespec *value)
{
        u64 nsec = (u64)jiffies * (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))));
        value->tv_sec = div_ll_X_l_rem(nsec,(1000000000L),&value->tv_nsec);
}
static __inline__ __attribute__((always_inline)) unsigned long
timeval_to_jiffies(const struct timeval *value)
{
        unsigned long sec = value->tv_sec;
        long usec = value->tv_usec;
        if (sec >= (long)((u64)((u64)((~0UL >> 1)-1) * (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))))) / (1000000000L))){
                sec = (long)((u64)((u64)((~0UL >> 1)-1) * (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))))) / (1000000000L));
                usec = 0;
        }
        return (((u64)sec * ((unsigned long)((((u64)(1000000000L) << (32 - 8)) + (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))))) -1) / (u64)(( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))))))) +
                (((u64)usec * ((unsigned long)((((u64)(1000L) << ((32 - 8) + 19)) + (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))))) -1) / (u64)(( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))))))) + (u64)(((u64)1 << ((32 - 8) + 19)) - 1)) >>
                 (((32 - 8) + 19) - (32 - 8)))) >> (32 - 8);
}
static __inline__ __attribute__((always_inline)) void
jiffies_to_timeval(const unsigned long jiffies, struct timeval *value)
{
        u64 nsec = (u64)jiffies * (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))));
        value->tv_sec = div_ll_X_l_rem(nsec,(1000000000L),&value->tv_usec);
        value->tv_usec /= (1000L);
}
static inline __attribute__((always_inline)) clock_t jiffies_to_clock_t(long x)
{
        u64 tmp = (u64)x * (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))));
        ({ unsigned long __upper, __low, __high, __mod, __base; __base = (((1000000000L) / 100)); asm("":"=a" (__low), "=d" (__high):"A" (tmp)); __upper = __high; if (__high) { __upper = __high % (__base); __high = __high / (__base); } asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (__base), "0" (__low), "1" (__upper)); asm("":"=A" (tmp):"a" (__low),"d" (__high)); __mod; });
        return (long)tmp;
}
static inline __attribute__((always_inline)) unsigned long clock_t_to_jiffies(unsigned long x)
{
        u64 jif;
        if (x >= ~0UL / 250 * 100)
                return ~0UL;
        jif = x * (u64) 250;
        ({ unsigned long __upper, __low, __high, __mod, __base; __base = (100); asm("":"=a" (__low), "=d" (__high):"A" (jif)); __upper = __high; if (__high) { __upper = __high % (__base); __high = __high / (__base); } asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (__base), "0" (__low), "1" (__upper)); asm("":"=A" (jif):"a" (__low),"d" (__high)); __mod; });
        return jif;
}
static inline __attribute__((always_inline)) u64 jiffies_64_to_clock_t(u64 x)
{
        x *= (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))));
        ({ unsigned long __upper, __low, __high, __mod, __base; __base = (((1000000000L) / 100)); asm("":"=a" (__low), "=d" (__high):"A" (x)); __upper = __high; if (__high) { __upper = __high % (__base); __high = __high / (__base); } asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (__base), "0" (__low), "1" (__upper)); asm("":"=A" (x):"a" (__low),"d" (__high)); __mod; });
        return x;
}
static inline __attribute__((always_inline)) u64 nsec_to_clock_t(u64 x)
{
        ({ unsigned long __upper, __low, __high, __mod, __base; __base = (((1000000000L) / 100)); asm("":"=a" (__low), "=d" (__high):"A" (x)); __upper = __high; if (__high) { __upper = __high % (__base); __high = __high / (__base); } asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (__base), "0" (__low), "1" (__upper)); asm("":"=A" (x):"a" (__low),"d" (__high)); __mod; });
        return x;
}
struct rb_node
{
        struct rb_node *rb_parent;
        int rb_color;
        struct rb_node *rb_right;
        struct rb_node *rb_left;
};
struct rb_root
{
        struct rb_node *rb_node;
};
extern void rb_insert_color(struct rb_node *, struct rb_root *);
extern void rb_erase(struct rb_node *, struct rb_root *);
extern struct rb_node *rb_next(struct rb_node *);
extern struct rb_node *rb_prev(struct rb_node *);
extern struct rb_node *rb_first(struct rb_root *);
extern struct rb_node *rb_last(struct rb_root *);
extern void rb_replace_node(struct rb_node *victim, struct rb_node *new,
                            struct rb_root *root);
static inline __attribute__((always_inline)) void rb_link_node(struct rb_node * node, struct rb_node * parent,
                                struct rb_node ** rb_link)
{
        node->rb_parent = parent;
        node->rb_color = 0;
        node->rb_left = node->rb_right = ((void *)0);
        *rb_link = node;
}
extern char * strpbrk(const char *,const char *);
extern char * strsep(char **,const char *);
extern __kernel_size_t strspn(const char *,const char *);
extern __kernel_size_t strcspn(const char *,const char *);
static inline __attribute__((always_inline)) char * strcpy(char * dest,const char *src)
{
int d0, d1, d2;
__asm__ __volatile__(
        "1:\tlodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b"
        : "=&S" (d0), "=&D" (d1), "=&a" (d2)
        :"0" (src),"1" (dest) : "memory");
return dest;
}
static inline __attribute__((always_inline)) char * strncpy(char * dest,const char *src,size_t count)
{
int d0, d1, d2, d3;
__asm__ __volatile__(
        "1:\tdecl %2\n\t"
        "js 2f\n\t"
        "lodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n\t"
        "rep\n\t"
        "stosb\n"
        "2:"
        : "=&S" (d0), "=&D" (d1), "=&c" (d2), "=&a" (d3)
        :"0" (src),"1" (dest),"2" (count) : "memory");
return dest;
}
static inline __attribute__((always_inline)) char * strcat(char * dest,const char * src)
{
int d0, d1, d2, d3;
__asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "decl %1\n"
        "1:\tlodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b"
        : "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
        : "0" (src), "1" (dest), "2" (0), "3" (0xffffffffu):"memory");
return dest;
}
static inline __attribute__((always_inline)) char * strncat(char * dest,const char * src,size_t count)
{
int d0, d1, d2, d3;
__asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "decl %1\n\t"
        "movl %8,%3\n"
        "1:\tdecl %3\n\t"
        "js 2f\n\t"
        "lodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n"
        "2:\txorl %2,%2\n\t"
        "stosb"
        : "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
        : "0" (src),"1" (dest),"2" (0),"3" (0xffffffffu), "g" (count)
        : "memory");
return dest;
}
static inline __attribute__((always_inline)) int strcmp(const char * cs,const char * ct)
{
int d0, d1;
register int __res;
__asm__ __volatile__(
        "1:\tlodsb\n\t"
        "scasb\n\t"
        "jne 2f\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n\t"
        "xorl %%eax,%%eax\n\t"
        "jmp 3f\n"
        "2:\tsbbl %%eax,%%eax\n\t"
        "orb $1,%%al\n"
        "3:"
        :"=a" (__res), "=&S" (d0), "=&D" (d1)
        :"1" (cs),"2" (ct)
        :"memory");
return __res;
}
static inline __attribute__((always_inline)) int strncmp(const char * cs,const char * ct,size_t count)
{
register int __res;
int d0, d1, d2;
__asm__ __volatile__(
        "1:\tdecl %3\n\t"
        "js 2f\n\t"
        "lodsb\n\t"
        "scasb\n\t"
        "jne 3f\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n"
        "2:\txorl %%eax,%%eax\n\t"
        "jmp 4f\n"
        "3:\tsbbl %%eax,%%eax\n\t"
        "orb $1,%%al\n"
        "4:"
        :"=a" (__res), "=&S" (d0), "=&D" (d1), "=&c" (d2)
        :"1" (cs),"2" (ct),"3" (count)
        :"memory");
return __res;
}
static inline __attribute__((always_inline)) char * strchr(const char * s, int c)
{
int d0;
register char * __res;
__asm__ __volatile__(
        "movb %%al,%%ah\n"
        "1:\tlodsb\n\t"
        "cmpb %%ah,%%al\n\t"
        "je 2f\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n\t"
        "movl $1,%1\n"
        "2:\tmovl %1,%0\n\t"
        "decl %0"
        :"=a" (__res), "=&S" (d0)
        :"1" (s),"0" (c)
        :"memory");
return __res;
}
static inline __attribute__((always_inline)) char * strrchr(const char * s, int c)
{
int d0, d1;
register char * __res;
__asm__ __volatile__(
        "movb %%al,%%ah\n"
        "1:\tlodsb\n\t"
        "cmpb %%ah,%%al\n\t"
        "jne 2f\n\t"
        "leal -1(%%esi),%0\n"
        "2:\ttestb %%al,%%al\n\t"
        "jne 1b"
        :"=g" (__res), "=&S" (d0), "=&a" (d1)
        :"0" (0),"1" (s),"2" (c)
        :"memory");
return __res;
}
static inline __attribute__((always_inline)) size_t strlen(const char * s)
{
int d0;
register int __res;
__asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "notl %0\n\t"
        "decl %0"
        :"=c" (__res), "=&D" (d0)
        :"1" (s),"a" (0), "0" (0xffffffffu)
        :"memory");
return __res;
}
static inline __attribute__((always_inline)) void * __memcpy(void * to, const void * from, size_t n)
{
int d0, d1, d2;
__asm__ __volatile__(
        "rep ; movsl\n\t"
        "movl %4,%%ecx\n\t"
        "andl $3,%%ecx\n\t"
        "jz 1f\n\t"
        "rep ; movsb\n\t"
        "1:"
        : "=&c" (d0), "=&D" (d1), "=&S" (d2)
        : "0" (n/4), "g" (n), "1" ((long) to), "2" ((long) from)
        : "memory");
return (to);
}
static inline __attribute__((always_inline)) void * __constant_memcpy(void * to, const void * from, size_t n)
{
        long esi, edi;
        if (!n) return to;
        switch (n) {
                case 1: *(char*)to = *(char*)from; return to;
                case 2: *(short*)to = *(short*)from; return to;
                case 4: *(int*)to = *(int*)from; return to;
                case 3: *(short*)to = *(short*)from;
                        *((char*)to+2) = *((char*)from+2); return to;
                case 5: *(int*)to = *(int*)from;
                        *((char*)to+4) = *((char*)from+4); return to;
                case 6: *(int*)to = *(int*)from;
                        *((short*)to+2) = *((short*)from+2); return to;
                case 8: *(int*)to = *(int*)from;
                        *((int*)to+1) = *((int*)from+1); return to;
        }
        esi = (long) from;
        edi = (long) to;
        if (n >= 5*4) {
                int ecx;
                __asm__ __volatile__(
                        "rep ; movsl"
                        : "=&c" (ecx), "=&D" (edi), "=&S" (esi)
                        : "0" (n/4), "1" (edi),"2" (esi)
                        : "memory"
                );
        } else {
                if (n >= 4*4) __asm__ __volatile__("movsl"
                        :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
                if (n >= 3*4) __asm__ __volatile__("movsl"
                        :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
                if (n >= 2*4) __asm__ __volatile__("movsl"
                        :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
                if (n >= 1*4) __asm__ __volatile__("movsl"
                        :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
        }
        switch (n % 4) {
                case 0: return to;
                case 1: __asm__ __volatile__("movsb"
                        :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
                        return to;
                case 2: __asm__ __volatile__("movsw"
                        :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
                        return to;
                default: __asm__ __volatile__("movsw\n\tmovsb"
                        :"=&D"(edi),"=&S"(esi):"0"(edi),"1"(esi):"memory");
                        return to;
        }
}
void *memmove(void * dest,const void * src, size_t n);
static inline __attribute__((always_inline)) void * memchr(const void * cs,int c,size_t count)
{
int d0;
register void * __res;
if (!count)
        return ((void *)0);
__asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "je 1f\n\t"
        "movl $1,%0\n"
        "1:\tdecl %0"
        :"=D" (__res), "=&c" (d0)
        :"a" (c),"0" (cs),"1" (count)
        :"memory");
return __res;
}
static inline __attribute__((always_inline)) void * __memset_generic(void * s, char c,size_t count)
{
int d0, d1;
__asm__ __volatile__(
        "rep\n\t"
        "stosb"
        : "=&c" (d0), "=&D" (d1)
        :"a" (c),"1" (s),"0" (count)
        :"memory");
return s;
}
static inline __attribute__((always_inline)) void * __constant_c_memset(void * s, unsigned long c, size_t count)
{
int d0, d1;
__asm__ __volatile__(
        "rep ; stosl\n\t"
        "testb $2,%b3\n\t"
        "je 1f\n\t"
        "stosw\n"
        "1:\ttestb $1,%b3\n\t"
        "je 2f\n\t"
        "stosb\n"
        "2:"
        :"=&c" (d0), "=&D" (d1)
        :"a" (c), "q" (count), "0" (count/4), "1" ((long) s)
        :"memory");
return (s);
}
static inline __attribute__((always_inline)) size_t strnlen(const char * s, size_t count)
{
int d0;
register int __res;
__asm__ __volatile__(
        "movl %2,%0\n\t"
        "jmp 2f\n"
        "1:\tcmpb $0,(%0)\n\t"
        "je 3f\n\t"
        "incl %0\n"
        "2:\tdecl %1\n\t"
        "cmpl $-1,%1\n\t"
        "jne 1b\n"
        "3:\tsubl %2,%0"
        :"=a" (__res), "=&d" (d0)
        :"c" (s),"1" (count)
        :"memory");
return __res;
}
extern char *strstr(const char *cs, const char *ct);
static inline __attribute__((always_inline)) void * __constant_c_and_count_memset(void * s, unsigned long pattern, size_t count)
{
        switch (count) {
                case 0:
                        return s;
                case 1:
                        *(unsigned char *)s = pattern;
                        return s;
                case 2:
                        *(unsigned short *)s = pattern;
                        return s;
                case 3:
                        *(unsigned short *)s = pattern;
                        *(2+(unsigned char *)s) = pattern;
                        return s;
                case 4:
                        *(unsigned long *)s = pattern;
                        return s;
        }
{
        int d0, d1;
        switch (count % 4) {
                case 0: __asm__ __volatile__( "rep ; stosl" "" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
                case 1: __asm__ __volatile__( "rep ; stosl" "\n\tstosb" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
                case 2: __asm__ __volatile__( "rep ; stosl" "\n\tstosw" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
                default: __asm__ __volatile__( "rep ; stosl" "\n\tstosw\n\tstosb" : "=&c" (d0), "=&D" (d1) : "a" (pattern),"0" (count/4),"1" ((long) s) : "memory"); return s;
        }
}
}
static inline __attribute__((always_inline)) void * memscan(void * addr, int c, size_t size)
{
        if (!size)
                return addr;
        __asm__("repnz; scasb\n\t"
                "jnz 1f\n\t"
                "dec %%edi\n"
                "1:"
                : "=D" (addr), "=c" (size)
                : "0" (addr), "1" (size), "a" (c)
                : "memory");
        return addr;
}
size_t strlcpy(char *, const char *, size_t);
extern size_t strlcat(char *, const char *, __kernel_size_t);
extern int strnicmp(const char *, const char *, __kernel_size_t);
extern char * strnchr(const char *, size_t, int);
extern int __builtin_memcmp(const void *,const void *,__kernel_size_t);
extern char *kstrdup(const char *s, gfp_t gfp);
extern int __bitmap_empty(const unsigned long *bitmap, int bits);
extern int __bitmap_full(const unsigned long *bitmap, int bits);
extern int __bitmap_equal(const unsigned long *bitmap1,
                        const unsigned long *bitmap2, int bits);
extern void __bitmap_complement(unsigned long *dst, const unsigned long *src,
                        int bits);
extern void __bitmap_shift_right(unsigned long *dst,
                        const unsigned long *src, int shift, int bits);
extern void __bitmap_shift_left(unsigned long *dst,
                        const unsigned long *src, int shift, int bits);
extern void __bitmap_and(unsigned long *dst, const unsigned long *bitmap1,
                        const unsigned long *bitmap2, int bits);
extern void __bitmap_or(unsigned long *dst, const unsigned long *bitmap1,
                        const unsigned long *bitmap2, int bits);
extern void __bitmap_xor(unsigned long *dst, const unsigned long *bitmap1,
                        const unsigned long *bitmap2, int bits);
extern void __bitmap_andnot(unsigned long *dst, const unsigned long *bitmap1,
                        const unsigned long *bitmap2, int bits);
extern int __bitmap_intersects(const unsigned long *bitmap1,
                        const unsigned long *bitmap2, int bits);
extern int __bitmap_subset(const unsigned long *bitmap1,
                        const unsigned long *bitmap2, int bits);
extern int __bitmap_weight(const unsigned long *bitmap, int bits);
extern int bitmap_scnprintf(char *buf, unsigned int len,
                        const unsigned long *src, int nbits);
extern int bitmap_parse(const char *ubuf, unsigned int ulen,
                        unsigned long *dst, int nbits);
extern int bitmap_scnlistprintf(char *buf, unsigned int len,
                        const unsigned long *src, int nbits);
extern int bitmap_parselist(const char *buf, unsigned long *maskp,
                        int nmaskbits);
extern int bitmap_find_free_region(unsigned long *bitmap, int bits, int order);
extern void bitmap_release_region(unsigned long *bitmap, int pos, int order);
extern int bitmap_allocate_region(unsigned long *bitmap, int pos, int order);
static inline __attribute__((always_inline)) void bitmap_zero(unsigned long *dst, int nbits)
{
        if (nbits <= 32)
                *dst = 0UL;
        else {
                int len = (((nbits)+32 -1)/32) * sizeof(unsigned long);
                (__builtin_constant_p(0) ? (__builtin_constant_p((len)) ? __constant_c_and_count_memset(((dst)),((0x01010101UL*(unsigned char)(0))),((len))) : __constant_c_memset(((dst)),((0x01010101UL*(unsigned char)(0))),((len)))) : (__builtin_constant_p((len)) ? __memset_generic((((dst))),(((0))),(((len)))) : __memset_generic(((dst)),((0)),((len)))));
        }
}
static inline __attribute__((always_inline)) void bitmap_fill(unsigned long *dst, int nbits)
{
        size_t nlongs = (((nbits)+32 -1)/32);
        if (nlongs > 1) {
                int len = (nlongs - 1) * sizeof(unsigned long);
                (__builtin_constant_p(0xff) ? (__builtin_constant_p((len)) ? __constant_c_and_count_memset(((dst)),((0x01010101UL*(unsigned char)(0xff))),((len))) : __constant_c_memset(((dst)),((0x01010101UL*(unsigned char)(0xff))),((len)))) : (__builtin_constant_p((len)) ? __memset_generic((((dst))),(((0xff))),(((len)))) : __memset_generic(((dst)),((0xff)),((len)))));
        }
        dst[nlongs - 1] = ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL );
}
static inline __attribute__((always_inline)) void bitmap_copy(unsigned long *dst, const unsigned long *src,
                        int nbits)
{
        if (nbits <= 32)
                *dst = *src;
        else {
                int len = (((nbits)+32 -1)/32) * sizeof(unsigned long);
                (__builtin_constant_p(len) ? __constant_memcpy((dst),(src),(len)) : __memcpy((dst),(src),(len)));
        }
}
static inline __attribute__((always_inline)) void bitmap_and(unsigned long *dst, const unsigned long *src1,
                        const unsigned long *src2, int nbits)
{
        if (nbits <= 32)
                *dst = *src1 & *src2;
        else
                __bitmap_and(dst, src1, src2, nbits);
}
static inline __attribute__((always_inline)) void bitmap_or(unsigned long *dst, const unsigned long *src1,
                        const unsigned long *src2, int nbits)
{
        if (nbits <= 32)
                *dst = *src1 | *src2;
        else
                __bitmap_or(dst, src1, src2, nbits);
}
static inline __attribute__((always_inline)) void bitmap_xor(unsigned long *dst, const unsigned long *src1,
                        const unsigned long *src2, int nbits)
{
        if (nbits <= 32)
                *dst = *src1 ^ *src2;
        else
                __bitmap_xor(dst, src1, src2, nbits);
}
static inline __attribute__((always_inline)) void bitmap_andnot(unsigned long *dst, const unsigned long *src1,
                        const unsigned long *src2, int nbits)
{
        if (nbits <= 32)
                *dst = *src1 & ~(*src2);
        else
                __bitmap_andnot(dst, src1, src2, nbits);
}
static inline __attribute__((always_inline)) void bitmap_complement(unsigned long *dst, const unsigned long *src,
                        int nbits)
{
        if (nbits <= 32)
                *dst = ~(*src) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL );
        else
                __bitmap_complement(dst, src, nbits);
}
static inline __attribute__((always_inline)) int bitmap_equal(const unsigned long *src1,
                        const unsigned long *src2, int nbits)
{
        if (nbits <= 32)
                return ! ((*src1 ^ *src2) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
        else
                return __bitmap_equal(src1, src2, nbits);
}
static inline __attribute__((always_inline)) int bitmap_intersects(const unsigned long *src1,
                        const unsigned long *src2, int nbits)
{
        if (nbits <= 32)
                return ((*src1 & *src2) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL )) != 0;
        else
                return __bitmap_intersects(src1, src2, nbits);
}
static inline __attribute__((always_inline)) int bitmap_subset(const unsigned long *src1,
                        const unsigned long *src2, int nbits)
{
        if (nbits <= 32)
                return ! ((*src1 & ~(*src2)) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
        else
                return __bitmap_subset(src1, src2, nbits);
}
static inline __attribute__((always_inline)) int bitmap_empty(const unsigned long *src, int nbits)
{
        if (nbits <= 32)
                return ! (*src & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
        else
                return __bitmap_empty(src, nbits);
}
static inline __attribute__((always_inline)) int bitmap_full(const unsigned long *src, int nbits)
{
        if (nbits <= 32)
                return ! (~(*src) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL ));
        else
                return __bitmap_full(src, nbits);
}
static inline __attribute__((always_inline)) int bitmap_weight(const unsigned long *src, int nbits)
{
        return __bitmap_weight(src, nbits);
}
static inline __attribute__((always_inline)) void bitmap_shift_right(unsigned long *dst,
                        const unsigned long *src, int n, int nbits)
{
        if (nbits <= 32)
                *dst = *src >> n;
        else
                __bitmap_shift_right(dst, src, n, nbits);
}
static inline __attribute__((always_inline)) void bitmap_shift_left(unsigned long *dst,
                        const unsigned long *src, int n, int nbits)
{
        if (nbits <= 32)
                *dst = (*src << n) & ( ((nbits) % 32) ? (1UL<<((nbits) % 32))-1 : ~0UL );
        else
                __bitmap_shift_left(dst, src, n, nbits);
}
typedef struct { unsigned long bits[(((8)+32 -1)/32)]; } cpumask_t;
extern cpumask_t _unused_cpumask_arg_;
static inline __attribute__((always_inline)) void __cpu_set(int cpu, volatile cpumask_t *dstp)
{
        set_bit(cpu, dstp->bits);
}
static inline __attribute__((always_inline)) void __cpu_clear(int cpu, volatile cpumask_t *dstp)
{
        clear_bit(cpu, dstp->bits);
}
static inline __attribute__((always_inline)) void __cpus_setall(cpumask_t *dstp, int nbits)
{
        bitmap_fill(dstp->bits, nbits);
}
static inline __attribute__((always_inline)) void __cpus_clear(cpumask_t *dstp, int nbits)
{
        bitmap_zero(dstp->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpu_test_and_set(int cpu, cpumask_t *addr)
{
        return test_and_set_bit(cpu, addr->bits);
}
static inline __attribute__((always_inline)) void __cpus_and(cpumask_t *dstp, const cpumask_t *src1p,
                                        const cpumask_t *src2p, int nbits)
{
        bitmap_and(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __cpus_or(cpumask_t *dstp, const cpumask_t *src1p,
                                        const cpumask_t *src2p, int nbits)
{
        bitmap_or(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __cpus_xor(cpumask_t *dstp, const cpumask_t *src1p,
                                        const cpumask_t *src2p, int nbits)
{
        bitmap_xor(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __cpus_andnot(cpumask_t *dstp, const cpumask_t *src1p,
                                        const cpumask_t *src2p, int nbits)
{
        bitmap_andnot(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __cpus_complement(cpumask_t *dstp,
                                        const cpumask_t *srcp, int nbits)
{
        bitmap_complement(dstp->bits, srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpus_equal(const cpumask_t *src1p,
                                        const cpumask_t *src2p, int nbits)
{
        return bitmap_equal(src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpus_intersects(const cpumask_t *src1p,
                                        const cpumask_t *src2p, int nbits)
{
        return bitmap_intersects(src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpus_subset(const cpumask_t *src1p,
                                        const cpumask_t *src2p, int nbits)
{
        return bitmap_subset(src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpus_empty(const cpumask_t *srcp, int nbits)
{
        return bitmap_empty(srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpus_full(const cpumask_t *srcp, int nbits)
{
        return bitmap_full(srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpus_weight(const cpumask_t *srcp, int nbits)
{
        return bitmap_weight(srcp->bits, nbits);
}
static inline __attribute__((always_inline)) void __cpus_shift_right(cpumask_t *dstp,
                                        const cpumask_t *srcp, int n, int nbits)
{
        bitmap_shift_right(dstp->bits, srcp->bits, n, nbits);
}
static inline __attribute__((always_inline)) void __cpus_shift_left(cpumask_t *dstp,
                                        const cpumask_t *srcp, int n, int nbits)
{
        bitmap_shift_left(dstp->bits, srcp->bits, n, nbits);
}
static inline __attribute__((always_inline)) int __first_cpu(const cpumask_t *srcp, int nbits)
{
        return ({ int __x = (nbits); int __y = (find_first_bit(srcp->bits, nbits)); __x < __y ? __x: __y; });
}
static inline __attribute__((always_inline)) int __next_cpu(int n, const cpumask_t *srcp, int nbits)
{
        return ({ int __x = (nbits); int __y = (find_next_bit(srcp->bits, nbits, n+1)); __x < __y ? __x: __y; });
}
static inline __attribute__((always_inline)) int __cpumask_scnprintf(char *buf, int len,
                                        const cpumask_t *srcp, int nbits)
{
        return bitmap_scnprintf(buf, len, srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpumask_parse(const char *buf, int len,
                                        cpumask_t *dstp, int nbits)
{
        return bitmap_parse(buf, len, dstp->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpulist_scnprintf(char *buf, int len,
                                        const cpumask_t *srcp, int nbits)
{
        return bitmap_scnlistprintf(buf, len, srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __cpulist_parse(const char *buf, cpumask_t *dstp, int nbits)
{
        return bitmap_parselist(buf, dstp->bits, nbits);
}
extern cpumask_t cpu_possible_map;
extern cpumask_t cpu_online_map;
extern cpumask_t cpu_present_map;
typedef struct { unsigned long bits[((((1 << 0))+32 -1)/32)]; } nodemask_t;
extern nodemask_t _unused_nodemask_arg_;
static inline __attribute__((always_inline)) void __node_set(int node, volatile nodemask_t *dstp)
{
        set_bit(node, dstp->bits);
}
static inline __attribute__((always_inline)) void __node_clear(int node, volatile nodemask_t *dstp)
{
        clear_bit(node, dstp->bits);
}
static inline __attribute__((always_inline)) void __nodes_setall(nodemask_t *dstp, int nbits)
{
        bitmap_fill(dstp->bits, nbits);
}
static inline __attribute__((always_inline)) void __nodes_clear(nodemask_t *dstp, int nbits)
{
        bitmap_zero(dstp->bits, nbits);
}
static inline __attribute__((always_inline)) int __node_test_and_set(int node, nodemask_t *addr)
{
        return test_and_set_bit(node, addr->bits);
}
static inline __attribute__((always_inline)) void __nodes_and(nodemask_t *dstp, const nodemask_t *src1p,
                                        const nodemask_t *src2p, int nbits)
{
        bitmap_and(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __nodes_or(nodemask_t *dstp, const nodemask_t *src1p,
                                        const nodemask_t *src2p, int nbits)
{
        bitmap_or(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __nodes_xor(nodemask_t *dstp, const nodemask_t *src1p,
                                        const nodemask_t *src2p, int nbits)
{
        bitmap_xor(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __nodes_andnot(nodemask_t *dstp, const nodemask_t *src1p,
                                        const nodemask_t *src2p, int nbits)
{
        bitmap_andnot(dstp->bits, src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) void __nodes_complement(nodemask_t *dstp,
                                        const nodemask_t *srcp, int nbits)
{
        bitmap_complement(dstp->bits, srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodes_equal(const nodemask_t *src1p,
                                        const nodemask_t *src2p, int nbits)
{
        return bitmap_equal(src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodes_intersects(const nodemask_t *src1p,
                                        const nodemask_t *src2p, int nbits)
{
        return bitmap_intersects(src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodes_subset(const nodemask_t *src1p,
                                        const nodemask_t *src2p, int nbits)
{
        return bitmap_subset(src1p->bits, src2p->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodes_empty(const nodemask_t *srcp, int nbits)
{
        return bitmap_empty(srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodes_full(const nodemask_t *srcp, int nbits)
{
        return bitmap_full(srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodes_weight(const nodemask_t *srcp, int nbits)
{
        return bitmap_weight(srcp->bits, nbits);
}
static inline __attribute__((always_inline)) void __nodes_shift_right(nodemask_t *dstp,
                                        const nodemask_t *srcp, int n, int nbits)
{
        bitmap_shift_right(dstp->bits, srcp->bits, n, nbits);
}
static inline __attribute__((always_inline)) void __nodes_shift_left(nodemask_t *dstp,
                                        const nodemask_t *srcp, int n, int nbits)
{
        bitmap_shift_left(dstp->bits, srcp->bits, n, nbits);
}
static inline __attribute__((always_inline)) int __first_node(const nodemask_t *srcp)
{
        return ({ int __x = ((1 << 0)); int __y = (find_first_bit(srcp->bits, (1 << 0))); __x < __y ? __x: __y; });
}
static inline __attribute__((always_inline)) int __next_node(int n, const nodemask_t *srcp)
{
        return ({ int __x = ((1 << 0)); int __y = (find_next_bit(srcp->bits, (1 << 0), n+1)); __x < __y ? __x: __y; });
}
static inline __attribute__((always_inline)) int __first_unset_node(const nodemask_t *maskp)
{
        return ({ int __x = ((1 << 0)); int __y = (find_first_zero_bit(maskp->bits, (1 << 0))); __x < __y ? __x: __y; });
}
static inline __attribute__((always_inline)) int __nodemask_scnprintf(char *buf, int len,
                                        const nodemask_t *srcp, int nbits)
{
        return bitmap_scnprintf(buf, len, srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodemask_parse(const char *buf, int len,
                                        nodemask_t *dstp, int nbits)
{
        return bitmap_parse(buf, len, dstp->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodelist_scnprintf(char *buf, int len,
                                        const nodemask_t *srcp, int nbits)
{
        return bitmap_scnlistprintf(buf, len, srcp->bits, nbits);
}
static inline __attribute__((always_inline)) int __nodelist_parse(const char *buf, nodemask_t *dstp, int nbits)
{
        return bitmap_parselist(buf, dstp->bits, nbits);
}
extern nodemask_t node_online_map;
extern nodemask_t node_possible_map;
static inline __attribute__((always_inline)) void prefetch_range(void *addr, size_t len)
{
        char *cp;
        char *end = addr + len;
        for (cp = addr; cp < end; cp += (4*(1 << (4))))
                prefetch(cp);
}
struct list_head {
        struct list_head *next, *prev;
};
static inline __attribute__((always_inline)) void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}
static inline __attribute__((always_inline)) void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}
static inline __attribute__((always_inline)) void list_add_tail(struct list_head *new, struct list_head *head)
{
        __list_add(new, head->prev, head);
}
static inline __attribute__((always_inline)) void __list_add_rcu(struct list_head * new,
                struct list_head * prev, struct list_head * next)
{
        new->next = next;
        new->prev = prev;
        __asm__ __volatile__ ("": : :"memory");
        next->prev = new;
        prev->next = new;
}
static inline __attribute__((always_inline)) void list_add_rcu(struct list_head *new, struct list_head *head)
{
        __list_add_rcu(new, head, head->next);
}
static inline __attribute__((always_inline)) void list_add_tail_rcu(struct list_head *new,
                                        struct list_head *head)
{
        __list_add_rcu(new, head->prev, head);
}
static inline __attribute__((always_inline)) void __list_del(struct list_head * prev, struct list_head * next)
{
        next->prev = prev;
        prev->next = next;
}
static inline __attribute__((always_inline)) void list_del(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        entry->next = ((void *) 0x00100100);
        entry->prev = ((void *) 0x00200200);
}
static inline __attribute__((always_inline)) void list_del_rcu(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        entry->prev = ((void *) 0x00200200);
}
static inline __attribute__((always_inline)) void list_replace_rcu(struct list_head *old, struct list_head *new){
        new->next = old->next;
        new->prev = old->prev;
        __asm__ __volatile__ ("": : :"memory");
        new->next->prev = new;
        new->prev->next = new;
}
static inline __attribute__((always_inline)) void list_del_init(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        do { (entry)->next = (entry); (entry)->prev = (entry); } while (0);
}
static inline __attribute__((always_inline)) void list_move(struct list_head *list, struct list_head *head)
{
        __list_del(list->prev, list->next);
        list_add(list, head);
}
static inline __attribute__((always_inline)) void list_move_tail(struct list_head *list,
                                  struct list_head *head)
{
        __list_del(list->prev, list->next);
        list_add_tail(list, head);
}
static inline __attribute__((always_inline)) int list_empty(const struct list_head *head)
{
        return head->next == head;
}
static inline __attribute__((always_inline)) int list_empty_careful(const struct list_head *head)
{
        struct list_head *next = head->next;
        return (next == head) && (next == head->prev);
}
static inline __attribute__((always_inline)) void __list_splice(struct list_head *list,
                                 struct list_head *head)
{
        struct list_head *first = list->next;
        struct list_head *last = list->prev;
        struct list_head *at = head->next;
        first->prev = head;
        head->next = first;
        last->next = at;
        at->prev = last;
}
static inline __attribute__((always_inline)) void list_splice(struct list_head *list, struct list_head *head)
{
        if (!list_empty(list))
                __list_splice(list, head);
}
static inline __attribute__((always_inline)) void list_splice_init(struct list_head *list,
                                    struct list_head *head)
{
        if (!list_empty(list)) {
                __list_splice(list, head);
                do { (list)->next = (list); (list)->prev = (list); } while (0);
        }
}
struct hlist_head {
        struct hlist_node *first;
};
struct hlist_node {
        struct hlist_node *next, **pprev;
};
static inline __attribute__((always_inline)) int hlist_unhashed(const struct hlist_node *h)
{
        return !h->pprev;
}
static inline __attribute__((always_inline)) int hlist_empty(const struct hlist_head *h)
{
        return !h->first;
}
static inline __attribute__((always_inline)) void __hlist_del(struct hlist_node *n)
{
        struct hlist_node *next = n->next;
        struct hlist_node **pprev = n->pprev;
        *pprev = next;
        if (next)
                next->pprev = pprev;
}
static inline __attribute__((always_inline)) void hlist_del(struct hlist_node *n)
{
        __hlist_del(n);
        n->next = ((void *) 0x00100100);
        n->pprev = ((void *) 0x00200200);
}
static inline __attribute__((always_inline)) void hlist_del_rcu(struct hlist_node *n)
{
        __hlist_del(n);
        n->pprev = ((void *) 0x00200200);
}
static inline __attribute__((always_inline)) void hlist_del_init(struct hlist_node *n)
{
        if (n->pprev) {
                __hlist_del(n);
                ((n)->next = ((void *)0), (n)->pprev = ((void *)0));
        }
}
static inline __attribute__((always_inline)) void hlist_add_head(struct hlist_node *n, struct hlist_head *h)
{
        struct hlist_node *first = h->first;
        n->next = first;
        if (first)
                first->pprev = &n->next;
        h->first = n;
        n->pprev = &h->first;
}
static inline __attribute__((always_inline)) void hlist_add_head_rcu(struct hlist_node *n,
                                        struct hlist_head *h)
{
        struct hlist_node *first = h->first;
        n->next = first;
        n->pprev = &h->first;
        __asm__ __volatile__ ("": : :"memory");
        if (first)
                first->pprev = &n->next;
        h->first = n;
}
static inline __attribute__((always_inline)) void hlist_add_before(struct hlist_node *n,
                                        struct hlist_node *next)
{
        n->pprev = next->pprev;
        n->next = next;
        next->pprev = &n->next;
        *(n->pprev) = n;
}
static inline __attribute__((always_inline)) void hlist_add_after(struct hlist_node *n,
                                        struct hlist_node *next)
{
        next->next = n->next;
        n->next = next;
        next->pprev = &n->next;
        if(next->next)
                next->next->pprev = &next->next;
}
static inline __attribute__((always_inline)) void hlist_add_before_rcu(struct hlist_node *n,
                                        struct hlist_node *next)
{
        n->pprev = next->pprev;
        n->next = next;
        __asm__ __volatile__ ("": : :"memory");
        next->pprev = &n->next;
        *(n->pprev) = n;
}
static inline __attribute__((always_inline)) void hlist_add_after_rcu(struct hlist_node *prev,
                                       struct hlist_node *n)
{
        n->next = prev->next;
        n->pprev = &prev->next;
        __asm__ __volatile__ ("": : :"memory");
        prev->next = n;
        if (n->next)
                n->next->pprev = &n->next;
}
struct task_struct;
static inline __attribute__((always_inline)) struct task_struct * get_current(void)
{
        return current_thread_info()->task;
}
typedef struct __wait_queue wait_queue_t;
typedef int (*wait_queue_func_t)(wait_queue_t *wait, unsigned mode, int sync, void *key);
int default_wake_function(wait_queue_t *wait, unsigned mode, int sync, void *key);
struct __wait_queue {
        unsigned int flags;
        void *private;
        wait_queue_func_t func;
        struct list_head task_list;
};
struct wait_bit_key {
        void *flags;
        int bit_nr;
};
struct wait_bit_queue {
        struct wait_bit_key key;
        wait_queue_t wait;
};
struct __wait_queue_head {
        spinlock_t lock;
        struct list_head task_list;
};
typedef struct __wait_queue_head wait_queue_head_t;
static inline __attribute__((always_inline)) void init_waitqueue_head(wait_queue_head_t *q)
{
        spin_lock_init(&q->lock);
        do { (&q->task_list)->next = (&q->task_list); (&q->task_list)->prev = (&q->task_list); } while (0);
}
static inline __attribute__((always_inline)) void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
{
        q->flags = 0;
        q->private = p;
        q->func = default_wake_function;
}
static inline __attribute__((always_inline)) void init_waitqueue_func_entry(wait_queue_t *q,
                                        wait_queue_func_t func)
{
        q->flags = 0;
        q->private = ((void *)0);
        q->func = func;
}
static inline __attribute__((always_inline)) int waitqueue_active(wait_queue_head_t *q)
{
        return !list_empty(&q->task_list);
}
extern void add_wait_queue(wait_queue_head_t *q, wait_queue_t * wait) __attribute__((regparm(3)));
extern void add_wait_queue_exclusive(wait_queue_head_t *q, wait_queue_t * wait) __attribute__((regparm(3)));
extern void remove_wait_queue(wait_queue_head_t *q, wait_queue_t * wait) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) void __add_wait_queue(wait_queue_head_t *head, wait_queue_t *new)
{
        list_add(&new->task_list, &head->task_list);
}
static inline __attribute__((always_inline)) void __add_wait_queue_tail(wait_queue_head_t *head,
                                                wait_queue_t *new)
{
        list_add_tail(&new->task_list, &head->task_list);
}
static inline __attribute__((always_inline)) void __remove_wait_queue(wait_queue_head_t *head,
                                                        wait_queue_t *old)
{
        list_del(&old->task_list);
}
void __wake_up(wait_queue_head_t *q, unsigned int mode, int nr, void *key) __attribute__((regparm(3)));
extern void __wake_up_locked(wait_queue_head_t *q, unsigned int mode) __attribute__((regparm(3)));
extern void __wake_up_sync(wait_queue_head_t *q, unsigned int mode, int nr) __attribute__((regparm(3)));
void __wake_up_bit(wait_queue_head_t *, void *, int) __attribute__((regparm(3)));
int __wait_on_bit(wait_queue_head_t *, struct wait_bit_queue *, int (*)(void *), unsigned) __attribute__((regparm(3)));
int __wait_on_bit_lock(wait_queue_head_t *, struct wait_bit_queue *, int (*)(void *), unsigned) __attribute__((regparm(3)));
void wake_up_bit(void *, int) __attribute__((regparm(3)));
int out_of_line_wait_on_bit(void *, int, int (*)(void *), unsigned) __attribute__((regparm(3)));
int out_of_line_wait_on_bit_lock(void *, int, int (*)(void *), unsigned) __attribute__((regparm(3)));
wait_queue_head_t *bit_waitqueue(void *, int) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) void add_wait_queue_exclusive_locked(wait_queue_head_t *q,
                                                   wait_queue_t * wait)
{
        wait->flags |= 0x01;
        __add_wait_queue_tail(q, wait);
}
static inline __attribute__((always_inline)) void remove_wait_queue_locked(wait_queue_head_t *q,
                                            wait_queue_t * wait)
{
        __remove_wait_queue(q, wait);
}
extern void sleep_on(wait_queue_head_t *q) __attribute__((regparm(3)));
extern long sleep_on_timeout(wait_queue_head_t *q, signed long timeout) __attribute__((regparm(3)));
extern void interruptible_sleep_on(wait_queue_head_t *q) __attribute__((regparm(3)));
extern long interruptible_sleep_on_timeout(wait_queue_head_t *q, signed long timeout) __attribute__((regparm(3)));
void prepare_to_wait(wait_queue_head_t *q, wait_queue_t *wait, int state) __attribute__((regparm(3)));
void prepare_to_wait_exclusive(wait_queue_head_t *q, wait_queue_t *wait, int state) __attribute__((regparm(3)));
void finish_wait(wait_queue_head_t *q, wait_queue_t *wait) __attribute__((regparm(3)));
int autoremove_wake_function(wait_queue_t *wait, unsigned mode, int sync, void *key);
int wake_bit_function(wait_queue_t *wait, unsigned mode, int sync, void *key);
static inline __attribute__((always_inline)) int wait_on_bit(void *word, int bit,
                                int (*action)(void *), unsigned mode)
{
        if (!(__builtin_constant_p(bit) ? constant_test_bit((bit),(word)) : variable_test_bit((bit),(word))))
                return 0;
        return out_of_line_wait_on_bit(word, bit, action, mode);
}
static inline __attribute__((always_inline)) int wait_on_bit_lock(void *word, int bit,
                                int (*action)(void *), unsigned mode)
{
        if (!test_and_set_bit(bit, word))
                return 0;
        return out_of_line_wait_on_bit_lock(word, bit, action, mode);
}
struct rw_semaphore;
struct rwsem_waiter;
struct rw_semaphore {
        __s32 activity;
        spinlock_t wait_lock;
        struct list_head wait_list;
};
extern void init_rwsem(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __down_read(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern int __down_read_trylock(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __down_write(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern int __down_write_trylock(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __up_read(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __up_write(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __downgrade_write(struct rw_semaphore *sem) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) void down_read(struct rw_semaphore *sem)
{
        do { do { } while (0); } while (0);
        ;
        __down_read(sem);
        ;
}
static inline __attribute__((always_inline)) int down_read_trylock(struct rw_semaphore *sem)
{
        int ret;
        ;
        ret = __down_read_trylock(sem);
        ;
        return ret;
}
static inline __attribute__((always_inline)) void down_write(struct rw_semaphore *sem)
{
        do { do { } while (0); } while (0);
        ;
        __down_write(sem);
        ;
}
static inline __attribute__((always_inline)) int down_write_trylock(struct rw_semaphore *sem)
{
        int ret;
        ;
        ret = __down_write_trylock(sem);
        ;
        return ret;
}
static inline __attribute__((always_inline)) void up_read(struct rw_semaphore *sem)
{
        ;
        __up_read(sem);
        ;
}
static inline __attribute__((always_inline)) void up_write(struct rw_semaphore *sem)
{
        ;
        __up_write(sem);
        ;
}
static inline __attribute__((always_inline)) void downgrade_write(struct rw_semaphore *sem)
{
        ;
        __downgrade_write(sem);
        ;
}
struct semaphore {
        atomic_t count;
        int sleepers;
        wait_queue_head_t wait;
};
static inline __attribute__((always_inline)) void sema_init (struct semaphore *sem, int val)
{
        (((&sem->count)->counter) = (val));
        sem->sleepers = 0;
        init_waitqueue_head(&sem->wait);
}
static inline __attribute__((always_inline)) void init_MUTEX (struct semaphore *sem)
{
        sema_init(sem, 1);
}
static inline __attribute__((always_inline)) void init_MUTEX_LOCKED (struct semaphore *sem)
{
        sema_init(sem, 0);
}
__attribute__((regparm(3))) void __down_failed(void );
__attribute__((regparm(3))) int __down_failed_interruptible(void );
__attribute__((regparm(3))) int __down_failed_trylock(void );
__attribute__((regparm(3))) void __up_wakeup(void );
static inline __attribute__((always_inline)) void down(struct semaphore * sem)
{
        do { do { } while (0); } while (0);
        __asm__ __volatile__(
                "# atomic down operation\n\t"
                "lock ; " "decl %0\n\t"
                "js 2f\n"
                "1:\n"
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "consolemap" "\n\t" ".text.lock." "consolemap" ":\n\t" ".endif\n"
                "2:\tlea %0,%%eax\n\t"
                "call __down_failed\n\t"
                "jmp 1b\n"
                ".previous\n\t"
                :"=m" (sem->count)
                :
                :"memory","ax");
}
static inline __attribute__((always_inline)) int down_interruptible(struct semaphore * sem)
{
        int result;
        do { do { } while (0); } while (0);
        __asm__ __volatile__(
                "# atomic interruptible down operation\n\t"
                "lock ; " "decl %1\n\t"
                "js 2f\n\t"
                "xorl %0,%0\n"
                "1:\n"
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "consolemap" "\n\t" ".text.lock." "consolemap" ":\n\t" ".endif\n"
                "2:\tlea %1,%%eax\n\t"
                "call __down_failed_interruptible\n\t"
                "jmp 1b\n"
                ".previous\n\t"
                :"=a" (result), "=m" (sem->count)
                :
                :"memory");
        return result;
}
static inline __attribute__((always_inline)) int down_trylock(struct semaphore * sem)
{
        int result;
        __asm__ __volatile__(
                "# atomic interruptible down operation\n\t"
                "lock ; " "decl %1\n\t"
                "js 2f\n\t"
                "xorl %0,%0\n"
                "1:\n"
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "consolemap" "\n\t" ".text.lock." "consolemap" ":\n\t" ".endif\n"
                "2:\tlea %1,%%eax\n\t"
                "call __down_failed_trylock\n\t"
                "jmp 1b\n"
                ".previous\n\t"
                :"=a" (result), "=m" (sem->count)
                :
                :"memory");
        return result;
}
static inline __attribute__((always_inline)) void up(struct semaphore * sem)
{
        __asm__ __volatile__(
                "# atomic up operation\n\t"
                "lock ; " "incl %0\n\t"
                "jle 2f\n"
                "1:\n"
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "consolemap" "\n\t" ".text.lock." "consolemap" ":\n\t" ".endif\n"
                "2:\tlea %0,%%eax\n\t"
                "call __up_wakeup\n\t"
                "jmp 1b\n"
                ".previous\n\t"
                ".subsection 0\n"
                :"=m" (sem->count)
                :
                :"memory","ax");
}
struct pt_regs {
        long ebx;
        long ecx;
        long edx;
        long esi;
        long edi;
        long ebp;
        long eax;
        int xds;
        int xes;
        long orig_eax;
        long eip;
        int xcs;
        long eflags;
        long esp;
        int xss;
};
struct task_struct;
extern void send_sigtrap(struct task_struct *tsk, struct pt_regs *regs, int error_code);
static inline __attribute__((always_inline)) int user_mode(struct pt_regs *regs)
{
        return (regs->xcs & 3) != 0;
}
static inline __attribute__((always_inline)) int user_mode_vm(struct pt_regs *regs)
{
        return ((regs->xcs & 3) | (regs->eflags & 0x00020000)) != 0;
}
typedef struct {
        int size;
        struct semaphore sem;
        void *ldt;
} mm_context_t;
typedef unsigned long cputime_t;
typedef u64 cputime64_t;
extern void cpu_idle(void);
static inline __attribute__((always_inline)) int
__acpi_acquire_global_lock (unsigned int *lock)
{
        unsigned int old, new, val;
        do {
                old = *lock;
                new = (((old & ~0x3) + 2) + ((old >> 1) & 0x1));
                val = ((__typeof__(*(lock)))__cmpxchg((lock),(unsigned long)(old), (unsigned long)(new),sizeof(*(lock))));
        } while (__builtin_expect(!!(val != old), 0));
        return (new < 3) ? -1 : 0;
}
static inline __attribute__((always_inline)) int
__acpi_release_global_lock (unsigned int *lock)
{
        unsigned int old, new, val;
        do {
                old = *lock;
                new = old & ~0x3;
                val = ((__typeof__(*(lock)))__cmpxchg((lock),(unsigned long)(old), (unsigned long)(new),sizeof(*(lock))));
        } while (__builtin_expect(!!(val != old), 0));
        return old & 0x1;
}
static inline __attribute__((always_inline)) void acpi_noirq_set(void) { }
static inline __attribute__((always_inline)) void acpi_disable_pci(void) { }
extern u8 x86_acpiid_to_apicid[];
struct local_apic {
        struct { unsigned int __reserved[4]; } __reserved_01;
        struct { unsigned int __reserved[4]; } __reserved_02;
        struct {
                unsigned int __reserved_1 : 24,
                        phys_apic_id : 4,
                        __reserved_2 : 4;
                unsigned int __reserved[3];
        } id;
        const
        struct {
                unsigned int version : 8,
                        __reserved_1 : 8,
                        max_lvt : 8,
                        __reserved_2 : 8;
                unsigned int __reserved[3];
        } version;
        struct { unsigned int __reserved[4]; } __reserved_03;
        struct { unsigned int __reserved[4]; } __reserved_04;
        struct { unsigned int __reserved[4]; } __reserved_05;
        struct { unsigned int __reserved[4]; } __reserved_06;
        struct {
                unsigned int priority : 8,
                        __reserved_1 : 24;
                unsigned int __reserved_2[3];
        } tpr;
        const
        struct {
                unsigned int priority : 8,
                        __reserved_1 : 24;
                unsigned int __reserved_2[3];
        } apr;
        const
        struct {
                unsigned int priority : 8,
                        __reserved_1 : 24;
                unsigned int __reserved_2[3];
        } ppr;
        struct {
                unsigned int eoi;
                unsigned int __reserved[3];
        } eoi;
        struct { unsigned int __reserved[4]; } __reserved_07;
        struct {
                unsigned int __reserved_1 : 24,
                        logical_dest : 8;
                unsigned int __reserved_2[3];
        } ldr;
        struct {
                unsigned int __reserved_1 : 28,
                        model : 4;
                unsigned int __reserved_2[3];
        } dfr;
        struct {
                unsigned int spurious_vector : 8,
                        apic_enabled : 1,
                        focus_cpu : 1,
                        __reserved_2 : 22;
                unsigned int __reserved_3[3];
        } svr;
        struct {
                unsigned int bitfield;
                unsigned int __reserved[3];
        } isr [8];
        struct {
                unsigned int bitfield;
                unsigned int __reserved[3];
        } tmr [8];
        struct {
                unsigned int bitfield;
                unsigned int __reserved[3];
        } irr [8];
        union {
                struct {
                        unsigned int send_cs_error : 1,
                                receive_cs_error : 1,
                                send_accept_error : 1,
                                receive_accept_error : 1,
                                __reserved_1 : 1,
                                send_illegal_vector : 1,
                                receive_illegal_vector : 1,
                                illegal_register_address : 1,
                                __reserved_2 : 24;
                        unsigned int __reserved_3[3];
                } error_bits;
                struct {
                        unsigned int errors;
                        unsigned int __reserved_3[3];
                } all_errors;
        } esr;
        struct { unsigned int __reserved[4]; } __reserved_08;
        struct { unsigned int __reserved[4]; } __reserved_09;
        struct { unsigned int __reserved[4]; } __reserved_10;
        struct { unsigned int __reserved[4]; } __reserved_11;
        struct { unsigned int __reserved[4]; } __reserved_12;
        struct { unsigned int __reserved[4]; } __reserved_13;
        struct { unsigned int __reserved[4]; } __reserved_14;
        struct {
                unsigned int vector : 8,
                        delivery_mode : 3,
                        destination_mode : 1,
                        delivery_status : 1,
                        __reserved_1 : 1,
                        level : 1,
                        trigger : 1,
                        __reserved_2 : 2,
                        shorthand : 2,
                        __reserved_3 : 12;
                unsigned int __reserved_4[3];
        } icr1;
        struct {
                union {
                        unsigned int __reserved_1 : 24,
                                phys_dest : 4,
                                __reserved_2 : 4;
                        unsigned int __reserved_3 : 24,
                                logical_dest : 8;
                } dest;
                unsigned int __reserved_4[3];
        } icr2;
        struct {
                unsigned int vector : 8,
                        __reserved_1 : 4,
                        delivery_status : 1,
                        __reserved_2 : 3,
                        mask : 1,
                        timer_mode : 1,
                        __reserved_3 : 14;
                unsigned int __reserved_4[3];
        } lvt_timer;
        struct {
                unsigned int vector : 8,
                        delivery_mode : 3,
                        __reserved_1 : 1,
                        delivery_status : 1,
                        __reserved_2 : 3,
                        mask : 1,
                        __reserved_3 : 15;
                unsigned int __reserved_4[3];
        } lvt_thermal;
        struct {
                unsigned int vector : 8,
                        delivery_mode : 3,
                        __reserved_1 : 1,
                        delivery_status : 1,
                        __reserved_2 : 3,
                        mask : 1,
                        __reserved_3 : 15;
                unsigned int __reserved_4[3];
        } lvt_pc;
        struct {
                unsigned int vector : 8,
                        delivery_mode : 3,
                        __reserved_1 : 1,
                        delivery_status : 1,
                        polarity : 1,
                        remote_irr : 1,
                        trigger : 1,
                        mask : 1,
                        __reserved_2 : 15;
                unsigned int __reserved_3[3];
        } lvt_lint0;
        struct {
                unsigned int vector : 8,
                        delivery_mode : 3,
                        __reserved_1 : 1,
                        delivery_status : 1,
                        polarity : 1,
                        remote_irr : 1,
                        trigger : 1,
                        mask : 1,
                        __reserved_2 : 15;
                unsigned int __reserved_3[3];
        } lvt_lint1;
        struct {
                unsigned int vector : 8,
                        __reserved_1 : 4,
                        delivery_status : 1,
                        __reserved_2 : 3,
                        mask : 1,
                        __reserved_3 : 15;
                unsigned int __reserved_4[3];
        } lvt_error;
        struct {
                unsigned int initial_count;
                unsigned int __reserved_2[3];
        } timer_icr;
        const
        struct {
                unsigned int curr_count;
                unsigned int __reserved_2[3];
        } timer_ccr;
        struct { unsigned int __reserved[4]; } __reserved_16;
        struct { unsigned int __reserved[4]; } __reserved_17;
        struct { unsigned int __reserved[4]; } __reserved_18;
        struct { unsigned int __reserved[4]; } __reserved_19;
        struct {
                unsigned int divisor : 4,
                        __reserved_1 : 28;
                unsigned int __reserved_2[3];
        } timer_dcr;
        struct { unsigned int __reserved[4]; } __reserved_20;
} __attribute__ ((packed));
enum km_type {
__KM_FENCE_0 , KM_BOUNCE_READ,
__KM_FENCE_1 , KM_SKB_SUNRPC_DATA,
__KM_FENCE_2 , KM_SKB_DATA_SOFTIRQ,
__KM_FENCE_3 , KM_USER0,
__KM_FENCE_4 , KM_USER1,
__KM_FENCE_5 , KM_BIO_SRC_IRQ,
__KM_FENCE_6 , KM_BIO_DST_IRQ,
__KM_FENCE_7 , KM_PTE0,
__KM_FENCE_8 , KM_PTE1,
__KM_FENCE_9 , KM_IRQ0,
__KM_FENCE_10 , KM_IRQ1,
__KM_FENCE_11 , KM_SOFTIRQ0,
__KM_FENCE_12 , KM_SOFTIRQ1,
__KM_FENCE_13 , KM_TYPE_NR
};
enum fixed_addresses {
        FIX_HOLE,
        FIX_VSYSCALL,
        FIX_APIC_BASE,
        FIX_IO_APIC_BASE_0,
        FIX_IO_APIC_BASE_END = FIX_IO_APIC_BASE_0 + 64 -1,
        FIX_F00F_IDT,
        FIX_KMAP_BEGIN,
        FIX_KMAP_END = FIX_KMAP_BEGIN+(KM_TYPE_NR*8)-1,
        __end_of_permanent_fixed_addresses,
        FIX_BTMAP_END = __end_of_permanent_fixed_addresses,
        FIX_BTMAP_BEGIN = FIX_BTMAP_END + 16 - 1,
        FIX_WP_TEST,
        __end_of_fixed_addresses
};
extern void __set_fixmap (enum fixed_addresses idx,
                                        unsigned long phys, pgprot_t flags);
extern void __this_fixmap_does_not_exist(void);
static inline __attribute__((always_inline)) unsigned long fix_to_virt(const unsigned int idx)
{
        if (idx >= __end_of_fixed_addresses)
                __this_fixmap_does_not_exist();
        return (((unsigned long)0xfffff000) - ((idx) << 12));
}
static inline __attribute__((always_inline)) unsigned long virt_to_fix(const unsigned long vaddr)
{
        do { if (__builtin_expect(!!((vaddr >= ((unsigned long)0xfffff000) || vaddr < (((unsigned long)0xfffff000) - (__end_of_permanent_fixed_addresses << 12)))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (153), "i" ("include/asm/fixmap.h")); } while(0);
        return ((((unsigned long)0xfffff000) - ((vaddr)&(~((1UL << 12)-1)))) >> 12);
}
struct intel_mp_floating
{
        char mpf_signature[4];
        unsigned long mpf_physptr;
        unsigned char mpf_length;
        unsigned char mpf_specification;
        unsigned char mpf_checksum;
        unsigned char mpf_feature1;
        unsigned char mpf_feature2;
        unsigned char mpf_feature3;
        unsigned char mpf_feature4;
        unsigned char mpf_feature5;
};
struct mp_config_table
{
        char mpc_signature[4];
        unsigned short mpc_length;
        char mpc_spec;
        char mpc_checksum;
        char mpc_oem[8];
        char mpc_productid[12];
        unsigned long mpc_oemptr;
        unsigned short mpc_oemsize;
        unsigned short mpc_oemcount;
        unsigned long mpc_lapic;
        unsigned long reserved;
};
struct mpc_config_processor
{
        unsigned char mpc_type;
        unsigned char mpc_apicid;
        unsigned char mpc_apicver;
        unsigned char mpc_cpuflag;
        unsigned long mpc_cpufeature;
        unsigned long mpc_featureflag;
        unsigned long mpc_reserved[2];
};
struct mpc_config_bus
{
        unsigned char mpc_type;
        unsigned char mpc_busid;
        unsigned char mpc_bustype[6] __attribute((packed));
};
struct mpc_config_ioapic
{
        unsigned char mpc_type;
        unsigned char mpc_apicid;
        unsigned char mpc_apicver;
        unsigned char mpc_flags;
        unsigned long mpc_apicaddr;
};
struct mpc_config_intsrc
{
        unsigned char mpc_type;
        unsigned char mpc_irqtype;
        unsigned short mpc_irqflag;
        unsigned char mpc_srcbus;
        unsigned char mpc_srcbusirq;
        unsigned char mpc_dstapic;
        unsigned char mpc_dstirq;
};
enum mp_irq_source_types {
        mp_INT = 0,
        mp_NMI = 1,
        mp_SMI = 2,
        mp_ExtINT = 3
};
struct mpc_config_lintsrc
{
        unsigned char mpc_type;
        unsigned char mpc_irqtype;
        unsigned short mpc_irqflag;
        unsigned char mpc_srcbusid;
        unsigned char mpc_srcbusirq;
        unsigned char mpc_destapic;
        unsigned char mpc_destapiclint;
};
struct mp_config_oemtable
{
        char oem_signature[4];
        unsigned short oem_length;
        char oem_rev;
        char oem_checksum;
        char mpc_oem[8];
};
struct mpc_config_translation
{
        unsigned char mpc_type;
        unsigned char trans_len;
        unsigned char trans_type;
        unsigned char trans_quad;
        unsigned char trans_global;
        unsigned char trans_local;
        unsigned short trans_reserved;
};
enum mp_bustype {
        MP_BUS_ISA = 1,
        MP_BUS_EISA,
        MP_BUS_PCI,
        MP_BUS_MCA,
        MP_BUS_NEC98
};
extern int mp_bus_id_to_type [260];
extern int mp_bus_id_to_node [260];
extern int mp_bus_id_to_local [260];
extern int quad_local_to_mp_bus_id [8/4][4];
extern int mp_bus_id_to_pci_bus [260];
extern unsigned int def_to_bigsmp;
extern unsigned int boot_cpu_physical_apicid;
extern int smp_found_config;
extern void find_smp_config (void);
extern void get_smp_config (void);
extern int nr_ioapics;
extern int apic_version [256];
extern int mp_bus_id_to_type [260];
extern int mp_irq_entries;
extern struct mpc_config_intsrc mp_irqs [256];
extern int mpc_default_type;
extern int mp_bus_id_to_pci_bus [260];
extern unsigned long mp_lapic_addr;
extern int pic_mode;
extern int using_apic_timer;
struct physid_mask
{
        unsigned long mask[(((256)+32 -1)/32)];
};
typedef struct physid_mask physid_mask_t;
extern physid_mask_t phys_cpu_present_map;
static inline __attribute__((always_inline)) int use_pci_vector(void) {return 0;}
static inline __attribute__((always_inline)) void disable_edge_ioapic_irq(unsigned int irq) { }
static inline __attribute__((always_inline)) void mask_and_ack_level_ioapic_irq(unsigned int irq) { }
static inline __attribute__((always_inline)) void end_edge_ioapic_irq (unsigned int irq) { }
union IO_APIC_reg_00 {
        u32 raw;
        struct {
                u32 __reserved_2 : 14,
                        LTS : 1,
                        delivery_type : 1,
                        __reserved_1 : 8,
                        ID : 8;
        } __attribute__ ((packed)) bits;
};
union IO_APIC_reg_01 {
        u32 raw;
        struct {
                u32 version : 8,
                        __reserved_2 : 7,
                        PRQ : 1,
                        entries : 8,
                        __reserved_1 : 8;
        } __attribute__ ((packed)) bits;
};
union IO_APIC_reg_02 {
        u32 raw;
        struct {
                u32 __reserved_2 : 24,
                        arbitration : 4,
                        __reserved_1 : 4;
        } __attribute__ ((packed)) bits;
};
union IO_APIC_reg_03 {
        u32 raw;
        struct {
                u32 boot_DT : 1,
                        __reserved_1 : 31;
        } __attribute__ ((packed)) bits;
};
extern int nr_ioapics;
extern int nr_ioapic_registers[64];
enum ioapic_irq_destination_types {
        dest_Fixed = 0,
        dest_LowestPrio = 1,
        dest_SMI = 2,
        dest__reserved_1 = 3,
        dest_NMI = 4,
        dest_INIT = 5,
        dest__reserved_2 = 6,
        dest_ExtINT = 7
};
struct IO_APIC_route_entry {
        __u32 vector : 8,
                delivery_mode : 3,
                dest_mode : 1,
                delivery_status : 1,
                polarity : 1,
                irr : 1,
                trigger : 1,
                mask : 1,
                __reserved_2 : 15;
        union { struct { __u32
                                        __reserved_1 : 24,
                                        physical_dest : 4,
                                        __reserved_2 : 4;
                        } physical;
                        struct { __u32
                                        __reserved_1 : 24,
                                        logical_dest : 8;
                        } logical;
        } dest;
} __attribute__ ((packed));
extern struct mpc_config_ioapic mp_ioapics[64];
extern int mp_irq_entries;
extern struct mpc_config_intsrc mp_irqs[256];
extern int mpc_default_type;
static inline __attribute__((always_inline)) unsigned int io_apic_read(unsigned int apic, unsigned int reg)
{
        *((volatile int *)((((unsigned long)0xfffff000) - ((FIX_IO_APIC_BASE_0 + apic) << 12)) + (mp_ioapics[apic].mpc_apicaddr & ~(~((1UL << 12)-1))))) = reg;
        return *(((volatile int *)((((unsigned long)0xfffff000) - ((FIX_IO_APIC_BASE_0 + apic) << 12)) + (mp_ioapics[apic].mpc_apicaddr & ~(~((1UL << 12)-1)))))+4);
}
static inline __attribute__((always_inline)) void io_apic_write(unsigned int apic, unsigned int reg, unsigned int value)
{
        *((volatile int *)((((unsigned long)0xfffff000) - ((FIX_IO_APIC_BASE_0 + apic) << 12)) + (mp_ioapics[apic].mpc_apicaddr & ~(~((1UL << 12)-1))))) = reg;
        *(((volatile int *)((((unsigned long)0xfffff000) - ((FIX_IO_APIC_BASE_0 + apic) << 12)) + (mp_ioapics[apic].mpc_apicaddr & ~(~((1UL << 12)-1)))))+4) = value;
}
extern int sis_apic_bug;
static inline __attribute__((always_inline)) void io_apic_modify(unsigned int apic, unsigned int reg, unsigned int value)
{
        if (sis_apic_bug)
                *((volatile int *)((((unsigned long)0xfffff000) - ((FIX_IO_APIC_BASE_0 + apic) << 12)) + (mp_ioapics[apic].mpc_apicaddr & ~(~((1UL << 12)-1))))) = reg;
        *(((volatile int *)((((unsigned long)0xfffff000) - ((FIX_IO_APIC_BASE_0 + apic) << 12)) + (mp_ioapics[apic].mpc_apicaddr & ~(~((1UL << 12)-1)))))+4) = value;
}
extern int skip_ioapic_setup;
extern int (*ioapic_renumber_irq)(int ioapic, int irq);
extern int assign_irq_vector(int irq);
typedef int pm_request_t;
typedef int pm_dev_t;
enum
{
        PM_SYS_UNKNOWN = 0x00000000,
        PM_SYS_KBC = 0x41d00303,
        PM_SYS_COM = 0x41d00500,
        PM_SYS_IRDA = 0x41d00510,
        PM_SYS_FDC = 0x41d00700,
        PM_SYS_VGA = 0x41d00900,
        PM_SYS_PCMCIA = 0x41d00e00,
};
struct pm_dev;
typedef int (*pm_callback)(struct pm_dev *dev, pm_request_t rqst, void *data);
struct pm_dev
{
        pm_dev_t type;
        unsigned long id;
        pm_callback callback;
        void *data;
        unsigned long flags;
        unsigned long state;
        unsigned long prev_state;
        struct list_head entry;
};
extern int pm_active;
struct pm_dev __attribute__((deprecated)) *
pm_register(pm_dev_t type, unsigned long id, pm_callback callback);
void __attribute__((deprecated)) pm_unregister(struct pm_dev *dev);
void __attribute__((deprecated)) pm_unregister_all(pm_callback callback);
int __attribute__((deprecated)) pm_send_all(pm_request_t rqst, void *data);
extern void (*pm_idle)(void);
extern void (*pm_power_off)(void);
typedef int suspend_state_t;
typedef int suspend_disk_method_t;
struct pm_ops {
        suspend_disk_method_t pm_disk_mode;
        int (*prepare)(suspend_state_t state);
        int (*enter)(suspend_state_t state);
        int (*finish)(suspend_state_t state);
};
extern void pm_set_ops(struct pm_ops *);
extern struct pm_ops *pm_ops;
extern int pm_suspend(suspend_state_t state);
struct device;
typedef struct pm_message {
        int event;
} pm_message_t;
struct dev_pm_info {
        pm_message_t power_state;
        pm_message_t prev_state;
        void * saved_state;
        atomic_t pm_users;
        struct device * pm_parent;
        struct list_head entry;
};
extern void device_pm_set_parent(struct device * dev, struct device * parent);
extern int device_power_down(pm_message_t state);
extern void device_power_up(void);
extern void device_resume(void);
extern int device_suspend(pm_message_t state);
extern int enable_local_apic;
extern int apic_verbosity;
static inline __attribute__((always_inline)) void lapic_disable(void)
{
        enable_local_apic = -1;
        clear_bit((0*32+ 9), boot_cpu_data.x86_capability);
}
static inline __attribute__((always_inline)) void lapic_enable(void)
{
        enable_local_apic = 1;
}
static __inline __attribute__((always_inline)) void apic_write(unsigned long reg, unsigned long v)
{
        *((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg)) = v;
}
static __inline __attribute__((always_inline)) void apic_write_atomic(unsigned long reg, unsigned long v)
{
        ((__typeof__(*((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg))))__xchg((unsigned long)(v),((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg)),sizeof(*((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg)))));
}
static __inline __attribute__((always_inline)) unsigned long apic_read(unsigned long reg)
{
        return *((volatile unsigned long *)((fix_to_virt(FIX_APIC_BASE))+reg));
}
static __inline__ __attribute__((always_inline)) void apic_wait_icr_idle(void)
{
        while ( apic_read( 0x300 ) & 0x01000 )
                rep_nop();
}
int get_physical_broadcast(void);
static inline __attribute__((always_inline)) void ack_APIC_irq(void)
{
        apic_write_atomic((0xB0),(0));
}
extern void (*wait_timer_tick)(void);
extern int get_maxlvt(void);
extern void clear_local_APIC(void);
extern void connect_bsp_APIC (void);
extern void disconnect_bsp_APIC (int virt_wire_setup);
extern void disable_local_APIC (void);
extern void lapic_shutdown (void);
extern int verify_local_APIC (void);
extern void cache_APIC_registers (void);
extern void sync_Arb_IDs (void);
extern void init_bsp_APIC (void);
extern void setup_local_APIC (void);
extern void init_apic_mappings (void);
extern void smp_local_timer_interrupt (struct pt_regs * regs);
extern void setup_boot_APIC_clock (void);
extern void setup_secondary_APIC_clock (void);
extern void setup_apic_nmi_watchdog (void);
extern int reserve_lapic_nmi(void);
extern void release_lapic_nmi(void);
extern void disable_timer_nmi_watchdog(void);
extern void enable_timer_nmi_watchdog(void);
extern void nmi_watchdog_tick (struct pt_regs * regs);
extern int APIC_init_uniprocessor (void);
extern void disable_APIC_timer(void);
extern void enable_APIC_timer(void);
extern void enable_NMI_through_LVT0 (void * dummy);
extern unsigned int nmi_watchdog;
extern int disable_timer_pin_1;
extern void smp_alloc_memory(void);
extern int pic_mode;
extern int smp_num_siblings;
extern cpumask_t cpu_sibling_map[];
extern cpumask_t cpu_core_map[];
extern void (*mtrr_hook) (void);
extern void zap_low_mappings (void);
extern void lock_ipi_call_lock(void);
extern void unlock_ipi_call_lock(void);
extern u8 x86_cpu_to_apicid[];
extern cpumask_t cpu_callout_map;
extern cpumask_t cpu_callin_map;
extern cpumask_t cpu_possible_map;
static inline __attribute__((always_inline)) int num_booting_cpus(void)
{
        return __cpus_weight(&(cpu_callout_map), 8);
}
static inline __attribute__((always_inline)) unsigned get_apic_id(unsigned long x)
{
        return (((x)>>24)&0xFF);
}
static inline __attribute__((always_inline)) int hard_smp_processor_id(void)
{
        return get_apic_id(*(unsigned long *)((fix_to_virt(FIX_APIC_BASE))+0x20));
}
static __inline __attribute__((always_inline)) int logical_smp_processor_id(void)
{
        return (((*(unsigned long *)((fix_to_virt(FIX_APIC_BASE))+0xD0))>>24)&0xFF);
}
extern int __cpu_disable(void);
extern void __cpu_die(unsigned int cpu);
extern void smp_send_stop(void);
extern void smp_send_reschedule(int cpu);
extern void smp_prepare_cpus(unsigned int max_cpus);
extern int __cpu_up(unsigned int cpunum);
extern void smp_cpus_done(unsigned int max_cpus);
extern int smp_call_function (void (*func) (void *info), void *info,
                              int retry, int wait);
static inline __attribute__((always_inline)) int on_each_cpu(void (*func) (void *info), void *info,
                              int retry, int wait)
{
        int ret = 0;
        do { } while (0);
        ret = smp_call_function(func, info, retry, wait);
        func(info);
        do { } while (0);
        return ret;
}
void smp_prepare_boot_cpu(void);
struct ipc_perm
{
        __kernel_key_t key;
        __kernel_uid_t uid;
        __kernel_gid_t gid;
        __kernel_uid_t cuid;
        __kernel_gid_t cgid;
        __kernel_mode_t mode;
        unsigned short seq;
};
struct ipc64_perm
{
        __kernel_key_t key;
        __kernel_uid32_t uid;
        __kernel_gid32_t gid;
        __kernel_uid32_t cuid;
        __kernel_gid32_t cgid;
        __kernel_mode_t mode;
        unsigned short __pad1;
        unsigned short seq;
        unsigned short __pad2;
        unsigned long __unused1;
        unsigned long __unused2;
};
struct kern_ipc_perm
{
        spinlock_t lock;
        int deleted;
        key_t key;
        uid_t uid;
        gid_t gid;
        uid_t cuid;
        gid_t cgid;
        mode_t mode;
        unsigned long seq;
        void *security;
};
struct semid_ds {
        struct ipc_perm sem_perm;
        __kernel_time_t sem_otime;
        __kernel_time_t sem_ctime;
        struct sem *sem_base;
        struct sem_queue *sem_pending;
        struct sem_queue **sem_pending_last;
        struct sem_undo *undo;
        unsigned short sem_nsems;
};
struct semid64_ds {
        struct ipc64_perm sem_perm;
        __kernel_time_t sem_otime;
        unsigned long __unused1;
        __kernel_time_t sem_ctime;
        unsigned long __unused2;
        unsigned long sem_nsems;
        unsigned long __unused3;
        unsigned long __unused4;
};
struct sembuf {
        unsigned short sem_num;
        short sem_op;
        short sem_flg;
};
union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
        void *__pad;
};
struct seminfo {
        int semmap;
        int semmni;
        int semmns;
        int semmnu;
        int semmsl;
        int semopm;
        int semume;
        int semusz;
        int semvmx;
        int semaem;
};
struct sem {
        int semval;
        int sempid;
};
struct sem_array {
        struct kern_ipc_perm sem_perm;
        int sem_id;
        time_t sem_otime;
        time_t sem_ctime;
        struct sem *sem_base;
        struct sem_queue *sem_pending;
        struct sem_queue **sem_pending_last;
        struct sem_undo *undo;
        unsigned long sem_nsems;
};
struct sem_queue {
        struct sem_queue * next;
        struct sem_queue ** prev;
        struct task_struct* sleeper;
        struct sem_undo * undo;
        int pid;
        int status;
        struct sem_array * sma;
        int id;
        struct sembuf * sops;
        int nsops;
        int alter;
};
struct sem_undo {
        struct sem_undo * proc_next;
        struct sem_undo * id_next;
        int semid;
        short * semadj;
};
struct sem_undo_list {
        atomic_t refcnt;
        spinlock_t lock;
        struct sem_undo *proc_list;
};
struct sysv_sem {
        struct sem_undo_list *undo_list;
};
extern int copy_semundo(unsigned long clone_flags, struct task_struct *tsk);
extern void exit_sem(struct task_struct *tsk);
struct siginfo;
typedef unsigned long old_sigset_t;
typedef struct {
        unsigned long sig[(64 / 32)];
} sigset_t;
typedef void __signalfn_t(int);
typedef __signalfn_t *__sighandler_t;
typedef void __restorefn_t(void);
typedef __restorefn_t *__sigrestore_t;
struct old_sigaction {
        __sighandler_t sa_handler;
        old_sigset_t sa_mask;
        unsigned long sa_flags;
        __sigrestore_t sa_restorer;
};
struct sigaction {
        __sighandler_t sa_handler;
        unsigned long sa_flags;
        __sigrestore_t sa_restorer;
        sigset_t sa_mask;
};
struct k_sigaction {
        struct sigaction sa;
};
typedef struct sigaltstack {
        void *ss_sp;
        int ss_flags;
        size_t ss_size;
} stack_t;
static __inline__ __attribute__((always_inline)) void sigaddset(sigset_t *set, int _sig)
{
        __asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}
static __inline__ __attribute__((always_inline)) void sigdelset(sigset_t *set, int _sig)
{
        __asm__("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}
static __inline__ __attribute__((always_inline)) int __const_sigismember(sigset_t *set, int _sig)
{
        unsigned long sig = _sig - 1;
        return 1 & (set->sig[sig / 32] >> (sig % 32));
}
static __inline__ __attribute__((always_inline)) int __gen_sigismember(sigset_t *set, int _sig)
{
        int ret;
        __asm__("btl %2,%1\n\tsbbl %0,%0"
                : "=r"(ret) : "m"(*set), "Ir"(_sig-1) : "cc");
        return ret;
}
static __inline__ __attribute__((always_inline)) int sigfindinword(unsigned long word)
{
        __asm__("bsfl %1,%0" : "=r"(word) : "rm"(word) : "cc");
        return word;
}
struct pt_regs;
extern int do_signal(struct pt_regs *regs, sigset_t *oldset) __attribute__((regparm(3)));
typedef union sigval {
        int sival_int;
        void *sival_ptr;
} sigval_t;
typedef struct siginfo {
        int si_signo;
        int si_errno;
        int si_code;
        union {
                int _pad[((128 - (3 * sizeof(int))) / sizeof(int))];
                struct {
                        pid_t _pid;
                        uid_t _uid;
                } _kill;
                struct {
                        timer_t _tid;
                        int _overrun;
                        char _pad[sizeof( uid_t) - sizeof(int)];
                        sigval_t _sigval;
                        int _sys_private;
                } _timer;
                struct {
                        pid_t _pid;
                        uid_t _uid;
                        sigval_t _sigval;
                } _rt;
                struct {
                        pid_t _pid;
                        uid_t _uid;
                        int _status;
                        clock_t _utime;
                        clock_t _stime;
                } _sigchld;
                struct {
                        void *_addr;
                } _sigfault;
                struct {
                        long _band;
                        int _fd;
                } _sigpoll;
        } _sifields;
} siginfo_t;
typedef struct sigevent {
        sigval_t sigev_value;
        int sigev_signo;
        int sigev_notify;
        union {
                int _pad[((64 - (sizeof(int) * 2 + sizeof(sigval_t))) / sizeof(int))];
                 int _tid;
                struct {
                        void (*_function)(sigval_t);
                        void *_attribute;
                } _sigev_thread;
        } _sigev_un;
} sigevent_t;
struct siginfo;
void do_schedule_next_timer(struct siginfo *info);
static inline __attribute__((always_inline)) void copy_siginfo(struct siginfo *to, struct siginfo *from)
{
        if (from->si_code < 0)
                (__builtin_constant_p(sizeof(*to)) ? __constant_memcpy((to),(from),(sizeof(*to))) : __memcpy((to),(from),(sizeof(*to))));
        else
                (__builtin_constant_p((3 * sizeof(int)) + sizeof(from->_sifields._sigchld)) ? __constant_memcpy((to),(from),((3 * sizeof(int)) + sizeof(from->_sifields._sigchld))) : __memcpy((to),(from),((3 * sizeof(int)) + sizeof(from->_sifields._sigchld))));
}
extern int copy_siginfo_to_user(struct siginfo *to, struct siginfo *from);
struct sigqueue {
        struct list_head list;
        spinlock_t *lock;
        int flags;
        siginfo_t info;
        struct user_struct *user;
};
struct sigpending {
        struct list_head list;
        sigset_t signal;
};
static inline __attribute__((always_inline)) void sigorsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) | (b3)); r->sig[2] = ((a2) | (b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) | (b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) | (b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }
static inline __attribute__((always_inline)) void sigandsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) & (b3)); r->sig[2] = ((a2) & (b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) & (b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) & (b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }
static inline __attribute__((always_inline)) void signandsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) & ~(b3)); r->sig[2] = ((a2) & ~(b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) & ~(b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) & ~(b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }
static inline __attribute__((always_inline)) void signotset(sigset_t *set) { extern void _NSIG_WORDS_is_unsupported_size(void); switch ((64 / 32)) { case 4: set->sig[3] = (~(set->sig[3])); set->sig[2] = (~(set->sig[2])); case 2: set->sig[1] = (~(set->sig[1])); case 1: set->sig[0] = (~(set->sig[0])); break; default: _NSIG_WORDS_is_unsupported_size(); } }
static inline __attribute__((always_inline)) void sigemptyset(sigset_t *set)
{
        switch ((64 / 32)) {
        default:
                (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(sigset_t))) ? __constant_c_and_count_memset(((set)),((0x01010101UL*(unsigned char)(0))),((sizeof(sigset_t)))) : __constant_c_memset(((set)),((0x01010101UL*(unsigned char)(0))),((sizeof(sigset_t))))) : (__builtin_constant_p((sizeof(sigset_t))) ? __memset_generic((((set))),(((0))),(((sizeof(sigset_t))))) : __memset_generic(((set)),((0)),((sizeof(sigset_t))))));
                break;
        case 2: set->sig[1] = 0;
        case 1: set->sig[0] = 0;
                break;
        }
}
static inline __attribute__((always_inline)) void sigfillset(sigset_t *set)
{
        switch ((64 / 32)) {
        default:
                (__builtin_constant_p(-1) ? (__builtin_constant_p((sizeof(sigset_t))) ? __constant_c_and_count_memset(((set)),((0x01010101UL*(unsigned char)(-1))),((sizeof(sigset_t)))) : __constant_c_memset(((set)),((0x01010101UL*(unsigned char)(-1))),((sizeof(sigset_t))))) : (__builtin_constant_p((sizeof(sigset_t))) ? __memset_generic((((set))),(((-1))),(((sizeof(sigset_t))))) : __memset_generic(((set)),((-1)),((sizeof(sigset_t))))));
                break;
        case 2: set->sig[1] = -1;
        case 1: set->sig[0] = -1;
                break;
        }
}
static inline __attribute__((always_inline)) void sigaddsetmask(sigset_t *set, unsigned long mask)
{
        set->sig[0] |= mask;
}
static inline __attribute__((always_inline)) void sigdelsetmask(sigset_t *set, unsigned long mask)
{
        set->sig[0] &= ~mask;
}
static inline __attribute__((always_inline)) int sigtestsetmask(sigset_t *set, unsigned long mask)
{
        return (set->sig[0] & mask) != 0;
}
static inline __attribute__((always_inline)) void siginitset(sigset_t *set, unsigned long mask)
{
        set->sig[0] = mask;
        switch ((64 / 32)) {
        default:
                (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __constant_c_and_count_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(0))),((sizeof(long)*((64 / 32)-1)))) : __constant_c_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(0))),((sizeof(long)*((64 / 32)-1))))) : (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __memset_generic((((&set->sig[1]))),(((0))),(((sizeof(long)*((64 / 32)-1))))) : __memset_generic(((&set->sig[1])),((0)),((sizeof(long)*((64 / 32)-1))))));
                break;
        case 2: set->sig[1] = 0;
        case 1: ;
        }
}
static inline __attribute__((always_inline)) void siginitsetinv(sigset_t *set, unsigned long mask)
{
        set->sig[0] = ~mask;
        switch ((64 / 32)) {
        default:
                (__builtin_constant_p(-1) ? (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __constant_c_and_count_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(-1))),((sizeof(long)*((64 / 32)-1)))) : __constant_c_memset(((&set->sig[1])),((0x01010101UL*(unsigned char)(-1))),((sizeof(long)*((64 / 32)-1))))) : (__builtin_constant_p((sizeof(long)*((64 / 32)-1))) ? __memset_generic((((&set->sig[1]))),(((-1))),(((sizeof(long)*((64 / 32)-1))))) : __memset_generic(((&set->sig[1])),((-1)),((sizeof(long)*((64 / 32)-1))))));
                break;
        case 2: set->sig[1] = -1;
        case 1: ;
        }
}
static inline __attribute__((always_inline)) void init_sigpending(struct sigpending *sig)
{
        sigemptyset(&sig->signal);
        do { (&sig->list)->next = (&sig->list); (&sig->list)->prev = (&sig->list); } while (0);
}
static inline __attribute__((always_inline)) int valid_signal(unsigned long sig)
{
        return sig <= 64 ? 1 : 0;
}
extern int group_send_sig_info(int sig, struct siginfo *info, struct task_struct *p);
extern int __group_send_sig_info(int, struct siginfo *, struct task_struct *);
extern long do_sigpending(void *, unsigned long);
extern int sigprocmask(int, sigset_t *, sigset_t *);
struct pt_regs;
extern int get_signal_to_deliver(siginfo_t *info, struct k_sigaction *return_ka, struct pt_regs *regs, void *cookie);
extern unsigned securebits;
struct dentry;
struct vfsmount;
struct fs_struct {
        atomic_t count;
        rwlock_t lock;
        int umask;
        struct dentry * root, * pwd, * altroot;
        struct vfsmount * rootmnt, * pwdmnt, * altrootmnt;
};
extern void exit_fs(struct task_struct *);
extern void set_fs_altroot(void);
extern void set_fs_root(struct fs_struct *, struct vfsmount *, struct dentry *);
extern void set_fs_pwd(struct fs_struct *, struct vfsmount *, struct dentry *);
extern struct fs_struct *copy_fs_struct(struct fs_struct *);
extern void put_fs_struct(struct fs_struct *);
struct completion {
        unsigned int done;
        wait_queue_head_t wait;
};
static inline __attribute__((always_inline)) void init_completion(struct completion *x)
{
        x->done = 0;
        init_waitqueue_head(&x->wait);
}
extern void wait_for_completion(struct completion *) __attribute__((regparm(3)));
extern int wait_for_completion_interruptible(struct completion *x) __attribute__((regparm(3)));
extern unsigned long wait_for_completion_timeout(struct completion *x, unsigned long timeout) __attribute__((regparm(3)));
extern unsigned long wait_for_completion_interruptible_timeout( struct completion *x, unsigned long timeout) __attribute__((regparm(3)));
extern void complete(struct completion *) __attribute__((regparm(3)));
extern void complete_all(struct completion *) __attribute__((regparm(3)));
enum pid_type
{
        PIDTYPE_PID,
        PIDTYPE_TGID,
        PIDTYPE_PGID,
        PIDTYPE_SID,
        PIDTYPE_MAX
};
struct pid
{
        int nr;
        struct hlist_node pid_chain;
        struct list_head pid_list;
};
extern int attach_pid(struct task_struct *task, enum pid_type type, int nr) __attribute__((regparm(3)));
extern void detach_pid(struct task_struct *task, enum pid_type) __attribute__((regparm(3)));
extern struct pid *find_pid(enum pid_type, int) __attribute__((regparm(3)));
extern int alloc_pidmap(void);
extern void free_pidmap(int) __attribute__((regparm(3)));
extern void switch_exec_pids(struct task_struct *leader, struct task_struct *thread);
typedef struct kmem_cache_s kmem_cache_t;
typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);
extern initcall_t __con_initcall_start[], __con_initcall_end[];
extern initcall_t __security_initcall_start[], __security_initcall_end[];
extern char saved_command_line[];
struct obs_kernel_param {
        const char *str;
        int (*setup_func)(char *);
        int early;
};
void __attribute__ ((__section__ (".init.text"))) parse_early_param(void);
struct free_area {
        struct list_head free_list;
        unsigned long nr_free;
};
struct pglist_data;
struct zone_padding {
        char x[0];
} __attribute__((__aligned__(1 << (7))));
struct per_cpu_pages {
        int count;
        int low;
        int high;
        int batch;
        struct list_head list;
};
struct per_cpu_pageset {
        struct per_cpu_pages pcp[2];
} __attribute__((__aligned__((1 << (4)))));
struct zone {
        unsigned long free_pages;
        unsigned long pages_min, pages_low, pages_high;
        unsigned long lowmem_reserve[3];
        struct per_cpu_pageset pageset[8];
        spinlock_t lock;
        struct free_area free_area[11];
        struct zone_padding _pad1_;
        spinlock_t lru_lock;
        struct list_head active_list;
        struct list_head inactive_list;
        unsigned long nr_scan_active;
        unsigned long nr_scan_inactive;
        unsigned long nr_active;
        unsigned long nr_inactive;
        unsigned long pages_scanned;
        int all_unreclaimable;
        int reclaim_pages;
        atomic_t reclaim_in_progress;
        int temp_priority;
        int prev_priority;
        struct zone_padding _pad2_;
        wait_queue_head_t * wait_table;
        unsigned long wait_table_size;
        unsigned long wait_table_bits;
        struct pglist_data *zone_pgdat;
        struct page *zone_mem_map;
        unsigned long zone_start_pfn;
        unsigned long spanned_pages;
        unsigned long present_pages;
        char *name;
} __attribute__((__aligned__(1 << (7))));
struct zonelist {
        struct zone *zones[(1 << 0) * 3 + 1];
};
struct bootmem_data;
typedef struct pglist_data {
        struct zone node_zones[3];
        struct zonelist node_zonelists[((0x03 + 1) / 2 + 1)];
        int nr_zones;
        struct page *node_mem_map;
        struct bootmem_data *bdata;
        unsigned long node_start_pfn;
        unsigned long node_present_pages;
        unsigned long node_spanned_pages;
        int node_id;
        struct pglist_data *pgdat_next;
        wait_queue_head_t kswapd_wait;
        struct task_struct *kswapd;
        int kswapd_max_order;
} pg_data_t;
extern struct pglist_data *pgdat_list;
void __get_zone_counts(unsigned long *active, unsigned long *inactive,
                        unsigned long *free, struct pglist_data *pgdat);
void get_zone_counts(unsigned long *active, unsigned long *inactive,
                        unsigned long *free);
void build_all_zonelists(void);
void wakeup_kswapd(struct zone *zone, int order);
int zone_watermark_ok(struct zone *z, int order, unsigned long mark,
                int alloc_type, int can_try_harder, int gfp_high);
static inline __attribute__((always_inline)) void memory_present(int nid, unsigned long start, unsigned long end) {}
static inline __attribute__((always_inline)) struct zone *next_zone(struct zone *zone)
{
        pg_data_t *pgdat = zone->zone_pgdat;
        if (zone < pgdat->node_zones + 3 - 1)
                zone++;
        else if (pgdat->pgdat_next) {
                pgdat = pgdat->pgdat_next;
                zone = pgdat->node_zones;
        } else
                zone = ((void *)0);
        return zone;
}
static inline __attribute__((always_inline)) int is_highmem_idx(int idx)
{
        return (idx == 2);
}
static inline __attribute__((always_inline)) int is_normal_idx(int idx)
{
        return (idx == 1);
}
static inline __attribute__((always_inline)) int is_highmem(struct zone *zone)
{
        return zone == zone->zone_pgdat->node_zones + 2;
}
static inline __attribute__((always_inline)) int is_normal(struct zone *zone)
{
        return zone == zone->zone_pgdat->node_zones + 1;
}
struct ctl_table;
struct file;
int min_free_kbytes_sysctl_handler(struct ctl_table *, int, struct file *,
                                        void *, size_t *, loff_t *);
extern int sysctl_lowmem_reserve_ratio[3 -1];
int lowmem_reserve_ratio_sysctl_handler(struct ctl_table *, int, struct file *,
                                        void *, size_t *, loff_t *);
extern struct pglist_data contig_page_data;
void memory_present(int nid, unsigned long start, unsigned long end);
unsigned long __attribute__ ((__section__ (".init.text"))) node_memmap_size_bytes(int, unsigned long, unsigned long);
struct vm_area_struct;
static inline __attribute__((always_inline)) void arch_free_page(struct page *page, int order) { }
extern struct page *
__alloc_pages(gfp_t, unsigned int, struct zonelist *) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) struct page *alloc_pages_node(int nid, gfp_t gfp_mask,
                                                unsigned int order)
{
        if (__builtin_expect(!!(order >= 11), 0))
                return ((void *)0);
        return __alloc_pages(gfp_mask, order,
                (&contig_page_data)->node_zonelists + (gfp_mask & 0x03));
}
extern unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order) __attribute__((regparm(3)));
extern unsigned long get_zeroed_page(gfp_t gfp_mask) __attribute__((regparm(3)));
extern void __free_pages(struct page *page, unsigned int order) __attribute__((regparm(3)));
extern void free_pages(unsigned long addr, unsigned int order) __attribute__((regparm(3)));
extern void free_hot_page(struct page *page) __attribute__((regparm(3)));
extern void free_cold_page(struct page *page) __attribute__((regparm(3)));
void page_alloc_init(void);
static inline __attribute__((always_inline)) void drain_remote_pages(void) { };
extern void __attribute__ ((__section__ (".init.text"))) kmem_cache_init(void);
extern kmem_cache_t *kmem_cache_create(const char *, size_t, size_t, unsigned long,
                                       void (*)(void *, kmem_cache_t *, unsigned long),
                                       void (*)(void *, kmem_cache_t *, unsigned long));
extern int kmem_cache_destroy(kmem_cache_t *);
extern int kmem_cache_shrink(kmem_cache_t *);
extern void *kmem_cache_alloc(kmem_cache_t *, gfp_t);
extern void kmem_cache_free(kmem_cache_t *, void *);
extern unsigned int kmem_cache_size(kmem_cache_t *);
extern const char *kmem_cache_name(kmem_cache_t *);
extern kmem_cache_t *kmem_find_general_cachep(size_t size, gfp_t gfpflags);
struct cache_sizes {
        size_t cs_size;
        kmem_cache_t *cs_cachep;
        kmem_cache_t *cs_dmacachep;
};
extern struct cache_sizes malloc_sizes[];
extern void *__kmalloc(size_t, gfp_t);
static inline __attribute__((always_inline)) void *kmalloc(size_t size, gfp_t flags)
{
        if (__builtin_constant_p(size)) {
                int i = 0;
        if (size <= 32) goto found; else i++;
        if (size <= 64) goto found; else i++;
        if (size <= 96) goto found; else i++;
        if (size <= 128) goto found; else i++;
        if (size <= 192) goto found; else i++;
        if (size <= 256) goto found; else i++;
        if (size <= 512) goto found; else i++;
        if (size <= 1024) goto found; else i++;
        if (size <= 2048) goto found; else i++;
        if (size <= 4096) goto found; else i++;
        if (size <= 8192) goto found; else i++;
        if (size <= 16384) goto found; else i++;
        if (size <= 32768) goto found; else i++;
        if (size <= 65536) goto found; else i++;
        if (size <= 131072) goto found; else i++;
                {
                        extern void __you_cannot_kmalloc_that_much(void);
                        __you_cannot_kmalloc_that_much();
                }
found:
                return kmem_cache_alloc((flags & 0x01u) ?
                        malloc_sizes[i].cs_dmacachep :
                        malloc_sizes[i].cs_cachep, flags);
        }
        return __kmalloc(size, flags);
}
extern void *kzalloc(size_t, gfp_t);
static inline __attribute__((always_inline)) void *kcalloc(size_t n, size_t size, gfp_t flags)
{
        if (n != 0 && size > ((int)(~0U>>1)) / n)
                return ((void *)0);
        return kzalloc(n * size, flags);
}
extern void kfree(const void *);
extern unsigned int ksize(const void *);
static inline __attribute__((always_inline)) void *kmem_cache_alloc_node(kmem_cache_t *cachep, int flags, int node)
{
        return kmem_cache_alloc(cachep, flags);
}
static inline __attribute__((always_inline)) void *kmalloc_node(size_t size, gfp_t flags, int node)
{
        return kmalloc(size, flags);
}
extern int kmem_cache_reap(int) __attribute__((regparm(3)));
extern int kmem_ptr_validate(kmem_cache_t *cachep, void *ptr) __attribute__((regparm(3)));
extern kmem_cache_t *vm_area_cachep;
extern kmem_cache_t *names_cachep;
extern kmem_cache_t *files_cachep;
extern kmem_cache_t *filp_cachep;
extern kmem_cache_t *fs_cachep;
extern kmem_cache_t *signal_cachep;
extern kmem_cache_t *sighand_cachep;
extern kmem_cache_t *bio_cachep;
extern atomic_t slab_reclaim_pages;
struct percpu_data {
        void *ptrs[8];
        void *blkp;
};
extern void *__alloc_percpu(size_t size, size_t align);
extern void free_percpu(const void *);
extern int errno;
typedef struct { int mode; } seccomp_t;
extern void __secure_computing(int);
static inline __attribute__((always_inline)) void secure_computing(int this_syscall)
{
        if (__builtin_expect(!!(test_thread_flag(8)), 0))
                __secure_computing(this_syscall);
}
static inline __attribute__((always_inline)) int has_secure_computing(struct thread_info *ti)
{
        return __builtin_expect(!!(test_ti_thread_flag(ti, 8)), 0);
}
struct exec_domain;
extern unsigned long avenrun[];
extern unsigned long total_forks;
extern int nr_threads;
extern int last_pid;
extern __typeof__(unsigned long) per_cpu__process_counts;
extern int nr_processes(void);
extern unsigned long nr_running(void);
extern unsigned long nr_uninterruptible(void);
extern unsigned long nr_iowait(void);
struct rusage {
        struct timeval ru_utime;
        struct timeval ru_stime;
        long ru_maxrss;
        long ru_ixrss;
        long ru_idrss;
        long ru_isrss;
        long ru_minflt;
        long ru_majflt;
        long ru_nswap;
        long ru_inblock;
        long ru_oublock;
        long ru_msgsnd;
        long ru_msgrcv;
        long ru_nsignals;
        long ru_nvcsw;
        long ru_nivcsw;
};
struct rlimit {
        unsigned long rlim_cur;
        unsigned long rlim_max;
};
struct timer_base_s;
struct timer_list {
        struct list_head entry;
        unsigned long expires;
        unsigned long magic;
        void (*function)(unsigned long);
        unsigned long data;
        struct timer_base_s *base;
};
extern struct timer_base_s __init_timer_base;
void __attribute__((regparm(3))) init_timer(struct timer_list * timer);
static inline __attribute__((always_inline)) int timer_pending(const struct timer_list * timer)
{
        return timer->entry.next != ((void *)0);
}
extern void add_timer_on(struct timer_list *timer, int cpu);
extern int del_timer(struct timer_list * timer);
extern int __mod_timer(struct timer_list *timer, unsigned long expires);
extern int mod_timer(struct timer_list *timer, unsigned long expires);
extern unsigned long next_timer_interrupt(void);
static inline __attribute__((always_inline)) void add_timer(struct timer_list * timer)
{
        __mod_timer(timer, timer->expires);
}
  extern int try_to_del_timer_sync(struct timer_list *timer);
  extern int del_timer_sync(struct timer_list *timer);
extern void init_timers(void);
extern void run_local_timers(void);
extern void it_real_fn(unsigned long);
struct sched_param {
        int sched_priority;
};
extern rwlock_t tasklist_lock;
extern spinlock_t mmlist_lock;
typedef struct task_struct task_t;
extern void sched_init(void);
extern void sched_init_smp(void);
extern void init_idle(task_t *idle, int cpu);
extern cpumask_t nohz_cpu_mask;
extern void show_state(void);
extern void show_regs(struct pt_regs *);
extern void show_stack(struct task_struct *task, unsigned long *sp);
void io_schedule(void);
long io_schedule_timeout(long timeout);
extern void cpu_init (void);
extern void trap_init(void);
extern void update_process_times(int user);
extern void scheduler_tick(void);
extern void softlockup_tick(struct pt_regs *regs);
extern void spawn_softlockup_task(void);
extern void touch_softlockup_watchdog(void);
extern int in_sched_functions(unsigned long addr);
extern signed long schedule_timeout(signed long timeout) __attribute__((regparm(3)));
extern signed long schedule_timeout_interruptible(signed long timeout);
extern signed long schedule_timeout_uninterruptible(signed long timeout);
 __attribute__((regparm(0))) void schedule(void);
struct namespace;
extern int sysctl_max_map_count;
struct workqueue_struct;
struct work_struct {
        unsigned long pending;
        struct list_head entry;
        void (*func)(void *);
        void *data;
        void *wq_data;
        struct timer_list timer;
};
extern struct workqueue_struct *__create_workqueue(const char *name,
                                                    int singlethread);
extern void destroy_workqueue(struct workqueue_struct *wq);
extern int queue_work(struct workqueue_struct *wq, struct work_struct *work) __attribute__((regparm(3)));
extern int queue_delayed_work(struct workqueue_struct *wq, struct work_struct *work, unsigned long delay) __attribute__((regparm(3)));
extern void flush_workqueue(struct workqueue_struct *wq) __attribute__((regparm(3)));
extern int schedule_work(struct work_struct *work) __attribute__((regparm(3)));
extern int schedule_delayed_work(struct work_struct *work, unsigned long delay) __attribute__((regparm(3)));
extern int schedule_delayed_work_on(int cpu, struct work_struct *work, unsigned long delay);
extern void flush_scheduled_work(void);
extern int current_is_keventd(void);
extern int keventd_up(void);
extern void init_workqueues(void);
void cancel_rearming_delayed_work(struct work_struct *work);
void cancel_rearming_delayed_workqueue(struct workqueue_struct *,
                                       struct work_struct *);
static inline __attribute__((always_inline)) int cancel_delayed_work(struct work_struct *work)
{
        int ret;
        ret = del_timer_sync(&work->timer);
        if (ret)
                clear_bit(0, &work->pending);
        return ret;
}
typedef unsigned long aio_context_t;
enum {
        IOCB_CMD_PREAD = 0,
        IOCB_CMD_PWRITE = 1,
        IOCB_CMD_FSYNC = 2,
        IOCB_CMD_FDSYNC = 3,
        IOCB_CMD_NOOP = 6,
};
struct io_event {
        __u64 data;
        __u64 obj;
        __s64 res;
        __s64 res2;
};
struct iocb {
        __u64 aio_data;
        __u32 aio_key, aio_reserved1;
        __u16 aio_lio_opcode;
        __s16 aio_reqprio;
        __u32 aio_fildes;
        __u64 aio_buf;
        __u64 aio_nbytes;
        __s64 aio_offset;
        __u64 aio_reserved2;
        __u64 aio_reserved3;
};
struct kioctx;
struct kiocb {
        struct list_head ki_run_list;
        long ki_flags;
        int ki_users;
        unsigned ki_key;
        struct file *ki_filp;
        struct kioctx *ki_ctx;
        int (*ki_cancel)(struct kiocb *, struct io_event *);
        ssize_t (*ki_retry)(struct kiocb *);
        void (*ki_dtor)(struct kiocb *);
        struct list_head ki_list;
        union {
                void *user;
                struct task_struct *tsk;
        } ki_obj;
        __u64 ki_user_data;
        loff_t ki_pos;
        unsigned short ki_opcode;
        size_t ki_nbytes;
        char *ki_buf;
        size_t ki_left;
        wait_queue_t ki_wait;
        long ki_retried;
        long ki_kicked;
        long ki_queued;
        void *private;
};
struct aio_ring {
        unsigned id;
        unsigned nr;
        unsigned head;
        unsigned tail;
        unsigned magic;
        unsigned compat_features;
        unsigned incompat_features;
        unsigned header_length;
        struct io_event io_events[0];
};
struct aio_ring_info {
        unsigned long mmap_base;
        unsigned long mmap_size;
        struct page **ring_pages;
        spinlock_t ring_lock;
        long nr_pages;
        unsigned nr, tail;
        struct page *internal_pages[8];
};
struct kioctx {
        atomic_t users;
        int dead;
        struct mm_struct *mm;
        unsigned long user_id;
        struct kioctx *next;
        wait_queue_head_t wait;
        spinlock_t ctx_lock;
        int reqs_active;
        struct list_head active_reqs;
        struct list_head run_list;
        unsigned max_reqs;
        struct aio_ring_info ring_info;
        struct work_struct wq;
};
extern unsigned aio_max_size;
extern ssize_t wait_on_sync_kiocb(struct kiocb *iocb) __attribute__((regparm(3)));
extern int aio_put_req(struct kiocb *iocb) __attribute__((regparm(3)));
extern void kick_iocb(struct kiocb *iocb) __attribute__((regparm(3)));
extern int aio_complete(struct kiocb *iocb, long res, long res2) __attribute__((regparm(3)));
extern void __put_ioctx(struct kioctx *ctx) __attribute__((regparm(3)));
struct mm_struct;
extern void exit_aio(struct mm_struct *mm) __attribute__((regparm(3)));
extern struct kioctx *lookup_ioctx(unsigned long ctx_id);
extern int io_submit_one(struct kioctx *ctx, struct iocb *user_iocb, struct iocb *iocb) __attribute__((regparm(3)));
struct kioctx *lookup_ioctx(unsigned long ctx_id);
int io_submit_one(struct kioctx *ctx, struct iocb *user_iocb, struct iocb *iocb) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) struct kiocb *list_kiocb(struct list_head *h)
{
        return ({ const typeof( ((struct kiocb *)0)->ki_list ) *__mptr = (h); (struct kiocb *)( (char *)__mptr - ((size_t) &((struct kiocb *)0)->ki_list) );});
}
extern atomic_t aio_nr;
extern unsigned aio_max_nr;
extern unsigned long
arch_get_unmapped_area(struct file *, unsigned long, unsigned long,
                       unsigned long, unsigned long);
extern unsigned long
arch_get_unmapped_area_topdown(struct file *filp, unsigned long addr,
                          unsigned long len, unsigned long pgoff,
                          unsigned long flags);
extern void arch_unmap_area(struct mm_struct *, unsigned long);
extern void arch_unmap_area_topdown(struct mm_struct *, unsigned long);
typedef unsigned long mm_counter_t;
struct mm_struct {
        struct vm_area_struct * mmap;
        struct rb_root mm_rb;
        struct vm_area_struct * mmap_cache;
        unsigned long (*get_unmapped_area) (struct file *filp,
                                unsigned long addr, unsigned long len,
                                unsigned long pgoff, unsigned long flags);
        void (*unmap_area) (struct mm_struct *mm, unsigned long addr);
        unsigned long mmap_base;
        unsigned long cached_hole_size;
        unsigned long free_area_cache;
        pgd_t * pgd;
        atomic_t mm_users;
        atomic_t mm_count;
        int map_count;
        struct rw_semaphore mmap_sem;
        spinlock_t page_table_lock;
        struct list_head mmlist;
        unsigned long start_code, end_code, start_data, end_data;
        unsigned long start_brk, brk, start_stack;
        unsigned long arg_start, arg_end, env_start, env_end;
        unsigned long total_vm, locked_vm, shared_vm;
        unsigned long exec_vm, stack_vm, reserved_vm, def_flags, nr_ptes;
        mm_counter_t _rss;
        mm_counter_t _anon_rss;
        unsigned long saved_auxv[42];
        unsigned dumpable:2;
        cpumask_t cpu_vm_mask;
        mm_context_t context;
        unsigned long swap_token_time;
        char recent_pagein;
        int core_waiters;
        struct completion *core_startup_done, core_done;
        rwlock_t ioctx_list_lock;
        struct kioctx *ioctx_list;
        struct kioctx default_kioctx;
        unsigned long hiwater_rss;
        unsigned long hiwater_vm;
};
struct sighand_struct {
        atomic_t count;
        struct k_sigaction action[64];
        spinlock_t siglock;
};
struct signal_struct {
        atomic_t count;
        atomic_t live;
        wait_queue_head_t wait_chldexit;
        task_t *curr_target;
        struct sigpending shared_pending;
        int group_exit_code;
        struct task_struct *group_exit_task;
        int notify_count;
        int group_stop_count;
        unsigned int flags;
        struct list_head posix_timers;
        struct timer_list real_timer;
        unsigned long it_real_value, it_real_incr;
        cputime_t it_prof_expires, it_virt_expires;
        cputime_t it_prof_incr, it_virt_incr;
        pid_t pgrp;
        pid_t tty_old_pgrp;
        pid_t session;
        int leader;
        struct tty_struct *tty;
        cputime_t utime, stime, cutime, cstime;
        unsigned long nvcsw, nivcsw, cnvcsw, cnivcsw;
        unsigned long min_flt, maj_flt, cmin_flt, cmaj_flt;
        unsigned long long sched_time;
        struct rlimit rlim[15];
        struct list_head cpu_timers[3];
};
struct user_struct {
        atomic_t __count;
        atomic_t processes;
        atomic_t files;
        atomic_t sigpending;
        atomic_t inotify_watches;
        atomic_t inotify_devs;
        unsigned long mq_bytes;
        unsigned long locked_shm;
        struct list_head uidhash_list;
        uid_t uid;
};
extern struct user_struct *find_user(uid_t);
extern struct user_struct root_user;
typedef struct prio_array prio_array_t;
struct backing_dev_info;
struct reclaim_state;
enum idle_type
{
        SCHED_IDLE,
        NOT_IDLE,
        NEWLY_IDLE,
        MAX_IDLE_TYPES
};
struct sched_group {
        struct sched_group *next;
        cpumask_t cpumask;
        unsigned long cpu_power;
};
struct sched_domain {
        struct sched_domain *parent;
        struct sched_group *groups;
        cpumask_t span;
        unsigned long min_interval;
        unsigned long max_interval;
        unsigned int busy_factor;
        unsigned int imbalance_pct;
        unsigned long long cache_hot_time;
        unsigned int cache_nice_tries;
        unsigned int per_cpu_gain;
        unsigned int busy_idx;
        unsigned int idle_idx;
        unsigned int newidle_idx;
        unsigned int wake_idx;
        unsigned int forkexec_idx;
        int flags;
        unsigned long last_balance;
        unsigned int balance_interval;
        unsigned int nr_balance_failed;
};
extern void partition_sched_domains(cpumask_t *partition1,
                                    cpumask_t *partition2);
struct io_context;
void exit_io_context(void);
struct cpuset;
struct group_info {
        int ngroups;
        atomic_t usage;
        gid_t small_block[32];
        int nblocks;
        gid_t *blocks[0];
};
extern struct group_info *groups_alloc(int gidsetsize);
extern void groups_free(struct group_info *group_info);
extern int set_current_groups(struct group_info *group_info);
extern int groups_search(struct group_info *group_info, gid_t grp);
static inline __attribute__((always_inline)) void prefetch_stack(struct task_struct *t) { }
struct audit_context;
struct mempolicy;
struct task_struct {
        volatile long state;
        struct thread_info *thread_info;
        atomic_t usage;
        unsigned long flags;
        unsigned long ptrace;
        int lock_depth;
        int prio, static_prio;
        struct list_head run_list;
        prio_array_t *array;
        unsigned short ioprio;
        unsigned long sleep_avg;
        unsigned long long timestamp, last_ran;
        unsigned long long sched_time;
        int activated;
        unsigned long policy;
        cpumask_t cpus_allowed;
        unsigned int time_slice, first_time_slice;
        struct list_head tasks;
        struct list_head ptrace_children;
        struct list_head ptrace_list;
        struct mm_struct *mm, *active_mm;
        struct linux_binfmt *binfmt;
        long exit_state;
        int exit_code, exit_signal;
        int pdeath_signal;
        unsigned long personality;
        unsigned did_exec:1;
        pid_t pid;
        pid_t tgid;
        struct task_struct *real_parent;
        struct task_struct *parent;
        struct list_head children;
        struct list_head sibling;
        struct task_struct *group_leader;
        struct pid pids[PIDTYPE_MAX];
        struct completion *vfork_done;
        int *set_child_tid;
        int *clear_child_tid;
        unsigned long rt_priority;
        cputime_t utime, stime;
        unsigned long nvcsw, nivcsw;
        struct timespec start_time;
        unsigned long min_flt, maj_flt;
        cputime_t it_prof_expires, it_virt_expires;
        unsigned long long it_sched_expires;
        struct list_head cpu_timers[3];
        uid_t uid,euid,suid,fsuid;
        gid_t gid,egid,sgid,fsgid;
        struct group_info *group_info;
        kernel_cap_t cap_effective, cap_inheritable, cap_permitted;
        unsigned keep_capabilities:1;
        struct user_struct *user;
        int oomkilladj;
        char comm[16];
        int link_count, total_link_count;
        struct sysv_sem sysvsem;
        struct thread_struct thread;
        struct fs_struct *fs;
        struct files_struct *files;
        struct namespace *namespace;
        struct signal_struct *signal;
        struct sighand_struct *sighand;
        sigset_t blocked, real_blocked;
        struct sigpending pending;
        unsigned long sas_ss_sp;
        size_t sas_ss_size;
        int (*notifier)(void *priv);
        void *notifier_data;
        sigset_t *notifier_mask;
        void *security;
        struct audit_context *audit_context;
        seccomp_t seccomp;
        u32 parent_exec_id;
        u32 self_exec_id;
        spinlock_t alloc_lock;
        spinlock_t proc_lock;
        void *journal_info;
        struct reclaim_state *reclaim_state;
        struct dentry *proc_dentry;
        struct backing_dev_info *backing_dev_info;
        struct io_context *io_context;
        unsigned long ptrace_message;
        siginfo_t *last_siginfo;
        wait_queue_t *io_wait;
        u64 rchar, wchar, syscr, syscw;
        u64 acct_rss_mem1;
        u64 acct_vm_mem1;
        clock_t acct_stimexpd;
        atomic_t fs_excl;
};
static inline __attribute__((always_inline)) pid_t process_group(struct task_struct *tsk)
{
        return tsk->signal->pgrp;
}
static inline __attribute__((always_inline)) int pid_alive(struct task_struct *p)
{
        return p->pids[PIDTYPE_PID].nr != 0;
}
extern void free_task(struct task_struct *tsk);
extern void __put_task_struct(struct task_struct *tsk);
extern int set_cpus_allowed(task_t *p, cpumask_t new_mask);
extern unsigned long long sched_clock(void);
extern unsigned long long current_sched_time(const task_t *current_task);
extern void sched_exec(void);
static inline __attribute__((always_inline)) void idle_task_exit(void) {}
extern void sched_idle_next(void);
extern void set_user_nice(task_t *p, long nice);
extern int task_prio(const task_t *p);
extern int task_nice(const task_t *p);
extern int can_nice(const task_t *p, const int nice);
extern int task_curr(const task_t *p);
extern int idle_cpu(int cpu);
extern int sched_setscheduler(struct task_struct *, int, struct sched_param *);
extern task_t *idle_task(int cpu);
extern task_t *curr_task(int cpu);
extern void set_curr_task(int cpu, task_t *p);
void yield(void);
extern struct exec_domain default_exec_domain;
union thread_union {
        struct thread_info thread_info;
        unsigned long stack[(8192)/sizeof(long)];
};
static inline __attribute__((always_inline)) int kstack_end(void *addr)
{
        return !(((unsigned long)addr+sizeof(void*)-1) & ((8192)-sizeof(void*)));
}
extern union thread_union init_thread_union;
extern struct task_struct init_task;
extern struct mm_struct init_mm;
extern struct task_struct *find_task_by_pid_type(int type, int pid);
extern void set_special_pids(pid_t session, pid_t pgrp);
extern void __set_special_pids(pid_t session, pid_t pgrp);
extern struct user_struct * alloc_uid(uid_t);
static inline __attribute__((always_inline)) struct user_struct *get_uid(struct user_struct *u)
{
        atomic_inc(&u->__count);
        return u;
}
extern void free_uid(struct user_struct *);
extern void switch_uid(struct user_struct *);
extern void do_timer(struct pt_regs *);
extern int wake_up_state(struct task_struct * tsk, unsigned int state) __attribute__((regparm(3)));
extern int wake_up_process(struct task_struct * tsk) __attribute__((regparm(3)));
extern void wake_up_new_task(struct task_struct * tsk, unsigned long clone_flags) __attribute__((regparm(3)));
 extern void kick_process(struct task_struct *tsk);
extern void sched_fork(task_t * p, int clone_flags) __attribute__((regparm(3)));
extern void sched_exit(task_t * p) __attribute__((regparm(3)));
extern int in_group_p(gid_t);
extern int in_egroup_p(gid_t);
extern void proc_caches_init(void);
extern void flush_signals(struct task_struct *);
extern void flush_signal_handlers(struct task_struct *, int force_default);
extern int dequeue_signal(struct task_struct *tsk, sigset_t *mask, siginfo_t *info);
static inline __attribute__((always_inline)) int dequeue_signal_lock(struct task_struct *tsk, sigset_t *mask, siginfo_t *info)
{
        unsigned long flags;
        int ret;
        flags = _spin_lock_irqsave(&tsk->sighand->siglock);
        ret = dequeue_signal(tsk, mask, info);
        _spin_unlock_irqrestore(&tsk->sighand->siglock, flags);
        return ret;
}
extern void block_all_signals(int (*notifier)(void *priv), void *priv,
                              sigset_t *mask);
extern void unblock_all_signals(void);
extern void release_task(struct task_struct * p);
extern int send_sig_info(int, struct siginfo *, struct task_struct *);
extern int send_group_sig_info(int, struct siginfo *, struct task_struct *);
extern int force_sigsegv(int, struct task_struct *);
extern int force_sig_info(int, struct siginfo *, struct task_struct *);
extern int __kill_pg_info(int sig, struct siginfo *info, pid_t pgrp);
extern int kill_pg_info(int, struct siginfo *, pid_t);
extern int kill_proc_info(int, struct siginfo *, pid_t);
extern int kill_proc_info_as_uid(int, struct siginfo *, pid_t, uid_t, uid_t);
extern void do_notify_parent(struct task_struct *, int);
extern void force_sig(int, struct task_struct *);
extern void force_sig_specific(int, struct task_struct *);
extern int send_sig(int, struct task_struct *, int);
extern void zap_other_threads(struct task_struct *p);
extern int kill_pg(pid_t, int, int);
extern int kill_sl(pid_t, int, int);
extern int kill_proc(pid_t, int, int);
extern struct sigqueue *sigqueue_alloc(void);
extern void sigqueue_free(struct sigqueue *);
extern int send_sigqueue(int, struct sigqueue *, struct task_struct *);
extern int send_group_sigqueue(int, struct sigqueue *, struct task_struct *);
extern int do_sigaction(int, const struct k_sigaction *, struct k_sigaction *);
extern int do_sigaltstack(const stack_t *, stack_t *, unsigned long);
static inline __attribute__((always_inline)) int on_sig_stack(unsigned long sp)
{
        return (sp - get_current()->sas_ss_sp < get_current()->sas_ss_size);
}
static inline __attribute__((always_inline)) int sas_ss_flags(unsigned long sp)
{
        return (get_current()->sas_ss_size == 0 ? 2
                : on_sig_stack(sp) ? 1 : 0);
}
static inline __attribute__((always_inline)) int capable(int cap)
{
        if (((get_current()->cap_effective) & (1 << (cap)))) {
                get_current()->flags |= 0x00000100;
                return 1;
        }
        return 0;
}
extern struct mm_struct * mm_alloc(void);
extern void __mmdrop(struct mm_struct *) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) void mmdrop(struct mm_struct * mm)
{
        if (atomic_dec_and_test(&mm->mm_count))
                __mmdrop(mm);
}
extern void mmput(struct mm_struct *);
extern struct mm_struct *get_task_mm(struct task_struct *task);
extern void mm_release(struct task_struct *, struct mm_struct *);
extern int copy_thread(int, unsigned long, unsigned long, unsigned long, struct task_struct *, struct pt_regs *);
extern void flush_thread(void);
extern void exit_thread(void);
extern void exit_files(struct task_struct *);
extern void exit_signal(struct task_struct *);
extern void __exit_signal(struct task_struct *);
extern void exit_sighand(struct task_struct *);
extern void __exit_sighand(struct task_struct *);
extern void exit_itimers(struct signal_struct *);
extern void do_group_exit(int);
extern void daemonize(const char *, ...);
extern int allow_signal(int);
extern int disallow_signal(int);
extern task_t *child_reaper;
extern int do_execve(char *, char * *, char * *, struct pt_regs *);
extern long do_fork(unsigned long, unsigned long, struct pt_regs *, unsigned long, int *, int *);
task_t *fork_idle(int);
extern void set_task_comm(struct task_struct *tsk, char *from);
extern void get_task_comm(char *to, struct task_struct *tsk);
extern void wait_task_inactive(task_t * p);
extern task_t * next_thread(const task_t *p) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) int thread_group_empty(task_t *p)
{
        return list_empty(&p->pids[PIDTYPE_TGID].pid_list);
}
extern void unhash_process(struct task_struct *p);
static inline __attribute__((always_inline)) void task_lock(struct task_struct *p)
{
        _spin_lock(&p->alloc_lock);
}
static inline __attribute__((always_inline)) void task_unlock(struct task_struct *p)
{
        _spin_unlock(&p->alloc_lock);
}
static inline __attribute__((always_inline)) void set_tsk_thread_flag(struct task_struct *tsk, int flag)
{
        set_ti_thread_flag(tsk->thread_info,flag);
}
static inline __attribute__((always_inline)) void clear_tsk_thread_flag(struct task_struct *tsk, int flag)
{
        clear_ti_thread_flag(tsk->thread_info,flag);
}
static inline __attribute__((always_inline)) int test_and_set_tsk_thread_flag(struct task_struct *tsk, int flag)
{
        return test_and_set_ti_thread_flag(tsk->thread_info,flag);
}
static inline __attribute__((always_inline)) int test_and_clear_tsk_thread_flag(struct task_struct *tsk, int flag)
{
        return test_and_clear_ti_thread_flag(tsk->thread_info,flag);
}
static inline __attribute__((always_inline)) int test_tsk_thread_flag(struct task_struct *tsk, int flag)
{
        return test_ti_thread_flag(tsk->thread_info,flag);
}
static inline __attribute__((always_inline)) void set_tsk_need_resched(struct task_struct *tsk)
{
        set_tsk_thread_flag(tsk,3);
}
static inline __attribute__((always_inline)) void clear_tsk_need_resched(struct task_struct *tsk)
{
        clear_tsk_thread_flag(tsk,3);
}
static inline __attribute__((always_inline)) int signal_pending(struct task_struct *p)
{
        return __builtin_expect(!!(test_tsk_thread_flag(p,2)), 0);
}
static inline __attribute__((always_inline)) int need_resched(void)
{
        return __builtin_expect(!!(test_thread_flag(3)), 0);
}
extern int cond_resched(void);
extern int cond_resched_lock(spinlock_t * lock);
extern int cond_resched_softirq(void);
static inline __attribute__((always_inline)) int lock_need_resched(spinlock_t *lock)
{
        if (0 || need_resched())
                return 1;
        return 0;
}
extern void recalc_sigpending_tsk(struct task_struct *t) __attribute__((regparm(3)));
extern void recalc_sigpending(void);
extern void signal_wake_up(struct task_struct *t, int resume_stopped);
static inline __attribute__((always_inline)) unsigned int task_cpu(const struct task_struct *p)
{
        return p->thread_info->cpu;
}
static inline __attribute__((always_inline)) void set_task_cpu(struct task_struct *p, unsigned int cpu)
{
        p->thread_info->cpu = cpu;
}
extern void arch_pick_mmap_layout(struct mm_struct *mm);
extern long sched_setaffinity(pid_t pid, cpumask_t new_mask);
extern long sched_getaffinity(pid_t pid, cpumask_t *mask);
extern void normalize_rt_tasks(void);
static inline __attribute__((always_inline)) int frozen(struct task_struct *p)
{
        return p->flags & 0x00010000;
}
static inline __attribute__((always_inline)) int freezing(struct task_struct *p)
{
        return p->flags & 0x00004000;
}
static inline __attribute__((always_inline)) void freeze(struct task_struct *p)
{
        p->flags |= 0x00004000;
}
static inline __attribute__((always_inline)) int thaw_process(struct task_struct *p)
{
        if (frozen(p)) {
                p->flags &= ~0x00010000;
                wake_up_process(p);
                return 1;
        }
        return 0;
}
static inline __attribute__((always_inline)) void frozen_process(struct task_struct *p)
{
        p->flags = (p->flags & ~0x00004000) | 0x00010000;
}
extern void refrigerator(void);
extern int freeze_processes(void);
extern void thaw_processes(void);
static inline __attribute__((always_inline)) int try_to_freeze(void)
{
        if (freezing(get_current())) {
                refrigerator();
                return 1;
        } else
                return 0;
}
struct __old_kernel_stat {
        unsigned short st_dev;
        unsigned short st_ino;
        unsigned short st_mode;
        unsigned short st_nlink;
        unsigned short st_uid;
        unsigned short st_gid;
        unsigned short st_rdev;
        unsigned long st_size;
        unsigned long st_atime;
        unsigned long st_mtime;
        unsigned long st_ctime;
};
struct stat {
        unsigned long st_dev;
        unsigned long st_ino;
        unsigned short st_mode;
        unsigned short st_nlink;
        unsigned short st_uid;
        unsigned short st_gid;
        unsigned long st_rdev;
        unsigned long st_size;
        unsigned long st_blksize;
        unsigned long st_blocks;
        unsigned long st_atime;
        unsigned long st_atime_nsec;
        unsigned long st_mtime;
        unsigned long st_mtime_nsec;
        unsigned long st_ctime;
        unsigned long st_ctime_nsec;
        unsigned long __unused4;
        unsigned long __unused5;
};
struct stat64 {
        unsigned long long st_dev;
        unsigned char __pad0[4];
        unsigned long __st_ino;
        unsigned int st_mode;
        unsigned int st_nlink;
        unsigned long st_uid;
        unsigned long st_gid;
        unsigned long long st_rdev;
        unsigned char __pad3[4];
        long long st_size;
        unsigned long st_blksize;
        unsigned long st_blocks;
        unsigned long __pad4;
        unsigned long st_atime;
        unsigned long st_atime_nsec;
        unsigned long st_mtime;
        unsigned int st_mtime_nsec;
        unsigned long st_ctime;
        unsigned long st_ctime_nsec;
        unsigned long long st_ino;
};
struct kstat {
        unsigned long ino;
        dev_t dev;
        umode_t mode;
        unsigned int nlink;
        uid_t uid;
        gid_t gid;
        dev_t rdev;
        loff_t size;
        struct timespec atime;
        struct timespec mtime;
        struct timespec ctime;
        unsigned long blksize;
        unsigned long blocks;
};
extern int request_module(const char * name, ...) __attribute__ ((format (printf, 1, 2)));
struct key;
extern int call_usermodehelper_keys(char *path, char *argv[], char *envp[],
                                    struct key *session_keyring, int wait);
static inline __attribute__((always_inline)) int
call_usermodehelper(char *path, char **argv, char **envp, int wait)
{
        return call_usermodehelper_keys(path, argv, envp, ((void *)0), wait);
}
extern void usermodehelper_init(void);
struct user_i387_struct {
        long cwd;
        long swd;
        long twd;
        long fip;
        long fcs;
        long foo;
        long fos;
        long st_space[20];
};
struct user_fxsr_struct {
        unsigned short cwd;
        unsigned short swd;
        unsigned short twd;
        unsigned short fop;
        long fip;
        long fcs;
        long foo;
        long fos;
        long mxcsr;
        long reserved;
        long st_space[32];
        long xmm_space[32];
        long padding[56];
};
struct user_regs_struct {
        long ebx, ecx, edx, esi, edi, ebp, eax;
        unsigned short ds, __ds, es, __es;
        unsigned short fs, __fs, gs, __gs;
        long orig_eax, eip;
        unsigned short cs, __cs;
        long eflags, esp;
        unsigned short ss, __ss;
};
struct user{
  struct user_regs_struct regs;
  int u_fpvalid;
  struct user_i387_struct i387;
  unsigned long int u_tsize;
  unsigned long int u_dsize;
  unsigned long int u_ssize;
  unsigned long start_code;
  unsigned long start_stack;
  long int signal;
  int reserved;
  struct user_pt_regs * u_ar0;
  struct user_i387_struct* u_fpstate;
  unsigned long magic;
  char u_comm[32];
  int u_debugreg[8];
};
struct oldold_utsname {
        char sysname[9];
        char nodename[9];
        char release[9];
        char version[9];
        char machine[9];
};
struct old_utsname {
        char sysname[65];
        char nodename[65];
        char release[65];
        char version[65];
        char machine[65];
};
struct new_utsname {
        char sysname[65];
        char nodename[65];
        char release[65];
        char version[65];
        char machine[65];
        char domainname[65];
};
extern struct new_utsname system_utsname;
extern struct rw_semaphore uts_sem;
typedef unsigned long elf_greg_t;
typedef elf_greg_t elf_gregset_t[(sizeof (struct user_regs_struct) / sizeof(elf_greg_t))];
typedef struct user_i387_struct elf_fpregset_t;
typedef struct user_fxsr_struct elf_fpxregset_t;
extern int dump_task_regs (struct task_struct *, elf_gregset_t *);
extern int dump_task_fpu (struct task_struct *, elf_fpregset_t *);
extern int dump_task_extended_fpu (struct task_struct *, struct user_fxsr_struct *);
extern void __kernel_vsyscall;
typedef __u32 Elf32_Addr;
typedef __u16 Elf32_Half;
typedef __u32 Elf32_Off;
typedef __s32 Elf32_Sword;
typedef __u32 Elf32_Word;
typedef __u64 Elf64_Addr;
typedef __u16 Elf64_Half;
typedef __s16 Elf64_SHalf;
typedef __u64 Elf64_Off;
typedef __s32 Elf64_Sword;
typedef __u32 Elf64_Word;
typedef __u64 Elf64_Xword;
typedef __s64 Elf64_Sxword;
typedef struct dynamic{
  Elf32_Sword d_tag;
  union{
    Elf32_Sword d_val;
    Elf32_Addr d_ptr;
  } d_un;
} Elf32_Dyn;
typedef struct {
  Elf64_Sxword d_tag;
  union {
    Elf64_Xword d_val;
    Elf64_Addr d_ptr;
  } d_un;
} Elf64_Dyn;
typedef struct elf32_rel {
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;
typedef struct elf64_rel {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
} Elf64_Rel;
typedef struct elf32_rela{
  Elf32_Addr r_offset;
  Elf32_Word r_info;
  Elf32_Sword r_addend;
} Elf32_Rela;
typedef struct elf64_rela {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
  Elf64_Sxword r_addend;
} Elf64_Rela;
typedef struct elf32_sym{
  Elf32_Word st_name;
  Elf32_Addr st_value;
  Elf32_Word st_size;
  unsigned char st_info;
  unsigned char st_other;
  Elf32_Half st_shndx;
} Elf32_Sym;
typedef struct elf64_sym {
  Elf64_Word st_name;
  unsigned char st_info;
  unsigned char st_other;
  Elf64_Half st_shndx;
  Elf64_Addr st_value;
  Elf64_Xword st_size;
} Elf64_Sym;
typedef struct elf32_hdr{
  unsigned char e_ident[16];
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
} Elf32_Ehdr;
typedef struct elf64_hdr {
  unsigned char e_ident[16];
  Elf64_Half e_type;
  Elf64_Half e_machine;
  Elf64_Word e_version;
  Elf64_Addr e_entry;
  Elf64_Off e_phoff;
  Elf64_Off e_shoff;
  Elf64_Word e_flags;
  Elf64_Half e_ehsize;
  Elf64_Half e_phentsize;
  Elf64_Half e_phnum;
  Elf64_Half e_shentsize;
  Elf64_Half e_shnum;
  Elf64_Half e_shstrndx;
} Elf64_Ehdr;
typedef struct elf32_phdr{
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
} Elf32_Phdr;
typedef struct elf64_phdr {
  Elf64_Word p_type;
  Elf64_Word p_flags;
  Elf64_Off p_offset;
  Elf64_Addr p_vaddr;
  Elf64_Addr p_paddr;
  Elf64_Xword p_filesz;
  Elf64_Xword p_memsz;
  Elf64_Xword p_align;
} Elf64_Phdr;
typedef struct {
  Elf32_Word sh_name;
  Elf32_Word sh_type;
  Elf32_Word sh_flags;
  Elf32_Addr sh_addr;
  Elf32_Off sh_offset;
  Elf32_Word sh_size;
  Elf32_Word sh_link;
  Elf32_Word sh_info;
  Elf32_Word sh_addralign;
  Elf32_Word sh_entsize;
} Elf32_Shdr;
typedef struct elf64_shdr {
  Elf64_Word sh_name;
  Elf64_Word sh_type;
  Elf64_Xword sh_flags;
  Elf64_Addr sh_addr;
  Elf64_Off sh_offset;
  Elf64_Xword sh_size;
  Elf64_Word sh_link;
  Elf64_Word sh_info;
  Elf64_Xword sh_addralign;
  Elf64_Xword sh_entsize;
} Elf64_Shdr;
typedef struct elf32_note {
  Elf32_Word n_namesz;
  Elf32_Word n_descsz;
  Elf32_Word n_type;
} Elf32_Nhdr;
typedef struct elf64_note {
  Elf64_Word n_namesz;
  Elf64_Word n_descsz;
  Elf64_Word n_type;
} Elf64_Nhdr;
extern Elf32_Dyn _DYNAMIC [];
struct kobject;
struct module;
struct attribute {
        const char * name;
        struct module * owner;
        mode_t mode;
};
struct attribute_group {
        const char * name;
        struct attribute ** attrs;
};
struct vm_area_struct;
struct bin_attribute {
        struct attribute attr;
        size_t size;
        void *private;
        ssize_t (*read)(struct kobject *, char *, loff_t, size_t);
        ssize_t (*write)(struct kobject *, char *, loff_t, size_t);
        int (*mmap)(struct kobject *, struct bin_attribute *attr,
                    struct vm_area_struct *vma);
};
struct sysfs_ops {
        ssize_t (*show)(struct kobject *, struct attribute *,char *);
        ssize_t (*store)(struct kobject *,struct attribute *,const char *, size_t);
};
struct sysfs_dirent {
        atomic_t s_count;
        struct list_head s_sibling;
        struct list_head s_children;
        void * s_element;
        int s_type;
        umode_t s_mode;
        struct dentry * s_dentry;
        struct iattr * s_iattr;
};
extern int
sysfs_create_dir(struct kobject *);
extern void
sysfs_remove_dir(struct kobject *);
extern int
sysfs_rename_dir(struct kobject *, const char *new_name);
extern int
sysfs_create_file(struct kobject *, const struct attribute *);
extern int
sysfs_update_file(struct kobject *, const struct attribute *);
extern int
sysfs_chmod_file(struct kobject *kobj, struct attribute *attr, mode_t mode);
extern void
sysfs_remove_file(struct kobject *, const struct attribute *);
extern int
sysfs_create_link(struct kobject * kobj, struct kobject * target, const char * name);
extern void
sysfs_remove_link(struct kobject *, const char * name);
int sysfs_create_bin_file(struct kobject * kobj, struct bin_attribute * attr);
int sysfs_remove_bin_file(struct kobject * kobj, struct bin_attribute * attr);
int sysfs_create_group(struct kobject *, const struct attribute_group *);
void sysfs_remove_group(struct kobject *, const struct attribute_group *);
struct kref {
        atomic_t refcount;
};
void kref_init(struct kref *kref);
void kref_get(struct kref *kref);
int kref_put(struct kref *kref, void (*release) (struct kref *kref));
extern char hotplug_path[];
typedef int kobject_action_t;
enum kobject_action {
        KOBJ_ADD = ( kobject_action_t) 0x01,
        KOBJ_REMOVE = ( kobject_action_t) 0x02,
        KOBJ_CHANGE = ( kobject_action_t) 0x03,
        KOBJ_MOUNT = ( kobject_action_t) 0x04,
        KOBJ_UMOUNT = ( kobject_action_t) 0x05,
        KOBJ_OFFLINE = ( kobject_action_t) 0x06,
        KOBJ_ONLINE = ( kobject_action_t) 0x07,
};
int kobject_uevent(struct kobject *kobj,
                   enum kobject_action action,
                   struct attribute *attr);
int kobject_uevent_atomic(struct kobject *kobj,
                          enum kobject_action action,
                          struct attribute *attr);
extern u64 hotplug_seqnum;
struct kobject {
        const char * k_name;
        char name[20];
        struct kref kref;
        struct list_head entry;
        struct kobject * parent;
        struct kset * kset;
        struct kobj_type * ktype;
        struct dentry * dentry;
};
extern int kobject_set_name(struct kobject *, const char *, ...)
        __attribute__((format(printf,2,3)));
static inline __attribute__((always_inline)) const char * kobject_name(const struct kobject * kobj)
{
        return kobj->k_name;
}
extern void kobject_init(struct kobject *);
extern void kobject_cleanup(struct kobject *);
extern int kobject_add(struct kobject *);
extern void kobject_del(struct kobject *);
extern int kobject_rename(struct kobject *, const char *new_name);
extern int kobject_register(struct kobject *);
extern void kobject_unregister(struct kobject *);
extern struct kobject * kobject_get(struct kobject *);
extern void kobject_put(struct kobject *);
extern char * kobject_get_path(struct kobject *, int);
struct kobj_type {
        void (*release)(struct kobject *);
        struct sysfs_ops * sysfs_ops;
        struct attribute ** default_attrs;
};
struct kset_hotplug_ops {
        int (*filter)(struct kset *kset, struct kobject *kobj);
        const char *(*name)(struct kset *kset, struct kobject *kobj);
        int (*hotplug)(struct kset *kset, struct kobject *kobj, char **envp,
                        int num_envp, char *buffer, int buffer_size);
};
struct kset {
        struct subsystem * subsys;
        struct kobj_type * ktype;
        struct list_head list;
        spinlock_t list_lock;
        struct kobject kobj;
        struct kset_hotplug_ops * hotplug_ops;
};
extern void kset_init(struct kset * k);
extern int kset_add(struct kset * k);
extern int kset_register(struct kset * k);
extern void kset_unregister(struct kset * k);
static inline __attribute__((always_inline)) struct kset * to_kset(struct kobject * kobj)
{
        return kobj ? ({ const typeof( ((struct kset *)0)->kobj ) *__mptr = (kobj); (struct kset *)( (char *)__mptr - ((size_t) &((struct kset *)0)->kobj) );}) : ((void *)0);
}
static inline __attribute__((always_inline)) struct kset * kset_get(struct kset * k)
{
        return k ? to_kset(kobject_get(&k->kobj)) : ((void *)0);
}
static inline __attribute__((always_inline)) void kset_put(struct kset * k)
{
        kobject_put(&k->kobj);
}
static inline __attribute__((always_inline)) struct kobj_type * get_ktype(struct kobject * k)
{
        if (k->kset && k->kset->ktype)
                return k->kset->ktype;
        else
                return k->ktype;
}
extern struct kobject * kset_find_obj(struct kset *, const char *);
struct subsystem {
        struct kset kset;
        struct rw_semaphore rwsem;
};
extern struct subsystem kernel_subsys;
extern void subsystem_init(struct subsystem *);
extern int subsystem_register(struct subsystem *);
extern void subsystem_unregister(struct subsystem *);
static inline __attribute__((always_inline)) struct subsystem * subsys_get(struct subsystem * s)
{
        return s ? ({ const typeof( ((struct subsystem *)0)->kset ) *__mptr = (kset_get(&s->kset)); (struct subsystem *)( (char *)__mptr - ((size_t) &((struct subsystem *)0)->kset) );}) : ((void *)0);
}
static inline __attribute__((always_inline)) void subsys_put(struct subsystem * s)
{
        kset_put(&s->kset);
}
struct subsys_attribute {
        struct attribute attr;
        ssize_t (*show)(struct subsystem *, char *);
        ssize_t (*store)(struct subsystem *, const char *, size_t);
};
extern int subsys_create_file(struct subsystem * , struct subsys_attribute *);
extern void subsys_remove_file(struct subsystem * , struct subsys_attribute *);
void kobject_hotplug(struct kobject *kobj, enum kobject_action action);
int add_hotplug_env_var(char **envp, int num_envp, int *cur_index,
                        char *buffer, int buffer_size, int *cur_len,
                        const char *format, ...)
        __attribute__((format (printf, 7, 8)));
struct kernel_param;
typedef int (*param_set_fn)(const char *val, struct kernel_param *kp);
typedef int (*param_get_fn)(char *buffer, struct kernel_param *kp);
struct kernel_param {
        const char *name;
        unsigned int perm;
        param_set_fn set;
        param_get_fn get;
        void *arg;
};
struct kparam_string {
        unsigned int maxlen;
        char *string;
};
struct kparam_array
{
        unsigned int max;
        unsigned int *num;
        param_set_fn set;
        param_get_fn get;
        unsigned int elemsize;
        void *elem;
};
extern int parse_args(const char *name,
                      char *args,
                      struct kernel_param *params,
                      unsigned num,
                      int (*unknown)(char *param, char *val));
extern int param_set_byte(const char *val, struct kernel_param *kp);
extern int param_get_byte(char *buffer, struct kernel_param *kp);
extern int param_set_short(const char *val, struct kernel_param *kp);
extern int param_get_short(char *buffer, struct kernel_param *kp);
extern int param_set_ushort(const char *val, struct kernel_param *kp);
extern int param_get_ushort(char *buffer, struct kernel_param *kp);
extern int param_set_int(const char *val, struct kernel_param *kp);
extern int param_get_int(char *buffer, struct kernel_param *kp);
extern int param_set_uint(const char *val, struct kernel_param *kp);
extern int param_get_uint(char *buffer, struct kernel_param *kp);
extern int param_set_long(const char *val, struct kernel_param *kp);
extern int param_get_long(char *buffer, struct kernel_param *kp);
extern int param_set_ulong(const char *val, struct kernel_param *kp);
extern int param_get_ulong(char *buffer, struct kernel_param *kp);
extern int param_set_charp(const char *val, struct kernel_param *kp);
extern int param_get_charp(char *buffer, struct kernel_param *kp);
extern int param_set_bool(const char *val, struct kernel_param *kp);
extern int param_get_bool(char *buffer, struct kernel_param *kp);
extern int param_set_invbool(const char *val, struct kernel_param *kp);
extern int param_get_invbool(char *buffer, struct kernel_param *kp);
extern int param_array_set(const char *val, struct kernel_param *kp);
extern int param_array_get(char *buffer, struct kernel_param *kp);
extern int param_set_copystring(const char *val, struct kernel_param *kp);
extern int param_get_string(char *buffer, struct kernel_param *kp);
int param_array(const char *name,
                const char *val,
                unsigned int min, unsigned int max,
                void *elem, int elemsize,
                int (*set)(const char *, struct kernel_param *kp),
                int *num);
struct module;
extern int module_param_sysfs_setup(struct module *mod,
                                    struct kernel_param *kparam,
                                    unsigned int num_params);
extern void module_param_sysfs_remove(struct module *mod);
typedef struct
{
        volatile unsigned long counter;
} local_t;
static __inline__ __attribute__((always_inline)) void local_inc(local_t *v)
{
        __asm__ __volatile__(
                "incl %0"
                :"=m" (v->counter)
                :"m" (v->counter));
}
static __inline__ __attribute__((always_inline)) void local_dec(local_t *v)
{
        __asm__ __volatile__(
                "decl %0"
                :"=m" (v->counter)
                :"m" (v->counter));
}
static __inline__ __attribute__((always_inline)) void local_add(unsigned long i, local_t *v)
{
        __asm__ __volatile__(
                "addl %1,%0"
                :"=m" (v->counter)
                :"ir" (i), "m" (v->counter));
}
static __inline__ __attribute__((always_inline)) void local_sub(unsigned long i, local_t *v)
{
        __asm__ __volatile__(
                "subl %1,%0"
                :"=m" (v->counter)
                :"ir" (i), "m" (v->counter));
}
struct mod_arch_specific
{
};
struct kernel_symbol
{
        unsigned long value;
        const char *name;
};
struct modversion_info
{
        unsigned long crc;
        char name[(64 - sizeof(unsigned long))];
};
struct module;
struct module_attribute {
        struct attribute attr;
        ssize_t (*show)(struct module_attribute *, struct module *, char *);
        ssize_t (*store)(struct module_attribute *, struct module *,
                         const char *, size_t count);
        void (*setup)(struct module *, const char *);
        int (*test)(struct module *);
        void (*free)(struct module *);
};
struct module_kobject
{
        struct kobject kobj;
        struct module *mod;
};
extern int init_module(void);
extern void cleanup_module(void);
struct exception_table_entry;
const struct exception_table_entry *
search_extable(const struct exception_table_entry *first,
               const struct exception_table_entry *last,
               unsigned long value);
void sort_extable(struct exception_table_entry *start,
                  struct exception_table_entry *finish);
void sort_main_extable(void);
extern struct subsystem module_subsys;
const struct exception_table_entry *search_exception_tables(unsigned long add);
struct notifier_block;
void *__symbol_get(const char *symbol);
void *__symbol_get_gpl(const char *symbol);
struct module_ref
{
        local_t count;
} __attribute__((__aligned__((1 << (4)))));
enum module_state
{
        MODULE_STATE_LIVE,
        MODULE_STATE_COMING,
        MODULE_STATE_GOING,
};
struct module_sect_attr
{
        struct module_attribute mattr;
        char name[32];
        unsigned long address;
};
struct module_sect_attrs
{
        struct attribute_group grp;
        struct module_sect_attr attrs[0];
};
struct module_param_attrs;
struct module
{
        enum module_state state;
        struct list_head list;
        char name[(64 - sizeof(unsigned long))];
        struct module_kobject mkobj;
        struct module_param_attrs *param_attrs;
        const char *version;
        const char *srcversion;
        const struct kernel_symbol *syms;
        unsigned int num_syms;
        const unsigned long *crcs;
        const struct kernel_symbol *gpl_syms;
        unsigned int num_gpl_syms;
        const unsigned long *gpl_crcs;
        unsigned int num_exentries;
        const struct exception_table_entry *extable;
        int (*init)(void);
        void *module_init;
        void *module_core;
        unsigned long init_size, core_size;
        unsigned long init_text_size, core_text_size;
        struct mod_arch_specific arch;
        int unsafe;
        int license_gplok;
        Elf32_Sym *symtab;
        unsigned long num_symtab;
        char *strtab;
        struct module_sect_attrs *sect_attrs;
        void *percpu;
        char *args;
};
static inline __attribute__((always_inline)) int module_is_live(struct module *mod)
{
        return mod->state != MODULE_STATE_GOING;
}
struct module *module_text_address(unsigned long addr);
struct module *__module_text_address(unsigned long addr);
struct module *module_get_kallsym(unsigned int symnum,
                                  unsigned long *value,
                                  char *type,
                                  char namebuf[128]);
unsigned long module_kallsyms_lookup_name(const char *name);
int is_exported(const char *name, const struct module *mod);
extern void __module_put_and_exit(struct module *mod, long code)
        __attribute__((noreturn));
static inline __attribute__((always_inline)) int try_module_get(struct module *module)
{
        return !module || module_is_live(module);
}
static inline __attribute__((always_inline)) void module_put(struct module *module)
{
}
static inline __attribute__((always_inline)) void __module_get(struct module *module)
{
}
const char *module_address_lookup(unsigned long addr,
                                  unsigned long *symbolsize,
                                  unsigned long *offset,
                                  char **modname);
const struct exception_table_entry *search_module_extables(unsigned long addr);
int register_module_notifier(struct notifier_block * nb);
int unregister_module_notifier(struct notifier_block * nb);
extern void print_modules(void);
struct device_driver;
void module_add_driver(struct module *, struct device_driver *);
void module_remove_driver(struct device_driver *);
struct obsolete_modparm {
        char name[64];
        char type[64-sizeof(void *)];
        void *addr;
};
static inline __attribute__((always_inline)) void MODULE_PARM_(void) { }
extern void __attribute__((deprecated)) inter_module_register(const char *,
                struct module *, const void *);
extern void __attribute__((deprecated)) inter_module_unregister(const char *);
extern const void * __attribute__((deprecated)) inter_module_get_request(const char *,
                const char *);
extern void __attribute__((deprecated)) inter_module_put(const char *);
struct consolefontdesc {
        unsigned short charcount;
        unsigned short charheight;
        char *chardata;
};
typedef char scrnmap_t;
struct unipair {
        unsigned short unicode;
        unsigned short fontpos;
};
struct unimapdesc {
        unsigned short entry_ct;
        struct unipair *entries;
};
struct unimapinit {
        unsigned short advised_hashsize;
        unsigned short advised_hashstep;
        unsigned short advised_hashlevel;
};
struct kbentry {
        unsigned char kb_table;
        unsigned char kb_index;
        unsigned short kb_value;
};
struct kbsentry {
        unsigned char kb_func;
        unsigned char kb_string[512];
};
struct kbdiacr {
        unsigned char diacr, base, result;
};
struct kbdiacrs {
        unsigned int kb_cnt;
        struct kbdiacr kbdiacr[256];
};
struct kbkeycode {
        unsigned int scancode, keycode;
};
struct kbd_repeat {
        int delay;
        int period;
};
struct console_font_op {
        unsigned int op;
        unsigned int flags;
        unsigned int width, height;
        unsigned int charcount;
        unsigned char *data;
};
struct console_font {
        unsigned int width, height;
        unsigned int charcount;
        unsigned char *data;
};
struct raw_prio_tree_node {
        struct prio_tree_node *left;
        struct prio_tree_node *right;
        struct prio_tree_node *parent;
};
struct prio_tree_node {
        struct prio_tree_node *left;
        struct prio_tree_node *right;
        struct prio_tree_node *parent;
        unsigned long start;
        unsigned long last;
};
struct prio_tree_root {
        struct prio_tree_node *prio_tree_node;
        unsigned short index_bits;
        unsigned short raw;
};
struct prio_tree_iter {
        struct prio_tree_node *cur;
        unsigned long mask;
        unsigned long value;
        int size_level;
        struct prio_tree_root *root;
        unsigned long r_index;
        unsigned long h_index;
};
static inline __attribute__((always_inline)) void prio_tree_iter_init(struct prio_tree_iter *iter,
                struct prio_tree_root *root, unsigned long r_index, unsigned long h_index)
{
        iter->root = root;
        iter->r_index = r_index;
        iter->h_index = h_index;
        iter->cur = ((void *)0);
}
static inline __attribute__((always_inline)) int prio_tree_empty(const struct prio_tree_root *root)
{
        return root->prio_tree_node == ((void *)0);
}
static inline __attribute__((always_inline)) int prio_tree_root(const struct prio_tree_node *node)
{
        return node->parent == node;
}
static inline __attribute__((always_inline)) int prio_tree_left_empty(const struct prio_tree_node *node)
{
        return node->left == node;
}
static inline __attribute__((always_inline)) int prio_tree_right_empty(const struct prio_tree_node *node)
{
        return node->right == node;
}
struct prio_tree_node *prio_tree_replace(struct prio_tree_root *root,
                struct prio_tree_node *old, struct prio_tree_node *node);
struct prio_tree_node *prio_tree_insert(struct prio_tree_root *root,
                struct prio_tree_node *node);
void prio_tree_remove(struct prio_tree_root *root, struct prio_tree_node *node);
struct prio_tree_node *prio_tree_next(struct prio_tree_iter *iter);
extern unsigned int __invalid_size_argument_for_IOC;
extern int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) __reacquire_kernel_lock(void);
extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) __release_kernel_lock(void);
static inline __attribute__((always_inline)) int reacquire_kernel_lock(struct task_struct *task)
{
        if (__builtin_expect(!!(task->lock_depth >= 0), 0))
                __reacquire_kernel_lock();
        return 0;
}
extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) lock_kernel(void) ;
extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) unlock_kernel(void) ;
static __inline__ __attribute__((always_inline)) int irq_canonicalize(int irq)
{
        return ((irq == 2) ? 9 : irq);
}
extern void release_vm86_irqs(struct task_struct *);
extern int irqbalance_disable(char *str);
struct hw_interrupt_type {
        const char * typename;
        unsigned int (*startup)(unsigned int irq);
        void (*shutdown)(unsigned int irq);
        void (*enable)(unsigned int irq);
        void (*disable)(unsigned int irq);
        void (*ack)(unsigned int irq);
        void (*end)(unsigned int irq);
        void (*set_affinity)(unsigned int irq, cpumask_t dest);
};
typedef struct hw_interrupt_type hw_irq_controller;
typedef struct irq_desc {
        hw_irq_controller *handler;
        void *handler_data;
        struct irqaction *action;
        unsigned int status;
        unsigned int depth;
        unsigned int irq_count;
        unsigned int irqs_unhandled;
        spinlock_t lock;
        unsigned int move_irq;
} __attribute__((__aligned__((1 << (4))))) irq_desc_t;
extern irq_desc_t irq_desc [224];
static inline __attribute__((always_inline)) irq_desc_t *
irq_descp (int irq)
{
        return irq_desc + irq;
}
struct proc_dir_entry;
struct pt_regs;
void __attribute__ ((__section__ (".init.text"))) profile_init(void);
void profile_tick(int, struct pt_regs *);
void profile_hit(int, void *);
void create_prof_cpu_mask(struct proc_dir_entry *);
enum profile_type {
        PROFILE_TASK_EXIT,
        PROFILE_MUNMAP
};
struct notifier_block;
struct task_struct;
struct mm_struct;
void profile_task_exit(struct task_struct * task);
int profile_handoff_task(struct task_struct * task);
void profile_munmap(unsigned long addr);
int task_handoff_register(struct notifier_block * n);
int task_handoff_unregister(struct notifier_block * n);
int profile_event_register(enum profile_type, struct notifier_block * n);
int profile_event_unregister(enum profile_type, struct notifier_block * n);
int register_timer_hook(int (*hook)(struct pt_regs *));
void unregister_timer_hook(int (*hook)(struct pt_regs *));
extern int (*timer_hook)(struct pt_regs *);
struct pt_regs;
extern char _text[], _stext[], _etext[];
extern char _data[], _sdata[], _edata[];
extern char __bss_start[], __bss_stop[];
extern char __init_begin[], __init_end[];
extern char _sinittext[], _einittext[];
extern char _sextratext[] __attribute__((weak));
extern char _eextratext[] __attribute__((weak));
extern char _end[];
extern char __per_cpu_start[], __per_cpu_end[];
extern char __kprobes_text_start[], __kprobes_text_end[];
struct hw_interrupt_type;
extern u8 irq_vector[(32 * 8)];
extern void (*interrupt[224])(void);
__attribute__((regparm(3))) void reschedule_interrupt(void);
__attribute__((regparm(3))) void invalidate_interrupt(void);
__attribute__((regparm(3))) void call_function_interrupt(void);
__attribute__((regparm(3))) void apic_timer_interrupt(void);
__attribute__((regparm(3))) void error_interrupt(void);
__attribute__((regparm(3))) void spurious_interrupt(void);
__attribute__((regparm(3))) void thermal_interrupt(struct pt_regs *);
void disable_8259A_irq(unsigned int irq);
void enable_8259A_irq(unsigned int irq);
int i8259A_irq_pending(unsigned int irq);
void make_8259A_irq(unsigned int irq);
void init_8259A(int aeoi);
void send_IPI_self(int vector) __attribute__((regparm(3)));
void init_VISWS_APIC_irqs(void);
void setup_IO_APIC(void);
void disable_IO_APIC(void);
void print_IO_APIC(void);
int IO_APIC_get_PCI_irq_vector(int bus, int slot, int fn);
void send_IPI(int dest, int vector);
void setup_ioapic_dest(void);
extern unsigned long io_apic_irqs;
extern atomic_t irq_err_count;
extern atomic_t irq_mis_count;
static inline __attribute__((always_inline)) void hw_resend_irq(struct hw_interrupt_type *h, unsigned int i)
{
        if ((((i) >= 16) || ((1<<(i)) & io_apic_irqs)))
                send_IPI_self((irq_vector[i]));
}
extern int setup_irq(unsigned int irq, struct irqaction * new);
extern cpumask_t irq_affinity[224];
static inline __attribute__((always_inline)) void set_native_irq_info(int irq, cpumask_t mask)
{
        irq_affinity[irq] = mask;
}
extern cpumask_t pending_irq_cpumask[224];
static inline __attribute__((always_inline)) void set_pending_irq(unsigned int irq, cpumask_t mask)
{
        irq_desc_t *desc = irq_desc + irq;
        unsigned long flags;
        flags = _spin_lock_irqsave(&desc->lock);
        desc->move_irq = 1;
        pending_irq_cpumask[irq] = mask;
        _spin_unlock_irqrestore(&desc->lock, flags);
}
static inline __attribute__((always_inline)) void
move_native_irq(int irq)
{
        cpumask_t tmp;
        irq_desc_t *desc = irq_descp(irq);
        if (__builtin_expect(!!(!desc->move_irq), 1))
                return;
        desc->move_irq = 0;
        if (__builtin_expect(!!(__cpus_empty(&(pending_irq_cpumask[irq]), 8)), 1))
                return;
        if (!desc->handler->set_affinity)
                return;
        __cpus_and(&(tmp), &(pending_irq_cpumask[irq]), &(cpu_online_map), 8);
        if (__builtin_expect(!!(!__cpus_empty(&(tmp), 8)), 0)) {
                desc->handler->disable(irq);
                desc->handler->set_affinity(irq,tmp);
                desc->handler->enable(irq);
        }
        __cpus_clear(&(pending_irq_cpumask[irq]), 8);
}
static inline __attribute__((always_inline)) void move_irq(int irq)
{
        move_native_irq(irq);
}
static inline __attribute__((always_inline)) void set_irq_info(int irq, cpumask_t mask)
{
        set_native_irq_info(irq, mask);
}
extern int no_irq_affinity;
extern int noirqdebug_setup(char *str);
extern __attribute__((regparm(3))) int handle_IRQ_event(unsigned int irq, struct pt_regs *regs,
                                        struct irqaction *action);
extern __attribute__((regparm(3))) unsigned int __do_IRQ(unsigned int irq, struct pt_regs *regs);
extern void note_interrupt(unsigned int irq, irq_desc_t *desc,
                                        int action_ret, struct pt_regs *regs);
extern int can_request_irq(unsigned int irq, unsigned long irqflags);
extern void init_irq_proc(void);
extern hw_irq_controller no_irq_type;
typedef struct {
        unsigned int __softirq_pending;
        unsigned long idle_timestamp;
        unsigned int __nmi_count;
        unsigned int apic_timer_irqs;
} __attribute__((__aligned__((1 << (4))))) irq_cpustat_t;
extern __typeof__(irq_cpustat_t) per_cpu__irq_stat;
extern irq_cpustat_t irq_stat[];
void ack_bad_irq(unsigned int irq);
extern void synchronize_irq(unsigned int irq);
static inline __attribute__((always_inline)) void account_user_vtime(struct task_struct *tsk)
{
}
static inline __attribute__((always_inline)) void account_system_vtime(struct task_struct *tsk)
{
}
extern void irq_exit(void);
typedef int irqreturn_t;
struct irqaction {
        irqreturn_t (*handler)(int, void *, struct pt_regs *);
        unsigned long flags;
        cpumask_t mask;
        const char *name;
        void *dev_id;
        struct irqaction *next;
        int irq;
        struct proc_dir_entry *dir;
};
extern irqreturn_t no_action(int cpl, void *dev_id, struct pt_regs *regs);
extern int request_irq(unsigned int,
                       irqreturn_t (*handler)(int, void *, struct pt_regs *),
                       unsigned long, const char *, void *);
extern void free_irq(unsigned int, void *);
extern void disable_irq_nosync(unsigned int irq);
extern void disable_irq(unsigned int irq);
extern void enable_irq(unsigned int irq);
extern void local_bh_enable(void);
enum
{
        HI_SOFTIRQ=0,
        TIMER_SOFTIRQ,
        NET_TX_SOFTIRQ,
        NET_RX_SOFTIRQ,
        SCSI_SOFTIRQ,
        TASKLET_SOFTIRQ
};
struct softirq_action
{
        void (*action)(struct softirq_action *);
        void *data;
};
 __attribute__((regparm(0))) void do_softirq(void);
extern void open_softirq(int nr, void (*action)(struct softirq_action*), void *data);
extern void softirq_init(void);
extern void raise_softirq_irqoff(unsigned int nr) __attribute__((regparm(3)));
extern void raise_softirq(unsigned int nr) __attribute__((regparm(3)));
struct tasklet_struct
{
        struct tasklet_struct *next;
        unsigned long state;
        atomic_t count;
        void (*func)(unsigned long);
        unsigned long data;
};
enum
{
        TASKLET_STATE_SCHED,
        TASKLET_STATE_RUN
};
static inline __attribute__((always_inline)) int tasklet_trylock(struct tasklet_struct *t)
{
        return !test_and_set_bit(TASKLET_STATE_RUN, &(t)->state);
}
static inline __attribute__((always_inline)) void tasklet_unlock(struct tasklet_struct *t)
{
        __asm__ __volatile__("": : :"memory");
        clear_bit(TASKLET_STATE_RUN, &(t)->state);
}
static inline __attribute__((always_inline)) void tasklet_unlock_wait(struct tasklet_struct *t)
{
        while ((__builtin_constant_p(TASKLET_STATE_RUN) ? constant_test_bit((TASKLET_STATE_RUN),(&(t)->state)) : variable_test_bit((TASKLET_STATE_RUN),(&(t)->state)))) { __asm__ __volatile__("": : :"memory"); }
}
extern void __tasklet_schedule(struct tasklet_struct *t) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) void tasklet_schedule(struct tasklet_struct *t)
{
        if (!test_and_set_bit(TASKLET_STATE_SCHED, &t->state))
                __tasklet_schedule(t);
}
extern void __tasklet_hi_schedule(struct tasklet_struct *t) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) void tasklet_hi_schedule(struct tasklet_struct *t)
{
        if (!test_and_set_bit(TASKLET_STATE_SCHED, &t->state))
                __tasklet_hi_schedule(t);
}
static inline __attribute__((always_inline)) void tasklet_disable_nosync(struct tasklet_struct *t)
{
        atomic_inc(&t->count);
        __asm__ __volatile__("": : :"memory");
}
static inline __attribute__((always_inline)) void tasklet_disable(struct tasklet_struct *t)
{
        tasklet_disable_nosync(t);
        tasklet_unlock_wait(t);
        asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "mfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
}
static inline __attribute__((always_inline)) void tasklet_enable(struct tasklet_struct *t)
{
        __asm__ __volatile__("": : :"memory");
        atomic_dec(&t->count);
}
static inline __attribute__((always_inline)) void tasklet_hi_enable(struct tasklet_struct *t)
{
        __asm__ __volatile__("": : :"memory");
        atomic_dec(&t->count);
}
extern void tasklet_kill(struct tasklet_struct *t);
extern void tasklet_kill_immediate(struct tasklet_struct *t, unsigned int cpu);
extern void tasklet_init(struct tasklet_struct *t,
                         void (*func)(unsigned long), unsigned long data);
extern unsigned long probe_irq_on(void);
extern int probe_irq_off(unsigned long);
extern unsigned int probe_irq_mask(unsigned long);
extern spinlock_t __rcuref_hash[];
static inline __attribute__((always_inline)) void rcuref_inc(atomic_t *rcuref)
{
        unsigned long flags;
        flags = _spin_lock_irqsave((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]));
        rcuref->counter += 1;
        _spin_unlock_irqrestore((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]), flags);
}
static inline __attribute__((always_inline)) void rcuref_dec(atomic_t *rcuref)
{
        unsigned long flags;
        flags = _spin_lock_irqsave((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]));
        rcuref->counter -= 1;
        _spin_unlock_irqrestore((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]), flags);
}
static inline __attribute__((always_inline)) int rcuref_dec_and_test(atomic_t *rcuref)
{
        unsigned long flags;
        flags = _spin_lock_irqsave((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]));
        rcuref->counter--;
        if (!rcuref->counter) {
                _spin_unlock_irqrestore((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]), flags);
                return 1;
        } else {
                _spin_unlock_irqrestore((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]), flags);
                return 0;
        }
}
static inline __attribute__((always_inline)) int rcuref_inc_lf(atomic_t *rcuref)
{
        int ret;
        unsigned long flags;
        flags = _spin_lock_irqsave((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]));
        if (rcuref->counter)
                ret = rcuref->counter++;
        else
                ret = 0;
        _spin_unlock_irqrestore((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]), flags);
        return ret;
}
struct files_stat_struct {
        int nr_files;
        int nr_free_files;
        int max_files;
};
extern struct files_stat_struct files_stat;
struct inodes_stat_t {
        int nr_inodes;
        int nr_unused;
        int dummy[5];
};
extern struct inodes_stat_t inodes_stat;
extern int leases_enable, lease_break_time;
extern int dir_notify_enable;
static inline __attribute__((always_inline)) int old_valid_dev(dev_t dev)
{
        return ((unsigned int) ((dev) >> 20)) < 256 && ((unsigned int) ((dev) & ((1U << 20) - 1))) < 256;
}
static inline __attribute__((always_inline)) u16 old_encode_dev(dev_t dev)
{
        return (((unsigned int) ((dev) >> 20)) << 8) | ((unsigned int) ((dev) & ((1U << 20) - 1)));
}
static inline __attribute__((always_inline)) dev_t old_decode_dev(u16 val)
{
        return ((((val >> 8) & 255) << 20) | (val & 255));
}
static inline __attribute__((always_inline)) int new_valid_dev(dev_t dev)
{
        return 1;
}
static inline __attribute__((always_inline)) u32 new_encode_dev(dev_t dev)
{
        unsigned major = ((unsigned int) ((dev) >> 20));
        unsigned minor = ((unsigned int) ((dev) & ((1U << 20) - 1)));
        return (minor & 0xff) | (major << 8) | ((minor & ~0xff) << 12);
}
static inline __attribute__((always_inline)) dev_t new_decode_dev(u32 dev)
{
        unsigned major = (dev & 0xfff00) >> 8;
        unsigned minor = (dev & 0xff) | ((dev >> 12) & 0xfff00);
        return (((major) << 20) | (minor));
}
static inline __attribute__((always_inline)) int huge_valid_dev(dev_t dev)
{
        return 1;
}
static inline __attribute__((always_inline)) u64 huge_encode_dev(dev_t dev)
{
        return new_encode_dev(dev);
}
static inline __attribute__((always_inline)) dev_t huge_decode_dev(u64 dev)
{
        return new_decode_dev(dev);
}
static inline __attribute__((always_inline)) int sysv_valid_dev(dev_t dev)
{
        return ((unsigned int) ((dev) >> 20)) < (1<<14) && ((unsigned int) ((dev) & ((1U << 20) - 1))) < (1<<18);
}
static inline __attribute__((always_inline)) u32 sysv_encode_dev(dev_t dev)
{
        return ((unsigned int) ((dev) & ((1U << 20) - 1))) | (((unsigned int) ((dev) >> 20)) << 18);
}
static inline __attribute__((always_inline)) unsigned sysv_major(u32 dev)
{
        return (dev >> 18) & 0x3fff;
}
static inline __attribute__((always_inline)) unsigned sysv_minor(u32 dev)
{
        return dev & 0x3ffff;
}
struct rcu_head {
        struct rcu_head *next;
        void (*func)(struct rcu_head *head);
};
struct rcu_ctrlblk {
        long cur;
        long completed;
        int next_pending;
} __attribute__((__aligned__(1 << (7))));
static inline __attribute__((always_inline)) int rcu_batch_before(long a, long b)
{
        return (a - b) < 0;
}
static inline __attribute__((always_inline)) int rcu_batch_after(long a, long b)
{
        return (a - b) > 0;
}
struct rcu_data {
        long quiescbatch;
        int passed_quiesc;
        int qs_pending;
        long batch;
        struct rcu_head *nxtlist;
        struct rcu_head **nxttail;
        long count;
        struct rcu_head *curlist;
        struct rcu_head **curtail;
        struct rcu_head *donelist;
        struct rcu_head **donetail;
        int cpu;
};
extern __typeof__(struct rcu_data) per_cpu__rcu_data;
extern __typeof__(struct rcu_data) per_cpu__rcu_bh_data;
extern struct rcu_ctrlblk rcu_ctrlblk;
extern struct rcu_ctrlblk rcu_bh_ctrlblk;
static inline __attribute__((always_inline)) void rcu_qsctr_inc(int cpu)
{
        struct rcu_data *rdp = &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__rcu_data)); (typeof(&per_cpu__rcu_data)) (__ptr + (__per_cpu_offset[cpu])); }));
        rdp->passed_quiesc = 1;
}
static inline __attribute__((always_inline)) void rcu_bh_qsctr_inc(int cpu)
{
        struct rcu_data *rdp = &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__rcu_bh_data)); (typeof(&per_cpu__rcu_bh_data)) (__ptr + (__per_cpu_offset[cpu])); }));
        rdp->passed_quiesc = 1;
}
static inline __attribute__((always_inline)) int __rcu_pending(struct rcu_ctrlblk *rcp,
                                                struct rcu_data *rdp)
{
        if (rdp->curlist && !rcu_batch_before(rcp->completed, rdp->batch))
                return 1;
        if (!rdp->curlist && rdp->nxtlist)
                return 1;
        if (rdp->donelist)
                return 1;
        if (rdp->quiescbatch != rcp->cur || rdp->qs_pending)
                return 1;
        return 0;
}
static inline __attribute__((always_inline)) int rcu_pending(int cpu)
{
        return __rcu_pending(&rcu_ctrlblk, &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__rcu_data)); (typeof(&per_cpu__rcu_data)) (__ptr + (__per_cpu_offset[cpu])); }))) ||
                __rcu_pending(&rcu_bh_ctrlblk, &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__rcu_bh_data)); (typeof(&per_cpu__rcu_bh_data)) (__ptr + (__per_cpu_offset[cpu])); })));
}
extern void rcu_init(void);
extern void rcu_check_callbacks(int cpu, int user);
extern void rcu_restart_cpu(int cpu);
extern void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head)) __attribute__((regparm(3)));
extern void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *head)) __attribute__((regparm(3)));
extern void synchronize_kernel(void);
extern void synchronize_rcu(void);
void synchronize_idle(void);
struct nameidata;
struct vfsmount;
struct qstr {
        unsigned int hash;
        unsigned int len;
        const unsigned char *name;
};
struct dentry_stat_t {
        int nr_dentry;
        int nr_unused;
        int age_limit;
        int want_pages;
        int dummy[2];
};
extern struct dentry_stat_t dentry_stat;
static inline __attribute__((always_inline)) unsigned long
partial_name_hash(unsigned long c, unsigned long prevhash)
{
        return (prevhash + (c << 4) + (c >> 4)) * 11;
}
static inline __attribute__((always_inline)) unsigned long end_name_hash(unsigned long hash)
{
        return (unsigned int) hash;
}
static inline __attribute__((always_inline)) unsigned int
full_name_hash(const unsigned char *name, unsigned int len)
{
        unsigned long hash = 0;
        while (len--)
                hash = partial_name_hash(*name++, hash);
        return end_name_hash(hash);
}
struct dcookie_struct;
struct dentry {
        atomic_t d_count;
        unsigned int d_flags;
        spinlock_t d_lock;
        struct inode *d_inode;
        struct hlist_node d_hash;
        struct dentry *d_parent;
        struct qstr d_name;
        struct list_head d_lru;
        struct list_head d_child;
        struct list_head d_subdirs;
        struct list_head d_alias;
        unsigned long d_time;
        struct dentry_operations *d_op;
        struct super_block *d_sb;
        void *d_fsdata;
        struct rcu_head d_rcu;
        struct dcookie_struct *d_cookie;
        int d_mounted;
        unsigned char d_iname[36];
};
struct dentry_operations {
        int (*d_revalidate)(struct dentry *, struct nameidata *);
        int (*d_hash) (struct dentry *, struct qstr *);
        int (*d_compare) (struct dentry *, struct qstr *, struct qstr *);
        int (*d_delete)(struct dentry *);
        void (*d_release)(struct dentry *);
        void (*d_iput)(struct dentry *, struct inode *);
};
extern spinlock_t dcache_lock;
static inline __attribute__((always_inline)) void __d_drop(struct dentry *dentry)
{
        if (!(dentry->d_flags & 0x0010)) {
                dentry->d_flags |= 0x0010;
                hlist_del_rcu(&dentry->d_hash);
        }
}
static inline __attribute__((always_inline)) void d_drop(struct dentry *dentry)
{
        _spin_lock(&dcache_lock);
        _spin_lock(&dentry->d_lock);
        __d_drop(dentry);
        _spin_unlock(&dentry->d_lock);
        _spin_unlock(&dcache_lock);
}
static inline __attribute__((always_inline)) int dname_external(struct dentry *dentry)
{
        return dentry->d_name.name != dentry->d_iname;
}
extern void d_instantiate(struct dentry *, struct inode *);
extern struct dentry * d_instantiate_unique(struct dentry *, struct inode *);
extern void d_delete(struct dentry *);
extern struct dentry * d_alloc(struct dentry *, const struct qstr *);
extern struct dentry * d_alloc_anon(struct inode *);
extern struct dentry * d_splice_alias(struct inode *, struct dentry *);
extern void shrink_dcache_sb(struct super_block *);
extern void shrink_dcache_parent(struct dentry *);
extern void shrink_dcache_anon(struct hlist_head *);
extern int d_invalidate(struct dentry *);
extern struct dentry * d_alloc_root(struct inode *);
extern void d_genocide(struct dentry *);
extern struct dentry *d_find_alias(struct inode *);
extern void d_prune_aliases(struct inode *);
extern int have_submounts(struct dentry *);
extern void d_rehash(struct dentry *);
static inline __attribute__((always_inline)) void d_add(struct dentry *entry, struct inode *inode)
{
        d_instantiate(entry, inode);
        d_rehash(entry);
}
static inline __attribute__((always_inline)) struct dentry *d_add_unique(struct dentry *entry, struct inode *inode)
{
        struct dentry *res;
        res = d_instantiate_unique(entry, inode);
        d_rehash(res != ((void *)0) ? res : entry);
        return res;
}
extern void d_move(struct dentry *, struct dentry *);
extern struct dentry * d_lookup(struct dentry *, struct qstr *);
extern struct dentry * __d_lookup(struct dentry *, struct qstr *);
extern int d_validate(struct dentry *, struct dentry *);
extern char * d_path(struct dentry *, struct vfsmount *, char *, int);
static inline __attribute__((always_inline)) struct dentry *dget(struct dentry *dentry)
{
        if (dentry) {
                do { if (__builtin_expect(!!((!((&dentry->d_count)->counter))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (294), "i" ("include/linux/dcache.h")); } while(0);
                atomic_inc(&dentry->d_count);
        }
        return dentry;
}
extern struct dentry * dget_locked(struct dentry *);
static inline __attribute__((always_inline)) int d_unhashed(struct dentry *dentry)
{
        return (dentry->d_flags & 0x0010);
}
static inline __attribute__((always_inline)) struct dentry *dget_parent(struct dentry *dentry)
{
        struct dentry *ret;
        _spin_lock(&dentry->d_lock);
        ret = dget(dentry->d_parent);
        _spin_unlock(&dentry->d_lock);
        return ret;
}
extern void dput(struct dentry *);
static inline __attribute__((always_inline)) int d_mountpoint(struct dentry *dentry)
{
        return dentry->d_mounted;
}
extern struct vfsmount *lookup_mnt(struct vfsmount *, struct dentry *);
extern struct dentry *lookup_create(struct nameidata *nd, int is_dir);
extern int sysctl_vfs_cache_pressure;
struct radix_tree_root {
        unsigned int height;
        unsigned int gfp_mask;
        struct radix_tree_node *rnode;
};
int radix_tree_insert(struct radix_tree_root *, unsigned long, void *);
void *radix_tree_lookup(struct radix_tree_root *, unsigned long);
void *radix_tree_delete(struct radix_tree_root *, unsigned long);
unsigned int
radix_tree_gang_lookup(struct radix_tree_root *root, void **results,
                        unsigned long first_index, unsigned int max_items);
int radix_tree_preload(gfp_t gfp_mask);
void radix_tree_init(void);
void *radix_tree_tag_set(struct radix_tree_root *root,
                        unsigned long index, int tag);
void *radix_tree_tag_clear(struct radix_tree_root *root,
                        unsigned long index, int tag);
int radix_tree_tag_get(struct radix_tree_root *root,
                        unsigned long index, int tag);
unsigned int
radix_tree_gang_lookup_tag(struct radix_tree_root *root, void **results,
                unsigned long first_index, unsigned int max_items, int tag);
int radix_tree_tagged(struct radix_tree_root *root, int tag);
static inline __attribute__((always_inline)) void radix_tree_preload_end(void)
{
        do { } while (0);
}
struct iovec;
struct nameidata;
struct kiocb;
struct pipe_inode_info;
struct poll_table_struct;
struct kstatfs;
struct vm_area_struct;
struct vfsmount;
extern void update_atime (struct inode *);
extern void __attribute__ ((__section__ (".init.text"))) inode_init(unsigned long);
extern void __attribute__ ((__section__ (".init.text"))) inode_init_early(void);
extern void __attribute__ ((__section__ (".init.text"))) mnt_init(unsigned long);
extern void __attribute__ ((__section__ (".init.text"))) files_init(unsigned long);
struct buffer_head;
typedef int (get_block_t)(struct inode *inode, sector_t iblock,
                        struct buffer_head *bh_result, int create);
typedef int (get_blocks_t)(struct inode *inode, sector_t iblock,
                        unsigned long max_blocks,
                        struct buffer_head *bh_result, int create);
typedef void (dio_iodone_t)(struct kiocb *iocb, loff_t offset,
                        ssize_t bytes, void *private);
struct iattr {
        unsigned int ia_valid;
        umode_t ia_mode;
        uid_t ia_uid;
        gid_t ia_gid;
        loff_t ia_size;
        struct timespec ia_atime;
        struct timespec ia_mtime;
        struct timespec ia_ctime;
};
typedef __kernel_uid32_t qid_t;
typedef __u64 qsize_t;
extern spinlock_t dq_data_lock;
struct if_dqblk {
        __u64 dqb_bhardlimit;
        __u64 dqb_bsoftlimit;
        __u64 dqb_curspace;
        __u64 dqb_ihardlimit;
        __u64 dqb_isoftlimit;
        __u64 dqb_curinodes;
        __u64 dqb_btime;
        __u64 dqb_itime;
        __u32 dqb_valid;
};
struct if_dqinfo {
        __u64 dqi_bgrace;
        __u64 dqi_igrace;
        __u32 dqi_flags;
        __u32 dqi_valid;
};
typedef struct fs_disk_quota {
        __s8 d_version;
        __s8 d_flags;
        __u16 d_fieldmask;
        __u32 d_id;
        __u64 d_blk_hardlimit;
        __u64 d_blk_softlimit;
        __u64 d_ino_hardlimit;
        __u64 d_ino_softlimit;
        __u64 d_bcount;
        __u64 d_icount;
        __s32 d_itimer;
        __s32 d_btimer;
        __u16 d_iwarns;
        __u16 d_bwarns;
        __s32 d_padding2;
        __u64 d_rtb_hardlimit;
        __u64 d_rtb_softlimit;
        __u64 d_rtbcount;
        __s32 d_rtbtimer;
        __u16 d_rtbwarns;
        __s16 d_padding3;
        char d_padding4[8];
} fs_disk_quota_t;
typedef struct fs_qfilestat {
        __u64 qfs_ino;
        __u64 qfs_nblks;
        __u32 qfs_nextents;
} fs_qfilestat_t;
typedef struct fs_quota_stat {
        __s8 qs_version;
        __u16 qs_flags;
        __s8 qs_pad;
        fs_qfilestat_t qs_uquota;
        fs_qfilestat_t qs_gquota;
        __u32 qs_incoredqs;
        __s32 qs_btimelimit;
        __s32 qs_itimelimit;
        __s32 qs_rtbtimelimit;
        __u16 qs_bwarnlimit;
        __u16 qs_iwarnlimit;
} fs_quota_stat_t;
struct v1_mem_dqinfo {
};
struct v2_mem_dqinfo {
        unsigned int dqi_blocks;
        unsigned int dqi_free_blk;
        unsigned int dqi_free_entry;
};
struct mem_dqblk {
        __u32 dqb_bhardlimit;
        __u32 dqb_bsoftlimit;
        qsize_t dqb_curspace;
        __u32 dqb_ihardlimit;
        __u32 dqb_isoftlimit;
        __u32 dqb_curinodes;
        time_t dqb_btime;
        time_t dqb_itime;
};
struct quota_format_type;
struct mem_dqinfo {
        struct quota_format_type *dqi_format;
        struct list_head dqi_dirty_list;
        unsigned long dqi_flags;
        unsigned int dqi_bgrace;
        unsigned int dqi_igrace;
        union {
                struct v1_mem_dqinfo v1_i;
                struct v2_mem_dqinfo v2_i;
        } u;
};
struct super_block;
extern void mark_info_dirty(struct super_block *sb, int type);
struct dqstats {
        int lookups;
        int drops;
        int reads;
        int writes;
        int cache_hits;
        int allocated_dquots;
        int free_dquots;
        int syncs;
};
extern struct dqstats dqstats;
struct dquot {
        struct hlist_node dq_hash;
        struct list_head dq_inuse;
        struct list_head dq_free;
        struct list_head dq_dirty;
        struct semaphore dq_lock;
        atomic_t dq_count;
        wait_queue_head_t dq_wait_unused;
        struct super_block *dq_sb;
        unsigned int dq_id;
        loff_t dq_off;
        unsigned long dq_flags;
        short dq_type;
        struct mem_dqblk dq_dqb;
};
struct quota_format_ops {
        int (*check_quota_file)(struct super_block *sb, int type);
        int (*read_file_info)(struct super_block *sb, int type);
        int (*write_file_info)(struct super_block *sb, int type);
        int (*free_file_info)(struct super_block *sb, int type);
        int (*read_dqblk)(struct dquot *dquot);
        int (*commit_dqblk)(struct dquot *dquot);
        int (*release_dqblk)(struct dquot *dquot);
};
struct dquot_operations {
        int (*initialize) (struct inode *, int);
        int (*drop) (struct inode *);
        int (*alloc_space) (struct inode *, qsize_t, int);
        int (*alloc_inode) (const struct inode *, unsigned long);
        int (*free_space) (struct inode *, qsize_t);
        int (*free_inode) (const struct inode *, unsigned long);
        int (*transfer) (struct inode *, struct iattr *);
        int (*write_dquot) (struct dquot *);
        int (*acquire_dquot) (struct dquot *);
        int (*release_dquot) (struct dquot *);
        int (*mark_dirty) (struct dquot *);
        int (*write_info) (struct super_block *, int);
};
struct quotactl_ops {
        int (*quota_on)(struct super_block *, int, int, char *);
        int (*quota_off)(struct super_block *, int);
        int (*quota_sync)(struct super_block *, int);
        int (*get_info)(struct super_block *, int, struct if_dqinfo *);
        int (*set_info)(struct super_block *, int, struct if_dqinfo *);
        int (*get_dqblk)(struct super_block *, int, qid_t, struct if_dqblk *);
        int (*set_dqblk)(struct super_block *, int, qid_t, struct if_dqblk *);
        int (*get_xstate)(struct super_block *, struct fs_quota_stat *);
        int (*set_xstate)(struct super_block *, unsigned int, int);
        int (*get_xquota)(struct super_block *, int, qid_t, struct fs_disk_quota *);
        int (*set_xquota)(struct super_block *, int, qid_t, struct fs_disk_quota *);
};
struct quota_format_type {
        int qf_fmt_id;
        struct quota_format_ops *qf_ops;
        struct module *qf_owner;
        struct quota_format_type *qf_next;
};
struct quota_info {
        unsigned int flags;
        struct semaphore dqio_sem;
        struct semaphore dqonoff_sem;
        struct rw_semaphore dqptr_sem;
        struct inode *files[2];
        struct vfsmount *mnt[2];
        struct mem_dqinfo info[2];
        struct quota_format_ops *ops[2];
};
int mark_dquot_dirty(struct dquot *dquot);
int register_quota_format(struct quota_format_type *fmt);
void unregister_quota_format(struct quota_format_type *fmt);
struct quota_module_name {
        int qm_fmt_id;
        char *qm_mod_name;
};
struct page;
struct address_space;
struct writeback_control;
struct address_space_operations {
        int (*writepage)(struct page *page, struct writeback_control *wbc);
        int (*readpage)(struct file *, struct page *);
        int (*sync_page)(struct page *);
        int (*writepages)(struct address_space *, struct writeback_control *);
        int (*set_page_dirty)(struct page *page);
        int (*readpages)(struct file *filp, struct address_space *mapping,
                        struct list_head *pages, unsigned nr_pages);
        int (*prepare_write)(struct file *, struct page *, unsigned, unsigned);
        int (*commit_write)(struct file *, struct page *, unsigned, unsigned);
        sector_t (*bmap)(struct address_space *, sector_t);
        int (*invalidatepage) (struct page *, unsigned long);
        int (*releasepage) (struct page *, int);
        ssize_t (*direct_IO)(int, struct kiocb *, const struct iovec *iov,
                        loff_t offset, unsigned long nr_segs);
        struct page* (*get_xip_page)(struct address_space *, sector_t,
                        int);
};
struct backing_dev_info;
struct address_space {
        struct inode *host;
        struct radix_tree_root page_tree;
        rwlock_t tree_lock;
        unsigned int i_mmap_writable;
        struct prio_tree_root i_mmap;
        struct list_head i_mmap_nonlinear;
        spinlock_t i_mmap_lock;
        unsigned int truncate_count;
        unsigned long nrpages;
        unsigned long writeback_index;
        struct address_space_operations *a_ops;
        unsigned long flags;
        struct backing_dev_info *backing_dev_info;
        spinlock_t private_lock;
        struct list_head private_list;
        struct address_space *assoc_mapping;
} __attribute__((aligned(sizeof(long))));
struct block_device {
        dev_t bd_dev;
        struct inode * bd_inode;
        int bd_openers;
        struct semaphore bd_sem;
        struct semaphore bd_mount_sem;
        struct list_head bd_inodes;
        void * bd_holder;
        int bd_holders;
        struct block_device * bd_contains;
        unsigned bd_block_size;
        struct hd_struct * bd_part;
        unsigned bd_part_count;
        int bd_invalidated;
        struct gendisk * bd_disk;
        struct list_head bd_list;
        struct backing_dev_info *bd_inode_backing_dev_info;
        unsigned long bd_private;
};
int mapping_tagged(struct address_space *mapping, int tag);
static inline __attribute__((always_inline)) int mapping_mapped(struct address_space *mapping)
{
        return !prio_tree_empty(&mapping->i_mmap) ||
                !list_empty(&mapping->i_mmap_nonlinear);
}
static inline __attribute__((always_inline)) int mapping_writably_mapped(struct address_space *mapping)
{
        return mapping->i_mmap_writable != 0;
}
struct inode {
        struct hlist_node i_hash;
        struct list_head i_list;
        struct list_head i_sb_list;
        struct list_head i_dentry;
        unsigned long i_ino;
        atomic_t i_count;
        umode_t i_mode;
        unsigned int i_nlink;
        uid_t i_uid;
        gid_t i_gid;
        dev_t i_rdev;
        loff_t i_size;
        struct timespec i_atime;
        struct timespec i_mtime;
        struct timespec i_ctime;
        unsigned int i_blkbits;
        unsigned long i_blksize;
        unsigned long i_version;
        unsigned long i_blocks;
        unsigned short i_bytes;
        spinlock_t i_lock;
        struct semaphore i_sem;
        struct rw_semaphore i_alloc_sem;
        struct inode_operations *i_op;
        struct file_operations *i_fop;
        struct super_block *i_sb;
        struct file_lock *i_flock;
        struct address_space *i_mapping;
        struct address_space i_data;
        struct dquot *i_dquot[2];
        struct list_head i_devices;
        struct pipe_inode_info *i_pipe;
        struct block_device *i_bdev;
        struct cdev *i_cdev;
        int i_cindex;
        __u32 i_generation;
        unsigned long i_dnotify_mask;
        struct dnotify_struct *i_dnotify;
        struct list_head inotify_watches;
        struct semaphore inotify_sem;
        unsigned long i_state;
        unsigned long dirtied_when;
        unsigned int i_flags;
        atomic_t i_writecount;
        void *i_security;
        union {
                void *generic_ip;
        } u;
        seqcount_t i_size_seqcount;
};
static inline __attribute__((always_inline)) loff_t i_size_read(struct inode *inode)
{
        loff_t i_size;
        unsigned int seq;
        do {
                seq = read_seqcount_begin(&inode->i_size_seqcount);
                i_size = inode->i_size;
        } while (read_seqcount_retry(&inode->i_size_seqcount, seq));
        return i_size;
}
static inline __attribute__((always_inline)) void i_size_write(struct inode *inode, loff_t i_size)
{
        write_seqcount_begin(&inode->i_size_seqcount);
        inode->i_size = i_size;
        write_seqcount_end(&inode->i_size_seqcount);
}
static inline __attribute__((always_inline)) unsigned iminor(struct inode *inode)
{
        return ((unsigned int) ((inode->i_rdev) & ((1U << 20) - 1)));
}
static inline __attribute__((always_inline)) unsigned imajor(struct inode *inode)
{
        return ((unsigned int) ((inode->i_rdev) >> 20));
}
extern struct block_device *I_BDEV(struct inode *inode);
struct fown_struct {
        rwlock_t lock;
        int pid;
        uid_t uid, euid;
        void *security;
        int signum;
};
struct file_ra_state {
        unsigned long start;
        unsigned long size;
        unsigned long flags;
        unsigned long cache_hit;
        unsigned long prev_page;
        unsigned long ahead_start;
        unsigned long ahead_size;
        unsigned long ra_pages;
        unsigned long mmap_hit;
        unsigned long mmap_miss;
};
struct file {
        struct list_head f_list;
        struct dentry *f_dentry;
        struct vfsmount *f_vfsmnt;
        struct file_operations *f_op;
        atomic_t f_count;
        unsigned int f_flags;
        mode_t f_mode;
        loff_t f_pos;
        struct fown_struct f_owner;
        unsigned int f_uid, f_gid;
        struct file_ra_state f_ra;
        unsigned long f_version;
        void *f_security;
        void *private_data;
        struct list_head f_ep_links;
        spinlock_t f_ep_lock;
        struct address_space *f_mapping;
        struct rcu_head f_rcuhead;
};
extern spinlock_t files_lock;
typedef struct files_struct *fl_owner_t;
struct file_lock_operations {
        void (*fl_insert)(struct file_lock *);
        void (*fl_remove)(struct file_lock *);
        void (*fl_copy_lock)(struct file_lock *, struct file_lock *);
        void (*fl_release_private)(struct file_lock *);
};
struct lock_manager_operations {
        int (*fl_compare_owner)(struct file_lock *, struct file_lock *);
        void (*fl_notify)(struct file_lock *);
        void (*fl_copy_lock)(struct file_lock *, struct file_lock *);
        void (*fl_release_private)(struct file_lock *);
        void (*fl_break)(struct file_lock *);
        int (*fl_mylease)(struct file_lock *, struct file_lock *);
        int (*fl_change)(struct file_lock **, int);
};
typedef u32 rpc_authflavor_t;
enum rpc_auth_flavors {
        RPC_AUTH_NULL = 0,
        RPC_AUTH_UNIX = 1,
        RPC_AUTH_SHORT = 2,
        RPC_AUTH_DES = 3,
        RPC_AUTH_KRB = 4,
        RPC_AUTH_GSS = 6,
        RPC_AUTH_MAXFLAVOR = 8,
        RPC_AUTH_GSS_KRB5 = 390003,
        RPC_AUTH_GSS_KRB5I = 390004,
        RPC_AUTH_GSS_KRB5P = 390005,
        RPC_AUTH_GSS_LKEY = 390006,
        RPC_AUTH_GSS_LKEYI = 390007,
        RPC_AUTH_GSS_LKEYP = 390008,
        RPC_AUTH_GSS_SPKM = 390009,
        RPC_AUTH_GSS_SPKMI = 390010,
        RPC_AUTH_GSS_SPKMP = 390011,
};
enum rpc_msg_type {
        RPC_CALL = 0,
        RPC_REPLY = 1
};
enum rpc_reply_stat {
        RPC_MSG_ACCEPTED = 0,
        RPC_MSG_DENIED = 1
};
enum rpc_accept_stat {
        RPC_SUCCESS = 0,
        RPC_PROG_UNAVAIL = 1,
        RPC_PROG_MISMATCH = 2,
        RPC_PROC_UNAVAIL = 3,
        RPC_GARBAGE_ARGS = 4,
        RPC_SYSTEM_ERR = 5
};
enum rpc_reject_stat {
        RPC_MISMATCH = 0,
        RPC_AUTH_ERROR = 1
};
enum rpc_auth_stat {
        RPC_AUTH_OK = 0,
        RPC_AUTH_BADCRED = 1,
        RPC_AUTH_REJECTEDCRED = 2,
        RPC_AUTH_BADVERF = 3,
        RPC_AUTH_REJECTEDVERF = 4,
        RPC_AUTH_TOOWEAK = 5,
        RPCSEC_GSS_CREDPROBLEM = 13,
        RPCSEC_GSS_CTXPROBLEM = 14
};
 enum nfs_stat {
        NFS_OK = 0,
        NFSERR_PERM = 1,
        NFSERR_NOENT = 2,
        NFSERR_IO = 5,
        NFSERR_NXIO = 6,
        NFSERR_EAGAIN = 11,
        NFSERR_ACCES = 13,
        NFSERR_EXIST = 17,
        NFSERR_XDEV = 18,
        NFSERR_NODEV = 19,
        NFSERR_NOTDIR = 20,
        NFSERR_ISDIR = 21,
        NFSERR_INVAL = 22,
        NFSERR_FBIG = 27,
        NFSERR_NOSPC = 28,
        NFSERR_ROFS = 30,
        NFSERR_MLINK = 31,
        NFSERR_OPNOTSUPP = 45,
        NFSERR_NAMETOOLONG = 63,
        NFSERR_NOTEMPTY = 66,
        NFSERR_DQUOT = 69,
        NFSERR_STALE = 70,
        NFSERR_REMOTE = 71,
        NFSERR_WFLUSH = 99,
        NFSERR_BADHANDLE = 10001,
        NFSERR_NOT_SYNC = 10002,
        NFSERR_BAD_COOKIE = 10003,
        NFSERR_NOTSUPP = 10004,
        NFSERR_TOOSMALL = 10005,
        NFSERR_SERVERFAULT = 10006,
        NFSERR_BADTYPE = 10007,
        NFSERR_JUKEBOX = 10008,
        NFSERR_SAME = 10009,
        NFSERR_DENIED = 10010,
        NFSERR_EXPIRED = 10011,
        NFSERR_LOCKED = 10012,
        NFSERR_GRACE = 10013,
        NFSERR_FHEXPIRED = 10014,
        NFSERR_SHARE_DENIED = 10015,
        NFSERR_WRONGSEC = 10016,
        NFSERR_CLID_INUSE = 10017,
        NFSERR_RESOURCE = 10018,
        NFSERR_MOVED = 10019,
        NFSERR_NOFILEHANDLE = 10020,
        NFSERR_MINOR_VERS_MISMATCH = 10021,
        NFSERR_STALE_CLIENTID = 10022,
        NFSERR_STALE_STATEID = 10023,
        NFSERR_OLD_STATEID = 10024,
        NFSERR_BAD_STATEID = 10025,
        NFSERR_BAD_SEQID = 10026,
        NFSERR_NOT_SAME = 10027,
        NFSERR_LOCK_RANGE = 10028,
        NFSERR_SYMLINK = 10029,
        NFSERR_RESTOREFH = 10030,
        NFSERR_LEASE_MOVED = 10031,
        NFSERR_ATTRNOTSUPP = 10032,
        NFSERR_NO_GRACE = 10033,
        NFSERR_RECLAIM_BAD = 10034,
        NFSERR_RECLAIM_CONFLICT = 10035,
        NFSERR_BAD_XDR = 10036,
        NFSERR_LOCKS_HELD = 10037,
        NFSERR_OPENMODE = 10038,
        NFSERR_BADOWNER = 10039,
        NFSERR_BADCHAR = 10040,
        NFSERR_BADNAME = 10041,
        NFSERR_BAD_RANGE = 10042,
        NFSERR_LOCK_NOTSUPP = 10043,
        NFSERR_OP_ILLEGAL = 10044,
        NFSERR_DEADLOCK = 10045,
        NFSERR_FILE_OPEN = 10046,
        NFSERR_ADMIN_REVOKED = 10047,
        NFSERR_CB_PATH_DOWN = 10048,
        NFSERR_REPLAY_ME = 10049
};
enum nfs_ftype {
        NFNON = 0,
        NFREG = 1,
        NFDIR = 2,
        NFBLK = 3,
        NFCHR = 4,
        NFLNK = 5,
        NFSOCK = 6,
        NFBAD = 7,
        NFFIFO = 8
};
struct nfs_fh {
        unsigned short size;
        unsigned char data[128];
};
static inline __attribute__((always_inline)) int nfs_compare_fh(const struct nfs_fh *a, const struct nfs_fh *b)
{
        return a->size != b->size || __builtin_memcmp(a->data, b->data, a->size) != 0;
}
static inline __attribute__((always_inline)) void nfs_copy_fh(struct nfs_fh *target, const struct nfs_fh *source)
{
        target->size = source->size;
        (__builtin_constant_p(source->size) ? __constant_memcpy((target->data),(source->data),(source->size)) : __memcpy((target->data),(source->data),(source->size)));
}
enum nfs3_stable_how {
        NFS_UNSTABLE = 0,
        NFS_DATA_SYNC = 1,
        NFS_FILE_SYNC = 2
};
struct nlm_lockowner;
struct nfs_lock_info {
        u32 state;
        u32 flags;
        struct nlm_lockowner *owner;
};
struct nfs4_lock_state;
struct nfs4_lock_info {
        struct nfs4_lock_state *owner;
};
struct file_lock {
        struct file_lock *fl_next;
        struct list_head fl_link;
        struct list_head fl_block;
        fl_owner_t fl_owner;
        unsigned int fl_pid;
        wait_queue_head_t fl_wait;
        struct file *fl_file;
        unsigned char fl_flags;
        unsigned char fl_type;
        loff_t fl_start;
        loff_t fl_end;
        struct fasync_struct * fl_fasync;
        unsigned long fl_break_time;
        struct file_lock_operations *fl_ops;
        struct lock_manager_operations *fl_lmops;
        union {
                struct nfs_lock_info nfs_fl;
                struct nfs4_lock_info nfs4_fl;
        } fl_u;
};
extern struct list_head file_lock_list;
struct flock {
        short l_type;
        short l_whence;
        off_t l_start;
        off_t l_len;
        pid_t l_pid;
};
struct flock64 {
        short l_type;
        short l_whence;
        loff_t l_start;
        loff_t l_len;
        pid_t l_pid;
};
extern int fcntl_getlk(struct file *, struct flock *);
extern int fcntl_setlk(unsigned int, struct file *, unsigned int,
                        struct flock *);
extern int fcntl_getlk64(struct file *, struct flock64 *);
extern int fcntl_setlk64(unsigned int, struct file *, unsigned int,
                        struct flock64 *);
extern void send_sigio(struct fown_struct *fown, int fd, int band);
extern int fcntl_setlease(unsigned int fd, struct file *filp, long arg);
extern int fcntl_getlease(struct file *filp);
extern void locks_init_lock(struct file_lock *);
extern void locks_copy_lock(struct file_lock *, struct file_lock *);
extern void locks_remove_posix(struct file *, fl_owner_t);
extern void locks_remove_flock(struct file *);
extern struct file_lock *posix_test_lock(struct file *, struct file_lock *);
extern int posix_lock_file(struct file *, struct file_lock *);
extern int posix_lock_file_wait(struct file *, struct file_lock *);
extern void posix_block_lock(struct file_lock *, struct file_lock *);
extern void posix_unblock_lock(struct file *, struct file_lock *);
extern int posix_locks_deadlock(struct file_lock *, struct file_lock *);
extern int flock_lock_file_wait(struct file *filp, struct file_lock *fl);
extern int __break_lease(struct inode *inode, unsigned int flags);
extern void lease_get_mtime(struct inode *, struct timespec *time);
extern int setlease(struct file *, long, struct file_lock **);
extern int lease_modify(struct file_lock **, int);
extern int lock_may_read(struct inode *, loff_t start, unsigned long count);
extern int lock_may_write(struct inode *, loff_t start, unsigned long count);
extern void steal_locks(fl_owner_t from);
struct fasync_struct {
        int magic;
        int fa_fd;
        struct fasync_struct *fa_next;
        struct file *fa_file;
};
extern int fasync_helper(int, struct file *, int, struct fasync_struct **);
extern void kill_fasync(struct fasync_struct **, int, int);
extern void __kill_fasync(struct fasync_struct *, int, int);
extern int f_setown(struct file *filp, unsigned long arg, int force);
extern void f_delown(struct file *filp);
extern int send_sigurg(struct fown_struct *fown);
extern struct list_head super_blocks;
extern spinlock_t sb_lock;
struct super_block {
        struct list_head s_list;
        dev_t s_dev;
        unsigned long s_blocksize;
        unsigned long s_old_blocksize;
        unsigned char s_blocksize_bits;
        unsigned char s_dirt;
        unsigned long long s_maxbytes;
        struct file_system_type *s_type;
        struct super_operations *s_op;
        struct dquot_operations *dq_op;
        struct quotactl_ops *s_qcop;
        struct export_operations *s_export_op;
        unsigned long s_flags;
        unsigned long s_magic;
        struct dentry *s_root;
        struct rw_semaphore s_umount;
        struct semaphore s_lock;
        int s_count;
        int s_syncing;
        int s_need_sync_fs;
        atomic_t s_active;
        void *s_security;
        struct xattr_handler **s_xattr;
        struct list_head s_inodes;
        struct list_head s_dirty;
        struct list_head s_io;
        struct hlist_head s_anon;
        struct list_head s_files;
        struct block_device *s_bdev;
        struct list_head s_instances;
        struct quota_info s_dquot;
        int s_frozen;
        wait_queue_head_t s_wait_unfrozen;
        char s_id[32];
        void *s_fs_info;
        struct semaphore s_vfs_rename_sem;
        u32 s_time_gran;
};
extern struct timespec current_fs_time(struct super_block *sb);
enum {
        SB_UNFROZEN = 0,
        SB_FREEZE_WRITE = 1,
        SB_FREEZE_TRANS = 2,
};
static inline __attribute__((always_inline)) void get_fs_excl(void)
{
        atomic_inc(&get_current()->fs_excl);
}
static inline __attribute__((always_inline)) void put_fs_excl(void)
{
        atomic_dec(&get_current()->fs_excl);
}
static inline __attribute__((always_inline)) int has_fs_excl(void)
{
        return ((&get_current()->fs_excl)->counter);
}
static inline __attribute__((always_inline)) void lock_super(struct super_block * sb)
{
        get_fs_excl();
        down(&sb->s_lock);
}
static inline __attribute__((always_inline)) void unlock_super(struct super_block * sb)
{
        put_fs_excl();
        up(&sb->s_lock);
}
extern int vfs_create(struct inode *, struct dentry *, int, struct nameidata *);
extern int vfs_mkdir(struct inode *, struct dentry *, int);
extern int vfs_mknod(struct inode *, struct dentry *, int, dev_t);
extern int vfs_symlink(struct inode *, struct dentry *, const char *, int);
extern int vfs_link(struct dentry *, struct inode *, struct dentry *);
extern int vfs_rmdir(struct inode *, struct dentry *);
extern int vfs_unlink(struct inode *, struct dentry *);
extern int vfs_rename(struct inode *, struct dentry *, struct inode *, struct dentry *);
extern void dentry_unhash(struct dentry *dentry);
int generic_osync_inode(struct inode *, struct address_space *, int);
typedef int (*filldir_t)(void *, const char *, int, loff_t, ino_t, unsigned);
struct block_device_operations {
        int (*open) (struct inode *, struct file *);
        int (*release) (struct inode *, struct file *);
        int (*ioctl) (struct inode *, struct file *, unsigned, unsigned long);
        long (*unlocked_ioctl) (struct file *, unsigned, unsigned long);
        long (*compat_ioctl) (struct file *, unsigned, unsigned long);
        int (*direct_access) (struct block_device *, sector_t, unsigned long *);
        int (*media_changed) (struct gendisk *);
        int (*revalidate_disk) (struct gendisk *);
        struct module *owner;
};
typedef struct {
        size_t written;
        size_t count;
        union {
                char * buf;
                void *data;
        } arg;
        int error;
} read_descriptor_t;
typedef int (*read_actor_t)(read_descriptor_t *, struct page *, unsigned long, unsigned long);
struct file_operations {
        struct module *owner;
        loff_t (*llseek) (struct file *, loff_t, int);
        ssize_t (*read) (struct file *, char *, size_t, loff_t *);
        ssize_t (*aio_read) (struct kiocb *, char *, size_t, loff_t);
        ssize_t (*write) (struct file *, const char *, size_t, loff_t *);
        ssize_t (*aio_write) (struct kiocb *, const char *, size_t, loff_t);
        int (*readdir) (struct file *, void *, filldir_t);
        unsigned int (*poll) (struct file *, struct poll_table_struct *);
        int (*ioctl) (struct inode *, struct file *, unsigned int, unsigned long);
        long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
        long (*compat_ioctl) (struct file *, unsigned int, unsigned long);
        int (*mmap) (struct file *, struct vm_area_struct *);
        int (*open) (struct inode *, struct file *);
        int (*flush) (struct file *);
        int (*release) (struct inode *, struct file *);
        int (*fsync) (struct file *, struct dentry *, int datasync);
        int (*aio_fsync) (struct kiocb *, int datasync);
        int (*fasync) (int, struct file *, int);
        int (*lock) (struct file *, int, struct file_lock *);
        ssize_t (*readv) (struct file *, const struct iovec *, unsigned long, loff_t *);
        ssize_t (*writev) (struct file *, const struct iovec *, unsigned long, loff_t *);
        ssize_t (*sendfile) (struct file *, loff_t *, size_t, read_actor_t, void *);
        ssize_t (*sendpage) (struct file *, struct page *, int, size_t, loff_t *, int);
        unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
        int (*check_flags)(int);
        int (*dir_notify)(struct file *filp, unsigned long arg);
        int (*flock) (struct file *, int, struct file_lock *);
};
struct inode_operations {
        int (*create) (struct inode *,struct dentry *,int, struct nameidata *);
        struct dentry * (*lookup) (struct inode *,struct dentry *, struct nameidata *);
        int (*link) (struct dentry *,struct inode *,struct dentry *);
        int (*unlink) (struct inode *,struct dentry *);
        int (*symlink) (struct inode *,struct dentry *,const char *);
        int (*mkdir) (struct inode *,struct dentry *,int);
        int (*rmdir) (struct inode *,struct dentry *);
        int (*mknod) (struct inode *,struct dentry *,int,dev_t);
        int (*rename) (struct inode *, struct dentry *,
                        struct inode *, struct dentry *);
        int (*readlink) (struct dentry *, char *,int);
        void * (*follow_link) (struct dentry *, struct nameidata *);
        void (*put_link) (struct dentry *, struct nameidata *, void *);
        void (*truncate) (struct inode *);
        int (*permission) (struct inode *, int, struct nameidata *);
        int (*setattr) (struct dentry *, struct iattr *);
        int (*getattr) (struct vfsmount *mnt, struct dentry *, struct kstat *);
        int (*setxattr) (struct dentry *, const char *,const void *,size_t,int);
        ssize_t (*getxattr) (struct dentry *, const char *, void *, size_t);
        ssize_t (*listxattr) (struct dentry *, char *, size_t);
        int (*removexattr) (struct dentry *, const char *);
};
struct seq_file;
extern ssize_t vfs_read(struct file *, char *, size_t, loff_t *);
extern ssize_t vfs_write(struct file *, const char *, size_t, loff_t *);
extern ssize_t vfs_readv(struct file *, const struct iovec *,
                unsigned long, loff_t *);
extern ssize_t vfs_writev(struct file *, const struct iovec *,
                unsigned long, loff_t *);
struct super_operations {
        struct inode *(*alloc_inode)(struct super_block *sb);
        void (*destroy_inode)(struct inode *);
        void (*read_inode) (struct inode *);
        void (*dirty_inode) (struct inode *);
        int (*write_inode) (struct inode *, int);
        void (*put_inode) (struct inode *);
        void (*drop_inode) (struct inode *);
        void (*delete_inode) (struct inode *);
        void (*put_super) (struct super_block *);
        void (*write_super) (struct super_block *);
        int (*sync_fs)(struct super_block *sb, int wait);
        void (*write_super_lockfs) (struct super_block *);
        void (*unlockfs) (struct super_block *);
        int (*statfs) (struct super_block *, struct kstatfs *);
        int (*remount_fs) (struct super_block *, int *, char *);
        void (*clear_inode) (struct inode *);
        void (*umount_begin) (struct super_block *);
        int (*show_options)(struct seq_file *, struct vfsmount *);
        ssize_t (*quota_read)(struct super_block *, int, char *, size_t, loff_t);
        ssize_t (*quota_write)(struct super_block *, int, const char *, size_t, loff_t);
};
extern void __mark_inode_dirty(struct inode *, int);
static inline __attribute__((always_inline)) void mark_inode_dirty(struct inode *inode)
{
        __mark_inode_dirty(inode, (1 | 2 | 4));
}
static inline __attribute__((always_inline)) void mark_inode_dirty_sync(struct inode *inode)
{
        __mark_inode_dirty(inode, 1);
}
static inline __attribute__((always_inline)) void touch_atime(struct vfsmount *mnt, struct dentry *dentry)
{
        update_atime(dentry->d_inode);
}
static inline __attribute__((always_inline)) void file_accessed(struct file *file)
{
        if (!(file->f_flags & 01000000))
                touch_atime(file->f_vfsmnt, file->f_dentry);
}
int sync_inode(struct inode *inode, struct writeback_control *wbc);
struct export_operations {
        struct dentry *(*decode_fh)(struct super_block *sb, __u32 *fh, int fh_len, int fh_type,
                         int (*acceptable)(void *context, struct dentry *de),
                         void *context);
        int (*encode_fh)(struct dentry *de, __u32 *fh, int *max_len,
                         int connectable);
        int (*get_name)(struct dentry *parent, char *name,
                        struct dentry *child);
        struct dentry * (*get_parent)(struct dentry *child);
        struct dentry * (*get_dentry)(struct super_block *sb, void *inump);
        struct dentry * (*find_exported_dentry)(
                struct super_block *sb, void *obj, void *parent,
                int (*acceptable)(void *context, struct dentry *de),
                void *context);
};
extern struct dentry *
find_exported_dentry(struct super_block *sb, void *obj, void *parent,
                     int (*acceptable)(void *context, struct dentry *de),
                     void *context);
struct file_system_type {
        const char *name;
        int fs_flags;
        struct super_block *(*get_sb) (struct file_system_type *, int,
                                       const char *, void *);
        void (*kill_sb) (struct super_block *);
        struct module *owner;
        struct file_system_type * next;
        struct list_head fs_supers;
};
struct super_block *get_sb_bdev(struct file_system_type *fs_type,
        int flags, const char *dev_name, void *data,
        int (*fill_super)(struct super_block *, void *, int));
struct super_block *get_sb_single(struct file_system_type *fs_type,
        int flags, void *data,
        int (*fill_super)(struct super_block *, void *, int));
struct super_block *get_sb_nodev(struct file_system_type *fs_type,
        int flags, void *data,
        int (*fill_super)(struct super_block *, void *, int));
void generic_shutdown_super(struct super_block *sb);
void kill_block_super(struct super_block *sb);
void kill_anon_super(struct super_block *sb);
void kill_litter_super(struct super_block *sb);
void deactivate_super(struct super_block *sb);
int set_anon_super(struct super_block *s, void *data);
struct super_block *sget(struct file_system_type *type,
                        int (*test)(struct super_block *,void *),
                        int (*set)(struct super_block *,void *),
                        void *data);
struct super_block *get_sb_pseudo(struct file_system_type *, char *,
                        struct super_operations *ops, unsigned long);
int __put_super(struct super_block *sb);
int __put_super_and_need_restart(struct super_block *sb);
void unnamed_dev_init(void);
extern int register_filesystem(struct file_system_type *);
extern int unregister_filesystem(struct file_system_type *);
extern struct vfsmount *kern_mount(struct file_system_type *);
extern int may_umount_tree(struct vfsmount *);
extern int may_umount(struct vfsmount *);
extern long do_mount(char *, char *, char *, unsigned long, void *);
extern int vfs_statfs(struct super_block *, struct kstatfs *);
extern int locks_mandatory_locked(struct inode *);
extern int locks_mandatory_area(int, struct inode *, struct file *, loff_t, size_t);
static inline __attribute__((always_inline)) int locks_verify_locked(struct inode *inode)
{
        if ((((inode)->i_sb->s_flags & (64)) && ((inode)->i_mode & (0002000 | 00010)) == 0002000))
                return locks_mandatory_locked(inode);
        return 0;
}
extern int rw_verify_area(int, struct file *, loff_t *, size_t);
static inline __attribute__((always_inline)) int locks_verify_truncate(struct inode *inode,
                                    struct file *filp,
                                    loff_t size)
{
        if (inode->i_flock && (((inode)->i_sb->s_flags & (64)) && ((inode)->i_mode & (0002000 | 00010)) == 0002000))
                return locks_mandatory_area(
                        2, inode, filp,
                        size < inode->i_size ? size : inode->i_size,
                        (size < inode->i_size ? inode->i_size - size
                         : size - inode->i_size)
                );
        return 0;
}
static inline __attribute__((always_inline)) int break_lease(struct inode *inode, unsigned int mode)
{
        if (inode->i_flock)
                return __break_lease(inode, mode);
        return 0;
}
extern int do_truncate(struct dentry *, loff_t start);
extern long do_sys_open(const char *filename, int flags, int mode);
extern struct file *filp_open(const char *, int, int);
extern struct file * dentry_open(struct dentry *, struct vfsmount *, int);
extern int filp_close(struct file *, fl_owner_t id);
extern char * getname(const char *);
extern void __attribute__ ((__section__ (".init.text"))) vfs_caches_init_early(void);
extern void __attribute__ ((__section__ (".init.text"))) vfs_caches_init(unsigned long);
extern int register_blkdev(unsigned int, const char *);
extern int unregister_blkdev(unsigned int, const char *);
extern struct block_device *bdget(dev_t);
extern void bd_set_size(struct block_device *, loff_t size);
extern void bd_forget(struct inode *inode);
extern void bdput(struct block_device *);
extern struct block_device *open_by_devnum(dev_t, unsigned);
extern struct file_operations def_blk_fops;
extern struct address_space_operations def_blk_aops;
extern struct file_operations def_chr_fops;
extern struct file_operations bad_sock_fops;
extern struct file_operations def_fifo_fops;
extern int ioctl_by_bdev(struct block_device *, unsigned, unsigned long);
extern int blkdev_ioctl(struct inode *, struct file *, unsigned, unsigned long);
extern long compat_blkdev_ioctl(struct file *, unsigned, unsigned long);
extern int blkdev_get(struct block_device *, mode_t, unsigned);
extern int blkdev_put(struct block_device *);
extern int bd_claim(struct block_device *, void *);
extern void bd_release(struct block_device *);
extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);
extern int register_chrdev_region(dev_t, unsigned, const char *);
extern int register_chrdev(unsigned int, const char *,
                           struct file_operations *);
extern int unregister_chrdev(unsigned int, const char *);
extern void unregister_chrdev_region(dev_t, unsigned);
extern int chrdev_open(struct inode *, struct file *);
extern const char *__bdevname(dev_t, char *buffer);
extern const char *bdevname(struct block_device *bdev, char *buffer);
extern struct block_device *lookup_bdev(const char *);
extern struct block_device *open_bdev_excl(const char *, int, void *);
extern void close_bdev_excl(struct block_device *);
extern void init_special_inode(struct inode *, umode_t, dev_t);
extern void make_bad_inode(struct inode *);
extern int is_bad_inode(struct inode *);
extern struct file_operations read_fifo_fops;
extern struct file_operations write_fifo_fops;
extern struct file_operations rdwr_fifo_fops;
extern struct file_operations read_pipe_fops;
extern struct file_operations write_pipe_fops;
extern struct file_operations rdwr_pipe_fops;
extern int fs_may_remount_ro(struct super_block *);
extern int check_disk_change(struct block_device *);
extern int invalidate_inodes(struct super_block *);
extern int __invalidate_device(struct block_device *);
extern int invalidate_partition(struct gendisk *, int);
unsigned long invalidate_mapping_pages(struct address_space *mapping,
                                        unsigned long start, unsigned long end);
unsigned long invalidate_inode_pages(struct address_space *mapping);
static inline __attribute__((always_inline)) void invalidate_remote_inode(struct inode *inode)
{
        if ((((inode->i_mode) & 00170000) == 0100000) || (((inode->i_mode) & 00170000) == 0040000) ||
            (((inode->i_mode) & 00170000) == 0120000))
                invalidate_inode_pages(inode->i_mapping);
}
extern int invalidate_inode_pages2(struct address_space *mapping);
extern int invalidate_inode_pages2_range(struct address_space *mapping,
                                         unsigned long start, unsigned long end);
extern int write_inode_now(struct inode *, int);
extern int filemap_fdatawrite(struct address_space *);
extern int filemap_flush(struct address_space *);
extern int filemap_fdatawait(struct address_space *);
extern int filemap_write_and_wait(struct address_space *mapping);
extern int filemap_write_and_wait_range(struct address_space *mapping,
                                        loff_t lstart, loff_t lend);
extern void sync_supers(void);
extern void sync_filesystems(int wait);
extern void emergency_sync(void);
extern void emergency_remount(void);
extern int do_remount_sb(struct super_block *sb, int flags,
                         void *data, int force);
extern sector_t bmap(struct inode *, sector_t);
extern int notify_change(struct dentry *, struct iattr *);
extern int permission(struct inode *, int, struct nameidata *);
extern int generic_permission(struct inode *, int,
                int (*check_acl)(struct inode *, int));
extern int get_write_access(struct inode *);
extern int deny_write_access(struct file *);
static inline __attribute__((always_inline)) void put_write_access(struct inode * inode)
{
        atomic_dec(&inode->i_writecount);
}
static inline __attribute__((always_inline)) void allow_write_access(struct file *file)
{
        if (file)
                atomic_inc(&file->f_dentry->d_inode->i_writecount);
}
extern int do_pipe(int *);
extern int open_namei(const char *, int, int, struct nameidata *);
extern int may_open(struct nameidata *, int, int);
extern int kernel_read(struct file *, unsigned long, char *, unsigned long);
extern struct file * open_exec(const char *);
extern int is_subdir(struct dentry *, struct dentry *);
extern ino_t find_inode_number(struct dentry *, struct qstr *);
static inline __attribute__((always_inline)) void *ERR_PTR(long error)
{
        return (void *) error;
}
static inline __attribute__((always_inline)) long PTR_ERR(const void *ptr)
{
        return (long) ptr;
}
static inline __attribute__((always_inline)) long IS_ERR(const void *ptr)
{
        return __builtin_expect(!!(((unsigned long)ptr) > (unsigned long)-1000L), 0);
}
extern loff_t default_llseek(struct file *file, loff_t offset, int origin);
extern loff_t vfs_llseek(struct file *file, loff_t offset, int origin);
extern void inode_init_once(struct inode *);
extern void iput(struct inode *);
extern struct inode * igrab(struct inode *);
extern ino_t iunique(struct super_block *, ino_t);
extern int inode_needs_sync(struct inode *inode);
extern void generic_delete_inode(struct inode *inode);
extern void generic_drop_inode(struct inode *inode);
extern struct inode *ilookup5_nowait(struct super_block *sb,
                unsigned long hashval, int (*test)(struct inode *, void *),
                void *data);
extern struct inode *ilookup5(struct super_block *sb, unsigned long hashval,
                int (*test)(struct inode *, void *), void *data);
extern struct inode *ilookup(struct super_block *sb, unsigned long ino);
extern struct inode * iget5_locked(struct super_block *, unsigned long, int (*test)(struct inode *, void *), int (*set)(struct inode *, void *), void *);
extern struct inode * iget_locked(struct super_block *, unsigned long);
extern void unlock_new_inode(struct inode *);
static inline __attribute__((always_inline)) struct inode *iget(struct super_block *sb, unsigned long ino)
{
        struct inode *inode = iget_locked(sb, ino);
        if (inode && (inode->i_state & 64)) {
                sb->s_op->read_inode(inode);
                unlock_new_inode(inode);
        }
        return inode;
}
extern void __iget(struct inode * inode);
extern void clear_inode(struct inode *);
extern void destroy_inode(struct inode *);
extern struct inode *new_inode(struct super_block *);
extern int remove_suid(struct dentry *);
extern void remove_dquot_ref(struct super_block *, int, struct list_head *);
extern struct semaphore iprune_sem;
extern void __insert_inode_hash(struct inode *, unsigned long hashval);
extern void remove_inode_hash(struct inode *);
static inline __attribute__((always_inline)) void insert_inode_hash(struct inode *inode) {
        __insert_inode_hash(inode, inode->i_ino);
}
extern struct file * get_empty_filp(void);
extern void file_move(struct file *f, struct list_head *list);
extern void file_kill(struct file *f);
struct bio;
extern void submit_bio(int, struct bio *);
extern int bdev_read_only(struct block_device *);
extern int set_blocksize(struct block_device *, int);
extern int sb_set_blocksize(struct super_block *, int);
extern int sb_min_blocksize(struct super_block *, int);
extern int generic_file_mmap(struct file *, struct vm_area_struct *);
extern int generic_file_readonly_mmap(struct file *, struct vm_area_struct *);
extern int file_read_actor(read_descriptor_t * desc, struct page *page, unsigned long offset, unsigned long size);
extern int file_send_actor(read_descriptor_t * desc, struct page *page, unsigned long offset, unsigned long size);
extern ssize_t generic_file_read(struct file *, char *, size_t, loff_t *);
int generic_write_checks(struct file *file, loff_t *pos, size_t *count, int isblk);
extern ssize_t generic_file_write(struct file *, const char *, size_t, loff_t *);
extern ssize_t generic_file_aio_read(struct kiocb *, char *, size_t, loff_t);
extern ssize_t __generic_file_aio_read(struct kiocb *, const struct iovec *, unsigned long, loff_t *);
extern ssize_t generic_file_aio_write(struct kiocb *, const char *, size_t, loff_t);
extern ssize_t generic_file_aio_write_nolock(struct kiocb *, const struct iovec *,
                unsigned long, loff_t *);
extern ssize_t generic_file_direct_write(struct kiocb *, const struct iovec *,
                unsigned long *, loff_t, loff_t *, size_t, size_t);
extern ssize_t generic_file_buffered_write(struct kiocb *, const struct iovec *,
                unsigned long, loff_t, loff_t *, size_t, ssize_t);
extern ssize_t do_sync_read(struct file *filp, char *buf, size_t len, loff_t *ppos);
extern ssize_t do_sync_write(struct file *filp, const char *buf, size_t len, loff_t *ppos);
ssize_t generic_file_write_nolock(struct file *file, const struct iovec *iov,
                                unsigned long nr_segs, loff_t *ppos);
extern ssize_t generic_file_sendfile(struct file *, loff_t *, size_t, read_actor_t, void *);
extern void do_generic_mapping_read(struct address_space *mapping,
                                    struct file_ra_state *, struct file *,
                                    loff_t *, read_descriptor_t *, read_actor_t);
extern void
file_ra_state_init(struct file_ra_state *ra, struct address_space *mapping);
extern ssize_t generic_file_readv(struct file *filp, const struct iovec *iov,
        unsigned long nr_segs, loff_t *ppos);
ssize_t generic_file_writev(struct file *filp, const struct iovec *iov,
                        unsigned long nr_segs, loff_t *ppos);
extern loff_t no_llseek(struct file *file, loff_t offset, int origin);
extern loff_t generic_file_llseek(struct file *file, loff_t offset, int origin);
extern loff_t remote_llseek(struct file *file, loff_t offset, int origin);
extern int generic_file_open(struct inode * inode, struct file * filp);
extern int nonseekable_open(struct inode * inode, struct file * filp);
static inline __attribute__((always_inline)) int xip_truncate_page(struct address_space *mapping, loff_t from)
{
        return 0;
}
static inline __attribute__((always_inline)) void do_generic_file_read(struct file * filp, loff_t *ppos,
                                        read_descriptor_t * desc,
                                        read_actor_t actor)
{
        do_generic_mapping_read(filp->f_mapping,
                                &filp->f_ra,
                                filp,
                                ppos,
                                desc,
                                actor);
}
ssize_t __blockdev_direct_IO(int rw, struct kiocb *iocb, struct inode *inode,
        struct block_device *bdev, const struct iovec *iov, loff_t offset,
        unsigned long nr_segs, get_blocks_t get_blocks, dio_iodone_t end_io,
        int lock_type);
enum {
        DIO_LOCKING = 1,
        DIO_NO_LOCKING,
        DIO_OWN_LOCKING,
};
static inline __attribute__((always_inline)) ssize_t blockdev_direct_IO(int rw, struct kiocb *iocb,
        struct inode *inode, struct block_device *bdev, const struct iovec *iov,
        loff_t offset, unsigned long nr_segs, get_blocks_t get_blocks,
        dio_iodone_t end_io)
{
        return __blockdev_direct_IO(rw, iocb, inode, bdev, iov, offset,
                                nr_segs, get_blocks, end_io, DIO_LOCKING);
}
static inline __attribute__((always_inline)) ssize_t blockdev_direct_IO_no_locking(int rw, struct kiocb *iocb,
        struct inode *inode, struct block_device *bdev, const struct iovec *iov,
        loff_t offset, unsigned long nr_segs, get_blocks_t get_blocks,
        dio_iodone_t end_io)
{
        return __blockdev_direct_IO(rw, iocb, inode, bdev, iov, offset,
                                nr_segs, get_blocks, end_io, DIO_NO_LOCKING);
}
static inline __attribute__((always_inline)) ssize_t blockdev_direct_IO_own_locking(int rw, struct kiocb *iocb,
        struct inode *inode, struct block_device *bdev, const struct iovec *iov,
        loff_t offset, unsigned long nr_segs, get_blocks_t get_blocks,
        dio_iodone_t end_io)
{
        return __blockdev_direct_IO(rw, iocb, inode, bdev, iov, offset,
                                nr_segs, get_blocks, end_io, DIO_OWN_LOCKING);
}
extern struct file_operations generic_ro_fops;
extern int vfs_readlink(struct dentry *, char *, int, const char *);
extern int vfs_follow_link(struct nameidata *, const char *);
extern int page_readlink(struct dentry *, char *, int);
extern void *page_follow_link_light(struct dentry *, struct nameidata *);
extern void page_put_link(struct dentry *, struct nameidata *, void *);
extern int page_symlink(struct inode *inode, const char *symname, int len);
extern struct inode_operations page_symlink_inode_operations;
extern int generic_readlink(struct dentry *, char *, int);
extern void generic_fillattr(struct inode *, struct kstat *);
extern int vfs_getattr(struct vfsmount *, struct dentry *, struct kstat *);
void inode_add_bytes(struct inode *inode, loff_t bytes);
void inode_sub_bytes(struct inode *inode, loff_t bytes);
loff_t inode_get_bytes(struct inode *inode);
void inode_set_bytes(struct inode *inode, loff_t bytes);
extern int vfs_readdir(struct file *, filldir_t, void *);
extern int vfs_stat(char *, struct kstat *);
extern int vfs_lstat(char *, struct kstat *);
extern int vfs_fstat(unsigned int, struct kstat *);
extern int vfs_ioctl(struct file *, unsigned int, unsigned int, unsigned long);
extern struct file_system_type *get_fs_type(const char *name);
extern struct super_block *get_super(struct block_device *);
extern struct super_block *user_get_super(dev_t);
extern void drop_super(struct super_block *sb);
extern int dcache_dir_open(struct inode *, struct file *);
extern int dcache_dir_close(struct inode *, struct file *);
extern loff_t dcache_dir_lseek(struct file *, loff_t, int);
extern int dcache_readdir(struct file *, void *, filldir_t);
extern int simple_getattr(struct vfsmount *, struct dentry *, struct kstat *);
extern int simple_statfs(struct super_block *, struct kstatfs *);
extern int simple_link(struct dentry *, struct inode *, struct dentry *);
extern int simple_unlink(struct inode *, struct dentry *);
extern int simple_rmdir(struct inode *, struct dentry *);
extern int simple_rename(struct inode *, struct dentry *, struct inode *, struct dentry *);
extern int simple_sync_file(struct file *, struct dentry *, int);
extern int simple_empty(struct dentry *);
extern int simple_readpage(struct file *file, struct page *page);
extern int simple_prepare_write(struct file *file, struct page *page,
                        unsigned offset, unsigned to);
extern int simple_commit_write(struct file *file, struct page *page,
                                unsigned offset, unsigned to);
extern struct dentry *simple_lookup(struct inode *, struct dentry *, struct nameidata *);
extern ssize_t generic_read_dir(struct file *, char *, size_t, loff_t *);
extern struct file_operations simple_dir_operations;
extern struct inode_operations simple_dir_inode_operations;
struct tree_descr { char *name; struct file_operations *ops; int mode; };
struct dentry *d_alloc_name(struct dentry *, const char *);
extern int simple_fill_super(struct super_block *, int, struct tree_descr *);
extern int simple_pin_fs(char *name, struct vfsmount **mount, int *count);
extern void simple_release_fs(struct vfsmount **mount, int *count);
extern ssize_t simple_read_from_buffer(void *, size_t, loff_t *, const void *, size_t);
extern int inode_change_ok(struct inode *, struct iattr *);
extern int inode_setattr(struct inode *, struct iattr *);
extern void inode_update_time(struct inode *inode, int ctime_too);
static inline __attribute__((always_inline)) ino_t parent_ino(struct dentry *dentry)
{
        ino_t res;
        _spin_lock(&dentry->d_lock);
        res = dentry->d_parent->d_inode->i_ino;
        _spin_unlock(&dentry->d_lock);
        return res;
}
extern int unshare_files(void);
struct simple_transaction_argresp {
        ssize_t size;
        char data[0];
};
char *simple_transaction_get(struct file *file, const char *buf,
                                size_t size);
ssize_t simple_transaction_read(struct file *file, char *buf,
                                size_t size, loff_t *pos);
int simple_transaction_release(struct inode *inode, struct file *file);
static inline __attribute__((always_inline)) void simple_transaction_set(struct file *file, size_t n)
{
        struct simple_transaction_argresp *ar = file->private_data;
        do { if (__builtin_expect(!!((n > ((1UL << 12) - sizeof(struct simple_transaction_argresp)))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (1692), "i" ("include/linux/fs.h")); } while(0);
        asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "mfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
        ar->size = n;
}
static inline __attribute__((always_inline)) void __attribute__((format(printf, 1, 2)))
__simple_attr_check_format(const char *fmt, ...)
{
}
int simple_attr_open(struct inode *inode, struct file *file,
                     u64 (*get)(void *), void (*set)(void *, u64),
                     const char *fmt);
int simple_attr_close(struct inode *inode, struct file *file);
ssize_t simple_attr_read(struct file *file, char *buf,
                         size_t len, loff_t *ppos);
ssize_t simple_attr_write(struct file *file, const char *buf,
                          size_t len, loff_t *ppos);
static inline __attribute__((always_inline)) char *alloc_secdata(void)
{
        return (char *)1;
}
static inline __attribute__((always_inline)) void free_secdata(void *secdata)
{ }
struct mempolicy;
struct anon_vma;
extern unsigned long max_mapnr;
extern unsigned long num_physpages;
extern void * high_memory;
extern unsigned long vmalloc_earlyreserve;
extern int page_cluster;
extern int sysctl_legacy_va_layout;
extern unsigned long empty_zero_page[1024];
extern pgd_t swapper_pg_dir[1024];
extern kmem_cache_t *pgd_cache;
extern kmem_cache_t *pmd_cache;
extern spinlock_t pgd_lock;
extern struct page *pgd_list;
void pmd_ctor(void *, kmem_cache_t *, unsigned long);
void pgd_ctor(void *, kmem_cache_t *, unsigned long);
void pgd_dtor(void *, kmem_cache_t *, unsigned long);
void pgtable_cache_init(void);
void paging_init(void);
extern unsigned long long __PAGE_KERNEL, __PAGE_KERNEL_EXEC;
extern unsigned long pg0[];
static inline __attribute__((always_inline)) int pte_user(pte_t pte) { return (pte).pte_low & 0x004; }
static inline __attribute__((always_inline)) int pte_read(pte_t pte) { return (pte).pte_low & 0x004; }
static inline __attribute__((always_inline)) int pte_dirty(pte_t pte) { return (pte).pte_low & 0x040; }
static inline __attribute__((always_inline)) int pte_young(pte_t pte) { return (pte).pte_low & 0x020; }
static inline __attribute__((always_inline)) int pte_write(pte_t pte) { return (pte).pte_low & 0x002; }
static inline __attribute__((always_inline)) int pte_huge(pte_t pte) { return ((pte).pte_low & (0x080 | 0x001)) == (0x080 | 0x001); }
static inline __attribute__((always_inline)) int pte_file(pte_t pte) { return (pte).pte_low & 0x040; }
static inline __attribute__((always_inline)) pte_t pte_rdprotect(pte_t pte) { (pte).pte_low &= ~0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_exprotect(pte_t pte) { (pte).pte_low &= ~0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkclean(pte_t pte) { (pte).pte_low &= ~0x040; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkold(pte_t pte) { (pte).pte_low &= ~0x020; return pte; }
static inline __attribute__((always_inline)) pte_t pte_wrprotect(pte_t pte) { (pte).pte_low &= ~0x002; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkread(pte_t pte) { (pte).pte_low |= 0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkexec(pte_t pte) { (pte).pte_low |= 0x004; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkdirty(pte_t pte) { (pte).pte_low |= 0x040; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkyoung(pte_t pte) { (pte).pte_low |= 0x020; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkwrite(pte_t pte) { (pte).pte_low |= 0x002; return pte; }
static inline __attribute__((always_inline)) pte_t pte_mkhuge(pte_t pte) { (pte).pte_low |= (0x080 | 0x001); return pte; }
typedef struct { pgd_t pgd; } pud_t;
static inline __attribute__((always_inline)) int pgd_none(pgd_t pgd) { return 0; }
static inline __attribute__((always_inline)) int pgd_bad(pgd_t pgd) { return 0; }
static inline __attribute__((always_inline)) int pgd_present(pgd_t pgd) { return 1; }
static inline __attribute__((always_inline)) void pgd_clear(pgd_t *pgd) { }
static inline __attribute__((always_inline)) pud_t * pud_offset(pgd_t * pgd, unsigned long address)
{
        return (pud_t *)pgd;
}
static inline __attribute__((always_inline)) int pte_x(pte_t pte)
{
        return !(((pte).pte_low | ((unsigned long long)(pte).pte_high << 32)) & (1ULL<<63));
}
static inline __attribute__((always_inline)) int pte_exec(pte_t pte)
{
        return pte_user(pte) && pte_x(pte);
}
static inline __attribute__((always_inline)) int pte_exec_kernel(pte_t pte)
{
        return pte_x(pte);
}
static inline __attribute__((always_inline)) void set_pte(pte_t *ptep, pte_t pte)
{
        ptep->pte_high = pte.pte_high;
        __asm__ __volatile__ ("": : :"memory");
        ptep->pte_low = pte.pte_low;
}
static inline __attribute__((always_inline)) void pud_clear (pud_t * pud) { }
static inline __attribute__((always_inline)) pte_t ptep_get_and_clear(struct mm_struct *mm, unsigned long addr, pte_t *ptep)
{
        pte_t res;
        res.pte_low = ((__typeof__(*(&ptep->pte_low)))__xchg((unsigned long)(0),(&ptep->pte_low),sizeof(*(&ptep->pte_low))));
        res.pte_high = ptep->pte_high;
        ptep->pte_high = 0;
        return res;
}
static inline __attribute__((always_inline)) int pte_same(pte_t a, pte_t b)
{
        return a.pte_low == b.pte_low && a.pte_high == b.pte_high;
}
static inline __attribute__((always_inline)) int pte_none(pte_t pte)
{
        return !pte.pte_low && !pte.pte_high;
}
static inline __attribute__((always_inline)) unsigned long pte_pfn(pte_t pte)
{
        return (pte.pte_low >> 12) |
                (pte.pte_high << (32 - 12));
}
extern unsigned long long __supported_pte_mask;
static inline __attribute__((always_inline)) pte_t pfn_pte(unsigned long page_nr, pgprot_t pgprot)
{
        pte_t pte;
        pte.pte_high = (page_nr >> (32 - 12)) | (((pgprot).pgprot) >> 32);
        pte.pte_high &= (__supported_pte_mask >> 32);
        pte.pte_low = ((page_nr << 12) | ((pgprot).pgprot)) & __supported_pte_mask;
        return pte;
}
static inline __attribute__((always_inline)) pmd_t pfn_pmd(unsigned long page_nr, pgprot_t pgprot)
{
        return ((pmd_t) { ((((unsigned long long)page_nr << 12) | ((pgprot).pgprot)) & __supported_pte_mask) } );
}
static inline __attribute__((always_inline)) int ptep_test_and_clear_dirty(struct vm_area_struct *vma, unsigned long addr, pte_t *ptep)
{
        if (!pte_dirty(*ptep))
                return 0;
        return test_and_clear_bit(6, &ptep->pte_low);
}
static inline __attribute__((always_inline)) int ptep_test_and_clear_young(struct vm_area_struct *vma, unsigned long addr, pte_t *ptep)
{
        if (!pte_young(*ptep))
                return 0;
        return test_and_clear_bit(5, &ptep->pte_low);
}
static inline __attribute__((always_inline)) pte_t ptep_get_and_clear_full(struct mm_struct *mm, unsigned long addr, pte_t *ptep, int full)
{
        pte_t pte;
        if (full) {
                pte = *ptep;
                *ptep = ((pte_t) { (0) } );
        } else {
                pte = ptep_get_and_clear(mm, addr, ptep);
        }
        return pte;
}
static inline __attribute__((always_inline)) void ptep_set_wrprotect(struct mm_struct *mm, unsigned long addr, pte_t *ptep)
{
        clear_bit(1, &ptep->pte_low);
}
static inline __attribute__((always_inline)) void clone_pgd_range(pgd_t *dst, pgd_t *src, int count)
{
       (__builtin_constant_p(count * sizeof(pgd_t)) ? __constant_memcpy((dst),(src),(count * sizeof(pgd_t))) : __memcpy((dst),(src),(count * sizeof(pgd_t))));
}
static inline __attribute__((always_inline)) pte_t pte_modify(pte_t pte, pgprot_t newprot)
{
        pte.pte_low &= ((~((1UL << 12)-1)) | 0x020 | 0x040);
        pte.pte_low |= ((newprot).pgprot);
        pte.pte_high &= ~(1 << (63 - 32));
        pte.pte_high |= (((newprot).pgprot) >> 32) & (__supported_pte_mask >> 32);
        return pte;
}
extern pte_t *lookup_address(unsigned long address);
 extern int set_kernel_exec(unsigned long vaddr, int enable);
extern void noexec_setup(const char *str);
void pgd_clear_bad(pgd_t *);
void pud_clear_bad(pud_t *);
void pmd_clear_bad(pmd_t *);
static inline __attribute__((always_inline)) int pgd_none_or_clear_bad(pgd_t *pgd)
{
        if (pgd_none(*pgd))
                return 1;
        if (__builtin_expect(!!(pgd_bad(*pgd)), 0)) {
                pgd_clear_bad(pgd);
                return 1;
        }
        return 0;
}
static inline __attribute__((always_inline)) int pud_none_or_clear_bad(pud_t *pud)
{
        if (0)
                return 1;
        if (__builtin_expect(!!(0), 0)) {
                pud_clear_bad(pud);
                return 1;
        }
        return 0;
}
static inline __attribute__((always_inline)) int pmd_none_or_clear_bad(pmd_t *pmd)
{
        if ((!((*pmd).pmd)))
                return 1;
        if (__builtin_expect(!!(((((*pmd).pmd) & (~(~((1UL << 12)-1)) & ~0x004)) != (0x001 | 0x002 | 0x020 | 0x040))), 0)) {
                pmd_clear_bad(pmd);
                return 1;
        }
        return 0;
}
struct vm_area_struct {
        struct mm_struct * vm_mm;
        unsigned long vm_start;
        unsigned long vm_end;
        struct vm_area_struct *vm_next;
        pgprot_t vm_page_prot;
        unsigned long vm_flags;
        struct rb_node vm_rb;
        union {
                struct {
                        struct list_head list;
                        void *parent;
                        struct vm_area_struct *head;
                } vm_set;
                struct raw_prio_tree_node prio_tree_node;
        } shared;
        struct list_head anon_vma_node;
        struct anon_vma *anon_vma;
        struct vm_operations_struct * vm_ops;
        unsigned long vm_pgoff;
        struct file * vm_file;
        void * vm_private_data;
        unsigned long vm_truncate_count;
};
struct vm_list_struct {
        struct vm_list_struct *next;
        struct vm_area_struct *vma;
};
extern pgprot_t protection_map[16];
struct vm_operations_struct {
        void (*open)(struct vm_area_struct * area);
        void (*close)(struct vm_area_struct * area);
        struct page * (*nopage)(struct vm_area_struct * area, unsigned long address, int *type);
        int (*populate)(struct vm_area_struct * area, unsigned long address, unsigned long len, pgprot_t prot, unsigned long pgoff, int nonblock);
};
struct mmu_gather;
struct inode;
typedef unsigned long page_flags_t;
struct page {
        page_flags_t flags;
        atomic_t _count;
        atomic_t _mapcount;
        unsigned long private;
        struct address_space *mapping;
        unsigned long index;
        struct list_head lru;
};
struct page_state {
        unsigned long nr_dirty;
        unsigned long nr_writeback;
        unsigned long nr_unstable;
        unsigned long nr_page_table_pages;
        unsigned long nr_mapped;
        unsigned long nr_slab;
        unsigned long pgpgin;
        unsigned long pgpgout;
        unsigned long pswpin;
        unsigned long pswpout;
        unsigned long pgalloc_high;
        unsigned long pgalloc_normal;
        unsigned long pgalloc_dma;
        unsigned long pgfree;
        unsigned long pgactivate;
        unsigned long pgdeactivate;
        unsigned long pgfault;
        unsigned long pgmajfault;
        unsigned long pgrefill_high;
        unsigned long pgrefill_normal;
        unsigned long pgrefill_dma;
        unsigned long pgsteal_high;
        unsigned long pgsteal_normal;
        unsigned long pgsteal_dma;
        unsigned long pgscan_kswapd_high;
        unsigned long pgscan_kswapd_normal;
        unsigned long pgscan_kswapd_dma;
        unsigned long pgscan_direct_high;
        unsigned long pgscan_direct_normal;
        unsigned long pgscan_direct_dma;
        unsigned long pginodesteal;
        unsigned long slabs_scanned;
        unsigned long kswapd_steal;
        unsigned long kswapd_inodesteal;
        unsigned long pageoutrun;
        unsigned long allocstall;
        unsigned long pgrotated;
        unsigned long nr_bounce;
};
extern void get_page_state(struct page_state *ret);
extern void get_page_state_node(struct page_state *ret, int node);
extern void get_full_page_state(struct page_state *ret);
extern unsigned long __read_page_state(unsigned long offset);
extern void __mod_page_state(unsigned long offset, unsigned long delta);
struct page;
int test_clear_page_dirty(struct page *page);
int test_clear_page_writeback(struct page *page);
int test_set_page_writeback(struct page *page);
static inline __attribute__((always_inline)) void clear_page_dirty(struct page *page)
{
        test_clear_page_dirty(page);
}
static inline __attribute__((always_inline)) void set_page_writeback(struct page *page)
{
        test_set_page_writeback(page);
}
extern void __page_cache_release(struct page *) __attribute__((regparm(3)));
static inline __attribute__((always_inline)) int page_count(struct page *p)
{
        if ((__builtin_constant_p(14) ? constant_test_bit((14),(&(p)->flags)) : variable_test_bit((14),(&(p)->flags))))
                p = (struct page *)p->private;
        return ((&(p)->_count)->counter) + 1;
}
static inline __attribute__((always_inline)) void get_page(struct page *page)
{
        if (__builtin_expect(!!((__builtin_constant_p(14) ? constant_test_bit((14),(&(page)->flags)) : variable_test_bit((14),(&(page)->flags)))), 0))
                page = (struct page *)page->private;
        atomic_inc(&page->_count);
}
void put_page(struct page *page);
static inline __attribute__((always_inline)) unsigned long page_zonenum(struct page *page)
{
        return (page->flags >> (((((sizeof(page_flags_t)*8) - 0) - 0) - 2) * (2 != 0))) & ((1UL << 2) - 1);
}
struct zone;
extern struct zone *zone_table[];
static inline __attribute__((always_inline)) struct zone *page_zone(struct page *page)
{
        return zone_table[(page->flags >> (((((sizeof(page_flags_t)*8) - 0) - 0) - 2) * (2 != 0))) &
                        ((1UL << (0 + 2)) - 1)];
}
static inline __attribute__((always_inline)) unsigned long page_to_nid(struct page *page)
{
        if ((0 > 0 || 0 == 0))
                return (page->flags >> ((((sizeof(page_flags_t)*8) - 0) - 0) * (0 != 0))) & ((1UL << 0) - 1);
        else
                return page_zone(page)->zone_pgdat->node_id;
}
static inline __attribute__((always_inline)) unsigned long page_to_section(struct page *page)
{
        return (page->flags >> (((sizeof(page_flags_t)*8) - 0) * (0 != 0))) & ((1UL << 0) - 1);
}
static inline __attribute__((always_inline)) void set_page_zone(struct page *page, unsigned long zone)
{
        page->flags &= ~(((1UL << 2) - 1) << (((((sizeof(page_flags_t)*8) - 0) - 0) - 2) * (2 != 0)));
        page->flags |= (zone & ((1UL << 2) - 1)) << (((((sizeof(page_flags_t)*8) - 0) - 0) - 2) * (2 != 0));
}
static inline __attribute__((always_inline)) void set_page_node(struct page *page, unsigned long node)
{
        page->flags &= ~(((1UL << 0) - 1) << ((((sizeof(page_flags_t)*8) - 0) - 0) * (0 != 0)));
        page->flags |= (node & ((1UL << 0) - 1)) << ((((sizeof(page_flags_t)*8) - 0) - 0) * (0 != 0));
}
static inline __attribute__((always_inline)) void set_page_section(struct page *page, unsigned long section)
{
        page->flags &= ~(((1UL << 0) - 1) << (((sizeof(page_flags_t)*8) - 0) * (0 != 0)));
        page->flags |= (section & ((1UL << 0) - 1)) << (((sizeof(page_flags_t)*8) - 0) * (0 != 0));
}
static inline __attribute__((always_inline)) void set_page_links(struct page *page, unsigned long zone,
        unsigned long node, unsigned long pfn)
{
        set_page_zone(page, zone);
        set_page_node(page, node);
        set_page_section(page, ((pfn) >> 0));
}
extern struct page *mem_map;
static inline __attribute__((always_inline)) void *lowmem_page_address(struct page *page)
{
        return ((void *)((unsigned long)(((unsigned long)((page) - mem_map)) << 12)+((unsigned long)(0xC0000000UL))));
}
void *page_address(struct page *page);
void set_page_address(struct page *page, void *virtual);
void page_address_init(void);
extern struct address_space swapper_space;
static inline __attribute__((always_inline)) struct address_space *page_mapping(struct page *page)
{
        struct address_space *mapping = page->mapping;
        if (__builtin_expect(!!((__builtin_constant_p(15) ? constant_test_bit((15),(&(page)->flags)) : variable_test_bit((15),(&(page)->flags)))), 0))
                mapping = &swapper_space;
        else if (__builtin_expect(!!((unsigned long)mapping & 1), 0))
                mapping = ((void *)0);
        return mapping;
}
static inline __attribute__((always_inline)) int PageAnon(struct page *page)
{
        return ((unsigned long)page->mapping & 1) != 0;
}
static inline __attribute__((always_inline)) unsigned long page_index(struct page *page)
{
        if (__builtin_expect(!!((__builtin_constant_p(15) ? constant_test_bit((15),(&(page)->flags)) : variable_test_bit((15),(&(page)->flags)))), 0))
                return page->private;
        return page->index;
}
static inline __attribute__((always_inline)) void reset_page_mapcount(struct page *page)
{
        (((&(page)->_mapcount)->counter) = (-1));
}
static inline __attribute__((always_inline)) int page_mapcount(struct page *page)
{
        return ((&(page)->_mapcount)->counter) + 1;
}
static inline __attribute__((always_inline)) int page_mapped(struct page *page)
{
        return ((&(page)->_mapcount)->counter) >= 0;
}
extern void show_free_areas(void);
struct page *shmem_nopage(struct vm_area_struct *vma,
                        unsigned long address, int *type);
int shmem_set_policy(struct vm_area_struct *vma, struct mempolicy *new);
struct mempolicy *shmem_get_policy(struct vm_area_struct *vma,
                                        unsigned long addr);
int shmem_lock(struct file *file, int lock, struct user_struct *user);
struct file *shmem_file_setup(char *name, loff_t size, unsigned long flags);
int shmem_zero_setup(struct vm_area_struct *);
static inline __attribute__((always_inline)) int can_do_mlock(void)
{
        if (capable(14))
                return 1;
        if (get_current()->signal->rlim[8].rlim_cur != 0)
                return 1;
        return 0;
}
extern int user_shm_lock(size_t, struct user_struct *);
extern void user_shm_unlock(size_t, struct user_struct *);
struct zap_details {
        struct vm_area_struct *nonlinear_vma;
        struct address_space *check_mapping;
        unsigned long first_index;
        unsigned long last_index;
        spinlock_t *i_mmap_lock;
        unsigned long truncate_count;
};
unsigned long zap_page_range(struct vm_area_struct *vma, unsigned long address,
                unsigned long size, struct zap_details *);
unsigned long unmap_vmas(struct mmu_gather **tlb, struct mm_struct *mm,
                struct vm_area_struct *start_vma, unsigned long start_addr,
                unsigned long end_addr, unsigned long *nr_accounted,
                struct zap_details *);
void free_pgd_range(struct mmu_gather **tlb, unsigned long addr,
                unsigned long end, unsigned long floor, unsigned long ceiling);
void free_pgtables(struct mmu_gather **tlb, struct vm_area_struct *start_vma,
                unsigned long floor, unsigned long ceiling);
int copy_page_range(struct mm_struct *dst, struct mm_struct *src,
                        struct vm_area_struct *vma);
int zeromap_page_range(struct vm_area_struct *vma, unsigned long from,
                        unsigned long size, pgprot_t prot);
void unmap_mapping_range(struct address_space *mapping,
                loff_t const holebegin, loff_t const holelen, int even_cows);
static inline __attribute__((always_inline)) void unmap_shared_mapping_range(struct address_space *mapping,
                loff_t const holebegin, loff_t const holelen)
{
        unmap_mapping_range(mapping, holebegin, holelen, 0);
}
extern int vmtruncate(struct inode * inode, loff_t offset);
extern pud_t *__pud_alloc(struct mm_struct *mm, pgd_t *pgd, unsigned long address) __attribute__((regparm(3)));
extern pmd_t *__pmd_alloc(struct mm_struct *mm, pud_t *pud, unsigned long address) __attribute__((regparm(3)));
extern pte_t *pte_alloc_kernel(struct mm_struct *mm, pmd_t *pmd, unsigned long address) __attribute__((regparm(3)));
extern pte_t *pte_alloc_map(struct mm_struct *mm, pmd_t *pmd, unsigned long address) __attribute__((regparm(3)));
extern int install_page(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, struct page *page, pgprot_t prot);
extern int install_file_pte(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, unsigned long pgoff, pgprot_t prot);
extern int __handle_mm_fault(struct mm_struct *mm,struct vm_area_struct *vma, unsigned long address, int write_access);
static inline __attribute__((always_inline)) int handle_mm_fault(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, int write_access)
{
        return __handle_mm_fault(mm, vma, address, write_access) & (~0x10);
}
extern int make_pages_present(unsigned long addr, unsigned long end);
extern int access_process_vm(struct task_struct *tsk, unsigned long addr, void *buf, int len, int write);
void install_arg_page(struct vm_area_struct *, struct page *, unsigned long);
int get_user_pages(struct task_struct *tsk, struct mm_struct *mm, unsigned long start,
                int len, int write, int force, struct page **pages, struct vm_area_struct **vmas);
int __set_page_dirty_buffers(struct page *page);
int __set_page_dirty_nobuffers(struct page *page);
int redirty_page_for_writepage(struct writeback_control *wbc,
                                struct page *page);
int set_page_dirty(struct page *page) __attribute__((regparm(3)));
int set_page_dirty_lock(struct page *page);
int clear_page_dirty_for_io(struct page *page);
extern unsigned long do_mremap(unsigned long addr,
                               unsigned long old_len, unsigned long new_len,
                               unsigned long flags, unsigned long new_addr);
typedef int (*shrinker_t)(int nr_to_scan, unsigned int gfp_mask);
struct shrinker;
extern struct shrinker *set_shrinker(int, shrinker_t);
extern void remove_shrinker(struct shrinker *shrinker);
static inline __attribute__((always_inline)) pud_t *pud_alloc(struct mm_struct *mm, pgd_t *pgd, unsigned long address)
{
        if (pgd_none(*pgd))
                return __pud_alloc(mm, pgd, address);
        return pud_offset(pgd, address);
}
static inline __attribute__((always_inline)) pmd_t *pmd_alloc(struct mm_struct *mm, pud_t *pud, unsigned long address)
{
        if (0)
                return __pmd_alloc(mm, pud, address);
        return ((pmd_t *) ((struct page *) ((void *)((unsigned long)(((((*(pud)).pgd).pgd)) & (~((1UL << 12)-1)))+((unsigned long)(0xC0000000UL))))) + (((address) >> 21) & (512 -1)));
}
extern void free_area_init(unsigned long * zones_size);
extern void free_area_init_node(int nid, pg_data_t *pgdat,
        unsigned long * zones_size, unsigned long zone_start_pfn,
        unsigned long *zholes_size);
extern void memmap_init_zone(unsigned long, int, unsigned long, unsigned long);
extern void mem_init(void);
extern void show_mem(void);
extern void si_meminfo(struct sysinfo * val);
extern void si_meminfo_node(struct sysinfo *val, int nid);
static inline __attribute__((always_inline)) void setup_per_cpu_pageset(void) {}
void vma_prio_tree_add(struct vm_area_struct *, struct vm_area_struct *old);
void vma_prio_tree_insert(struct vm_area_struct *, struct prio_tree_root *);
void vma_prio_tree_remove(struct vm_area_struct *, struct prio_tree_root *);
struct vm_area_struct *vma_prio_tree_next(struct vm_area_struct *vma,
        struct prio_tree_iter *iter);
static inline __attribute__((always_inline)) void vma_nonlinear_insert(struct vm_area_struct *vma,
                                        struct list_head *list)
{
        vma->shared.vm_set.parent = ((void *)0);
        list_add_tail(&vma->shared.vm_set.list, list);
}
extern int __vm_enough_memory(long pages, int cap_sys_admin);
extern void vma_adjust(struct vm_area_struct *vma, unsigned long start,
        unsigned long end, unsigned long pgoff, struct vm_area_struct *insert);
extern struct vm_area_struct *vma_merge(struct mm_struct *,
        struct vm_area_struct *prev, unsigned long addr, unsigned long end,
        unsigned long vm_flags, struct anon_vma *, struct file *, unsigned long,
        struct mempolicy *);
extern struct anon_vma *find_mergeable_anon_vma(struct vm_area_struct *);
extern int split_vma(struct mm_struct *,
        struct vm_area_struct *, unsigned long addr, int new_below);
extern int insert_vm_struct(struct mm_struct *, struct vm_area_struct *);
extern void __vma_link_rb(struct mm_struct *, struct vm_area_struct *,
        struct rb_node **, struct rb_node *);
extern struct vm_area_struct *copy_vma(struct vm_area_struct **,
        unsigned long addr, unsigned long len, unsigned long pgoff);
extern void exit_mmap(struct mm_struct *);
extern int may_expand_vm(struct mm_struct *mm, unsigned long npages);
extern unsigned long get_unmapped_area(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
extern unsigned long do_mmap_pgoff(struct file *file, unsigned long addr,
        unsigned long len, unsigned long prot,
        unsigned long flag, unsigned long pgoff);
static inline __attribute__((always_inline)) unsigned long do_mmap(struct file *file, unsigned long addr,
        unsigned long len, unsigned long prot,
        unsigned long flag, unsigned long offset)
{
        unsigned long ret = -22;
        if ((offset + (((len)+(1UL << 12)-1)&(~((1UL << 12)-1)))) < offset)
                goto out;
        if (!(offset & ~(~((1UL << 12)-1))))
                ret = do_mmap_pgoff(file, addr, len, prot, flag, offset >> 12);
out:
        return ret;
}
extern int do_munmap(struct mm_struct *, unsigned long, size_t);
extern unsigned long do_brk(unsigned long, unsigned long);
extern unsigned long page_unuse(struct page *);
extern void truncate_inode_pages(struct address_space *, loff_t);
extern struct page *filemap_nopage(struct vm_area_struct *, unsigned long, int *);
extern int filemap_populate(struct vm_area_struct *, unsigned long,
                unsigned long, pgprot_t, unsigned long, int);
int write_one_page(struct page *page, int wait);
int do_page_cache_readahead(struct address_space *mapping, struct file *filp,
                        unsigned long offset, unsigned long nr_to_read);
int force_page_cache_readahead(struct address_space *mapping, struct file *filp,
                        unsigned long offset, unsigned long nr_to_read);
unsigned long page_cache_readahead(struct address_space *mapping,
                          struct file_ra_state *ra,
                          struct file *filp,
                          unsigned long offset,
                          unsigned long size);
void handle_ra_miss(struct address_space *mapping,
                    struct file_ra_state *ra, unsigned long offset);
unsigned long max_sane_readahead(unsigned long nr);
extern int expand_stack(struct vm_area_struct * vma, unsigned long address);
extern struct vm_area_struct * find_vma(struct mm_struct * mm, unsigned long addr);
extern struct vm_area_struct * find_vma_prev(struct mm_struct * mm, unsigned long addr,
                                             struct vm_area_struct **pprev);
static inline __attribute__((always_inline)) struct vm_area_struct * find_vma_intersection(struct mm_struct * mm, unsigned long start_addr, unsigned long end_addr)
{
        struct vm_area_struct * vma = find_vma(mm,start_addr);
        if (vma && end_addr <= vma->vm_start)
                vma = ((void *)0);
        return vma;
}
static inline __attribute__((always_inline)) unsigned long vma_pages(struct vm_area_struct *vma)
{
        return (vma->vm_end - vma->vm_start) >> 12;
}
extern struct vm_area_struct *find_extend_vma(struct mm_struct *mm, unsigned long addr);
extern struct page * vmalloc_to_page(void *addr);
extern unsigned long vmalloc_to_pfn(void *addr);
extern struct page * follow_page(struct mm_struct *mm, unsigned long address,
                int write);
extern int check_user_page_readable(struct mm_struct *mm, unsigned long address);
int remap_pfn_range(struct vm_area_struct *, unsigned long,
                unsigned long, unsigned long, pgprot_t);
void __vm_stat_account(struct mm_struct *, unsigned long, struct file *, long);
static inline __attribute__((always_inline)) void vm_stat_account(struct vm_area_struct *vma)
{
        __vm_stat_account(vma->vm_mm, vma->vm_flags, vma->vm_file,
                                                        vma_pages(vma));
}
static inline __attribute__((always_inline)) void vm_stat_unaccount(struct vm_area_struct *vma)
{
        __vm_stat_account(vma->vm_mm, vma->vm_flags, vma->vm_file,
                                                        -vma_pages(vma));
}
extern void update_mem_hiwater(struct task_struct *tsk);
static inline __attribute__((always_inline)) void
kernel_map_pages(struct page *page, int numpages, int enable)
{
}
extern struct vm_area_struct *get_gate_vma(struct task_struct *tsk);
int in_gate_area_no_task(unsigned long addr);
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;
struct termios {
        tcflag_t c_iflag;
        tcflag_t c_oflag;
        tcflag_t c_cflag;
        tcflag_t c_lflag;
        cc_t c_line;
        cc_t c_cc[19];
};
struct winsize {
        unsigned short ws_row;
        unsigned short ws_col;
        unsigned short ws_xpixel;
        unsigned short ws_ypixel;
};
struct termio {
        unsigned short c_iflag;
        unsigned short c_oflag;
        unsigned short c_cflag;
        unsigned short c_lflag;
        unsigned char c_line;
        unsigned char c_cc[8];
};
struct cdev {
        struct kobject kobj;
        struct module *owner;
        struct file_operations *ops;
        struct list_head list;
        dev_t dev;
        unsigned int count;
};
void cdev_init(struct cdev *, struct file_operations *);
struct cdev *cdev_alloc(void);
void cdev_put(struct cdev *p);
int cdev_add(struct cdev *, dev_t, unsigned);
void cdev_del(struct cdev *);
void cd_forget(struct inode *);
struct tty_struct;
struct tty_operations {
        int (*open)(struct tty_struct * tty, struct file * filp);
        void (*close)(struct tty_struct * tty, struct file * filp);
        int (*write)(struct tty_struct * tty,
                      const unsigned char *buf, int count);
        void (*put_char)(struct tty_struct *tty, unsigned char ch);
        void (*flush_chars)(struct tty_struct *tty);
        int (*write_room)(struct tty_struct *tty);
        int (*chars_in_buffer)(struct tty_struct *tty);
        int (*ioctl)(struct tty_struct *tty, struct file * file,
                    unsigned int cmd, unsigned long arg);
        void (*set_termios)(struct tty_struct *tty, struct termios * old);
        void (*throttle)(struct tty_struct * tty);
        void (*unthrottle)(struct tty_struct * tty);
        void (*stop)(struct tty_struct *tty);
        void (*start)(struct tty_struct *tty);
        void (*hangup)(struct tty_struct *tty);
        void (*break_ctl)(struct tty_struct *tty, int state);
        void (*flush_buffer)(struct tty_struct *tty);
        void (*set_ldisc)(struct tty_struct *tty);
        void (*wait_until_sent)(struct tty_struct *tty, int timeout);
        void (*send_xchar)(struct tty_struct *tty, char ch);
        int (*read_proc)(char *page, char **start, off_t off,
                          int count, int *eof, void *data);
        int (*write_proc)(struct file *file, const char *buffer,
                          unsigned long count, void *data);
        int (*tiocmget)(struct tty_struct *tty, struct file *file);
        int (*tiocmset)(struct tty_struct *tty, struct file *file,
                        unsigned int set, unsigned int clear);
};
struct tty_driver {
        int magic;
        struct cdev cdev;
        struct module *owner;
        const char *driver_name;
        const char *devfs_name;
        const char *name;
        int name_base;
        int major;
        int minor_start;
        int minor_num;
        int num;
        short type;
        short subtype;
        struct termios init_termios;
        int flags;
        int refcount;
        struct proc_dir_entry *proc_entry;
        struct tty_driver *other;
        struct tty_struct **ttys;
        struct termios **termios;
        struct termios **termios_locked;
        void *driver_state;
        int (*open)(struct tty_struct * tty, struct file * filp);
        void (*close)(struct tty_struct * tty, struct file * filp);
        int (*write)(struct tty_struct * tty,
                      const unsigned char *buf, int count);
        void (*put_char)(struct tty_struct *tty, unsigned char ch);
        void (*flush_chars)(struct tty_struct *tty);
        int (*write_room)(struct tty_struct *tty);
        int (*chars_in_buffer)(struct tty_struct *tty);
        int (*ioctl)(struct tty_struct *tty, struct file * file,
                    unsigned int cmd, unsigned long arg);
        void (*set_termios)(struct tty_struct *tty, struct termios * old);
        void (*throttle)(struct tty_struct * tty);
        void (*unthrottle)(struct tty_struct * tty);
        void (*stop)(struct tty_struct *tty);
        void (*start)(struct tty_struct *tty);
        void (*hangup)(struct tty_struct *tty);
        void (*break_ctl)(struct tty_struct *tty, int state);
        void (*flush_buffer)(struct tty_struct *tty);
        void (*set_ldisc)(struct tty_struct *tty);
        void (*wait_until_sent)(struct tty_struct *tty, int timeout);
        void (*send_xchar)(struct tty_struct *tty, char ch);
        int (*read_proc)(char *page, char **start, off_t off,
                          int count, int *eof, void *data);
        int (*write_proc)(struct file *file, const char *buffer,
                          unsigned long count, void *data);
        int (*tiocmget)(struct tty_struct *tty, struct file *file);
        int (*tiocmset)(struct tty_struct *tty, struct file *file,
                        unsigned int set, unsigned int clear);
        struct list_head tty_drivers;
};
extern struct list_head tty_drivers;
struct tty_driver *alloc_tty_driver(int lines);
void put_tty_driver(struct tty_driver *driver);
void tty_set_operations(struct tty_driver *driver, struct tty_operations *op);
struct tty_ldisc {
        int magic;
        char *name;
        int num;
        int flags;
        int (*open)(struct tty_struct *);
        void (*close)(struct tty_struct *);
        void (*flush_buffer)(struct tty_struct *tty);
        ssize_t (*chars_in_buffer)(struct tty_struct *tty);
        ssize_t (*read)(struct tty_struct * tty, struct file * file,
                        unsigned char * buf, size_t nr);
        ssize_t (*write)(struct tty_struct * tty, struct file * file,
                         const unsigned char * buf, size_t nr);
        int (*ioctl)(struct tty_struct * tty, struct file * file,
                         unsigned int cmd, unsigned long arg);
        void (*set_termios)(struct tty_struct *tty, struct termios * old);
        unsigned int (*poll)(struct tty_struct *, struct file *,
                             struct poll_table_struct *);
        int (*hangup)(struct tty_struct *tty);
        void (*receive_buf)(struct tty_struct *, const unsigned char *cp,
                               char *fp, int count);
        int (*receive_room)(struct tty_struct *);
        void (*write_wakeup)(struct tty_struct *);
        struct module *owner;
        int refcount;
};
struct screen_info {
        u8 orig_x;
        u8 orig_y;
        u16 dontuse1;
        u16 orig_video_page;
        u8 orig_video_mode;
        u8 orig_video_cols;
        u16 unused2;
        u16 orig_video_ega_bx;
        u16 unused3;
        u8 orig_video_lines;
        u8 orig_video_isVGA;
        u16 orig_video_points;
        u16 lfb_width;
        u16 lfb_height;
        u16 lfb_depth;
        u32 lfb_base;
        u32 lfb_size;
        u16 dontuse2, dontuse3;
        u16 lfb_linelength;
        u8 red_size;
        u8 red_pos;
        u8 green_size;
        u8 green_pos;
        u8 blue_size;
        u8 blue_pos;
        u8 rsvd_size;
        u8 rsvd_pos;
        u16 vesapm_seg;
        u16 vesapm_off;
        u16 pages;
        u16 vesa_attributes;
        u32 capabilities;
};
extern struct screen_info screen_info;
struct tty_flip_buffer {
        struct work_struct work;
        struct semaphore pty_sem;
        char *char_buf_ptr;
        unsigned char *flag_buf_ptr;
        int count;
        int buf_num;
        unsigned char char_buf[2*512];
        char flag_buf[2*512];
        unsigned char slop[4];
};
struct device;
struct tty_struct {
        int magic;
        struct tty_driver *driver;
        int index;
        struct tty_ldisc ldisc;
        struct semaphore termios_sem;
        struct termios *termios, *termios_locked;
        char name[64];
        int pgrp;
        int session;
        unsigned long flags;
        int count;
        struct winsize winsize;
        unsigned char stopped:1, hw_stopped:1, flow_stopped:1, packet:1;
        unsigned char low_latency:1, warned:1;
        unsigned char ctrl_status;
        struct tty_struct *link;
        struct fasync_struct *fasync;
        struct tty_flip_buffer flip;
        int max_flip_cnt;
        int alt_speed;
        wait_queue_head_t write_wait;
        wait_queue_head_t read_wait;
        struct work_struct hangup_work;
        void *disc_data;
        void *driver_data;
        struct list_head tty_files;
        unsigned int column;
        unsigned char lnext:1, erasing:1, raw:1, real_raw:1, icanon:1;
        unsigned char closing:1;
        unsigned short minimum_to_wake;
        unsigned long overrun_time;
        int num_overrun;
        unsigned long process_char_map[256/(8*sizeof(unsigned long))];
        char *read_buf;
        int read_head;
        int read_tail;
        int read_cnt;
        unsigned long read_flags[4096/(8*sizeof(unsigned long))];
        int canon_data;
        unsigned long canon_head;
        unsigned int canon_column;
        struct semaphore atomic_read;
        struct semaphore atomic_write;
        unsigned char *write_buf;
        int write_cnt;
        spinlock_t read_lock;
        struct work_struct SAK_work;
};
extern void tty_write_flush(struct tty_struct *);
extern struct termios tty_std_termios;
extern int fg_console, last_console, want_console;
extern int kmsg_redirect;
extern void console_init(void);
extern int vcs_init(void);
extern int tty_paranoia_check(struct tty_struct *tty, struct inode *inode,
                              const char *routine);
extern char *tty_name(struct tty_struct *tty, char *buf);
extern void tty_wait_until_sent(struct tty_struct * tty, long timeout);
extern int tty_check_change(struct tty_struct * tty);
extern void stop_tty(struct tty_struct * tty);
extern void start_tty(struct tty_struct * tty);
extern int tty_register_ldisc(int disc, struct tty_ldisc *new_ldisc);
extern int tty_unregister_ldisc(int disc);
extern int tty_register_driver(struct tty_driver *driver);
extern int tty_unregister_driver(struct tty_driver *driver);
extern void tty_register_device(struct tty_driver *driver, unsigned index, struct device *dev);
extern void tty_unregister_device(struct tty_driver *driver, unsigned index);
extern int tty_read_raw_data(struct tty_struct *tty, unsigned char *bufp,
                             int buflen);
extern void tty_write_message(struct tty_struct *tty, char *msg);
extern int is_orphaned_pgrp(int pgrp);
extern int is_ignored(int sig);
extern int tty_signal(int sig, struct tty_struct *tty);
extern void tty_hangup(struct tty_struct * tty);
extern void tty_vhangup(struct tty_struct * tty);
extern void tty_unhangup(struct file *filp);
extern int tty_hung_up_p(struct file * filp);
extern void do_SAK(struct tty_struct *tty);
extern void disassociate_ctty(int priv);
extern void tty_flip_buffer_push(struct tty_struct *tty);
extern int tty_get_baud_rate(struct tty_struct *tty);
extern int tty_termios_baud_rate(struct termios *termios);
extern struct tty_ldisc *tty_ldisc_ref(struct tty_struct *);
extern void tty_ldisc_deref(struct tty_ldisc *);
extern struct tty_ldisc *tty_ldisc_ref_wait(struct tty_struct *);
extern struct tty_ldisc *tty_ldisc_get(int);
extern void tty_ldisc_put(int);
extern void tty_wakeup(struct tty_struct *tty);
extern void tty_ldisc_flush(struct tty_struct *tty);
struct semaphore;
extern struct semaphore tty_sem;
extern struct tty_ldisc tty_ldisc_N_TTY;
extern int n_tty_ioctl(struct tty_struct * tty, struct file * file,
                       unsigned int cmd, unsigned long arg);
extern void serial_console_init(void);
extern int pcxe_open(struct tty_struct *tty, struct file *filp);
extern void console_print(const char *);
extern int vt_ioctl(struct tty_struct *tty, struct file * file,
                    unsigned int cmd, unsigned long arg);
static inline __attribute__((always_inline)) dev_t tty_devnum(struct tty_struct *tty)
{
        return (((tty->driver->major) << 20) | (tty->driver->minor_start)) + tty->index;
}
struct exception_table_entry
{
        unsigned long insn, fixup;
};
extern int fixup_exception(struct pt_regs *regs);
extern void __get_user_1(void);
extern void __get_user_2(void);
extern void __get_user_4(void);
extern void __put_user_bad(void);
extern void __put_user_1(void);
extern void __put_user_2(void);
extern void __put_user_4(void);
extern void __put_user_8(void);
struct __large_struct { unsigned long buf[100]; };
extern long __get_user_bad(void);
unsigned long __copy_to_user_ll(void *to,
                                const void *from, unsigned long n);
unsigned long __copy_from_user_ll(void *to,
                                const void *from, unsigned long n);
static inline __attribute__((always_inline)) unsigned long
__copy_to_user_inatomic(void *to, const void *from, unsigned long n)
{
        if (__builtin_constant_p(n)) {
                unsigned long ret;
                switch (n) {
                case 1:
                        do { __typeof__(*((u8 *)to)) __pus_tmp = *(u8 *)from; ret = 0; if(__builtin_expect(!!(__copy_to_user_ll((u8 *)to, &__pus_tmp, 1) != 0), 0)) ret = 1; } while (0);
                        return ret;
                case 2:
                        do { __typeof__(*((u16 *)to)) __pus_tmp = *(u16 *)from; ret = 0; if(__builtin_expect(!!(__copy_to_user_ll((u16 *)to, &__pus_tmp, 2) != 0), 0)) ret = 2; } while (0);
                        return ret;
                case 4:
                        do { __typeof__(*((u32 *)to)) __pus_tmp = *(u32 *)from; ret = 0; if(__builtin_expect(!!(__copy_to_user_ll((u32 *)to, &__pus_tmp, 4) != 0), 0)) ret = 4; } while (0);
                        return ret;
                }
        }
        return __copy_to_user_ll(to, from, n);
}
static inline __attribute__((always_inline)) unsigned long
__copy_to_user(void *to, const void *from, unsigned long n)
{
       do { do { } while (0); } while (0);
       return __copy_to_user_inatomic(to, from, n);
}
static inline __attribute__((always_inline)) unsigned long
__copy_from_user_inatomic(void *to, const void *from, unsigned long n)
{
        if (__builtin_constant_p(n)) {
                unsigned long ret;
                switch (n) {
                case 1:
                        do { ret = 0; (void)0; switch (1) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(struct __large_struct *)(from))), "i"(1), "0"(ret));break; default: (*(u8 *)to) = __get_user_bad(); } } while (0);
                        return ret;
                case 2:
                        do { ret = 0; (void)0; switch (2) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(struct __large_struct *)(from))), "i"(2), "0"(ret));break; default: (*(u16 *)to) = __get_user_bad(); } } while (0);
                        return ret;
                case 4:
                        do { ret = 0; (void)0; switch (4) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=q" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(struct __large_struct *)(from))), "i"(4), "0"(ret));break; default: (*(u32 *)to) = __get_user_bad(); } } while (0);
                        return ret;
                }
        }
        return __copy_from_user_ll(to, from, n);
}
static inline __attribute__((always_inline)) unsigned long
__copy_from_user(void *to, const void *from, unsigned long n)
{
       do { do { } while (0); } while (0);
       return __copy_from_user_inatomic(to, from, n);
}
unsigned long copy_to_user(void *to,
                                const void *from, unsigned long n);
unsigned long copy_from_user(void *to,
                                const void *from, unsigned long n);
long strncpy_from_user(char *dst, const char *src,
                                long count);
long __strncpy_from_user(char *dst,
                                const char *src, long count);
long strnlen_user(const char *str, long n);
unsigned long clear_user(void *mem, unsigned long len);
unsigned long __clear_user(void *mem, unsigned long len);
struct vc_data;
extern unsigned char inverse_translate(struct vc_data *conp, int glyph);
extern unsigned short *set_translate(int m, struct vc_data *vc);
extern int conv_uni_to_pc(struct vc_data *conp, long ucs);
struct vt_mode {
        char mode;
        char waitv;
        short relsig;
        short acqsig;
        short frsig;
};
struct vt_stat {
        unsigned short v_active;
        unsigned short v_signal;
        unsigned short v_state;
};
struct vt_sizes {
        unsigned short v_rows;
        unsigned short v_cols;
        unsigned short v_scrollsize;
};
struct vt_consize {
        unsigned short v_rows;
        unsigned short v_cols;
        unsigned short v_vlin;
        unsigned short v_clin;
        unsigned short v_vcol;
        unsigned short v_ccol;
};
struct vt_struct;
struct vc_data {
        unsigned short vc_num;
        unsigned int vc_cols;
        unsigned int vc_rows;
        unsigned int vc_size_row;
        unsigned int vc_scan_lines;
        unsigned long vc_origin;
        unsigned long vc_scr_end;
        unsigned long vc_visible_origin;
        unsigned int vc_top, vc_bottom;
        const struct consw *vc_sw;
        unsigned short *vc_screenbuf;
        unsigned int vc_screenbuf_size;
        unsigned char vc_mode;
        unsigned char vc_attr;
        unsigned char vc_def_color;
        unsigned char vc_color;
        unsigned char vc_s_color;
        unsigned char vc_ulcolor;
        unsigned char vc_halfcolor;
        unsigned int vc_cursor_type;
        unsigned short vc_complement_mask;
        unsigned short vc_s_complement_mask;
        unsigned int vc_x, vc_y;
        unsigned int vc_saved_x, vc_saved_y;
        unsigned long vc_pos;
        unsigned short vc_hi_font_mask;
        struct console_font vc_font;
        unsigned short vc_video_erase_char;
        unsigned int vc_state;
        unsigned int vc_npar,vc_par[16];
        struct tty_struct *vc_tty;
        struct vt_mode vt_mode;
        int vt_pid;
        int vt_newvt;
        wait_queue_head_t paste_wait;
        unsigned int vc_charset : 1;
        unsigned int vc_s_charset : 1;
        unsigned int vc_disp_ctrl : 1;
        unsigned int vc_toggle_meta : 1;
        unsigned int vc_decscnm : 1;
        unsigned int vc_decom : 1;
        unsigned int vc_decawm : 1;
        unsigned int vc_deccm : 1;
        unsigned int vc_decim : 1;
        unsigned int vc_deccolm : 1;
        unsigned int vc_intensity : 2;
        unsigned int vc_underline : 1;
        unsigned int vc_blink : 1;
        unsigned int vc_reverse : 1;
        unsigned int vc_s_intensity : 2;
        unsigned int vc_s_underline : 1;
        unsigned int vc_s_blink : 1;
        unsigned int vc_s_reverse : 1;
        unsigned int vc_ques : 1;
        unsigned int vc_need_wrap : 1;
        unsigned int vc_can_do_color : 1;
        unsigned int vc_report_mouse : 2;
        unsigned int vc_kmalloced : 1;
        unsigned char vc_utf : 1;
        unsigned char vc_utf_count;
                 int vc_utf_char;
        unsigned int vc_tab_stop[8];
        unsigned char vc_palette[16*3];
        unsigned short * vc_translate;
        unsigned char vc_G0_charset;
        unsigned char vc_G1_charset;
        unsigned char vc_saved_G0;
        unsigned char vc_saved_G1;
        unsigned int vc_bell_pitch;
        unsigned int vc_bell_duration;
        struct vc_data **vc_display_fg;
        unsigned long vc_uni_pagedir;
        unsigned long *vc_uni_pagedir_loc;
};
struct vc {
        struct vc_data *d;
};
extern struct vc vc_cons [63];
extern void kd_mksound(unsigned int hz, unsigned int ticks);
extern int kbd_rate(struct kbd_repeat *rep);
int vc_allocate(unsigned int console);
int vc_cons_allocated(unsigned int console);
int vc_resize(struct vc_data *vc, unsigned int cols, unsigned int lines);
void vc_disallocate(unsigned int console);
void reset_palette(struct vc_data *vc);
void do_blank_screen(int entering_gfx);
void do_unblank_screen(int leaving_gfx);
void unblank_screen(void);
void poke_blanked_console(void);
int con_font_op(struct vc_data *vc, struct console_font_op *op);
int con_set_cmap(unsigned char *cmap);
int con_get_cmap(unsigned char *cmap);
void scrollback(struct vc_data *vc, int lines);
void scrollfront(struct vc_data *vc, int lines);
void update_region(struct vc_data *vc, unsigned long start, int count);
void redraw_screen(struct vc_data *vc, int is_switch);
struct tty_struct;
int tioclinux(struct tty_struct *tty, unsigned long arg);
struct unimapinit;
struct unipair;
int con_set_trans_old(unsigned char * table);
int con_get_trans_old(unsigned char * table);
int con_set_trans_new(unsigned short * table);
int con_get_trans_new(unsigned short * table);
int con_clear_unimap(struct vc_data *vc, struct unimapinit *ui);
int con_set_unimap(struct vc_data *vc, ushort ct, struct unipair *list);
int con_get_unimap(struct vc_data *vc, ushort ct, ushort *uct, struct unipair *list);
int con_set_default_unimap(struct vc_data *vc);
void con_free_unimap(struct vc_data *vc);
void con_protect_unimap(struct vc_data *vc, int rdonly);
int con_copy_unimap(struct vc_data *dst_vc, struct vc_data *src_vc);
int vt_waitactive(int vt);
void change_console(struct vc_data *new_vc);
void reset_vc(struct vc_data *vc);
extern char con_buf[(0 ? 256 : (1UL << 12))];
extern struct semaphore con_buf_sem;
static unsigned short translations[][256] = {
  {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x001e, 0x001f,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
    0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
    0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
    0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
    0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
    0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
    0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f,
    0x00a0, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7,
    0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af,
    0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7,
    0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf,
    0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7,
    0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
    0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7,
    0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00df,
    0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7,
    0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef,
    0x00f0, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7,
    0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd, 0x00fe, 0x00ff
  },
  {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x001e, 0x001f,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
    0x0028, 0x0029, 0x002a, 0x2192, 0x2190, 0x2191, 0x2193, 0x002f,
    0x2588, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
    0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
    0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x00a0,
    0x25c6, 0x2592, 0x2409, 0x240c, 0x240d, 0x240a, 0x00b0, 0x00b1,
    0x2591, 0x240b, 0x2518, 0x2510, 0x250c, 0x2514, 0x253c, 0x23ba,
    0x23bb, 0x2500, 0x23bc, 0x23bd, 0x251c, 0x2524, 0x2534, 0x252c,
    0x2502, 0x2264, 0x2265, 0x03c0, 0x2260, 0x00a3, 0x00b7, 0x007f,
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
    0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f,
    0x00a0, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7,
    0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af,
    0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7,
    0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf,
    0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7,
    0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
    0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7,
    0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00df,
    0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7,
    0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef,
    0x00f0, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7,
    0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd, 0x00fe, 0x00ff
  },
  {
    0x0000, 0x263a, 0x263b, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022,
    0x25d8, 0x25cb, 0x25d9, 0x2642, 0x2640, 0x266a, 0x266b, 0x263c,
    0x25b6, 0x25c0, 0x2195, 0x203c, 0x00b6, 0x00a7, 0x25ac, 0x21a8,
    0x2191, 0x2193, 0x2192, 0x2190, 0x221f, 0x2194, 0x25b2, 0x25bc,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
    0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
    0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
    0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
    0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
    0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x2302,
    0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7,
    0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
    0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
    0x00ff, 0x00d6, 0x00dc, 0x00a2, 0x00a3, 0x00a5, 0x20a7, 0x0192,
    0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
    0x00bf, 0x2310, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
    0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
    0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
    0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
    0x03b1, 0x00df, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x00b5, 0x03c4,
    0x03a6, 0x0398, 0x03a9, 0x03b4, 0x221e, 0x03c6, 0x03b5, 0x2229,
    0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
    0x00b0, 0x2219, 0x00b7, 0x221a, 0x207f, 0x00b2, 0x25a0, 0x00a0
  },
  {
    0xf000, 0xf001, 0xf002, 0xf003, 0xf004, 0xf005, 0xf006, 0xf007,
    0xf008, 0xf009, 0xf00a, 0xf00b, 0xf00c, 0xf00d, 0xf00e, 0xf00f,
    0xf010, 0xf011, 0xf012, 0xf013, 0xf014, 0xf015, 0xf016, 0xf017,
    0xf018, 0xf019, 0xf01a, 0xf01b, 0xf01c, 0xf01d, 0xf01e, 0xf01f,
    0xf020, 0xf021, 0xf022, 0xf023, 0xf024, 0xf025, 0xf026, 0xf027,
    0xf028, 0xf029, 0xf02a, 0xf02b, 0xf02c, 0xf02d, 0xf02e, 0xf02f,
    0xf030, 0xf031, 0xf032, 0xf033, 0xf034, 0xf035, 0xf036, 0xf037,
    0xf038, 0xf039, 0xf03a, 0xf03b, 0xf03c, 0xf03d, 0xf03e, 0xf03f,
    0xf040, 0xf041, 0xf042, 0xf043, 0xf044, 0xf045, 0xf046, 0xf047,
    0xf048, 0xf049, 0xf04a, 0xf04b, 0xf04c, 0xf04d, 0xf04e, 0xf04f,
    0xf050, 0xf051, 0xf052, 0xf053, 0xf054, 0xf055, 0xf056, 0xf057,
    0xf058, 0xf059, 0xf05a, 0xf05b, 0xf05c, 0xf05d, 0xf05e, 0xf05f,
    0xf060, 0xf061, 0xf062, 0xf063, 0xf064, 0xf065, 0xf066, 0xf067,
    0xf068, 0xf069, 0xf06a, 0xf06b, 0xf06c, 0xf06d, 0xf06e, 0xf06f,
    0xf070, 0xf071, 0xf072, 0xf073, 0xf074, 0xf075, 0xf076, 0xf077,
    0xf078, 0xf079, 0xf07a, 0xf07b, 0xf07c, 0xf07d, 0xf07e, 0xf07f,
    0xf080, 0xf081, 0xf082, 0xf083, 0xf084, 0xf085, 0xf086, 0xf087,
    0xf088, 0xf089, 0xf08a, 0xf08b, 0xf08c, 0xf08d, 0xf08e, 0xf08f,
    0xf090, 0xf091, 0xf092, 0xf093, 0xf094, 0xf095, 0xf096, 0xf097,
    0xf098, 0xf099, 0xf09a, 0xf09b, 0xf09c, 0xf09d, 0xf09e, 0xf09f,
    0xf0a0, 0xf0a1, 0xf0a2, 0xf0a3, 0xf0a4, 0xf0a5, 0xf0a6, 0xf0a7,
    0xf0a8, 0xf0a9, 0xf0aa, 0xf0ab, 0xf0ac, 0xf0ad, 0xf0ae, 0xf0af,
    0xf0b0, 0xf0b1, 0xf0b2, 0xf0b3, 0xf0b4, 0xf0b5, 0xf0b6, 0xf0b7,
    0xf0b8, 0xf0b9, 0xf0ba, 0xf0bb, 0xf0bc, 0xf0bd, 0xf0be, 0xf0bf,
    0xf0c0, 0xf0c1, 0xf0c2, 0xf0c3, 0xf0c4, 0xf0c5, 0xf0c6, 0xf0c7,
    0xf0c8, 0xf0c9, 0xf0ca, 0xf0cb, 0xf0cc, 0xf0cd, 0xf0ce, 0xf0cf,
    0xf0d0, 0xf0d1, 0xf0d2, 0xf0d3, 0xf0d4, 0xf0d5, 0xf0d6, 0xf0d7,
    0xf0d8, 0xf0d9, 0xf0da, 0xf0db, 0xf0dc, 0xf0dd, 0xf0de, 0xf0df,
    0xf0e0, 0xf0e1, 0xf0e2, 0xf0e3, 0xf0e4, 0xf0e5, 0xf0e6, 0xf0e7,
    0xf0e8, 0xf0e9, 0xf0ea, 0xf0eb, 0xf0ec, 0xf0ed, 0xf0ee, 0xf0ef,
    0xf0f0, 0xf0f1, 0xf0f2, 0xf0f3, 0xf0f4, 0xf0f5, 0xf0f6, 0xf0f7,
    0xf0f8, 0xf0f9, 0xf0fa, 0xf0fb, 0xf0fc, 0xf0fd, 0xf0fe, 0xf0ff
  }
};
static int inv_translate[63];
struct uni_pagedir {
        u16 **uni_pgdir[32];
        unsigned long refcount;
        unsigned long sum;
        unsigned char *inverse_translations[4];
        int readonly;
};
static struct uni_pagedir *dflt;
static void set_inverse_transl(struct vc_data *conp, struct uni_pagedir *p, int i)
{
        int j, glyph;
        unsigned short *t = translations[i];
        unsigned char *q;
        if (!p) return;
        q = p->inverse_translations[i];
        if (!q) {
                q = p->inverse_translations[i] = (unsigned char *)
                        kmalloc(512, (0x10u | 0x40u | 0x80u));
                if (!q) return;
        }
        (__builtin_constant_p(0) ? (__builtin_constant_p((512)) ? __constant_c_and_count_memset(((q)),((0x01010101UL*(unsigned char)(0))),((512))) : __constant_c_memset(((q)),((0x01010101UL*(unsigned char)(0))),((512)))) : (__builtin_constant_p((512)) ? __memset_generic((((q))),(((0))),(((512)))) : __memset_generic(((q)),((0)),((512)))));
        for (j = 0; j < 256; j++) {
                glyph = conv_uni_to_pc(conp, t[j]);
                if (glyph >= 0 && glyph < 512 && q[glyph] < 32) {
                        q[glyph] = j;
                }
        }
}
unsigned short *set_translate(int m, struct vc_data *vc)
{
        inv_translate[vc->vc_num] = m;
        return translations[m];
}
unsigned char inverse_translate(struct vc_data *conp, int glyph)
{
        struct uni_pagedir *p;
        if (glyph < 0 || glyph >= 512)
                return 0;
        else if (!(p = (struct uni_pagedir *)*conp->vc_uni_pagedir_loc) ||
                 !p->inverse_translations[inv_translate[conp->vc_num]])
                return glyph;
        else
                return p->inverse_translations[inv_translate[conp->vc_num]][glyph];
}
static void update_user_maps(void)
{
        int i;
        struct uni_pagedir *p, *q = ((void *)0);
        for (i = 0; i < 63; i++) {
                if (!vc_cons_allocated(i))
                        continue;
                p = (struct uni_pagedir *)*vc_cons[i].d->vc_uni_pagedir_loc;
                if (p && p != q) {
                        set_inverse_transl(vc_cons[i].d, p, 3);
                        q = p;
                }
        }
}
int con_set_trans_old(unsigned char * arg)
{
        int i;
        unsigned short *p = translations[3];
        if (!(__builtin_expect(!!(({ unsigned long flag,sum; (void)0; asm("addl %3,%1 ; sbbl %0,%0; cmpl %1,%4; sbbl $0,%0" :"=&r" (flag), "=r" (sum) :"1" (arg),"g" ((int)(256)),"g" (current_thread_info()->addr_limit.seg)); flag; }) == 0), 1)))
                return -14;
        for (i=0; i<256 ; i++) {
                unsigned char uc;
                ({ long __gu_err; unsigned long __gu_val; do { __gu_err = 0; (void)0; switch ((sizeof(*(arg+i)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=q" (__gu_val) : "m"((*(struct __large_struct *)(((arg+i))))), "i"(-14), "0"(__gu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((arg+i))))), "i"(-14), "0"(__gu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((arg+i))))), "i"(-14), "0"(__gu_err));break; default: (__gu_val) = __get_user_bad(); } } while (0); ((uc)) = (__typeof__(*((arg+i))))__gu_val; __gu_err; });
                p[i] = 0xF000 | uc;
        }
        update_user_maps();
        return 0;
}
int con_get_trans_old(unsigned char * arg)
{
        int i, ch;
        unsigned short *p = translations[3];
        if (!(__builtin_expect(!!(({ unsigned long flag,sum; (void)0; asm("addl %3,%1 ; sbbl %0,%0; cmpl %1,%4; sbbl $0,%0" :"=&r" (flag), "=r" (sum) :"1" (arg),"g" ((int)(256)),"g" (current_thread_info()->addr_limit.seg)); flag; }) == 0), 1)))
                return -14;
        for (i=0; i<256 ; i++)
          {
            ch = conv_uni_to_pc(vc_cons[fg_console].d, p[i]);
            ({ long __pu_err; do { __typeof__(*(((arg+i)))) __pus_tmp = ((__typeof__(*(arg+i)))((ch & ~0xff) ? 0 : ch)); __pu_err = 0; if(__builtin_expect(!!(__copy_to_user_ll(((arg+i)), &__pus_tmp, (sizeof(*(arg+i)))) != 0), 0)) __pu_err = -14; } while (0); __pu_err; });
          }
        return 0;
}
int con_set_trans_new(ushort * arg)
{
        int i;
        unsigned short *p = translations[3];
        if (!(__builtin_expect(!!(({ unsigned long flag,sum; (void)0; asm("addl %3,%1 ; sbbl %0,%0; cmpl %1,%4; sbbl $0,%0" :"=&r" (flag), "=r" (sum) :"1" (arg),"g" ((int)(256*sizeof(unsigned short))),"g" (current_thread_info()->addr_limit.seg)); flag; }) == 0), 1)))
                return -14;
        for (i=0; i<256 ; i++) {
                unsigned short us;
                ({ long __gu_err; unsigned long __gu_val; do { __gu_err = 0; (void)0; switch ((sizeof(*(arg+i)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=q" (__gu_val) : "m"((*(struct __large_struct *)(((arg+i))))), "i"(-14), "0"(__gu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((arg+i))))), "i"(-14), "0"(__gu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((arg+i))))), "i"(-14), "0"(__gu_err));break; default: (__gu_val) = __get_user_bad(); } } while (0); ((us)) = (__typeof__(*((arg+i))))__gu_val; __gu_err; });
                p[i] = us;
        }
        update_user_maps();
        return 0;
}
int con_get_trans_new(ushort * arg)
{
        int i;
        unsigned short *p = translations[3];
        if (!(__builtin_expect(!!(({ unsigned long flag,sum; (void)0; asm("addl %3,%1 ; sbbl %0,%0; cmpl %1,%4; sbbl $0,%0" :"=&r" (flag), "=r" (sum) :"1" (arg),"g" ((int)(256*sizeof(unsigned short))),"g" (current_thread_info()->addr_limit.seg)); flag; }) == 0), 1)))
                return -14;
        for (i=0; i<256 ; i++)
          ({ long __pu_err; do { __typeof__(*(((arg+i)))) __pus_tmp = ((__typeof__(*(arg+i)))(p[i])); __pu_err = 0; if(__builtin_expect(!!(__copy_to_user_ll(((arg+i)), &__pus_tmp, (sizeof(*(arg+i)))) != 0), 0)) __pu_err = -14; } while (0); __pu_err; });
        return 0;
}
extern u8 dfont_unicount[];
extern u16 dfont_unitable[];
static void con_release_unimap(struct uni_pagedir *p)
{
        u16 **p1;
        int i, j;
        if (p == dflt) dflt = ((void *)0);
        for (i = 0; i < 32; i++) {
                if ((p1 = p->uni_pgdir[i]) != ((void *)0)) {
                        for (j = 0; j < 32; j++)
                                if (p1[j])
                                        kfree(p1[j]);
                        kfree(p1);
                }
                p->uni_pgdir[i] = ((void *)0);
        }
        for (i = 0; i < 4; i++)
                if (p->inverse_translations[i]) {
                        kfree(p->inverse_translations[i]);
                        p->inverse_translations[i] = ((void *)0);
                }
}
void con_free_unimap(struct vc_data *vc)
{
        struct uni_pagedir *p;
        p = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
        if (!p)
                return;
        *vc->vc_uni_pagedir_loc = 0;
        if (--p->refcount)
                return;
        con_release_unimap(p);
        kfree(p);
}
static int con_unify_unimap(struct vc_data *conp, struct uni_pagedir *p)
{
        int i, j, k;
        struct uni_pagedir *q;
        for (i = 0; i < 63; i++) {
                if (!vc_cons_allocated(i))
                        continue;
                q = (struct uni_pagedir *)*vc_cons[i].d->vc_uni_pagedir_loc;
                if (!q || q == p || q->sum != p->sum)
                        continue;
                for (j = 0; j < 32; j++) {
                        u16 **p1, **q1;
                        p1 = p->uni_pgdir[j]; q1 = q->uni_pgdir[j];
                        if (!p1 && !q1)
                                continue;
                        if (!p1 || !q1)
                                break;
                        for (k = 0; k < 32; k++) {
                                if (!p1[k] && !q1[k])
                                        continue;
                                if (!p1[k] || !q1[k])
                                        break;
                                if (__builtin_memcmp(p1[k], q1[k], 64*sizeof(u16)))
                                        break;
                        }
                        if (k < 32)
                                break;
                }
                if (j == 32) {
                        q->refcount++;
                        *conp->vc_uni_pagedir_loc = (unsigned long)q;
                        con_release_unimap(p);
                        kfree(p);
                        return 1;
                }
        }
        return 0;
}
static int
con_insert_unipair(struct uni_pagedir *p, u_short unicode, u_short fontpos)
{
        int i, n;
        u16 **p1, *p2;
        if (!(p1 = p->uni_pgdir[n = unicode >> 11])) {
                p1 = p->uni_pgdir[n] = kmalloc(32*sizeof(u16 *), (0x10u | 0x40u | 0x80u));
                if (!p1) return -12;
                for (i = 0; i < 32; i++)
                        p1[i] = ((void *)0);
        }
        if (!(p2 = p1[n = (unicode >> 6) & 0x1f])) {
                p2 = p1[n] = kmalloc(64*sizeof(u16), (0x10u | 0x40u | 0x80u));
                if (!p2) return -12;
                (__builtin_constant_p(0xff) ? (__builtin_constant_p((64*sizeof(u16))) ? __constant_c_and_count_memset(((p2)),((0x01010101UL*(unsigned char)(0xff))),((64*sizeof(u16)))) : __constant_c_memset(((p2)),((0x01010101UL*(unsigned char)(0xff))),((64*sizeof(u16))))) : (__builtin_constant_p((64*sizeof(u16))) ? __memset_generic((((p2))),(((0xff))),(((64*sizeof(u16))))) : __memset_generic(((p2)),((0xff)),((64*sizeof(u16))))));
        }
        p2[unicode & 0x3f] = fontpos;
        p->sum += (fontpos << 20) + unicode;
        return 0;
}
int con_clear_unimap(struct vc_data *vc, struct unimapinit *ui)
{
        struct uni_pagedir *p, *q;
        p = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
        if (p && p->readonly) return -5;
        if (!p || --p->refcount) {
                q = (struct uni_pagedir *)kmalloc(sizeof(*p), (0x10u | 0x40u | 0x80u));
                if (!q) {
                        if (p) p->refcount++;
                        return -12;
                }
                (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(*q))) ? __constant_c_and_count_memset(((q)),((0x01010101UL*(unsigned char)(0))),((sizeof(*q)))) : __constant_c_memset(((q)),((0x01010101UL*(unsigned char)(0))),((sizeof(*q))))) : (__builtin_constant_p((sizeof(*q))) ? __memset_generic((((q))),(((0))),(((sizeof(*q))))) : __memset_generic(((q)),((0)),((sizeof(*q))))));
                q->refcount=1;
                *vc->vc_uni_pagedir_loc = (unsigned long)q;
        } else {
                if (p == dflt) dflt = ((void *)0);
                p->refcount++;
                p->sum = 0;
                con_release_unimap(p);
        }
        return 0;
}
int con_set_unimap(struct vc_data *vc, ushort ct, struct unipair *list)
{
        int err = 0, err1, i;
        struct uni_pagedir *p, *q;
        p = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
        if (p->readonly) return -5;
        if (!ct) return 0;
        if (p->refcount > 1) {
                int j, k;
                u16 **p1, *p2, l;
                err1 = con_clear_unimap(vc, ((void *)0));
                if (err1) return err1;
                q = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
                for (i = 0, l = 0; i < 32; i++)
                if ((p1 = p->uni_pgdir[i]))
                        for (j = 0; j < 32; j++)
                        if ((p2 = p1[j]))
                                for (k = 0; k < 64; k++, l++)
                                if (p2[k] != 0xffff) {
                                        err1 = con_insert_unipair(q, l, p2[k]);
                                        if (err1) {
                                                p->refcount++;
                                                *vc->vc_uni_pagedir_loc = (unsigned long)p;
                                                con_release_unimap(q);
                                                kfree(q);
                                                return err1;
                                        }
                                }
                p = q;
        } else if (p == dflt)
                dflt = ((void *)0);
        while (ct--) {
                unsigned short unicode, fontpos;
                ({ long __gu_err; unsigned long __gu_val; do { __gu_err = 0; (void)0; switch ((sizeof(*(&list->unicode)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=q" (__gu_val) : "m"((*(struct __large_struct *)(((&list->unicode))))), "i"(-14), "0"(__gu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((&list->unicode))))), "i"(-14), "0"(__gu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((&list->unicode))))), "i"(-14), "0"(__gu_err));break; default: (__gu_val) = __get_user_bad(); } } while (0); ((unicode)) = (__typeof__(*((&list->unicode))))__gu_val; __gu_err; });
                ({ long __gu_err; unsigned long __gu_val; do { __gu_err = 0; (void)0; switch ((sizeof(*(&list->fontpos)))) { case 1: __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=q" (__gu_val) : "m"((*(struct __large_struct *)(((&list->fontpos))))), "i"(-14), "0"(__gu_err));break; case 2: __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((&list->fontpos))))), "i"(-14), "0"(__gu_err));break; case 4: __asm__ __volatile__( "1:	mov""l"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	movl %3,%0\n" "	xor""l"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" ".section __ex_table,\"a\"\n" "	.align 4\n" "	.long 1b,3b\n" ".previous" : "=r"(__gu_err), "=r" (__gu_val) : "m"((*(struct __large_struct *)(((&list->fontpos))))), "i"(-14), "0"(__gu_err));break; default: (__gu_val) = __get_user_bad(); } } while (0); ((fontpos)) = (__typeof__(*((&list->fontpos))))__gu_val; __gu_err; });
                if ((err1 = con_insert_unipair(p, unicode,fontpos)) != 0)
                        err = err1;
                        list++;
        }
        if (con_unify_unimap(vc, p))
                return err;
        for (i = 0; i <= 3; i++)
                set_inverse_transl(vc, p, i);
        return err;
}
int con_set_default_unimap(struct vc_data *vc)
{
        int i, j, err = 0, err1;
        u16 *q;
        struct uni_pagedir *p;
        if (dflt) {
                p = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
                if (p == dflt)
                        return 0;
                dflt->refcount++;
                *vc->vc_uni_pagedir_loc = (unsigned long)dflt;
                if (p && --p->refcount) {
                        con_release_unimap(p);
                        kfree(p);
                }
                return 0;
        }
        err = con_clear_unimap(vc, ((void *)0));
        if (err) return err;
        p = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
        q = dfont_unitable;
        for (i = 0; i < 256; i++)
                for (j = dfont_unicount[i]; j; j--) {
                        err1 = con_insert_unipair(p, *(q++), i);
                        if (err1)
                                err = err1;
                }
        if (con_unify_unimap(vc, p)) {
                dflt = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
                return err;
        }
        for (i = 0; i <= 3; i++)
                set_inverse_transl(vc, p, i);
        dflt = p;
        return err;
}
extern void *__crc_con_set_default_unimap __attribute__((weak)); static const unsigned long __kcrctab_con_set_default_unimap __attribute__((__unused__)) __attribute__((section("__kcrctab" ""), unused)) = (unsigned long) &__crc_con_set_default_unimap; static const char __kstrtab_con_set_default_unimap[] __attribute__((section("__ksymtab_strings"))) = "" "con_set_default_unimap"; static const struct kernel_symbol __ksymtab_con_set_default_unimap __attribute__((__unused__)) __attribute__((section("__ksymtab" ""), unused)) = { (unsigned long)&con_set_default_unimap, __kstrtab_con_set_default_unimap };
int con_copy_unimap(struct vc_data *dst_vc, struct vc_data *src_vc)
{
        struct uni_pagedir *q;
        if (!*src_vc->vc_uni_pagedir_loc)
                return -22;
        if (*dst_vc->vc_uni_pagedir_loc == *src_vc->vc_uni_pagedir_loc)
                return 0;
        con_free_unimap(dst_vc);
        q = (struct uni_pagedir *)*src_vc->vc_uni_pagedir_loc;
        q->refcount++;
        *dst_vc->vc_uni_pagedir_loc = (long)q;
        return 0;
}
int con_get_unimap(struct vc_data *vc, ushort ct, ushort *uct, struct unipair *list)
{
        int i, j, k, ect;
        u16 **p1, *p2;
        struct uni_pagedir *p;
        ect = 0;
        if (*vc->vc_uni_pagedir_loc) {
                p = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
                for (i = 0; i < 32; i++)
                if ((p1 = p->uni_pgdir[i]))
                        for (j = 0; j < 32; j++)
                        if ((p2 = *(p1++)))
                                for (k = 0; k < 64; k++) {
                                        if (*p2 < 512 && ect++ < ct) {
                                                ({ long __pu_err; do { __typeof__(*(((&list->unicode)))) __pus_tmp = ((__typeof__(*(&list->unicode)))((u_short)((i<<11)+(j<<6)+k))); __pu_err = 0; if(__builtin_expect(!!(__copy_to_user_ll(((&list->unicode)), &__pus_tmp, (sizeof(*(&list->unicode)))) != 0), 0)) __pu_err = -14; } while (0); __pu_err; });
                                                ({ long __pu_err; do { __typeof__(*(((&list->fontpos)))) __pus_tmp = ((__typeof__(*(&list->fontpos)))((u_short) *p2)); __pu_err = 0; if(__builtin_expect(!!(__copy_to_user_ll(((&list->fontpos)), &__pus_tmp, (sizeof(*(&list->fontpos)))) != 0), 0)) __pu_err = -14; } while (0); __pu_err; });
                                                list++;
                                        }
                                        p2++;
                                }
        }
        ({ long __pu_err; do { __typeof__(*(((uct)))) __pus_tmp = ((__typeof__(*(uct)))(ect)); __pu_err = 0; if(__builtin_expect(!!(__copy_to_user_ll(((uct)), &__pus_tmp, (sizeof(*(uct)))) != 0), 0)) __pu_err = -14; } while (0); __pu_err; });
        return ((ect <= ct) ? 0 : -12);
}
void con_protect_unimap(struct vc_data *vc, int rdonly)
{
        struct uni_pagedir *p = (struct uni_pagedir *)*vc->vc_uni_pagedir_loc;
        if (p)
                p->readonly = rdonly;
}
int
conv_uni_to_pc(struct vc_data *conp, long ucs)
{
        int h;
        u16 **p1, *p2;
        struct uni_pagedir *p;
        if (ucs > 0xffff)
                ucs = 0xfffd;
        else if (ucs < 0x20 || ucs >= 0xfffe)
                return -1;
        else if (ucs == 0xfeff || (ucs >= 0x200a && ucs <= 0x200f))
                return -2;
        else if ((ucs & ~0x01FF) == 0xF000)
                return ucs & 0x01FF;
        if (!*conp->vc_uni_pagedir_loc)
                return -3;
        p = (struct uni_pagedir *)*conp->vc_uni_pagedir_loc;
        if ((p1 = p->uni_pgdir[ucs >> 11]) &&
            (p2 = p1[(ucs >> 6) & 0x1f]) &&
            (h = p2[ucs & 0x3f]) < 512)
                return h;
        return -4;
}
void __attribute__ ((__section__ (".init.text")))
console_map_init(void)
{
        int i;
        for (i = 0; i < 63; i++)
                if (vc_cons_allocated(i) && !*vc_cons[i].d->vc_uni_pagedir_loc)
                        con_set_default_unimap(vc_cons[i].d);
}
extern void *__crc_con_copy_unimap __attribute__((weak)); static const unsigned long __kcrctab_con_copy_unimap __attribute__((__unused__)) __attribute__((section("__kcrctab" ""), unused)) = (unsigned long) &__crc_con_copy_unimap; static const char __kstrtab_con_copy_unimap[] __attribute__((section("__ksymtab_strings"))) = "" "con_copy_unimap"; static const struct kernel_symbol __ksymtab_con_copy_unimap __attribute__((__unused__)) __attribute__((section("__ksymtab" ""), unused)) = { (unsigned long)&con_copy_unimap, __kstrtab_con_copy_unimap };
struct vc_data dst_vc;
struct vc_data src_vc;
struct unipair upair;
void * f(void *) {
  console_map_init();
  con_protect_unimap(&dst_vc, 0);
  con_copy_unimap(&dst_vc, &src_vc);
  con_free_unimap(&dst_vc);
  con_get_unimap(&dst_vc, 0, 0, &upair);
  con_set_trans_old(0);
  con_get_trans_old(0);
  con_set_trans_new(0);
  con_get_trans_new(0);
  inverse_translate(&dst_vc, 0);
  return 0;
}
typedef int pthread_t;
int main() {
  pthread_t t;
  pthread_create(&t, (void*)0, f, (void*)0);
  pthread_create(&t, (void*)0, f, (void*)0);
}
