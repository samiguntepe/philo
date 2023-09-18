#include "philo.h"

void    init_threads_fork(t_sim *sim, int philo_count)
{
    pthread_t       th_philo[philo_count];
    pthread_mutex_t mtx_fork[philo_count];
    int         i;

    i = 0;
    while (i < philo_count)
    {
        pthread_create(&th_philo[i], NULL, &a, NULL);
        pthread_mutex_init(&mtx_fork[i], NULL);
        i++;
    }
}

void    init_philo(t_sim *sim, int i)
{
    int philo_count;
    int i;


    sim->philos = malloc(sizeof(t_philo) * philo_count);
    philo_count = sim->philos->number_of_philosophers;
    i = 0;
    while (i < philo_count)
    {
        sim->philos[i].num = (i + 1);
        sim->philos[i].fork_num = (i + 1);
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