#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
   
    char command[100][10];
    FILE* fp;
    fp = fopen("cmdfile","r");
    int i;
   for (i=0; i < 100; i++)   //100 line
    {
        if(fscanf(fp,"%s",command[i])==EOF)
        break;
        //for(j=0; j<10; j++)   //10 arguments
        //fscanf(fp,"%s",command[i]);
        system(command[i]);
        //printf("%s\n",command[i]);
    }
    fclose(fp);
    
//    while(fgets(command[i],10,fp)!=NULL)  //100 line
//     {
//
//         //for(j=0; j<10; j++)   //10 arguments
//         //fgets(fp,"%s",command[i]);
//         printf("%s\n",command[i]);
//         i++;
//         system(command[i]);
//     }
//     fclose(fp);
//    char * arguments[2] = {&command[0][0], NULL};
//
//    int id = fork();
//    if(id<0){
//        printf("error in fork");
//    }
//    else if(id>0){
//        wait(NULL);
//    }
//    else{   //child
//
//        //int my_exec = execvp(arguments[0], arguments);
//        //system(command);
//    }
    
return 0; }
