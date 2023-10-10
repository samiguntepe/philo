/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/10 15:45:00 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->forks[philos->left_f]);
	write_term(philos->id, 1, philos);
	if (philos->args->number_of_philosophers >= 2)
	{
		pthread_mutex_lock(&philos->args->forks[philos->right_f]);
		write_term(philos->id, 1, philos);
	}
	else
	{
		pthread_mutex_unlock(&philos->args->forks[philos->left_f]);
		return (1);
	}
	write_term(philos->id, 2, philos);
	pthread_mutex_lock(&philos->args->mutex_last_eat);
	philos->last_eat = get_time();
	pthread_mutex_unlock(&philos->args->mutex_last_eat);
	wait_time(philos, philos->args->time_to_eat);
	pthread_mutex_lock(&philos->args->mutex_eat);
	philos->eat_count++;
	pthread_mutex_unlock(&philos->args->mutex_eat);
	pthread_mutex_unlock(&philos->args->forks[philos->left_f]);
	if (philos->args->number_of_philosophers >= 2)
		pthread_mutex_unlock(&philos->args->forks[philos->right_f]);
	return (0);
}

void	wait_time(t_philo *philos, int wait_time)
{
	long	time;

	time = get_time();
	pthread_mutex_lock(&philos->args->mutex_die);
	while (!philos->args->died)
	{
		pthread_mutex_unlock(&philos->args->mutex_die);
		usleep(40);
		if (get_time() - time >= wait_time)
			break ;
		pthread_mutex_lock(&philos->args->mutex_die);
	}
	pthread_mutex_unlock(&philos->args->mutex_die);
}
