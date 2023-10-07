/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:32 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/07 14:38:39 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_control(t_arg *args, int argc)
{
	if (argc == 6)
	{
		if (args->number_of_must_eat == 0 || args->time_to_die == 0
			|| args->number_of_philosophers == 0 || args->time_to_eat == 0
			|| args->time_to_sleep == 0)
			return (0);
	}
	else if (argc == 5)
	{
		if (args->number_of_philosophers == 0 || args->time_to_die == 0
			|| args->time_to_eat == 0 || args->time_to_sleep == 0)
			return (0);
	}
	return (1);
}

void	life_control(t_philo *philos)
{
	if (get_time(philos->args) - philos->args->first_time > philos->args->time_to_die)
	{
		philos->args->died = 1;	
		write_term(philos->id, 5, philos);
	}
}