# 1 "drivers/net/yellowfin.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "drivers/net/yellowfin.c"
# 59 "drivers/net/yellowfin.c"
static int debug = 1;

static int max_interrupt_work = 20;
static int mtu;
# 72 "drivers/net/yellowfin.c"
static int dma_ctrl = 0x004A0263;
static int fifo_cfg = 0x0020;




static int rx_copybreak;






static int options[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
static int full_duplex[8] = {-1, -1, -1, -1, -1, -1, -1, -1};


static int gx_fix;
# 111 "drivers/net/yellowfin.c"
# 1 "include/linux/module.h" 1
# 9 "include/linux/module.h"
# 1 "include/linux/config.h" 1



# 1 "include/linux/autoconf.h" 1
# 5 "include/linux/config.h" 2
# 10 "include/linux/module.h" 2
# 1 "include/linux/sched.h" 1



# 1 "include/asm/param.h" 1
# 5 "include/linux/sched.h" 2


# 1 "include/linux/capability.h" 1
# 16 "include/linux/capability.h"
# 1 "include/linux/types.h" 1
# 13 "include/linux/types.h"
# 1 "include/linux/posix_types.h" 1



# 1 "include/linux/stddef.h" 1



# 1 "include/linux/compiler.h" 1
# 44 "include/linux/compiler.h"
# 1 "include/linux/compiler-gcc3.h" 1



# 1 "include/linux/compiler-gcc.h" 1
# 5 "include/linux/compiler-gcc3.h" 2
# 45 "include/linux/compiler.h" 2
# 5 "include/linux/stddef.h" 2
# 5 "include/linux/posix_types.h" 2
# 36 "include/linux/posix_types.h"
typedef struct {
        unsigned long fds_bits [(1024/(8 * sizeof(unsigned long)))];
} __kernel_fd_set;


typedef void (*__kernel_sighandler_t)(int);


typedef int __kernel_key_t;
typedef int __kernel_mqd_t;

# 1 "include/asm/posix_types.h" 1
# 10 "include/asm/posix_types.h"
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
# 48 "include/linux/posix_types.h" 2
# 14 "include/linux/types.h" 2
# 1 "include/asm/types.h" 1





typedef unsigned short umode_t;






typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;


typedef __signed__ long long __s64;
typedef unsigned long long __u64;
# 40 "include/asm/types.h"
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
# 15 "include/linux/types.h" 2



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
# 55 "include/linux/types.h"
typedef __kernel_loff_t loff_t;
# 64 "include/linux/types.h"
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
# 135 "include/linux/types.h"
typedef unsigned long sector_t;
# 159 "include/linux/types.h"
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
# 17 "include/linux/capability.h" 2
# 32 "include/linux/capability.h"
typedef struct __user_cap_header_struct {
        __u32 version;
        int pid;
} *cap_user_header_t;

typedef struct __user_cap_data_struct {
        __u32 effective;
        __u32 permitted;
        __u32 inheritable;
} *cap_user_data_t;



# 1 "include/linux/spinlock.h" 1
# 50 "include/linux/spinlock.h"
# 1 "include/linux/preempt.h" 1
# 10 "include/linux/preempt.h"
# 1 "include/linux/linkage.h" 1




# 1 "include/asm/linkage.h" 1
# 6 "include/linux/linkage.h" 2
# 11 "include/linux/preempt.h" 2
# 51 "include/linux/spinlock.h" 2


# 1 "include/linux/thread_info.h" 1
# 13 "include/linux/thread_info.h"
struct restart_block {
        long (*fn)(struct restart_block *);
        unsigned long arg0, arg1, arg2, arg3;
};

extern long do_no_restart_syscall(struct restart_block *parm);

# 1 "include/linux/bitops.h" 1
# 11 "include/linux/bitops.h"
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





# 1 "include/asm/bitops.h" 1
# 42 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void set_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__( "lock ; "
                "btsl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
# 59 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void __set_bit(int nr, volatile unsigned long * addr)
{
        __asm__(
                "btsl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
# 77 "include/asm/bitops.h"
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
# 104 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void __change_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__(
                "btcl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
# 122 "include/asm/bitops.h"
static inline __attribute__((always_inline)) void change_bit(int nr, volatile unsigned long * addr)
{
        __asm__ __volatile__( "lock ; "
                "btcl %1,%0"
                :"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
}
# 139 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int test_and_set_bit(int nr, volatile unsigned long * addr)
{
        int oldbit;

        __asm__ __volatile__( "lock ; "
                "btsl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr) : "memory");
        return oldbit;
}
# 159 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int __test_and_set_bit(int nr, volatile unsigned long * addr)
{
        int oldbit;

        __asm__(
                "btsl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr));
        return oldbit;
}
# 179 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int test_and_clear_bit(int nr, volatile unsigned long * addr)
{
        int oldbit;

        __asm__ __volatile__( "lock ; "
                "btrl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr) : "memory");
        return oldbit;
}
# 199 "include/asm/bitops.h"
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
# 230 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int test_and_change_bit(int nr, volatile unsigned long* addr)
{
        int oldbit;

        __asm__ __volatile__( "lock ; "
                "btcl %2,%1\n\tsbbl %0,%0"
                :"=r" (oldbit),"=m" ((*(volatile long *) addr))
                :"Ir" (nr) : "memory");
        return oldbit;
}
# 250 "include/asm/bitops.h"
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
# 281 "include/asm/bitops.h"
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
# 335 "include/asm/bitops.h"
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
# 384 "include/asm/bitops.h"
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
# 405 "include/asm/bitops.h"
static inline __attribute__((always_inline)) int ffs(int x)
{
        int r;

        __asm__("bsfl %1,%0\n\t"
                "jnz 1f\n\t"
                "movl $-1,%0\n"
                "1:" : "=r" (r) : "rm" (x));
        return r+1;
}
# 78 "include/linux/bitops.h" 2

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
# 130 "include/linux/bitops.h"
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
# 21 "include/linux/thread_info.h" 2
# 1 "include/asm/thread_info.h" 1
# 14 "include/asm/thread_info.h"
# 1 "include/asm/page.h" 1
# 45 "include/asm/page.h"
extern int nx_enabled;

extern unsigned long long __supported_pte_mask;
typedef struct { unsigned long pte_low, pte_high; } pte_t;
typedef struct { unsigned long long pmd; } pmd_t;
typedef struct { unsigned long long pgd; } pgd_t;
typedef struct { unsigned long long pgprot; } pgprot_t;
# 104 "include/asm/page.h"
extern unsigned int __VMALLOC_RESERVE;

extern int sysctl_legacy_va_layout;

extern int page_is_ram(unsigned long pagenr);
# 144 "include/asm/page.h"
# 1 "include/asm-generic/page.h" 1
# 10 "include/asm-generic/page.h"
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
# 145 "include/asm/page.h" 2
# 15 "include/asm/thread_info.h" 2


# 1 "include/asm/processor.h" 1
# 10 "include/asm/processor.h"
# 1 "include/asm/vm86.h" 1
# 68 "include/asm/vm86.h"
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
# 145 "include/asm/vm86.h"
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
# 184 "include/asm/vm86.h"
        unsigned long flags;
        unsigned long screen_bitmap;
        unsigned long cpu_type;
        struct revectored_struct int_revectored;
        struct revectored_struct int21_revectored;
        struct vm86plus_info_struct vm86plus;
        struct pt_regs *regs32;
# 201 "include/asm/vm86.h"
};

void handle_vm86_fault(struct kernel_vm86_regs *, long);
int handle_vm86_trap(struct kernel_vm86_regs *, long, int);
# 11 "include/asm/processor.h" 2
# 1 "include/asm/math_emu.h" 1



# 1 "include/asm/sigcontext.h" 1
# 20 "include/asm/sigcontext.h"
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
# 5 "include/asm/math_emu.h" 2

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
# 12 "include/asm/processor.h" 2
# 1 "include/asm/segment.h" 1
# 13 "include/asm/processor.h" 2



# 1 "include/asm/cpufeature.h" 1
# 17 "include/asm/processor.h" 2
# 1 "include/asm/msr.h" 1
# 27 "include/asm/msr.h"
static inline __attribute__((always_inline)) void wrmsrl (unsigned long msr, unsigned long long val)
{
        unsigned long lo, hi;
        lo = (unsigned long) val;
        hi = val >> 32;
        __asm__ __volatile__("wrmsr" : : "c" (msr), "a" (lo), "d" (hi));
}
# 18 "include/asm/processor.h" 2
# 1 "include/asm/system.h" 1




# 1 "include/linux/kernel.h" 1
# 10 "include/linux/kernel.h"
# 1 "/usr/lib/gcc-lib/i386-redhat-linux/3.2.3/include/stdarg.h" 1
# 43 "/usr/lib/gcc-lib/i386-redhat-linux/3.2.3/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
# 110 "/usr/lib/gcc-lib/i386-redhat-linux/3.2.3/include/stdarg.h"
typedef __gnuc_va_list va_list;
# 11 "include/linux/kernel.h" 2





# 1 "include/asm/byteorder.h" 1
# 14 "include/asm/byteorder.h"
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
# 57 "include/asm/byteorder.h"
# 1 "include/linux/byteorder/little_endian.h" 1
# 12 "include/linux/byteorder/little_endian.h"
# 1 "include/linux/byteorder/swab.h" 1
# 133 "include/linux/byteorder/swab.h"
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
# 13 "include/linux/byteorder/little_endian.h" 2
# 43 "include/linux/byteorder/little_endian.h"
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
# 104 "include/linux/byteorder/little_endian.h"
# 1 "include/linux/byteorder/generic.h" 1
# 154 "include/linux/byteorder/generic.h"
extern __u32 ntohl(__be32);
extern __be32 htonl(__u32);
extern __u16 ntohs(__be16);
extern __be16 htons(__u16);
# 105 "include/linux/byteorder/little_endian.h" 2
# 58 "include/asm/byteorder.h" 2
# 17 "include/linux/kernel.h" 2
# 1 "include/asm/bug.h" 1
# 25 "include/asm/bug.h"
# 1 "include/asm-generic/bug.h" 1
# 26 "include/asm/bug.h" 2
# 18 "include/linux/kernel.h" 2

extern const char linux_banner[];
# 42 "include/linux/kernel.h"
extern int console_printk[];






struct completion;
# 88 "include/linux/kernel.h"
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
# 140 "include/linux/kernel.h"
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
# 193 "include/linux/kernel.h"
extern void dump_stack(void);
# 293 "include/linux/kernel.h"
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
# 6 "include/asm/system.h" 2






struct task_struct;
extern struct task_struct * __switch_to(struct task_struct *prev, struct task_struct *next) __attribute__((regparm(3)));
# 59 "include/asm/system.h"
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
# 152 "include/asm/system.h"
static inline __attribute__((always_inline)) unsigned long get_limit(unsigned long segment)
{
        unsigned long __limit;
        __asm__("lsll %1,%0"
                :"=r" (__limit):"r" (segment));
        return __limit+1;
}







struct __xchg_dummy { unsigned long a[100]; };
# 184 "include/asm/system.h"
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
# 229 "include/asm/system.h"
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
# 264 "include/asm/system.h"
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
# 485 "include/asm/system.h"
void disable_hlt(void);
void enable_hlt(void);

extern int es7000_plat;
void cpu_idle_wait(void);

extern unsigned long arch_align_stack(unsigned long sp);
# 19 "include/asm/processor.h" 2
# 1 "include/linux/cache.h" 1





# 1 "include/asm/cache.h" 1
# 7 "include/linux/cache.h" 2
# 20 "include/asm/processor.h" 2

# 1 "include/linux/threads.h" 1
# 22 "include/asm/processor.h" 2
# 1 "include/asm/percpu.h" 1



# 1 "include/asm-generic/percpu.h" 1







extern unsigned long __per_cpu_offset[8];
# 5 "include/asm/percpu.h" 2
# 23 "include/asm/processor.h" 2


extern int tsc_disable;

struct desc_struct {
        unsigned long a,b;
};
# 48 "include/asm/processor.h"
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
# 87 "include/asm/processor.h"
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
# 140 "include/asm/processor.h"
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
# 229 "include/asm/processor.h"
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
# 280 "include/asm/processor.h"
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
# 334 "include/asm/processor.h"
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
# 483 "include/asm/processor.h"
static inline __attribute__((always_inline)) void load_esp0(struct tss_struct *tss, struct thread_struct *thread)
{
        tss->esp0 = thread->esp0;

        if (__builtin_expect(!!(tss->ss1 != thread->sysenter_cs), 0)) {
                tss->ss1 = thread->sysenter_cs;
                __asm__ __volatile__("wrmsr" : : "c" (0x174), "a" (thread->sysenter_cs), "d" (0));
        }
}
# 518 "include/asm/processor.h"
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
# 569 "include/asm/processor.h"
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
# 682 "include/asm/processor.h"
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
# 18 "include/asm/thread_info.h" 2
# 28 "include/asm/thread_info.h"
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
# 88 "include/asm/thread_info.h"
static inline __attribute__((always_inline)) struct thread_info *current_thread_info(void)
{
        struct thread_info *ti;
        __asm__("andl %%esp,%0; ":"=r" (ti) : "0" (~((8192) - 1)));
        return ti;
}


register unsigned long current_stack_pointer asm("esp") __attribute__((__unused__));
# 22 "include/linux/thread_info.h" 2
# 30 "include/linux/thread_info.h"
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
# 54 "include/linux/spinlock.h" 2

# 1 "include/linux/stringify.h" 1
# 56 "include/linux/spinlock.h" 2
# 80 "include/linux/spinlock.h"
# 1 "include/linux/spinlock_types.h" 1
# 13 "include/linux/spinlock_types.h"
# 1 "include/asm/spinlock_types.h" 1







typedef struct {
        volatile unsigned int slock;
} raw_spinlock_t;



typedef struct {
        volatile unsigned int lock;
} raw_rwlock_t;
# 14 "include/linux/spinlock_types.h" 2




typedef struct {
        raw_spinlock_t raw_lock;







} spinlock_t;



typedef struct {
        raw_rwlock_t raw_lock;







} rwlock_t;
# 81 "include/linux/spinlock.h" 2

extern int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) generic__raw_read_trylock(raw_rwlock_t *lock);





# 1 "include/asm/spinlock.h" 1



# 1 "include/asm/atomic.h" 1
# 24 "include/asm/atomic.h"
typedef struct { volatile int counter; } atomic_t;
# 52 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) void atomic_add(int i, atomic_t *v)
{
        __asm__ __volatile__(
                "lock ; " "addl %1,%0"
                :"=m" (v->counter)
                :"ir" (i), "m" (v->counter));
}
# 67 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) void atomic_sub(int i, atomic_t *v)
{
        __asm__ __volatile__(
                "lock ; " "subl %1,%0"
                :"=m" (v->counter)
                :"ir" (i), "m" (v->counter));
}
# 84 "include/asm/atomic.h"
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
# 131 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_dec_and_test(atomic_t *v)
{
        unsigned char c;

        __asm__ __volatile__(
                "lock ; " "decl %0; sete %1"
                :"=m" (v->counter), "=qm" (c)
                :"m" (v->counter) : "memory");
        return c != 0;
}
# 150 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_inc_and_test(atomic_t *v)
{
        unsigned char c;

        __asm__ __volatile__(
                "lock ; " "incl %0; sete %1"
                :"=m" (v->counter), "=qm" (c)
                :"m" (v->counter) : "memory");
        return c != 0;
}
# 170 "include/asm/atomic.h"
static __inline__ __attribute__((always_inline)) int atomic_add_negative(int i, atomic_t *v)
{
        unsigned char c;

        __asm__ __volatile__(
                "lock ; " "addl %2,%0; sets %1"
                :"=m" (v->counter), "=qm" (c)
                :"ir" (i), "m" (v->counter) : "memory");
        return c;
}
# 188 "include/asm/atomic.h"
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
# 5 "include/asm/spinlock.h" 2
# 1 "include/asm/rwlock.h" 1
# 6 "include/asm/spinlock.h" 2
# 51 "include/asm/spinlock.h"
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
# 103 "include/asm/spinlock.h"
static inline __attribute__((always_inline)) void __raw_spin_unlock(raw_spinlock_t *lock)
{
        char oldval = 1;

        __asm__ __volatile__(
                "xchgb %b0, %1" :"=q" (oldval), "=m" (lock->slock) :"0" (oldval) : "memory"
        );
}
# 150 "include/asm/spinlock.h"
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
# 89 "include/linux/spinlock.h" 2





void spin_lock_init(spinlock_t *lock);
# 109 "include/linux/spinlock.h"
# 1 "include/linux/spinlock_api_smp.h" 1
# 18 "include/linux/spinlock_api_smp.h"
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
# 110 "include/linux/spinlock.h" 2
# 220 "include/linux/spinlock.h"
extern int _atomic_dec_and_lock(atomic_t *atomic, spinlock_t *lock);
# 46 "include/linux/capability.h" 2
# 57 "include/linux/capability.h"
typedef __u32 kernel_cap_t;
# 294 "include/linux/capability.h"
extern kernel_cap_t cap_bset;
# 322 "include/linux/capability.h"
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
# 8 "include/linux/sched.h" 2



# 1 "include/linux/timex.h" 1
# 58 "include/linux/timex.h"
# 1 "include/linux/time.h" 1






# 1 "include/linux/seqlock.h" 1
# 33 "include/linux/seqlock.h"
typedef struct {
        unsigned sequence;
        spinlock_t lock;
} seqlock_t;
# 50 "include/linux/seqlock.h"
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
# 91 "include/linux/seqlock.h"
static inline __attribute__((always_inline)) int read_seqretry(const seqlock_t *sl, unsigned iv)
{
        asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
        return (iv & 1) | (sl->sequence ^ iv);
}
# 105 "include/linux/seqlock.h"
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
# 8 "include/linux/time.h" 2




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
# 36 "include/linux/time.h"
static __inline__ __attribute__((always_inline)) int timespec_equal(struct timespec *a, struct timespec *b)
{
        return (a->tv_sec == b->tv_sec) && (a->tv_nsec == b->tv_nsec);
}
# 56 "include/linux/time.h"
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
# 134 "include/linux/time.h"
struct itimerspec {
        struct timespec it_interval;
        struct timespec it_value;
};

struct itimerval {
        struct timeval it_interval;
        struct timeval it_value;
};
# 59 "include/linux/timex.h" 2

# 1 "include/asm/param.h" 1
# 61 "include/linux/timex.h" 2
# 1 "include/asm/timex.h" 1
# 33 "include/asm/timex.h"
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
# 62 "include/linux/timex.h" 2
# 135 "include/linux/timex.h"
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
# 227 "include/linux/timex.h"
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
# 334 "include/linux/timex.h"
static inline __attribute__((always_inline)) void
time_interpolator_reset(void)
{
}
# 12 "include/linux/sched.h" 2
# 1 "include/linux/jiffies.h" 1







# 1 "include/asm/param.h" 1
# 9 "include/linux/jiffies.h" 2
# 1 "include/asm/div64.h" 1
# 38 "include/asm/div64.h"
static inline __attribute__((always_inline)) long
div_ll_X_l_rem(long long divs, long div, long *rem)
{
        long dum2;
      __asm__("divl %2":"=a"(dum2), "=d"(*rem)
      : "rm"(div), "A"(divs));

        return dum2;

}
# 10 "include/linux/jiffies.h" 2
# 84 "include/linux/jiffies.h"
extern u64 __attribute__((section(".data"))) jiffies_64;
extern unsigned long volatile __attribute__((section(".data"))) jiffies;


u64 get_jiffies_64(void);
# 255 "include/linux/jiffies.h"
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
# 314 "include/linux/jiffies.h"
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
# 353 "include/linux/jiffies.h"
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
# 424 "include/linux/jiffies.h"
        x *= (( ((1000000UL * 1000 / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (((1000000UL * 1000 % (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))) << 8) + (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250))) / 2) / (( ((1193182 / ((1193182 + 250/2) / 250)) << 8) + (((1193182 % ((1193182 + 250/2) / 250)) << 8) + ((1193182 + 250/2) / 250) / 2) / ((1193182 + 250/2) / 250)))));
        ({ unsigned long __upper, __low, __high, __mod, __base; __base = (((1000000000L) / 100)); asm("":"=a" (__low), "=d" (__high):"A" (x)); __upper = __high; if (__high) { __upper = __high % (__base); __high = __high / (__base); } asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (__base), "0" (__low), "1" (__upper)); asm("":"=A" (x):"a" (__low),"d" (__high)); __mod; });

        return x;
}

static inline __attribute__((always_inline)) u64 nsec_to_clock_t(u64 x)
{

        ({ unsigned long __upper, __low, __high, __mod, __base; __base = (((1000000000L) / 100)); asm("":"=a" (__low), "=d" (__high):"A" (x)); __upper = __high; if (__high) { __upper = __high % (__base); __high = __high / (__base); } asm("divl %2":"=a" (__low), "=d" (__mod):"rm" (__base), "0" (__low), "1" (__upper)); asm("":"=A" (x):"a" (__low),"d" (__high)); __mod; });
# 447 "include/linux/jiffies.h"
        return x;
}
# 13 "include/linux/sched.h" 2
# 1 "include/linux/rbtree.h" 1
# 100 "include/linux/rbtree.h"
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
# 14 "include/linux/sched.h" 2

# 1 "include/linux/cpumask.h" 1
# 82 "include/linux/cpumask.h"
# 1 "include/linux/bitmap.h" 1







# 1 "include/linux/string.h" 1
# 16 "include/linux/string.h"
extern char * strpbrk(const char *,const char *);
extern char * strsep(char **,const char *);
extern __kernel_size_t strspn(const char *,const char *);
extern __kernel_size_t strcspn(const char *,const char *);




# 1 "include/asm/string.h" 1
# 30 "include/asm/string.h"
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
# 327 "include/asm/string.h"
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
# 370 "include/asm/string.h"
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
# 478 "include/asm/string.h"
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
# 25 "include/linux/string.h" 2
# 33 "include/linux/string.h"
size_t strlcpy(char *, const char *, size_t);
# 42 "include/linux/string.h"
extern size_t strlcat(char *, const char *, __kernel_size_t);
# 51 "include/linux/string.h"
extern int strnicmp(const char *, const char *, __kernel_size_t);





extern char * strnchr(const char *, size_t, int);
# 85 "include/linux/string.h"
extern int __builtin_memcmp(const void *,const void *,__kernel_size_t);





extern char *kstrdup(const char *s, gfp_t gfp);
# 9 "include/linux/bitmap.h" 2
# 75 "include/linux/bitmap.h"
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
# 83 "include/linux/cpumask.h" 2


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
# 269 "include/linux/cpumask.h"
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
# 362 "include/linux/cpumask.h"
extern cpumask_t cpu_possible_map;
extern cpumask_t cpu_online_map;
extern cpumask_t cpu_present_map;
# 16 "include/linux/sched.h" 2
# 1 "include/linux/errno.h" 1



# 1 "include/asm/errno.h" 1



# 1 "include/asm-generic/errno.h" 1



# 1 "include/asm-generic/errno-base.h" 1
# 5 "include/asm-generic/errno.h" 2
# 5 "include/asm/errno.h" 2
# 5 "include/linux/errno.h" 2
# 17 "include/linux/sched.h" 2
# 1 "include/linux/nodemask.h" 1
# 82 "include/linux/nodemask.h"
# 1 "include/linux/numa.h" 1
# 83 "include/linux/nodemask.h" 2


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
# 248 "include/linux/nodemask.h"
static inline __attribute__((always_inline)) int __first_unset_node(const nodemask_t *maskp)
{
        return ({ int __x = ((1 << 0)); int __y = (find_first_zero_bit(maskp->bits, (1 << 0))); __x < __y ? __x: __y; });

}
# 282 "include/linux/nodemask.h"
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
# 326 "include/linux/nodemask.h"
extern nodemask_t node_online_map;
extern nodemask_t node_possible_map;
# 18 "include/linux/sched.h" 2


# 1 "include/asm/semaphore.h" 1
# 41 "include/asm/semaphore.h"
# 1 "include/linux/wait.h" 1
# 23 "include/linux/wait.h"
# 1 "include/linux/list.h" 1






# 1 "include/linux/prefetch.h" 1
# 58 "include/linux/prefetch.h"
static inline __attribute__((always_inline)) void prefetch_range(void *addr, size_t len)
{

        char *cp;
        char *end = addr + len;

        for (cp = addr; cp < end; cp += (4*(1 << (4))))
                prefetch(cp);

}
# 8 "include/linux/list.h" 2
# 28 "include/linux/list.h"
struct list_head {
        struct list_head *next, *prev;
};
# 47 "include/linux/list.h"
static inline __attribute__((always_inline)) void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
        next->prev = new;
        new->next = next;
        new->prev = prev;
        prev->next = new;
}
# 65 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}
# 78 "include/linux/list.h"
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
# 115 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_add_rcu(struct list_head *new, struct list_head *head)
{
        __list_add_rcu(new, head, head->next);
}
# 136 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_add_tail_rcu(struct list_head *new,
                                        struct list_head *head)
{
        __list_add_rcu(new, head->prev, head);
}
# 149 "include/linux/list.h"
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
# 192 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_del_rcu(struct list_head *entry)
{
        __list_del(entry->prev, entry->next);
        entry->prev = ((void *) 0x00200200);
}
# 205 "include/linux/list.h"
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
# 267 "include/linux/list.h"
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
# 305 "include/linux/list.h"
static inline __attribute__((always_inline)) void list_splice_init(struct list_head *list,
                                    struct list_head *head)
{
        if (!list_empty(list)) {
                __list_splice(list, head);
                do { (list)->next = (list); (list)->prev = (list); } while (0);
        }
}
# 509 "include/linux/list.h"
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
# 567 "include/linux/list.h"
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
# 608 "include/linux/list.h"
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
# 656 "include/linux/list.h"
static inline __attribute__((always_inline)) void hlist_add_before_rcu(struct hlist_node *n,
                                        struct hlist_node *next)
{
        n->pprev = next->pprev;
        n->next = next;
        __asm__ __volatile__ ("": : :"memory");
        next->pprev = &n->next;
        *(n->pprev) = n;
}
# 681 "include/linux/list.h"
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
# 24 "include/linux/wait.h" 2



# 1 "include/asm/current.h" 1





struct task_struct;

static inline __attribute__((always_inline)) struct task_struct * get_current(void)
{
        return current_thread_info()->task;
}
# 28 "include/linux/wait.h" 2

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
# 80 "include/linux/wait.h"
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
# 115 "include/linux/wait.h"
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
# 346 "include/linux/wait.h"
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
# 424 "include/linux/wait.h"
static inline __attribute__((always_inline)) int wait_on_bit(void *word, int bit,
                                int (*action)(void *), unsigned mode)
{
        if (!(__builtin_constant_p(bit) ? constant_test_bit((bit),(word)) : variable_test_bit((bit),(word))))
                return 0;
        return out_of_line_wait_on_bit(word, bit, action, mode);
}
# 448 "include/linux/wait.h"
static inline __attribute__((always_inline)) int wait_on_bit_lock(void *word, int bit,
                                int (*action)(void *), unsigned mode)
{
        if (!test_and_set_bit(bit, word))
                return 0;
        return out_of_line_wait_on_bit_lock(word, bit, action, mode);
}
# 42 "include/asm/semaphore.h" 2
# 1 "include/linux/rwsem.h" 1
# 22 "include/linux/rwsem.h"
struct rw_semaphore;


# 1 "include/linux/rwsem-spinlock.h" 1
# 22 "include/linux/rwsem-spinlock.h"
struct rwsem_waiter;
# 31 "include/linux/rwsem-spinlock.h"
struct rw_semaphore {
        __s32 activity;
        spinlock_t wait_lock;
        struct list_head wait_list;



};
# 55 "include/linux/rwsem-spinlock.h"
extern void init_rwsem(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __down_read(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern int __down_read_trylock(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __down_write(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern int __down_write_trylock(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __up_read(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __up_write(struct rw_semaphore *sem) __attribute__((regparm(3)));
extern void __downgrade_write(struct rw_semaphore *sem) __attribute__((regparm(3)));
# 26 "include/linux/rwsem.h" 2
# 41 "include/linux/rwsem.h"
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
# 43 "include/asm/semaphore.h" 2

struct semaphore {
        atomic_t count;
        int sleepers;
        wait_queue_head_t wait;
};
# 67 "include/asm/semaphore.h"
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
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "yellowfin" "\n\t" ".text.lock." "yellowfin" ":\n\t" ".endif\n"
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
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "yellowfin" "\n\t" ".text.lock." "yellowfin" ":\n\t" ".endif\n"
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
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "yellowfin" "\n\t" ".text.lock." "yellowfin" ":\n\t" ".endif\n"
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
                ".subsection 1\n\t" "" ".ifndef " ".text.lock." "yellowfin" "\n\t" ".text.lock." "yellowfin" ":\n\t" ".endif\n"
                "2:\tlea %0,%%eax\n\t"
                "call __up_wakeup\n\t"
                "jmp 1b\n"
                ".previous\n\t"
                ".subsection 0\n"
                :"=m" (sem->count)
                :
                :"memory","ax");
}
# 21 "include/linux/sched.h" 2

# 1 "include/asm/ptrace.h" 1
# 26 "include/asm/ptrace.h"
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
# 61 "include/asm/ptrace.h"
struct task_struct;
extern void send_sigtrap(struct task_struct *tsk, struct pt_regs *regs, int error_code);
# 71 "include/asm/ptrace.h"
static inline __attribute__((always_inline)) int user_mode(struct pt_regs *regs)
{
        return (regs->xcs & 3) != 0;
}
static inline __attribute__((always_inline)) int user_mode_vm(struct pt_regs *regs)
{
        return ((regs->xcs & 3) | (regs->eflags & 0x00020000)) != 0;
}
# 23 "include/linux/sched.h" 2
# 1 "include/asm/mmu.h" 1
# 11 "include/asm/mmu.h"
typedef struct {
        int size;
        struct semaphore sem;
        void *ldt;
} mm_context_t;
# 24 "include/linux/sched.h" 2
# 1 "include/asm/cputime.h" 1



# 1 "include/asm-generic/cputime.h" 1






typedef unsigned long cputime_t;
# 23 "include/asm-generic/cputime.h"
typedef u64 cputime64_t;
# 5 "include/asm/cputime.h" 2
# 25 "include/linux/sched.h" 2

# 1 "include/linux/smp.h" 1
# 11 "include/linux/smp.h"
extern void cpu_idle(void);







# 1 "include/asm/smp.h" 1
# 16 "include/asm/smp.h"
# 1 "include/asm/fixmap.h" 1
# 27 "include/asm/fixmap.h"
# 1 "include/asm/acpi.h" 1
# 31 "include/asm/acpi.h"
# 1 "include/acpi/pdc_intel.h" 1
# 32 "include/asm/acpi.h" 2
# 60 "include/asm/acpi.h"
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
# 161 "include/asm/acpi.h"
static inline __attribute__((always_inline)) void acpi_noirq_set(void) { }
static inline __attribute__((always_inline)) void acpi_disable_pci(void) { }
# 180 "include/asm/acpi.h"
extern u8 x86_acpiid_to_apicid[];
# 28 "include/asm/fixmap.h" 2
# 1 "include/asm/apicdef.h" 1
# 125 "include/asm/apicdef.h"
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
# 29 "include/asm/fixmap.h" 2



# 1 "include/asm/kmap_types.h" 1
# 12 "include/asm/kmap_types.h"
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
# 33 "include/asm/fixmap.h" 2
# 53 "include/asm/fixmap.h"
enum fixed_addresses {
        FIX_HOLE,
        FIX_VSYSCALL,

        FIX_APIC_BASE,


        FIX_IO_APIC_BASE_0,
        FIX_IO_APIC_BASE_END = FIX_IO_APIC_BASE_0 + 64 -1,
# 70 "include/asm/fixmap.h"
        FIX_F00F_IDT,





        FIX_KMAP_BEGIN,
        FIX_KMAP_END = FIX_KMAP_BEGIN+(KM_TYPE_NR*8)-1,
# 86 "include/asm/fixmap.h"
        __end_of_permanent_fixed_addresses,


        FIX_BTMAP_END = __end_of_permanent_fixed_addresses,
        FIX_BTMAP_BEGIN = FIX_BTMAP_END + 16 - 1,
        FIX_WP_TEST,
        __end_of_fixed_addresses
};

extern void __set_fixmap (enum fixed_addresses idx,
                                        unsigned long phys, pgprot_t flags);
# 127 "include/asm/fixmap.h"
extern void __this_fixmap_does_not_exist(void);






static inline __attribute__((always_inline)) unsigned long fix_to_virt(const unsigned int idx)
{
# 145 "include/asm/fixmap.h"
        if (idx >= __end_of_fixed_addresses)
                __this_fixmap_does_not_exist();

        return (((unsigned long)0xfffff000) - ((idx) << 12));
}

static inline __attribute__((always_inline)) unsigned long virt_to_fix(const unsigned long vaddr)
{
        do { if (__builtin_expect(!!((vaddr >= ((unsigned long)0xfffff000) || vaddr < (((unsigned long)0xfffff000) - (__end_of_permanent_fixed_addresses << 12)))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (153), "i" ("include/asm/fixmap.h")); } while(0);
        return ((((unsigned long)0xfffff000) - ((vaddr)&(~((1UL << 12)-1)))) >> 12);
}
# 17 "include/asm/smp.h" 2

# 1 "include/asm/mpspec.h" 1




# 1 "include/asm/mpspec_def.h" 1
# 19 "include/asm/mpspec_def.h"
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
# 58 "include/asm/mpspec_def.h"
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
# 102 "include/asm/mpspec_def.h"
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
# 180 "include/asm/mpspec_def.h"
enum mp_bustype {
        MP_BUS_ISA = 1,
        MP_BUS_EISA,
        MP_BUS_PCI,
        MP_BUS_MCA,
        MP_BUS_NEC98
};
# 6 "include/asm/mpspec.h" 2
# 1 "include/asm/mach-summit/mach_mpspec.h" 1
# 7 "include/asm/mpspec.h" 2

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
# 41 "include/asm/mpspec.h"
struct physid_mask
{
        unsigned long mask[(((256)+32 -1)/32)];
};

typedef struct physid_mask physid_mask_t;
# 81 "include/asm/mpspec.h"
extern physid_mask_t phys_cpu_present_map;
# 19 "include/asm/smp.h" 2

# 1 "include/asm/io_apic.h" 1
# 36 "include/asm/io_apic.h"
static inline __attribute__((always_inline)) int use_pci_vector(void) {return 0;}
static inline __attribute__((always_inline)) void disable_edge_ioapic_irq(unsigned int irq) { }
static inline __attribute__((always_inline)) void mask_and_ack_level_ioapic_irq(unsigned int irq) { }
static inline __attribute__((always_inline)) void end_edge_ioapic_irq (unsigned int irq) { }
# 63 "include/asm/io_apic.h"
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
# 205 "include/asm/io_apic.h"
extern int (*ioapic_renumber_irq)(int ioapic, int irq);





extern int assign_irq_vector(int irq);
# 21 "include/asm/smp.h" 2

# 1 "include/asm/apic.h" 1




# 1 "include/linux/pm.h" 1
# 35 "include/linux/pm.h"
typedef int pm_request_t;
# 44 "include/linux/pm.h"
typedef int pm_dev_t;
# 57 "include/linux/pm.h"
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
# 76 "include/linux/pm.h"
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
# 152 "include/linux/pm.h"
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
# 220 "include/linux/pm.h"
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
# 6 "include/asm/apic.h" 2
# 20 "include/asm/apic.h"
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
# 52 "include/asm/apic.h"
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
# 85 "include/asm/apic.h"
static inline __attribute__((always_inline)) void ack_APIC_irq(void)
{
# 95 "include/asm/apic.h"
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
# 23 "include/asm/smp.h" 2
# 34 "include/asm/smp.h"
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
# 60 "include/asm/smp.h"
extern cpumask_t cpu_callout_map;
extern cpumask_t cpu_callin_map;
extern cpumask_t cpu_possible_map;


static inline __attribute__((always_inline)) int num_booting_cpus(void)
{
        return __cpus_weight(&(cpu_callout_map), 8);
}






# 1 "include/asm/mach-summit/mach_apicdef.h" 1





static inline __attribute__((always_inline)) unsigned get_apic_id(unsigned long x)
{
        return (((x)>>24)&0xFF);
}
# 76 "include/asm/smp.h" 2
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
# 20 "include/linux/smp.h" 2
# 30 "include/linux/smp.h"
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
# 88 "include/linux/smp.h"
void smp_prepare_boot_cpu(void);
# 27 "include/linux/sched.h" 2
# 1 "include/linux/sem.h" 1



# 1 "include/linux/ipc.h" 1
# 9 "include/linux/ipc.h"
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


# 1 "include/asm/ipcbuf.h" 1
# 14 "include/asm/ipcbuf.h"
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
# 22 "include/linux/ipc.h" 2
# 57 "include/linux/ipc.h"
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
# 5 "include/linux/sem.h" 2
# 24 "include/linux/sem.h"
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


# 1 "include/asm/sembuf.h" 1
# 14 "include/asm/sembuf.h"
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
# 37 "include/linux/sem.h" 2


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
# 83 "include/linux/sem.h"
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
# 28 "include/linux/sched.h" 2
# 1 "include/linux/signal.h" 1





# 1 "include/asm/signal.h" 1
# 10 "include/asm/signal.h"
struct siginfo;
# 20 "include/asm/signal.h"
typedef unsigned long old_sigset_t;

typedef struct {
        unsigned long sig[(64 / 32)];
} sigset_t;
# 113 "include/asm/signal.h"
# 1 "include/asm-generic/signal.h" 1
# 12 "include/asm-generic/signal.h"
typedef void __signalfn_t(int);
typedef __signalfn_t *__sighandler_t;

typedef void __restorefn_t(void);
typedef __restorefn_t *__sigrestore_t;
# 114 "include/asm/signal.h" 2


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
# 151 "include/asm/signal.h"
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
# 7 "include/linux/signal.h" 2
# 1 "include/asm/siginfo.h" 1



# 1 "include/asm-generic/siginfo.h" 1






typedef union sigval {
        int sival_int;
        void *sival_ptr;
} sigval_t;
# 40 "include/asm-generic/siginfo.h"
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
# 251 "include/asm-generic/siginfo.h"
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
# 5 "include/asm/siginfo.h" 2
# 8 "include/linux/signal.h" 2
# 26 "include/linux/signal.h"
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
# 115 "include/linux/signal.h"
static inline __attribute__((always_inline)) void sigorsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) | (b3)); r->sig[2] = ((a2) | (b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) | (b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) | (b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }


static inline __attribute__((always_inline)) void sigandsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) & (b3)); r->sig[2] = ((a2) & (b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) & (b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) & (b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }


static inline __attribute__((always_inline)) void signandsets(sigset_t *r, const sigset_t *a, const sigset_t *b) { extern void _NSIG_WORDS_is_unsupported_size(void); unsigned long a0, a1, a2, a3, b0, b1, b2, b3; switch ((64 / 32)) { case 4: a3 = a->sig[3]; a2 = a->sig[2]; b3 = b->sig[3]; b2 = b->sig[2]; r->sig[3] = ((a3) & ~(b3)); r->sig[2] = ((a2) & ~(b2)); case 2: a1 = a->sig[1]; b1 = b->sig[1]; r->sig[1] = ((a1) & ~(b1)); case 1: a0 = a->sig[0]; b0 = b->sig[0]; r->sig[0] = ((a0) & ~(b0)); break; default: _NSIG_WORDS_is_unsupported_size(); } }
# 145 "include/linux/signal.h"
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
# 29 "include/linux/sched.h" 2
# 1 "include/linux/securebits.h" 1





extern unsigned securebits;
# 30 "include/linux/sched.h" 2
# 1 "include/linux/fs_struct.h" 1



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
# 31 "include/linux/sched.h" 2

# 1 "include/linux/completion.h" 1
# 13 "include/linux/completion.h"
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
# 33 "include/linux/sched.h" 2
# 1 "include/linux/pid.h" 1



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
# 29 "include/linux/pid.h"
extern int attach_pid(struct task_struct *task, enum pid_type type, int nr) __attribute__((regparm(3)));

extern void detach_pid(struct task_struct *task, enum pid_type) __attribute__((regparm(3)));





extern struct pid *find_pid(enum pid_type, int) __attribute__((regparm(3)));

extern int alloc_pidmap(void);
extern void free_pidmap(int) __attribute__((regparm(3)));
extern void switch_exec_pids(struct task_struct *leader, struct task_struct *thread);
# 34 "include/linux/sched.h" 2
# 1 "include/linux/percpu.h" 1



# 1 "include/linux/slab.h" 1
# 12 "include/linux/slab.h"
typedef struct kmem_cache_s kmem_cache_t;


# 1 "include/linux/gfp.h" 1



# 1 "include/linux/mmzone.h" 1
# 14 "include/linux/mmzone.h"
# 1 "include/linux/init.h" 1
# 64 "include/linux/init.h"
typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);

extern initcall_t __con_initcall_start[], __con_initcall_end[];
extern initcall_t __security_initcall_start[], __security_initcall_end[];


extern char saved_command_line[];
# 110 "include/linux/init.h"
struct obs_kernel_param {
        const char *str;
        int (*setup_func)(char *);
        int early;
};
# 145 "include/linux/init.h"
void __attribute__ ((__section__ (".init.text"))) parse_early_param(void);
# 15 "include/linux/mmzone.h" 2
# 24 "include/linux/mmzone.h"
struct free_area {
        struct list_head free_list;
        unsigned long nr_free;
};

struct pglist_data;
# 38 "include/linux/mmzone.h"
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
# 64 "include/linux/mmzone.h"
} __attribute__((__aligned__((1 << (4)))));
# 117 "include/linux/mmzone.h"
struct zone {

        unsigned long free_pages;
        unsigned long pages_min, pages_low, pages_high;
# 129 "include/linux/mmzone.h"
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
# 180 "include/linux/mmzone.h"
        int temp_priority;
        int prev_priority;


        struct zone_padding _pad2_;
# 211 "include/linux/mmzone.h"
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
# 251 "include/linux/mmzone.h"
struct zonelist {
        struct zone *zones[(1 << 0) * 3 + 1];
};
# 267 "include/linux/mmzone.h"
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
# 296 "include/linux/mmzone.h"
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
# 340 "include/linux/mmzone.h"
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
# 373 "include/linux/mmzone.h"
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

# 1 "include/linux/topology.h" 1
# 32 "include/linux/topology.h"
# 1 "include/linux/mmzone.h" 1
# 33 "include/linux/topology.h" 2

# 1 "include/asm/topology.h" 1
# 103 "include/asm/topology.h"
# 1 "include/asm-generic/topology.h" 1
# 104 "include/asm/topology.h" 2
# 35 "include/linux/topology.h" 2
# 408 "include/linux/mmzone.h" 2





extern struct pglist_data contig_page_data;
# 604 "include/linux/mmzone.h"
void memory_present(int nid, unsigned long start, unsigned long end);
unsigned long __attribute__ ((__section__ (".init.text"))) node_memmap_size_bytes(int, unsigned long, unsigned long);
# 5 "include/linux/gfp.h" 2




struct vm_area_struct;
# 84 "include/linux/gfp.h"
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
# 120 "include/linux/gfp.h"
extern unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order) __attribute__((regparm(3)));
extern unsigned long get_zeroed_page(gfp_t gfp_mask) __attribute__((regparm(3)));







extern void __free_pages(struct page *page, unsigned int order) __attribute__((regparm(3)));
extern void free_pages(unsigned long addr, unsigned int order) __attribute__((regparm(3)));
extern void free_hot_page(struct page *page) __attribute__((regparm(3)));
extern void free_cold_page(struct page *page) __attribute__((regparm(3)));




void page_alloc_init(void);



static inline __attribute__((always_inline)) void drain_remote_pages(void) { };
# 16 "include/linux/slab.h" 2
# 57 "include/linux/slab.h"
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





# 1 "include/linux/kmalloc_sizes.h" 1

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
# 89 "include/linux/slab.h" 2

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
# 5 "include/linux/percpu.h" 2
# 20 "include/linux/percpu.h"
struct percpu_data {
        void *ptrs[8];
        void *blkp;
};
# 36 "include/linux/percpu.h"
extern void *__alloc_percpu(size_t size, size_t align);
extern void free_percpu(const void *);
# 35 "include/linux/sched.h" 2

# 1 "include/linux/seccomp.h" 1
# 11 "include/linux/seccomp.h"
# 1 "include/asm/seccomp.h" 1
# 9 "include/asm/seccomp.h"
# 1 "include/linux/unistd.h" 1



extern int errno;




# 1 "include/asm/unistd.h" 1
# 10 "include/linux/unistd.h" 2
# 10 "include/asm/seccomp.h" 2
# 12 "include/linux/seccomp.h" 2

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
# 37 "include/linux/sched.h" 2

# 1 "include/linux/auxvec.h" 1



# 1 "include/asm/auxvec.h" 1
# 5 "include/linux/auxvec.h" 2
# 39 "include/linux/sched.h" 2

struct exec_domain;
# 80 "include/linux/sched.h"
extern unsigned long avenrun[];
# 94 "include/linux/sched.h"
extern unsigned long total_forks;
extern int nr_threads;
extern int last_pid;
extern __typeof__(unsigned long) per_cpu__process_counts;
extern int nr_processes(void);
extern unsigned long nr_running(void);
extern unsigned long nr_uninterruptible(void);
extern unsigned long nr_iowait(void);


# 1 "include/linux/param.h" 1



# 1 "include/asm/param.h" 1
# 5 "include/linux/param.h" 2
# 105 "include/linux/sched.h" 2
# 1 "include/linux/resource.h" 1
# 21 "include/linux/resource.h"
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
# 68 "include/linux/resource.h"
# 1 "include/asm/resource.h" 1



# 1 "include/asm-generic/resource.h" 1
# 5 "include/asm/resource.h" 2
# 69 "include/linux/resource.h" 2
# 106 "include/linux/sched.h" 2
# 1 "include/linux/timer.h" 1
# 9 "include/linux/timer.h"
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
# 39 "include/linux/timer.h"
void __attribute__((regparm(3))) init_timer(struct timer_list * timer);
# 51 "include/linux/timer.h"
static inline __attribute__((always_inline)) int timer_pending(const struct timer_list * timer)
{
        return timer->entry.next != ((void *)0);
}

extern void add_timer_on(struct timer_list *timer, int cpu);
extern int del_timer(struct timer_list * timer);
extern int __mod_timer(struct timer_list *timer, unsigned long expires);
extern int mod_timer(struct timer_list *timer, unsigned long expires);

extern unsigned long next_timer_interrupt(void);
# 77 "include/linux/timer.h"
static inline __attribute__((always_inline)) void add_timer(struct timer_list * timer)
{
        __mod_timer(timer, timer->expires);
}


  extern int try_to_del_timer_sync(struct timer_list *timer);
  extern int del_timer_sync(struct timer_list *timer);







extern void init_timers(void);
extern void run_local_timers(void);
extern void it_real_fn(unsigned long);
# 107 "include/linux/sched.h" 2
# 162 "include/linux/sched.h"
struct sched_param {
        int sched_priority;
};
# 176 "include/linux/sched.h"
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
# 225 "include/linux/sched.h"
extern int in_sched_functions(unsigned long addr);


extern signed long schedule_timeout(signed long timeout) __attribute__((regparm(3)));
extern signed long schedule_timeout_interruptible(signed long timeout);
extern signed long schedule_timeout_uninterruptible(signed long timeout);
 __attribute__((regparm(0))) void schedule(void);

struct namespace;




extern int sysctl_max_map_count;

# 1 "include/linux/aio.h" 1




# 1 "include/linux/workqueue.h" 1
# 12 "include/linux/workqueue.h"
struct workqueue_struct;

struct work_struct {
        unsigned long pending;
        struct list_head entry;
        void (*func)(void *);
        void *data;
        void *wq_data;
        struct timer_list timer;
};
# 53 "include/linux/workqueue.h"
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
# 6 "include/linux/aio.h" 2
# 1 "include/linux/aio_abi.h" 1
# 32 "include/linux/aio_abi.h"
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
# 68 "include/linux/aio_abi.h"
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
# 7 "include/linux/aio.h" 2






struct kioctx;
# 85 "include/linux/aio.h"
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
# 138 "include/linux/aio.h"
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
# 231 "include/linux/aio.h"
static inline __attribute__((always_inline)) struct kiocb *list_kiocb(struct list_head *h)
{
        return ({ const typeof( ((struct kiocb *)0)->ki_list ) *__mptr = (h); (struct kiocb *)( (char *)__mptr - ((size_t) &((struct kiocb *)0)->ki_list) );});
}


extern atomic_t aio_nr;
extern unsigned aio_max_nr;
# 241 "include/linux/sched.h" 2

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
# 331 "include/linux/sched.h"
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
# 404 "include/linux/sched.h"
        struct rlimit rlim[15];

        struct list_head cpu_timers[3];







};
# 453 "include/linux/sched.h"
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
# 500 "include/linux/sched.h"
enum idle_type
{
        SCHED_IDLE,
        NOT_IDLE,
        NEWLY_IDLE,
        MAX_IDLE_TYPES
};
# 523 "include/linux/sched.h"
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
# 589 "include/linux/sched.h"
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
# 625 "include/linux/sched.h"
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
# 815 "include/linux/sched.h"
        atomic_t fs_excl;
};

static inline __attribute__((always_inline)) pid_t process_group(struct task_struct *tsk)
{
        return tsk->signal->pgrp;
}
# 831 "include/linux/sched.h"
static inline __attribute__((always_inline)) int pid_alive(struct task_struct *p)
{
        return p->pids[PIDTYPE_PID].nr != 0;
}

extern void free_task(struct task_struct *tsk);
extern void __put_task_struct(struct task_struct *tsk);
# 894 "include/linux/sched.h"
extern int set_cpus_allowed(task_t *p, cpumask_t new_mask);
# 904 "include/linux/sched.h"
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
# 1044 "include/linux/sched.h"
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
# 1152 "include/linux/sched.h"
extern task_t * next_thread(const task_t *p) __attribute__((regparm(3)));



static inline __attribute__((always_inline)) int thread_group_empty(task_t *p)
{
        return list_empty(&p->pids[PIDTYPE_TGID].pid_list);
}




extern void unhash_process(struct task_struct *p);
# 1175 "include/linux/sched.h"
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
# 1240 "include/linux/sched.h"
extern int cond_resched(void);
extern int cond_resched_lock(spinlock_t * lock);
extern int cond_resched_softirq(void);
# 1258 "include/linux/sched.h"
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
# 1303 "include/linux/sched.h"
extern void arch_pick_mmap_layout(struct mm_struct *mm);
# 1313 "include/linux/sched.h"
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
# 11 "include/linux/module.h" 2


# 1 "include/linux/stat.h" 1





# 1 "include/asm/stat.h" 1



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
# 7 "include/linux/stat.h" 2
# 59 "include/linux/stat.h"
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
# 14 "include/linux/module.h" 2


# 1 "include/linux/kmod.h" 1
# 32 "include/linux/kmod.h"
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
# 17 "include/linux/module.h" 2
# 1 "include/linux/elf.h" 1





# 1 "include/asm/elf.h" 1
# 9 "include/asm/elf.h"
# 1 "include/asm/user.h" 1
# 44 "include/asm/user.h"
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
# 10 "include/asm/elf.h" 2




# 1 "include/linux/utsname.h" 1





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
# 15 "include/asm/elf.h" 2
# 29 "include/asm/elf.h"
typedef unsigned long elf_greg_t;


typedef elf_greg_t elf_gregset_t[(sizeof (struct user_regs_struct) / sizeof(elf_greg_t))];

typedef struct user_i387_struct elf_fpregset_t;
typedef struct user_fxsr_struct elf_fpxregset_t;
# 122 "include/asm/elf.h"
extern int dump_task_regs (struct task_struct *, elf_gregset_t *);
extern int dump_task_fpu (struct task_struct *, elf_fpregset_t *);
extern int dump_task_extended_fpu (struct task_struct *, struct user_fxsr_struct *);
# 133 "include/asm/elf.h"
extern void __kernel_vsyscall;
# 7 "include/linux/elf.h" 2
# 16 "include/linux/elf.h"
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
# 162 "include/linux/elf.h"
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
# 185 "include/linux/elf.h"
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
# 324 "include/linux/elf.h"
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
# 397 "include/linux/elf.h"
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
# 18 "include/linux/module.h" 2

# 1 "include/linux/kobject.h" 1
# 22 "include/linux/kobject.h"
# 1 "include/linux/sysfs.h" 1
# 15 "include/linux/sysfs.h"
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
# 51 "include/linux/sysfs.h"
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
# 88 "include/linux/sysfs.h"
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
# 23 "include/linux/kobject.h" 2


# 1 "include/linux/kref.h" 1
# 23 "include/linux/kref.h"
struct kref {
        atomic_t refcount;
};

void kref_init(struct kref *kref);
void kref_get(struct kref *kref);
int kref_put(struct kref *kref, void (*release) (struct kref *kref));
# 26 "include/linux/kobject.h" 2
# 1 "include/linux/kobject_uevent.h" 1
# 17 "include/linux/kobject_uevent.h"
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
# 27 "include/linux/kobject.h" 2






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
# 95 "include/linux/kobject.h"
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
# 151 "include/linux/kobject.h"
struct subsystem {
        struct kset kset;
        struct rw_semaphore rwsem;
};
# 174 "include/linux/kobject.h"
extern struct subsystem kernel_subsys;
# 221 "include/linux/kobject.h"
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
# 20 "include/linux/module.h" 2
# 1 "include/linux/moduleparam.h" 1
# 29 "include/linux/moduleparam.h"
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
# 95 "include/linux/moduleparam.h"
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
# 159 "include/linux/moduleparam.h"
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
# 21 "include/linux/module.h" 2
# 1 "include/asm/local.h" 1





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
# 22 "include/linux/module.h" 2

# 1 "include/asm/module.h" 1




struct mod_arch_specific
{
};
# 24 "include/linux/module.h" 2
# 35 "include/linux/module.h"
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
# 159 "include/linux/module.h"
const struct exception_table_entry *search_exception_tables(unsigned long add);

struct notifier_block;




void *__symbol_get(const char *symbol);
void *__symbol_get_gpl(const char *symbol);
# 203 "include/linux/module.h"
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
# 302 "include/linux/module.h"
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
# 391 "include/linux/module.h"
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
# 424 "include/linux/module.h"
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
# 547 "include/linux/module.h"
struct obsolete_modparm {
        char name[64];
        char type[64-sizeof(void *)];
        void *addr;
};

static inline __attribute__((always_inline)) void MODULE_PARM_(void) { }
# 568 "include/linux/module.h"
extern void __attribute__((deprecated)) inter_module_register(const char *,
                struct module *, const void *);
extern void __attribute__((deprecated)) inter_module_unregister(const char *);
extern const void * __attribute__((deprecated)) inter_module_get_request(const char *,
                const char *);
extern void __attribute__((deprecated)) inter_module_put(const char *);
# 112 "drivers/net/yellowfin.c" 2




# 1 "include/linux/ioport.h" 1
# 16 "include/linux/ioport.h"
struct resource {
        const char *name;
        unsigned long start, end;
        unsigned long flags;
        struct resource *parent, *sibling, *child;
};

struct resource_list {
        struct resource_list *next;
        struct resource *res;
        struct pci_dev *dev;
};
# 91 "include/linux/ioport.h"
extern struct resource ioport_resource;
extern struct resource iomem_resource;

extern int request_resource(struct resource *root, struct resource *new);
extern struct resource * ____request_resource(struct resource *root, struct resource *new);
extern int release_resource(struct resource *new);
extern int insert_resource(struct resource *parent, struct resource *new);
extern int allocate_resource(struct resource *root, struct resource *new,
                             unsigned long size,
                             unsigned long min, unsigned long max,
                             unsigned long align,
                             void (*alignf)(void *, struct resource *,
                                            unsigned long, unsigned long),
                             void *alignf_data);
int adjust_resource(struct resource *res, unsigned long start,
                    unsigned long size);






extern struct resource * __request_region(struct resource *, unsigned long start, unsigned long n, const char *name);






extern int __check_region(struct resource *, unsigned long, unsigned long);
extern void __release_region(struct resource *, unsigned long, unsigned long);

static inline __attribute__((always_inline)) int __attribute__((deprecated)) check_region(unsigned long s, unsigned long n)
{
        return __check_region(&ioport_resource, s, n);
}
# 117 "drivers/net/yellowfin.c" 2

# 1 "include/linux/interrupt.h" 1
# 11 "include/linux/interrupt.h"
# 1 "include/linux/hardirq.h" 1





# 1 "include/linux/smp_lock.h" 1
# 12 "include/linux/smp_lock.h"
extern int __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) __reacquire_kernel_lock(void);
extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) __release_kernel_lock(void);
# 35 "include/linux/smp_lock.h"
static inline __attribute__((always_inline)) int reacquire_kernel_lock(struct task_struct *task)
{
        if (__builtin_expect(!!(task->lock_depth >= 0), 0))
                __reacquire_kernel_lock();
        return 0;
}

extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) lock_kernel(void) ;
extern void __attribute__((regparm(3))) __attribute__((section(".spinlock.text"))) unlock_kernel(void) ;
# 7 "include/linux/hardirq.h" 2
# 1 "include/asm/hardirq.h" 1





# 1 "include/linux/irq.h" 1
# 21 "include/linux/irq.h"
# 1 "include/asm/irq.h" 1
# 16 "include/asm/irq.h"
# 1 "include/asm/mach-default/irq_vectors.h" 1
# 87 "include/asm/mach-default/irq_vectors.h"
# 1 "include/asm/mach-default/irq_vectors_limits.h" 1
# 88 "include/asm/mach-default/irq_vectors.h" 2
# 17 "include/asm/irq.h" 2


static __inline__ __attribute__((always_inline)) int irq_canonicalize(int irq)
{
        return ((irq == 2) ? 9 : irq);
}

extern void release_vm86_irqs(struct task_struct *);
# 40 "include/asm/irq.h"
extern int irqbalance_disable(char *str);
# 22 "include/linux/irq.h" 2
# 46 "include/linux/irq.h"
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
# 70 "include/linux/irq.h"
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

# 1 "include/asm/hw_irq.h" 1
# 16 "include/asm/hw_irq.h"
# 1 "include/linux/profile.h" 1
# 15 "include/linux/profile.h"
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
# 17 "include/asm/hw_irq.h" 2


# 1 "include/asm/sections.h" 1




# 1 "include/asm-generic/sections.h" 1





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
# 6 "include/asm/sections.h" 2
# 20 "include/asm/hw_irq.h" 2

struct hw_interrupt_type;
# 30 "include/asm/hw_irq.h"
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
# 94 "include/linux/irq.h" 2

extern int setup_irq(unsigned int irq, struct irqaction * new);


extern cpumask_t irq_affinity[224];


static inline __attribute__((always_inline)) void set_native_irq_info(int irq, cpumask_t mask)
{
        irq_affinity[irq] = mask;
}
# 114 "include/linux/irq.h"
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
# 156 "include/linux/irq.h"
        if (__builtin_expect(!!(!__cpus_empty(&(tmp), 8)), 0)) {
                desc->handler->disable(irq);
                desc->handler->set_affinity(irq,tmp);
                desc->handler->enable(irq);
        }
        __cpus_clear(&(pending_irq_cpumask[irq]), 8);
}
# 182 "include/linux/irq.h"
static inline __attribute__((always_inline)) void move_irq(int irq)
{
        move_native_irq(irq);
}

static inline __attribute__((always_inline)) void set_irq_info(int irq, cpumask_t mask)
{
        set_native_irq_info(irq, mask);
}
# 212 "include/linux/irq.h"
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
# 7 "include/asm/hardirq.h" 2

typedef struct {
        unsigned int __softirq_pending;
        unsigned long idle_timestamp;
        unsigned int __nmi_count;
        unsigned int apic_timer_irqs;
} __attribute__((__aligned__((1 << (4))))) irq_cpustat_t;

extern __typeof__(irq_cpustat_t) per_cpu__irq_stat;
extern irq_cpustat_t irq_stat[];




void ack_bad_irq(unsigned int irq);
# 1 "include/linux/irq_cpustat.h" 1
# 23 "include/asm/hardirq.h" 2
# 8 "include/linux/hardirq.h" 2
# 85 "include/linux/hardirq.h"
extern void synchronize_irq(unsigned int irq);
# 94 "include/linux/hardirq.h"
static inline __attribute__((always_inline)) void account_user_vtime(struct task_struct *tsk)
{
}

static inline __attribute__((always_inline)) void account_system_vtime(struct task_struct *tsk)
{
}
# 109 "include/linux/hardirq.h"
extern void irq_exit(void);
# 12 "include/linux/interrupt.h" 2
# 30 "include/linux/interrupt.h"
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
# 100 "include/linux/interrupt.h"
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
# 156 "include/linux/interrupt.h"
struct tasklet_struct
{
        struct tasklet_struct *next;
        unsigned long state;
        atomic_t count;
        void (*func)(unsigned long);
        unsigned long data;
};
# 172 "include/linux/interrupt.h"
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
# 289 "include/linux/interrupt.h"
extern unsigned long probe_irq_on(void);
extern int probe_irq_off(unsigned long);
extern unsigned int probe_irq_mask(unsigned long);
# 119 "drivers/net/yellowfin.c" 2
# 1 "include/linux/pci.h" 1
# 20 "include/linux/pci.h"
# 1 "include/linux/mod_devicetable.h" 1
# 12 "include/linux/mod_devicetable.h"
typedef unsigned long kernel_ulong_t;




struct pci_device_id {
        __u32 vendor, device;
        __u32 subvendor, subdevice;
        __u32 class, class_mask;
        kernel_ulong_t driver_data;
};







struct ieee1394_device_id {
        __u32 match_flags;
        __u32 vendor_id;
        __u32 model_id;
        __u32 specifier_id;
        __u32 version;
        kernel_ulong_t driver_data
                __attribute__((aligned(sizeof(kernel_ulong_t))));
};
# 98 "include/linux/mod_devicetable.h"
struct usb_device_id {

        __u16 match_flags;


        __u16 idVendor;
        __u16 idProduct;
        __u16 bcdDevice_lo;
        __u16 bcdDevice_hi;


        __u8 bDeviceClass;
        __u8 bDeviceSubClass;
        __u8 bDeviceProtocol;


        __u8 bInterfaceClass;
        __u8 bInterfaceSubClass;
        __u8 bInterfaceProtocol;


        kernel_ulong_t driver_info;
};
# 135 "include/linux/mod_devicetable.h"
struct ccw_device_id {
        __u16 match_flags;

        __u16 cu_type;
        __u16 dev_type;
        __u8 cu_model;
        __u8 dev_model;

        kernel_ulong_t driver_info;
};
# 155 "include/linux/mod_devicetable.h"
struct pnp_device_id {
        __u8 id[8];
        kernel_ulong_t driver_data;
};

struct pnp_card_device_id {
        __u8 id[8];
        kernel_ulong_t driver_data;
        struct {
                __u8 id[8];
        } devs[8];
};




struct serio_device_id {
        __u8 type;
        __u8 extra;
        __u8 id;
        __u8 proto;
};




struct of_device_id
{
        char name[32];
        char type[32];
        char compatible[128];

        void *data;



};


struct vio_device_id {
        char type[32];
        char compat[32];
};



struct pcmcia_device_id {
        __u16 match_flags;

        __u16 manf_id;
        __u16 card_id;

        __u8 func_id;


        __u8 function;


        __u8 device_no;

        __u32 prod_id_hash[4]
                __attribute__((aligned(sizeof(__u32))));



        const char * prod_id[4];






        kernel_ulong_t driver_info;

        char * cisfile;



};
# 21 "include/linux/pci.h" 2


# 1 "include/linux/pci_regs.h" 1
# 24 "include/linux/pci.h" 2


# 1 "include/linux/pci_ids.h" 1
# 27 "include/linux/pci.h" 2
# 54 "include/linux/pci.h"
# 1 "include/linux/device.h" 1
# 17 "include/linux/device.h"
# 1 "include/linux/klist.h" 1
# 20 "include/linux/klist.h"
struct klist_node;
struct klist {
        spinlock_t k_lock;
        struct list_head k_list;
        void (*get)(struct klist_node *);
        void (*put)(struct klist_node *);
};


extern void klist_init(struct klist * k, void (*get)(struct klist_node *),
                       void (*put)(struct klist_node *));

struct klist_node {
        struct klist * n_klist;
        struct list_head n_node;
        struct kref n_ref;
        struct completion n_removed;
};

extern void klist_add_tail(struct klist_node * n, struct klist * k);
extern void klist_add_head(struct klist_node * n, struct klist * k);

extern void klist_del(struct klist_node * n);
extern void klist_remove(struct klist_node * n);

extern int klist_node_attached(struct klist_node * n);


struct klist_iter {
        struct klist * i_klist;
        struct list_head * i_head;
        struct klist_node * i_cur;
};


extern void klist_iter_init(struct klist * k, struct klist_iter * i);
extern void klist_iter_init_node(struct klist * k, struct klist_iter * i,
                                 struct klist_node * n);
extern void klist_iter_exit(struct klist_iter * i);
extern struct klist_node * klist_next(struct klist_iter * i);
# 18 "include/linux/device.h" 2
# 31 "include/linux/device.h"
enum {
        SUSPEND_NOTIFY,
        SUSPEND_SAVE_STATE,
        SUSPEND_DISABLE,
        SUSPEND_POWER_DOWN,
};

enum {
        RESUME_POWER_ON,
        RESUME_RESTORE_STATE,
        RESUME_ENABLE,
};

struct device;
struct device_driver;
struct class;
struct class_device;

struct bus_type {
        const char * name;

        struct subsystem subsys;
        struct kset drivers;
        struct kset devices;
        struct klist klist_devices;
        struct klist klist_drivers;

        struct bus_attribute * bus_attrs;
        struct device_attribute * dev_attrs;
        struct driver_attribute * drv_attrs;

        int (*match)(struct device * dev, struct device_driver * drv);
        int (*hotplug) (struct device *dev, char **envp,
                                    int num_envp, char *buffer, int buffer_size);
        int (*suspend)(struct device * dev, pm_message_t state);
        int (*resume)(struct device * dev);
};

extern int bus_register(struct bus_type * bus);
extern void bus_unregister(struct bus_type * bus);

extern void bus_rescan_devices(struct bus_type * bus);

extern struct bus_type * get_bus(struct bus_type * bus);
extern void put_bus(struct bus_type * bus);

extern struct bus_type * find_bus(char * name);



int bus_for_each_dev(struct bus_type * bus, struct device * start, void * data,
                     int (*fn)(struct device *, void *));
struct device * bus_find_device(struct bus_type *bus, struct device *start,
                                void *data, int (*match)(struct device *, void *));

int bus_for_each_drv(struct bus_type * bus, struct device_driver * start,
                     void * data, int (*fn)(struct device_driver *, void *));




struct bus_attribute {
        struct attribute attr;
        ssize_t (*show)(struct bus_type *, char * buf);
        ssize_t (*store)(struct bus_type *, const char * buf, size_t count);
};




extern int bus_create_file(struct bus_type *, struct bus_attribute *);
extern void bus_remove_file(struct bus_type *, struct bus_attribute *);

struct device_driver {
        const char * name;
        struct bus_type * bus;

        struct completion unloaded;
        struct kobject kobj;
        struct klist klist_devices;
        struct klist_node knode_bus;

        struct module * owner;

        int (*probe) (struct device * dev);
        int (*remove) (struct device * dev);
        void (*shutdown) (struct device * dev);
        int (*suspend) (struct device * dev, pm_message_t state, u32 level);
        int (*resume) (struct device * dev, u32 level);
};


extern int driver_register(struct device_driver * drv);
extern void driver_unregister(struct device_driver * drv);

extern struct device_driver * get_driver(struct device_driver * drv);
extern void put_driver(struct device_driver * drv);
extern struct device_driver *driver_find(const char *name, struct bus_type *bus);




struct driver_attribute {
        struct attribute attr;
        ssize_t (*show)(struct device_driver *, char * buf);
        ssize_t (*store)(struct device_driver *, const char * buf, size_t count);
};




extern int driver_create_file(struct device_driver *, struct driver_attribute *);
extern void driver_remove_file(struct device_driver *, struct driver_attribute *);

extern int driver_for_each_device(struct device_driver * drv, struct device * start,
                                  void * data, int (*fn)(struct device *, void *));
struct device * driver_find_device(struct device_driver *drv,
                                   struct device *start, void *data,
                                   int (*match)(struct device *, void *));





struct class {
        const char * name;
        struct module * owner;

        struct subsystem subsys;
        struct list_head children;
        struct list_head interfaces;
        struct semaphore sem;

        struct class_attribute * class_attrs;
        struct class_device_attribute * class_dev_attrs;

        int (*hotplug)(struct class_device *dev, char **envp,
                           int num_envp, char *buffer, int buffer_size);

        void (*release)(struct class_device *dev);
        void (*class_release)(struct class *class);
};

extern int class_register(struct class *);
extern void class_unregister(struct class *);

extern struct class * class_get(struct class *);
extern void class_put(struct class *);


struct class_attribute {
        struct attribute attr;
        ssize_t (*show)(struct class *, char * buf);
        ssize_t (*store)(struct class *, const char * buf, size_t count);
};




extern int class_create_file(struct class *, const struct class_attribute *);
extern void class_remove_file(struct class *, const struct class_attribute *);


struct class_device {
        struct list_head node;

        struct kobject kobj;
        struct class * class;
        dev_t devt;
        struct class_device_attribute *devt_attr;
        struct device * dev;
        void * class_data;

        char class_id[20];
};

static inline __attribute__((always_inline)) void *
class_get_devdata (struct class_device *dev)
{
        return dev->class_data;
}

static inline __attribute__((always_inline)) void
class_set_devdata (struct class_device *dev, void *data)
{
        dev->class_data = data;
}


extern int class_device_register(struct class_device *);
extern void class_device_unregister(struct class_device *);
extern void class_device_initialize(struct class_device *);
extern int class_device_add(struct class_device *);
extern void class_device_del(struct class_device *);

extern int class_device_rename(struct class_device *, char *);

extern struct class_device * class_device_get(struct class_device *);
extern void class_device_put(struct class_device *);

struct class_device_attribute {
        struct attribute attr;
        ssize_t (*show)(struct class_device *, char * buf);
        ssize_t (*store)(struct class_device *, const char * buf, size_t count);
};





extern int class_device_create_file(struct class_device *,
                                    const struct class_device_attribute *);
extern void class_device_remove_file(struct class_device *,
                                     const struct class_device_attribute *);
extern int class_device_create_bin_file(struct class_device *,
                                        struct bin_attribute *);
extern void class_device_remove_bin_file(struct class_device *,
                                         struct bin_attribute *);

struct class_interface {
        struct list_head node;
        struct class *class;

        int (*add) (struct class_device *);
        void (*remove) (struct class_device *);
};

extern int class_interface_register(struct class_interface *);
extern void class_interface_unregister(struct class_interface *);

extern struct class *class_create(struct module *owner, char *name);
extern void class_destroy(struct class *cls);
extern struct class_device *class_device_create(struct class *cls, dev_t devt,
                                                struct device *device, char *fmt, ...)
                                        __attribute__((format(printf,4,5)));
extern void class_device_destroy(struct class *cls, dev_t devt);


struct device {
        struct klist klist_children;
        struct klist_node knode_parent;
        struct klist_node knode_driver;
        struct klist_node knode_bus;
        struct device * parent;

        struct kobject kobj;
        char bus_id[20];

        struct semaphore sem;



        struct bus_type * bus;
        struct device_driver *driver;

        void *driver_data;
        void *platform_data;

        void *firmware_data;

        struct dev_pm_info power;

        u64 *dma_mask;
        u64 coherent_dma_mask;





        struct list_head dma_pools;

        struct dma_coherent_mem *dma_mem;


        void (*release)(struct device * dev);
};

static inline __attribute__((always_inline)) void *
dev_get_drvdata (struct device *dev)
{
        return dev->driver_data;
}

static inline __attribute__((always_inline)) void
dev_set_drvdata (struct device *dev, void *data)
{
        dev->driver_data = data;
}

static inline __attribute__((always_inline)) int device_is_registered(struct device *dev)
{
        return klist_node_attached(&dev->knode_bus);
}




extern int device_register(struct device * dev);
extern void device_unregister(struct device * dev);
extern void device_initialize(struct device * dev);
extern int device_add(struct device * dev);
extern void device_del(struct device * dev);
extern int device_for_each_child(struct device *, void *,
                     int (*fn)(struct device *, void *));





extern void device_bind_driver(struct device * dev);
extern void device_release_driver(struct device * dev);
extern int device_attach(struct device * dev);
extern void driver_attach(struct device_driver * drv);




struct device_attribute {
        struct attribute attr;
        ssize_t (*show)(struct device *dev, struct device_attribute *attr,
                        char *buf);
        ssize_t (*store)(struct device *dev, struct device_attribute *attr,
                         const char *buf, size_t count);
};





extern int device_create_file(struct device *device, struct device_attribute * entry);
extern void device_remove_file(struct device * dev, struct device_attribute * attr);







extern int (*platform_notify)(struct device * dev);

extern int (*platform_notify_remove)(struct device * dev);






extern struct device * get_device(struct device * dev);
extern void put_device(struct device * dev);




struct platform_device {
        const char * name;
        u32 id;
        struct device dev;
        u32 num_resources;
        struct resource * resource;
};



extern int platform_device_register(struct platform_device *);
extern void platform_device_unregister(struct platform_device *);

extern struct bus_type platform_bus_type;
extern struct device platform_bus;

extern struct resource *platform_get_resource(struct platform_device *, unsigned int, unsigned int);
extern int platform_get_irq(struct platform_device *, unsigned int);
extern struct resource *platform_get_resource_byname(struct platform_device *, unsigned int, char *);
extern int platform_get_irq_byname(struct platform_device *, char *);
extern int platform_add_devices(struct platform_device **, int);

extern struct platform_device *platform_device_register_simple(char *, unsigned int, struct resource *, unsigned int);


extern void device_shutdown(void);



extern int firmware_register(struct subsystem *);
extern void firmware_unregister(struct subsystem *);
# 55 "include/linux/pci.h" 2


enum pci_mmap_state {
        pci_mmap_io,
        pci_mmap_mem
};
# 71 "include/linux/pci.h"
typedef int pci_power_t;
# 84 "include/linux/pci.h"
struct pci_dev {
        struct list_head global_list;
        struct list_head bus_list;
        struct pci_bus *bus;
        struct pci_bus *subordinate;

        void *sysdata;
        struct proc_dir_entry *procent;

        unsigned int devfn;
        unsigned short vendor;
        unsigned short device;
        unsigned short subsystem_vendor;
        unsigned short subsystem_device;
        unsigned int class;
        u8 hdr_type;
        u8 rom_base_reg;

        struct pci_driver *driver;
        u64 dma_mask;





        pci_power_t current_state;



        struct device dev;


        unsigned short vendor_compatible[4];
        unsigned short device_compatible[4];

        int cfg_size;





        unsigned int irq;
        struct resource resource[12];


        unsigned int transparent:1;
        unsigned int multifunction:1;

        unsigned int is_enabled:1;
        unsigned int is_busmaster:1;
        unsigned int no_msi:1;

        u32 saved_config_space[16];
        struct bin_attribute *rom_attr;
        int rom_attr_enabled;
        struct bin_attribute *res_attr[12];
};
# 165 "include/linux/pci.h"
struct pci_bus {
        struct list_head node;
        struct pci_bus *parent;
        struct list_head children;
        struct list_head devices;
        struct pci_dev *self;
        struct resource *resource[8];


        struct pci_ops *ops;
        void *sysdata;
        struct proc_dir_entry *procdir;

        unsigned char number;
        unsigned char primary;
        unsigned char secondary;
        unsigned char subordinate;

        char name[48];

        unsigned short bridge_ctl;
        unsigned short pad2;
        struct device *bridge;
        struct class_device class_dev;
        struct bin_attribute *legacy_io;
        struct bin_attribute *legacy_mem;
};
# 209 "include/linux/pci.h"
struct pci_ops {
        int (*read)(struct pci_bus *bus, unsigned int devfn, int where, int size, u32 *val);
        int (*write)(struct pci_bus *bus, unsigned int devfn, int where, int size, u32 val);
};

struct pci_raw_ops {
        int (*read)(unsigned int domain, unsigned int bus, unsigned int devfn,
                    int reg, int len, u32 *val);
        int (*write)(unsigned int domain, unsigned int bus, unsigned int devfn,
                     int reg, int len, u32 val);
};

extern struct pci_raw_ops *raw_pci_ops;

struct pci_bus_region {
        unsigned long start;
        unsigned long end;
};

struct pci_dynids {
        spinlock_t lock;
        struct list_head list;
        unsigned int use_driver_data:1;
};

struct module;
struct pci_driver {
        struct list_head node;
        char *name;
        struct module *owner;
        const struct pci_device_id *id_table;
        int (*probe) (struct pci_dev *dev, const struct pci_device_id *id);
        void (*remove) (struct pci_dev *dev);
        int (*suspend) (struct pci_dev *dev, pm_message_t state);
        int (*resume) (struct pci_dev *dev);
        int (*enable_wake) (struct pci_dev *dev, pci_power_t state, int enable);
        void (*shutdown) (struct pci_dev *dev);

        struct device_driver driver;
        struct pci_dynids dynids;
};
# 289 "include/linux/pci.h"
extern struct bus_type pci_bus_type;



extern struct list_head pci_root_buses;
extern struct list_head pci_devices;

void pcibios_fixup_bus(struct pci_bus *);
int pcibios_enable_device(struct pci_dev *, int mask);
char *pcibios_setup (char *str);


void pcibios_align_resource(void *, struct resource *,
                            unsigned long, unsigned long);
void pcibios_update_irq(struct pci_dev *, int irq);



extern struct pci_bus *pci_find_bus(int domain, int busnr);
void pci_bus_add_devices(struct pci_bus *bus);
struct pci_bus *pci_scan_bus_parented(struct device *parent, int bus, struct pci_ops *ops, void *sysdata);
static inline __attribute__((always_inline)) struct pci_bus *pci_scan_bus(int bus, struct pci_ops *ops, void *sysdata)
{
        struct pci_bus *root_bus;
        root_bus = pci_scan_bus_parented(((void *)0), bus, ops, sysdata);
        if (root_bus)
                pci_bus_add_devices(root_bus);
        return root_bus;
}
struct pci_bus *pci_create_bus(struct device *parent, int bus, struct pci_ops *ops, void *sysdata);
struct pci_bus * pci_add_new_bus(struct pci_bus *parent, struct pci_dev *dev, int busnr);
int pci_scan_slot(struct pci_bus *bus, int devfn);
struct pci_dev * pci_scan_single_device(struct pci_bus *bus, int devfn);
void pci_device_add(struct pci_dev *dev, struct pci_bus *bus);
unsigned int pci_scan_child_bus(struct pci_bus *bus);
void pci_bus_add_device(struct pci_dev *dev);
void pci_read_bridge_bases(struct pci_bus *child);
struct resource *pci_find_parent_resource(const struct pci_dev *dev, struct resource *res);
int pci_get_interrupt_pin(struct pci_dev *dev, struct pci_dev **bridge);
extern struct pci_dev *pci_dev_get(struct pci_dev *dev);
extern void pci_dev_put(struct pci_dev *dev);
extern void pci_remove_bus(struct pci_bus *b);
extern void pci_remove_bus_device(struct pci_dev *dev);
void pci_setup_cardbus(struct pci_bus *bus);



struct pci_dev *pci_find_device (unsigned int vendor, unsigned int device, const struct pci_dev *from);
struct pci_dev *pci_find_device_reverse (unsigned int vendor, unsigned int device, const struct pci_dev *from);
struct pci_dev *pci_find_slot (unsigned int bus, unsigned int devfn);
int pci_find_capability (struct pci_dev *dev, int cap);
int pci_find_ext_capability (struct pci_dev *dev, int cap);
struct pci_bus * pci_find_next_bus(const struct pci_bus *from);

struct pci_dev *pci_get_device (unsigned int vendor, unsigned int device, struct pci_dev *from);
struct pci_dev *pci_get_subsys (unsigned int vendor, unsigned int device,
                                unsigned int ss_vendor, unsigned int ss_device,
                                struct pci_dev *from);
struct pci_dev *pci_get_slot (struct pci_bus *bus, unsigned int devfn);
struct pci_dev *pci_get_class (unsigned int class, struct pci_dev *from);
int pci_dev_present(const struct pci_device_id *ids);

int pci_bus_read_config_byte (struct pci_bus *bus, unsigned int devfn, int where, u8 *val);
int pci_bus_read_config_word (struct pci_bus *bus, unsigned int devfn, int where, u16 *val);
int pci_bus_read_config_dword (struct pci_bus *bus, unsigned int devfn, int where, u32 *val);
int pci_bus_write_config_byte (struct pci_bus *bus, unsigned int devfn, int where, u8 val);
int pci_bus_write_config_word (struct pci_bus *bus, unsigned int devfn, int where, u16 val);
int pci_bus_write_config_dword (struct pci_bus *bus, unsigned int devfn, int where, u32 val);

static inline __attribute__((always_inline)) int pci_read_config_byte(struct pci_dev *dev, int where, u8 *val)
{
        return pci_bus_read_config_byte (dev->bus, dev->devfn, where, val);
}
static inline __attribute__((always_inline)) int pci_read_config_word(struct pci_dev *dev, int where, u16 *val)
{
        return pci_bus_read_config_word (dev->bus, dev->devfn, where, val);
}
static inline __attribute__((always_inline)) int pci_read_config_dword(struct pci_dev *dev, int where, u32 *val)
{
        return pci_bus_read_config_dword (dev->bus, dev->devfn, where, val);
}
static inline __attribute__((always_inline)) int pci_write_config_byte(struct pci_dev *dev, int where, u8 val)
{
        return pci_bus_write_config_byte (dev->bus, dev->devfn, where, val);
}
static inline __attribute__((always_inline)) int pci_write_config_word(struct pci_dev *dev, int where, u16 val)
{
        return pci_bus_write_config_word (dev->bus, dev->devfn, where, val);
}
static inline __attribute__((always_inline)) int pci_write_config_dword(struct pci_dev *dev, int where, u32 val)
{
        return pci_bus_write_config_dword (dev->bus, dev->devfn, where, val);
}

int pci_enable_device(struct pci_dev *dev);
int pci_enable_device_bars(struct pci_dev *dev, int mask);
void pci_disable_device(struct pci_dev *dev);
void pci_set_master(struct pci_dev *dev);

int pci_set_mwi(struct pci_dev *dev);
void pci_clear_mwi(struct pci_dev *dev);
void pci_intx(struct pci_dev *dev, int enable);
int pci_set_dma_mask(struct pci_dev *dev, u64 mask);
int pci_set_consistent_dma_mask(struct pci_dev *dev, u64 mask);
void pci_update_resource(struct pci_dev *dev, struct resource *res, int resno);
int pci_assign_resource(struct pci_dev *dev, int i);
void pci_restore_bars(struct pci_dev *dev);


void *pci_map_rom(struct pci_dev *pdev, size_t *size);
void *pci_map_rom_copy(struct pci_dev *pdev, size_t *size);
void pci_unmap_rom(struct pci_dev *pdev, void *rom);
void pci_remove_rom(struct pci_dev *pdev);


int pci_save_state(struct pci_dev *dev);
int pci_restore_state(struct pci_dev *dev);
int pci_set_power_state(struct pci_dev *dev, pci_power_t state);
pci_power_t pci_choose_state(struct pci_dev *dev, pm_message_t state);
int pci_enable_wake(struct pci_dev *dev, pci_power_t state, int enable);


void pci_bus_assign_resources(struct pci_bus *bus);
void pci_bus_size_bridges(struct pci_bus *bus);
int pci_claim_resource(struct pci_dev *, int);
void pci_assign_unassigned_resources(void);
void pdev_enable_device(struct pci_dev *);
void pdev_sort_resources(struct pci_dev *, struct resource_list *);
void pci_fixup_irqs(u8 (*)(struct pci_dev *, u8 *),
                    int (*)(struct pci_dev *, u8, u8));

int pci_request_regions(struct pci_dev *, char *);
void pci_release_regions(struct pci_dev *);
int pci_request_region(struct pci_dev *, int, char *);
void pci_release_region(struct pci_dev *, int);


int pci_bus_alloc_resource(struct pci_bus *bus, struct resource *res,
                           unsigned long size, unsigned long align,
                           unsigned long min, unsigned int type_mask,
                           void (*alignf)(void *, struct resource *,
                                          unsigned long, unsigned long),
                           void *alignf_data);
void pci_enable_bridges(struct pci_bus *bus);


int pci_register_driver(struct pci_driver *);
void pci_unregister_driver(struct pci_driver *);
void pci_remove_behind_bridge(struct pci_dev *);
struct pci_driver *pci_dev_driver(const struct pci_dev *);
const struct pci_device_id *pci_match_device(struct pci_driver *drv, struct pci_dev *dev);
const struct pci_device_id *pci_match_id(const struct pci_device_id *ids, struct pci_dev *dev);
int pci_scan_bridge(struct pci_bus *bus, struct pci_dev * dev, int max, int pass);

void pci_walk_bus(struct pci_bus *top, void (*cb)(struct pci_dev *, void *),
                  void *userdata);



# 1 "include/linux/dmapool.h" 1
# 14 "include/linux/dmapool.h"
# 1 "include/asm/io.h" 1
# 48 "include/asm/io.h"
# 1 "include/asm-generic/iomap.h" 1
# 28 "include/asm-generic/iomap.h"
extern unsigned int __attribute__((regparm(3))) ioread8(void *);
extern unsigned int __attribute__((regparm(3))) ioread16(void *);
extern unsigned int __attribute__((regparm(3))) ioread16be(void *);
extern unsigned int __attribute__((regparm(3))) ioread32(void *);
extern unsigned int __attribute__((regparm(3))) ioread32be(void *);

extern void __attribute__((regparm(3))) iowrite8(u8, void *);
extern void __attribute__((regparm(3))) iowrite16(u16, void *);
extern void __attribute__((regparm(3))) iowrite16be(u16, void *);
extern void __attribute__((regparm(3))) iowrite32(u32, void *);
extern void __attribute__((regparm(3))) iowrite32be(u32, void *);
# 51 "include/asm-generic/iomap.h"
extern void __attribute__((regparm(3))) ioread8_rep(void *port, void *buf, unsigned long count);
extern void __attribute__((regparm(3))) ioread16_rep(void *port, void *buf, unsigned long count);
extern void __attribute__((regparm(3))) ioread32_rep(void *port, void *buf, unsigned long count);

extern void __attribute__((regparm(3))) iowrite8_rep(void *port, const void *buf, unsigned long count);
extern void __attribute__((regparm(3))) iowrite16_rep(void *port, const void *buf, unsigned long count);
extern void __attribute__((regparm(3))) iowrite32_rep(void *port, const void *buf, unsigned long count);


extern void *ioport_map(unsigned long port, unsigned int nr);
extern void ioport_unmap(void *);


struct pci_dev;
extern void *pci_iomap(struct pci_dev *dev, int bar, unsigned long max);
extern void pci_iounmap(struct pci_dev *dev, void *);
# 49 "include/asm/io.h" 2

# 1 "include/linux/vmalloc.h" 1
# 21 "include/linux/vmalloc.h"
struct vm_struct {
        void *addr;
        unsigned long size;
        unsigned long flags;
        struct page **pages;
        unsigned int nr_pages;
        unsigned long phys_addr;
        struct vm_struct *next;
};




extern void *vmalloc(unsigned long size);
extern void *vmalloc_exec(unsigned long size);
extern void *vmalloc_32(unsigned long size);
extern void *__vmalloc(unsigned long size, gfp_t gfp_mask, pgprot_t prot);
extern void *__vmalloc_area(struct vm_struct *area, gfp_t gfp_mask, pgprot_t prot);
extern void vfree(void *addr);

extern void *vmap(struct page **pages, unsigned int count,
                        unsigned long flags, pgprot_t prot);
extern void vunmap(void *addr);




extern struct vm_struct *get_vm_area(unsigned long size, unsigned long flags);
extern struct vm_struct *__get_vm_area(unsigned long size, unsigned long flags,
                                        unsigned long start, unsigned long end);
extern struct vm_struct *remove_vm_area(void *addr);
extern struct vm_struct *__remove_vm_area(void *addr);
extern int map_vm_area(struct vm_struct *area, pgprot_t prot,
                        struct page ***pages);
extern void unmap_vm_area(struct vm_struct *area);




extern rwlock_t vmlist_lock;
extern struct vm_struct *vmlist;
# 51 "include/asm/io.h" 2
# 76 "include/asm/io.h"
static inline __attribute__((always_inline)) unsigned long virt_to_phys(volatile void * address)
{
        return ((unsigned long)(address)-((unsigned long)(0xC0000000UL)));
}
# 94 "include/asm/io.h"
static inline __attribute__((always_inline)) void * phys_to_virt(unsigned long address)
{
        return ((void *)((unsigned long)(address)+((unsigned long)(0xC0000000UL))));
}






extern void * __ioremap(unsigned long offset, unsigned long size, unsigned long flags);
# 118 "include/asm/io.h"
static inline __attribute__((always_inline)) void * ioremap(unsigned long offset, unsigned long size)
{
        return __ioremap(offset, size, 0);
}

extern void * ioremap_nocache(unsigned long offset, unsigned long size);
extern void iounmap(volatile void *addr);






extern void *bt_ioremap(unsigned long offset, unsigned long size);
extern void bt_iounmap(void *addr, unsigned long size);
# 157 "include/asm/io.h"
static inline __attribute__((always_inline)) unsigned char readb(const volatile void *addr)
{
        return *(volatile unsigned char *) addr;
}
static inline __attribute__((always_inline)) unsigned short readw(const volatile void *addr)
{
        return *(volatile unsigned short *) addr;
}
static inline __attribute__((always_inline)) unsigned int readl(const volatile void *addr)
{
        return *(volatile unsigned int *) addr;
}







static inline __attribute__((always_inline)) void writeb(unsigned char b, volatile void *addr)
{
        *(volatile unsigned char *) addr = b;
}
static inline __attribute__((always_inline)) void writew(unsigned short b, volatile void *addr)
{
        *(volatile unsigned short *) addr = b;
}
static inline __attribute__((always_inline)) void writel(unsigned int b, volatile void *addr)
{
        *(volatile unsigned int *) addr = b;
}






static inline __attribute__((always_inline)) void memset_io(volatile void *addr, unsigned char val, int count)
{
        (__builtin_constant_p(val) ? (__builtin_constant_p((count)) ? __constant_c_and_count_memset((((void *) addr)),((0x01010101UL*(unsigned char)(val))),((count))) : __constant_c_memset((((void *) addr)),((0x01010101UL*(unsigned char)(val))),((count)))) : (__builtin_constant_p((count)) ? __memset_generic(((((void *) addr))),(((val))),(((count)))) : __memset_generic((((void *) addr)),((val)),((count)))));
}
static inline __attribute__((always_inline)) void memcpy_fromio(void *dst, const volatile void *src, int count)
{
        __memcpy(dst, (void *) src, count);
}
static inline __attribute__((always_inline)) void memcpy_toio(volatile void *dst, const void *src, int count)
{
        __memcpy((void *) dst, src, count);
}
# 246 "include/asm/io.h"
static inline __attribute__((always_inline)) int check_signature(volatile void * io_addr,
        const unsigned char *signature, int length)
{
        int retval = 0;
        do {
                if (readb(io_addr) != *signature)
                        goto out;
                io_addr++;
                signature++;
                length--;
        } while (length);
        retval = 1;
out:
        return retval;
}
# 272 "include/asm/io.h"
static inline __attribute__((always_inline)) void flush_write_buffers(void)
{
        __asm__ __volatile__ ("lock; addl $0,0(%%esp)": : :"memory");
}
# 300 "include/asm/io.h"
static inline __attribute__((always_inline)) void slow_down_io(void) {
        __asm__ __volatile__(
                "outb %%al,$0x80;"



                : : );
}
# 377 "include/asm/io.h"
static inline __attribute__((always_inline)) void outb_local(unsigned char value, int port) { __asm__ __volatile__("out" "b" " %" "b" "0, %w1" : : "a"(value), "Nd"(port)); } static inline __attribute__((always_inline)) unsigned char inb_local(int port) { unsigned char value; __asm__ __volatile__("in" "b" " %w1, %" "b" "0" : "=a"(value) : "Nd"(port)); return value; } static inline __attribute__((always_inline)) void outb_local_p(unsigned char value, int port) { outb_local(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned char inb_local_p(int port) { unsigned char value = inb_local(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outb(unsigned char value, int port) { outb_local(value, port); } static inline __attribute__((always_inline)) unsigned char inb(int port) { return inb_local(port); } static inline __attribute__((always_inline)) void outb_p(unsigned char value, int port) { outb(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned char inb_p(int port) { unsigned char value = inb(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outsb(int port, const void *addr, unsigned long count) { __asm__ __volatile__("rep; outs" "b" : "+S"(addr), "+c"(count) : "d"(port)); } static inline __attribute__((always_inline)) void insb(int port, void *addr, unsigned long count) { __asm__ __volatile__("rep; ins" "b" : "+D"(addr), "+c"(count) : "d"(port)); }
static inline __attribute__((always_inline)) void outw_local(unsigned short value, int port) { __asm__ __volatile__("out" "w" " %" "w" "0, %w1" : : "a"(value), "Nd"(port)); } static inline __attribute__((always_inline)) unsigned short inw_local(int port) { unsigned short value; __asm__ __volatile__("in" "w" " %w1, %" "w" "0" : "=a"(value) : "Nd"(port)); return value; } static inline __attribute__((always_inline)) void outw_local_p(unsigned short value, int port) { outw_local(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned short inw_local_p(int port) { unsigned short value = inw_local(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outw(unsigned short value, int port) { outw_local(value, port); } static inline __attribute__((always_inline)) unsigned short inw(int port) { return inw_local(port); } static inline __attribute__((always_inline)) void outw_p(unsigned short value, int port) { outw(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned short inw_p(int port) { unsigned short value = inw(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outsw(int port, const void *addr, unsigned long count) { __asm__ __volatile__("rep; outs" "w" : "+S"(addr), "+c"(count) : "d"(port)); } static inline __attribute__((always_inline)) void insw(int port, void *addr, unsigned long count) { __asm__ __volatile__("rep; ins" "w" : "+D"(addr), "+c"(count) : "d"(port)); }
static inline __attribute__((always_inline)) void outl_local(unsigned int value, int port) { __asm__ __volatile__("out" "l" " %" "" "0, %w1" : : "a"(value), "Nd"(port)); } static inline __attribute__((always_inline)) unsigned int inl_local(int port) { unsigned int value; __asm__ __volatile__("in" "l" " %w1, %" "" "0" : "=a"(value) : "Nd"(port)); return value; } static inline __attribute__((always_inline)) void outl_local_p(unsigned int value, int port) { outl_local(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned int inl_local_p(int port) { unsigned int value = inl_local(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outl(unsigned int value, int port) { outl_local(value, port); } static inline __attribute__((always_inline)) unsigned int inl(int port) { return inl_local(port); } static inline __attribute__((always_inline)) void outl_p(unsigned int value, int port) { outl(value, port); slow_down_io(); } static inline __attribute__((always_inline)) unsigned int inl_p(int port) { unsigned int value = inl(port); slow_down_io(); return value; } static inline __attribute__((always_inline)) void outsl(int port, const void *addr, unsigned long count) { __asm__ __volatile__("rep; outs" "l" : "+S"(addr), "+c"(count) : "d"(port)); } static inline __attribute__((always_inline)) void insl(int port, void *addr, unsigned long count) { __asm__ __volatile__("rep; ins" "l" : "+D"(addr), "+c"(count) : "d"(port)); }
# 15 "include/linux/dmapool.h" 2
# 1 "include/asm/scatterlist.h" 1



struct scatterlist {
    struct page *page;
    unsigned int offset;
    dma_addr_t dma_address;
    unsigned int length;
};
# 16 "include/linux/dmapool.h" 2

struct dma_pool *dma_pool_create(const char *name, struct device *dev,
                        size_t size, size_t align, size_t allocation);

void dma_pool_destroy(struct dma_pool *pool);

void *dma_pool_alloc(struct dma_pool *pool, gfp_t mem_flags,
                     dma_addr_t *handle);

void dma_pool_free(struct dma_pool *pool, void *vaddr, dma_addr_t addr);
# 449 "include/linux/pci.h" 2
# 457 "include/linux/pci.h"
enum pci_dma_burst_strategy {
        PCI_DMA_BURST_INFINITY,

        PCI_DMA_BURST_BOUNDARY,

        PCI_DMA_BURST_MULTIPLE,

};


extern struct pci_dev *isa_bridge;


struct msix_entry {
        u16 vector;
        u16 entry;
};


static inline __attribute__((always_inline)) void pci_scan_msi_device(struct pci_dev *dev) {}
static inline __attribute__((always_inline)) int pci_enable_msi(struct pci_dev *dev) {return -1;}
static inline __attribute__((always_inline)) void pci_disable_msi(struct pci_dev *dev) {}
static inline __attribute__((always_inline)) int pci_enable_msix(struct pci_dev* dev,
        struct msix_entry *entries, int nvec) {return -1;}
static inline __attribute__((always_inline)) void pci_disable_msix(struct pci_dev *dev) {}
static inline __attribute__((always_inline)) void msi_remove_pci_irq_vectors(struct pci_dev *dev) {}
# 499 "include/linux/pci.h"
static inline __attribute__((always_inline)) int pci_domain_nr(struct pci_bus *bus) { return 0; }
static inline __attribute__((always_inline)) int pci_proc_domain(struct pci_bus *bus)
{
        return 0;
}
# 567 "include/linux/pci.h"
# 1 "include/asm/pci.h" 1






# 1 "include/linux/mm.h" 1
# 14 "include/linux/mm.h"
# 1 "include/linux/prio_tree.h" 1
# 14 "include/linux/prio_tree.h"
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
# 84 "include/linux/prio_tree.h"
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
# 15 "include/linux/mm.h" 2
# 1 "include/linux/fs.h" 1
# 10 "include/linux/fs.h"
# 1 "include/linux/limits.h" 1
# 11 "include/linux/fs.h" 2
# 1 "include/linux/ioctl.h" 1



# 1 "include/asm/ioctl.h" 1
# 56 "include/asm/ioctl.h"
extern unsigned int __invalid_size_argument_for_IOC;
# 5 "include/linux/ioctl.h" 2
# 12 "include/linux/fs.h" 2
# 1 "include/linux/rcuref.h" 1
# 119 "include/linux/rcuref.h"
extern spinlock_t __rcuref_hash[];
# 142 "include/linux/rcuref.h"
static inline __attribute__((always_inline)) void rcuref_inc(atomic_t *rcuref)
{
        unsigned long flags;
        flags = _spin_lock_irqsave((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]));
        rcuref->counter += 1;
        _spin_unlock_irqrestore((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]), flags);
}
# 158 "include/linux/rcuref.h"
static inline __attribute__((always_inline)) void rcuref_dec(atomic_t *rcuref)
{
        unsigned long flags;
        flags = _spin_lock_irqsave((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]));
        rcuref->counter -= 1;
        _spin_unlock_irqrestore((&__rcuref_hash[(((unsigned long)rcuref)>>8) & (4 -1)]), flags);
}
# 179 "include/linux/rcuref.h"
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
# 203 "include/linux/rcuref.h"
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
# 13 "include/linux/fs.h" 2
# 33 "include/linux/fs.h"
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
# 209 "include/linux/fs.h"
# 1 "include/linux/kdev_t.h" 1
# 21 "include/linux/kdev_t.h"
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
# 210 "include/linux/fs.h" 2
# 1 "include/linux/dcache.h" 1
# 10 "include/linux/dcache.h"
# 1 "include/linux/rcupdate.h" 1
# 50 "include/linux/rcupdate.h"
struct rcu_head {
        struct rcu_head *next;
        void (*func)(struct rcu_head *head);
};
# 64 "include/linux/rcupdate.h"
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
# 275 "include/linux/rcupdate.h"
extern void rcu_init(void);
extern void rcu_check_callbacks(int cpu, int user);
extern void rcu_restart_cpu(int cpu);


extern void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head)) __attribute__((regparm(3)));

extern void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *head)) __attribute__((regparm(3)));

extern void synchronize_kernel(void);
extern void synchronize_rcu(void);
void synchronize_idle(void);
# 11 "include/linux/dcache.h" 2


struct nameidata;
struct vfsmount;
# 34 "include/linux/dcache.h"
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
# 159 "include/linux/dcache.h"
extern spinlock_t dcache_lock;
# 177 "include/linux/dcache.h"
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
# 241 "include/linux/dcache.h"
static inline __attribute__((always_inline)) void d_add(struct dentry *entry, struct inode *inode)
{
        d_instantiate(entry, inode);
        d_rehash(entry);
}
# 255 "include/linux/dcache.h"
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
# 291 "include/linux/dcache.h"
static inline __attribute__((always_inline)) struct dentry *dget(struct dentry *dentry)
{
        if (dentry) {
                do { if (__builtin_expect(!!((!((&dentry->d_count)->counter))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (294), "i" ("include/linux/dcache.h")); } while(0);
                atomic_inc(&dentry->d_count);
        }
        return dentry;
}

extern struct dentry * dget_locked(struct dentry *);
# 309 "include/linux/dcache.h"
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
# 211 "include/linux/fs.h" 2




# 1 "include/linux/radix-tree.h" 1
# 25 "include/linux/radix-tree.h"
struct radix_tree_root {
        unsigned int height;
        unsigned int gfp_mask;
        struct radix_tree_node *rnode;
};
# 47 "include/linux/radix-tree.h"
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
# 216 "include/linux/fs.h" 2
# 224 "include/linux/fs.h"
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
# 277 "include/linux/fs.h"
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




# 1 "include/linux/quota.h" 1
# 45 "include/linux/quota.h"
typedef __kernel_uid32_t qid_t;
typedef __u64 qsize_t;

extern spinlock_t dq_data_lock;
# 106 "include/linux/quota.h"
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
# 127 "include/linux/quota.h"
struct if_dqinfo {
        __u64 dqi_bgrace;
        __u64 dqi_igrace;
        __u32 dqi_flags;
        __u32 dqi_valid;
};



# 1 "include/linux/dqblk_xfs.h" 1
# 52 "include/linux/dqblk_xfs.h"
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
# 139 "include/linux/dqblk_xfs.h"
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
# 137 "include/linux/quota.h" 2
# 1 "include/linux/dqblk_v1.h" 1
# 21 "include/linux/dqblk_v1.h"
struct v1_mem_dqinfo {
};
# 138 "include/linux/quota.h" 2
# 1 "include/linux/dqblk_v2.h" 1
# 20 "include/linux/dqblk_v2.h"
struct v2_mem_dqinfo {
        unsigned int dqi_blocks;
        unsigned int dqi_free_blk;
        unsigned int dqi_free_entry;
};
# 139 "include/linux/quota.h" 2
# 150 "include/linux/quota.h"
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
# 213 "include/linux/quota.h"
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
# 308 "include/linux/quota.h"
int register_quota_format(struct quota_format_type *fmt);
void unregister_quota_format(struct quota_format_type *fmt);

struct quota_module_name {
        int qm_fmt_id;
        char *qm_mod_name;
};
# 292 "include/linux/fs.h" 2




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
# 389 "include/linux/fs.h"
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
# 422 "include/linux/fs.h"
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
# 499 "include/linux/fs.h"
static inline __attribute__((always_inline)) loff_t i_size_read(struct inode *inode)
{

        loff_t i_size;
        unsigned int seq;

        do {
                seq = read_seqcount_begin(&inode->i_size_seqcount);
                i_size = inode->i_size;
        } while (read_seqcount_retry(&inode->i_size_seqcount, seq));
        return i_size;
# 520 "include/linux/fs.h"
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
# 634 "include/linux/fs.h"
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


# 1 "include/linux/nfs_fs_i.h" 1





# 1 "include/linux/nfs.h" 1
# 10 "include/linux/nfs.h"
# 1 "include/linux/sunrpc/msg_prot.h" 1
# 15 "include/linux/sunrpc/msg_prot.h"
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
# 11 "include/linux/nfs.h" 2
# 42 "include/linux/nfs.h"
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
# 165 "include/linux/nfs.h"
enum nfs3_stable_how {
        NFS_UNSTABLE = 0,
        NFS_DATA_SYNC = 1,
        NFS_FILE_SYNC = 2
};
# 7 "include/linux/nfs_fs_i.h" 2

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
# 655 "include/linux/fs.h" 2

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
# 687 "include/linux/fs.h"
extern struct list_head file_lock_list;

# 1 "include/linux/fcntl.h" 1



# 1 "include/asm/fcntl.h" 1
# 1 "include/asm-generic/fcntl.h" 1
# 115 "include/asm-generic/fcntl.h"
struct flock {
        short l_type;
        short l_whence;
        off_t l_start;
        off_t l_len;
        pid_t l_pid;
       
};
# 138 "include/asm-generic/fcntl.h"
struct flock64 {
        short l_type;
        short l_whence;
        loff_t l_start;
        loff_t l_len;
        pid_t l_pid;
       
};
# 2 "include/asm/fcntl.h" 2
# 5 "include/linux/fcntl.h" 2
# 690 "include/linux/fs.h" 2

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
# 753 "include/linux/fs.h"
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
# 892 "include/linux/fs.h"
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
# 923 "include/linux/fs.h"
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
# 946 "include/linux/fs.h"
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
# 1053 "include/linux/fs.h"
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
# 1162 "include/linux/fs.h"
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
# 1253 "include/linux/fs.h"
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
# 1304 "include/linux/fs.h"
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
# 1366 "include/linux/fs.h"
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

# 1 "include/linux/err.h" 1
# 18 "include/linux/err.h"
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
# 1425 "include/linux/fs.h" 2


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
# 1533 "include/linux/fs.h"
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
# 1732 "include/linux/fs.h"
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
# 1759 "include/linux/fs.h"
static inline __attribute__((always_inline)) char *alloc_secdata(void)
{
        return (char *)1;
}

static inline __attribute__((always_inline)) void free_secdata(void *secdata)
{ }
# 16 "include/linux/mm.h" 2

struct mempolicy;
struct anon_vma;


extern unsigned long max_mapnr;


extern unsigned long num_physpages;
extern void * high_memory;
extern unsigned long vmalloc_earlyreserve;
extern int page_cluster;


extern int sysctl_legacy_va_layout;





# 1 "include/asm/pgtable.h" 1
# 33 "include/asm/pgtable.h"
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







# 1 "include/asm/pgtable-3level-defs.h" 1
# 53 "include/asm/pgtable.h" 2
# 157 "include/asm/pgtable.h"
extern unsigned long long __PAGE_KERNEL, __PAGE_KERNEL_EXEC;
# 201 "include/asm/pgtable.h"
extern unsigned long pg0[];
# 219 "include/asm/pgtable.h"
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


# 1 "include/asm/pgtable-3level.h" 1



# 1 "include/asm-generic/pgtable-nopud.h" 1
# 13 "include/asm-generic/pgtable-nopud.h"
typedef struct { pgd_t pgd; } pud_t;
# 25 "include/asm-generic/pgtable-nopud.h"
static inline __attribute__((always_inline)) int pgd_none(pgd_t pgd) { return 0; }
static inline __attribute__((always_inline)) int pgd_bad(pgd_t pgd) { return 0; }
static inline __attribute__((always_inline)) int pgd_present(pgd_t pgd) { return 1; }
static inline __attribute__((always_inline)) void pgd_clear(pgd_t *pgd) { }
# 38 "include/asm-generic/pgtable-nopud.h"
static inline __attribute__((always_inline)) pud_t * pud_offset(pgd_t * pgd, unsigned long address)
{
        return (pud_t *)pgd;
}
# 5 "include/asm/pgtable-3level.h" 2
# 27 "include/asm/pgtable-3level.h"
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
# 75 "include/asm/pgtable-3level.h"
static inline __attribute__((always_inline)) void pud_clear (pud_t * pud) { }
# 93 "include/asm/pgtable-3level.h"
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
# 245 "include/asm/pgtable.h" 2




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
# 290 "include/asm/pgtable.h"
static inline __attribute__((always_inline)) void clone_pgd_range(pgd_t *dst, pgd_t *src, int count)
{
       (__builtin_constant_p(count * sizeof(pgd_t)) ? __constant_memcpy((dst),(src),(count * sizeof(pgd_t))) : __memcpy((dst),(src),(count * sizeof(pgd_t))));
}
# 309 "include/asm/pgtable.h"
static inline __attribute__((always_inline)) pte_t pte_modify(pte_t pte, pgprot_t newprot)
{
        pte.pte_low &= ((~((1UL << 12)-1)) | 0x020 | 0x040);
        pte.pte_low |= ((newprot).pgprot);





        pte.pte_high &= ~(1 << (63 - 32));
        pte.pte_high |= (((newprot).pgprot) >> 32) & (__supported_pte_mask >> 32);


        return pte;
}
# 377 "include/asm/pgtable.h"
extern pte_t *lookup_address(unsigned long address);
# 386 "include/asm/pgtable.h"
 extern int set_kernel_exec(unsigned long vaddr, int enable);




extern void noexec_setup(const char *str);
# 447 "include/asm/pgtable.h"
# 1 "include/asm-generic/pgtable.h" 1
# 205 "include/asm-generic/pgtable.h"
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
# 448 "include/asm/pgtable.h" 2
# 37 "include/linux/mm.h" 2
# 57 "include/linux/mm.h"
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
# 186 "include/linux/mm.h"
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
# 221 "include/linux/mm.h"
struct page {
        page_flags_t flags;

        atomic_t _count;
        atomic_t _mapcount;



        unsigned long private;






        struct address_space *mapping;






        unsigned long index;
        struct list_head lru;
# 261 "include/linux/mm.h"
};





# 1 "include/linux/page-flags.h" 1
# 83 "include/linux/page-flags.h"
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
# 310 "include/linux/page-flags.h"
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
# 268 "include/linux/mm.h" 2
# 310 "include/linux/mm.h"
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
# 470 "include/linux/mm.h"
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
# 544 "include/linux/mm.h"
void *page_address(struct page *page);
void set_page_address(struct page *page, void *virtual);
void page_address_init(void);
# 566 "include/linux/mm.h"
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
# 641 "include/linux/mm.h"
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
# 750 "include/linux/mm.h"
typedef int (*shrinker_t)(int nr_to_scan, unsigned int gfp_mask);







struct shrinker;
extern struct shrinker *set_shrinker(int, shrinker_t);
extern void remove_shrinker(struct shrinker *shrinker);
# 773 "include/linux/mm.h"
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
# 8 "include/asm/pci.h" 2






extern unsigned int pcibios_assign_all_busses(void);





extern unsigned long pci_mem_start;





void pcibios_config_init(void);
struct pci_bus * pcibios_scan_root(int bus);

void pcibios_set_master(struct pci_dev *dev);
void pcibios_penalize_isa_irq(int irq, int active);
struct irq_routing_table *pcibios_get_irq_routing_table(void);
int pcibios_set_irq_routing(struct pci_dev *dev, int pin, int irq);
# 44 "include/asm/pci.h"
struct pci_dev;
# 63 "include/asm/pci.h"
static inline __attribute__((always_inline)) dma64_addr_t
pci_dac_page_to_dma(struct pci_dev *pdev, struct page *page, unsigned long offset, int direction)
{
        return ((dma64_addr_t) ((dma_addr_t)((unsigned long)((page) - mem_map)) << 12) +
                (dma64_addr_t) offset);
}

static inline __attribute__((always_inline)) struct page *
pci_dac_dma_to_page(struct pci_dev *pdev, dma64_addr_t dma_addr)
{
        return (mem_map + (dma_addr >> 12));
}

static inline __attribute__((always_inline)) unsigned long
pci_dac_dma_to_offset(struct pci_dev *pdev, dma64_addr_t dma_addr)
{
        return (dma_addr & ~(~((1UL << 12)-1)));
}

static inline __attribute__((always_inline)) void
pci_dac_dma_sync_single_for_cpu(struct pci_dev *pdev, dma64_addr_t dma_addr, size_t len, int direction)
{
}

static inline __attribute__((always_inline)) void
pci_dac_dma_sync_single_for_device(struct pci_dev *pdev, dma64_addr_t dma_addr, size_t len, int direction)
{
        flush_write_buffers();
}


extern int pci_mmap_page_range(struct pci_dev *dev, struct vm_area_struct *vma,
                               enum pci_mmap_state mmap_state, int write_combine);


static inline __attribute__((always_inline)) void pcibios_add_platform_entries(struct pci_dev *dev)
{
}


static inline __attribute__((always_inline)) void pci_dma_burst_advice(struct pci_dev *pdev,
                                        enum pci_dma_burst_strategy *strat,
                                        unsigned long *strategy_parameter)
{
        *strat = PCI_DMA_BURST_INFINITY;
        *strategy_parameter = ~0UL;
}





# 1 "include/asm-generic/pci-dma-compat.h" 1






# 1 "include/linux/dma-mapping.h" 1
# 9 "include/linux/dma-mapping.h"
enum dma_data_direction {
        DMA_BIDIRECTIONAL = 0,
        DMA_TO_DEVICE = 1,
        DMA_FROM_DEVICE = 2,
        DMA_NONE = 3,
};
# 24 "include/linux/dma-mapping.h"
# 1 "include/asm/dma-mapping.h" 1
# 13 "include/asm/dma-mapping.h"
void *dma_alloc_coherent(struct device *dev, size_t size,
                           dma_addr_t *dma_handle, gfp_t flag);

void dma_free_coherent(struct device *dev, size_t size,
                         void *vaddr, dma_addr_t dma_handle);

static inline __attribute__((always_inline)) dma_addr_t
dma_map_single(struct device *dev, void *ptr, size_t size,
               enum dma_data_direction direction)
{
        do { if (__builtin_expect(!!((direction == DMA_NONE)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (23), "i" ("include/asm/dma-mapping.h")); } while(0);
        flush_write_buffers();
        return virt_to_phys(ptr);
}

static inline __attribute__((always_inline)) void
dma_unmap_single(struct device *dev, dma_addr_t dma_addr, size_t size,
                 enum dma_data_direction direction)
{
        do { if (__builtin_expect(!!((direction == DMA_NONE)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (32), "i" ("include/asm/dma-mapping.h")); } while(0);
}

static inline __attribute__((always_inline)) int
dma_map_sg(struct device *dev, struct scatterlist *sg, int nents,
           enum dma_data_direction direction)
{
        int i;

        do { if (__builtin_expect(!!((direction == DMA_NONE)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (41), "i" ("include/asm/dma-mapping.h")); } while(0);

        for (i = 0; i < nents; i++ ) {
                do { if (__builtin_expect(!!((!sg[i].page)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (44), "i" ("include/asm/dma-mapping.h")); } while(0);

                sg[i].dma_address = ((dma_addr_t)((unsigned long)((sg[i].page) - mem_map)) << 12) + sg[i].offset;
        }

        flush_write_buffers();
        return nents;
}

static inline __attribute__((always_inline)) dma_addr_t
dma_map_page(struct device *dev, struct page *page, unsigned long offset,
             size_t size, enum dma_data_direction direction)
{
        do { if (__builtin_expect(!!((direction == DMA_NONE)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (57), "i" ("include/asm/dma-mapping.h")); } while(0);
        return ((dma_addr_t)((unsigned long)((page) - mem_map)) << 12) + offset;
}

static inline __attribute__((always_inline)) void
dma_unmap_page(struct device *dev, dma_addr_t dma_address, size_t size,
               enum dma_data_direction direction)
{
        do { if (__builtin_expect(!!((direction == DMA_NONE)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (65), "i" ("include/asm/dma-mapping.h")); } while(0);
}


static inline __attribute__((always_inline)) void
dma_unmap_sg(struct device *dev, struct scatterlist *sg, int nhwentries,
             enum dma_data_direction direction)
{
        do { if (__builtin_expect(!!((direction == DMA_NONE)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (73), "i" ("include/asm/dma-mapping.h")); } while(0);
}

static inline __attribute__((always_inline)) void
dma_sync_single_for_cpu(struct device *dev, dma_addr_t dma_handle, size_t size,
                        enum dma_data_direction direction)
{
}

static inline __attribute__((always_inline)) void
dma_sync_single_for_device(struct device *dev, dma_addr_t dma_handle, size_t size,
                        enum dma_data_direction direction)
{
        flush_write_buffers();
}

static inline __attribute__((always_inline)) void
dma_sync_single_range_for_cpu(struct device *dev, dma_addr_t dma_handle,
                              unsigned long offset, size_t size,
                              enum dma_data_direction direction)
{
}

static inline __attribute__((always_inline)) void
dma_sync_single_range_for_device(struct device *dev, dma_addr_t dma_handle,
                                 unsigned long offset, size_t size,
                                 enum dma_data_direction direction)
{
        flush_write_buffers();
}

static inline __attribute__((always_inline)) void
dma_sync_sg_for_cpu(struct device *dev, struct scatterlist *sg, int nelems,
                    enum dma_data_direction direction)
{
}

static inline __attribute__((always_inline)) void
dma_sync_sg_for_device(struct device *dev, struct scatterlist *sg, int nelems,
                    enum dma_data_direction direction)
{
        flush_write_buffers();
}

static inline __attribute__((always_inline)) int
dma_mapping_error(dma_addr_t dma_addr)
{
        return 0;
}

static inline __attribute__((always_inline)) int
dma_supported(struct device *dev, u64 mask)
{





        if(mask < 0x00ffffff)
                return 0;

        return 1;
}

static inline __attribute__((always_inline)) int
dma_set_mask(struct device *dev, u64 mask)
{
        if(!dev->dma_mask || !dma_supported(dev, mask))
                return -5;

        *dev->dma_mask = mask;

        return 0;
}

static inline __attribute__((always_inline)) int
dma_get_cache_alignment(void)
{


        return (1 << 7);
}



static inline __attribute__((always_inline)) void
dma_cache_sync(void *vaddr, size_t size,
               enum dma_data_direction direction)
{
        flush_write_buffers();
}


extern int
dma_declare_coherent_memory(struct device *dev, dma_addr_t bus_addr,
                            dma_addr_t device_addr, size_t size, int flags);

extern void
dma_release_declared_memory(struct device *dev);

extern void *
dma_mark_declared_memory_occupied(struct device *dev,
                                  dma_addr_t device_addr, size_t size);
# 25 "include/linux/dma-mapping.h" 2





extern u64 dma_get_required_mask(struct device *dev);
# 8 "include/asm-generic/pci-dma-compat.h" 2




static inline __attribute__((always_inline)) int
pci_dma_supported(struct pci_dev *hwdev, u64 mask)
{
        return dma_supported(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, mask);
}

static inline __attribute__((always_inline)) void *
pci_alloc_consistent(struct pci_dev *hwdev, size_t size,
                     dma_addr_t *dma_handle)
{
        return dma_alloc_coherent(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, size, dma_handle, (0x20u));
}

static inline __attribute__((always_inline)) void
pci_free_consistent(struct pci_dev *hwdev, size_t size,
                    void *vaddr, dma_addr_t dma_handle)
{
        dma_free_coherent(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, size, vaddr, dma_handle);
}

static inline __attribute__((always_inline)) dma_addr_t
pci_map_single(struct pci_dev *hwdev, void *ptr, size_t size, int direction)
{
        return dma_map_single(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, ptr, size, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) void
pci_unmap_single(struct pci_dev *hwdev, dma_addr_t dma_addr,
                 size_t size, int direction)
{
        dma_unmap_single(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, dma_addr, size, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) dma_addr_t
pci_map_page(struct pci_dev *hwdev, struct page *page,
             unsigned long offset, size_t size, int direction)
{
        return dma_map_page(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, page, offset, size, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) void
pci_unmap_page(struct pci_dev *hwdev, dma_addr_t dma_address,
               size_t size, int direction)
{
        dma_unmap_page(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, dma_address, size, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) int
pci_map_sg(struct pci_dev *hwdev, struct scatterlist *sg,
           int nents, int direction)
{
        return dma_map_sg(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, sg, nents, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) void
pci_unmap_sg(struct pci_dev *hwdev, struct scatterlist *sg,
             int nents, int direction)
{
        dma_unmap_sg(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, sg, nents, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) void
pci_dma_sync_single_for_cpu(struct pci_dev *hwdev, dma_addr_t dma_handle,
                    size_t size, int direction)
{
        dma_sync_single_for_cpu(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, dma_handle, size, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) void
pci_dma_sync_single_for_device(struct pci_dev *hwdev, dma_addr_t dma_handle,
                    size_t size, int direction)
{
        dma_sync_single_for_device(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, dma_handle, size, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) void
pci_dma_sync_sg_for_cpu(struct pci_dev *hwdev, struct scatterlist *sg,
                int nelems, int direction)
{
        dma_sync_sg_for_cpu(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, sg, nelems, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) void
pci_dma_sync_sg_for_device(struct pci_dev *hwdev, struct scatterlist *sg,
                int nelems, int direction)
{
        dma_sync_sg_for_device(hwdev == ((void *)0) ? ((void *)0) : &hwdev->dev, sg, nelems, (enum dma_data_direction)direction);
}

static inline __attribute__((always_inline)) int
pci_dma_mapping_error(dma_addr_t dma_addr)
{
        return dma_mapping_error(dma_addr);
}
# 116 "include/asm/pci.h" 2


# 1 "include/asm-generic/pci.h" 1
# 17 "include/asm-generic/pci.h"
static inline __attribute__((always_inline)) void
pcibios_resource_to_bus(struct pci_dev *dev, struct pci_bus_region *region,
                         struct resource *res)
{
        region->start = res->start;
        region->end = res->end;
}

static inline __attribute__((always_inline)) void
pcibios_bus_to_resource(struct pci_dev *dev, struct resource *res,
                        struct pci_bus_region *region)
{
        res->start = region->start;
        res->end = region->end;
}

static inline __attribute__((always_inline)) struct resource *
pcibios_select_root(struct pci_dev *pdev, struct resource *res)
{
        struct resource *root = ((void *)0);

        if (res->flags & 0x00000100)
                root = &ioport_resource;
        if (res->flags & 0x00000200)
                root = &iomem_resource;

        return root;
}




static inline __attribute__((always_inline)) int pci_get_legacy_ide_irq(struct pci_dev *dev, int channel)
{
        return channel ? 15 : 14;
}
# 119 "include/asm/pci.h" 2
# 568 "include/linux/pci.h" 2
# 586 "include/linux/pci.h"
static inline __attribute__((always_inline)) void *pci_get_drvdata (struct pci_dev *pdev)
{
        return dev_get_drvdata(&pdev->dev);
}

static inline __attribute__((always_inline)) void pci_set_drvdata (struct pci_dev *pdev, void *data)
{
        dev_set_drvdata(&pdev->dev, data);
}




static inline __attribute__((always_inline)) char *pci_name(struct pci_dev *pdev)
{
        return pdev->dev.bus_id;
}






static inline __attribute__((always_inline)) void pci_resource_to_user(const struct pci_dev *dev, int bar,
                const struct resource *rsrc, u64 *start, u64 *end)
{
        *start = rsrc->start;
        *end = rsrc->end;
}
# 625 "include/linux/pci.h"
struct pci_fixup {
        u16 vendor, device;
        void (*hook)(struct pci_dev *dev);
};

enum pci_fixup_pass {
        pci_fixup_early,
        pci_fixup_header,
        pci_fixup_final,
        pci_fixup_enable,
};
# 655 "include/linux/pci.h"
void pci_fixup_device(enum pci_fixup_pass pass, struct pci_dev *dev);

extern int pci_pci_problems;
# 120 "drivers/net/yellowfin.c" 2

# 1 "include/linux/mii.h" 1
# 12 "include/linux/mii.h"
# 1 "include/linux/if.h" 1
# 23 "include/linux/if.h"
# 1 "include/linux/socket.h" 1
# 11 "include/linux/socket.h"
struct __kernel_sockaddr_storage {
        unsigned short ss_family;

        char __data[128 - sizeof(unsigned short)];


} __attribute__ ((aligned((__alignof__ (struct sockaddr *)))));





# 1 "include/asm/socket.h" 1



# 1 "include/asm/sockios.h" 1
# 5 "include/asm/socket.h" 2
# 24 "include/linux/socket.h" 2
# 1 "include/linux/sockios.h" 1
# 25 "include/linux/socket.h" 2
# 1 "include/linux/uio.h" 1
# 20 "include/linux/uio.h"
struct iovec
{
        void *iov_base;
        __kernel_size_t iov_len;
};



struct kvec {
        void *iov_base;
        size_t iov_len;
};
# 54 "include/linux/uio.h"
static inline __attribute__((always_inline)) size_t iov_length(const struct iovec *iov, unsigned long nr_segs)
{
        unsigned long seg;
        size_t ret = 0;

        for (seg = 0; seg < nr_segs; seg++)
                ret += iov[seg].iov_len;
        return ret;
}

unsigned long iov_shorten(struct iovec *iov, unsigned long nr_segs, size_t to);
# 26 "include/linux/socket.h" 2



extern int sysctl_somaxconn;
extern void sock_init(void);

struct seq_file;
extern void socket_seq_show(struct seq_file *seq);


typedef unsigned short sa_family_t;





struct sockaddr {
        sa_family_t sa_family;
        char sa_data[14];
};

struct linger {
        int l_onoff;
        int l_linger;
};
# 60 "include/linux/socket.h"
struct msghdr {
        void * msg_name;
        int msg_namelen;
        struct iovec * msg_iov;
        __kernel_size_t msg_iovlen;
        void * msg_control;
        __kernel_size_t msg_controllen;
        unsigned msg_flags;
};







struct cmsghdr {
        __kernel_size_t cmsg_len;
        int cmsg_level;
        int cmsg_type;
};
# 133 "include/linux/socket.h"
static inline __attribute__((always_inline)) struct cmsghdr * __cmsg_nxthdr(void *__ctl, __kernel_size_t __size,
                                               struct cmsghdr *__cmsg)
{
        struct cmsghdr * __ptr;

        __ptr = (struct cmsghdr*)(((unsigned char *) __cmsg) + ( ((__cmsg->cmsg_len)+sizeof(long)-1) & ~(sizeof(long)-1) ));
        if ((unsigned long)((char*)(__ptr+1) - (char *) __ctl) > __size)
                return (struct cmsghdr *)0;

        return __ptr;
}

static inline __attribute__((always_inline)) struct cmsghdr * cmsg_nxthdr (struct msghdr *__msg, struct cmsghdr *__cmsg)
{
        return __cmsg_nxthdr(__msg->msg_control, __msg->msg_controllen, __cmsg);
}






struct ucred {
        __u32 pid;
        __u32 uid;
        __u32 gid;
};
# 288 "include/linux/socket.h"
extern int memcpy_fromiovec(unsigned char *kdata, struct iovec *iov, int len);
extern int memcpy_fromiovecend(unsigned char *kdata, struct iovec *iov,
                                int offset, int len);
extern int csum_partial_copy_fromiovecend(unsigned char *kdata,
                                          struct iovec *iov,
                                          int offset,
                                          unsigned int len, int *csump);

extern int verify_iovec(struct msghdr *m, struct iovec *iov, char *address, int mode);
extern int memcpy_toiovec(struct iovec *v, unsigned char *kdata, int len);
extern int move_addr_to_user(void *kaddr, int klen, void *uaddr, int *ulen);
extern int move_addr_to_kernel(void *uaddr, int ulen, void *kaddr);
extern int put_cmsg(struct msghdr*, int level, int type, int len, void *data);
# 24 "include/linux/if.h" 2



# 1 "include/linux/hdlc/ioctl.h" 1



typedef struct {
        unsigned int clock_rate;
        unsigned int clock_type;
        unsigned short loopback;
} sync_serial_settings;

typedef struct {
        unsigned int clock_rate;
        unsigned int clock_type;
        unsigned short loopback;
        unsigned int slot_map;
} te1_settings;

typedef struct {
        unsigned short encoding;
        unsigned short parity;
} raw_hdlc_proto;

typedef struct {
        unsigned int t391;
        unsigned int t392;
        unsigned int n391;
        unsigned int n392;
        unsigned int n393;
        unsigned short lmi;
        unsigned short dce;
} fr_proto;

typedef struct {
        unsigned int dlci;
} fr_proto_pvc;

typedef struct {
        unsigned int dlci;
        char master[16];
}fr_proto_pvc_info;

typedef struct {
    unsigned int interval;
    unsigned int timeout;
} cisco_proto;
# 28 "include/linux/if.h" 2
# 94 "include/linux/if.h"
struct ifmap
{
        unsigned long mem_start;
        unsigned long mem_end;
        unsigned short base_addr;
        unsigned char irq;
        unsigned char dma;
        unsigned char port;

};

struct if_settings
{
        unsigned int type;
        unsigned int size;
        union {

                raw_hdlc_proto *raw_hdlc;
                cisco_proto *cisco;
                fr_proto *fr;
                fr_proto_pvc *fr_pvc;
                fr_proto_pvc_info *fr_pvc_info;


                sync_serial_settings *sync;
                te1_settings *te1;
        } ifs_ifsu;
};
# 130 "include/linux/if.h"
struct ifreq
{

        union
        {
                char ifrn_name[16];
        } ifr_ifrn;

        union {
                struct sockaddr ifru_addr;
                struct sockaddr ifru_dstaddr;
                struct sockaddr ifru_broadaddr;
                struct sockaddr ifru_netmask;
                struct sockaddr ifru_hwaddr;
                short ifru_flags;
                int ifru_ivalue;
                int ifru_mtu;
                struct ifmap ifru_map;
                char ifru_slave[16];
                char ifru_newname[16];
                void * ifru_data;
                struct if_settings ifru_settings;
        } ifr_ifru;
};
# 180 "include/linux/if.h"
struct ifconf
{
        int ifc_len;
        union
        {
                char *ifcu_buf;
                struct ifreq *ifcu_req;
        } ifc_ifcu;
};
# 13 "include/linux/mii.h" 2
# 139 "include/linux/mii.h"
struct mii_if_info {
        int phy_id;
        int advertising;
        int phy_id_mask;
        int reg_num_mask;

        unsigned int full_duplex : 1;
        unsigned int force_media : 1;
        unsigned int supports_gmii : 1;

        struct net_device *dev;
        int (*mdio_read) (struct net_device *dev, int phy_id, int location);
        void (*mdio_write) (struct net_device *dev, int phy_id, int location, int val);
};

struct ethtool_cmd;
struct mii_ioctl_data;

extern int mii_link_ok (struct mii_if_info *mii);
extern int mii_nway_restart (struct mii_if_info *mii);
extern int mii_ethtool_gset(struct mii_if_info *mii, struct ethtool_cmd *ecmd);
extern int mii_ethtool_sset(struct mii_if_info *mii, struct ethtool_cmd *ecmd);
extern void mii_check_link (struct mii_if_info *mii);
extern unsigned int mii_check_media (struct mii_if_info *mii,
                                     unsigned int ok_to_print,
                                     unsigned int init_media);
extern int generic_mii_ioctl(struct mii_if_info *mii_if,
                             struct mii_ioctl_data *mii_data, int cmd,
                             unsigned int *duplex_changed);




struct mii_ioctl_data {
        u16 phy_id;
        u16 reg_num;
        u16 val_in;
        u16 val_out;
};


static inline __attribute__((always_inline)) struct mii_ioctl_data *if_mii(struct ifreq *rq)
{
        return (struct mii_ioctl_data *) &rq->ifr_ifru;
}
# 200 "include/linux/mii.h"
static inline __attribute__((always_inline)) unsigned int mii_nway_result (unsigned int negotiated)
{
        unsigned int ret;

        if (negotiated & 0x0100)
                ret = 0x0100;
        else if (negotiated & 0x0200)
                ret = 0x0200;
        else if (negotiated & 0x0080)
                ret = 0x0080;
        else if (negotiated & 0x0040)
                ret = 0x0040;
        else
                ret = 0x0020;

        return ret;
}
# 227 "include/linux/mii.h"
static inline __attribute__((always_inline)) unsigned int mii_duplex (unsigned int duplex_lock,
                                       unsigned int negotiated)
{
        if (duplex_lock)
                return 1;
        if (mii_nway_result(negotiated) & (0x0040 | 0x0100))
                return 1;
        return 0;
}
# 122 "drivers/net/yellowfin.c" 2
# 1 "include/linux/netdevice.h" 1
# 29 "include/linux/netdevice.h"
# 1 "include/linux/if_ether.h" 1
# 100 "include/linux/if_ether.h"
struct ethhdr {
        unsigned char h_dest[6];
        unsigned char h_source[6];
        unsigned short h_proto;
} __attribute__((packed));


# 1 "include/linux/skbuff.h" 1
# 27 "include/linux/skbuff.h"
# 1 "include/linux/highmem.h" 1







# 1 "include/asm/cacheflush.h" 1
# 26 "include/asm/cacheflush.h"
void global_flush_tlb(void);
int change_page_attr(struct page *page, int numpages, pgprot_t prot);
# 9 "include/linux/highmem.h" 2



# 1 "include/asm/highmem.h" 1
# 27 "include/asm/highmem.h"
# 1 "include/asm/tlbflush.h" 1
# 40 "include/asm/tlbflush.h"
extern unsigned long pgkern_mask;
# 115 "include/asm/tlbflush.h"
extern void flush_tlb_all(void);
extern void flush_tlb_current_task(void);
extern void flush_tlb_mm(struct mm_struct *);
extern void flush_tlb_page(struct vm_area_struct *, unsigned long);



static inline __attribute__((always_inline)) void flush_tlb_range(struct vm_area_struct * vma, unsigned long start, unsigned long end)
{
        flush_tlb_mm(vma->vm_mm);
}




struct tlb_state
{
        struct mm_struct *active_mm;
        int state;
        char __cacheline_padding[(1 << (4))-8];
};
extern __typeof__(struct tlb_state) per_cpu__cpu_tlbstate;






static inline __attribute__((always_inline)) void flush_tlb_pgtables(struct mm_struct *mm,
                                      unsigned long start, unsigned long end)
{

}
# 28 "include/asm/highmem.h" 2


extern unsigned long highstart_pfn, highend_pfn;

extern pte_t *kmap_pte;
extern pgprot_t kmap_prot;
extern pte_t *pkmap_page_table;
# 66 "include/asm/highmem.h"
extern void * kmap_high(struct page *page) __attribute__((regparm(3)));
extern void kunmap_high(struct page *page) __attribute__((regparm(3)));

void *kmap(struct page *page);
void kunmap(struct page *page);
void *kmap_atomic(struct page *page, enum km_type type);
void kunmap_atomic(void *kvaddr, enum km_type type);
void *kmap_atomic_pfn(unsigned long pfn, enum km_type type);
struct page *kmap_atomic_to_page(void *ptr);
# 13 "include/linux/highmem.h" 2


unsigned int nr_free_highpages(void);
# 37 "include/linux/highmem.h"
static inline __attribute__((always_inline)) void clear_user_highpage(struct page *page, unsigned long vaddr)
{
        void *addr = kmap_atomic(page, KM_USER0);
        (__builtin_constant_p(0) ? (__builtin_constant_p(((1UL << 12))) ? __constant_c_and_count_memset((((void *)(addr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12)))) : __constant_c_memset((((void *)(addr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12))))) : (__builtin_constant_p(((1UL << 12))) ? __memset_generic(((((void *)(addr)))),(((0))),((((1UL << 12))))) : __memset_generic((((void *)(addr))),((0)),(((1UL << 12))))));
        kunmap_atomic(addr, KM_USER0);

        __asm__ __volatile__ ("": : :"memory");
}
# 59 "include/linux/highmem.h"
static inline __attribute__((always_inline)) void clear_highpage(struct page *page)
{
        void *kaddr = kmap_atomic(page, KM_USER0);
        (__builtin_constant_p(0) ? (__builtin_constant_p(((1UL << 12))) ? __constant_c_and_count_memset((((void *)(kaddr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12)))) : __constant_c_memset((((void *)(kaddr))),((0x01010101UL*(unsigned char)(0))),(((1UL << 12))))) : (__builtin_constant_p(((1UL << 12))) ? __memset_generic(((((void *)(kaddr)))),(((0))),((((1UL << 12))))) : __memset_generic((((void *)(kaddr))),((0)),(((1UL << 12))))));
        kunmap_atomic(kaddr, KM_USER0);
}




static inline __attribute__((always_inline)) void memclear_highpage_flush(struct page *page, unsigned int offset, unsigned int size)
{
        void *kaddr;

        do { if (__builtin_expect(!!((offset + size > (1UL << 12))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (73), "i" ("include/linux/highmem.h")); } while(0);

        kaddr = kmap_atomic(page, KM_USER0);
        (__builtin_constant_p(0) ? (__builtin_constant_p((size)) ? __constant_c_and_count_memset((((char *)kaddr + offset)),((0x01010101UL*(unsigned char)(0))),((size))) : __constant_c_memset((((char *)kaddr + offset)),((0x01010101UL*(unsigned char)(0))),((size)))) : (__builtin_constant_p((size)) ? __memset_generic(((((char *)kaddr + offset))),(((0))),(((size)))) : __memset_generic((((char *)kaddr + offset)),((0)),((size)))));
        do { } while (0);
        kunmap_atomic(kaddr, KM_USER0);
}

static inline __attribute__((always_inline)) void copy_user_highpage(struct page *to, struct page *from, unsigned long vaddr)
{
        char *vfrom, *vto;

        vfrom = kmap_atomic(from, KM_USER0);
        vto = kmap_atomic(to, KM_USER1);
        (__builtin_constant_p((1UL << 12)) ? __constant_memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))) : __memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))));
        kunmap_atomic(vfrom, KM_USER0);
        kunmap_atomic(vto, KM_USER1);

        __asm__ __volatile__ ("": : :"memory");
}

static inline __attribute__((always_inline)) void copy_highpage(struct page *to, struct page *from)
{
        char *vfrom, *vto;

        vfrom = kmap_atomic(from, KM_USER0);
        vto = kmap_atomic(to, KM_USER1);
        (__builtin_constant_p((1UL << 12)) ? __constant_memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))) : __memcpy(((void *)(vto)),((void *)(vfrom)),((1UL << 12))));
        kunmap_atomic(vfrom, KM_USER0);
        kunmap_atomic(vto, KM_USER1);
}
# 28 "include/linux/skbuff.h" 2
# 1 "include/linux/poll.h" 1



# 1 "include/asm/poll.h" 1
# 20 "include/asm/poll.h"
struct pollfd {
        int fd;
        short events;
        short revents;
};
# 5 "include/linux/poll.h" 2







# 1 "include/asm/uaccess.h" 1
# 99 "include/asm/uaccess.h"
struct exception_table_entry
{
        unsigned long insn, fixup;
};

extern int fixup_exception(struct pt_regs *regs);
# 121 "include/asm/uaccess.h"
extern void __get_user_1(void);
extern void __get_user_2(void);
extern void __get_user_4(void);
# 163 "include/asm/uaccess.h"
extern void __put_user_bad(void);





extern void __put_user_1(void);
extern void __put_user_2(void);
extern void __put_user_4(void);
extern void __put_user_8(void);
# 324 "include/asm/uaccess.h"
struct __large_struct { unsigned long buf[100]; };
# 357 "include/asm/uaccess.h"
extern long __get_user_bad(void);
# 388 "include/asm/uaccess.h"
unsigned long __copy_to_user_ll(void *to,
                                const void *from, unsigned long n);
unsigned long __copy_from_user_ll(void *to,
                                const void *from, unsigned long n);
# 414 "include/asm/uaccess.h"
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
# 459 "include/asm/uaccess.h"
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
# 511 "include/asm/uaccess.h"
long strnlen_user(const char *str, long n);
unsigned long clear_user(void *mem, unsigned long len);
unsigned long __clear_user(void *mem, unsigned long len);
# 13 "include/linux/poll.h" 2

struct poll_table_struct;




typedef void (*poll_queue_proc)(struct file *, wait_queue_head_t *, struct poll_table_struct *);

typedef struct poll_table_struct {
        poll_queue_proc qproc;
} poll_table;

static inline __attribute__((always_inline)) void poll_wait(struct file * filp, wait_queue_head_t * wait_address, poll_table *p)
{
        if (p && wait_address)
                p->qproc(filp, wait_address, p);
}

static inline __attribute__((always_inline)) void init_poll_funcptr(poll_table *pt, poll_queue_proc qproc)
{
        pt->qproc = qproc;
}




struct poll_wqueues {
        poll_table pt;
        struct poll_table_page * table;
        int error;
};

extern void poll_initwait(struct poll_wqueues *pwq);
extern void poll_freewait(struct poll_wqueues *pwq);





typedef struct {
        unsigned long *in, *out, *ex;
        unsigned long *res_in, *res_out, *res_ex;
} fd_set_bits;
# 70 "include/linux/poll.h"
static inline __attribute__((always_inline))
int get_fd_set(unsigned long nr, void *ufdset, unsigned long *fdset)
{
        nr = ((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long));
        if (ufdset)
                return copy_from_user(fdset, ufdset, nr) ? -14 : 0;

        (__builtin_constant_p(0) ? (__builtin_constant_p((nr)) ? __constant_c_and_count_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((nr))) : __constant_c_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((nr)))) : (__builtin_constant_p((nr)) ? __memset_generic((((fdset))),(((0))),(((nr)))) : __memset_generic(((fdset)),((0)),((nr)))));
        return 0;
}

static inline __attribute__((always_inline)) unsigned long
set_fd_set(unsigned long nr, void *ufdset, unsigned long *fdset)
{
        if (ufdset)
                return __copy_to_user(ufdset, fdset, ((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)));
        return 0;
}

static inline __attribute__((always_inline))
void zero_fd_set(unsigned long nr, unsigned long *fdset)
{
        (__builtin_constant_p(0) ? (__builtin_constant_p((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))) ? __constant_c_and_count_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long))))) : __constant_c_memset(((fdset)),((0x01010101UL*(unsigned char)(0))),((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))))) : (__builtin_constant_p((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))) ? __memset_generic((((fdset))),(((0))),(((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))))) : __memset_generic(((fdset)),((0)),((((((nr)+(8*sizeof(long))-1)/(8*sizeof(long)))*sizeof(long)))))));
}

extern int do_select(int n, fd_set_bits *fds, long *timeout);
# 29 "include/linux/skbuff.h" 2
# 1 "include/linux/net.h" 1
# 26 "include/linux/net.h"
struct poll_table_struct;
struct inode;
# 49 "include/linux/net.h"
typedef enum {
        SS_FREE = 0,
        SS_UNCONNECTED,
        SS_CONNECTING,
        SS_CONNECTED,
        SS_DISCONNECTING
} socket_state;
# 81 "include/linux/net.h"
enum sock_type {
        SOCK_STREAM = 1,
        SOCK_DGRAM = 2,
        SOCK_RAW = 3,
        SOCK_RDM = 4,
        SOCK_SEQPACKET = 5,
        SOCK_DCCP = 6,
        SOCK_PACKET = 10,
};
# 106 "include/linux/net.h"
struct socket {
        socket_state state;
        unsigned long flags;
        struct proto_ops *ops;
        struct fasync_struct *fasync_list;
        struct file *file;
        struct sock *sk;
        wait_queue_head_t wait;
        short type;
};

struct vm_area_struct;
struct page;
struct kiocb;
struct sockaddr;
struct msghdr;
struct module;

struct proto_ops {
        int family;
        struct module *owner;
        int (*release) (struct socket *sock);
        int (*bind) (struct socket *sock,
                                      struct sockaddr *myaddr,
                                      int sockaddr_len);
        int (*connect) (struct socket *sock,
                                      struct sockaddr *vaddr,
                                      int sockaddr_len, int flags);
        int (*socketpair)(struct socket *sock1,
                                      struct socket *sock2);
        int (*accept) (struct socket *sock,
                                      struct socket *newsock, int flags);
        int (*getname) (struct socket *sock,
                                      struct sockaddr *addr,
                                      int *sockaddr_len, int peer);
        unsigned int (*poll) (struct file *file, struct socket *sock,
                                      struct poll_table_struct *wait);
        int (*ioctl) (struct socket *sock, unsigned int cmd,
                                      unsigned long arg);
        int (*listen) (struct socket *sock, int len);
        int (*shutdown) (struct socket *sock, int flags);
        int (*setsockopt)(struct socket *sock, int level,
                                      int optname, char *optval, int optlen);
        int (*getsockopt)(struct socket *sock, int level,
                                      int optname, char *optval, int *optlen);
        int (*sendmsg) (struct kiocb *iocb, struct socket *sock,
                                      struct msghdr *m, size_t total_len);
        int (*recvmsg) (struct kiocb *iocb, struct socket *sock,
                                      struct msghdr *m, size_t total_len,
                                      int flags);
        int (*mmap) (struct file *file, struct socket *sock,
                                      struct vm_area_struct * vma);
        ssize_t (*sendpage) (struct socket *sock, struct page *page,
                                      int offset, size_t size, int flags);
};

struct net_proto_family {
        int family;
        int (*create)(struct socket *sock, int protocol);


        short authentication;
        short encryption;
        short encrypt_net;
        struct module *owner;
};

struct iovec;
struct kvec;

extern int sock_wake_async(struct socket *sk, int how, int band);
extern int sock_register(struct net_proto_family *fam);
extern int sock_unregister(int family);
extern int sock_create(int family, int type, int proto,
                                 struct socket **res);
extern int sock_create_kern(int family, int type, int proto,
                                      struct socket **res);
extern int sock_create_lite(int family, int type, int proto,
                                      struct socket **res);
extern void sock_release(struct socket *sock);
extern int sock_sendmsg(struct socket *sock, struct msghdr *msg,
                                  size_t len);
extern int sock_recvmsg(struct socket *sock, struct msghdr *msg,
                                  size_t size, int flags);
extern int sock_map_fd(struct socket *sock);
extern struct socket *sockfd_lookup(int fd, int *err);

extern int net_ratelimit(void);
extern unsigned long net_random(void);
extern void net_srandom(unsigned long);
extern void net_random_init(void);

extern int kernel_sendmsg(struct socket *sock, struct msghdr *msg,
                                    struct kvec *vec, size_t num, size_t len);
extern int kernel_recvmsg(struct socket *sock, struct msghdr *msg,
                                    struct kvec *vec, size_t num,
                                    size_t len, int flags);
# 290 "include/linux/net.h"
# 1 "include/linux/sysctl.h" 1
# 26 "include/linux/sysctl.h"
struct file;






struct __sysctl_args {
        int *name;
        int nlen;
        void *oldval;
        size_t *oldlenp;
        void *newval;
        size_t newlen;
        unsigned long __unused[4];
};
# 53 "include/linux/sysctl.h"
enum
{
        CTL_KERN=1,
        CTL_VM=2,
        CTL_NET=3,
        CTL_PROC=4,
        CTL_FS=5,
        CTL_DEBUG=6,
        CTL_DEV=7,
        CTL_BUS=8,
        CTL_ABI=9,
        CTL_CPU=10
};


enum
{
        CTL_BUS_ISA=1
};


enum
{
        INOTIFY_MAX_USER_INSTANCES=1,
        INOTIFY_MAX_USER_WATCHES=2,
        INOTIFY_MAX_QUEUED_EVENTS=3
};


enum
{
        KERN_OSTYPE=1,
        KERN_OSRELEASE=2,
        KERN_OSREV=3,
        KERN_VERSION=4,
        KERN_SECUREMASK=5,
        KERN_PROF=6,
        KERN_NODENAME=7,
        KERN_DOMAINNAME=8,

        KERN_CAP_BSET=14,
        KERN_PANIC=15,
        KERN_REALROOTDEV=16,

        KERN_SPARC_REBOOT=21,
        KERN_CTLALTDEL=22,
        KERN_PRINTK=23,
        KERN_NAMETRANS=24,
        KERN_PPC_HTABRECLAIM=25,
        KERN_PPC_ZEROPAGED=26,
        KERN_PPC_POWERSAVE_NAP=27,
        KERN_MODPROBE=28,
        KERN_SG_BIG_BUFF=29,
        KERN_ACCT=30,
        KERN_PPC_L2CR=31,

        KERN_RTSIGNR=32,
        KERN_RTSIGMAX=33,

        KERN_SHMMAX=34,
        KERN_MSGMAX=35,
        KERN_MSGMNB=36,
        KERN_MSGPOOL=37,
        KERN_SYSRQ=38,
        KERN_MAX_THREADS=39,
        KERN_RANDOM=40,
        KERN_SHMALL=41,
        KERN_MSGMNI=42,
        KERN_SEM=43,
        KERN_SPARC_STOP_A=44,
        KERN_SHMMNI=45,
        KERN_OVERFLOWUID=46,
        KERN_OVERFLOWGID=47,
        KERN_SHMPATH=48,
        KERN_HOTPLUG=49,
        KERN_IEEE_EMULATION_WARNINGS=50,
        KERN_S390_USER_DEBUG_LOGGING=51,
        KERN_CORE_USES_PID=52,
        KERN_TAINTED=53,
        KERN_CADPID=54,
        KERN_PIDMAX=55,
        KERN_CORE_PATTERN=56,
        KERN_PANIC_ON_OOPS=57,
        KERN_HPPA_PWRSW=58,
        KERN_HPPA_UNALIGNED=59,
        KERN_PRINTK_RATELIMIT=60,
        KERN_PRINTK_RATELIMIT_BURST=61,
        KERN_PTY=62,
        KERN_NGROUPS_MAX=63,
        KERN_SPARC_SCONS_PWROFF=64,
        KERN_HZ_TIMER=65,
        KERN_UNKNOWN_NMI_PANIC=66,
        KERN_BOOTLOADER_TYPE=67,
        KERN_RANDOMIZE=68,
        KERN_SETUID_DUMPABLE=69,
        KERN_SPIN_RETRY=70,
};



enum
{
        VM_UNUSED1=1,
        VM_UNUSED2=2,
        VM_UNUSED3=3,
        VM_UNUSED4=4,
        VM_OVERCOMMIT_MEMORY=5,
        VM_UNUSED5=6,
        VM_UNUSED7=7,
        VM_UNUSED8=8,
        VM_UNUSED9=9,
        VM_PAGE_CLUSTER=10,
        VM_DIRTY_BACKGROUND=11,
        VM_DIRTY_RATIO=12,
        VM_DIRTY_WB_CS=13,
        VM_DIRTY_EXPIRE_CS=14,
        VM_NR_PDFLUSH_THREADS=15,
        VM_OVERCOMMIT_RATIO=16,
        VM_PAGEBUF=17,
        VM_HUGETLB_PAGES=18,
        VM_SWAPPINESS=19,
        VM_LOWMEM_RESERVE_RATIO=20,
        VM_MIN_FREE_KBYTES=21,
        VM_MAX_MAP_COUNT=22,
        VM_LAPTOP_MODE=23,
        VM_BLOCK_DUMP=24,
        VM_HUGETLB_GROUP=25,
        VM_VFS_CACHE_PRESSURE=26,
        VM_LEGACY_VA_LAYOUT=27,
        VM_SWAP_TOKEN_TIMEOUT=28,
};



enum
{
        NET_CORE=1,
        NET_ETHER=2,
        NET_802=3,
        NET_UNIX=4,
        NET_IPV4=5,
        NET_IPX=6,
        NET_ATALK=7,
        NET_NETROM=8,
        NET_AX25=9,
        NET_BRIDGE=10,
        NET_ROSE=11,
        NET_IPV6=12,
        NET_X25=13,
        NET_TR=14,
        NET_DECNET=15,
        NET_ECONET=16,
        NET_SCTP=17,
        NET_LLC=18,
};


enum
{
        RANDOM_POOLSIZE=1,
        RANDOM_ENTROPY_COUNT=2,
        RANDOM_READ_THRESH=3,
        RANDOM_WRITE_THRESH=4,
        RANDOM_BOOT_ID=5,
        RANDOM_UUID=6
};


enum
{
        PTY_MAX=1,
        PTY_NR=2
};


enum
{
        BUS_ISA_MEM_BASE=1,
        BUS_ISA_PORT_BASE=2,
        BUS_ISA_PORT_SHIFT=3
};


enum
{
        NET_CORE_WMEM_MAX=1,
        NET_CORE_RMEM_MAX=2,
        NET_CORE_WMEM_DEFAULT=3,
        NET_CORE_RMEM_DEFAULT=4,

        NET_CORE_MAX_BACKLOG=6,
        NET_CORE_FASTROUTE=7,
        NET_CORE_MSG_COST=8,
        NET_CORE_MSG_BURST=9,
        NET_CORE_OPTMEM_MAX=10,
        NET_CORE_HOT_LIST_LENGTH=11,
        NET_CORE_DIVERT_VERSION=12,
        NET_CORE_NO_CONG_THRESH=13,
        NET_CORE_NO_CONG=14,
        NET_CORE_LO_CONG=15,
        NET_CORE_MOD_CONG=16,
        NET_CORE_DEV_WEIGHT=17,
        NET_CORE_SOMAXCONN=18,
        NET_CORE_BUDGET=19,
};







enum
{
        NET_UNIX_DESTROY_DELAY=1,
        NET_UNIX_DELETE_DELAY=2,
        NET_UNIX_MAX_DGRAM_QLEN=3,
};


enum
{

        NET_IPV4_FORWARD=8,
        NET_IPV4_DYNADDR=9,

        NET_IPV4_CONF=16,
        NET_IPV4_NEIGH=17,
        NET_IPV4_ROUTE=18,
        NET_IPV4_FIB_HASH=19,
        NET_IPV4_NETFILTER=20,

        NET_IPV4_TCP_TIMESTAMPS=33,
        NET_IPV4_TCP_WINDOW_SCALING=34,
        NET_IPV4_TCP_SACK=35,
        NET_IPV4_TCP_RETRANS_COLLAPSE=36,
        NET_IPV4_DEFAULT_TTL=37,
        NET_IPV4_AUTOCONFIG=38,
        NET_IPV4_NO_PMTU_DISC=39,
        NET_IPV4_TCP_SYN_RETRIES=40,
        NET_IPV4_IPFRAG_HIGH_THRESH=41,
        NET_IPV4_IPFRAG_LOW_THRESH=42,
        NET_IPV4_IPFRAG_TIME=43,
        NET_IPV4_TCP_MAX_KA_PROBES=44,
        NET_IPV4_TCP_KEEPALIVE_TIME=45,
        NET_IPV4_TCP_KEEPALIVE_PROBES=46,
        NET_IPV4_TCP_RETRIES1=47,
        NET_IPV4_TCP_RETRIES2=48,
        NET_IPV4_TCP_FIN_TIMEOUT=49,
        NET_IPV4_IP_MASQ_DEBUG=50,
        NET_TCP_SYNCOOKIES=51,
        NET_TCP_STDURG=52,
        NET_TCP_RFC1337=53,
        NET_TCP_SYN_TAILDROP=54,
        NET_TCP_MAX_SYN_BACKLOG=55,
        NET_IPV4_LOCAL_PORT_RANGE=56,
        NET_IPV4_ICMP_ECHO_IGNORE_ALL=57,
        NET_IPV4_ICMP_ECHO_IGNORE_BROADCASTS=58,
        NET_IPV4_ICMP_SOURCEQUENCH_RATE=59,
        NET_IPV4_ICMP_DESTUNREACH_RATE=60,
        NET_IPV4_ICMP_TIMEEXCEED_RATE=61,
        NET_IPV4_ICMP_PARAMPROB_RATE=62,
        NET_IPV4_ICMP_ECHOREPLY_RATE=63,
        NET_IPV4_ICMP_IGNORE_BOGUS_ERROR_RESPONSES=64,
        NET_IPV4_IGMP_MAX_MEMBERSHIPS=65,
        NET_TCP_TW_RECYCLE=66,
        NET_IPV4_ALWAYS_DEFRAG=67,
        NET_IPV4_TCP_KEEPALIVE_INTVL=68,
        NET_IPV4_INET_PEER_THRESHOLD=69,
        NET_IPV4_INET_PEER_MINTTL=70,
        NET_IPV4_INET_PEER_MAXTTL=71,
        NET_IPV4_INET_PEER_GC_MINTIME=72,
        NET_IPV4_INET_PEER_GC_MAXTIME=73,
        NET_TCP_ORPHAN_RETRIES=74,
        NET_TCP_ABORT_ON_OVERFLOW=75,
        NET_TCP_SYNACK_RETRIES=76,
        NET_TCP_MAX_ORPHANS=77,
        NET_TCP_MAX_TW_BUCKETS=78,
        NET_TCP_FACK=79,
        NET_TCP_REORDERING=80,
        NET_TCP_ECN=81,
        NET_TCP_DSACK=82,
        NET_TCP_MEM=83,
        NET_TCP_WMEM=84,
        NET_TCP_RMEM=85,
        NET_TCP_APP_WIN=86,
        NET_TCP_ADV_WIN_SCALE=87,
        NET_IPV4_NONLOCAL_BIND=88,
        NET_IPV4_ICMP_RATELIMIT=89,
        NET_IPV4_ICMP_RATEMASK=90,
        NET_TCP_TW_REUSE=91,
        NET_TCP_FRTO=92,
        NET_TCP_LOW_LATENCY=93,
        NET_IPV4_IPFRAG_SECRET_INTERVAL=94,
        NET_IPV4_IGMP_MAX_MSF=96,
        NET_TCP_NO_METRICS_SAVE=97,
        NET_TCP_DEFAULT_WIN_SCALE=105,
        NET_TCP_MODERATE_RCVBUF=106,
        NET_TCP_TSO_WIN_DIVISOR=107,
        NET_TCP_BIC_BETA=108,
        NET_IPV4_ICMP_ERRORS_USE_INBOUND_IFADDR=109,
        NET_TCP_CONG_CONTROL=110,
};

enum {
        NET_IPV4_ROUTE_FLUSH=1,
        NET_IPV4_ROUTE_MIN_DELAY=2,
        NET_IPV4_ROUTE_MAX_DELAY=3,
        NET_IPV4_ROUTE_GC_THRESH=4,
        NET_IPV4_ROUTE_MAX_SIZE=5,
        NET_IPV4_ROUTE_GC_MIN_INTERVAL=6,
        NET_IPV4_ROUTE_GC_TIMEOUT=7,
        NET_IPV4_ROUTE_GC_INTERVAL=8,
        NET_IPV4_ROUTE_REDIRECT_LOAD=9,
        NET_IPV4_ROUTE_REDIRECT_NUMBER=10,
        NET_IPV4_ROUTE_REDIRECT_SILENCE=11,
        NET_IPV4_ROUTE_ERROR_COST=12,
        NET_IPV4_ROUTE_ERROR_BURST=13,
        NET_IPV4_ROUTE_GC_ELASTICITY=14,
        NET_IPV4_ROUTE_MTU_EXPIRES=15,
        NET_IPV4_ROUTE_MIN_PMTU=16,
        NET_IPV4_ROUTE_MIN_ADVMSS=17,
        NET_IPV4_ROUTE_SECRET_INTERVAL=18,
        NET_IPV4_ROUTE_GC_MIN_INTERVAL_MS=19,
};

enum
{
        NET_PROTO_CONF_ALL=-2,
        NET_PROTO_CONF_DEFAULT=-3


};

enum
{
        NET_IPV4_CONF_FORWARDING=1,
        NET_IPV4_CONF_MC_FORWARDING=2,
        NET_IPV4_CONF_PROXY_ARP=3,
        NET_IPV4_CONF_ACCEPT_REDIRECTS=4,
        NET_IPV4_CONF_SECURE_REDIRECTS=5,
        NET_IPV4_CONF_SEND_REDIRECTS=6,
        NET_IPV4_CONF_SHARED_MEDIA=7,
        NET_IPV4_CONF_RP_FILTER=8,
        NET_IPV4_CONF_ACCEPT_SOURCE_ROUTE=9,
        NET_IPV4_CONF_BOOTP_RELAY=10,
        NET_IPV4_CONF_LOG_MARTIANS=11,
        NET_IPV4_CONF_TAG=12,
        NET_IPV4_CONF_ARPFILTER=13,
        NET_IPV4_CONF_MEDIUM_ID=14,
        NET_IPV4_CONF_NOXFRM=15,
        NET_IPV4_CONF_NOPOLICY=16,
        NET_IPV4_CONF_FORCE_IGMP_VERSION=17,
        NET_IPV4_CONF_ARP_ANNOUNCE=18,
        NET_IPV4_CONF_ARP_IGNORE=19,
        NET_IPV4_CONF_PROMOTE_SECONDARIES=20,
        __NET_IPV4_CONF_MAX
};


enum
{
        NET_IPV4_NF_CONNTRACK_MAX=1,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_SYN_SENT=2,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_SYN_RECV=3,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_ESTABLISHED=4,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_FIN_WAIT=5,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_CLOSE_WAIT=6,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_LAST_ACK=7,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_TIME_WAIT=8,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_CLOSE=9,
        NET_IPV4_NF_CONNTRACK_UDP_TIMEOUT=10,
        NET_IPV4_NF_CONNTRACK_UDP_TIMEOUT_STREAM=11,
        NET_IPV4_NF_CONNTRACK_ICMP_TIMEOUT=12,
        NET_IPV4_NF_CONNTRACK_GENERIC_TIMEOUT=13,
        NET_IPV4_NF_CONNTRACK_BUCKETS=14,
        NET_IPV4_NF_CONNTRACK_LOG_INVALID=15,
        NET_IPV4_NF_CONNTRACK_TCP_TIMEOUT_MAX_RETRANS=16,
        NET_IPV4_NF_CONNTRACK_TCP_LOOSE=17,
        NET_IPV4_NF_CONNTRACK_TCP_BE_LIBERAL=18,
        NET_IPV4_NF_CONNTRACK_TCP_MAX_RETRANS=19,
        NET_IPV4_NF_CONNTRACK_SCTP_TIMEOUT_CLOSED=20,
        NET_IPV4_NF_CONNTRACK_SCTP_TIMEOUT_COOKIE_WAIT=21,
        NET_IPV4_NF_CONNTRACK_SCTP_TIMEOUT_COOKIE_ECHOED=22,
        NET_IPV4_NF_CONNTRACK_SCTP_TIMEOUT_ESTABLISHED=23,
        NET_IPV4_NF_CONNTRACK_SCTP_TIMEOUT_SHUTDOWN_SENT=24,
        NET_IPV4_NF_CONNTRACK_SCTP_TIMEOUT_SHUTDOWN_RECD=25,
        NET_IPV4_NF_CONNTRACK_SCTP_TIMEOUT_SHUTDOWN_ACK_SENT=26,
        NET_IPV4_NF_CONNTRACK_COUNT=27,
};


enum {
        NET_IPV6_CONF=16,
        NET_IPV6_NEIGH=17,
        NET_IPV6_ROUTE=18,
        NET_IPV6_ICMP=19,
        NET_IPV6_BINDV6ONLY=20,
        NET_IPV6_IP6FRAG_HIGH_THRESH=21,
        NET_IPV6_IP6FRAG_LOW_THRESH=22,
        NET_IPV6_IP6FRAG_TIME=23,
        NET_IPV6_IP6FRAG_SECRET_INTERVAL=24,
        NET_IPV6_MLD_MAX_MSF=25,
};

enum {
        NET_IPV6_ROUTE_FLUSH=1,
        NET_IPV6_ROUTE_GC_THRESH=2,
        NET_IPV6_ROUTE_MAX_SIZE=3,
        NET_IPV6_ROUTE_GC_MIN_INTERVAL=4,
        NET_IPV6_ROUTE_GC_TIMEOUT=5,
        NET_IPV6_ROUTE_GC_INTERVAL=6,
        NET_IPV6_ROUTE_GC_ELASTICITY=7,
        NET_IPV6_ROUTE_MTU_EXPIRES=8,
        NET_IPV6_ROUTE_MIN_ADVMSS=9,
        NET_IPV6_ROUTE_GC_MIN_INTERVAL_MS=10
};

enum {
        NET_IPV6_FORWARDING=1,
        NET_IPV6_HOP_LIMIT=2,
        NET_IPV6_MTU=3,
        NET_IPV6_ACCEPT_RA=4,
        NET_IPV6_ACCEPT_REDIRECTS=5,
        NET_IPV6_AUTOCONF=6,
        NET_IPV6_DAD_TRANSMITS=7,
        NET_IPV6_RTR_SOLICITS=8,
        NET_IPV6_RTR_SOLICIT_INTERVAL=9,
        NET_IPV6_RTR_SOLICIT_DELAY=10,
        NET_IPV6_USE_TEMPADDR=11,
        NET_IPV6_TEMP_VALID_LFT=12,
        NET_IPV6_TEMP_PREFERED_LFT=13,
        NET_IPV6_REGEN_MAX_RETRY=14,
        NET_IPV6_MAX_DESYNC_FACTOR=15,
        NET_IPV6_MAX_ADDRESSES=16,
        NET_IPV6_FORCE_MLD_VERSION=17,
        __NET_IPV6_MAX
};


enum {
        NET_IPV6_ICMP_RATELIMIT=1
};


enum {
        NET_NEIGH_MCAST_SOLICIT=1,
        NET_NEIGH_UCAST_SOLICIT=2,
        NET_NEIGH_APP_SOLICIT=3,
        NET_NEIGH_RETRANS_TIME=4,
        NET_NEIGH_REACHABLE_TIME=5,
        NET_NEIGH_DELAY_PROBE_TIME=6,
        NET_NEIGH_GC_STALE_TIME=7,
        NET_NEIGH_UNRES_QLEN=8,
        NET_NEIGH_PROXY_QLEN=9,
        NET_NEIGH_ANYCAST_DELAY=10,
        NET_NEIGH_PROXY_DELAY=11,
        NET_NEIGH_LOCKTIME=12,
        NET_NEIGH_GC_INTERVAL=13,
        NET_NEIGH_GC_THRESH1=14,
        NET_NEIGH_GC_THRESH2=15,
        NET_NEIGH_GC_THRESH3=16,
        NET_NEIGH_RETRANS_TIME_MS=17,
        NET_NEIGH_REACHABLE_TIME_MS=18,
        __NET_NEIGH_MAX
};


enum {
        NET_IPX_PPROP_BROADCASTING=1,
        NET_IPX_FORWARDING=2
};


enum {
        NET_LLC2=1,
        NET_LLC_STATION=2,
};


enum {
        NET_LLC2_TIMEOUT=1,
};


enum {
        NET_LLC_STATION_ACK_TIMEOUT=1,
};


enum {
        NET_LLC2_ACK_TIMEOUT=1,
        NET_LLC2_P_TIMEOUT=2,
        NET_LLC2_REJ_TIMEOUT=3,
        NET_LLC2_BUSY_TIMEOUT=4,
};


enum {
        NET_ATALK_AARP_EXPIRY_TIME=1,
        NET_ATALK_AARP_TICK_TIME=2,
        NET_ATALK_AARP_RETRANSMIT_LIMIT=3,
        NET_ATALK_AARP_RESOLVE_TIME=4
};



enum {
        NET_NETROM_DEFAULT_PATH_QUALITY=1,
        NET_NETROM_OBSOLESCENCE_COUNT_INITIALISER=2,
        NET_NETROM_NETWORK_TTL_INITIALISER=3,
        NET_NETROM_TRANSPORT_TIMEOUT=4,
        NET_NETROM_TRANSPORT_MAXIMUM_TRIES=5,
        NET_NETROM_TRANSPORT_ACKNOWLEDGE_DELAY=6,
        NET_NETROM_TRANSPORT_BUSY_DELAY=7,
        NET_NETROM_TRANSPORT_REQUESTED_WINDOW_SIZE=8,
        NET_NETROM_TRANSPORT_NO_ACTIVITY_TIMEOUT=9,
        NET_NETROM_ROUTING_CONTROL=10,
        NET_NETROM_LINK_FAILS_COUNT=11,
        NET_NETROM_RESET=12
};


enum {
        NET_AX25_IP_DEFAULT_MODE=1,
        NET_AX25_DEFAULT_MODE=2,
        NET_AX25_BACKOFF_TYPE=3,
        NET_AX25_CONNECT_MODE=4,
        NET_AX25_STANDARD_WINDOW=5,
        NET_AX25_EXTENDED_WINDOW=6,
        NET_AX25_T1_TIMEOUT=7,
        NET_AX25_T2_TIMEOUT=8,
        NET_AX25_T3_TIMEOUT=9,
        NET_AX25_IDLE_TIMEOUT=10,
        NET_AX25_N2=11,
        NET_AX25_PACLEN=12,
        NET_AX25_PROTOCOL=13,
        NET_AX25_DAMA_SLAVE_TIMEOUT=14
};


enum {
        NET_ROSE_RESTART_REQUEST_TIMEOUT=1,
        NET_ROSE_CALL_REQUEST_TIMEOUT=2,
        NET_ROSE_RESET_REQUEST_TIMEOUT=3,
        NET_ROSE_CLEAR_REQUEST_TIMEOUT=4,
        NET_ROSE_ACK_HOLD_BACK_TIMEOUT=5,
        NET_ROSE_ROUTING_CONTROL=6,
        NET_ROSE_LINK_FAIL_TIMEOUT=7,
        NET_ROSE_MAX_VCS=8,
        NET_ROSE_WINDOW_SIZE=9,
        NET_ROSE_NO_ACTIVITY_TIMEOUT=10
};


enum {
        NET_X25_RESTART_REQUEST_TIMEOUT=1,
        NET_X25_CALL_REQUEST_TIMEOUT=2,
        NET_X25_RESET_REQUEST_TIMEOUT=3,
        NET_X25_CLEAR_REQUEST_TIMEOUT=4,
        NET_X25_ACK_HOLD_BACK_TIMEOUT=5
};


enum
{
        NET_TR_RIF_TIMEOUT=1
};


enum {
        NET_DECNET_NODE_TYPE = 1,
        NET_DECNET_NODE_ADDRESS = 2,
        NET_DECNET_NODE_NAME = 3,
        NET_DECNET_DEFAULT_DEVICE = 4,
        NET_DECNET_TIME_WAIT = 5,
        NET_DECNET_DN_COUNT = 6,
        NET_DECNET_DI_COUNT = 7,
        NET_DECNET_DR_COUNT = 8,
        NET_DECNET_DST_GC_INTERVAL = 9,
        NET_DECNET_CONF = 10,
        NET_DECNET_NO_FC_MAX_CWND = 11,
        NET_DECNET_DEBUG_LEVEL = 255
};


enum {
        NET_DECNET_CONF_LOOPBACK = -2,
        NET_DECNET_CONF_DDCMP = -3,
        NET_DECNET_CONF_PPP = -4,
        NET_DECNET_CONF_X25 = -5,
        NET_DECNET_CONF_GRE = -6,
        NET_DECNET_CONF_ETHER = -7


};


enum {
        NET_DECNET_CONF_DEV_PRIORITY = 1,
        NET_DECNET_CONF_DEV_T1 = 2,
        NET_DECNET_CONF_DEV_T2 = 3,
        NET_DECNET_CONF_DEV_T3 = 4,
        NET_DECNET_CONF_DEV_FORWARDING = 5,
        NET_DECNET_CONF_DEV_BLKSIZE = 6,
        NET_DECNET_CONF_DEV_STATE = 7
};


enum {
        NET_SCTP_RTO_INITIAL = 1,
        NET_SCTP_RTO_MIN = 2,
        NET_SCTP_RTO_MAX = 3,
        NET_SCTP_RTO_ALPHA = 4,
        NET_SCTP_RTO_BETA = 5,
        NET_SCTP_VALID_COOKIE_LIFE = 6,
        NET_SCTP_ASSOCIATION_MAX_RETRANS = 7,
        NET_SCTP_PATH_MAX_RETRANS = 8,
        NET_SCTP_MAX_INIT_RETRANSMITS = 9,
        NET_SCTP_HB_INTERVAL = 10,
        NET_SCTP_PRESERVE_ENABLE = 11,
        NET_SCTP_MAX_BURST = 12,
        NET_SCTP_ADDIP_ENABLE = 13,
        NET_SCTP_PRSCTP_ENABLE = 14,
        NET_SCTP_SNDBUF_POLICY = 15,
        NET_SCTP_SACK_TIMEOUT = 16,
};


enum {
        NET_BRIDGE_NF_CALL_ARPTABLES = 1,
        NET_BRIDGE_NF_CALL_IPTABLES = 2,
        NET_BRIDGE_NF_CALL_IP6TABLES = 3,
        NET_BRIDGE_NF_FILTER_VLAN_TAGGED = 4,
};




enum
{
        FS_NRINODE=1,
        FS_STATINODE=2,
        FS_MAXINODE=3,
        FS_NRDQUOT=4,
        FS_MAXDQUOT=5,
        FS_NRFILE=6,
        FS_MAXFILE=7,
        FS_DENTRY=8,
        FS_NRSUPER=9,
        FS_MAXSUPER=10,
        FS_OVERFLOWUID=11,
        FS_OVERFLOWGID=12,
        FS_LEASES=13,
        FS_DIR_NOTIFY=14,
        FS_LEASE_TIME=15,
        FS_DQSTATS=16,
        FS_XFS=17,
        FS_AIO_NR=18,
        FS_AIO_MAX_NR=19,
        FS_INOTIFY=20,
};


enum {
        FS_DQ_LOOKUPS = 1,
        FS_DQ_DROPS = 2,
        FS_DQ_READS = 3,
        FS_DQ_WRITES = 4,
        FS_DQ_CACHE_HITS = 5,
        FS_DQ_ALLOCATED = 6,
        FS_DQ_FREE = 7,
        FS_DQ_SYNCS = 8,
        FS_DQ_WARNINGS = 9,
};




enum {
        DEV_CDROM=1,
        DEV_HWMON=2,
        DEV_PARPORT=3,
        DEV_RAID=4,
        DEV_MAC_HID=5,
        DEV_SCSI=6,
        DEV_IPMI=7,
};


enum {
        DEV_CDROM_INFO=1,
        DEV_CDROM_AUTOCLOSE=2,
        DEV_CDROM_AUTOEJECT=3,
        DEV_CDROM_DEBUG=4,
        DEV_CDROM_LOCK=5,
        DEV_CDROM_CHECK_MEDIA=6
};


enum {
        DEV_PARPORT_DEFAULT=-3
};


enum {
        DEV_RAID_SPEED_LIMIT_MIN=1,
        DEV_RAID_SPEED_LIMIT_MAX=2
};


enum {
        DEV_PARPORT_DEFAULT_TIMESLICE=1,
        DEV_PARPORT_DEFAULT_SPINTIME=2
};


enum {
        DEV_PARPORT_SPINTIME=1,
        DEV_PARPORT_BASE_ADDR=2,
        DEV_PARPORT_IRQ=3,
        DEV_PARPORT_DMA=4,
        DEV_PARPORT_MODES=5,
        DEV_PARPORT_DEVICES=6,
        DEV_PARPORT_AUTOPROBE=16
};


enum {
        DEV_PARPORT_DEVICES_ACTIVE=-3,
};


enum {
        DEV_PARPORT_DEVICE_TIMESLICE=1,
};


enum {
        DEV_MAC_HID_KEYBOARD_SENDS_LINUX_KEYCODES=1,
        DEV_MAC_HID_KEYBOARD_LOCK_KEYCODES=2,
        DEV_MAC_HID_MOUSE_BUTTON_EMULATION=3,
        DEV_MAC_HID_MOUSE_BUTTON2_KEYCODE=4,
        DEV_MAC_HID_MOUSE_BUTTON3_KEYCODE=5,
        DEV_MAC_HID_ADB_MOUSE_SENDS_KEYCODES=6
};


enum {
        DEV_SCSI_LOGGING_LEVEL=1,
};


enum {
        DEV_IPMI_POWEROFF_POWERCYCLE=1,
};


enum
{
        ABI_DEFHANDLER_COFF=1,
        ABI_DEFHANDLER_ELF=2,
        ABI_DEFHANDLER_LCALL7=3,
        ABI_DEFHANDLER_LIBCSO=4,
        ABI_TRACE=5,
        ABI_FAKE_UTSNAME=6,
};



extern void sysctl_init(void);

typedef struct ctl_table ctl_table;

typedef int ctl_handler (ctl_table *table, int *name, int nlen,
                         void *oldval, size_t *oldlenp,
                         void *newval, size_t newlen,
                         void **context);

typedef int proc_handler (ctl_table *ctl, int write, struct file * filp,
                          void *buffer, size_t *lenp, loff_t *ppos);

extern int proc_dostring(ctl_table *, int, struct file *,
                         void *, size_t *, loff_t *);
extern int proc_dointvec(ctl_table *, int, struct file *,
                         void *, size_t *, loff_t *);
extern int proc_dointvec_bset(ctl_table *, int, struct file *,
                              void *, size_t *, loff_t *);
extern int proc_dointvec_minmax(ctl_table *, int, struct file *,
                                void *, size_t *, loff_t *);
extern int proc_dointvec_jiffies(ctl_table *, int, struct file *,
                                 void *, size_t *, loff_t *);
extern int proc_dointvec_userhz_jiffies(ctl_table *, int, struct file *,
                                        void *, size_t *, loff_t *);
extern int proc_dointvec_ms_jiffies(ctl_table *, int, struct file *,
                                    void *, size_t *, loff_t *);
extern int proc_doulongvec_minmax(ctl_table *, int, struct file *,
                                  void *, size_t *, loff_t *);
extern int proc_doulongvec_ms_jiffies_minmax(ctl_table *table, int,
                                      struct file *, void *, size_t *, loff_t *);

extern int do_sysctl (int *name, int nlen,
                      void *oldval, size_t *oldlenp,
                      void *newval, size_t newlen);

extern int do_sysctl_strategy (ctl_table *table,
                               int *name, int nlen,
                               void *oldval, size_t *oldlenp,
                               void *newval, size_t newlen, void ** context);

extern ctl_handler sysctl_string;
extern ctl_handler sysctl_intvec;
extern ctl_handler sysctl_jiffies;
extern ctl_handler sysctl_ms_jiffies;
# 907 "include/linux/sysctl.h"
struct ctl_table
{
        int ctl_name;
        const char *procname;
        void *data;
        int maxlen;
        mode_t mode;
        ctl_table *child;
        proc_handler *proc_handler;
        ctl_handler *strategy;
        struct proc_dir_entry *de;
        void *extra1;
        void *extra2;
};



struct ctl_table_header
{
        ctl_table *ctl_table;
        struct list_head ctl_entry;
};

struct ctl_table_header * register_sysctl_table(ctl_table * table,
                                                int insert_at_head);
void unregister_sysctl_table(struct ctl_table_header * table);
# 291 "include/linux/net.h" 2
extern ctl_table net_table[];
extern int net_msg_cost;
extern int net_msg_burst;
# 30 "include/linux/skbuff.h" 2
# 1 "include/linux/textsearch.h" 1
# 12 "include/linux/textsearch.h"
struct ts_config;
# 24 "include/linux/textsearch.h"
struct ts_state
{
        unsigned int offset;
        char cb[40];
};
# 40 "include/linux/textsearch.h"
struct ts_ops
{
        const char *name;
        struct ts_config * (*init)(const void *, unsigned int, int);
        unsigned int (*find)(struct ts_config *,
                                        struct ts_state *);
        void (*destroy)(struct ts_config *);
        void * (*get_pattern)(struct ts_config *);
        unsigned int (*get_pattern_len)(struct ts_config *);
        struct module *owner;
        struct list_head list;
};







struct ts_config
{
        struct ts_ops *ops;
# 75 "include/linux/textsearch.h"
        unsigned int (*get_next_block)(unsigned int consumed,
                                                  const u8 **dst,
                                                  struct ts_config *conf,
                                                  struct ts_state *state);
# 88 "include/linux/textsearch.h"
        void (*finish)(struct ts_config *conf,
                                          struct ts_state *state);
};
# 104 "include/linux/textsearch.h"
static inline __attribute__((always_inline)) unsigned int textsearch_next(struct ts_config *conf,
                                           struct ts_state *state)
{
        unsigned int ret = conf->ops->find(conf, state);

        if (conf->finish)
                conf->finish(conf, state);

        return ret;
}
# 123 "include/linux/textsearch.h"
static inline __attribute__((always_inline)) unsigned int textsearch_find(struct ts_config *conf,
                                           struct ts_state *state)
{
        state->offset = 0;
        return textsearch_next(conf, state);
}





static inline __attribute__((always_inline)) void *textsearch_get_pattern(struct ts_config *conf)
{
        return conf->ops->get_pattern(conf);
}





static inline __attribute__((always_inline)) unsigned int textsearch_get_pattern_len(struct ts_config *conf)
{
        return conf->ops->get_pattern_len(conf);
}

extern int textsearch_register(struct ts_ops *);
extern int textsearch_unregister(struct ts_ops *);
extern struct ts_config *textsearch_prepare(const char *, const void *,
                                            unsigned int, int, int);
extern void textsearch_destroy(struct ts_config *conf);
extern unsigned int textsearch_find_continuous(struct ts_config *,
                                               struct ts_state *,
                                               const void *, unsigned int);





static inline __attribute__((always_inline)) struct ts_config *alloc_ts_config(size_t payload,
                                                gfp_t gfp_mask)
{
        struct ts_config *conf;

        conf = kmalloc((((sizeof(*conf)) + 8 -1) & ~(8 -1)) + payload, gfp_mask);
        if (conf == ((void *)0))
                return ERR_PTR(-12);

        (__builtin_constant_p(0) ? (__builtin_constant_p(((((sizeof(*conf)) + 8 -1) & ~(8 -1)) + payload)) ? __constant_c_and_count_memset(((conf)),((0x01010101UL*(unsigned char)(0))),(((((sizeof(*conf)) + 8 -1) & ~(8 -1)) + payload))) : __constant_c_memset(((conf)),((0x01010101UL*(unsigned char)(0))),(((((sizeof(*conf)) + 8 -1) & ~(8 -1)) + payload)))) : (__builtin_constant_p(((((sizeof(*conf)) + 8 -1) & ~(8 -1)) + payload)) ? __memset_generic((((conf))),(((0))),((((((sizeof(*conf)) + 8 -1) & ~(8 -1)) + payload)))) : __memset_generic(((conf)),((0)),(((((sizeof(*conf)) + 8 -1) & ~(8 -1)) + payload)))));
        return conf;
}

static inline __attribute__((always_inline)) void *ts_config_priv(struct ts_config *conf)
{
        return ((u8 *) conf + (((sizeof(struct ts_config)) + 8 -1) & ~(8 -1)));
}
# 31 "include/linux/skbuff.h" 2
# 1 "include/net/checksum.h" 1
# 26 "include/net/checksum.h"
# 1 "include/asm/checksum.h" 1



# 1 "include/linux/in6.h" 1
# 30 "include/linux/in6.h"
struct in6_addr
{
        union
        {
                __u8 u6_addr8[16];
                __u16 u6_addr16[8];
                __u32 u6_addr32[4];
        } in6_u;



};
# 51 "include/linux/in6.h"
extern const struct in6_addr in6addr_loopback;


struct sockaddr_in6 {
        unsigned short int sin6_family;
        __u16 sin6_port;
        __u32 sin6_flowinfo;
        struct in6_addr sin6_addr;
        __u32 sin6_scope_id;
};

struct ipv6_mreq {

        struct in6_addr ipv6mr_multiaddr;


        int ipv6mr_ifindex;
};



struct in6_flowlabel_req
{
        struct in6_addr flr_dst;
        __u32 flr_label;
        __u8 flr_action;
        __u8 flr_share;
        __u16 flr_flags;
        __u16 flr_expires;
        __u16 flr_linger;
        __u32 __flr_pad;

};
# 5 "include/asm/checksum.h" 2
# 20 "include/asm/checksum.h"
 __attribute__((regparm(0))) unsigned int csum_partial(const unsigned char * buff, int len, unsigned int sum);
# 30 "include/asm/checksum.h"
 __attribute__((regparm(0))) unsigned int csum_partial_copy_generic(const unsigned char *src, unsigned char *dst,
                                                  int len, int sum, int *src_err_ptr, int *dst_err_ptr);
# 40 "include/asm/checksum.h"
static __inline__ __attribute__((always_inline))
unsigned int csum_partial_copy_nocheck (const unsigned char *src, unsigned char *dst,
                                        int len, int sum)
{
        return csum_partial_copy_generic ( src, dst, len, sum, ((void *)0), ((void *)0));
}

static __inline__ __attribute__((always_inline))
unsigned int csum_partial_copy_from_user(const unsigned char *src, unsigned char *dst,
                                                int len, int sum, int *err_ptr)
{
        do { do { } while (0); } while (0);
        return csum_partial_copy_generic(( unsigned char *)src, dst,
                                        len, sum, err_ptr, ((void *)0));
}
# 63 "include/asm/checksum.h"
static inline __attribute__((always_inline)) unsigned short ip_fast_csum(unsigned char * iph,
                                          unsigned int ihl)
{
        unsigned int sum;

        __asm__ __volatile__(
            "movl (%1), %0	;\n"
            "subl $4, %2	;\n"
            "jbe 2f		;\n"
            "addl 4(%1), %0	;\n"
            "adcl 8(%1), %0	;\n"
            "adcl 12(%1), %0	;\n"
"1:	    adcl 16(%1), %0	;\n"
            "lea 4(%1), %1	;\n"
            "decl %2		;\n"
            "jne 1b		;\n"
            "adcl $0, %0	;\n"
            "movl %0, %2	;\n"
            "shrl $16, %0	;\n"
            "addw %w2, %w0	;\n"
            "adcl $0, %0	;\n"
            "notl %0		;\n"
"2:				;\n"



        : "=r" (sum), "=r" (iph), "=r" (ihl)
        : "1" (iph), "2" (ihl)
        : "memory");
        return(sum);
}





static inline __attribute__((always_inline)) unsigned int csum_fold(unsigned int sum)
{
        __asm__(
                "addl %1, %0		;\n"
                "adcl $0xffff, %0	;\n"
                : "=r" (sum)
                : "r" (sum << 16), "0" (sum & 0xffff0000)
        );
        return (~sum) >> 16;
}

static inline __attribute__((always_inline)) unsigned long csum_tcpudp_nofold(unsigned long saddr,
                                                   unsigned long daddr,
                                                   unsigned short len,
                                                   unsigned short proto,
                                                   unsigned int sum)
{
    __asm__(
        "addl %1, %0	;\n"
        "adcl %2, %0	;\n"
        "adcl %3, %0	;\n"
        "adcl $0, %0	;\n"
        : "=r" (sum)
        : "g" (daddr), "g"(saddr), "g"((ntohs(len)<<16)+proto*256), "0"(sum));
    return sum;
}





static inline __attribute__((always_inline)) unsigned short int csum_tcpudp_magic(unsigned long saddr,
                                                   unsigned long daddr,
                                                   unsigned short len,
                                                   unsigned short proto,
                                                   unsigned int sum)
{
        return csum_fold(csum_tcpudp_nofold(saddr,daddr,len,proto,sum));
}






static inline __attribute__((always_inline)) unsigned short ip_compute_csum(unsigned char * buff, int len)
{
    return csum_fold (csum_partial(buff, len, 0));
}


static __inline__ __attribute__((always_inline)) unsigned short int csum_ipv6_magic(struct in6_addr *saddr,
                                                     struct in6_addr *daddr,
                                                     __u32 len,
                                                     unsigned short proto,
                                                     unsigned int sum)
{
        __asm__(
                "addl 0(%1), %0		;\n"
                "adcl 4(%1), %0		;\n"
                "adcl 8(%1), %0		;\n"
                "adcl 12(%1), %0	;\n"
                "adcl 0(%2), %0		;\n"
                "adcl 4(%2), %0		;\n"
                "adcl 8(%2), %0		;\n"
                "adcl 12(%2), %0	;\n"
                "adcl %3, %0		;\n"
                "adcl %4, %0		;\n"
                "adcl $0, %0		;\n"
                : "=&r" (sum)
                : "r" (saddr), "r" (daddr),
                  "r"(htonl(len)), "r"(htonl(proto)), "0"(sum));

        return csum_fold(sum);
}





static __inline__ __attribute__((always_inline)) unsigned int csum_and_copy_to_user(const unsigned char *src,
                                                     unsigned char *dst,
                                                     int len, int sum,
                                                     int *err_ptr)
{
        do { do { } while (0); } while (0);
        if ((__builtin_expect(!!(({ unsigned long flag,sum; (void)0; asm("addl %3,%1 ; sbbl %0,%0; cmpl %1,%4; sbbl $0,%0" :"=&r" (flag), "=r" (sum) :"1" (dst),"g" ((int)(len)),"g" (current_thread_info()->addr_limit.seg)); flag; }) == 0), 1)))
                return csum_partial_copy_generic(src, ( unsigned char *)dst, len, sum, ((void *)0), err_ptr);

        if (len)
                *err_ptr = -14;

        return -1;
}
# 27 "include/net/checksum.h" 2


static inline __attribute__((always_inline))
unsigned int csum_and_copy_from_user (const unsigned char *src, unsigned char *dst,
                                      int len, int sum, int *err_ptr)
{
        if ((__builtin_expect(!!(({ unsigned long flag,sum; (void)0; asm("addl %3,%1 ; sbbl %0,%0; cmpl %1,%4; sbbl $0,%0" :"=&r" (flag), "=r" (sum) :"1" (src),"g" ((int)(len)),"g" (current_thread_info()->addr_limit.seg)); flag; }) == 0), 1)))
                return csum_partial_copy_from_user(src, dst, len, sum, err_ptr);

        if (len)
                *err_ptr = -14;

        return sum;
}
# 60 "include/net/checksum.h"
static inline __attribute__((always_inline)) unsigned int csum_add(unsigned int csum, unsigned int addend)
{
        csum += addend;
        return csum + (csum < addend);
}

static inline __attribute__((always_inline)) unsigned int csum_sub(unsigned int csum, unsigned int addend)
{
        return csum_add(csum, ~addend);
}

static inline __attribute__((always_inline)) unsigned int
csum_block_add(unsigned int csum, unsigned int csum2, int offset)
{
        if (offset&1)
                csum2 = ((csum2&0xFF00FF)<<8)+((csum2>>8)&0xFF00FF);
        return csum_add(csum, csum2);
}

static inline __attribute__((always_inline)) unsigned int
csum_block_sub(unsigned int csum, unsigned int csum2, int offset)
{
        if (offset&1)
                csum2 = ((csum2&0xFF00FF)<<8)+((csum2>>8)&0xFF00FF);
        return csum_sub(csum, csum2);
}
# 32 "include/linux/skbuff.h" 2
# 87 "include/linux/skbuff.h"
struct net_device;


struct nf_conntrack {
        atomic_t use;
        void (*destroy)(struct nf_conntrack *);
};


struct nf_bridge_info {
        atomic_t use;
        struct net_device *physindev;
        struct net_device *physoutdev;

        struct net_device *netoutdev;

        unsigned int mask;
        unsigned long data[32 / sizeof(unsigned long)];
};




struct sk_buff_head {

        struct sk_buff *next;
        struct sk_buff *prev;

        __u32 qlen;
        spinlock_t lock;
};

struct sk_buff;




typedef struct skb_frag_struct skb_frag_t;

struct skb_frag_struct {
        struct page *page;
        __u16 page_offset;
        __u16 size;
};




struct skb_shared_info {
        atomic_t dataref;
        unsigned int nr_frags;
        unsigned short tso_size;
        unsigned short tso_segs;
        struct sk_buff *frag_list;
        skb_frag_t frags[(65536/(1UL << 12) + 2)];
};
# 158 "include/linux/skbuff.h"
struct skb_timeval {
        u32 off_sec;
        u32 off_usec;
};


enum {
        SKB_FCLONE_UNAVAILABLE,
        SKB_FCLONE_ORIG,
        SKB_FCLONE_CLONE,
};
# 211 "include/linux/skbuff.h"
struct sk_buff {

        struct sk_buff *next;
        struct sk_buff *prev;

        struct sock *sk;
        struct skb_timeval tstamp;
        struct net_device *dev;
        struct net_device *input_dev;

        union {
                struct tcphdr *th;
                struct udphdr *uh;
                struct icmphdr *icmph;
                struct igmphdr *igmph;
                struct iphdr *ipiph;
                struct ipv6hdr *ipv6h;
                unsigned char *raw;
        } h;

        union {
                struct iphdr *iph;
                struct ipv6hdr *ipv6h;
                struct arphdr *arph;
                unsigned char *raw;
        } nh;

        union {
                unsigned char *raw;
        } mac;

        struct dst_entry *dst;
        struct sec_path *sp;







        char cb[40];

        unsigned int len,
                                data_len,
                                mac_len,
                                csum;
        __u32 priority;
        __u8 local_df:1,
                                cloned:1,
                                ip_summed:2,
                                nohdr:1,
                                nfctinfo:3;
        __u8 pkt_type:3,
                                fclone:2;
        __be16 protocol;

        void (*destructor)(struct sk_buff *skb);

        __u32 nfmark;
        struct nf_conntrack *nfct;

        __u8 ipvs_property:1;


        struct nf_bridge_info *nf_bridge;



        __u16 tc_index;







        unsigned int truesize;
        atomic_t users;
        unsigned char *head,
                                *data,
                                *tail,
                                *end;
};
# 303 "include/linux/skbuff.h"
extern void __kfree_skb(struct sk_buff *skb);
extern struct sk_buff *__alloc_skb(unsigned int size,
                                   gfp_t priority, int fclone);
static inline __attribute__((always_inline)) struct sk_buff *alloc_skb(unsigned int size,
                                        gfp_t priority)
{
        return __alloc_skb(size, priority, 0);
}

static inline __attribute__((always_inline)) struct sk_buff *alloc_skb_fclone(unsigned int size,
                                               gfp_t priority)
{
        return __alloc_skb(size, priority, 1);
}

extern struct sk_buff *alloc_skb_from_cache(kmem_cache_t *cp,
                                            unsigned int size,
                                            gfp_t priority);
extern void kfree_skbmem(struct sk_buff *skb);
extern struct sk_buff *skb_clone(struct sk_buff *skb,
                                 gfp_t priority);
extern struct sk_buff *skb_copy(const struct sk_buff *skb,
                                gfp_t priority);
extern struct sk_buff *pskb_copy(struct sk_buff *skb,
                                 gfp_t gfp_mask);
extern int pskb_expand_head(struct sk_buff *skb,
                                        int nhead, int ntail,
                                        gfp_t gfp_mask);
extern struct sk_buff *skb_realloc_headroom(struct sk_buff *skb,
                                            unsigned int headroom);
extern struct sk_buff *skb_copy_expand(const struct sk_buff *skb,
                                       int newheadroom, int newtailroom,
                                       gfp_t priority);
extern struct sk_buff * skb_pad(struct sk_buff *skb, int pad);

extern void skb_over_panic(struct sk_buff *skb, int len,
                                     void *here);
extern void skb_under_panic(struct sk_buff *skb, int len,
                                      void *here);

struct skb_seq_state
{
        __u32 lower_offset;
        __u32 upper_offset;
        __u32 frag_idx;
        __u32 stepped_offset;
        struct sk_buff *root_skb;
        struct sk_buff *cur_skb;
        __u8 *frag_data;
};

extern void skb_prepare_seq_read(struct sk_buff *skb,
                                           unsigned int from, unsigned int to,
                                           struct skb_seq_state *st);
extern unsigned int skb_seq_read(unsigned int consumed, const u8 **data,
                                   struct skb_seq_state *st);
extern void skb_abort_seq_read(struct skb_seq_state *st);

extern unsigned int skb_find_text(struct sk_buff *skb, unsigned int from,
                                    unsigned int to, struct ts_config *config,
                                    struct ts_state *state);
# 374 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) int skb_queue_empty(const struct sk_buff_head *list)
{
        return list->next == (struct sk_buff *)list;
}
# 386 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *skb_get(struct sk_buff *skb)
{
        atomic_inc(&skb->users);
        return skb;
}
# 404 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void kfree_skb(struct sk_buff *skb)
{
        if (__builtin_expect(!!(((&skb->users)->counter) == 1), 1))
                asm volatile ("661:\n\t" "lock; addl $0,0(%%esp)" "\n662:\n" ".section .altinstructions,\"a\"\n" "  .align 4\n" "  .long 661b\n" "  .long 663f\n" "  .byte %c0\n" "  .byte 662b-661b\n" "  .byte 664f-663f\n" ".previous\n" ".section .altinstr_replacement,\"ax\"\n" "663:\n\t" "lfence" "\n664:\n" ".previous" :: "i" ((0*32+26)) : "memory");
        else if (__builtin_expect(!!(!atomic_dec_and_test(&skb->users)), 1))
                return;
        __kfree_skb(skb);
}
# 421 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) int skb_cloned(const struct sk_buff *skb)
{
        return skb->cloned &&
               (((&((struct skb_shared_info *)((skb)->end))->dataref)->counter) & ((1 << 16) - 1)) != 1;
}
# 434 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) int skb_header_cloned(const struct sk_buff *skb)
{
        int dataref;

        if (!skb->cloned)
                return 0;

        dataref = ((&((struct skb_shared_info *)((skb)->end))->dataref)->counter);
        dataref = (dataref & ((1 << 16) - 1)) - (dataref >> 16);
        return dataref != 1;
}
# 454 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void skb_header_release(struct sk_buff *skb)
{
        do { if (__builtin_expect(!!((skb->nohdr)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (456), "i" ("include/linux/skbuff.h")); } while(0);
        skb->nohdr = 1;
        atomic_add(1 << 16, &((struct skb_shared_info *)((skb)->end))->dataref);
}
# 468 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) int skb_shared(const struct sk_buff *skb)
{
        return ((&skb->users)->counter) != 1;
}
# 486 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *skb_share_check(struct sk_buff *skb,
                                              gfp_t pri)
{
        do { if (__builtin_expect(!!(pri & 0x10u), 0)) do { do { } while (0); } while (0); } while (0);
        if (skb_shared(skb)) {
                struct sk_buff *nskb = skb_clone(skb, pri);
                kfree_skb(skb);
                skb = nskb;
        }
        return skb;
}
# 518 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *skb_unshare(struct sk_buff *skb,
                                          gfp_t pri)
{
        do { if (__builtin_expect(!!(pri & 0x10u), 0)) do { do { } while (0); } while (0); } while (0);
        if (skb_cloned(skb)) {
                struct sk_buff *nskb = skb_copy(skb, pri);
                kfree_skb(skb);
                skb = nskb;
        }
        return skb;
}
# 543 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *skb_peek(struct sk_buff_head *list_)
{
        struct sk_buff *list = ((struct sk_buff *)list_)->next;
        if (list == (struct sk_buff *)list_)
                list = ((void *)0);
        return list;
}
# 564 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *skb_peek_tail(struct sk_buff_head *list_)
{
        struct sk_buff *list = ((struct sk_buff *)list_)->prev;
        if (list == (struct sk_buff *)list_)
                list = ((void *)0);
        return list;
}







static inline __attribute__((always_inline)) __u32 skb_queue_len(const struct sk_buff_head *list_)
{
        return list_->qlen;
}

static inline __attribute__((always_inline)) void skb_queue_head_init(struct sk_buff_head *list)
{
        spin_lock_init(&list->lock);
        list->prev = list->next = (struct sk_buff *)list;
        list->qlen = 0;
}
# 607 "include/linux/skbuff.h"
extern void skb_queue_head(struct sk_buff_head *list, struct sk_buff *newsk);
static inline __attribute__((always_inline)) void __skb_queue_head(struct sk_buff_head *list,
                                    struct sk_buff *newsk)
{
        struct sk_buff *prev, *next;

        list->qlen++;
        prev = (struct sk_buff *)list;
        next = prev->next;
        newsk->next = next;
        newsk->prev = prev;
        next->prev = prev->next = newsk;
}
# 631 "include/linux/skbuff.h"
extern void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk);
static inline __attribute__((always_inline)) void __skb_queue_tail(struct sk_buff_head *list,
                                   struct sk_buff *newsk)
{
        struct sk_buff *prev, *next;

        list->qlen++;
        next = (struct sk_buff *)list;
        prev = next->prev;
        newsk->next = next;
        newsk->prev = prev;
        next->prev = prev->next = newsk;
}
# 654 "include/linux/skbuff.h"
extern struct sk_buff *skb_dequeue(struct sk_buff_head *list);
static inline __attribute__((always_inline)) struct sk_buff *__skb_dequeue(struct sk_buff_head *list)
{
        struct sk_buff *next, *prev, *result;

        prev = (struct sk_buff *) list;
        next = prev->next;
        result = ((void *)0);
        if (next != prev) {
                result = next;
                next = next->next;
                list->qlen--;
                next->prev = prev;
                prev->next = next;
                result->next = result->prev = ((void *)0);
        }
        return result;
}





extern void skb_insert(struct sk_buff *old, struct sk_buff *newsk, struct sk_buff_head *list);
static inline __attribute__((always_inline)) void __skb_insert(struct sk_buff *newsk,
                                struct sk_buff *prev, struct sk_buff *next,
                                struct sk_buff_head *list)
{
        newsk->next = next;
        newsk->prev = prev;
        next->prev = prev->next = newsk;
        list->qlen++;
}




extern void skb_append(struct sk_buff *old, struct sk_buff *newsk, struct sk_buff_head *list);
static inline __attribute__((always_inline)) void __skb_append(struct sk_buff *old, struct sk_buff *newsk, struct sk_buff_head *list)
{
        __skb_insert(newsk, old, old->next, list);
}





extern void skb_unlink(struct sk_buff *skb, struct sk_buff_head *list);
static inline __attribute__((always_inline)) void __skb_unlink(struct sk_buff *skb, struct sk_buff_head *list)
{
        struct sk_buff *next, *prev;

        list->qlen--;
        next = skb->next;
        prev = skb->prev;
        skb->next = skb->prev = ((void *)0);
        next->prev = prev;
        prev->next = next;
}
# 725 "include/linux/skbuff.h"
extern struct sk_buff *skb_dequeue_tail(struct sk_buff_head *list);
static inline __attribute__((always_inline)) struct sk_buff *__skb_dequeue_tail(struct sk_buff_head *list)
{
        struct sk_buff *skb = skb_peek_tail(list);
        if (skb)
                __skb_unlink(skb, list);
        return skb;
}


static inline __attribute__((always_inline)) int skb_is_nonlinear(const struct sk_buff *skb)
{
        return skb->data_len;
}

static inline __attribute__((always_inline)) unsigned int skb_headlen(const struct sk_buff *skb)
{
        return skb->len - skb->data_len;
}

static inline __attribute__((always_inline)) int skb_pagelen(const struct sk_buff *skb)
{
        int i, len = 0;

        for (i = (int)((struct skb_shared_info *)((skb)->end))->nr_frags - 1; i >= 0; i--)
                len += ((struct skb_shared_info *)((skb)->end))->frags[i].size;
        return len + skb_headlen(skb);
}

static inline __attribute__((always_inline)) void skb_fill_page_desc(struct sk_buff *skb, int i,
                                      struct page *page, int off, int size)
{
        skb_frag_t *frag = &((struct skb_shared_info *)((skb)->end))->frags[i];

        frag->page = page;
        frag->page_offset = off;
        frag->size = size;
        ((struct skb_shared_info *)((skb)->end))->nr_frags = i + 1;
}
# 772 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) unsigned char *__skb_put(struct sk_buff *skb, unsigned int len)
{
        unsigned char *tmp = skb->tail;
        do { if (__builtin_expect(!!((skb_is_nonlinear(skb))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (775), "i" ("include/linux/skbuff.h")); } while(0);
        skb->tail += len;
        skb->len += len;
        return tmp;
}
# 790 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) unsigned char *skb_put(struct sk_buff *skb, unsigned int len)
{
        unsigned char *tmp = skb->tail;
        do { if (__builtin_expect(!!((skb_is_nonlinear(skb))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (793), "i" ("include/linux/skbuff.h")); } while(0);
        skb->tail += len;
        skb->len += len;
        if (__builtin_expect(!!(skb->tail>skb->end), 0))
                skb_over_panic(skb, len, ({ void *pc; __asm__("movl $1f,%0\n1:":"=g" (pc)); pc; }));
        return tmp;
}

static inline __attribute__((always_inline)) unsigned char *__skb_push(struct sk_buff *skb, unsigned int len)
{
        skb->data -= len;
        skb->len += len;
        return skb->data;
}
# 817 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) unsigned char *skb_push(struct sk_buff *skb, unsigned int len)
{
        skb->data -= len;
        skb->len += len;
        if (__builtin_expect(!!(skb->data<skb->head), 0))
                skb_under_panic(skb, len, ({ void *pc; __asm__("movl $1f,%0\n1:":"=g" (pc)); pc; }));
        return skb->data;
}

static inline __attribute__((always_inline)) unsigned char *__skb_pull(struct sk_buff *skb, unsigned int len)
{
        skb->len -= len;
        do { if (__builtin_expect(!!((skb->len < skb->data_len)!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (829), "i" ("include/linux/skbuff.h")); } while(0);
        return skb->data += len;
}
# 843 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) unsigned char *skb_pull(struct sk_buff *skb, unsigned int len)
{
        return __builtin_expect(!!(len > skb->len), 0) ? ((void *)0) : __skb_pull(skb, len);
}

extern unsigned char *__pskb_pull_tail(struct sk_buff *skb, int delta);

static inline __attribute__((always_inline)) unsigned char *__pskb_pull(struct sk_buff *skb, unsigned int len)
{
        if (len > skb_headlen(skb) &&
            !__pskb_pull_tail(skb, len-skb_headlen(skb)))
                return ((void *)0);
        skb->len -= len;
        return skb->data += len;
}

static inline __attribute__((always_inline)) unsigned char *pskb_pull(struct sk_buff *skb, unsigned int len)
{
        return __builtin_expect(!!(len > skb->len), 0) ? ((void *)0) : __pskb_pull(skb, len);
}

static inline __attribute__((always_inline)) int pskb_may_pull(struct sk_buff *skb, unsigned int len)
{
        if (__builtin_expect(!!(len <= skb_headlen(skb)), 1))
                return 1;
        if (__builtin_expect(!!(len > skb->len), 0))
                return 0;
        return __pskb_pull_tail(skb, len-skb_headlen(skb)) != ((void *)0);
}







static inline __attribute__((always_inline)) int skb_headroom(const struct sk_buff *skb)
{
        return skb->data - skb->head;
}







static inline __attribute__((always_inline)) int skb_tailroom(const struct sk_buff *skb)
{
        return skb_is_nonlinear(skb) ? 0 : skb->end - skb->tail;
}
# 903 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void skb_reserve(struct sk_buff *skb, unsigned int len)
{
        skb->data += len;
        skb->tail += len;
}
# 933 "include/linux/skbuff.h"
extern int ___pskb_trim(struct sk_buff *skb, unsigned int len, int realloc);

static inline __attribute__((always_inline)) void __skb_trim(struct sk_buff *skb, unsigned int len)
{
        if (!skb->data_len) {
                skb->len = len;
                skb->tail = skb->data + len;
        } else
                ___pskb_trim(skb, len, 0);
}
# 952 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void skb_trim(struct sk_buff *skb, unsigned int len)
{
        if (skb->len > len)
                __skb_trim(skb, len);
}


static inline __attribute__((always_inline)) int __pskb_trim(struct sk_buff *skb, unsigned int len)
{
        if (!skb->data_len) {
                skb->len = len;
                skb->tail = skb->data+len;
                return 0;
        }
        return ___pskb_trim(skb, len, 1);
}

static inline __attribute__((always_inline)) int pskb_trim(struct sk_buff *skb, unsigned int len)
{
        return (len < skb->len) ? __pskb_trim(skb, len) : 0;
}
# 982 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void skb_orphan(struct sk_buff *skb)
{
        if (skb->destructor)
                skb->destructor(skb);
        skb->destructor = ((void *)0);
        skb->sk = ((void *)0);
}
# 998 "include/linux/skbuff.h"
extern void skb_queue_purge(struct sk_buff_head *list);
static inline __attribute__((always_inline)) void __skb_queue_purge(struct sk_buff_head *list)
{
        struct sk_buff *skb;
        while ((skb = __skb_dequeue(list)) != ((void *)0))
                kfree_skb(skb);
}
# 1019 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *__dev_alloc_skb(unsigned int length,
                                              gfp_t gfp_mask)
{
        struct sk_buff *skb = alloc_skb(length + 16, gfp_mask);
        if (__builtin_expect(!!(skb), 1))
                skb_reserve(skb, 16);
        return skb;
}
# 1043 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *dev_alloc_skb(unsigned int length)
{
        return __dev_alloc_skb(length, (0x20u));
}
# 1060 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) int skb_cow(struct sk_buff *skb, unsigned int headroom)
{
        int delta = (headroom > 16 ? headroom : 16) - skb_headroom(skb);

        if (delta < 0)
                delta = 0;

        if (delta || skb_cloned(skb))
                return pskb_expand_head(skb, (delta + 15) & ~15, 0, (0x20u));
        return 0;
}
# 1084 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) struct sk_buff *skb_padto(struct sk_buff *skb, unsigned int len)
{
        unsigned int size = skb->len;
        if (__builtin_expect(!!(size >= len), 1))
                return skb;
        return skb_pad(skb, len-size);
}

static inline __attribute__((always_inline)) int skb_add_data(struct sk_buff *skb,
                               char *from, int copy)
{
        const int off = skb->len;

        if (skb->ip_summed == 0) {
                int err = 0;
                unsigned int csum = csum_and_copy_from_user(from,
                                                            skb_put(skb, copy),
                                                            copy, 0, &err);
                if (!err) {
                        skb->csum = csum_block_add(skb->csum, csum, off);
                        return 0;
                }
        } else if (!copy_from_user(skb_put(skb, copy), from, copy))
                return 0;

        __skb_trim(skb, off);
        return -14;
}

static inline __attribute__((always_inline)) int skb_can_coalesce(struct sk_buff *skb, int i,
                                   struct page *page, int off)
{
        if (i) {
                struct skb_frag_struct *frag = &((struct skb_shared_info *)((skb)->end))->frags[i - 1];

                return page == frag->page &&
                       off == frag->page_offset + frag->size;
        }
        return 0;
}
# 1133 "include/linux/skbuff.h"
extern int __skb_linearize(struct sk_buff *skb, gfp_t gfp);
static inline __attribute__((always_inline)) int skb_linearize(struct sk_buff *skb, gfp_t gfp)
{
        return __skb_linearize(skb, gfp);
}
# 1150 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void skb_postpull_rcsum(struct sk_buff *skb,
                                         const void *start, int len)
{
        if (skb->ip_summed == 1)
                skb->csum = csum_sub(skb->csum, csum_partial(start, len, 0));
}
# 1166 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) int pskb_trim_rcsum(struct sk_buff *skb, unsigned int len)
{
        if (__builtin_expect(!!(len >= skb->len), 1))
                return 0;
        if (skb->ip_summed == 1)
                skb->ip_summed = 0;
        return __pskb_trim(skb, len);
}

static inline __attribute__((always_inline)) void *kmap_skb_frag(const skb_frag_t *frag)
{

        do { if (__builtin_expect(!!(((((current_thread_info()->preempt_count) & (((1UL << (12))-1) << ((0 + 8) + 8)))))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (1178), "i" ("include/linux/skbuff.h")); } while(0);

        do { do { (current_thread_info()->preempt_count) += ((1UL << (0 + 8))); } while (0); __asm__ __volatile__("": : :"memory"); } while (0);

        return kmap_atomic(frag->page, KM_SKB_DATA_SOFTIRQ);
}

static inline __attribute__((always_inline)) void kunmap_skb_frag(void *vaddr)
{
        kunmap_atomic(vaddr, KM_SKB_DATA_SOFTIRQ);

        local_bh_enable();

}







extern struct sk_buff *skb_recv_datagram(struct sock *sk, unsigned flags,
                                         int noblock, int *err);
extern unsigned int datagram_poll(struct file *file, struct socket *sock,
                                     struct poll_table_struct *wait);
extern int skb_copy_datagram_iovec(const struct sk_buff *from,
                                               int offset, struct iovec *to,
                                               int size);
extern int skb_copy_and_csum_datagram_iovec(const
                                                        struct sk_buff *skb,
                                                        int hlen,
                                                        struct iovec *iov);
extern void skb_free_datagram(struct sock *sk, struct sk_buff *skb);
extern unsigned int skb_checksum(const struct sk_buff *skb, int offset,
                                    int len, unsigned int csum);
extern int skb_copy_bits(const struct sk_buff *skb, int offset,
                                     void *to, int len);
extern int skb_store_bits(const struct sk_buff *skb, int offset,
                                      void *from, int len);
extern unsigned int skb_copy_and_csum_bits(const struct sk_buff *skb,
                                              int offset, u8 *to, int len,
                                              unsigned int csum);
extern void skb_copy_and_csum_dev(const struct sk_buff *skb, u8 *to);
extern void skb_split(struct sk_buff *skb,
                                 struct sk_buff *skb1, const u32 len);

extern void skb_release_data(struct sk_buff *skb);

static inline __attribute__((always_inline)) void *skb_header_pointer(const struct sk_buff *skb, int offset,
                                       int len, void *buffer)
{
        int hlen = skb_headlen(skb);

        if (hlen - offset >= len)
                return skb->data + offset;

        if (skb_copy_bits(skb, offset, buffer, len) < 0)
                return ((void *)0);

        return buffer;
}

extern void skb_init(void);
extern void skb_add_mtu(int mtu);
# 1252 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void skb_get_timestamp(const struct sk_buff *skb, struct timeval *stamp)
{
        stamp->tv_sec = skb->tstamp.off_sec;
        stamp->tv_usec = skb->tstamp.off_usec;
}
# 1267 "include/linux/skbuff.h"
static inline __attribute__((always_inline)) void skb_set_timestamp(struct sk_buff *skb, const struct timeval *stamp)
{
        skb->tstamp.off_sec = stamp->tv_sec;
        skb->tstamp.off_usec = stamp->tv_usec;
}

extern void __net_timestamp(struct sk_buff *skb);


static inline __attribute__((always_inline)) void nf_conntrack_put(struct nf_conntrack *nfct)
{
        if (nfct && atomic_dec_and_test(&nfct->use))
                nfct->destroy(nfct);
}
static inline __attribute__((always_inline)) void nf_conntrack_get(struct nf_conntrack *nfct)
{
        if (nfct)
                atomic_inc(&nfct->use);
}
static inline __attribute__((always_inline)) void nf_reset(struct sk_buff *skb)
{
        nf_conntrack_put(skb->nfct);
        skb->nfct = ((void *)0);
}


static inline __attribute__((always_inline)) void nf_bridge_put(struct nf_bridge_info *nf_bridge)
{
        if (nf_bridge && atomic_dec_and_test(&nf_bridge->use))
                kfree(nf_bridge);
}
static inline __attribute__((always_inline)) void nf_bridge_get(struct nf_bridge_info *nf_bridge)
{
        if (nf_bridge)
                atomic_inc(&nf_bridge->use);
}
# 108 "include/linux/if_ether.h" 2

static inline __attribute__((always_inline)) struct ethhdr *eth_hdr(const struct sk_buff *skb)
{
        return (struct ethhdr *)skb->mac.raw;
}


extern struct ctl_table ether_table[];
# 30 "include/linux/netdevice.h" 2
# 1 "include/linux/if_packet.h" 1



struct sockaddr_pkt
{
        unsigned short spkt_family;
        unsigned char spkt_device[14];
        unsigned short spkt_protocol;
};

struct sockaddr_ll
{
        unsigned short sll_family;
        unsigned short sll_protocol;
        int sll_ifindex;
        unsigned short sll_hatype;
        unsigned char sll_pkttype;
        unsigned char sll_halen;
        unsigned char sll_addr[8];
};
# 43 "include/linux/if_packet.h"
struct tpacket_stats
{
        unsigned int tp_packets;
        unsigned int tp_drops;
};

struct tpacket_hdr
{
        unsigned long tp_status;





        unsigned int tp_len;
        unsigned int tp_snaplen;
        unsigned short tp_mac;
        unsigned short tp_net;
        unsigned int tp_sec;
        unsigned int tp_usec;
};
# 82 "include/linux/if_packet.h"
struct tpacket_req
{
        unsigned int tp_block_size;
        unsigned int tp_block_nr;
        unsigned int tp_frame_size;
        unsigned int tp_frame_nr;
};

struct packet_mreq
{
        int mr_ifindex;
        unsigned short mr_type;
        unsigned short mr_alen;
        unsigned char mr_address[8];
};
# 31 "include/linux/netdevice.h" 2
# 41 "include/linux/netdevice.h"
struct divert_blk;
struct vlan_group;
struct ethtool_ops;
struct netpoll_info;
# 108 "include/linux/netdevice.h"
struct net_device_stats
{
        unsigned long rx_packets;
        unsigned long tx_packets;
        unsigned long rx_bytes;
        unsigned long tx_bytes;
        unsigned long rx_errors;
        unsigned long tx_errors;
        unsigned long rx_dropped;
        unsigned long tx_dropped;
        unsigned long multicast;
        unsigned long collisions;


        unsigned long rx_length_errors;
        unsigned long rx_over_errors;
        unsigned long rx_crc_errors;
        unsigned long rx_frame_errors;
        unsigned long rx_fifo_errors;
        unsigned long rx_missed_errors;


        unsigned long tx_aborted_errors;
        unsigned long tx_carrier_errors;
        unsigned long tx_fifo_errors;
        unsigned long tx_heartbeat_errors;
        unsigned long tx_window_errors;


        unsigned long rx_compressed;
        unsigned long tx_compressed;
};



enum {
        IF_PORT_UNKNOWN = 0,
        IF_PORT_10BASE2,
        IF_PORT_10BASET,
        IF_PORT_AUI,
        IF_PORT_100BASET,
        IF_PORT_100BASETX,
        IF_PORT_100BASEFX
};






struct neighbour;
struct neigh_parms;
struct sk_buff;

struct netif_rx_stats
{
        unsigned total;
        unsigned dropped;
        unsigned time_squeeze;
        unsigned cpu_collision;
};

extern __typeof__(struct netif_rx_stats) per_cpu__netdev_rx_stat;






struct dev_mc_list
{
        struct dev_mc_list *next;
        __u8 dmi_addr[32];
        unsigned char dmi_addrlen;
        int dmi_users;
        int dmi_gusers;
};

struct hh_cache
{
        struct hh_cache *hh_next;
        atomic_t hh_refcnt;
        unsigned short hh_type;



        int hh_len;
        int (*hh_output)(struct sk_buff *skb);
        rwlock_t hh_lock;







        unsigned long hh_data[(((48)+(16 -1))&~(16 - 1)) / sizeof(long)];
};
# 225 "include/linux/netdevice.h"
enum netdev_state_t
{
        __LINK_STATE_XOFF=0,
        __LINK_STATE_START,
        __LINK_STATE_PRESENT,
        __LINK_STATE_SCHED,
        __LINK_STATE_NOCARRIER,
        __LINK_STATE_RX_SCHED,
        __LINK_STATE_LINKWATCH_PENDING
};






struct netdev_boot_setup {
        char name[16];
        struct ifmap map;
};


extern int __attribute__ ((__section__ (".init.text"))) netdev_boot_setup(char *str);
# 259 "include/linux/netdevice.h"
struct net_device
{






        char name[16];

        struct hlist_node name_hlist;





        unsigned long mem_end;
        unsigned long mem_start;
        unsigned long base_addr;
        unsigned int irq;






        unsigned char if_port;
        unsigned char dma;

        unsigned long state;

        struct net_device *next;


        int (*init)(struct net_device *dev);




        unsigned long features;
# 312 "include/linux/netdevice.h"
        struct net_device *next_sched;


        int ifindex;
        int iflink;


        struct net_device_stats* (*get_stats)(struct net_device *dev);
        struct iw_statistics* (*get_wireless_stats)(struct net_device *dev);



        const struct iw_handler_def * wireless_handlers;

        struct iw_public_data * wireless_data;

        struct ethtool_ops *ethtool_ops;
# 337 "include/linux/netdevice.h"
        unsigned short flags;
        unsigned short gflags;
        unsigned short priv_flags;
        unsigned short padded;

        unsigned mtu;
        unsigned short type;
        unsigned short hard_header_len;

        struct net_device *master;




        unsigned char perm_addr[32];
        unsigned char addr_len;
        unsigned short dev_id;

        struct dev_mc_list *mc_list;
        int mc_count;
        int promiscuity;
        int allmulti;




        void *atalk_ptr;
        void *ip_ptr;
        void *dn_ptr;
        void *ip6_ptr;
        void *ec_ptr;
        void *ax25_ptr;




        struct list_head poll_list __attribute__((__aligned__((1 << (4)))));


        int (*poll) (struct net_device *dev, int *quota);
        int quota;
        int weight;
        unsigned long last_rx;

        unsigned char dev_addr[32];


        unsigned char broadcast[32];





        spinlock_t queue_lock __attribute__((__aligned__((1 << (4)))));
        struct Qdisc *qdisc;
        struct Qdisc *qdisc_sleeping;
        struct list_head qdisc_list;
        unsigned long tx_queue_len;


        spinlock_t ingress_lock;
        struct Qdisc *qdisc_ingress;





        spinlock_t xmit_lock __attribute__((__aligned__((1 << (4)))));



        int xmit_lock_owner;
        void *priv;
        int (*hard_start_xmit) (struct sk_buff *skb,
                                                    struct net_device *dev);

        unsigned long trans_start;

        int watchdog_timeo;
        struct timer_list watchdog_timer;





        atomic_t refcnt __attribute__((__aligned__((1 << (4)))));


        struct list_head todo_list;

        struct hlist_node index_hlist;


        enum { NETREG_UNINITIALIZED=0,
               NETREG_REGISTERING,
               NETREG_REGISTERED,
               NETREG_UNREGISTERING,
               NETREG_UNREGISTERED,
               NETREG_RELEASED,
        } reg_state;


        void (*uninit)(struct net_device *dev);

        void (*destructor)(struct net_device *dev);


        int (*open)(struct net_device *dev);
        int (*stop)(struct net_device *dev);

        int (*hard_header) (struct sk_buff *skb,
                                                struct net_device *dev,
                                                unsigned short type,
                                                void *daddr,
                                                void *saddr,
                                                unsigned len);
        int (*rebuild_header)(struct sk_buff *skb);

        void (*set_multicast_list)(struct net_device *dev);

        int (*set_mac_address)(struct net_device *dev,
                                                   void *addr);

        int (*do_ioctl)(struct net_device *dev,
                                            struct ifreq *ifr, int cmd);

        int (*set_config)(struct net_device *dev,
                                              struct ifmap *map);

        int (*hard_header_cache)(struct neighbour *neigh,
                                                     struct hh_cache *hh);
        void (*header_cache_update)(struct hh_cache *hh,
                                                       struct net_device *dev,
                                                       unsigned char * haddr);

        int (*change_mtu)(struct net_device *dev, int new_mtu);


        void (*tx_timeout) (struct net_device *dev);

        void (*vlan_rx_register)(struct net_device *dev,
                                                    struct vlan_group *grp);
        void (*vlan_rx_add_vid)(struct net_device *dev,
                                                   unsigned short vid);
        void (*vlan_rx_kill_vid)(struct net_device *dev,
                                                    unsigned short vid);

        int (*hard_header_parse)(struct sk_buff *skb,
                                                     unsigned char *haddr);
        int (*neigh_setup)(struct net_device *dev, struct neigh_parms *);

        struct netpoll_info *npinfo;


        void (*poll_controller)(struct net_device *dev);



        struct net_bridge_port *br_port;



        struct divert_blk *divert;



        struct class_device class_dev;
};




static inline __attribute__((always_inline)) void *netdev_priv(struct net_device *dev)
{
        return (char *)dev + ((sizeof(struct net_device)
                                        + (32 - 1))
                                & ~(32 - 1));
}







struct packet_type {
        __be16 type;
        struct net_device *dev;
        int (*func) (struct sk_buff *,
                                         struct net_device *,
                                         struct packet_type *,
                                         struct net_device *);
        void *af_packet_priv;
        struct list_head list;
};


# 1 "include/linux/notifier.h" 1
# 14 "include/linux/notifier.h"
struct notifier_block
{
        int (*notifier_call)(struct notifier_block *self, unsigned long, void *);
        struct notifier_block *next;
        int priority;
};




extern int notifier_chain_register(struct notifier_block **list, struct notifier_block *n);
extern int notifier_chain_unregister(struct notifier_block **nl, struct notifier_block *n);
extern int notifier_call_chain(struct notifier_block **n, unsigned long val, void *v);
# 535 "include/linux/netdevice.h" 2

extern struct net_device loopback_dev;
extern struct net_device *dev_base;
extern rwlock_t dev_base_lock;

extern int netdev_boot_setup_check(struct net_device *dev);
extern unsigned long netdev_boot_base(const char *prefix, int unit);
extern struct net_device *dev_getbyhwaddr(unsigned short type, char *hwaddr);
extern struct net_device *dev_getfirstbyhwtype(unsigned short type);
extern void dev_add_pack(struct packet_type *pt);
extern void dev_remove_pack(struct packet_type *pt);
extern void __dev_remove_pack(struct packet_type *pt);

extern struct net_device *dev_get_by_flags(unsigned short flags,
                                                  unsigned short mask);
extern struct net_device *dev_get_by_name(const char *name);
extern struct net_device *__dev_get_by_name(const char *name);
extern int dev_alloc_name(struct net_device *dev, const char *name);
extern int dev_open(struct net_device *dev);
extern int dev_close(struct net_device *dev);
extern int dev_queue_xmit(struct sk_buff *skb);
extern int register_netdevice(struct net_device *dev);
extern int unregister_netdevice(struct net_device *dev);
extern void free_netdev(struct net_device *dev);
extern void synchronize_net(void);
extern int register_netdevice_notifier(struct notifier_block *nb);
extern int unregister_netdevice_notifier(struct notifier_block *nb);
extern int call_netdevice_notifiers(unsigned long val, void *v);
extern struct net_device *dev_get_by_index(int ifindex);
extern struct net_device *__dev_get_by_index(int ifindex);
extern int dev_restart(struct net_device *dev);

extern int netpoll_trap(void);


typedef int gifconf_func_t(struct net_device * dev, char * bufptr, int len);
extern int register_gifconf(unsigned int family, gifconf_func_t * gifconf);
static inline __attribute__((always_inline)) int unregister_gifconf(unsigned int family)
{
        return register_gifconf(family, ((void *)0));
}






struct softnet_data
{
        struct net_device *output_queue;
        struct sk_buff_head input_pkt_queue;
        struct list_head poll_list;
        struct sk_buff *completion_queue;

        struct net_device backlog_dev;
};

extern __typeof__(struct softnet_data) per_cpu__softnet_data;



static inline __attribute__((always_inline)) void __netif_schedule(struct net_device *dev)
{
        if (!test_and_set_bit(__LINK_STATE_SCHED, &dev->state)) {
                unsigned long flags;
                struct softnet_data *sd;

                __asm__ __volatile__("pushfl ; popl %0 ; cli":"=g" (flags): :"memory");
                sd = &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__softnet_data)); (typeof(&per_cpu__softnet_data)) (__ptr + (__per_cpu_offset[(current_thread_info()->cpu)])); }));
                dev->next_sched = sd->output_queue;
                sd->output_queue = dev;
                raise_softirq_irqoff(NET_TX_SOFTIRQ);
                do { ({ unsigned long __dummy; typeof(flags) __dummy2; (void)(&__dummy == &__dummy2); 1; }); __asm__ __volatile__("pushl %0 ; popfl": :"g" (flags):"memory", "cc"); } while (0);
        }
}

static inline __attribute__((always_inline)) void netif_schedule(struct net_device *dev)
{
        if (!(__builtin_constant_p(__LINK_STATE_XOFF) ? constant_test_bit((__LINK_STATE_XOFF),(&dev->state)) : variable_test_bit((__LINK_STATE_XOFF),(&dev->state))))
                __netif_schedule(dev);
}

static inline __attribute__((always_inline)) void netif_start_queue(struct net_device *dev)
{
        clear_bit(__LINK_STATE_XOFF, &dev->state);
}

static inline __attribute__((always_inline)) void netif_wake_queue(struct net_device *dev)
{

        if (netpoll_trap())
                return;

        if (test_and_clear_bit(__LINK_STATE_XOFF, &dev->state))
                __netif_schedule(dev);
}

static inline __attribute__((always_inline)) void netif_stop_queue(struct net_device *dev)
{

        if (netpoll_trap())
                return;

        set_bit(__LINK_STATE_XOFF, &dev->state);
}

static inline __attribute__((always_inline)) int netif_queue_stopped(const struct net_device *dev)
{
        return (__builtin_constant_p(__LINK_STATE_XOFF) ? constant_test_bit((__LINK_STATE_XOFF),(&dev->state)) : variable_test_bit((__LINK_STATE_XOFF),(&dev->state)));
}

static inline __attribute__((always_inline)) int netif_running(const struct net_device *dev)
{
        return (__builtin_constant_p(__LINK_STATE_START) ? constant_test_bit((__LINK_STATE_START),(&dev->state)) : variable_test_bit((__LINK_STATE_START),(&dev->state)));
}





static inline __attribute__((always_inline)) void dev_kfree_skb_irq(struct sk_buff *skb)
{
        if (atomic_dec_and_test(&skb->users)) {
                struct softnet_data *sd;
                unsigned long flags;

                __asm__ __volatile__("pushfl ; popl %0 ; cli":"=g" (flags): :"memory");
                sd = &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__softnet_data)); (typeof(&per_cpu__softnet_data)) (__ptr + (__per_cpu_offset[(current_thread_info()->cpu)])); }));
                skb->next = sd->completion_queue;
                sd->completion_queue = skb;
                raise_softirq_irqoff(NET_TX_SOFTIRQ);
                do { ({ unsigned long __dummy; typeof(flags) __dummy2; (void)(&__dummy == &__dummy2); 1; }); __asm__ __volatile__("pushl %0 ; popfl": :"g" (flags):"memory", "cc"); } while (0);
        }
}




static inline __attribute__((always_inline)) void dev_kfree_skb_any(struct sk_buff *skb)
{
        if ((((current_thread_info()->preempt_count) & (((1UL << (12))-1) << ((0 + 8) + 8)))) || ({ unsigned long flags; do { ({ unsigned long __dummy; typeof(flags) __dummy2; (void)(&__dummy == &__dummy2); 1; }); __asm__ __volatile__("pushfl ; popl %0":"=g" (flags): ); } while (0); !(flags & (1<<9)); }))
                dev_kfree_skb_irq(skb);
        else
                kfree_skb(skb);
}


extern int netif_rx(struct sk_buff *skb);
extern int netif_rx_ni(struct sk_buff *skb);

extern int netif_receive_skb(struct sk_buff *skb);
extern int dev_ioctl(unsigned int cmd, void *);
extern int dev_ethtool(struct ifreq *);
extern unsigned dev_get_flags(const struct net_device *);
extern int dev_change_flags(struct net_device *, unsigned);
extern int dev_change_name(struct net_device *, char *);
extern int dev_set_mtu(struct net_device *, int);
extern int dev_set_mac_address(struct net_device *,
                                            struct sockaddr *);
extern void dev_queue_xmit_nit(struct sk_buff *skb, struct net_device *dev);

extern void dev_init(void);

extern int netdev_nit;
extern int netdev_budget;


extern void netdev_run_todo(void);

static inline __attribute__((always_inline)) void dev_put(struct net_device *dev)
{
        atomic_dec(&dev->refcnt);
}
# 717 "include/linux/netdevice.h"
extern void linkwatch_fire_event(struct net_device *dev);

static inline __attribute__((always_inline)) int netif_carrier_ok(const struct net_device *dev)
{
        return !(__builtin_constant_p(__LINK_STATE_NOCARRIER) ? constant_test_bit((__LINK_STATE_NOCARRIER),(&dev->state)) : variable_test_bit((__LINK_STATE_NOCARRIER),(&dev->state)));
}

extern void __netdev_watchdog_up(struct net_device *dev);

extern void netif_carrier_on(struct net_device *dev);

extern void netif_carrier_off(struct net_device *dev);


static inline __attribute__((always_inline)) int netif_device_present(struct net_device *dev)
{
        return (__builtin_constant_p(__LINK_STATE_PRESENT) ? constant_test_bit((__LINK_STATE_PRESENT),(&dev->state)) : variable_test_bit((__LINK_STATE_PRESENT),(&dev->state)));
}

static inline __attribute__((always_inline)) void netif_device_detach(struct net_device *dev)
{
        if (test_and_clear_bit(__LINK_STATE_PRESENT, &dev->state) &&
            netif_running(dev)) {
                netif_stop_queue(dev);
        }
}

static inline __attribute__((always_inline)) void netif_device_attach(struct net_device *dev)
{
        if (!test_and_set_bit(__LINK_STATE_PRESENT, &dev->state) &&
            netif_running(dev)) {
                netif_wake_queue(dev);
                __netdev_watchdog_up(dev);
        }
}






enum {
        NETIF_MSG_DRV = 0x0001,
        NETIF_MSG_PROBE = 0x0002,
        NETIF_MSG_LINK = 0x0004,
        NETIF_MSG_TIMER = 0x0008,
        NETIF_MSG_IFDOWN = 0x0010,
        NETIF_MSG_IFUP = 0x0020,
        NETIF_MSG_RX_ERR = 0x0040,
        NETIF_MSG_TX_ERR = 0x0080,
        NETIF_MSG_TX_QUEUED = 0x0100,
        NETIF_MSG_INTR = 0x0200,
        NETIF_MSG_TX_DONE = 0x0400,
        NETIF_MSG_RX_STATUS = 0x0800,
        NETIF_MSG_PKTDATA = 0x1000,
        NETIF_MSG_HW = 0x2000,
        NETIF_MSG_WOL = 0x4000,
};
# 792 "include/linux/netdevice.h"
static inline __attribute__((always_inline)) u32 netif_msg_init(int debug_value, int default_msg_enable_bits)
{

        if (debug_value < 0 || debug_value >= (sizeof(u32) * 8))
                return default_msg_enable_bits;
        if (debug_value == 0)
                return 0;

        return (1 << debug_value) - 1;
}



static inline __attribute__((always_inline)) int netif_rx_schedule_prep(struct net_device *dev)
{
        return netif_running(dev) &&
                !test_and_set_bit(__LINK_STATE_RX_SCHED, &dev->state);
}





static inline __attribute__((always_inline)) void __netif_rx_schedule(struct net_device *dev)
{
        unsigned long flags;

        __asm__ __volatile__("pushfl ; popl %0 ; cli":"=g" (flags): :"memory");
        atomic_inc(&(dev)->refcnt);
        list_add_tail(&dev->poll_list, &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__softnet_data)); (typeof(&per_cpu__softnet_data)) (__ptr + (__per_cpu_offset[(current_thread_info()->cpu)])); })).poll_list);
        if (dev->quota < 0)
                dev->quota += dev->weight;
        else
                dev->quota = dev->weight;
        do { (((*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__irq_stat)); (typeof(&per_cpu__irq_stat)) (__ptr + (__per_cpu_offset[(current_thread_info()->cpu)])); })).__softirq_pending) |= (1UL << (NET_RX_SOFTIRQ))); } while (0);
        do { ({ unsigned long __dummy; typeof(flags) __dummy2; (void)(&__dummy == &__dummy2); 1; }); __asm__ __volatile__("pushl %0 ; popfl": :"g" (flags):"memory", "cc"); } while (0);
}



static inline __attribute__((always_inline)) void netif_rx_schedule(struct net_device *dev)
{
        if (netif_rx_schedule_prep(dev))
                __netif_rx_schedule(dev);
}




static inline __attribute__((always_inline)) int netif_rx_reschedule(struct net_device *dev, int undo)
{
        if (netif_rx_schedule_prep(dev)) {
                unsigned long flags;

                dev->quota += undo;

                __asm__ __volatile__("pushfl ; popl %0 ; cli":"=g" (flags): :"memory");
                list_add_tail(&dev->poll_list, &(*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__softnet_data)); (typeof(&per_cpu__softnet_data)) (__ptr + (__per_cpu_offset[(current_thread_info()->cpu)])); })).poll_list);
                do { (((*({ unsigned long __ptr; __asm__ ("" : "=g"(__ptr) : "0"(&per_cpu__irq_stat)); (typeof(&per_cpu__irq_stat)) (__ptr + (__per_cpu_offset[(current_thread_info()->cpu)])); })).__softirq_pending) |= (1UL << (NET_RX_SOFTIRQ))); } while (0);
                do { ({ unsigned long __dummy; typeof(flags) __dummy2; (void)(&__dummy == &__dummy2); 1; }); __asm__ __volatile__("pushl %0 ; popfl": :"g" (flags):"memory", "cc"); } while (0);
                return 1;
        }
        return 0;
}






static inline __attribute__((always_inline)) void netif_rx_complete(struct net_device *dev)
{
        unsigned long flags;

        __asm__ __volatile__("pushfl ; popl %0 ; cli":"=g" (flags): :"memory");
        do { if (__builtin_expect(!!((!(__builtin_constant_p(__LINK_STATE_RX_SCHED) ? constant_test_bit((__LINK_STATE_RX_SCHED),(&dev->state)) : variable_test_bit((__LINK_STATE_RX_SCHED),(&dev->state))))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (867), "i" ("include/linux/netdevice.h")); } while(0);
        list_del(&dev->poll_list);
        __asm__ __volatile__("": : :"memory");
        clear_bit(__LINK_STATE_RX_SCHED, &dev->state);
        do { ({ unsigned long __dummy; typeof(flags) __dummy2; (void)(&__dummy == &__dummy2); 1; }); __asm__ __volatile__("pushl %0 ; popfl": :"g" (flags):"memory", "cc"); } while (0);
}

static inline __attribute__((always_inline)) void netif_poll_disable(struct net_device *dev)
{
        while (test_and_set_bit(__LINK_STATE_RX_SCHED, &dev->state)) {

                get_current()->state = 1;
                schedule_timeout(1);
        }
}

static inline __attribute__((always_inline)) void netif_poll_enable(struct net_device *dev)
{
        clear_bit(__LINK_STATE_RX_SCHED, &dev->state);
}




static inline __attribute__((always_inline)) void __netif_rx_complete(struct net_device *dev)
{
        do { if (__builtin_expect(!!((!(__builtin_constant_p(__LINK_STATE_RX_SCHED) ? constant_test_bit((__LINK_STATE_RX_SCHED),(&dev->state)) : variable_test_bit((__LINK_STATE_RX_SCHED),(&dev->state))))!=0), 0)) __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (893), "i" ("include/linux/netdevice.h")); } while(0);
        list_del(&dev->poll_list);
        __asm__ __volatile__("": : :"memory");
        clear_bit(__LINK_STATE_RX_SCHED, &dev->state);
}

static inline __attribute__((always_inline)) void netif_tx_disable(struct net_device *dev)
{
        _spin_lock_bh(&dev->xmit_lock);
        netif_stop_queue(dev);
        _spin_unlock_bh(&dev->xmit_lock);
}



extern void ether_setup(struct net_device *dev);


extern struct net_device *alloc_netdev(int sizeof_priv, const char *name,
                                       void (*setup)(struct net_device *));
extern int register_netdev(struct net_device *dev);
extern void unregister_netdev(struct net_device *dev);

extern void dev_mc_upload(struct net_device *dev);
extern int dev_mc_delete(struct net_device *dev, void *addr, int alen, int all);
extern int dev_mc_add(struct net_device *dev, void *addr, int alen, int newonly);
extern void dev_mc_discard(struct net_device *dev);
extern void dev_set_promiscuity(struct net_device *dev, int inc);
extern void dev_set_allmulti(struct net_device *dev, int inc);
extern void netdev_state_change(struct net_device *dev);
extern void netdev_features_change(struct net_device *dev);

extern void dev_load(const char *name);
extern void dev_mcast_init(void);
extern int netdev_max_backlog;
extern int weight_p;
extern int netdev_set_master(struct net_device *dev, struct net_device *master);
extern int skb_checksum_help(struct sk_buff *skb, int inward);

extern void net_enable_timestamp(void);
extern void net_disable_timestamp(void);


extern void *dev_seq_start(struct seq_file *seq, loff_t *pos);
extern void *dev_seq_next(struct seq_file *seq, void *v, loff_t *pos);
extern void dev_seq_stop(struct seq_file *seq, void *v);


extern void linkwatch_run_queue(void);
# 123 "drivers/net/yellowfin.c" 2
# 1 "include/linux/etherdevice.h" 1
# 29 "include/linux/etherdevice.h"
# 1 "include/linux/random.h" 1
# 35 "include/linux/random.h"
struct rand_pool_info {
        int entropy_count;
        int buf_size;
        __u32 buf[0];
};





extern void rand_initialize_irq(int irq);

extern void add_input_randomness(unsigned int type, unsigned int code,
                                 unsigned int value);
extern void add_interrupt_randomness(int irq);

extern void get_random_bytes(void *buf, int nbytes);
void generate_random_uuid(unsigned char uuid_out[16]);

extern __u32 secure_ip_id(__u32 daddr);
extern u32 secure_tcp_port_ephemeral(__u32 saddr, __u32 daddr, __u16 dport);
extern u32 secure_tcpv6_port_ephemeral(const __u32 *saddr, const __u32 *daddr,
                                       __u16 dport);
extern __u32 secure_tcp_sequence_number(__u32 saddr, __u32 daddr,
                                        __u16 sport, __u16 dport);
extern __u32 secure_tcpv6_sequence_number(__u32 *saddr, __u32 *daddr,
                                          __u16 sport, __u16 dport);
extern u64 secure_dccp_sequence_number(__u32 saddr, __u32 daddr,
                                       __u16 sport, __u16 dport);


extern struct file_operations random_fops, urandom_fops;


unsigned int get_random_int(void);
unsigned long randomize_range(unsigned long start, unsigned long end, unsigned long len);
# 30 "include/linux/etherdevice.h" 2


extern int eth_header(struct sk_buff *skb, struct net_device *dev,
                                   unsigned short type, void *daddr,
                                   void *saddr, unsigned len);
extern int eth_rebuild_header(struct sk_buff *skb);
extern __be16 eth_type_trans(struct sk_buff *skb, struct net_device *dev);
extern void eth_header_cache_update(struct hh_cache *hh, struct net_device *dev,
                                                unsigned char * haddr);
extern int eth_header_cache(struct neighbour *neigh,
                                         struct hh_cache *hh);

extern struct net_device *alloc_etherdev(int sizeof_priv);
static inline __attribute__((always_inline)) void eth_copy_and_sum (struct sk_buff *dest,
                                     const unsigned char *src,
                                     int len, int base)
{
        (__builtin_constant_p(len) ? __constant_memcpy((dest->data),(src),(len)) : __memcpy((dest->data),(src),(len)));
}





static inline __attribute__((always_inline)) int is_zero_ether_addr(const u8 *addr)
{
        return !(addr[0] | addr[1] | addr[2] | addr[3] | addr[4] | addr[5]);
}
# 67 "include/linux/etherdevice.h"
static inline __attribute__((always_inline)) int is_multicast_ether_addr(const u8 *addr)
{
        return ((addr[0] != 0xff) && (0x01 & addr[0]));
}

static inline __attribute__((always_inline)) int is_broadcast_ether_addr(const u8 *addr)
{
        return ((addr[0] == 0xff) && (addr[1] == 0xff) && (addr[2] == 0xff) &&
                (addr[3] == 0xff) && (addr[4] == 0xff) && (addr[5] == 0xff));
}
# 87 "include/linux/etherdevice.h"
static inline __attribute__((always_inline)) int is_valid_ether_addr(const u8 *addr)
{


        return !is_multicast_ether_addr(addr) && !is_zero_ether_addr(addr);
}
# 101 "include/linux/etherdevice.h"
static inline __attribute__((always_inline)) void random_ether_addr(u8 *addr)
{
        get_random_bytes (addr, 6);
        addr [0] &= 0xfe;
        addr [0] |= 0x02;
}
# 124 "drivers/net/yellowfin.c" 2

# 1 "include/linux/ethtool.h" 1
# 17 "include/linux/ethtool.h"
struct ethtool_cmd {
        u32 cmd;
        u32 supported;
        u32 advertising;
        u16 speed;
        u8 duplex;
        u8 port;
        u8 phy_address;
        u8 transceiver;
        u8 autoneg;
        u32 maxtxpkt;
        u32 maxrxpkt;
        u32 reserved[4];
};



struct ethtool_drvinfo {
        u32 cmd;
        char driver[32];
        char version[32];
        char fw_version[32];
        char bus_info[32];

        char reserved1[32];
        char reserved2[16];
        u32 n_stats;
        u32 testinfo_len;
        u32 eedump_len;
        u32 regdump_len;
};



struct ethtool_wolinfo {
        u32 cmd;
        u32 supported;
        u32 wolopts;
        u8 sopass[6];
};


struct ethtool_value {
        u32 cmd;
        u32 data;
};


struct ethtool_regs {
        u32 cmd;
        u32 version;
        u32 len;
        u8 data[0];
};


struct ethtool_eeprom {
        u32 cmd;
        u32 magic;
        u32 offset;
        u32 len;
        u8 data[0];
};


struct ethtool_coalesce {
        u32 cmd;





        u32 rx_coalesce_usecs;







        u32 rx_max_coalesced_frames;






        u32 rx_coalesce_usecs_irq;
        u32 rx_max_coalesced_frames_irq;





        u32 tx_coalesce_usecs;







        u32 tx_max_coalesced_frames;






        u32 tx_coalesce_usecs_irq;
        u32 tx_max_coalesced_frames_irq;






        u32 stats_block_coalesce_usecs;
# 143 "include/linux/ethtool.h"
        u32 use_adaptive_rx_coalesce;
        u32 use_adaptive_tx_coalesce;





        u32 pkt_rate_low;
        u32 rx_coalesce_usecs_low;
        u32 rx_max_coalesced_frames_low;
        u32 tx_coalesce_usecs_low;
        u32 tx_max_coalesced_frames_low;
# 165 "include/linux/ethtool.h"
        u32 pkt_rate_high;
        u32 rx_coalesce_usecs_high;
        u32 rx_max_coalesced_frames_high;
        u32 tx_coalesce_usecs_high;
        u32 tx_max_coalesced_frames_high;




        u32 rate_sample_interval;
};


struct ethtool_ringparam {
        u32 cmd;





        u32 rx_max_pending;
        u32 rx_mini_max_pending;
        u32 rx_jumbo_max_pending;
        u32 tx_max_pending;




        u32 rx_pending;
        u32 rx_mini_pending;
        u32 rx_jumbo_pending;
        u32 tx_pending;
};


struct ethtool_pauseparam {
        u32 cmd;
# 213 "include/linux/ethtool.h"
        u32 autoneg;
        u32 rx_pause;
        u32 tx_pause;
};


enum ethtool_stringset {
        ETH_SS_TEST = 0,
        ETH_SS_STATS,
};


struct ethtool_gstrings {
        u32 cmd;
        u32 string_set;
        u32 len;
        u8 data[0];
};

enum ethtool_test_flags {
        ETH_TEST_FL_OFFLINE = (1 << 0),
        ETH_TEST_FL_FAILED = (1 << 1),
};


struct ethtool_test {
        u32 cmd;
        u32 flags;
        u32 reserved;
        u32 len;
        u64 data[0];
};


struct ethtool_stats {
        u32 cmd;
        u32 n_stats;
        u64 data[0];
};

struct ethtool_perm_addr {
        u32 cmd;
        u32 size;
        u8 data[0];
};

struct net_device;


u32 ethtool_op_get_link(struct net_device *dev);
u32 ethtool_op_get_tx_csum(struct net_device *dev);
int ethtool_op_set_tx_csum(struct net_device *dev, u32 data);
int ethtool_op_set_tx_hw_csum(struct net_device *dev, u32 data);
u32 ethtool_op_get_sg(struct net_device *dev);
int ethtool_op_set_sg(struct net_device *dev, u32 data);
u32 ethtool_op_get_tso(struct net_device *dev);
int ethtool_op_set_tso(struct net_device *dev, u32 data);
int ethtool_op_get_perm_addr(struct net_device *dev,
                             struct ethtool_perm_addr *addr, u8 *data);
# 329 "include/linux/ethtool.h"
struct ethtool_ops {
        int (*get_settings)(struct net_device *, struct ethtool_cmd *);
        int (*set_settings)(struct net_device *, struct ethtool_cmd *);
        void (*get_drvinfo)(struct net_device *, struct ethtool_drvinfo *);
        int (*get_regs_len)(struct net_device *);
        void (*get_regs)(struct net_device *, struct ethtool_regs *, void *);
        void (*get_wol)(struct net_device *, struct ethtool_wolinfo *);
        int (*set_wol)(struct net_device *, struct ethtool_wolinfo *);
        u32 (*get_msglevel)(struct net_device *);
        void (*set_msglevel)(struct net_device *, u32);
        int (*nway_reset)(struct net_device *);
        u32 (*get_link)(struct net_device *);
        int (*get_eeprom_len)(struct net_device *);
        int (*get_eeprom)(struct net_device *, struct ethtool_eeprom *, u8 *);
        int (*set_eeprom)(struct net_device *, struct ethtool_eeprom *, u8 *);
        int (*get_coalesce)(struct net_device *, struct ethtool_coalesce *);
        int (*set_coalesce)(struct net_device *, struct ethtool_coalesce *);
        void (*get_ringparam)(struct net_device *, struct ethtool_ringparam *);
        int (*set_ringparam)(struct net_device *, struct ethtool_ringparam *);
        void (*get_pauseparam)(struct net_device *, struct ethtool_pauseparam*);
        int (*set_pauseparam)(struct net_device *, struct ethtool_pauseparam*);
        u32 (*get_rx_csum)(struct net_device *);
        int (*set_rx_csum)(struct net_device *, u32);
        u32 (*get_tx_csum)(struct net_device *);
        int (*set_tx_csum)(struct net_device *, u32);
        u32 (*get_sg)(struct net_device *);
        int (*set_sg)(struct net_device *, u32);
        u32 (*get_tso)(struct net_device *);
        int (*set_tso)(struct net_device *, u32);
        int (*self_test_count)(struct net_device *);
        void (*self_test)(struct net_device *, struct ethtool_test *, u64 *);
        void (*get_strings)(struct net_device *, u32 stringset, u8 *);
        int (*phys_id)(struct net_device *, u32);
        int (*get_stats_count)(struct net_device *);
        void (*get_ethtool_stats)(struct net_device *, struct ethtool_stats *, u64 *);
        int (*get_perm_addr)(struct net_device *, struct ethtool_perm_addr *, u8 *);
        int (*begin)(struct net_device *);
        void (*complete)(struct net_device *);
};
# 126 "drivers/net/yellowfin.c" 2
# 1 "include/linux/crc32.h" 1
# 10 "include/linux/crc32.h"
extern u32 crc32_le(u32 crc, unsigned char const *p, size_t len);
extern u32 crc32_be(u32 crc, unsigned char const *p, size_t len);
extern u32 bitreverse(u32 in);
# 127 "drivers/net/yellowfin.c" 2



# 1 "include/asm/unaligned.h" 1
# 131 "drivers/net/yellowfin.c" 2



static char version[] =
"<6>" "yellowfin" ".c:v1.05  1/09/2001  Written by Donald Becker <becker@scyld.com>\n"
"<6>" "  http://www.scyld.com/network/yellowfin.html\n"
"<6>" "  (unofficial 2.4.x port, " "1.05+LK1.1.6" ", " "Feb 11, 2002" ")\n";

;
;
;

static inline __attribute__((always_inline)) int *__check_max_interrupt_work(void) { return(&(max_interrupt_work)); }; static char __param_str_max_interrupt_work[] = "yellowfin" "." "max_interrupt_work"; static struct kernel_param const __param_max_interrupt_work __attribute__((__unused__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_max_interrupt_work, 0, param_set_int, param_get_int, &max_interrupt_work }; ;
static inline __attribute__((always_inline)) int *__check_mtu(void) { return(&(mtu)); }; static char __param_str_mtu[] = "yellowfin" "." "mtu"; static struct kernel_param const __param_mtu __attribute__((__unused__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_mtu, 0, param_set_int, param_get_int, &mtu }; ;
static inline __attribute__((always_inline)) int *__check_debug(void) { return(&(debug)); }; static char __param_str_debug[] = "yellowfin" "." "debug"; static struct kernel_param const __param_debug __attribute__((__unused__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_debug, 0, param_set_int, param_get_int, &debug }; ;
static inline __attribute__((always_inline)) int *__check_rx_copybreak(void) { return(&(rx_copybreak)); }; static char __param_str_rx_copybreak[] = "yellowfin" "." "rx_copybreak"; static struct kernel_param const __param_rx_copybreak __attribute__((__unused__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_rx_copybreak, 0, param_set_int, param_get_int, &rx_copybreak }; ;
static struct kparam_array __param_arr_options = { (sizeof(options) / sizeof((options)[0])), ((void *)0), param_set_int, param_get_int, sizeof(options[0]), options }; static char __param_str_options[] = "yellowfin" "." "options"; static struct kernel_param const __param_options __attribute__((__unused__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_options, 0, param_array_set, param_array_get, &__param_arr_options }; ;
static struct kparam_array __param_arr_full_duplex = { (sizeof(full_duplex) / sizeof((full_duplex)[0])), ((void *)0), param_set_int, param_get_int, sizeof(full_duplex[0]), full_duplex }; static char __param_str_full_duplex[] = "yellowfin" "." "full_duplex"; static struct kernel_param const __param_full_duplex __attribute__((__unused__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_full_duplex, 0, param_array_set, param_array_get, &__param_arr_full_duplex }; ;
static inline __attribute__((always_inline)) int *__check_gx_fix(void) { return(&(gx_fix)); }; static char __param_str_gx_fix[] = "yellowfin" "." "gx_fix"; static struct kernel_param const __param_gx_fix __attribute__((__unused__)) __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_gx_fix, 0, param_set_int, param_get_int, &gx_fix }; ;
;
;
;
;
;
;
;
# 237 "drivers/net/yellowfin.c"
enum pci_id_flags_bits {

        PCI_USES_IO=1, PCI_USES_MEM=2, PCI_USES_MASTER=4,

        PCI_ADDR0=0<<4, PCI_ADDR1=1<<4, PCI_ADDR2=2<<4, PCI_ADDR3=3<<4,
        PCI_ADDR_64BITS=0x100, PCI_NO_ACPI_WAKE=0x200, PCI_NO_MIN_LATENCY=0x400,
        PCI_UNUSED_IRQ=0x800,
};
enum capability_flags {
        HasMII=1, FullTxStatus=2, IsGigabit=4, HasMulticastBug=8, FullRxStatus=16,
        HasMACAddrBug=32,
        DontUseEeprom=64,
};
# 258 "drivers/net/yellowfin.c"
struct pci_id_info {
        const char *name;
        struct match_info {
                int pci, pci_mask, subsystem, subsystem_mask;
                int revision, revision_mask;
        } id;
        enum pci_id_flags_bits pci_flags;
        int io_size;
        int drv_flags;
};

static struct pci_id_info pci_id_tbl[] = {
        {"Yellowfin G-NIC Gigabit Ethernet", { 0x07021000, 0xffffffff},
         (PCI_USES_MASTER | PCI_USES_MEM | PCI_ADDR1), 0x100,
         FullTxStatus | IsGigabit | HasMulticastBug | HasMACAddrBug | DontUseEeprom},
        {"Symbios SYM83C885", { 0x07011000, 0xffffffff},
         (PCI_USES_MASTER | PCI_USES_MEM | PCI_ADDR1), 0x100, HasMII | DontUseEeprom },
        {((void *)0),},
};

static struct pci_device_id yellowfin_pci_tbl[] = {
        { 0x1000, 0x0702, (~0), (~0), 0, 0, 0 },
        { 0x1000, 0x0701, (~0), (~0), 0, 0, 1 },
        { 0, }
};
;



enum yellowfin_offsets {
        TxCtrl=0x00, TxStatus=0x04, TxPtr=0x0C,
        TxIntrSel=0x10, TxBranchSel=0x14, TxWaitSel=0x18,
        RxCtrl=0x40, RxStatus=0x44, RxPtr=0x4C,
        RxIntrSel=0x50, RxBranchSel=0x54, RxWaitSel=0x58,
        EventStatus=0x80, IntrEnb=0x82, IntrClear=0x84, IntrStatus=0x86,
        ChipRev=0x8C, DMACtrl=0x90, TxThreshold=0x94,
        Cnfg=0xA0, FrameGap0=0xA2, FrameGap1=0xA4,
        MII_Cmd=0xA6, MII_Addr=0xA8, MII_Wr_Data=0xAA, MII_Rd_Data=0xAC,
        MII_Status=0xAE,
        RxDepth=0xB8, FlowCtrl=0xBC,
        AddrMode=0xD0, StnAddr=0xD2, HashTbl=0xD8, FIFOcfg=0xF8,
        EEStatus=0xF0, EECtrl=0xF1, EEAddr=0xF2, EERead=0xF3, EEWrite=0xF4,
        EEFeature=0xF5,
};



struct yellowfin_desc {
        u32 dbdma_cmd;
        u32 addr;
        u32 branch_addr;
        u32 result_status;
};

struct tx_status_words {






        u16 tx_cnt;
        u16 tx_errs;
        u16 total_tx_cnt;
        u16 paused;

};


enum desc_cmd_bits {
        CMD_TX_PKT=0x10000000, CMD_RX_BUF=0x20000000, CMD_TXSTATUS=0x30000000,
        CMD_NOP=0x60000000, CMD_STOP=0x70000000,
        BRANCH_ALWAYS=0x0C0000, INTR_ALWAYS=0x300000, WAIT_ALWAYS=0x030000,
        BRANCH_IFTRUE=0x040000,
};


enum desc_status_bits { RX_EOP=0x0040, };


enum intr_status_bits {
        IntrRxDone=0x01, IntrRxInvalid=0x02, IntrRxPCIFault=0x04,IntrRxPCIErr=0x08,
        IntrTxDone=0x10, IntrTxInvalid=0x20, IntrTxPCIFault=0x40,IntrTxPCIErr=0x80,
        IntrEarlyRx=0x100, IntrWakeup=0x200, };



struct yellowfin_private {


        struct yellowfin_desc *rx_ring;
        struct yellowfin_desc *tx_ring;
        struct sk_buff* rx_skbuff[64];
        struct sk_buff* tx_skbuff[16];
        dma_addr_t rx_ring_dma;
        dma_addr_t tx_ring_dma;

        struct tx_status_words *tx_status;
        dma_addr_t tx_status_dma;

        struct timer_list timer;
        struct net_device_stats stats;

        int chip_id, drv_flags;
        struct pci_dev *pci_dev;
        unsigned int cur_rx, dirty_rx;
        unsigned int rx_buf_sz;
        struct tx_status_words *tx_tail_desc;
        unsigned int cur_tx, dirty_tx;
        int tx_threshold;
        unsigned int tx_full:1;
        unsigned int full_duplex:1;
        unsigned int duplex_lock:1;
        unsigned int medialock:1;
        unsigned int default_port:4;

        int mii_cnt;
        u16 advertising;
        unsigned char phys[4];
        spinlock_t lock;
        void *base;
};

static int read_eeprom(void *ioaddr, int location);
static int mdio_read(void *ioaddr, int phy_id, int location);
static void mdio_write(void *ioaddr, int phy_id, int location, int value);
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd);
static int yellowfin_open(struct net_device *dev);
static void yellowfin_timer(unsigned long data);
static void yellowfin_tx_timeout(struct net_device *dev);
static void yellowfin_init_ring(struct net_device *dev);
static int yellowfin_start_xmit(struct sk_buff *skb, struct net_device *dev);
static irqreturn_t yellowfin_interrupt(int irq, void *dev_instance, struct pt_regs *regs);
static int yellowfin_rx(struct net_device *dev);
static void yellowfin_error(struct net_device *dev, int intr_status);
static int yellowfin_close(struct net_device *dev);
static struct net_device_stats *yellowfin_get_stats(struct net_device *dev);
static void set_rx_mode(struct net_device *dev);
static struct ethtool_ops ethtool_ops;


static int yellowfin_init_one(struct pci_dev *pdev,
                                        const struct pci_device_id *ent)
{
        struct net_device *dev;
        struct yellowfin_private *np;
        int irq;
        int chip_idx = ent->driver_data;
        static int find_cnt;
        void *ioaddr;
        int i, option = find_cnt < 8 ? options[find_cnt] : 0;
        int drv_flags = pci_id_tbl[chip_idx].drv_flags;
        void *ring_space;
        dma_addr_t ring_dma;



        int bar = 1;




        static int printed_version;
        if (!printed_version++)
                printk(version);


        i = pci_enable_device(pdev);
        if (i) return i;

        dev = alloc_etherdev(sizeof(*np));
        if (!dev) {
                printk ("<3>" "yellowfin" ": " "cannot allocate ethernet device\n");
                return -12;
        }
        do { } while (0);
        ((dev)->class_dev.dev = (&pdev->dev));

        np = netdev_priv(dev);

        if (pci_request_regions(pdev, "yellowfin"))
                goto err_out_free_netdev;

        pci_set_master (pdev);

        ioaddr = pci_iomap(pdev, bar, 0x100);
        if (!ioaddr)
                goto err_out_free_res;

        irq = pdev->irq;

        if (drv_flags & DontUseEeprom)
                for (i = 0; i < 6; i++)
                        dev->dev_addr[i] = ioread8(ioaddr + StnAddr + i);
        else {
                int ee_offset = (read_eeprom(ioaddr, 6) == 0xff ? 0x100 : 0);
                for (i = 0; i < 6; i++)
                        dev->dev_addr[i] = read_eeprom(ioaddr, ee_offset + i);
        }


        iowrite32(0x80000000, ioaddr + DMACtrl);

        dev->base_addr = (unsigned long)ioaddr;
        dev->irq = irq;

        pci_set_drvdata(pdev, dev);
        spin_lock_init(&np->lock);

        np->pci_dev = pdev;
        np->chip_id = chip_idx;
        np->drv_flags = drv_flags;
        np->base = ioaddr;

        ring_space = pci_alloc_consistent(pdev, 2*16*sizeof(struct yellowfin_desc), &ring_dma);
        if (!ring_space)
                goto err_out_cleardev;
        np->tx_ring = (struct yellowfin_desc *)ring_space;
        np->tx_ring_dma = ring_dma;

        ring_space = pci_alloc_consistent(pdev, 64*sizeof(struct yellowfin_desc), &ring_dma);
        if (!ring_space)
                goto err_out_unmap_tx;
        np->rx_ring = (struct yellowfin_desc *)ring_space;
        np->rx_ring_dma = ring_dma;

        ring_space = pci_alloc_consistent(pdev, 16*sizeof(struct tx_status_words), &ring_dma);
        if (!ring_space)
                goto err_out_unmap_rx;
        np->tx_status = (struct tx_status_words *)ring_space;
        np->tx_status_dma = ring_dma;

        if (dev->mem_start)
                option = dev->mem_start;


        if (option > 0) {
                if (option & 0x200)
                        np->full_duplex = 1;
                np->default_port = option & 15;
                if (np->default_port)
                        np->medialock = 1;
        }
        if (find_cnt < 8 && full_duplex[find_cnt] > 0)
                np->full_duplex = 1;

        if (np->full_duplex)
                np->duplex_lock = 1;


        dev->open = &yellowfin_open;
        dev->hard_start_xmit = &yellowfin_start_xmit;
        dev->stop = &yellowfin_close;
        dev->get_stats = &yellowfin_get_stats;
        dev->set_multicast_list = &set_rx_mode;
        dev->do_ioctl = &netdev_ioctl;
        ( (dev)->ethtool_ops = (&ethtool_ops) );
        dev->tx_timeout = yellowfin_tx_timeout;
        dev->watchdog_timeo = (2*250);

        if (mtu)
                dev->mtu = mtu;

        i = register_netdev(dev);
        if (i)
                goto err_out_unmap_status;

        printk("<6>" "%s: %s type %8x at %p, ",
                   dev->name, pci_id_tbl[chip_idx].name,
                   ioread32(ioaddr + ChipRev), ioaddr);
        for (i = 0; i < 5; i++)
                        printk("%2.2x:", dev->dev_addr[i]);
        printk("%2.2x, IRQ %d.\n", dev->dev_addr[i], irq);

        if (np->drv_flags & HasMII) {
                int phy, phy_idx = 0;
                for (phy = 0; phy < 32 && phy_idx < 4; phy++) {
                        int mii_status = mdio_read(ioaddr, phy, 1);
                        if (mii_status != 0xffff && mii_status != 0x0000) {
                                np->phys[phy_idx++] = phy;
                                np->advertising = mdio_read(ioaddr, phy, 4);
                                printk("<6>" "%s: MII PHY found at address %d, status "
                                           "0x%4.4x advertising %4.4x.\n",
                                           dev->name, phy, mii_status, np->advertising);
                        }
                }
                np->mii_cnt = phy_idx;
        }

        find_cnt++;

        return 0;

err_out_unmap_status:
        pci_free_consistent(pdev, 16*sizeof(struct tx_status_words), np->tx_status,
                np->tx_status_dma);
err_out_unmap_rx:
        pci_free_consistent(pdev, 64*sizeof(struct yellowfin_desc), np->rx_ring, np->rx_ring_dma);
err_out_unmap_tx:
        pci_free_consistent(pdev, 2*16*sizeof(struct yellowfin_desc), np->tx_ring, np->tx_ring_dma);
err_out_cleardev:
        pci_set_drvdata(pdev, ((void *)0));
        pci_iounmap(pdev, ioaddr);
err_out_free_res:
        pci_release_regions(pdev);
err_out_free_netdev:
        free_netdev (dev);
        return -19;
}

static int read_eeprom(void *ioaddr, int location)
{
        int bogus_cnt = 10000;

        iowrite8(location, ioaddr + EEAddr);
        iowrite8(0x30 | ((location >> 8) & 7), ioaddr + EECtrl);
        while ((ioread8(ioaddr + EEStatus) & 0x80) && --bogus_cnt > 0)
                ;
        return ioread8(ioaddr + EERead);
}





static int mdio_read(void *ioaddr, int phy_id, int location)
{
        int i;

        iowrite16((phy_id<<8) + location, ioaddr + MII_Addr);
        iowrite16(1, ioaddr + MII_Cmd);
        for (i = 10000; i >= 0; i--)
                if ((ioread16(ioaddr + MII_Status) & 1) == 0)
                        break;
        return ioread16(ioaddr + MII_Rd_Data);
}

static void mdio_write(void *ioaddr, int phy_id, int location, int value)
{
        int i;

        iowrite16((phy_id<<8) + location, ioaddr + MII_Addr);
        iowrite16(value, ioaddr + MII_Wr_Data);


        for (i = 10000; i >= 0; i--)
                if ((ioread16(ioaddr + MII_Status) & 1) == 0)
                        break;
        return;
}


static int yellowfin_open(struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        void *ioaddr = yp->base;
        int i;


        iowrite32(0x80000000, ioaddr + DMACtrl);

        i = request_irq(dev->irq, &yellowfin_interrupt, 0x04000000, dev->name, dev);
        if (i) return i;

        if (debug > 1)
                printk("<7>" "%s: yellowfin_open() irq %d.\n",
                           dev->name, dev->irq);

        yellowfin_init_ring(dev);

        iowrite32(yp->rx_ring_dma, ioaddr + RxPtr);
        iowrite32(yp->tx_ring_dma, ioaddr + TxPtr);

        for (i = 0; i < 6; i++)
                iowrite8(dev->dev_addr[i], ioaddr + StnAddr + i);



        iowrite32(0x00800080, ioaddr + TxIntrSel);
        iowrite32(0x00800080, ioaddr + TxBranchSel);
        iowrite32(0x00400040, ioaddr + TxWaitSel);
        iowrite32(0x00400040, ioaddr + RxIntrSel);
        iowrite32(0x00400040, ioaddr + RxBranchSel);
        iowrite32(0x00400040, ioaddr + RxWaitSel);



        iowrite32(dma_ctrl, ioaddr + DMACtrl);
        iowrite16(fifo_cfg, ioaddr + FIFOcfg);

        iowrite32(0x0030FFFF, ioaddr + FlowCtrl);

        yp->tx_threshold = 32;
        iowrite32(yp->tx_threshold, ioaddr + TxThreshold);

        if (dev->if_port == 0)
                dev->if_port = yp->default_port;

        netif_start_queue(dev);


        if (yp->drv_flags & IsGigabit) {

                yp->full_duplex = 1;
                iowrite16(0x01CF, ioaddr + Cnfg);
        } else {
                iowrite16(0x0018, ioaddr + FrameGap0);
                iowrite16(0x1018, ioaddr + FrameGap1);
                iowrite16(0x101C | (yp->full_duplex ? 2 : 0), ioaddr + Cnfg);
        }
        set_rx_mode(dev);


        iowrite16(0x81ff, ioaddr + IntrEnb);
        iowrite16(0x0000, ioaddr + EventStatus);
        iowrite32(0x80008000, ioaddr + RxCtrl);
        iowrite32(0x80008000, ioaddr + TxCtrl);

        if (debug > 2) {
                printk("<7>" "%s: Done yellowfin_open().\n",
                           dev->name);
        }


        init_timer(&yp->timer);
        yp->timer.expires = jiffies + 3*250;
        yp->timer.data = (unsigned long)dev;
        yp->timer.function = &yellowfin_timer;
        add_timer(&yp->timer);

        return 0;
}

static void yellowfin_timer(unsigned long data)
{
        struct net_device *dev = (struct net_device *)data;
        struct yellowfin_private *yp = netdev_priv(dev);
        void *ioaddr = yp->base;
        int next_tick = 60*250;

        if (debug > 3) {
                printk("<7>" "%s: Yellowfin timer tick, status %8.8x.\n",
                           dev->name, ioread16(ioaddr + IntrStatus));
        }

        if (yp->mii_cnt) {
                int bmsr = mdio_read(ioaddr, yp->phys[0], 0x01);
                int lpa = mdio_read(ioaddr, yp->phys[0], 0x05);
                int negotiated = lpa & yp->advertising;
                if (debug > 1)
                        printk("<7>" "%s: MII #%d status register is %4.4x, "
                                   "link partner capability %4.4x.\n",
                                   dev->name, yp->phys[0], bmsr, lpa);

                yp->full_duplex = mii_duplex(yp->duplex_lock, negotiated);

                iowrite16(0x101C | (yp->full_duplex ? 2 : 0), ioaddr + Cnfg);

                if (bmsr & 0x0004)
                        next_tick = 60*250;
                else
                        next_tick = 3*250;
        }

        yp->timer.expires = jiffies + next_tick;
        add_timer(&yp->timer);
}

static void yellowfin_tx_timeout(struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        void *ioaddr = yp->base;

        printk("<4>" "%s: Yellowfin transmit timed out at %d/%d Tx "
                   "status %4.4x, Rx status %4.4x, resetting...\n",
                   dev->name, yp->cur_tx, yp->dirty_tx,
                   ioread32(ioaddr + TxStatus), ioread32(ioaddr + RxStatus));


        if (debug) {
                int i;
                printk("<4>" "  Rx ring %p: ", yp->rx_ring);
                for (i = 0; i < 64; i++)
                        printk(" %8.8x", yp->rx_ring[i].result_status);
                printk("\n""<4>""  Tx ring %p: ", yp->tx_ring);
                for (i = 0; i < 16; i++)
                        printk(" %4.4x /%8.8x", yp->tx_status[i].tx_errs,
                                   yp->tx_ring[i].result_status);
                printk("\n");
        }



        dev->if_port = 0;


        iowrite32(0x10001000, yp->base + TxCtrl);
        if (yp->cur_tx - yp->dirty_tx < 12)
                netif_wake_queue (dev);

        dev->trans_start = jiffies;
        yp->stats.tx_errors++;
}


static void yellowfin_init_ring(struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        int i;

        yp->tx_full = 0;
        yp->cur_rx = yp->cur_tx = 0;
        yp->dirty_tx = 0;

        yp->rx_buf_sz = (dev->mtu <= 1500 ? 1536 : dev->mtu + 32);

        for (i = 0; i < 64; i++) {
                yp->rx_ring[i].dbdma_cmd =
                        (( __le32)(__u32)(CMD_RX_BUF | INTR_ALWAYS | yp->rx_buf_sz));
                yp->rx_ring[i].branch_addr = (( __le32)(__u32)(yp->rx_ring_dma + ((i+1)%64)*sizeof(struct yellowfin_desc)));

        }

        for (i = 0; i < 64; i++) {
                struct sk_buff *skb = dev_alloc_skb(yp->rx_buf_sz);
                yp->rx_skbuff[i] = skb;
                if (skb == ((void *)0))
                        break;
                skb->dev = dev;
                skb_reserve(skb, 2);
                yp->rx_ring[i].addr = (( __le32)(__u32)(pci_map_single(yp->pci_dev, skb->data, yp->rx_buf_sz, 2)));

        }
        yp->rx_ring[i-1].dbdma_cmd = (( __le32)(__u32)(CMD_STOP));
        yp->dirty_rx = (unsigned int)(i - 64);




        for (i = 0; i < 16; i++) {
                yp->tx_skbuff[i] = ((void *)0);
                yp->tx_ring[i].dbdma_cmd = (( __le32)(__u32)(CMD_STOP));
                yp->tx_ring[i].branch_addr = (( __le32)(__u32)(yp->tx_ring_dma + ((i+1)%16)*sizeof(struct yellowfin_desc)));

        }

        yp->tx_ring[--i].dbdma_cmd = (( __le32)(__u32)(CMD_STOP | BRANCH_ALWAYS));
# 842 "drivers/net/yellowfin.c"
        yp->tx_tail_desc = &yp->tx_status[0];
        return;
}

static int yellowfin_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        unsigned entry;
        int len = skb->len;

        netif_stop_queue (dev);





        entry = yp->cur_tx % 16;

        if (gx_fix) {
                int cacheline_end = ((unsigned long)skb->data + skb->len) % 32;

                if (cacheline_end > 24 || cacheline_end == 0) {
                        len = skb->len + 32 - cacheline_end + 1;
                        if (len != skb->len)
                                skb = skb_padto(skb, len);
                }
                if (skb == ((void *)0)) {
                        yp->tx_skbuff[entry] = ((void *)0);
                        netif_wake_queue(dev);
                        return 0;
                }
        }
        yp->tx_skbuff[entry] = skb;


        yp->tx_ring[entry].addr = (( __le32)(__u32)(pci_map_single(yp->pci_dev, skb->data, len, 1)));

        yp->tx_ring[entry].result_status = 0;
        if (entry >= 16 -1) {

                yp->tx_ring[0].dbdma_cmd = (( __le32)(__u32)(CMD_STOP));
                yp->tx_ring[16 -1].dbdma_cmd =
                        (( __le32)(__u32)(CMD_TX_PKT|BRANCH_ALWAYS | len));
        } else {
                yp->tx_ring[entry+1].dbdma_cmd = (( __le32)(__u32)(CMD_STOP));
                yp->tx_ring[entry].dbdma_cmd =
                        (( __le32)(__u32)(CMD_TX_PKT | BRANCH_IFTRUE | len));
        }
        yp->cur_tx++;
# 913 "drivers/net/yellowfin.c"
        iowrite32(0x10001000, yp->base + TxCtrl);

        if (yp->cur_tx - yp->dirty_tx < 12)
                netif_start_queue (dev);
        else
                yp->tx_full = 1;
        dev->trans_start = jiffies;

        if (debug > 4) {
                printk("<7>" "%s: Yellowfin transmit frame #%d queued in slot %d.\n",
                           dev->name, yp->cur_tx, entry);
        }
        return 0;
}



static irqreturn_t yellowfin_interrupt(int irq, void *dev_instance, struct pt_regs *regs)
{
        struct net_device *dev = dev_instance;
        struct yellowfin_private *yp;
        void *ioaddr;
        int boguscnt = max_interrupt_work;
        unsigned int handled = 0;


        if (dev == ((void *)0)) {
                printk ("<3>" "yellowfin_interrupt(): irq %d for unknown device.\n", irq);
                return (0);
        }


        yp = netdev_priv(dev);
        ioaddr = yp->base;

        _spin_lock(&yp->lock);

        do {
                u16 intr_status = ioread16(ioaddr + IntrClear);

                if (debug > 4)
                        printk("<7>" "%s: Yellowfin interrupt, status %4.4x.\n",
                                   dev->name, intr_status);

                if (intr_status == 0)
                        break;
                handled = 1;

                if (intr_status & (IntrRxDone | IntrEarlyRx)) {
                        yellowfin_rx(dev);
                        iowrite32(0x10001000, ioaddr + RxCtrl);
                }


                for (; yp->cur_tx - yp->dirty_tx > 0; yp->dirty_tx++) {
                        int entry = yp->dirty_tx % 16;
                        struct sk_buff *skb;

                        if (yp->tx_ring[entry].result_status == 0)
                                break;
                        skb = yp->tx_skbuff[entry];
                        yp->stats.tx_packets++;
                        yp->stats.tx_bytes += skb->len;

                        pci_unmap_single(yp->pci_dev, yp->tx_ring[entry].addr,
                                skb->len, 1);
                        dev_kfree_skb_irq(skb);
                        yp->tx_skbuff[entry] = ((void *)0);
                }
                if (yp->tx_full
                        && yp->cur_tx - yp->dirty_tx < 12 - 4) {

                        yp->tx_full = 0;
                        netif_wake_queue(dev);
                }
# 1065 "drivers/net/yellowfin.c"
                if (intr_status & 0x2ee)
                        yellowfin_error(dev, intr_status);

                if (--boguscnt < 0) {
                        printk("<4>" "%s: Too much work at interrupt, "
                                   "status=0x%4.4x.\n",
                                   dev->name, intr_status);
                        break;
                }
        } while (1);

        if (debug > 3)
                printk("<7>" "%s: exiting interrupt, status=%#4.4x.\n",
                           dev->name, ioread16(ioaddr + IntrStatus));

        _spin_unlock(&yp->lock);
        return ((handled) != 0);
}



static int yellowfin_rx(struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        int entry = yp->cur_rx % 64;
        int boguscnt = yp->dirty_rx + 64 - yp->cur_rx;

        if (debug > 4) {
                printk("<7>" " In yellowfin_rx(), entry %d status %8.8x.\n",
                           entry, yp->rx_ring[entry].result_status);
                printk("<7>" "   #%d desc. %8.8x %8.8x %8.8x.\n",
                           entry, yp->rx_ring[entry].dbdma_cmd, yp->rx_ring[entry].addr,
                           yp->rx_ring[entry].result_status);
        }


        while (1) {
                struct yellowfin_desc *desc = &yp->rx_ring[entry];
                struct sk_buff *rx_skb = yp->rx_skbuff[entry];
                s16 frame_status;
                u16 desc_status;
                int data_size;
                u8 *buf_addr;

                if(!desc->result_status)
                        break;
                pci_dma_sync_single_for_cpu(yp->pci_dev, desc->addr,
                        yp->rx_buf_sz, 2);
                desc_status = (( __u32)(__le32)(desc->result_status)) >> 16;
                buf_addr = rx_skb->data;
                data_size = ((( __u32)(__le32)(desc->dbdma_cmd)) -
                        (( __u32)(__le32)(desc->result_status))) & 0xffff;
                frame_status = (( __u16)(__le16)((*((s16*)&(buf_addr[data_size - 2])))));
                if (debug > 4)
                        printk("<7>" "  yellowfin_rx() status was %4.4x.\n",
                                   frame_status);
                if (--boguscnt < 0)
                        break;
                if ( ! (desc_status & RX_EOP)) {
                        if (data_size != 0)
                                printk("<4>" "%s: Oversized Ethernet frame spanned multiple buffers,"
                                           " status %4.4x, data_size %d!\n", dev->name, desc_status, data_size);
                        yp->stats.rx_length_errors++;
                } else if ((yp->drv_flags & IsGigabit) && (frame_status & 0x0038)) {

                        if (debug > 3)
                                printk("<7>" "  yellowfin_rx() Rx error was %4.4x.\n",
                                           frame_status);
                        yp->stats.rx_errors++;
                        if (frame_status & 0x0060) yp->stats.rx_length_errors++;
                        if (frame_status & 0x0008) yp->stats.rx_frame_errors++;
                        if (frame_status & 0x0010) yp->stats.rx_crc_errors++;
                        if (frame_status < 0) yp->stats.rx_dropped++;
                } else if ( !(yp->drv_flags & IsGigabit) &&
                                   ((buf_addr[data_size-1] & 0x85) || buf_addr[data_size-2] & 0xC0)) {
                        u8 status1 = buf_addr[data_size-2];
                        u8 status2 = buf_addr[data_size-1];
                        yp->stats.rx_errors++;
                        if (status1 & 0xC0) yp->stats.rx_length_errors++;
                        if (status2 & 0x03) yp->stats.rx_frame_errors++;
                        if (status2 & 0x04) yp->stats.rx_crc_errors++;
                        if (status2 & 0x80) yp->stats.rx_dropped++;
# 1161 "drivers/net/yellowfin.c"
                } else {
                        struct sk_buff *skb;
                        int pkt_len = data_size -
                                (yp->chip_id ? 7 : 8 + buf_addr[data_size - 8]);



                        if (debug > 4)
                                printk("<7>" "  yellowfin_rx() normal Rx pkt length %d"
                                           " of %d, bogus_cnt %d.\n",
                                           pkt_len, data_size, boguscnt);



                        if (pkt_len > rx_copybreak) {
                                skb_put(skb = rx_skb, pkt_len);
                                pci_unmap_single(yp->pci_dev,
                                        yp->rx_ring[entry].addr,
                                        yp->rx_buf_sz,
                                        2);
                                yp->rx_skbuff[entry] = ((void *)0);
                        } else {
                                skb = dev_alloc_skb(pkt_len + 2);
                                if (skb == ((void *)0))
                                        break;
                                skb->dev = dev;
                                skb_reserve(skb, 2);
                                eth_copy_and_sum(skb, rx_skb->data, pkt_len, 0);
                                skb_put(skb, pkt_len);
                                pci_dma_sync_single_for_device(yp->pci_dev, desc->addr,
                                                                                           yp->rx_buf_sz,
                                                                                           2);
                        }
                        skb->protocol = eth_type_trans(skb, dev);
                        netif_rx(skb);
                        dev->last_rx = jiffies;
                        yp->stats.rx_packets++;
                        yp->stats.rx_bytes += pkt_len;
                }
                entry = (++yp->cur_rx) % 64;
        }


        for (; yp->cur_rx - yp->dirty_rx > 0; yp->dirty_rx++) {
                entry = yp->dirty_rx % 64;
                if (yp->rx_skbuff[entry] == ((void *)0)) {
                        struct sk_buff *skb = dev_alloc_skb(yp->rx_buf_sz);
                        if (skb == ((void *)0))
                                break;
                        yp->rx_skbuff[entry] = skb;
                        skb->dev = dev;
                        skb_reserve(skb, 2);
                        yp->rx_ring[entry].addr = (( __le32)(__u32)(pci_map_single(yp->pci_dev, skb->data, yp->rx_buf_sz, 2)));

                }
                yp->rx_ring[entry].dbdma_cmd = (( __le32)(__u32)(CMD_STOP));
                yp->rx_ring[entry].result_status = 0;
                if (entry != 0)
                        yp->rx_ring[entry - 1].dbdma_cmd =
                                (( __le32)(__u32)(CMD_RX_BUF | INTR_ALWAYS | yp->rx_buf_sz));
                else
                        yp->rx_ring[64 - 1].dbdma_cmd =
                                (( __le32)(__u32)(CMD_RX_BUF | INTR_ALWAYS | BRANCH_ALWAYS | yp->rx_buf_sz));

        }

        return 0;
}

static void yellowfin_error(struct net_device *dev, int intr_status)
{
        struct yellowfin_private *yp = netdev_priv(dev);

        printk("<3>" "%s: Something Wicked happened! %4.4x.\n",
                   dev->name, intr_status);

        if (intr_status & (IntrTxPCIErr | IntrTxPCIFault))
                yp->stats.tx_errors++;
        if (intr_status & (IntrRxPCIErr | IntrRxPCIFault))
                yp->stats.rx_errors++;
}

static int yellowfin_close(struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        void *ioaddr = yp->base;
        int i;

        netif_stop_queue (dev);

        if (debug > 1) {
                printk("<7>" "%s: Shutting down ethercard, status was Tx %4.4x "
                           "Rx %4.4x Int %2.2x.\n",
                           dev->name, ioread16(ioaddr + TxStatus),
                           ioread16(ioaddr + RxStatus),
                           ioread16(ioaddr + IntrStatus));
                printk("<7>" "%s: Queue pointers were Tx %d / %d,  Rx %d / %d.\n",
                           dev->name, yp->cur_tx, yp->dirty_tx, yp->cur_rx, yp->dirty_rx);
        }


        iowrite16(0x0000, ioaddr + IntrEnb);


        iowrite32(0x80000000, ioaddr + RxCtrl);
        iowrite32(0x80000000, ioaddr + TxCtrl);

        del_timer(&yp->timer);


        if (debug > 2) {
                printk("\n""<7>""  Tx ring at %8.8llx:\n",
                                (unsigned long long)yp->tx_ring_dma);
                for (i = 0; i < 16*2; i++)
                        printk(" %c #%d desc. %8.8x %8.8x %8.8x %8.8x.\n",
                                   ioread32(ioaddr + TxPtr) == (long)&yp->tx_ring[i] ? '>' : ' ',
                                   i, yp->tx_ring[i].dbdma_cmd, yp->tx_ring[i].addr,
                                   yp->tx_ring[i].branch_addr, yp->tx_ring[i].result_status);
                printk("<7>" "  Tx status %p:\n", yp->tx_status);
                for (i = 0; i < 16; i++)
                        printk("   #%d status %4.4x %4.4x %4.4x %4.4x.\n",
                                   i, yp->tx_status[i].tx_cnt, yp->tx_status[i].tx_errs,
                                   yp->tx_status[i].total_tx_cnt, yp->tx_status[i].paused);

                printk("\n""<7>" "  Rx ring %8.8llx:\n",
                                (unsigned long long)yp->rx_ring_dma);
                for (i = 0; i < 64; i++) {
                        printk("<7>" " %c #%d desc. %8.8x %8.8x %8.8x\n",
                                   ioread32(ioaddr + RxPtr) == (long)&yp->rx_ring[i] ? '>' : ' ',
                                   i, yp->rx_ring[i].dbdma_cmd, yp->rx_ring[i].addr,
                                   yp->rx_ring[i].result_status);
                        if (debug > 6) {
                                if ((*((u8*)yp->rx_ring[i].addr)) != 0x69) {
                                        int j;
                                        for (j = 0; j < 0x50; j++)
                                                printk(" %4.4x",
                                                           (*(((u16*)yp->rx_ring[i].addr) + j)));
                                        printk("\n");
                                }
                        }
                }
        }


        free_irq(dev->irq, dev);


        for (i = 0; i < 64; i++) {
                yp->rx_ring[i].dbdma_cmd = (( __le32)(__u32)(CMD_STOP));
                yp->rx_ring[i].addr = 0xBADF00D0;
                if (yp->rx_skbuff[i]) {
                        kfree_skb(yp->rx_skbuff[i]);
                }
                yp->rx_skbuff[i] = ((void *)0);
        }
        for (i = 0; i < 16; i++) {
                if (yp->tx_skbuff[i])
                        kfree_skb(yp->tx_skbuff[i]);
                yp->tx_skbuff[i] = ((void *)0);
        }
# 1329 "drivers/net/yellowfin.c"
        return 0;
}

static struct net_device_stats *yellowfin_get_stats(struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        return &yp->stats;
}



static void set_rx_mode(struct net_device *dev)
{
        struct yellowfin_private *yp = netdev_priv(dev);
        void *ioaddr = yp->base;
        u16 cfg_value = ioread16(ioaddr + Cnfg);


        iowrite16(cfg_value & ~0x1000, ioaddr + Cnfg);
        if (dev->flags & 0x100) {

                printk("<5>" "%s: Promiscuous mode enabled.\n", dev->name);
                iowrite16(0x000F, ioaddr + AddrMode);
        } else if ((dev->mc_count > 64) || (dev->flags & 0x200)) {

                iowrite16(0x000B, ioaddr + AddrMode);
        } else if (dev->mc_count > 0) {
                struct dev_mc_list *mclist;
                u16 hash_table[4];
                int i;
                (__builtin_constant_p(0) ? (__builtin_constant_p((sizeof(hash_table))) ? __constant_c_and_count_memset(((hash_table)),((0x01010101UL*(unsigned char)(0))),((sizeof(hash_table)))) : __constant_c_memset(((hash_table)),((0x01010101UL*(unsigned char)(0))),((sizeof(hash_table))))) : (__builtin_constant_p((sizeof(hash_table))) ? __memset_generic((((hash_table))),(((0))),(((sizeof(hash_table))))) : __memset_generic(((hash_table)),((0)),((sizeof(hash_table))))));
                for (i = 0, mclist = dev->mc_list; mclist && i < dev->mc_count;
                         i++, mclist = mclist->next) {
                        unsigned int bit;



                        if (yp->drv_flags & HasMulticastBug) {
                                bit = (crc32_le(~0, mclist->dmi_addr, 3) >> 3) & 0x3f;
                                hash_table[bit >> 4] |= (1 << bit);
                                bit = (crc32_le(~0, mclist->dmi_addr, 4) >> 3) & 0x3f;
                                hash_table[bit >> 4] |= (1 << bit);
                                bit = (crc32_le(~0, mclist->dmi_addr, 5) >> 3) & 0x3f;
                                hash_table[bit >> 4] |= (1 << bit);
                        }
                        bit = (crc32_le(~0, mclist->dmi_addr, 6) >> 3) & 0x3f;
                        hash_table[bit >> 4] |= (1 << bit);
                }

                for (i = 0; i < 4; i++)
                        iowrite16(hash_table[i], ioaddr + HashTbl + i*2);
                iowrite16(0x0003, ioaddr + AddrMode);
        } else {
                iowrite16(0x0001, ioaddr + AddrMode);
        }

        iowrite16(cfg_value | 0x1000, ioaddr + Cnfg);
}

static void yellowfin_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
        struct yellowfin_private *np = netdev_priv(dev);
        strcpy(info->driver, "yellowfin");
        strcpy(info->version, "1.05+LK1.1.6");
        strcpy(info->bus_info, pci_name(np->pci_dev));
}

static struct ethtool_ops ethtool_ops = {
        .get_drvinfo = yellowfin_get_drvinfo
};

static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
        struct yellowfin_private *np = netdev_priv(dev);
        void *ioaddr = np->base;
        struct mii_ioctl_data *data = if_mii(rq);

        switch(cmd) {
        case 0x8947:
                data->phy_id = np->phys[0] & 0x1f;


        case 0x8948:
                data->val_out = mdio_read(ioaddr, data->phy_id & 0x1f, data->reg_num & 0x1f);
                return 0;

        case 0x8949:
                if (!capable(12))
                        return -1;
                if (data->phy_id == np->phys[0]) {
                        u16 value = data->val_in;
                        switch (data->reg_num) {
                        case 0:

                                np->medialock = (value & 0x9000) ? 0 : 1;
                                if (np->medialock)
                                        np->full_duplex = (value & 0x0100) ? 1 : 0;
                                break;
                        case 4: np->advertising = value; break;
                        }

                }
                mdio_write(ioaddr, data->phy_id & 0x1f, data->reg_num & 0x1f, data->val_in);
                return 0;
        default:
                return -95;
        }
}


static void yellowfin_remove_one (struct pci_dev *pdev)
{
        struct net_device *dev = pci_get_drvdata(pdev);
        struct yellowfin_private *np;

        if (!dev)
                __asm__ __volatile__( "ud2\n" "\t.word %c0\n" "\t.long %c1\n" : : "i" (1445), "i" ("drivers/net/yellowfin.c"));
        np = netdev_priv(dev);

        pci_free_consistent(pdev, 16*sizeof(struct tx_status_words), np->tx_status,
                np->tx_status_dma);
        pci_free_consistent(pdev, 64*sizeof(struct yellowfin_desc), np->rx_ring, np->rx_ring_dma);
        pci_free_consistent(pdev, 2*16*sizeof(struct yellowfin_desc), np->tx_ring, np->tx_ring_dma);
        unregister_netdev (dev);

        pci_iounmap(pdev, np->base);

        pci_release_regions (pdev);

        free_netdev (dev);
        pci_set_drvdata(pdev, ((void *)0));
}


static struct pci_driver yellowfin_driver = {
        .name = "yellowfin",
        .id_table = yellowfin_pci_tbl,
        .probe = yellowfin_init_one,
        .remove = yellowfin_remove_one,
};


static int __attribute__ ((__section__ (".init.text"))) yellowfin_init (void)
{




        return pci_register_driver (&yellowfin_driver);
}


static void __attribute__((__unused__)) __attribute__ ((__section__(".exit.text"))) yellowfin_cleanup (void)
{
        pci_unregister_driver (&yellowfin_driver);
}


static initcall_t __initcall_yellowfin_init __attribute__((__unused__)) __attribute__((__section__(".initcall" "6" ".init"))) = yellowfin_init;;
static exitcall_t __exitcall_yellowfin_cleanup __attribute__((__unused__)) __attribute__ ((__section__ (".exitcall.exit"))) = yellowfin_cleanup;;

struct pci_dev pdev;
struct pci_device_id ent;
void * f(void *) {
  yellowfin_init();
  yellowfin_init_one(&pdev, &ent);
  return 0;
}

typedef int pthread_t;

int main() {
  pthread_t t;
  pthread_create(&t, (void*)0, f, (void*)0);
  pthread_create(&t, (void*)0, f, (void*)0);
}
