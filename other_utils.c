/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:28:05 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/07 15:44:48 by sguntepe         ###   ########.fr       */
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

int	check_food(t_philo *philos)
{
	int	i;

	i = 0;
	if (philos->args->number_of_must_eat > 0)
	{
		while (i < philos->args->number_of_philosophers)
		{
			if (philos[i].eat_count >= philos->args->number_of_must_eat)
				philos->args->full++;
			i++;
		}
		if (philos->args->full >= philos->args->number_of_philosophers)
		{
			philos->args->died = 1;
			return (1);
		}
	}
	return (0);
}
