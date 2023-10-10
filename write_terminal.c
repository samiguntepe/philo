/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:57:29 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/10 15:27:35 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_term(int philo_num, int ans, t_philo *philos)
{
	pthread_mutex_lock(&philos->args->write);
	if (philos->args->write_died == 1)
	{
		pthread_mutex_unlock(&philos->args->write);
		return ;
	}
	printf(SPC"%ld ms"END, get_time() - philos->args->first_time);
	printf(PURPLE" %d"END, philo_num);
	if (ans == 1)
		printf(" has taken a fork");
	else if (ans == 2)
		printf(GREEN" is eating"END);
	else if (ans == 3)
		printf(BLUE" is sleeping"END);
	else if (ans == 4)
		printf(CYAN" is thinking"END);
	else if (ans == 5)
	{
		philos->args->write_died = 1;
		printf(RED" died"END);
	}
	printf("\n");
	pthread_mutex_unlock(&philos->args->write);
}
