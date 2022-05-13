#include "headers.h"
#include "functions.h"

void fgprocess(char *arr[1000], int len, ptn hehe)
{

    if (len > 2)
    {
        printf("Too many arguments\n");
    }
    else
    {
        int id = atoi(arr[1]);
        long long int pir = pret(hehe, id);
        //printf("%lld\n", pir);
        signal(SIGTTIN, SIG_IGN); 
        signal(SIGTTOU, SIG_IGN);
        tcsetpgrp(STDIN_FILENO, pir);
        if (pir == 0)
        {
            printf("No such job is there\n");
        }
        else
        {
            int w, s;
            fopid = pir;
            kill(pir, SIGCONT);

            w = waitpid(pir, &s, WUNTRACED);
            if(WIFSTOPPED(s)!=1){
                deleteall(hehe, pir);

            }
            //
        }
        tcsetpgrp(STDIN_FILENO, getpgid(getpid())); 

        signal(SIGTTIN, SIG_DFL);
        signal(SIGTTOU, SIG_DFL);
    }
}