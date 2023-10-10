/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/10 16:42:15 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*view(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (!check_food(philos, 0))
	{
		philos->args->count = 0;
		while (philos->args->count < philos->args->number_of_philosophers)
		{
			pthread_mutex_lock(&philos->args->mutex_last_eat);
			if (get_time() - philos[philos->args->count++].last_eat
				> philos->args->time_to_die)
			{
				pthread_mutex_unlock(&philos->args->mutex_last_eat);
				write_term(philos->id, 5, philos);
				pthread_mutex_lock(&philos->args->mutex_die);
				philos->args->died = 1;
				pthread_mutex_unlock(&philos->args->mutex_die);
				return (NULL);
			}
			pthread_mutex_unlock(&philos->args->mutex_last_eat);
		}
		if (one_die_check(philos))
			break ;
	}
	return (NULL);
}

int	one_die_check(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->mutex_die);
	if (philos->args->number_of_philosophers < 2 && philos->args->died == 1)
	{
		pthread_mutex_unlock(&philos->args->mutex_die);
		return (1);
	}
	pthread_mutex_unlock(&philos->args->mutex_die);
	return (0);
}
