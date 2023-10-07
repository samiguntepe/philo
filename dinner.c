/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:18 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/07 14:32:22 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	if (philos->id % 2 != 0)
		usleep(1000 * philos->args->time_to_eat);
	while (philos->args->died != 1)
	{
		eating(philos, philos->id);
		life_control(philos);
		usleep(1000);
	}
	return (NULL);
}