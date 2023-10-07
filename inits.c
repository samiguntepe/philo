/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:04:48 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/07 18:11:17 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_philo *philos, int philo_count)
{
	pthread_t	tview;
	int			i;

	i = 0;
	while (i < philo_count)
	{
		pthread_create(&philos[i].thread, NULL, &dinner, &philos[i]);
		i++;
	}
	pthread_create(&tview, NULL, view, philos);
	i = 0;
	while (i < philo_count)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(tview, NULL);
}

void	init_philo(t_arg *args, t_philo *philos)
{
	int		philo_count;
	int		i;

	philo_count = args->number_of_philosophers;
	i = 0;
	while (i < philo_count)
	{
		philos[i].id = (i +1);
		philos[i].left_f = i;
		philos[i].right_f = i +1;
		philos[i].eat_count = 0;
		philos[i].args = args;
		i++;
	}
	philos[i -1].right_f = 0;
}

void	init_forks(t_arg *args, int philo_count)
{
	int	i;

	args->forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	pthread_mutex_init(&args->write, NULL);
	i = 0;
	while (i < philo_count)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
}
void	inits(t_arg	*args, t_philo *philos)
{
	args->died = 0;
	args->full = 0;
	init_philo(args, philos);
	init_forks(args, args->number_of_philosophers);
	init_threads(philos, args->number_of_philosophers);
}
