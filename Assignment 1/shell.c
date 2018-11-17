#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

int main(int argc, char* argv[]){
    int SIZE = 1000;
   // printf("hi\n");
    while(1){
        int i=0;
        int j=0;
        char buff[SIZE];char str[SIZE];char cwd[SIZE];
        while(i!=SIZE){
            buff[i]='\0'; str[i]='\0';// cwd[i]='\0';
            i++;
        }
        getcwd(cwd,1000);
		printf(" %s > ",cwd);
        scanf(" %[^\n]",buff);
       // printf("%s",buff);
        char command[SIZE];
        i=0;
        while(buff[i]!='\0'){
            if(buff[i]==' '){
                i++;
            }else{
                break;
            }
        }
        j=0;
        while(buff[i]!=' ' && buff[i]!='\0'){
            str[j]=buff[i];
            i++;j++;
        }
        while(buff[i]==' '){
            i++;
        }
        if(strcmp(str,"pwd")==0){
            printf("%s\n",cwd);
        }else if(strcmp(str,"cd")==0){
            char path[SIZE];
            int k = 0;
    
             while(k!=SIZE){
            path[k++]='\0';
            }

            j=0;
            while(buff[i]!='\0' && buff[i]!=' '){
                path[j]=buff[i];
                i++; j++;
            }
            int  status;
           // printf("%s\n",path);
           if(j == 0){
               status = chdir("/home/tatvam");
           }else{
               status = chdir(path);
           }
            
           if(status == -1){
               perror("Error in changing directory!\n");
           }
        }else if(strcmp(str,"ls")==0){
            char ext[SIZE];
            int j=0;
            while(j!=SIZE){
                ext[j++]='\0';
            }
             j=0;
             
            while(buff[i]!='\0' && buff[i]!=' '){
                ext[j]=buff[i];
                i++;j++;
            }
         //   printf("%s\n",ext);
            if(j==0){
                DIR *ff; 
                struct dirent *fdata;
                ff = opendir(cwd);
                while((fdata=readdir(ff))!=NULL){
                    if(strcmp(fdata->d_name,"..")!=0  &&  strcmp(fdata->d_name,".")!=0)
                    printf("%s\n",fdata->d_name);
                }

           }else{

           }

        }else if(strcmp(str,"mkdir")==0){
            char mdir[SIZE];
            int j=0;
            while(j!=SIZE){
                mdir[j++]='\0';
            }
             j=0;  
            while(buff[i]!='\0' && buff[i]!=' '){
                mdir[j]=buff[i];
                i++;j++;
            }
            int status = mkdir(mdir, S_IRWXU | S_IRWXG | S_IRWXO);
			if(status==-1)
				perror("Error in creating new directory!\n");
        }
        else if(strcmp(str,"rmdir")==0){
              char rdir[SIZE];
            int j=0;
            while(j!=SIZE){
                rdir[j++]='\0';
            }
             j=0;  
            while(buff[i]!='\0' && buff[i]!=' '){
                rdir[j]=buff[i];
                i++;j++;
            }
            int status = rmdir(rdir);
			if(status==-1)
				perror("Error in creating new directory!\n");
        }
        else if(strcmp(str,"exit")==0){
            exit(0);
        }
    }

}