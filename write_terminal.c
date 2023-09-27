/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:29 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/27 19:40:25 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    write_term(int philo_num, int ans, t_arg *args)
{
	args->time = get_time() - args->first_time;
	printf(SPC"%llu ms"END, args->time);
	printf(PURPLE" %d"END, philo_num);
	if (ans == 1)
		printf(" has taken a fork");
	else if (ans == 2)
		printf(GREEN" is eating"END);
	else if (ans == 3)
		printf(BLUE" is sleeping"END);
	else if (ans == 4)
		printf(CYAN" is thinking");
	else if (ans == 5)
		printf(RED" died"END);
	printf("\n");
	
}