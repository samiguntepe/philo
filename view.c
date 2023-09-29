/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:43:00 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/29 19:14:43 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	view(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos->args->number_of_philosophers)
	{
		if (philos[i].life == 0)
			return 0;
		i++;
	}
	return 1;
}