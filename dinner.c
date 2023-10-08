/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:18 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/08 17:36:15 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	if (philos->args->number_of_philosophers < 2)
		return (NULL);
	if (philos->id % 2 != 0)
		usleep(1500);
	while (philos->args->died != 1)
	{
		eating(philos);
		printf("%d\n",philos->args->died);
		write_term(philos->id, 3, philos);
		wait_time(philos, philos->args->time_to_sleep);
		write_term(philos->id, 4, philos);
	}
	return (NULL);
}