/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:47:02 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/18 13:40:28 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	activity(void *data)
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
	
}

int launch_threads(t_args *args, t_all *all)
{
	int i;

	i = 0;
	while (i < args->nmb_philos)
	{
		if (i % 2 == 0)
			ft_usleep(args->tte / 10, all->philos[i].begin_all);
		// pthread_create(&all->philos[i].thread_philo, NULL, &activity, &all->philos[i]);
		// pthread_detach(all->philos[i].thread_philo);
		activity(&all->philos[i]);
		i++;
	}
	return (0);
}