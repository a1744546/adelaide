/* execute.c - code used by small shell to execute commands */

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <signal.h>
#include    <sys/wait.h>
#include    <fcntl.h>

int execute3(char *argv[], int n_pipes, int comd[], char *rec[])
/*
 * purpose: run a program passing it arguments
 * returns: status returned via wait, or -1 on error
 *  errors: -1 on fork() or wait() errors
 */
{
    int    pid;
    int    child_info = -1;

    if(argv[0] == NULL)
    {
        return 0;
    }

    int prev_pipe[2];
    int new_pipe[2];
    int i;
    for(i=0; i < n_pipes; i++)
    {
        //Not the final command
        if (i != n_pipes-1) 
        {
            pipe(new_pipe);
        }
        
        pid = fork();
        if(pid < 0)
        {
            printf("Error"); //Forks and checks for errors
        }
        else if(pid > 0)
        {
            //Parent
            wait(NULL);
            if(i != 0) //not first command
            {
                close(prev_pipe[0]);
            }
            if(i != n_pipes - 1) //not final command
            {
                //prev_pipe = new_pipe
                prev_pipe[0] = new_pipe[0];
                prev_pipe[1] = new_pipe[1];
                close(prev_pipe[1]);
            }
        }
        //Child
        else
        {
            if(i != 0) //not first command
            {
                //rec input to prev_pipe
                dup2 (prev_pipe[0], 0);
                close(prev_pipe[0]);
            }
            if(i != n_pipes - 1) //not final command
            {
                //rec output to new_pipe
                dup2(new_pipe[1], 1);
                close(new_pipe[1]);
            }

            //rec if < or >
            //rec stdin to file
            if(rec[0] != NULL && i == 0)
            {
                int filefd_in = open(rec[0], O_RDONLY, 0);
                dup2 (filefd_in, 0);
            }
            //rec stdout to file
            if(rec[1] != NULL && i == n_pipes - 1)
            {
                int filefd_out = open(rec[1], O_WRONLY | O_CREAT, 0644);
                dup2 (filefd_out, 1);
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
