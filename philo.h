/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/09 21:06:25 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_must_eat;
	int		number_of_fork;
}	t_philo;

int		ft_atoi(const char *str);
void	arg_parser(char **arg, t_philo *philo, int argc);
int		number_of_philo_control(t_philo *philo, int argc);

#endif