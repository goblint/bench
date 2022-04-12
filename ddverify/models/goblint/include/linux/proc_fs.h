#ifndef _LINUX_PROC_FS_H
#define _LINUX_PROC_FS_H

#include <linux/fs.h>
#include <linux/slab.h>

struct proc_dir_entry {
  int something;
};

struct proc_dir_entry *proc_root_driver;

typedef	int (read_proc_t)(char *page, char **start, off_t off,
			  int count, int *eof, void *data);

struct proc_dir_entry *create_proc_read_entry(const char *name,
					      mode_t mode, 
					      struct proc_dir_entry *base, 
					      read_proc_t *read_proc, 
					      void * data);

struct proc_dir_entry *create_proc_entry(const char *name, 
					 mode_t mode,
					 struct proc_dir_entry *parent);

void remove_proc_entry(const char *name, struct proc_dir_entry *parent);
struct proc_dir_entry *proc_mkdir(const char *,struct proc_dir_entry *);

#endif
