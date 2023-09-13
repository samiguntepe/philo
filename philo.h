/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <sguntepe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/13 22:16:18 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_must_eat;
	int		number_of_fork;
}	t_philo;

typedef struct s_sim
{
	t_philo	*philos;
	long	start_time;
}	t_sim;

int		ft_atoi(const char *str);
void	arg_parser(char **arg, t_philo *philo, int argc);
int		number_of_philo_control(t_philo *philo, int argc);
long	get_time(t_sim *sim);

#endif