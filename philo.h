/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/10/10 17:23:40 by sguntepe         ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_full;
	int				number_of_philosophers;
	int				number_of_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				full;
	long			first_time;
	int				died;
	int				write_died;
	int				count;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thread;
	int				left_f;
	int				right_f;
	int				id;
	int				eat_count;
	long			last_eat;
	t_arg			*args;
}	t_philo;

long		get_time(void);
int			ft_atoi(const char *str);
int			arg_control(t_arg *args, int argc);
void		arg_parser(char **argv, t_arg *args, int argc);
void		init_threads(t_philo *philos, int philo_count);
void		init_philo(t_arg *args, t_philo *philos);
void		init_forks(t_arg *args, int philo_count);
void		inits(t_arg	*args, t_philo *philos);
int			eating(t_philo *philos);
void		*dinner(void *arg);
void		write_term(int philo_num, int ans, t_philo *philos);
void		*view(void *arg);
int			check_food(t_philo *philos, int i);
void		wait_time(t_philo *philos, int wait_time);
int			one_die_check(t_philo *philos);
int			control(char **argv);

#endif