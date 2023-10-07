/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/07 18:50:54 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->forks[philos->left_f]);
	pthread_mutex_lock(&philos->args->forks[philos->right_f]);
	
	write_term(philos->id, 1, philos);
	write_term(philos->id, 1, philos);
	write_term(philos->id, 2, philos);
	
	philos->last_eat = get_time(philos->args);
	wait_time(philos, philos->args->time_to_eat);
	philos->eat_count++;
	pthread_mutex_unlock(&philos->args->forks[philos->left_f]);
	pthread_mutex_unlock(&philos->args->forks[philos->right_f]);
}

void	wait_time(t_philo *philos, int wait_time)
{
	long time;

	time = get_time(philos->args);
	while (1)
	{
		usleep(40);
		if (get_time(philos->args) - time >= wait_time)
			break ;
	}
}
