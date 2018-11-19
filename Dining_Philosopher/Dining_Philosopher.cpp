#include<bits/stdc++.h>
#include<cstdio>
#include<semaphore.h>
#include<unistd.h>
using namespace std;
#define N 5
#define Hungry 2
#define Thinking 0
#define Eating 1
#define left (ph+4)%5
#define right (ph+1)%5

vector<int> phil = {0,1,2,3,4};
vector<int> state(N);

sem_t mut;
sem_t s[N];

void test(int ph){
    if(state[ph]==Hungry && state[left]!=Eating && state[right]!=Eating){
        state[ph]=Eating;
         sleep(2); 
        cout<<"Philosopher "<<ph+1<<" takes fork "<<left+1<<" and "<<ph+1<<endl; 
        cout<<"Philosopher "<<ph+1<<" is Eating"<<endl;
        sem_post(&s[ph]);
    }
}

void putfork(int ph){
    sem_wait(&mut);
    state[ph]=Thinking;
    cout<<"Philosopher "<<ph+1<<" putting fork "<<left+1<<" and "<<ph+1<<" down"<<endl; 
    cout<<"Philosopher "<<ph+1<<" is thinking"<<endl;
    test(left);
    test(right);
    sem_post(&mut);
}

void takefork(int ph){
    sem_wait(&mut);
    state[ph]=Hungry;
    cout<<"Philosopher "<<ph+1<<" is hungry"<<endl;
    test(ph);
    sem_post(&mut);
    sem_wait(&s[ph]);
    sleep(1);

}

void* dining(void* num){
    while(1){  
        int i = *((int *)num); 
        takefork(i);
        sleep(1);
        putfork(i);
    }
}

int main(){ 

    pthread_t thread[N];

    sem_init(&mut,0,1);

    for(int i = 0;i<N;i++){
        sem_init(&s[i],0,0);
    }
    for(int i = 0;i<N;i++){
        pthread_create(&thread[i],NULL,dining,&phil[i]);
    }
    for(int i = 0;i<N;i++){
        pthread_join(thread[i],NULL);
    }

}