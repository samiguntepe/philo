/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:52:19 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/13 13:09:06 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <pthread.h>

void	free_memory(t_philo *philos, int ans)
{
	int	i;

	i = 0;
	while (i < philos->args->number_of_philosophers)
	{
		pthread_mutex_destroy(&philos->args->forks[i]);
		i++;
	}
	if (ans == 2)
	{
		pthread_mutex_destroy(&philos->args->write);
		pthread_mutex_destroy(&philos->args->mutex_die);
		pthread_mutex_destroy(&philos->args->mutex_eat);
		pthread_mutex_destroy(&philos->args->mutex_full);
		pthread_mutex_destroy(&philos->args->mutex_last_eat);
	}
	free(philos->args->forks);
	free(philos);
}

int	free_forks(pthread_mutex_t *mutex, t_philo *philos, int ans)
{
	if (ans == 0)
	{
		pthread_mutex_destroy(mutex);
		free_memory(philos, 0);
	}
	else if (ans == 1)
	{
		free(philos);
	}
	return (1);
}
