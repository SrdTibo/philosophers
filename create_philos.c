/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:56:09 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/17 15:01:44 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philos(t_args *args, t_gen *gen, t_all *all)
{
	int			i;
	long int	time;
	
	i = 0;
	all->philos = malloc(sizeof(t_philos) * args->nmb_philos);
	if (!all->philos)
		return (1);
	time = initialising_time();
	printf("%dms initialising\n", 0);
	pthread_mutex_init(&gen->write, NULL);
	while (i < args->nmb_philos)
	{
		all->philos[i].id = i;
		all->philos[i].nb_eat = 0;
		all->philos[i].last_eat = 0;
		all->philos[i].ptr_write = &gen->write;
		all->philos[i].begin_all = time;
		if (pthread_mutex_init(&all->philos[i].f_c, NULL) != 0)
			return (1);
		if (i == 0)
			all->philos[i].f_l = &all->philos[args->nmb_philos].f_c;
		else
			all->philos[i].f_l = all->philos[i - 1].f_l;
		i++;
	}
	return(0);
}
