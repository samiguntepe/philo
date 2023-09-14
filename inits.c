#include "philo.h"

void    init_threads(t_sim *sim, int philo_count)
{
    int i;

    i = 0;
    // sim->th_philo = malloc(philo_count);
    // sim->th_philo[philo_count];
    pthread_t 	th_philo[philo_count];
    while (i < philo_count)
    {
        pthread_create(&th_philo[i], NULL, &a, NULL);
        pthread_join(th_philo[i], NULL);
        printf("%d",i);
        i++;
        // printf("%d\n",i);
    }
    
}

void    *a()
{
    printf("girdi\n");
    
    return NULL;
}

// void    init_mutex()
// {

// }