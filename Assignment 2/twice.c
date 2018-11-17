#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc, char *argv[])
{

	char exec[512];//Need to exec with ./
        exec[0]='.';
        exec[1]='/';
		int i =0;
        for(i=2;i<512;i++)
        if(argv[0][i-2]=='\0')
            break;
        else
            exec[i]=argv[0][i-2];
            exec[i]='\0';

	//printf("%d\n",atoi(argv[argc-1]));
	int x=atoi(argv[argc-1])*2;
	//printf("%d\n",x);
	sprintf(argv[argc-1], "%d",x);
	if(argc==1){
	printf("%d\n",atoi(argv[argc-1]));
	return 0;
	}
	//argv++;
	//printf("%s\n",argv[argc-1]);
	argv++;
	execvp(exec,argv);
	return 0;
}
