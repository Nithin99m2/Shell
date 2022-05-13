#include "headers.h"
#include "functions.h"

void pipc(char *array[1000])
{
    // char *took;
    // int i;
    // char *array[1000] = {'\0'};

    // took = strtok(abc, " ");
    // i = 0;
    // while (took != NULL)
    // {
    //     array[i] = took;
    //     took = strtok(NULL, " ");
    //     i++;
    // }
    // for(int ll=0;ll<i;ll++){
    //     printf("%s\n",array[ll]);
    // }
    // int lef = -1;
    // int rig = -1;
    // int righ = -1;
    // for (int dn = 0; dn < i; dn++)
    // {
    //     if (strcmp(array[dn], "<") == 0)
    //     {
    //         lef = dn;
    //     }
    //     if (strcmp(array[dn], ">") == 0)
    //     {
    //         rig = dn;
    //     }
    //     if (strcmp(array[dn], ">>") == 0)
    //     {
    //         righ = dn;
    //     }
    // }
    // printf("%d %d %d\n",lef,rig,righ);
    

    execvp(array[0], array);

    return;
}

void pips(char str[1000])
{
    char array[1000][1000];
    char *took;
    took = strtok(str, "|");
    int i = 0;
    while (took != NULL)
    {
        strcpy(array[i], took);
        took = strtok(NULL, "|");
        i++;
    }
    int piping[2];
    pid_t pidval;
    int fd = 0;

    for (int mi = 0; mi < i; mi++)
    {
        //printf("%s\n", array[mi]);
        char *array1[1000];
        char *took1;
        took1 = strtok(array[mi], " ");
        int i1 = 0;
        int y1 = 0;
        int d1 = 0;
        int x1 = 0;
        while (took1 != NULL)
        {
            if (strcmp(took1, "<") == 0)
            {
                y1 = i1;
            }
            if (strcmp(took1, ">") == 0)
            {
                d1 = i1;
            }
            if (strcmp(took1, ">>") == 0)
            {
                x1 = i1;
            }
            array1[i1] = took1;
            took1 = strtok(NULL, " ");
            i1++;
        }
        char ufo[1000];

        if (y1 != 0 && (d1 != 0 || x1 != 0))
        {
            if (d1 != 0)
            {
                strcpy(array1[y1], array1[d1 - 1]);
                strcpy(ufo, array1[d1 + 1]);
                i1 = y1 + 1;
            }
            else
            {
                strcpy(array1[y1], array1[x1 - 1]);
                strcpy(ufo, array1[x1 + 1]);
                i1 = y1 + 1;
            }
        }
        else if (y1 != 0)
        {
            strcpy(array1[y1], array1[i1 - 1]);
            i1 = y1 + 1;
        }
        else if (x1 != 0)
        {
            strcpy(ufo, array1[x1 + 1]);
            i1 = x1;
        }
        else if (d1 != 0)
        {
            strcpy(ufo, array1[d1 + 1]);
            i1 = d1;
        }

        char *kavali[1000];
        int vcd1 = 0;
        for (int vcd = 0; vcd < i1; vcd++)
        {
            kavali[vcd] = array1[vcd];
            vcd1 = vcd;
        }

        

        kavali[vcd1 + 1] = NULL;
        int origing;

        // printf("%d %d %d\n", y1, d1, x1);

        int ama = pipe(piping);
        if (ama < 0)
        {
            printf("Pipe not created\n");
            break;
        }
        pidval = fork();

        if (pidval < 0)
        {
            perror("Child process not created\n");
            break;
        }
        if (pidval == 0)
        {
            dup2(fd, 0);
            if (mi != i - 1)
            {
                dup2(piping[1], 1);
            }
            else
            {
                if (x1 != 0 || d1 != 0)
                {
                    if (d1 != 0)
                    {
                        int fdd = open(ufo, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                        if (fdd < 0)
                        {
                            perror("File not found\n");
                            continue;
                        }

                        if (dup2(fdd, 1) < 0)
                        {
                            perror("Unable to duplicate file descriptor");
                            continue;
                        }
                        close(fdd);
                    }
                    else
                    {
                        int fdd = open(ufo, O_APPEND | O_WRONLY | O_CREAT, 0644);
                        if (fdd < 0)
                        {
                            perror("File not found\n");
                            continue;
                        }

                        if (dup2(fdd, 1) < 0)
                        {
                            perror("Unable to duplicate file descriptor");
                            continue;
                        }
                        close(fdd);
                    }
                }
            }
            close(piping[0]);

            pipc(kavali);

            exit(0);
        }
        else
        {

            int ybg;
            waitpid(pidval, &ybg, 0);

            if (WIFEXITED(ybg))
            {

                close(piping[1]);
                fd = piping[0];
            }
        }
    }
}
