#include "headers.h"
#include "functions.h"




void spec4(char *abce[],int len)
{
    int pidval;
    if(len>2){
        printf("too many arguments\n");
        return;
    }
    if(len==2){
        pidval=atoi(abce[1]);
    }
    else{
        pidval = getpid();

    }
    long long int nvg1,nvg2;
    
    printf("pid--%d\n", pidval);
    char andrew[1000]={'\0'};
    sprintf(andrew, "/proc/%d/stat", pidval);
     
    FILE *jfe;
    jfe = fopen(andrew, "r");
    if(jfe==NULL){
        printf("File can't be opened\n");
        return;
    }
   
    char honey[1000]={'\0'};
    int qwad=1;
    int xc=0;
     
    while (fgets(honey, sizeof(honey), jfe) != NULL)
    {
        if(qwad==5){
            nvg1=atoi(honey);
            xc++;

        }
        if(qwad==8){
            nvg2=atoi(honey);
            xc++;

        }
        if(xc==2){
            break;
        }
        qwad++;


    }
    
    fclose(jfe);
    char djk[1000] = {'\0'};

    sprintf(djk, "/proc/%d/status", pidval);

    FILE *fileping;

    fileping = fopen(djk, "r");

    if (fileping == NULL)
    {
        printf("File error can't be opened\n");
        return;
    }
    
    char harry[1000] = {'\0'};
    int dek = 1;
    long long int e1, e2;
    char *uho;
    char string[1000] = {'\0'};
    char string1[1000] = {'\0'};
    int mcc = 0;
    int mc1 = 0;
    
    while (fgets(harry, sizeof(harry), fileping) != NULL)
    {
        if (dek == 3)
        {
            //printf("%s\n",uho);
            uho = strtok(harry, ":");
            uho = strtok(NULL, ":");
            //printf("%s\n",uho);
            for (int i = 0; i < strlen(uho); i++)
            {
                if (uho[i] != '\t' && uho[i]!='\n')
                {
                    string[mcc] = uho[i];
                    mcc++;
                }
            }
            string[mcc]='\0';
        }

        if (dek == 18)
        {
            //printf("%s\n",uho);
            uho = strtok(harry, ":");
            uho = strtok(NULL, ":");
             //printf("%s\n",uho);
            for (int i = 0; i < strlen(uho); i++)
            {
                if (uho[i] != '\t' && uho[i]!='\n' )
                {
                    string1[mc1] = uho[i];
                    mc1++;
                }
            }
            string1[mc1]='\0';
            break;
        }
        dek = dek + 1;
    }
    

    fclose(fileping);

    if(nvg1==nvg2){
        printf("Process Status -- {%s+}\n", string);

    }
    else{
        printf("Process Status -- {%s}\n", string);

    }

    
    printf("Memory -- %s {Virtual memory}\n", string1);

    char deccan[1000]={'\0'};
    sprintf(deccan,"/proc/%d/exe",pidval);
    long long int gbn;
    char hundr[1000]={'\0'};
    gbn= readlink(deccan, hundr, 1000);
    if(gbn<0){
        printf("Unable to open file\n");
        return;
    }
    printf("Executable Path -- %s\n",hundr);












}
