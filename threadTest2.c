// this is a test for thread functions
#include "types.h"
#include "stat.h"
#include "user.h"
// #include "thread.h"

int arrsum = 0;
int arr[] = {1, 2, 3, 4, 5, 6}; // 1 + 2 + 3 + 4 + 5 + 6 = 21

void sum(void *x){
    arrsum += *((int *)x);
}

int main(){
   int join_pid;
    for(int i = 0; i < 6; i++){
        join_pid = thread_create(sum, &arr[i]);
        printf(1, "thread %d joined : %d\n",i ,  join_pid);
    }
    for(int i = 0; i < 6; i++){
        join();
    }
    printf(1,"*%d\n", arrsum);

    printf(1, "TEST PASSED\n");
     
    exit(); 
}
