/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:52:19 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/12 15:26:45 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <pthread.h>

void	free_memory(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->args->number_of_philosophers)
	{
		pthread_mutex_destroy(&philos->args->forks[i]);
		i++;
	}
	free(philos->args->forks);
	free(philos);
}
