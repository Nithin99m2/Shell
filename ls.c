#include "headers.h"
#include "functions.h"

long int filefuncioning(char aft[1000])
{
    struct stat stating;

    if (stat(aft, &stating) == -1)
    {
        //printf("%s\n",aft);
        perror("");
        return 0;
    }

    return stating.st_blocks;
}

void filefunc(char aft[1000])
{
    struct stat stating;

    if (stat(aft, &stating) == -1)
    {
        //printf("%s\n",aft);
        perror("");
        return;
    }
    struct passwd *root = getpwuid(stating.st_uid);
    struct group *alex = getgrgid(stating.st_gid);

    //printf("Total %ld\n", stating.st_blocks);
    if (S_ISDIR(stating.st_mode))
    {
        printf("d");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IRUSR))
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IWUSR))
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IXUSR))
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IRGRP))
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IWGRP))
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IXGRP))
    {
        printf("x");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IROTH))
    {
        printf("r");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IWOTH))
    {
        printf("w");
    }
    else
    {
        printf("-");
    }

    if ((stating.st_mode & S_IXOTH))
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    char cortana[1000];
    printf(" ");
    printf("%ld ", stating.st_nlink);
    printf("%s ", alex->gr_name);
    printf("%s ", root->pw_name);
    printf("%ld ", stating.st_size);
    strftime(cortana, 100, "%b %d %H:%M", localtime(&stating.st_mtime));
    printf("%s ", cortana);
    //printf("%ld ", stating.st_blocks);
    printf("%s", aft);
    printf("\n");
}

void lscommand(char abc[1000][1000], int index, int index2, char origin[1000])
{


    char *token2 = strtok(abc[index2], " ");

    char dcb[1000][1000] = {'\0'};
    int rtr = 0;
    while (token2 != NULL)
    {
        if(strcmp(token2,">")==0 || strcmp(token2,">>")==0)
        {
            break;
        }
        strcpy(dcb[rtr], token2);
        token2 = strtok(NULL, " ");
        rtr++;
    }
    // for(int i=0;i<rtr;i++){
    //     printf("%s\n",dcb[i]);
    // }
    // printf("\n");

    char yono[1000] = {'\0'};
    getcwd(yono, sizeof(yono));

    if (rtr == 1)
    {
        struct dirent *de;

        DIR *drint = opendir(".");

        if (drint == NULL)
        {
            perror("");
            return;
        }
        printf("\n");
        printf("Files and directories:\n");
        printf("\n");

        while ((de = readdir(drint)) != NULL)
        {
            char addd[1000] = {'\0'};
            strcpy(addd, de->d_name);
            if (addd[0] != '.')
            {
                printf("%s\n", de->d_name);
            }
        }

        closedir(drint);
        printf("\n");
        return;
    }

    int flag = -1;
    int flag1 = -1;
    int flag2 = -1;

    for (int i = 0; i < rtr; i++)
    {
        if (strcmp(dcb[i], "-a") == 0)
        {
            flag = 1;
        }
        else if (strcmp(dcb[i], "-l") == 0)
        {
            flag1 = 1;
        }
        else if (strcmp(dcb[i], "-la") == 0 || strcmp(dcb[i], "-al") == 0)
        {
            flag2 = 1;
        }
    }
    // printf("%d %d %d\n",flag,flag1,flag2);

    if (flag == -1 && flag1 == -1 && flag2 == -1)
    {

        for (int yr = 0; yr < rtr; yr++)
        {

            if (strcmp(dcb[yr], "ls") != 0)
            {
                struct dirent *de;
                if (strcmp(dcb[yr], "~") == 0)
                {
                    strcpy(dcb[yr], origin);
                }

                DIR *drint = opendir(dcb[yr]);
                //chdir(dcb[yr]);
                //printf("%s\n",dcb[vb]);

                if (drint == NULL)
                {
                    perror("");
                    return;
                }
                printf("\n");
                printf("Files and directories:\n");
                printf("\n");

                while ((de = readdir(drint)) != NULL)
                {
                    char addd[1000] = {'\0'};
                    strcpy(addd, de->d_name);
                    if (addd[0] != '.')
                    {
                        printf("%s\n", de->d_name);
                    }
                }

                closedir(drint);
                //chdir(yono);
                printf("\n");
            }
        }
        return;
    }
    // printf("%d %d %d\n",flag,flag1,flag2);
    //printf("%d\n",flag);
    if (flag2 == 1 || (flag == 1 && flag1 == 1))
    {
        //printf("hello\n");
        int qx = -1;
        for (int vb = 0; vb < rtr; vb++)
        {

            if ((strcmp(dcb[vb], "-a") != 0) && (strcmp(dcb[vb], "-l") != 0) && (strcmp(dcb[vb], "-al") != 0) && (strcmp(dcb[vb], "-la") != 0) && (strcmp(dcb[vb], "ls") != 0))
            {
                qx = 0;
                struct dirent *de;
                struct dirent *dim;
                if (strcmp(dcb[vb], "~") == 0)
                {
                    strcpy(dcb[vb], origin);
                }

                DIR *drint = opendir(dcb[vb]);
                DIR *drinting = opendir(dcb[vb]);
                //printf("%s\n",dcb[vb]);
                chdir(dcb[vb]);

                if (drint == NULL)
                {
                    perror("");
                    return;
                }
                printf("\n");
                printf("Files and directories:\n");
                printf("\n");
                long long int blocks = 0;

                while ((dim = readdir(drinting)) != NULL)
                {

                    blocks = blocks + filefuncioning(dim->d_name);
                }

                closedir(drinting);

                printf("total %lld\n", blocks/2);

                while ((de = readdir(drint)) != NULL)

                    filefunc(de->d_name);

                closedir(drint);
                chdir(yono);
                printf("\n");
            }
            else
            {
                continue;
            }
        }
        if (qx == -1)
        {
            struct dirent *de;
            struct dirent *dim;

            DIR *drint = opendir(".");
            DIR *drinting = opendir(".");

            if (drint == NULL)
            {
                perror("");
                return;
            }
            printf("\n");
            printf("Files and directories:\n");
            printf("\n");

            long long int blocks = 0;

            while ((dim = readdir(drinting)) != NULL)
            {

                blocks = blocks + filefuncioning(dim->d_name);
            }

            closedir(drinting);

            printf("total %lld\n", blocks/2);

            while ((de = readdir(drint)) != NULL)

                filefunc(de->d_name);

            closedir(drint);
            printf("\n");
        }
        return;
    }

    if (flag == 1)
    {
        //printf("hello1\n");
        int qx = -1;
        for (int vb = 0; vb < rtr; vb++)
        {
            if ((strcmp(dcb[vb], "-a") != 0) && (strcmp(dcb[vb], "-l") != 0) && (strcmp(dcb[vb], "-al") != 0) && (strcmp(dcb[vb], "-la") != 0) && (strcmp(dcb[vb], "ls") != 0))
            {
                //printf("\n%s\n",dcb[vb]);
                qx = 0;
                struct dirent *de;
                if (strcmp(dcb[vb], "~") == 0)
                {
                    strcpy(dcb[vb], origin);
                }

                DIR *drint = opendir(dcb[vb]);
                //printf("%s\n",dcb[vb]);

                if (drint == NULL)
                {
                    perror("");
                    return;
                }
                printf("\n");
                printf("Files and directories:\n");
                printf("\n");

                while ((de = readdir(drint)) != NULL)
                {

                    printf("%s\n", de->d_name);
                }

                closedir(drint);
                printf("\n");
            }
            else
            {
                continue;
            }
        }
        if (qx == -1)
        {
            //printf("nithin\n");
            struct dirent *de;

            DIR *drint = opendir(".");

            if (drint == NULL)
            {
                perror("");
                return;
            }
            printf("\n");
            printf("Files and directories:\n");
            printf("\n");

            while ((de = readdir(drint)) != NULL)
            {

                printf("%s\n", de->d_name);
            }

            closedir(drint);
            printf("\n");
        }
        return;
    }
    //printf("%d\n",flag1);
    if (flag1 == 1)
    {
        //printf("hello2\n");
        int qx = -1;
        for (int vb = 0; vb < rtr; vb++)
        {
            if ((strcmp(dcb[vb], "-a") != 0) && (strcmp(dcb[vb], "-l") != 0) && (strcmp(dcb[vb], "-al") != 0) && (strcmp(dcb[vb], "-la") != 0) && (strcmp(dcb[vb], "ls") != 0))
            {
                qx = 0;
                struct dirent *de;
                struct dirent *dim;
                if (strcmp(dcb[vb], "~") == 0)
                {
                    strcpy(dcb[vb], origin);
                }

                DIR *drint = opendir(dcb[vb]);
                DIR *drinting = opendir(dcb[vb]);
                //printf("%s\n",dcb[vb]);
                chdir(dcb[vb]);

                if (drint == NULL)
                {
                    perror("");
                    return;
                }
                printf("\n");
                printf("Files and directories:\n");
                printf("\n");
                long long int blocks = 0;

                while ((dim = readdir(drinting)) != NULL)
                {
                    char chax[1000]={'\0'};
                    strcpy(chax, dim->d_name);
                    if(chax[0]!='.'){
                        blocks = blocks + filefuncioning(dim->d_name);

                    }

                    
                }

                closedir(drinting);

                printf("total %lld\n", blocks/2);

                while ((de = readdir(drint)) != NULL)
                {
                    char addd[1000] = {'\0'};
                    strcpy(addd, de->d_name);
                    //printf("%s\n",de->d_name);
                    if (addd[0] != '.')
                    {

                        filefunc(addd);
                    }
                }

                closedir(drint);
                chdir(yono);
                printf("\n");
            }
            else
            {
                continue;
            }
        }
        if (qx == -1)
        {
            struct dirent *de;
            struct dirent *dim;

            DIR *drint = opendir(".");
            DIR *drinting = opendir(".");

            if (drint == NULL)
            {
                perror("");
                return;
            }
            printf("\n");
            printf("Files and directories:\n");
            printf("\n");
            long long int blocks = 0;

            while ((dim = readdir(drinting)) != NULL)
            {

                char chax[1000]={'\0'};
                strcpy(chax, dim->d_name);
                if(chax[0]!='.'){
                    blocks = blocks + filefuncioning(dim->d_name);

                }
            }

            closedir(drinting);

            printf("total %lld\n", blocks/2);

            while ((de = readdir(drint)) != NULL)
            {
                char addd[1000] = {'\0'};
                strcpy(addd, de->d_name);
                if (addd[0] != '.')
                {

                    filefunc(de->d_name);
                }
            }

            closedir(drint);
            printf("\n");
        }
        return;
    }
}
