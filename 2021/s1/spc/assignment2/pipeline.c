#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    char command[100][256];
    int cmds = 0;
    while(fgets(command[cmds],256,stdin)!=NULL)  //100 line
     {
         cmds++;
         
     }
    close(0);
    
    const char * split = " ";
    char * p;
    int new_pipe[2];
    int prev_pipe[2];
    if (pipe(prev_pipe) == -1)
    {
        perror("Cannot create pipe2");
    }
    int i;
    for(i = 0; i < cmds; i++)
    {
        int L = strlen(command[i]);
        command[i][L-1] = '\0';    //remove \n
        char * arguments[256]; //for execvp
        //char * arguments2[256];
        p = strtok(command[i],split);
  
        int j = 0;
        while(p!=NULL)
            {
                arguments[j] = p;
                p = strtok(NULL,split);
                j++;
            }
        arguments[j++] = NULL;
        
        if (i != cmds-1)
        {
            if (pipe(new_pipe) == -1)
            {
                perror("Cannot create pipe1");
            }
        }
        
        int my_pid;
        my_pid = fork();
        if (my_pid < 0)
        {
            printf("Failed Fork\n");
        }

        //child process
        else if(my_pid == 0){
            if(i != cmds-1)
            {
                close(new_pipe[0]);
                dup2(new_pipe[1],1);
                close(new_pipe[1]);
                //execvp(arguments[0], arguments);
            }
            if(i != 0)
            {
                close(prev_pipe[1]);
                dup2(prev_pipe[0],0);
                close(prev_pipe[0]);
                //execvp(arguments[0], arguments);
            }
            if (execvp(arguments[0], arguments) == -1)
            {
                printf("fail EXECVP\n");//  EXECVP fail
                exit(0);
            }
        }
        //parent process
        else
        {

            if (i != 0) // if it's not the first command
            {
                close(prev_pipe[1]);
            }
            wait(NULL);
            if (i != cmds-1)// if it's not the final command
            {
                prev_pipe[0] = new_pipe[0];
                prev_pipe[1] = new_pipe[1];
            }
        }
    }
    close(prev_pipe[0]);
    close(prev_pipe[1]);
    close(new_pipe[0]);
    close(new_pipe[1]);
    return 0;
    
}
