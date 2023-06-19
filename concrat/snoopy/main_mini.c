
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

typedef __builtin_va_list __gnuc_va_list;
typedef long __off_t;
typedef long __off64_t;
typedef unsigned long size_t;

struct __anonstruct_snoopy_configuration_t_620930686 {
   int initialized ;
   int configfile_enabled ;
   char *configfile_path ;
   int configfile_found ;
   int configfile_parsed ;
   int error_logging_enabled ;
   char *message_format ;
   int message_format_malloced ;
   int filtering_enabled ;
   char *filter_chain ;
   int filter_chain_malloced ;
   char *output ;
   int output_malloced ;
   char *output_arg ;
   int output_arg_malloced ;
   int syslog_facility ;
   int syslog_level ;
   int syslog_ident_format_malloced ;
   char *syslog_ident_format ;
};
typedef struct __anonstruct_snoopy_configuration_t_620930686 snoopy_configuration_t;
typedef long __time_t;
typedef long __ssize_t;
typedef long __syscall_slong_t;
typedef __ssize_t ssize_t;
struct timespec {
   __time_t tv_sec ;
   __syscall_slong_t tv_nsec ;
};
struct __pthread_internal_list {
   struct __pthread_internal_list *__prev ;
   struct __pthread_internal_list *__next ;
};

typedef unsigned long pthread_t;
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
struct __anonstruct_tData_t_1064464920 {
   int seqNr ;
};
typedef struct __anonstruct_tData_t_1064464920 tData_t;
typedef int __pid_t;
typedef __pid_t pid_t;
/* compiler builtin: 
   long __builtin_expect(long  , long  ) ;  */
#pragma merger("0","/tmp/cil-YQyqXhlZ.i","-Wall,-Werror,-Wextra,-Wno-unused-parameter,-std=c99,-Wpedantic,-fvisibility=hidden,-g,-O2")
void fatalError(char const   * const  message ) ;
void fatalErrorValue(char const   * const  message , char const   * const  value ) ;

__inline extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__gnu_inline__)) atoi)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern int ( __attribute__((__nonnull__(1), __gnu_inline__)) atoi)(char const   *__nptr ) 
{ 
  long tmp ;

  {
  tmp = strtol((char const   * __restrict  )__nptr, (char ** __restrict  )((char **)((void *)0)),
               10);
  return ((int )tmp);
}
}

extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strcmp)(char const   *__s1 ,
                                                                                     char const   *__s2 )  __attribute__((__pure__)) ;

char **g_argv ;

extern int snoopy_datasourceregistry_getCount() ;

extern char *snoopy_datasourceregistry_getName(int datasourceId ) ;
extern int snoopy_datasourceregistry_callById(int datasourceId , char * const  result ,
                                              char const   * const  datasourceArg ) ;

extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) unlink)(char const   *__name ) ;
extern int snoopy_outputregistry_getCount() ;

extern char *snoopy_outputregistry_getName(int outputId ) ;
extern int snoopy_outputregistry_callById(int outputId , char const   * const  logMessage ,
                                          char const   * const  outputArg ) ;
extern int snoopy_outputregistry_callByName(char const   * const  outputName , char const   * const  logMessage ,
                                            char const   * const  outputArg ) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  snprintf)(char * __restrict  __s ,
                                                                             size_t __maxlen ,
                                                                             char const   * __restrict  __format 
                                                                             , ...) ;
int snoopyTestCli_action_stress_threads(int argc , char **argv ) ;
int snoopyTestCli_action_stress_threadsexec(int argc , char **argv ) ;
void snoopyTestCli_action_stress_showHelp(void) 
{ 
  char *helpContent ;

  {
  helpContent = (char *)"Snoopy TEST SUITE CLI utility :: Action `stress`\n\nUsage:\n    snoopy stress SUBSYSTEM [ARGS]\n\nAvailable subsystems:\n    threads,t          Stress internal threading implementation\n    threadsexec,te     Stress threading implementation by including execution of an external command\n\n    help,h             Show this help\n    SUBSYSTEM help     Show SUBSYSTEM\'s help\n\n";
  printf((char const   * __restrict  )"%s", helpContent);
  return;
}
}
int snoopyTestCli_action_stress(int argc , char **argv ) 
{ 
  char const   *subsystem ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;

  {
  if (argc < 1) {
    snoopyTestCli_action_stress_showHelp();
    fatalError((char const   * const  )"No subsystem specified.");
  }
  subsystem = (char const   *)*(argv + 0);
  tmp = strcmp(subsystem, "help");
  if (0 == tmp) {
    snoopyTestCli_action_stress_showHelp();
    return (0);
  } else {
    tmp___0 = strcmp(subsystem, "h");
    if (0 == tmp___0) {
      snoopyTestCli_action_stress_showHelp();
      return (0);
    }
  }
  tmp___2 = strcmp(subsystem, "threads");
  if (0 == tmp___2) {
    tmp___1 = snoopyTestCli_action_stress_threads(argc - 1, argv + 1);
    return (tmp___1);
  } else {
    tmp___3 = strcmp(subsystem, "t");
    if (0 == tmp___3) {
      tmp___1 = snoopyTestCli_action_stress_threads(argc - 1, argv + 1);
      return (tmp___1);
    }
  }
  tmp___5 = strcmp(subsystem, "threadsexec");
  if (0 == tmp___5) {
    tmp___4 = snoopyTestCli_action_stress_threadsexec(argc - 1, argv + 1);
    return (tmp___4);
  } else {
    tmp___6 = strcmp(subsystem, "te");
    if (0 == tmp___6) {
      tmp___4 = snoopyTestCli_action_stress_threadsexec(argc - 1, argv + 1);
      return (tmp___4);
    }
  }
  snoopyTestCli_action_stress_showHelp();
  fatalErrorValue((char const   * const  )"Unknown subsystem", (char const   * const  )subsystem); 
}
}

#pragma merger("0","/tmp/cil-rwY2gemM.i","-Wall,-Werror,-Wextra,-Wno-unused-parameter,-std=c99,-Wpedantic,-fvisibility=hidden,-g,-O2")
int g_argc  ;
char **g_argv  ;

int main(int argc , char **argv ) 
{ 
  char const   *action ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;

  {
  g_argc = argc;
  g_argv = argv;
  if (argc < 2) {
    snoopyTestCli_showHelp();
    fatalError((char const   * const  )"No action specified.");
  }
  action = (char const   *)*(argv + 1);
  tmp = strcmp(action, "--help");
  if (0 == tmp) {
    snoopyTestCli_showHelp();
    return (0);
  } else {
    tmp___0 = strcmp(action, "-h");
    if (0 == tmp___0) {
      snoopyTestCli_showHelp();
      return (0);
    }
  }
  tmp___2 = strcmp(action, "run");
  
  tmp___4 = strcmp(action, "stress");
  if (0 == tmp___4) {
    tmp___3 = snoopyTestCli_action_stress(argc - 2, argv + 2);
    return (tmp___3);
  }
  tmp___6 = strcmp(action, "unit");
  
  snoopyTestCli_showHelp();
  fatalErrorValue((char const   * const  )"Unknown action", (char const   * const  )action);
}
}
#pragma merger("0","/tmp/cil-3j2Adaqx.i","-Wall,-Werror,-Wextra,-Wno-unused-parameter,-std=c99,-Wpedantic,-fvisibility=hidden,-g,-O2")

void printDiagValue(char const   * const  message , char const   * const  value ) ;

void printWarningValue(char const   * const  message , char const   * const  value ) ;
void printError(char const   * const  message ) ;
void printErrorValue(char const   * const  message , char const   * const  value ) ;

extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) access)(char const   *__name ,
                                                                                   int __type ) ;
extern  __attribute__((__nothrow__)) void *dlopen(char const   *__file , int __mode ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(2))) dlsym)(void * __restrict  __handle ,
                                                                                    char const   * __restrict  __name ) ;
extern  __attribute__((__nothrow__)) char *dlerror(void) ;
extern  __attribute__((__nothrow__)) int *__errno_location(void)  __attribute__((__const__)) ;

void printError(char const   * const  message ) 
{ 


  {
  fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"[ERROR] %s\n",
          message);
  return;
}
}
void printErrorValue(char const   * const  message , char const   * const  value ) 
{ 


  {
  fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"[ERROR] %s: %s\n",
          message, value);
  return;
}
}
void fatalError(char const   * const  message ) 
{ 


  {
  printError(message);
  exit(127);
}
}
void fatalErrorValue(char const   * const  message , char const   * const  value ) 
{ 


  {
  printErrorValue(message, value);
  exit(127);
}
}

extern void snoopy_entrypoint_test_cli_threads_init() ;
extern void snoopy_configuration_preinit_disableConfigFileParsing() ;
extern int nanosleep(struct timespec  const  *__requested_time , struct timespec *__remaining ) ;

extern int snoopy_tsrm_get_threadCount() ;
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file , int __oflag 
                                                   , ...) ;
void *snoopyTestCli_action_stress_threads_threadMain(void *args ) ;

pthread_t snoopyTestCli_action_stress_threads_tRepo[10000]  ;
pthread_mutex_t threadCountMutex  =    {{0, 0U, 0, 0U, 0, (short)0, (short)0, {(struct __pthread_internal_list *)0, (struct __pthread_internal_list *)0}}};
int threadCountCreated  =    0;
int threadCountAliveNow  =    0;
int threadCountAliveMax  =    0;
int verbose  ;

int snoopyTestCli_action_stress_threads(int argc , char **argv ) 
{ 
  int threadsToCreate ;
  int maxConcurrentThreadsObserved ;
  int retVal ;
  int tmp ;
  int i ;
  tData_t *tArgs ;
  void *tmp___0 ;
  struct timespec ts_sleep ;
  int tmp___1 ;
  int i___0 ;
  int tmp___2 ;
  int tmp___3 ;

  {
  maxConcurrentThreadsObserved = 0;
  retVal = 0;
  if (argc < 1) {
    snoopyTestCli_action_stress_threads_showHelp();
    fatalError((char const   * const  )"Missing argument: number of threads to create");
  }
  threadsToCreate = atoi((char const   *)*(argv + 0));
  if (threadsToCreate < 1) {
    snoopyTestCli_action_stress_threads_showHelp();
    fatalError((char const   * const  )"Invalid number of threads to create (min 1, max THREAD_COUNT_MAX)");
  } else
  if (threadsToCreate > 10000) {
    snoopyTestCli_action_stress_threads_showHelp();
    fatalError((char const   * const  )"Invalid number of threads to create (min 1, max THREAD_COUNT_MAX)");
  }
  if (argc >= 2) {
    tmp = strcmp((char const   *)*(argv + 1), "-v");
    if (0 == tmp) {
      verbose = 1;
    } else {
      verbose = 0;
    }
  } else {
    verbose = 0;
  }
  snoopy_configuration_preinit_disableConfigFileParsing();
  printf((char const   * __restrict  )"M: Starting threads... ");
  i = 0;
  while (i < threadsToCreate) {
    tmp___0 = malloc(sizeof(*tArgs));
    tArgs = (tData_t *)tmp___0;
    tArgs->seqNr = i;
    if (verbose) {
      printf((char const   * __restrict  )" M: Starting thread #%d:\n", i + 1);
    }
    retVal = pthread_create((pthread_t * __restrict  )(& snoopyTestCli_action_stress_threads_tRepo[i]),
                            (pthread_attr_t const   * __restrict  )((void *)0), & snoopyTestCli_action_stress_threads_threadMain,
                            (void * __restrict  )tArgs);
    i ++;
  }
  printf((char const   * __restrict  )"done.\n");
  printf((char const   * __restrict  )"M: Threads alive right after thread creation was completed: %d\n",
         threadCountAliveNow);
  if (verbose) {
    ts_sleep.tv_sec = (__time_t )0;
    ts_sleep.tv_nsec = (__syscall_slong_t )200000000;
    nanosleep((struct timespec  const  *)(& ts_sleep), (struct timespec *)((void *)0));
    maxConcurrentThreadsObserved = snoopy_tsrm_get_threadCount();
    printf((char const   * __restrict  )"M: Threads after first sleep: %d\n", maxConcurrentThreadsObserved);
    nanosleep((struct timespec  const  *)(& ts_sleep), (struct timespec *)((void *)0));
    tmp___1 = snoopy_tsrm_get_threadCount();
    printf((char const   * __restrict  )"M: Threads after all threads are supposedly finished: %d\n",
           tmp___1);
  }
  printf((char const   * __restrict  )"M: Waiting for all threads to finish... ");
  i___0 = 0;
  while (i___0 < threadsToCreate) {
    pthread_join(snoopyTestCli_action_stress_threads_tRepo[i___0], (void **)((void *)0));
    if (verbose) {
      printf((char const   * __restrict  )"M: Thread joined: #%d\n", i___0 + 1);
      printf((char const   * __restrict  )" M: Thread #%d joined.\n", i___0 + 1);
    }
    i___0 ++;
  }
  printf((char const   * __restrict  )"done.\n");
  printf((char const   * __restrict  )"M: Number of threads created:        %d\n",
         threadCountCreated);
  printf((char const   * __restrict  )"M: Max threads alive simultaneously: %d\n",
         threadCountAliveMax);
  if (verbose) {
    tmp___2 = snoopy_tsrm_get_threadCount();
    printf((char const   * __restrict  )"M: Threads after all threads, except main, have finished: %d\n",
           tmp___2);
  }
  if (verbose) {
    tmp___3 = snoopy_tsrm_get_threadCount();
    printf((char const   * __restrict  )"M: Threads after all threads have finished: %d\n",
           tmp___3);
  }
  if (verbose) {
    printf((char const   * __restrict  )"SUCCESS! Expected Snoopy threads count reached: %d\n",
           maxConcurrentThreadsObserved);
  }
  return (retVal);
}
}
void *snoopyTestCli_action_stress_threads_threadMain(void *args ) 
{ 
  tData_t *tArgs ;
  int seqNr ;
  int seqNrPub ;
  int dsCount ;
  int dsId ;
  char *dsName ;
  char const   *dsArg ;
  char dsResult[2048] ;
  int retVal ;
  pthread_t tmp ;
  int tmp___0 ;
  pthread_t tmp___1 ;
  int tmp___2 ;
  pthread_t tmp___3 ;
  pthread_t tmp___4 ;
  pthread_t tmp___5 ;
  int tmp___6 ;
  pthread_t tmp___7 ;
  int tmp___8 ;
  pthread_t tmp___9 ;
  pthread_t tmp___10 ;

  {
  tArgs = (tData_t *)args;
  seqNr = tArgs->seqNr;
  seqNrPub = seqNr + 1;
  dsArg = "";
  pthread_mutex_lock(& threadCountMutex);
  threadCountCreated ++;
  threadCountAliveNow ++;
  if (threadCountAliveNow > threadCountAliveMax) {
    threadCountAliveMax = threadCountAliveNow;
  }
  pthread_mutex_unlock(& threadCountMutex);
  if (verbose) {
    tmp = pthread_self();
    printf((char const   * __restrict  )"    t%d %llu : Hello from thread #%d\n",
           seqNrPub, (unsigned long long )tmp, seqNrPub);
  }
  if (verbose) {
    tmp___0 = snoopy_tsrm_get_threadCount();
    tmp___1 = pthread_self();
    printf((char const   * __restrict  )"    t%d %llu : Threads before snoopy_init():    %d\n",
           seqNrPub, (unsigned long long )tmp___1, tmp___0);
  }
  snoopy_entrypoint_test_cli_threads_init();
  if (verbose) {
    tmp___2 = snoopy_tsrm_get_threadCount();
    tmp___3 = pthread_self();
    printf((char const   * __restrict  )"    t%d %llu : Threads after  snoopy_init():    %d\n",
           seqNrPub, (unsigned long long )tmp___3, tmp___2);
  }
  dsCount = snoopy_datasourceregistry_getCount();
  
  dsName = snoopy_datasourceregistry_getName(dsId);
  retVal = snoopy_datasourceregistry_callById(dsId, (char * const  )(dsResult), (char const   * const  )dsArg);
  
  pthread_mutex_lock(& threadCountMutex);
  threadCountAliveNow --;
  pthread_mutex_unlock(& threadCountMutex);
  free((void *)tArgs);
  return ((void *)0);
}
}

extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execv)(char const   *__path ,
                                                                                    char * const  *__argv ) ;
extern  __attribute__((__nothrow__)) __pid_t fork(void) ;
extern __pid_t waitpid(__pid_t __pid , int *__stat_loc , int __options ) ;
void *snoopyTestCli_action_stress_threadsexec_threadMain(void *args ) ;
char **snoopyTestCli_action_stress_threadsexec_runCmdAndArgv  ;
pthread_t snoopyTestCli_action_stress_threadsexec_tRepo[10000]  ;

int snoopyTestCli_action_stress_threadsexec(int argc , char **argv ) 
{ 
  int threadsToCreate ;
  int i ;
  int retVal ;
  tData_t *tArgs ;
  void *tmp ;

  {
  retVal = 0;
  
  snoopyTestCli_action_stress_threadsexec_runCmdAndArgv = argv + 1;
  printf((char const   * __restrict  )"M: Starting threads:\n");
  i = 0;
  while (i < threadsToCreate) {
    tmp = malloc(sizeof(*tArgs));
    tArgs = (tData_t *)tmp;
    tArgs->seqNr = i;
    printf((char const   * __restrict  )" M: Starting thread #%d:\n", i + 1);
    retVal = pthread_create((pthread_t * __restrict  )(& snoopyTestCli_action_stress_threadsexec_tRepo[i]),
                            (pthread_attr_t const   * __restrict  )((void *)0), & snoopyTestCli_action_stress_threadsexec_threadMain,
                            (void * __restrict  )tArgs);
    i ++;
  }
  printf((char const   * __restrict  )"M: All threads started\n");
  printf((char const   * __restrict  )"M: Waiting for all threads to finish:\n");
  i = 0;
  while (i < threadsToCreate) {
    pthread_join(snoopyTestCli_action_stress_threadsexec_tRepo[i], (void **)((void *)0));
    printf((char const   * __restrict  )" M: Thread #%d joined.\n", i + 1);
    i ++;
  }
  printf((char const   * __restrict  )"M: All threads have finished.\n");
  printf((char const   * __restrict  )"SUCCESS!\n");
  return (retVal);
}
}
void *snoopyTestCli_action_stress_threadsexec_threadMain(void *args ) 
{ 
  tData_t *tArgs ;
  char *cmd ;
  char **argv ;
  pid_t pid ;
  __pid_t tmp ;
  int *status ;

  {
  tArgs = (tData_t *)args;
  printf((char const   * __restrict  )"  t%d : Hello from thread #%d.\n", tArgs->seqNr + 1,
         tArgs->seqNr + 1);
  tmp = fork();
  pid = tmp;
  if (pid > 0) {
    printf((char const   * __restrict  )"  t%dp: Hello from parent proc\n", tArgs->seqNr + 1);
    status = (int *)0;
    waitpid(pid, status, 0);
    printf((char const   * __restrict  )"  t%dp: Child proc has finished\n", tArgs->seqNr + 1);
  } else
  if (pid == 0) {
    printf((char const   * __restrict  )"  t%dc: Hello from child proc\n", tArgs->seqNr + 1);
    cmd = *(snoopyTestCli_action_stress_threadsexec_runCmdAndArgv + 0);
    argv = snoopyTestCli_action_stress_threadsexec_runCmdAndArgv + 0;
    printf((char const   * __restrict  )"  t%dc: running cmd %s %s\n", tArgs->seqNr + 1,
           cmd, *(argv + 0));
    execv((char const   *)cmd, (char * const  *)argv);
  } else {
    printf((char const   * __restrict  )"  t%d : Fork failed!\n", tArgs->seqNr + 1);
  }
  free((void *)tArgs);
  return ((void *)0);
}
}
#pragma merger("0","/tmp/cil-vM5FnDqc.i","-Wall,-Werror,-Wextra,-Wno-unused-parameter,-std=c99,-Wpedantic,-fvisibility=hidden,-g,-O2")
extern char *snoopy_util_systemd_convertCgroupEntryToUnitName(char const   * const  cgroupEntry ) ;
