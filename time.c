/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:51:29 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/14 15:45:18 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	static struct timeval	start_time = {0};
	struct timeval			current_time;
	uint64_t				elapsed_ms;

	gettimeofday(&current_time, NULL);
	if (start_time.tv_sec == 0 && start_time.tv_usec == 0)
		start_time = current_time;
	elapsed_ms = (uint64_t)(current_time.tv_sec - start_time.tv_sec) * 1000
		+ (uint64_t)(current_time.tv_usec - start_time.tv_usec) / 1000;
	return (elapsed_ms);
}
