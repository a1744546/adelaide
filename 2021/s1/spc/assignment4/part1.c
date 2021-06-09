#include "slow_functions.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    pthread_t thid;//Creates a thread for slowfunc 2
   

    if(pthread_create(&thid,NULL,slow_function2,NULL))
    {
        fprintf(stderr, "Error creating  thread for slowfunc2\n");
        return 1;
    }
    int i,j,err;
    pthread_t child[10];//Creates a thread for slow function1
    for(i = 0; i < 10; i++) {
        if(pthread_create(&child[i], NULL, slow_function1, NULL))
        {
            fprintf(stderr, "Error creating  thread for slowfunc1\n");
            return 1;
        }
    }
    // Ensure Threads Join Well
    if(pthread_join(thid, NULL))
    {
        fprintf(stderr, "Error joining thread for slowfunc2\n");
        return 2;
    }
    for(j = 0; j < 10; j++)
    {
        if(pthread_join(child[j], NULL))
        {
            fprintf(stderr, "Error joining thread for slowfunc1\n");
            return 2;
        }
        
    }
    return 0;

}
