/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/20 20:08:20 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_sim *sim, int i)
{
	pthread_mutex_lock(&sim->philos[i].mtx_fork);
	write_term(sim, 1);
	write_term(sim, 1);
	write_term(sim, 2);
	
	pthread_mutex_unlock(&sim->philos[i].mtx_fork);
}