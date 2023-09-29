/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:18 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/29 19:11:24 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	if (philos->id % 2 != 0)
		usleep(1000 * philos->args->time_to_eat);
	while (1)
	{
		eating(philos, philos->id);
		life_control(philos);
		usleep(1000);
	}
	return (NULL);
}