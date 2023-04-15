/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:48:27 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/14 15:18:11 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	is_thinking(int x, t_gen *gen)
{
	pthread_mutex_lock(&gen->write);
	printf("%dms %d is thinking\n", get_chrono(gen), x);
	pthread_mutex_unlock(&gen->write);
}

void	is_eating(int x, t_gen *gen, t_args *args)
{
	pthread_mutex_lock(&gen->write);
	printf("%dms %d is eating\n", get_chrono(gen), x);
	pthread_mutex_unlock(&gen->write);
	ft_usleep(args->tte, gen);
}

void	is_sleeping(int x, t_gen *gen, t_args *args)
{
	pthread_mutex_lock(&gen->write);
	printf("%dms %d is sleeping\n", get_chrono(gen), x);
	pthread_mutex_unlock(&gen->write);
	ft_usleep(args->tts, gen);
}

void	take_fork(int x, t_gen *gen)
{
	pthread_mutex_lock(&gen->write);
	printf("%dms %d has taken a fork\n", get_chrono(gen), x);
	pthread_mutex_unlock(&gen->write);
}

void	is_dead(int x, t_gen *gen)
{
	pthread_mutex_lock(&gen->write);
	printf("%dms %d died\n", get_chrono(gen), x);
	pthread_mutex_unlock(&gen->write);
}