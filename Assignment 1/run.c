#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc, char *argv[]){
    
    int id = fork();
    if(id==0){
        printf("Welcome To Shell\n");
        execvp("./shell",argv);
    }else{
        wait(NULL);
        printf("Exiting Shell \n");

    }

}