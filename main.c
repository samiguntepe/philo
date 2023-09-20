/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/20 19:07:05 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;
	get_time();
	sim.philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (argc < 5 || argc > 6)
		return (0);
	arg_parser(argv, sim.philos, argc);
	if (number_of_philo_control(sim.philos, argc) == 0)
		return (0);
	inits(&sim);
	start_dinner(&sim);
}
