/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/29 17:08:23 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philos, int phid)
{
	(void)phid;
	pthread_mutex_lock(&philos->args->forks[philos->left_f]);
	pthread_mutex_lock(&philos->args->forks[philos->right_f]);
	
	write_term(philos->id, 1, philos);
	write_term(philos->id, 1, philos);
	write_term(philos->id, 2, philos);
	
	usleep(philos->args->time_to_eat * 1000);
	philos->last_eat = philos->args->last_t + philos->args->time_to_eat;
	printf("%d : %ld\n",philos->id,philos->last_eat);
	pthread_mutex_unlock(&philos->args->forks[philos->left_f]);
	pthread_mutex_unlock(&philos->args->forks[philos->right_f]);
}

