/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:04:48 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/24 16:44:35 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads_fork(t_philo *philo, int philo_count)
{
	int	i;
	
	i = 0;
	while (i < philo_count)
	{
		philo[i].mtx_fork = malloc(sizeof(pthread_mutex_t));
		pthread_create(philo[i].th_philo, NULL, &dinner, (void *)&philo[i]);
		pthread_join(*philo[i].th_philo, NULL);
		pthread_mutex_init(philo[i].mtx_fork, NULL);
		i++;
	}
}

void	init_philo(t_philo *philo)
{
	int	philo_count;
	int	i;
	
	philo_count = philo->number_of_philosophers;
	i = 0;
	while (i < philo_count)
	{
		philo[i].id = (i + 1);
		philo[i].fork_id = (i);
		philo[i].th_philo = malloc(sizeof(pthread_t) * philo_count);
		i++;
	}
}

void	inits(t_philo *philo)
{
	init_philo(philo);
	init_threads_fork(philo, philo->number_of_philosophers);
}

void	*a()
{
	return (NULL);
}
