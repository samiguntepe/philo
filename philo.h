/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/27 19:39:20 by sguntepe         ###   ########.fr       */
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
# define SPC		"\033[37;2m\033[48;5;0m"
# define RED		"\033[0;31m"
# define END		"\033[0m"

typedef struct s_arg
{
	int				number_of_philosophers;
	int				number_of_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	uint64_t		first_time;
	uint64_t		current_time;
	uint64_t 		time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thread;
	uint64_t 		time;
	int				left_f;
	int				right_f;
	int				id;
	t_arg			*args;
}	t_philo;


uint64_t	get_time(void);
int			ft_atoi(const char *str);
int			arg_control(t_arg *args, int argc);
void		arg_parser(char **argv, t_arg *args, int argc);
void		init_threads_fork(t_arg *args, t_philo *philos, int philo_count);
void		init_philo(t_arg *args, t_philo *philos);
void		inits(t_arg	*args, t_philo *philos);
void		eat(t_philo *philos, int phid);
void		*dinner(void *arg);
void    	write_term(int philo_num, int ans, t_arg *args);

#endif