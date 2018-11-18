#include<bits/stdc++.h>
#include<cstdio>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/time.h>
#include<unistd.h>
#include<sys/shm.h>
#include<fcntl.h>
using namespace std;

#define BUFFER_SIZE 10
#define KEY 1111

class Memory{
    public:
        int buff[BUFFER_SIZE];
        sem_t mutex,full,empty;
};

Memory *mem(){
    key_t key = KEY;
    int shmid = shmget(key,sizeof(Memory),0666|IPC_CREAT);
    return (Memory *)shmat(shmid,NULL,0);


}  

void init(){

    Memory *M = mem();

    sem_init(&M->mutex,1,1);
    sem_init(&M->empty,1,BUFFER_SIZE);
    sem_init(&M->full,1,0);

}


