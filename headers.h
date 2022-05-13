#ifndef __HE_H
#define __HE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>
#include <sys/wait.h>
#include <grp.h>
#include <time.h>
#include <limits.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <assert.h>


typedef long long int emt;
typedef struct Linked* ptn;

typedef ptn List;

struct Linked{
    emt num;
    emt pid;
    char nam[1000];

    struct Linked* Next;

};

emt jbcount;

emt fopid;

char abc[1000];
emt in;


#endif
