/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:29 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/20 20:06:35 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    write_term(t_sim *sim, int ans)
{
	printf(SPC"%llu ms"END, get_time());
	printf(PURPLE" %d"END,sim->philos->num);
	
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