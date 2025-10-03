#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 100

int x[MAX];
int nx;
pthread_mutex_t mutex;

void *worker(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);

        if(nx <= 1)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        
        if(nx >= 2)
        {
            x[0] = x[0] + x[1];
            for(int i = 1; i < nx - 1; i++)
            {
                x[i] = x[i+1];
            }
            nx--;
        }
        pthread_mutex_unlock(&mutex);
        usleep(1000);
    }
    return NULL;
}

int main()
{
    pthread_t threads[10];
    int i;

    nx = 10;
    for(i = 0; i < nx; i++)
    {
        x[i] = i + 1;
    }

    pthread_mutex_init(&mutex, NULL);

    for(i = 0; i < 10; i++)
    {
        if(pthread_create(&threads[i], NULL, worker, NULL) != 0)
        {
            perror("pthread_create");
            exit(1);
        }
    }

    for(i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Total sum: %d\n", x[0]);
    pthread_mutex_destroy(&mutex);

    return 0;
}