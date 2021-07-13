#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int add_stack = 2;
    int* x = 2;
    printf(1, "clone %d", clone((void *)add_stack));
    printf(1, "clone %d", join();
    printf(1, "clone %d", lock(x));
    printf(1, "clone %d", unlock(x));
    exit();
}