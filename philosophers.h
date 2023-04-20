/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:07:27 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/20 13:53:21 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
typedef struct s_args
{
	int 				nmb_philos;
	int					ttd;
	int 				tte;
	int 				tts;
	int 				nmb_of_eat;
	int					stop;
}					t_args;
typedef struct s_gen
{

	pthread_mutex_t    	write;
	pthread_t			thread_gen;
}					t_gen;
typedef struct s_philos
{
	int					id;
	int					nb_eat;
	int 				begin;
	int					last_eat;
	long int			begin_all;
	long int			log_eat;
	t_args				*args;
	pthread_mutex_t		dead;
	pthread_mutex_t    	f_c;
	pthread_mutex_t    	*f_l;
	pthread_mutex_t		*ptr_write;
	pthread_t			thread_philo;
	pthread_t			thread_dead;
}					t_philos;
typedef struct s_all
{
	t_args			*args;
	t_gen			*gen;
	t_philos		*philos;
}					t_all;
int		check_args(int argc, char **argv, t_args *args);
int		free_end(t_args *args, t_gen *gen, t_all *all);
int		create_philos(t_args *args, t_gen *gen, t_all *all);
int		ft_atoi(const char *thestring);
int			get_chrono(long int begin_all);
long int	initialising_time(void);
void	ft_usleep(long int time_in_ms, long int begin_all);
void    is_eating(int x, pthread_mutex_t write, long int begin_all);
void	is_thinking(int x, pthread_mutex_t write, long int begin_all);
void	is_sleeping(int x, pthread_mutex_t write, long int begin_all);
int		launch_threads(t_args *args, t_gen *gen, t_all *all);
void	is_dead(int x, pthread_mutex_t write, long int begin_all);
void	*full_eat(void *all_void);
void	*dead(void *data);
void	take_fork(int x, pthread_mutex_t write, long int begin_all);
#endif