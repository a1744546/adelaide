#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    char command[100][256];
    FILE* fp;
    fp = fopen("cmdfile","r");
    int cmds = 0;
    while(fgets(command[cmds],256,fp)!=NULL)  //100 line
     {
         cmds++;
     }
    fclose(fp);
    const char * split = " ";
    char * p;
    
    for(int i = 0; i < cmds; i++){
        
        int L = strlen(command[i]);
        command[i][L-1] = NULL;    //remove \n
        char * arguments[256]; //for execvp

        p = strtok (command[i],split); //split command[i] by " "
        int j = 0;
        while(p!=NULL) {
            arguments[j] = p;
            p = strtok(NULL,split);
            j++;
        }
        arguments[j++] = NULL;
        
        pid_t my_pid;
        my_pid = fork();
        if (my_pid < 0)
        {
            printf("Failed Fork\n");
        }
        else if (my_pid > 0){
            //parent process
          wait(NULL);
          //printf("execvp done\n\n");
        }
        else{
        //child process
            if (execvp(arguments[0], arguments) <0 ){
              //perror("error on exec");
              exit(0);
            }
          }
    }
    
    return 0;
}
