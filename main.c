/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:16 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/14 18:49:01 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;
	uint64_t time;
	sim.philos = malloc(sizeof(t_philo)); 
	if (argc < 5 || argc > 6)
		return (0);
	time = get_time();
	arg_parser(argv, sim.philos, argc);
	if (number_of_philo_control(sim.philos, argc) == 0)
		return (0);

	init_threads(&sim, sim.philos->number_of_philosophers);

	// exit(1);

}
