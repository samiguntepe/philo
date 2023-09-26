/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:04:48 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/26 10:32:31 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads_fork(t_arg *args, int philo_count)
{
	int	i;
	
	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	while (i < philo_count)
	{
		args->forks->fork = malloc(sizeof(pthread_mutex_t));
		
		pthread_create(&args->philos[i].thread, NULL, &dinner, &args[i]);
		pthread_join(args->philos[i].thread, NULL);
		pthread_mutex_init(args->forks->fork, NULL);
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
		args[i].philos->fid = i;
		args[i].philos->thread = malloc(sizeof(pthread_t));
		i++;
	}
}

void	inits(t_arg	*args)
{
	init_philo(args);
	init_threads_fork(args, args->philos->number_of_philosophers);
	
}
