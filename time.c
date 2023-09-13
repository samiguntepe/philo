/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <sguntepe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:51:29 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/13 22:34:15 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_sim *sim)
{
	struct timeval	ct;
	long			past_time;

	gettimeofday(&ct, NULL);
	past_time = (ct.tv_sec * 1000)
		+ (ct.tv_usec / 1000) - sim->start_time;
	return (past_time);
}
