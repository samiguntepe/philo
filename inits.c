/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:04:48 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/20 18:52:37 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads_fork(t_sim *sim, int philo_count)
{
	int	i;

	sim->th_philo = malloc(sizeof(pthread_t) * philo_count);
	
	i = 0;
	while (i < philo_count)
	{
		pthread_create(&sim->th_philo[i], NULL, &a, NULL);
		pthread_mutex_init(&sim->philos[i].mtx_fork, NULL);
		i++;
	}
}

void	init_philo(t_sim *sim)
{
	int	philo_count;
	int	i;

	philo_count = sim->philos->number_of_philosophers;
	i = 0;
	while (i < philo_count)
	{
		sim->philos[i].num = (i + 1);
		sim->philos[i].fork_num = (i + 1);
		i++;
	}
}

void	inits(t_sim *sim)
{
	init_threads_fork(sim, sim->philos->number_of_philosophers);
	init_philo(sim);
}

void	*a()
{
	return (NULL);
}
