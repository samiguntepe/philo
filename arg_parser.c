/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:28:07 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/26 15:07:55 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_parser(char **argv, t_arg *args, int argc)
{
	int i;
	int philo_count;

	philo_count = ft_atoi(argv[1]);
	i = 0;
	while (i < philo_count)
	{
		args[i].philos = malloc(sizeof(t_philo));
		i++;
	}
	
	args->philos->number_of_philosophers = philo_count;
	args->philos->time_to_die = ft_atoi(argv[2]);
	args->philos->time_to_sleep = ft_atoi(argv[4]);
	args->philos->time_to_eat = ft_atoi(argv[3]);
	if (argc == 6)
		args->philos->number_of_must_eat = ft_atoi(argv[5]);
}
