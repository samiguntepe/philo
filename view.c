/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:52 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/09 20:12:16 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*view(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (!check_food(philos, 0))
	{
		i = 0;
		while (i++ < philos->args->number_of_philosophers)
		{
			pthread_mutex_lock(&philos->args->mutex_last_eat);
			if (get_time() - philos[i].last_eat > philos->args->time_to_die)
			{
				pthread_mutex_unlock(&philos->args->mutex_last_eat);
				write_term(philos->id, 5, philos);
				pthread_mutex_lock(&philos->args->mutex_die);
				philos->args->died = 1;
				pthread_mutex_unlock(&philos->args->mutex_die);
				return (NULL);
			}
			pthread_mutex_unlock(&philos->args->mutex_last_eat);
			i++;
		}
		pthread_mutex_lock(&philos->args->mutex_die);
		if (philos->args->number_of_philosophers < 2 && philos->args->died == 1)
		{
			pthread_mutex_unlock(&philos->args->mutex_die);
			break ;
		}
		pthread_mutex_unlock(&philos->args->mutex_die);
	}
	return (NULL);
}
