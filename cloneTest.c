#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int add_stack = 2;
    printf(1, "clone %d", clone((void *)add_stack));
    exit();
}