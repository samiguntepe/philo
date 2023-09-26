/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/26 10:28:50 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	*args;

	if (argc < 5 || argc > 6)
		return (0);
	args = malloc(sizeof(t_arg) * ft_atoi(argv[1]));
	arg_parser(argv, args, argc);
	if (number_of_philo_control(args->philos, argc) == 0)
		return (0);
	inits(args);
}
