#include "headers.h"
#include "functions.h"

char nano[1000];

ptn pleas = NULL;

long long int myid;

int oa = 0;




void comdline()
{
    char hostname[1000];

    gethostname(hostname, 1000);

    char us[1000];
    getlogin_r(us, 1000);

    char halo[1023] = {'\0'};
    getcwd(halo, sizeof(halo));

    printf("<%s@%s:", us, hostname);

    // printf("\n%s\n",halo);
    // printf("\n%s\n",nano);
    int ug = 0;
    for (int i = 0; i < strlen(nano); i++)
    {
        if (halo[i] != nano[i])
        {
            ug = 1;
            break;
        }
    }
    char vano[1023] = {'\0'};
    if (ug == 0)
    {
        vano[0] = '~';

        int slash = 1;
        for (int k = strlen(nano); k < strlen(halo); k++) // need to change here
        {

            vano[slash] = halo[k];
            slash++;
        }

        printf("%s>", vano);
    }
    else
    {

        printf("%s>", halo);
    }
}


void siginter(int signo){
    printf("\n");
    comdline();
    fflush(stdout);
}
  


void sigint(int sig_num)
{

    if (fopid == -1)
    {
        printf("\n");
        comdline();
        fflush(stdout);
        return;
    }

    if (fopid != -1)
    {
        printf("\n");
        kill(fopid, 9);
        fopid = -1;
        signal(SIGINT, sigint);
    }
}



void plhandle(int agay)
{
    int status;
    int pid = waitpid(-1, &status, WNOHANG);

    if (pid > 0)
    {
        ptn ptr = NULL;
        ptr = Getpid(pleas, pid);
        deleteall(pleas, pid);
        if (ptr == NULL)
        {
            return;
        }
        if (WIFEXITED(status))
        {
            //sleep(2);
            printf("\n%s with pid %lld exited normally with job number %lld\n", ptr->nam, ptr->pid, ptr->num);
        }
        else
        {
            printf("\n%s with pid %lld exited abnormally with job number %lld\n", ptr->nam, ptr->pid, ptr->num);
        }
        comdline();
        fflush(stdout);
    }
    return;
}

void cd(ptn ple)
{

    char hostname[1000];

    gethostname(hostname, 1000);

    char us[1000];
    getlogin_r(us, 1000);

    char patha[1000] = {'\0'};

    getcwd(nano, sizeof(nano));

    int ug;
    int gru;
    int qw;

    int rt;
    int rrt;
    int ree;

    int dco = 0;
    int mn = 0;
    char circle[10][1000] = {'\0'};

    FILE *filep1, *filep;

    filep = fopen("history.txt", "a");
    if (filep == NULL)
    {
        perror("");
    }
    fclose(filep);
    filep1 = fopen("history.txt", "r");
    if (filep1 == NULL)
    {
        perror("");
    }
    char addj[1000] = {'\0'};
    while (fgets(addj, sizeof(addj), filep1) != NULL)
    {
        continue;
    }
    if (addj[strlen(addj) - 1] == '\n')
    {
        addj[strlen(addj) - 1] = '\0';
    }

    fclose(filep1);

    char lineco[1000] = {'\0'};
    

    while (1)
    {
        //ptn fz=fz1;
        fopid = -1;
        
        signal(SIGINT, sigint);
        signal(SIGTSTP, siginter);
        
        
        

        comdline();

        char abc[1000][1000] = {'\0'};
        char halo[1023] = {'\0'};
        getcwd(halo, sizeof(halo));
        //signal(SIGTSTP,sigtstp_handler);

        gru = 0;

        char line[1000];

        if(fgets(line, sizeof(line), stdin)==NULL){
            printf("\n");
            exit(EXIT_SUCCESS);


        }
        
        //     

        // }

        line[strlen(line) - 1] = '\0';

        FILE *filepo, *filepo2;
        char c;
        char bug[1000];
        if (strcmp(lineco, line) != 0 && strcmp(addj, line) != 0)
        {
            strcpy(addj, "");
            if (strcmp(line, "") != 0)
            {
                chdir(nano);
                filepo = fopen("history.txt", "a");
                if (filepo == NULL)
                {
                    perror("");
                }
                filepo2 = fopen("history.txt", "r");
                int count = 0;
                for (c = getc(filepo2); c != EOF; c = getc(filepo2))
                {
                    if (c == '\n')
                    {
                        count = count + 1;
                    }
                }
                if (count == 20)
                {
                    FILE *fptr1, *fptr2, *fptr3, *fptr4;
                    char ceo;
                    fptr1 = fopen("history.txt", "r");
                    if (fptr1 == NULL)
                    {
                        perror("");
                    }

                    fptr2 = fopen("test.txt", "w");
                    if (fptr2 == NULL)
                    {
                        perror("");
                    }

                    ceo = fgetc(fptr1);
                    int h = 0;
                    while (ceo != EOF)
                    {
                        if (ceo == '\n' && h == 0)
                        {
                            h = 1;
                            ceo = fgetc(fptr1);

                            continue;
                        }
                        if (h == 1)
                        {
                            fputc(ceo, fptr2);
                            ceo = fgetc(fptr1);
                            continue;
                        }
                        ceo = fgetc(fptr1);
                    }
                    fclose(fptr1);
                    fclose(fptr2);

                    fptr3 = fopen("history.txt", "w");
                    fptr4 = fopen("test.txt", "r");
                    char manj;
                    manj = fgetc(fptr4);

                    while (manj != EOF)
                    {

                        fputc(manj, fptr3);
                        manj = fgetc(fptr4);
                    }
                    fclose(fptr3);
                    fclose(fptr4);
                    strcpy(bug, line);
                    fprintf(filepo, "%s\n", bug);
                }
                else
                {
                    strcpy(bug, line);
                    fprintf(filepo, "%s\n", bug);
                }
                fclose(filepo);
                fclose(filepo2);
                chdir(halo);
            }
        }
      
        if (strcmp(line, "") == 0)
        {
            
            //printf("\n");

            continue;
        }
        
       

        char *tokenize = strtok(line, ";");

        while (tokenize != NULL)
        {
            strcpy(abc[gru], tokenize);
            //printf("\n%s\n",abc[gru]);
            tokenize = strtok(NULL, ";");
            gru++;
        }

        for (int hh = 0; hh < gru; hh++)
        {
            //ptn fz=fz1;
            int thber = 0;
            for (int zox = 0; zox < strlen(abc[hh]); zox++)
            {
                if (abc[hh][zox] == '|')
                {
                    thber = 1;
                    break;
                }
            }
            if (thber == 1)
            {
                pips(abc[hh]);
                continue;
            }
            char *pro4[1000] = {'\0'};
            int avsa = 0;
            char diff[1000] = {'\0'};
            strcpy(diff, abc[hh]);
            //int thberi=0;

            char *tokening = strtok(diff, " ");
            while (tokening != NULL)
            {

                pro4[avsa] = tokening;

                tokening = strtok(NULL, " ");
                avsa++;
            }
            int lef = -1;
            int rig = -1;
            int righ = -1;
            for (int dn = 0; dn < avsa; dn++)
            {
                if (strcmp(pro4[dn], "<") == 0)
                {
                    lef = dn;
                }
                if (strcmp(pro4[dn], ">") == 0)
                {
                    rig = dn;
                }
                if (strcmp(pro4[dn], ">>") == 0)
                {
                    righ = dn;
                }
            }
            char lol[1000] = {'\0'};
            if (lef != -1 && (rig != -1 || righ != -1))
            {
                
                if (rig != -1)
                {
                    if(rig==avsa-1){
                        printf("Invalid command\n");
                        continue;
                    }
                    strcpy(pro4[lef], pro4[rig - 1]);
                    avsa = lef + 1;
                    strcpy(lol, pro4[rig + 1]);
                }
                else
                {
                    if(righ==avsa-1){
                        printf("Invalid command\n");
                        continue;
                    }
                    strcpy(pro4[lef], pro4[righ - 1]);
                    avsa = lef + 1;
                    strcpy(lol, pro4[righ + 1]);
                }
            }
            else if (lef != -1)
            {
                strcpy(pro4[lef], pro4[avsa - 1]);
                avsa = lef + 1;
            }
            else if (rig != -1 || righ != -1)
            {
                if (rig != -1)
                {
                    if(rig==avsa-1){
                        printf("Invalid command\n");
                        continue;
                    }

                    avsa = rig;
                    strcpy(lol, pro4[rig + 1]);
                }
                else
                {
                    if(righ==avsa-1){
                        printf("Invalid command\n");
                        continue;
                    }

                    avsa = righ;
                    strcpy(lol, pro4[righ + 1]);
                }
            }
            if (strcmp(pro4[0], "ls") == 0 || strcmp(pro4[0], "cd") == 0 || strcmp(pro4[0], "pwd") == 0 || strcmp(pro4[0], "history") == 0 || strcmp(pro4[0], "echo") == 0 || strcmp(pro4[0], "pinfo") == 0 || strcmp(pro4[0], "jobs") == 0 || strcmp(pro4[0], "sig") == 0 || strcmp(pro4[0], "bg") == 0 || strcmp(pro4[0], "fg") == 0)
            {

                // printf("hello1\n");
                // printf("%s\n",abc[hh]);
                if (strcmp(pro4[0], "bg") == 0)
                {
                    bgprocess(pro4, avsa, ple);
                    continue;
                }
                if (strcmp(pro4[0], "fg") == 0)
                {
                    fgprocess(pro4, avsa, ple);
                    continue;
                }
                if (strcmp(pro4[0], "sig") == 0)
                {
                    kjobs(pro4, avsa, ple);
                    continue;
                }

                if (strcmp(pro4[0], "jobs") == 0)
                {
                    printlist(ple, pro4, avsa);

                    continue;
                }
                if (strcmp(pro4[0], "pinfo") == 0)
                {
                    int origing;
                    dup2(STDOUT_FILENO, origing);
                    if (rig != -1 || righ != -1)
                    {
                        if (rig != -1)
                        {
                            int fdd = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                            if (fdd < 0)
                            {
                                perror("File not found\n");
                                continue;
                            }

                            if (dup2(fdd, STDOUT_FILENO) < 0)
                            {
                                perror("Unable to duplicate file descriptor");
                                continue;
                            }
                            close(fdd);
                        }
                        else
                        {
                            int fdd = open(lol, O_APPEND | O_WRONLY | O_CREAT, 0644);
                            if (fdd < 0)
                            {
                                perror("File not found\n");
                                continue;
                            }

                            if (dup2(fdd, STDOUT_FILENO) < 0)
                            {
                                perror("Unable to duplicate file descriptor");
                                continue;
                            }
                            close(fdd);
                        }
                    }

                    spec4(pro4, avsa);
                    dup2(origing, STDOUT_FILENO);

                    continue;
                }

                rt = -1;
                rrt = -1;
                for (int jj = 0; jj < strlen(abc[hh]); jj++)
                {
                    if (abc[hh][jj] == 'c' && abc[hh][jj + 1] == 'd')
                    {
                        if ((jj + 2) < strlen(abc[hh]) && abc[hh][jj + 2] != ' ')
                        {
                            printf("command not found\n");
                            break;
                        }
                        for (int mm = jj + 2; mm < strlen(abc[hh]); mm++)
                        {
                            if (abc[hh][mm] != ' ')
                            {
                                if (rrt == -1)
                                {
                                    rrt = mm;
                                }
                                rt = mm;
                            }
                        }

                        ///printf("\n%d %d\n",rrt,rt);
                        int asd = 0;
                        char hyum[1000] = {'\0'};
                        int qwe = 0;
                        for (int mm = rrt; mm <= rt; mm++)
                        {
                            if (abc[hh][mm] == ' ')
                            {
                                asd = 1;
                                break;
                            }
                            hyum[qwe] = abc[hh][mm];

                            qwe++;
                        }

                        if (asd == 1)
                        {
                            printf("too many arguments\n");
                            break;
                        }
                        // char mb[1000];
                        // if(dco<2){
                        //     if(strcmp(hyum,"~")==0 && strcmp(hyum,"-")!=0 ){
                        //         strcpy(circle[dco],nano);
                        //         printf("%d %s\n",dco,circle[dco]);
                        //         printf("help\n");
                        //         dco++;

                        //     }
                        //     else if(strcmp(hyum,"-")!=0){
                        //         getcwd(mb,sizeof(mb));
                        //         strcpy(circle[dco],mb);
                        //         printf("%d %s\n",dco,circle[dco]);
                        //         printf("help1\n");
                        //         dco++;

                        //     }

                        // }
                        // else{
                        //     dco=0;
                        //     strcpy(circle[dco],circle[dco+1]);
                        //     dco++;
                        //     if(strcmp(hyum,"~")==0 && strcmp(hyum,"-")!=0 ){
                        //         strcpy(circle[dco],nano);
                        //         printf("%d %s\n",dco,circle[dco]);
                        //         printf("help3\n");
                        //         dco++;

                        //     }
                        //     else if(strcmp(hyum,"-")!=0){
                        //         strcpy(circle[dco],hyum);
                        //         printf("%d %s\n",dco,circle[dco]);
                        //         printf("help4\n");
                        //         dco++;

                        //     }

                        // }
                        // printf("%s  %s\n",circle[0],circle[1]);

                        if (strcmp(hyum, "~") == 0)
                        {
                            char tt[1000];
                            getcwd(tt, 1000);
                            strcpy(patha, tt);

                            chdir(nano);

                            mn = 0;

                            //strcpy(circle,nano);
                            break;
                        }
                        if (strcmp(hyum, "") == 0)
                        {

                            chdir(nano);

                            break;
                        }

                        if (strcmp(hyum, "-") == 0)
                        {
                            if (strcmp(patha, "") == 0)
                            {
                                printf("cd: OLDPWD not set\n");
                                break;
                            }
                            else
                            {
                                char tt[1000];
                                getcwd(tt, 1000);

                                chdir(patha);
                                printf("%s\n", patha);
                                strcpy(patha, tt);
                                break;
                            }
                        }

                        DIR *Mio = opendir(hyum);

                        if (Mio == NULL)
                        {
                            perror("");
                            break;
                        }

                        // if(strcmp(hyum,"-")==0){

                        //     chdir(circle[mn%2]);
                        //     printf("%s\n",circle[mn%2]);
                        //     mn++;

                        //     //strcpy(circle,nano);
                        //     break;

                        // }
                        // mn=0;
                        // printf("%s",hyum);
                        char tt[1000];
                        getcwd(tt, 1000);
                        strcpy(patha, tt);
                        chdir(hyum);
                        //strcpy(circle,hyum);
                        break;
                    }
                    if (abc[hh][jj] == 'p' && abc[hh][jj + 1] == 'w' && abc[hh][jj + 2] == 'd')
                    {
                        int origing;
                        dup2(STDOUT_FILENO, origing);
                        if (rig != -1 || righ != -1)
                        {
                            if (rig != -1)
                            {
                                int fdd = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                            else
                            {
                                int fdd = open(lol, O_APPEND | O_WRONLY | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                        }
                        getcwd(halo, sizeof(halo));
                        printf("%s\n", halo);
                        dup2(origing, STDOUT_FILENO);

                        break;
                    }
                    if (abc[hh][jj] == 'e' && abc[hh][jj + 1] == 'c' && abc[hh][jj + 2] == 'h' && abc[hh][jj + 3] == 'o')
                    {
                        char udt[1000] = {'\0'};
                        ree = 0;
                        qw = 0;

                        for (int mm = jj + 4; mm < strlen(abc[hh]) && abc[hh][mm] != '>'; mm++)
                        {
                            if (abc[hh][mm] != ' ')
                            {
                                if (rrt == -1)
                                {
                                    rrt = mm;
                                }
                                udt[ree] = abc[hh][mm];
                                ree++;
                                qw = 0;
                            }
                            if (rrt != -1 && abc[hh][mm] == ' ' && qw == 0)
                            {
                                udt[ree] = ' ';
                                ree++;
                                qw = 1;
                            }
                        }
                        int origing;
                        dup2(STDOUT_FILENO, origing);
                        if (rig != -1 || righ != -1)
                        {
                            if (rig != -1)
                            {
                                int fdd = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                            else
                            {
                                int fdd = open(lol, O_APPEND | O_WRONLY | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                        }
                        printf("%s\n", udt);
                        dup2(origing, STDOUT_FILENO);
                        break;
                    }
                    if (abc[hh][jj] == 'l' && abc[hh][jj + 1] == 's')
                    {
                        int origing;
                        dup2(STDOUT_FILENO, origing);
                        if (rig != -1 || righ != -1)
                        {
                            if (rig != -1)
                            {
                                int fdd = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                            else
                            {
                                int fdd = open(lol, O_APPEND | O_WRONLY | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                        }
                        lscommand(abc, jj + 2, hh, nano);
                        dup2(origing, STDOUT_FILENO);
                        break;
                    }
                    if (((strlen(abc[hh])) - jj >= 7) && abc[hh][jj] == 'h' && abc[hh][jj + 1] == 'i' && abc[hh][jj + 2] == 's' && abc[hh][jj + 3] == 't' && abc[hh][jj + 4] == 'o' && abc[hh][jj + 5] == 'r' && abc[hh][jj + 6] == 'y')
                    {
                        int origing;
                        dup2(STDOUT_FILENO, origing);
                        if (rig != -1 || righ != -1)
                        {
                            if (rig != -1)
                            {
                                int fdd = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                            else
                            {
                                int fdd = open(lol, O_APPEND | O_WRONLY | O_CREAT, 0644);
                                if (fdd < 0)
                                {
                                    perror("File not found\n");
                                    continue;
                                }

                                if (dup2(fdd, STDOUT_FILENO) < 0)
                                {
                                    perror("Unable to duplicate file descriptor");
                                    continue;
                                }
                                close(fdd);
                            }
                        }
                        if (avsa > 1)
                        {
                            historyl(nano, pro4[1]);
                        }
                        else
                        {
                            history(nano);
                        }
                        dup2(origing, STDOUT_FILENO);

                        break;
                    }
                }
            }
            else
            {
                int origing;
                dup2(STDOUT_FILENO, origing);
                if (rig != -1 || righ != -1)
                {
                    if (rig != -1)
                    {
                        int fdd = open(lol, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                        if (fdd < 0)
                        {
                            perror("File not found\n");
                            continue;
                        }

                        if (dup2(fdd, STDOUT_FILENO) < 0)
                        {
                            perror("Unable to duplicate file descriptor");
                            continue;
                        }
                        close(fdd);
                    }
                    else
                    {
                        int fdd = open(lol, O_APPEND | O_WRONLY | O_CREAT, 0644);
                        if (fdd < 0)
                        {
                            perror("File not found\n");
                            continue;
                        }

                        if (dup2(fdd, STDOUT_FILENO) < 0)
                        {
                            perror("Unable to duplicate file descriptor");
                            continue;
                        }
                        close(fdd);
                    }
                }

                char slewo[1000] = {'\0'};
                for (int mcq = 0; mcq < strlen(abc[hh]); mcq++)
                {
                    if (abc[hh][mcq] != '&')
                    {
                        slewo[mcq] = abc[hh][mcq];
                    }
                }

                proc(pro4, avsa, ple, slewo);
                dup2(origing, STDOUT_FILENO);
            }
        }
        strcpy(lineco, line);
    }
}

int main(int argc, char **argv)
{
    in=0;
    fopid = -1;
    myid = getpid();
    jbcount = 0;
    signal(SIGCHLD, plhandle);

    pleas = makenode(0, 0, "yo");

    cd(pleas);

    return 0;
}
