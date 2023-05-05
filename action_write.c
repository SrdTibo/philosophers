/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:48:27 by tserdet           #+#    #+#             */
/*   Updated: 2023/05/05 12:48:52 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	is_thinking(int x, pthread_mutex_t write, long int begin_all)
{
	pthread_mutex_lock(&write);
	printf("%dms %d is thinking\n", get_chrono(begin_all), x + 1);
	pthread_mutex_unlock(&write);
}

void	is_eating(int x, pthread_mutex_t write, long int begin_all)
{
	pthread_mutex_lock(&write);
	printf("%dms %d is eating\n", get_chrono(begin_all), x + 1);
	pthread_mutex_unlock(&write);
}

void	is_sleeping(int x, pthread_mutex_t write, long int begin_all)
{
	pthread_mutex_lock(&write);
	printf("%dms %d is sleeping\n", get_chrono(begin_all), x + 1);
	pthread_mutex_unlock(&write);
}

void	take_fork(int x, pthread_mutex_t write, long int begin_all)
{
	pthread_mutex_lock(&write);
	printf("%dms %d has taken a fork\n", get_chrono(begin_all), x + 1);
	pthread_mutex_unlock(&write);
}

void	is_dead(int x, pthread_mutex_t write, long int begin_all)
{
	pthread_mutex_lock(&write);
	printf("%dms %d died\n", get_chrono(begin_all), x + 1);
	pthread_mutex_unlock(&write);
}