/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:28:07 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/25 19:09:41 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_parser(char **arg, t_philo *philo, int argc)
{
	philo->number_of_philosophers = ft_atoi(arg[1]);
	philo->time_to_die = ft_atoi(arg[2]);
	philo->time_to_eat = ft_atoi(arg[3]);
	philo->time_to_sleep = ft_atoi(arg[4]);
	if (argc == 6)
		philo->number_of_must_eat = ft_atoi(arg[5]);
}
