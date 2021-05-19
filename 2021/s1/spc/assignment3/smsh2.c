/**  smsh1.c  small-shell version 1
 **        first really useful version after prompting shell
 **        this one parses the command line into strings
 **        uses fork, exec, wait, and ignores signals
 **/

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <signal.h>
#include    "smsh.h"

#define    DFL_PROMPT    "> "

int main()
{
    char *cmdline, *prompt, **arglist;
    
    void setup();

    prompt = DFL_PROMPT ;
    setup();
    int result;
    while ((cmdline = next_cmd(prompt, stdin)) != NULL)
        //Finds number of arguments
        int i, arg_size = 0;
        for(i = 0; i < 255; i++)
        {
            if(cmdline[i] == ' ')
            {
                arg_size++;
            }
        }


        if ((arglist = splitline(cmdline)) != NULL){

            //Define location of pipe
            int n_pipes = 0, comd[arg_size];
            comd[0] = 0;
            //sets the pipe to NULL
            for(i = 0; i < arg_size+1; i++)
            {
                if(*arglist[i] == '|')
                {
                    n_pipes++;
                    comd[n_pipes] = i+1;
                    arglist[i] = NULL;
                }
            }
            //Executes command using pipe location
            result = execute2(arglist,n_pipes+1,comd);
            freelist(arglist);
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
