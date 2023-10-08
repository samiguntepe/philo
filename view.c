/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/08 17:30:16 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*view(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;

	while (!check_food(philos))
	{
		i = 0;
		while (i < philos->args->number_of_philosophers)
		{
			if (get_time() - philos[i].last_eat > philos->args->time_to_die)
			{
				write_term(philos->id, 5, philos);
				philos->args->died = 1;
				return (NULL);
			}
			i++;
		}
		if (philos->args->number_of_philosophers < 2 && philos->args->died == 1)
			break ;
	}
	return (NULL);
}