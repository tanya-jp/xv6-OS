#include "types.h"
#include "stat.h"
#include "user.h"

#define PGSIZE 4096

int
thread_create(void (*fn) (void *), void *arg)
{
  void* stack = malloc(PGSIZE * 2);
  
  //check stack and update
  if((uint)stack % PGSIZE)
    stack += (PGSIZE - (uint)stack % PGSIZE);

  int tid = clone(stack);

  if (tid == -1)
    return -1;

  if (tid != 0) //Parent
  {
    return tid;
  }
  else //Child
  {
    fn(arg);
	  free(stack);
    exit();
  }

  return -1;
}