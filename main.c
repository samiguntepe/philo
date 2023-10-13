/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/13 13:41:26 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_arg	args;
	t_philo	*philos;

	args.died = 0;
	if (argc < 5 || argc > 6)
		return (write(2, RED"Error\n"END, 13));
	if (control(argv))
		return (write(2, RED"Error\n"END, 13));
	args.first_time = get_time();
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philos)
		return (write(2, RED"Error\n"END, 13));
	arg_parser(argv, &args, argc);
	if (arg_control(&args, argc) == 0)
	{
		free(philos);
		write(2, RED"Error\n"END, 13);
		return (0);
	}
	if (inits(&args, philos))
		return (write(2, RED"Error\n"END, 13));
	free_memory(philos, 2);
}
