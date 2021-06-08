#include "slow_functions.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    pthread_t thid;//for slowfunc 2
   

    pthread_create(&thid,NULL,slow_function2,NULL);
    int i,j,err;
    pthread_t child[10];
    for(i = 0; i < 10; i++) {
     err = pthread_create(&child[i], NULL, slow_function1,NULL);//for slow function1
     if(err) {
      exit(0);
     }
    }
    pthread_join(thid, NULL);
    for(j = 0; j < 10; j++)
    pthread_join(child[j], NULL);
    return 0;

}
