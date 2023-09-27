/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/27 19:50:30 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philos, int phid)
{
	(void)phid;
	pthread_mutex_lock(&philos->args->forks[0]);
	pthread_mutex_lock(&philos->args->forks[1]);
	pthread_mutex_lock(&philos->args->forks[2]);
	write_term(philos->id, 1, philos->args);
	write_term(philos->id, 1, philos->args);
	write_term(philos->id, 2, philos->args);
	usleep(philos->args->time_to_eat * 1000);

	
	pthread_mutex_unlock(&philos->args->forks[0]);
	pthread_mutex_unlock(&philos->args->forks[1]);
	pthread_mutex_unlock(&philos->args->forks[2]);
}