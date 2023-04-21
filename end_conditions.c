/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:02:23 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/21 15:02:50 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*full_eat(void *data)
{
	int	i;
	int				eat;
	t_all			*all;

	i = 0;
	eat = 1;
	all = (t_all *)data;
	while (1)
	{
		while (i < all->args->nmb_philos)
		{
			if (all->philos[i].nb_eat < all->args->nmb_of_eat)
			{
				i = 0;
				eat = 0;
				break ;
			}
			i++;
		}
		if (eat == 1)
			break ;
		eat = 1;
	}
	all->philos->args->stop = 1;
	return (NULL);
}

int	if_he_died(t_philos *philos)
{
	// printf("Actual time: %d\n Time Begin: %ld\n Time to die :%d\n", get_chrono(philos->begin_all), philos->begin_all, philos->args->ttd);
	if (get_chrono(philos->begin_all) - philos->log_eat >= 
		philos->args->ttd)
	{
		is_dead(philos->id, *philos->ptr_write, philos->begin_all);
		philos->args->stop = 1;
		return (1);
	}
	return (0);
}

void	*dead(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	if (philos->args->stop == 0)
	{
		ft_usleep(philos->args->ttd, philos->begin_all);
		if_he_died(philos);
	}
	return (NULL);
}