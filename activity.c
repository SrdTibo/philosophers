/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:47:02 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/20 14:31:08 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*activity(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	pthread_mutex_lock(&philos->f_c);
	take_fork(philos->id, *philos->ptr_write, philos->begin_all);
	pthread_mutex_lock(philos->f_l);
	take_fork(philos->id, *philos->ptr_write, philos->begin_all);
	is_eating(philos->id, *philos->ptr_write, philos->begin_all);
	ft_usleep(philos->args->tte, philos->begin_all);
	philos->log_eat = get_chrono(philos->begin_all);
	if (philos->nb_eat != 2147483647)
		philos->nb_eat += 1;
	pthread_mutex_unlock(&philos->f_c);
	pthread_mutex_unlock(philos->f_l);
	is_sleeping(philos->id, *philos->ptr_write, philos->begin_all);
	ft_usleep(philos->args->tts, philos->begin_all);
	is_thinking(philos->id, *philos->ptr_write, philos->begin_all);
	return 0;
}

void	*threads(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	if (philos->id % 2 == 0)
		ft_usleep(philos->args->tte / 10, philos->begin_all);
	while (philos->args->stop == 0)
	{
		if (pthread_create(&philos->thread_dead, NULL, &dead, (void *)philos) != 0)
		{
			printf("Error when creating the thread\n");
			return (NULL);
		}
		activity(philos);
		pthread_detach(philos->thread_dead);
	}
	return (0);
}

int launch_threads(t_args *args, t_gen *gen, t_all *all)
{
	int i;
	long int	time;

	i = 0;
	time = initialising_time();
	pthread_mutex_init(&gen->write, NULL);
	while (i < args->nmb_philos)
	{
		all->philos[i].begin_all = time;
		all->philos[i].args = args;
		if (pthread_create(&all->philos[i].thread_philo, NULL,
				&threads, &all->philos[i]) != 0)
			return (1);
		pthread_detach(all->philos[i].thread_philo);
		i++;
	}
	if (args->nmb_of_eat != -1)
	{
		if (pthread_create(&gen->thread_gen, NULL, &full_eat,
				(void *)all) != 0)
			return (-1);
		pthread_detach(gen->thread_gen);
	}
	while (all->args->stop == 0);
	return (0);
}
