/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <sguntepe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:32 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/13 21:12:46 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	number_of_philo_control(t_philo *philo, int argc)
{
	if (argc == 6)
	{
		if (philo->number_of_must_eat == 0 || philo->time_to_die == 0
			|| philo->number_of_philosophers == 0 || philo->time_to_eat == 0
			|| philo->time_to_sleep == 0)
			return (0);
	}
	else if (argc == 5)
	{
		if (philo->number_of_philosophers == 0 || philo->time_to_die == 0
			|| philo->time_to_eat == 0 || philo->time_to_sleep == 0)
			return (0);
	}
	return (1);
}

// void	check_arg(t_philo *philo)
// {
// 	if (philo->number_of_philosophers > 200)
// }
