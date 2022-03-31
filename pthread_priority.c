#include<pthread.h>
#include<stdio.h>

void *myvoid(void *i){
printf("\ni am in %d thread\n",(int)i);
}

int main(){
pthread_t tid;
struct sched_param param;
int priority,policy,ret;

ret=pthread_getschedparam(pthread_self(),&policy,&param);

printf("\n -------------------main thread-------------- \n policy : %d \t priority : %d \n",policy,param.sched_priority);

policy=SCHED_FIFO;
param.sched_priority = 3;
pthread_setschedparam(pthread_self(),policy,&param);
pthread_getschedparam(pthread_self(),&policy,&param);

printf("\n -------------------main thread-------------- \n policy : %d \t priority : %d \n",policy,param.sched_priority);



return 0;
}
