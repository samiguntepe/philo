/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:18 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/07 21:06:38 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	philo_is_full(t_philo *philos);

void	*dinner(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	if ((philos->id) % 2 != 0)
		usleep(1000 * philos->args->time_to_eat);
	while (philos->args->died != 1 && philo_is_full(philos))
	{
		eating(philos);
		write_term(philos->id, 3, philos);
		wait_time(philos, philos->args->time_to_sleep);
		write_term(philos->id, 4, philos);
		usleep(1000);
	}
	return (NULL);
}

static char	philo_is_full(t_philo *philos)
{
	if (!philos->args->number_of_must_eat)
		return (1);
	if (philos->eat_count >= philos->args->number_of_must_eat)
		return (0);
	return (1);
}
