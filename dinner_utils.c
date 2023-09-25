/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:01:55 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/25 20:37:03 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_arg *args)
{
	write_term(args->philos->id, 1);
	write_term(args->philos->id, 1);
	write_term(args->philos->id, 2);

}