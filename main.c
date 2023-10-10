/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/10 17:24:00 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	args;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (0);
	if (control(argv))
		return (0);
	args.first_time = get_time();
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	arg_parser(argv, &args, argc);
	if (arg_control(&args, argc) == 0)
		return (0);
	inits(&args, philos);
}
