/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:47:02 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/17 13:49:58 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*activity(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	printf("%d\n", philos->id);
	return (0);
}

int launch_threads(t_args *args, t_gen *gen, t_all *all)
{
	int i;

	i = 0;
	while (i < args->nmb_philos)
	{
		if (i % 2 == 0)
			ft_usleep(50, gen);
		pthread_create(&all->philos[i].thread_philo, NULL, &activity, &all->philos[i]);
		pthread_detach(all->philos[i].thread_philo);
		i++;	
	}
	return (0);
}