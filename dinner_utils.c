/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/27 20:18:55 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philos, int phid)
{
	(void)phid;
	pthread_mutex_lock(&philos->args->forks[philos->left_f]);
	pthread_mutex_lock(&philos->args->forks[philos->right_f]);
	
	write_term(philos->id, 1, philos);
	write_term(philos->id, 1, philos);
	write_term(philos->id, 2, philos);
	
	usleep(philos->args->time_to_eat * 1000);
	pthread_mutex_unlock(&philos->args->forks[philos->left_f]);
	pthread_mutex_unlock(&philos->args->forks[philos->right_f]);
}