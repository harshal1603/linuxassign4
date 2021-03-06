#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_t tid;

struct char_print_params
{

char character[10];
int count;
};

void *char_print(void *parameters)
{
struct char_print_params *p=(struct char_print_params *)parameters;
int i;
printf("structure character data = %s count=%d\n",p->character,p->count);
}

void* thread1(void *arg){
char *s=(char *)arg;
printf("newly created thread is executing\n");
printf("%s\n",s);
return NULL;

}

int main(){
pthread_t thread1;
pthread_t thread2;

struct char_print_params thread1_args;
struct char_print_params thread2_args;

strcpy(thread1_args.character,"hello");
thread1_args.count=20;
pthread_create(&thread1,NULL,&char_print,&thread1_args);

strcpy(thread2_args.character,"world");
thread2_args.count=20;
pthread_create(&thread2,NULL,&char_print,&thread2_args);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);




return 0;
}

