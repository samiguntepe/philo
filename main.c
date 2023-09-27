/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/27 20:13:09 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	args;
	t_philo *philos;
	
	get_time();
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (argc < 5 || argc > 6)
		return (0);
	arg_parser(argv, &args, argc);
	if (arg_control(&args, argc) == 0)
		return (0);
	inits(&args, philos);
}
