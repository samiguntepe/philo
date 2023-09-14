#include "philo.h"

void    init_threads(t_sim *sim, int philo_count)
{
    pthread_t   th_philo[philo_count];
    int         i;

    i = 0;
    while (i < philo_count)
    {
        pthread_create(&th_philo[i], NULL, &a, NULL);
        sim->philos->num = i;
        i++;
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