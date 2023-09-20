/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/20 19:54:56 by sguntepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

# define CYAN		"\033[0;36m"
# define PURPLE		"\033[0;35m"
# define BLUE		"\033[0;34m"
# define YELLOW		"\033[0;33m"
# define GREEN		"\033[0;32m"
# define SPC	"\033[37;2m\033[48;5;0m"
# define RED		"\033[0;31m"
# define END		"\033[0m"

typedef struct s_philo
{
	pthread_mutex_t	mtx_fork;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				fork_num;
	int				num;
}	t_philo;

typedef struct s_sim
{
	pthread_t		*th_philo;
	
	uint64_t 	time;
	t_philo		*philos;
}	t_sim;

int			ft_atoi(const char *str);
void		arg_parser(char **arg, t_philo *philo, int argc);
int			number_of_philo_control(t_philo *philo, int argc);
uint64_t	get_time(void);
void    	init_threads_fork(t_sim *sim, int philo_count);
void		inits(t_sim *sim);
void		eat(t_sim *sim, int i);
void		start_dinner(t_sim *sim);
void    	write_term(t_sim *sim, int ans);
void		*a();

#endif