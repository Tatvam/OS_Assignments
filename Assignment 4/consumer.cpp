#include "Problem.h"

void consumer(){
    Memory *M = mem();
    while(1){
        int n;
        sem_wait(&M->full);
        sem_wait(&M->mutex);
        sem_getvalue(&M->full,&n);
        printf("[CONSUMER] Removed item [%d]\n", (M->buff)[n]);
        sem_post(&M->empty);
        sem_post(&M->mutex);
        sleep(1);
    }
}


int main(){
    consumer();
}