#include "headers.h"
#include "functions.h"

void history(char vx[1000]){
	char vxx[1000];
	getcwd(vxx,sizeof(vxx));
	chdir(vx);
    FILE *ff=fopen("history.txt","r");
	if(ff==NULL){
		perror("");
	}
	char c;
	while((c=fgetc(ff))!=EOF)
		putchar(c);
	fclose(ff);
	chdir(vxx);
	return;
    
}


void historyl(char vx[1000],char arf[1000]){
	char vxx[1000];
	getcwd(vxx,sizeof(vxx));
	chdir(vx);
    FILE *ff=fopen("history.txt","r");
	if(ff==NULL){
		perror("");
	}
	int latest=atoi(arf);
	char cbi;
	int count = 0;
    for (cbi = getc(ff); cbi != EOF; cbi = getc(ff))
    {
        if (cbi == '\n')
        {
            count = count + 1;
        }
    }
	fclose(ff);
	if(latest<=count){
		int cno=count-latest;
		FILE *ffm=fopen("history.txt","r");
		if(ffm==NULL){
		   perror("");
		}
		char hemro[1000]={'\0'};
		int vcount=0;
		while (fgets(hemro, sizeof(hemro), ffm) != NULL)
        { 

			vcount=vcount+1;
			if(cno<vcount){
				printf("%s",hemro);
			}

		}
		fclose(ffm);




	}
	else{
		printf("Not those many history lines are there\n");
		
	}
	
	chdir(vxx);
	return;
    
}