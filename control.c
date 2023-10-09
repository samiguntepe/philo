/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:32 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/09 19:51:30 by sguntepe         ###   ########.fr       */
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
