/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:27:23 by sguntepe          #+#    #+#             */
/*   Updated: 2023/09/25 20:37:16 by sguntepe         ###   ########.fr       */
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

typedef struct s_forks
{
	pthread_mutex_t	*fork;
	int				id;
}	t_fork;

typedef struct s_philo
{
	t_fork			*forks;
	pthread_t		thread;
	uint64_t 		time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				fid;
	int				id;
}	t_philo;

typedef struct s_arg
{
	t_philo	*philos;
	t_fork	*forks;
}	t_arg;

uint64_t	get_time(void);
int			ft_atoi(const char *str);
int			number_of_philo_control(t_philo *philo, int argc);
void		arg_parser(char **argv, t_arg *args, int argc);
void		init_threads_fork(t_arg *args, int philo_count);
void		inits(t_arg	*args);
void		eat(t_arg *args);
void		*dinner(void *arg);
void    	write_term(int philo_num, int ans);

#endif