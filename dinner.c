/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:48:18 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/26 16:53:14 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_arg *args;
	
	args = (t_arg *)arg;

// 4.filo -> 3. - 4. kitlemeye çalışacak.
	
 // 3.filo -> 2. - 3. kitledi
	eat(args, args->philos->id, args->forks->id);
 // 3.filo -> 2. - 3. unlock
	//3->sleep
	//3->think
	return (NULL);
}