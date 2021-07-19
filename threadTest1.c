/* thread user library functions */
#include "types.h"
#include "user.h"

#undef NULL
#define NULL ((void*)0)

#define PGSIZE (4096)

int ppid;
int global = 1;

#define assert(x) if (x) {} else { \
   printf(1, "%s: %d ", __FILE__, __LINE__); \
   printf(1, "assert failed (%s)\n", # x); \
   printf(1, "TEST FAILED\n"); \
   kill(ppid); \
   exit(); \
}

void worker(void *arg_ptr);

int
main(int argc, char *argv[])
{
   ppid = getpid();

   int arg = 35;
   int thread_pid = thread_create(worker, &arg);
   assert(thread_pid > 0);
   int join_pid = join();
   printf(1, "thread 1 joined : %d\n", join_pid);
   printf(1, "global : %d\n", global);

   int thread_pid1 = thread_create(worker, &arg);
   assert(thread_pid1 > 0);
   int join_pid1 = join();

   printf(1, "thread 2 joined : %d\n", join_pid1);
   printf(1, "global : %d\n", global);


   assert(global == 3);

   printf(1, "TEST PASSED\n");

   exit();
}

void
worker(void *arg_ptr) {
   int arg = *(int*)arg_ptr;
   assert(arg == 35);
   //assert(global == 1);
   global++;
   exit();
}