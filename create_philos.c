/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:56:09 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/17 13:18:36 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philos(t_args *args, t_gen *gen, t_all *all)
{
	int	i;

	i = 0;
	all->philos = malloc(sizeof(t_philos) * args->nmb_philos);
	if (!all->philos)
		return (1);
	pthread_mutex_init(&gen->write, NULL);
	while (i < args->nmb_philos)
	{
		all->philos[i].id = i;
		all->philos[i].nb_eat = 0;
		all->philos[i].last_eat = 0;
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
