/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:28:07 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/28 14:31:49 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	arg_parser(char **argv, t_arg *args, int argc)
{
	int	i;

	i = 0;
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->time_to_eat = ft_atoi(argv[3]);
	if (argc == 6)
		args->number_of_must_eat = ft_atoi(argv[5]);
}
