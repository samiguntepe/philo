/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:32 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/11 15:12:31 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

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

int	control(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			write(2, RED"Error\n"END, 13);
			return (1);
		}
		i++;
	}
	return (0);
}
