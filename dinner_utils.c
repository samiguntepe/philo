/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/26 17:11:32 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_arg *args, int phid, int fkid)
{
	(void)phid;
	if (fkid == 1)
		pthread_mutex_lock(args->forks->fork);
	
	pthread_mutex_lock(&args->write);
	write_term(args->philos->id, 1);
	write_term(args->philos->id, 1);
	write_term(args->philos->id, 2);
	pthread_mutex_unlock(&args->write);
	pthread_mutex_unlock(args->forks[phid].fork);
}