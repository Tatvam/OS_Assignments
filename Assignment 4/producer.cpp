#include "Problem.h"

void producer(){
    int i = 0,n;
    Memory * M = mem();
    while(1){
        i++;
        sem_wait(&M->empty);  // DOWN
        sem_wait(&M->mutex);
        sem_getvalue(&M->full,&n);
        M->buff[n]=i;
        printf("[PRODUCER] Placed item [%d]\n", i);
        sem_post(&M->full);
        sem_post(&M->mutex);
        sleep(5);
    }
}


int main(){
    init();
    producer();
}
