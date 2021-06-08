#include "slow_functions.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    pthread_t thid;//for slowfunc 2
   

    pthread_create(&thid,NULL,slow_function2,NULL);
    
    pthread_t child[10];
    for(i = 0; i < 9; i++) {
     err = pthread_create(&child[i], NULL, slow_function1,NULL);//for slow function1
     if(err) {
      exit(0);
     }
    }
    pthread_join(thid, NULL);
    for(i = 0; i < 10; i++)
    pthread_join(child[i], NULL);
    return 0;

}
