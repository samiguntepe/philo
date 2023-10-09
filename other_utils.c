/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:28:05 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/09 19:59:13 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	s;

	s = 0;
	while (*str >= '0' && *str <= '9')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s);
}

int	check_food(t_philo *philos, int i)
{
	if (philos->args->number_of_must_eat > 0)
	{
		while (i < philos->args->number_of_philosophers)
		{
			pthread_mutex_lock(&philos->args->mutex_eat);
			if (philos[i].eat_count >= philos->args->number_of_must_eat)
			{
				pthread_mutex_unlock(&philos->args->mutex_eat);
				philos->args->full++;
			}
			else
				pthread_mutex_unlock(&philos->args->mutex_eat);
			i++;
		}
		if (philos->args->full >= philos->args->number_of_philosophers)
		{
			pthread_mutex_lock(&philos->args->mutex_die);
			philos->args->died = 1;
			pthread_mutex_unlock(&philos->args->mutex_die);
			return (1);
		}
	}
	return (0);
}
