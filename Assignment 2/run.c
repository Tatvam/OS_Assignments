#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc, char *argv[])
{

    argv++;
    int i;
    char exec[512];
        exec[0]='.';
        exec[1]='/';
        for(i=2;i<512;i++)
        if(argv[0][i-2]=='\0')
            break;
        else
            exec[i]=argv[0][i-2];
            exec[i]='\0';
            
    argv++;
    execvp(exec,argv);
    return 0;
}
