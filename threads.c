#include "types.h"
#include "stats.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "mmu.h"

int thread_create(void*(*start_routine)void*, void*(arg)){
    char* stack = malloc(PGSIZE);
    if(stack == 0)
        return -1;
    int id = clone(stack);
    if(id < 0){
        printf("error calling clone\n");
        return -1;
    }
    if(id == 0){
        (start_routine)(arg);
        free(stack);
        exit();
    }

    return id;
}