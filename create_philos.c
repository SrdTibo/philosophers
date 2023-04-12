/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:56:09 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/12 12:59:28 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philos(t_args *args, t_philos *philos)
{
	int	i;

	i = 0;
	philos = malloc(sizeof(t_philos) * args->nmb_philos);
	if (!philos)
	{
		free_end(args, philos);
		return (1);
	}
	pthread_mutex_init(args->write, NULL);
	while (i < args->nmb_philos)
	{
		philos[i].id = i;
		philos[i].nb_eat = 0;
		if (pthread_mutex_init(&philos[i].f_c, NULL) != 0)
			return (1);
		if (i == 0)
			philos[i].f_l = &philos[args->nmb_philos].f_c;
		else
			philos[i].f_l = philos[i - 1].f_l;
		i++;
	}
	return(0);
}