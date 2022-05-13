#include "headers.h"
#include "functions.h"

ptn makenode(emt x, emt y, char loki[1000])
{
    ptn p;
    p = (ptn)malloc(sizeof(struct Linked));
    assert(p != NULL);

    p->num = x;
    p->pid = y;
    strcpy(p->nam, loki);

    p->Next = NULL;
    return p;
}



int pret(ptn hehe,int x){
    assert(hehe != NULL);

    ptn P = hehe->Next;

    if (P == NULL)
    {
        //printf("NO ELEMENTS\n");
        return 0;
    }
    while (P != NULL)
    {

        if (P->num == x)
        {
            return P->pid;
        }
        P = P->Next;
    }
    return 0;

}

void insertr(ptn p, emt x, emt y, char lokii[1000])
{
    ptn t = makenode(x, y, lokii);

    while (p->Next != NULL)
    {
        p = p->Next;
    }
    p->Next = t;
}

int statuser(long long int hhj)
{
    char djk[1000] = {'\0'};

    sprintf(djk, "/proc/%lld/status", hhj);

    FILE *fileping;
    char status;

    fileping = fopen(djk, "r");
    char si[1000];

    if (fileping == NULL)
    {
        printf("File error can't be opened\n");
        return -1;
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
                if (uho[i] != '\t' && uho[i] != '\n')
                {
                    string[mcc] = uho[i];
                    mcc++;
                }
            }
            string[mcc] = '\0';
            break;
        }

        dek = dek + 1;
    }

 
    char helo[1000] = "T (stopped)";
    if (strcmp(helo, string) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void printlist(ptn L, char *ahy[1000], int you)
{
    assert(L != NULL);
    ptn P = L->Next;

    if (P == NULL)
    {
        printf("No Jobs\n");
        return;
    }
    if (you > 1)
    {
        if (strcmp(ahy[1], "-r") == 0)
        {
            while (P != NULL)
            {
                //printf("%lld ",P->num);
                //printf(" ");
                long long int pider = P->pid;
                long long int kol = P->num;

                
                int hehe=statuser(pider);
                if(hehe==1){
                    printf("[%lld] ", kol);
                    printf("Running ");
                    printf("%s ", P->nam);
                    printf("[%lld]\n", P->pid);


                }
                

                

                P = P->Next;
            }
        }

        else if (strcmp(ahy[1], "-s") == 0)
        {
            while (P != NULL)
            {
                //printf("%lld ",P->num);
                //printf(" ");
                long long int pider = P->pid;
                long long int kol = P->num;

                int hehe=statuser(pider);
                if(hehe==0){
                    printf("[%lld] ", kol);
                    printf("Stopped ");
                    printf("%s ", P->nam);
                    printf("[%lld]\n", P->pid);


                }

                P = P->Next;
            }
        }

        else
        {
            printf("Wrong command\n");
            return;
        }
    }
    else
    {
        while (P != NULL)
        {
            //printf("%lld ",P->num);
            //printf(" ");
            long long int pider = P->pid;
            long long int kol = P->num;

            printf("[%lld] ", kol);
            int hehe=statuser(pider);
            if(hehe==1){
                printf("Running ");
            }
            else if(hehe==0){
                printf("Stopped ");

            }

            printf("%s ", P->nam);
            printf("[%lld]\n", P->pid);

            P = P->Next;
        }
    }
}

ptn Getpid(ptn p, long long int pi)
{
    assert(p != NULL);

    ptn P = p->Next;

    if (P == NULL)
    {
        //printf("NO ELEMENTS\n");
        return NULL;
    }
    while (P != NULL)
    {

        if (P->pid == pi)
        {
            return P;
        }
        P = P->Next;
    }
}

void deleteall(ptn p, emt x)
{
    assert(p != NULL);
    ptn temp1 = p;
    ptn P = p->Next;
    ptn temp;

    if (P == NULL)
    {
        //printf("NO ELEMENTS\n");
        return;
    }

    while (P != NULL)
    {
        if (P->pid == x)
        {
            temp = P->Next;
            deletn(P);
            temp1->Next = temp;
            break;
        }
        temp1 = P;

        P = P->Next;
    }
}

void deletn(ptn p)
{
    if (!p)
    {
        free(p);
    }
}
