/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:51:29 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/28 14:35:01 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_arg *args)
{
	gettimeofday(&args->time, NULL);
	return ((args->time.tv_sec * 1000) + (args->time.tv_usec / 1000));
}
