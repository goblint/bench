// ftw implementation stub for Goblint

// types copied from pfscan_comb.c
typedef long long __quad_t;
typedef unsigned long long __u_quad_t;
typedef __u_quad_t __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long __off_t;
typedef long __time_t;
typedef long __blksize_t;
typedef long __blkcnt_t;

struct timespec {
   __time_t tv_sec ;
   long tv_nsec ;
};

struct stat {
   __dev_t st_dev ;
   unsigned short __pad1 ;
   __ino_t st_ino ;
   __mode_t st_mode ;
   __nlink_t st_nlink ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   __dev_t st_rdev ;
   unsigned short __pad2 ;
   __off_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   unsigned long __unused4 ;
   unsigned long __unused5 ;
};

int ftw(const char *dir, int (*fn)(const char *file, const struct stat *sb, int flag), int nopenfd) {
  char *file; // rand
  struct stat s; // rand
  int flag; // rand
  fn(file, &s, flag);
  return 0;
}
