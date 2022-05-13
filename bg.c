#include "headers.h"
#include "functions.h"

void bgprocess(char *arr[1000], int len, ptn hehe)
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
        if (pir == 0)
        {
            printf("No such job is there\n");
        }
        else
        {
            int w,s;
            kill(pir, SIGCONT);
            //w = waitpid(pir, &s, WNOHANG);
            
        }
    }
}