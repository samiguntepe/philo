/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:18 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/07 18:47:48 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	if (philos->id % 2 != 0)
		wait_time(philos, philos->args->time_to_eat);
	while (philos->args->died != 1)
	{
		eating(philos);
		write_term(philos->id, 3, philos);
		wait_time(philos, philos->args->time_to_sleep);
		write_term(philos->id, 4, philos);
		usleep(1000);
	}
	return (NULL);
}