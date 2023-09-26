/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:04:48 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/26 18:05:07 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads_fork(t_arg *args, int philo_count)
{
	int	i;
	
	i = 0;
	while (i < philo_count)
	{
		args[i].forks = malloc(sizeof(t_fork));
		args[i].forks->fork = malloc(sizeof(pthread_mutex_t));
		args[i].forks->id = (i + 1);
		pthread_create(&args[i].philos->thread, NULL, &dinner, &args[i]);
		pthread_mutex_init(args[i].forks->fork, NULL);
		i++;
	}
	i = 0;
	while (i < philo_count)
	{
		pthread_join(args[i].philos->thread, NULL);
		i++;
	}
	
}

void	init_philo(t_arg *args)
{
	int	philo_count;
	int	i;
	
	philo_count = args->philos->number_of_philosophers;
	i = 0;
	while (i < philo_count)
	{
		args[i].philos->id = (i + 1);
		args[i].philos->thread = malloc(sizeof(pthread_t));
		args[i].philos->fid = 0;
		i++;
	}
}

void	inits(t_arg	*args)
{
	init_philo(args);
	init_threads_fork(args, args->philos->number_of_philosophers);
	
}
