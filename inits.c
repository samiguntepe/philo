/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:04:48 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/27 19:57:11 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads_fork(t_arg *args, t_philo *philos, int philo_count)
{
	int	i;
	
	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	pthread_mutex_init(&args->write, NULL);
	while (i < philo_count)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo_count)
	{
		pthread_create(&philos[i].thread, NULL, &dinner, &philos[i]);	
		i++;
	}
	i = 0;
	while (i < philo_count)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

void	init_philo(t_arg *args, t_philo *philos)
{
	int		philo_count;
	int		i;
	
	philo_count = args->number_of_philosophers;
	i = 0;
	while (i < philo_count)
	{
		philos[i].id = (i + 1);
		philos[i].left_f = i;
		philos[i].right_f = i + 1;
		philos[i].args = args;
		i++;
	}
	philos[i-1].right_f = 0;
}

void	inits(t_arg	*args, t_philo *philos)
{
	init_philo(args, philos);
	init_threads_fork(args, philos, args->number_of_philosophers);
}
