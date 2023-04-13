/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:07:27 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/13 13:42:50 by tserdet          ###   ########.fr       */
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
}					t_args;
typedef struct s_gen
{
	pthread_mutex_t    	write;
}					t_gen;
typedef struct s_philos
{
	int					id;
	int					nb_eat;
	int 				begin;
	pthread_mutex_t    	f_c;
	pthread_mutex_t    	*f_l;
}					t_philos;
int	check_args(int argc, char **argv, t_args *args);
void free_end(t_args *args, t_philos *philos, t_gen *gen);
int	create_philos(t_args *args, t_philos *philos, t_gen *gen);
int	ft_atoi(const char *thestring);
#endif