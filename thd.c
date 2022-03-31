#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *process(void *arg){
printf("in thread 1\n");
printf("sleeping for 2 secs\n");
sleep(2);
printf("slept for 2 secs\n");
//pthread_exit(NULL);
}

void *process2(void *arg){
printf("in thread 2\n");
printf("sleeping for 2 secs\n");
sleep(2);
printf("slept for 2 secs\n");
//pthread_exit(NULL);
}

int main(){
pthread_t t_id;
pthread_t t_id2;
pthread_create(&t_id,NULL,process,NULL);
pthread_create(&t_id2,NULL,process2,NULL);
printf("exiting from main\n");
pthread_exit(NULL);


return 0;
}
