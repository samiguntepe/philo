#include <stdio.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philo_id = *((int *)arg);
    int left_fork = philo_id;
    int right_fork = (philo_id + 1) % NUM_PHILOSOPHERS;

    // Filozofun düşünme işlemini simüle et

    // Çatal alma işlemi
    pthread_mutex_lock(&forks[left_fork]);
    pthread_mutex_lock(&forks[right_fork]);

    // Yemek yeme işlemi

    // Çatal bırakma işlemi
    pthread_mutex_unlock(&forks[left_fork]);
    pthread_mutex_unlock(&forks[right_fork]);

    return NULL;
}

int main() {
    pthread_t threads[NUM_PHILOSOPHERS];
    int philo_ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        philo_ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &philo_ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(threads[i], NULL);
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
