#include "headers.h"
#include "functions.h"

void kjobs(char *exten[1000],int ted,ptn hehe2){

    if(ted==3){
        int fir=atoi(exten[1]);
        int sec=atoi(exten[2]);
        if(fir>0){
            long long int hehe1=pret(hehe2,fir);
            if(hehe1==0){
                printf("No such job is there\n");
                return;

            }
            else{
                kill(hehe1,sec);
                //deleteall(hehe2,hehe1);
                //jbcount--;

            }
        }
        else{
            printf("No such job exists\n");
        }

    }
    else{
        printf("Invalid command\n");
    }


}