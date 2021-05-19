/**  smsh1.c  small-shell version 1
 **        first really useful version after prompting shell
 **        this one parses the command line into strings
 **        uses fork, exec, wait, and ignores signals
 **/

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <signal.h>
#include     <glob.h>
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

        //Finds number of arguments
        int i, argSize = 0;
        for(i = 0; i < 255; i++)
        {
            if(cmdline[i] == ' ')
            {
                argSize++;
            }
        }

        if ( (arglist = splitline(cmdline)) != NULL  ){

            //Define location of pipe
            int pipes = 0, skips[argSize];
            skips[0] = 0;
            int globNum = 0;
            char *redirect[2] = {NULL, NULL};
            glob_t globResults;
            //sets the pipe to NULL
            for(i = 0; i < argSize+1; i++)
            {

                if(*arglist[i] == '|')
                {
                    //checks for an amount of pipe and location of next commands
                    pipes++;
                    skips[pipes] = i+1;
                    arglist[i] = NULL;
                } else if (*arglist[i] == '<')
                {
                    redirect[0] = arglist[i+1];
                    arglist[i] = NULL;
                } else if (*arglist[i] == '>')
                {
                    redirect[1] = arglist[i+1];
                    arglist[i] = NULL;
                } else if (wildCheck(arglist[i]))
                {
                    //check glob
                    globNum = 1;
                    //set glob offset
                    globResults.gl_offs = i;
                    glob(arglist[i],GLOB_DOOFFS, NULL, &globResults);
                    //Moves offset into the glob
                    int j;
                    for (j = 0; j < i; j++)
                    {
                        globResults.gl_pathv[j] = arglist[j];
                    }
                }

            }

            //Executes command using pipe location and glob data
            if (globNum == 0)
            {
                result = execute4(arglist,pipes+1,skips, redirect);
            } else if (globNum == 1)
            {
                //Execute using glob info and free glob
                result = execute4(globResults.gl_pathv,pipes+1,skips, redirect);
                globfree(&globResults);
            }
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

//Check for wildcard
int wildCheck(char *arglist)
{
    int j = 0;
    //while not the end of line
    while (arglist[j] != '\0' || arglist != NULL)
    {
        //If wildcard, then return true
        if(arglist[j] == '*') {
            return 1;
        }
        j++;
    }

    //failed
    return 0;
}
