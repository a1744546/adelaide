/**  smsh2.c  small-shell
 **        first really useful version after prompting shell
 **        this one parses the command line into strings
 **        uses fork, exec, wait, and ignores signals
 **/

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <string.h>
#include    <signal.h>
#include    "smsh.h"

#define    DFL_PROMPT    "> "

int main()
{
    char    *cmdline, *prompt, **arglist;
    int    result;
    void    setup();

    prompt = DFL_PROMPT ;
    setup();

    while ( (cmdline = next_cmd(prompt, stdin)) != NULL ){
        char *cp = cmdline;
        int n_pipe = 0;
        int pos = 1;
        int Ppos[3];
    
    //Count how many pipes are in the line
        while (*cp != '\0'){
            if  (*cp == '|'){
                n_pipe++;
                //store the position of each pipe in the line
                if (n_pipe == 1){ Ppos[0] = pos;}
                if (n_pipe == 2){ Ppos[1] = pos;}
                if (n_pipe == 3){ Ppos[2] = pos;}
                cp++;
                pos++;
            }
            cp++;
            pos++;
        }

        //If not pipe execute old code
        if (n_pipe == 0){
            if ( (arglist = splitline(cmdline)) != NULL  ){
                result = execute(arglist);
                freelist(arglist);
            }
        } else {

            //Fork before pipe so execvp dont exit shell
            int    pid1 ;
            int    child_info = -1;
            pid1 = fork();
            if ( pid1 == 0 ){
                //variables to make the pipes
                int old_fds[2];
                int new_fds[2];
                int    pid;
                int i = n_pipe+1;
                int j;

                //loop to pipe as many time as pipes count
                for (j = 0; j < i; j++){
                     if (j < i-1){
                        pipe(new_fds);
                    }
                    //fork inside the pipe
                    pid = fork();
                     
                     if ( pid == 0) {
                         //Splitline break when befor the | and argv array
                         if (j == 0){ arglist = splitline(cmdline);}
                         if (j == 1){ arglist = splitline(&cmdline[Ppos[0]]);}
                         if (j == 2){ arglist = splitline(&cmdline[Ppos[1]]);}
                         if (j == 3){ arglist = splitline(&cmdline[Ppos[2]]);}

                        //write in the pide
                        if ( j > 0 ){
                            if ( dup2(old_fds[0], 0) == -1 )
                                return 0;
                            close(old_fds[0]); // process doesn't write to pipe
                            close(old_fds[1]); // stdin is duped, close pipe
                        }

                        //read from the pide
                        if ( j < i-1 ){
                            close(new_fds[0]);  // process doesn't read from pipe
                            fflush(stdout);
                            if (dup2(new_fds[1], 1) == -1 )
                                return 0;
                            close(new_fds[1]);  // stdout is duped, close pipe
                        }
                        
                        //execute the program with the arguments
                        execvp(arglist[0], arglist);

                    } else if ( pid > 0) {
                        // close unused file descriptors and flush standard out
                        if ( j > 0 ){
                            close(old_fds[0]);
                            fflush(stdout);
                            close(old_fds[1]);
                        }

                        //make the new pipe the old one to keep the loop
                        if ( j < i-1 ){
                            old_fds[0] = new_fds[0];
                            old_fds[1] = new_fds[1];
                        }

                        //wait for the pipe process to finished
                        waitpid(pid, NULL, 0);
                    }
                }

                // close the last unused file descriptors and flush standard out
                close(old_fds[0]);
                fflush(stdout);
                close(old_fds[1]);

            } else if ( pid1 > 0 ) {
                //wait for fork before pipe to finished
                if ( wait(&child_info) == -1 )
                    perror("wait");
            }
        }
        
        free(cmdline);
    }
    
    return 0;
}

void setup()
/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */
{
    signal(SIGINT,  SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n)
{
    fprintf(stderr,"Error: %s,%s\n", s1, s2);
    exit(n);
}
