/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:56:09 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/12 12:22:22 by tserdet          ###   ########.fr       */
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
	while (i < args->nmb_philos)
	{
		philos[i].id = i;
		philos[i].nb_eat = 0;
		if (pthread_mutex_init(&philos[i].f_c, NULL) != 0)
			return (1);
		i++;
	}
	return(0);
}