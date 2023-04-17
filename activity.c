/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:47:02 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/17 13:21:56 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*activity(void *all_void)
{
	(void)all_void;
	t_all			*all;
	all = (t_all *)all_void;
	printf("d\n");
	return (0);
}

int launch_threads(t_args *args, t_all *all)
{
	int i;

	i = 0;
	while (i < args->nmb_philos)
	{
		pthread_create(&all->philos[i].thread_philo, NULL, &activity, all);
		pthread_detach(all->philos[i].thread_philo);
		i++;
	}
	return (0);
}