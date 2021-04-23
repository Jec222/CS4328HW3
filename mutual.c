#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define MAX 3
double scholarship = 4000;
double after = 0;

pthread_mutex_t mutex;

void* routine(void* name);

int main(void)
{
    pthread_t th[3];
    

    pthread_mutex_init(&mutex, NULL);
    char names[3] = {'A','B','C'};

    pthread_create(&th[0],NULL,&routine,&names[0]);
    pthread_create(&th[1],NULL,&routine,&names[1]);
    pthread_create(&th[2],NULL,&routine,&names[2]);

    for (int k = 0; k < MAX; k++ )
    {
        pthread_join(th[k],NULL);
    }
    printf("Total given out %f\n",after);
    
}

void* routine(void* name) 
{
    char t_name = *(char*)name;
    double deduction;

    while (scholarship > 0 )
    {
        //sleep(1);

        pthread_mutex_lock(&mutex);
        deduction = scholarship * 25 /100;
        
        deduction = ceil(deduction);
        printf("%c=%f\n",t_name,deduction);
        after = after + deduction;
        pthread_mutex_unlock(&mutex);
        
        scholarship = scholarship - deduction; 
    }
}