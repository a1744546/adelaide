/* execute.c - code used by small shell to execute commands */

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <signal.h>
#include    <sys/wait.h>

int execute2(char *argv[], int n_pipes, int comd[])
/*
 * purpose: run a program passing it arguments
 * returns: status returned via wait, or -1 on error
 *  errors: -1 on fork() or wait() errors
 */
{
    int    pid;
    int    child_info = -1;

    if( argv[0] == NULL )
    {        
        return 0;
    }

    int i;
    int prev_pipe[2];
    int new_pipe[2];
    for(i=0; i < n_pipes; i++)
    {
        //Not the final command
        if (i != n_pipes-1) 
        {
            pipe(new_pipe);
        }

        //Forks and checks for errors
        pid = fork();
        if(pid < 0) 
        {
            printf("Error");
        }
        //Parent
        else if(pid > 0)
        {   
            wait(NULL);
            //not first command
            if(i != 0) 
            {
                close(prev_pipe[0]);
            }
            //not final command
            if(i != n_pipes-1) 
            {
                prev_pipe[0] = new_pipe[0];
                prev_pipe[1] = new_pipe[1];
                close(prev_pipe[1]);
            }
        }
        //Child
        else
        {
            //not first command
            if(i != 0) 
            {
                //rec input to prev_pipe
                dup2 (prev_pipe[0], 0);
                close(prev_pipe[0]);
            }
            //not final command
            if(i != n_pipes-1) 
            {
                //rec output to new_pipe
                dup2(new_pipe[1], 1);
                close(new_pipe[1]);
            }

            signal(SIGINT, SIG_DFL);
            signal(SIGQUIT, SIG_DFL);
            
            //Reads current command and moves null term array to follow command
            execvp(argv[comd[i]], &argv[comd[i]]);
            perror("cannot execute command");
            exit(1);

        }



    }

    return child_info;
}
