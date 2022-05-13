#include "headers.h"
#include "functions.h"


void sigintering(ptn ple,long long int heu,char namer[1000]){
    kill(heu,SIGSTOP);
    jbcount++;
    insertr(ple,jbcount,heu,namer);
  
    
}

void proc(char *qwert[], int length,ptn ple,char letsna[1000])
{

    pid_t val;
    qwert[length] = NULL;
    
     
    
    //printf("%s",qwert[1]);

    val = fork();
    
    if (val < 0)
    {
        printf("Child is not created\n");

        return;
    }

       
    

    if (val == 0)
    {
        int rr = -100;
        if (strcmp(qwert[length - 1], "&") == 0)
        {

          

            printf("%d\n", getpid());
            qwert[length - 1] = NULL;
        }

        setpgid(0,0);

        rr = execvp(qwert[0], qwert);
        if (rr == -1)
        {
            printf("Command not found\n");
            exit(0);
        }

        exit(0);

        //exit(0);
    }
    else
    {
        setpgid(val, 0);
        

        if (strcmp(qwert[length - 1], "&") != 0)
        {
            signal(SIGTTIN, SIG_IGN);
            signal(SIGTTOU, SIG_IGN);
            tcsetpgrp(STDIN_FILENO, val);

            strcpy(abc,letsna);
            
            fopid=val;
            //printf(" there %lld\n",fopid);

            int ybg;
           

            waitpid(val, &ybg, WUNTRACED);
            if(WIFSTOPPED(ybg)==1){
                sigintering(ple,val,letsna);

            }
            fopid=-1;
            tcsetpgrp(STDIN_FILENO, getpgid(getpid())); 
            signal(SIGTTIN, SIG_DFL);
            signal(SIGTTOU, SIG_DFL);

           
        }
        else{
            
            setpgid(getpid(), 0);
            tcsetpgrp(STDIN_FILENO, getpgid(getpid()));
            jbcount++;
            insertr(ple,jbcount,val,letsna);
        }
       
        

        
    }
}