/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:47:02 by tserdet           #+#    #+#             */
/*   Updated: 2023/05/06 20:51:06 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*solo_philo(t_philos *philos)
{
	ft_usleep(philos->args->tte, philos->begin_all);
	pthread_mutex_unlock(&(philos->f_c));
	return (0);
}

void	*activity(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	pthread_mutex_lock(&philos->f_c);
	take_fork(philos->id, *philos->ptr_write, philos->begin_all);
	if (philos->args->nmb_philos == 1)
		return (solo_philo(philos));
	pthread_mutex_lock(philos->f_l);	
	take_fork(philos->id, *philos->ptr_write, philos->begin_all);
	is_eating(philos->id, *philos->ptr_write, philos->begin_all);
	philos->log_eat = get_chrono(philos->begin_all);
	if (philos->nb_eat != 2147483647)
		philos->nb_eat += 1;
	ft_usleep(philos->args->tte, philos->begin_all);
	// printf("\033[0;31m%dms Philo %d eated %d times (%ldms)\033[0m\n",get_chrono(philos->begin_all), philos->id  + 1, philos->nb_eat, philos->log_eat);
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
	philos->begin_all = initialising_time();
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
	// long int	time;

	i = 0;
	// time = initialising_time();
	pthread_mutex_init(&gen->write, NULL);
	while (i < args->nmb_philos)
	{
		// all->philos[i].begin_all = time;
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
	while (all->philos->args->stop == 0);
	return (0);
}

// 	test 							resultat attendu 												resultat obtenu
//
// ./philo 1 200 200 200 			philo 1 ne prend qu'une fourchette et meurt au bout de 200 ms -	OK
// ./philo 2 800 200 200			personne ne meurt - 											OK
// ./philo 5 800 200 200 		 	personne ne meurt - 											OK
// ./philo 5 800 200 200 7 			la simulation s'arrete quand chaque philo a mange 7 fois - 		OK
// ./philo 4 410 200 200 			personne ne meurt - 											1 meurs
// ./philo 4 310 200 200 			un philo meurt - 												OK
// ./philo 4 500 200 1.2 			argument invalide - 											OK
// ./philo 4 0 200 200 				argument invalide - 											OK
// ./philo 4 -500 200 200 			argument invalide - 											OK
// ./philo 4 500 200 2147483647 	un philo meurt au bout de 500 ms - 								OK
// ./philo 4 2147483647 200 200 	personne ne meurt - 											OK
// ./philo 4 214748364732 200 200 	argument invalide - 											OK
// ./philo 4 200 210 200 			un philo meurt, il faut afficher la mort avant 210 ms -  		OK
