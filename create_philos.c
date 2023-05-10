/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:56:09 by tserdet           #+#    #+#             */
/*   Updated: 2023/05/06 22:56:06 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	all_create(int i, t_gen *gen, t_all *all)
{
	all->philos[i].id = i;
	all->philos[i].nb_eat = 0;
	all->philos[i].log_eat = 0;
	all->philos[i].ptr_write = &gen->write;
}

int	create_philos(t_args *args, t_gen *gen, t_all *all)
{
	int			i;

	i = 0;
	all->philos = malloc(sizeof(t_philos) * args->nmb_philos);
	all->philos->args = malloc(sizeof(t_args) * args->nmb_philos);
	if (!all->philos || !all->philos->args)
		return (1);
	while (i < args->nmb_philos)
	{
		all_create(i, gen, all);
		if (pthread_mutex_init(&all->philos[i].f_c, NULL) != 0)
			return (1);
		if (i == 0)
			all->philos[i].f_l = &all->philos[args->nmb_philos].f_c;
		else
			all->philos[i].f_l = &all->philos[i - 1].f_c;
		i++;
	}
	return (0);
}
