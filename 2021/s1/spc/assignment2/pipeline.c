#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    char command[100][256];
//    FILE* fp;
//    fp = fopen("cmdfile1","r");
    int cmds = 0;
    while(fgets(command[cmds],256,stdin)!=NULL)  //100 line
     {
         cmds++;
     }
    fclose(fp);
    
    const char * split = " ";
    char * p1;
    char * p2;
    int i;
    for(i = 0; i < cmds; i++)
    {
            
        int L = strlen(command[i]);
        command[i][L-1] = '\0';    //remove \n
        char * arguments1[256]; //for execvp
        char * arguments2[256];
        p1 = strtok (command[i],split);
        p2 = strtok (command[i++],split);//split command[i] by " "
        int j = 0;
        while(p1!=NULL && p2!=NULL && i<99)
            {
                arguments1[j] = p1;
                p1 = strtok(NULL,split);
                arguments2[j] = p2;
                p2 = strtok(NULL,split);
                j++;
            }
        arguments1[j++] = NULL;
        arguments2[j++] = NULL;
        int my_pipe[2];
        if (pipe(my_pipe) == -1)
        {
            perror("Cannot create pipe");
        }
        
        int my_pid;
        my_pid = fork();
        if (my_pid < 0)
        {
            printf("Failed Fork\n");
        }
        else if (my_pid == 0)
        {
            //parent process
            close(my_pipe[1]);
            dup2(my_pipe[0], STDIN_FILENO);
            execvp(arguments2[0], arguments2);
          //wait(NULL);
          //printf("execvp done\n\n");
        }
        else{
        //child process
            // Close Read
            close(my_pipe[0]);
            dup2(my_pipe[1], STDOUT_FILENO);
            //printf("Hello\n");
            //write(my_pipe[1], "hello", strlen("hello") + 1);
            execvp(arguments1[0], arguments1);
            }
          
    }
   
    
    
    return 0;

}
