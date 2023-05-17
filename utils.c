/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:32:53 by tserdet           #+#    #+#             */
/*   Updated: 2023/05/17 18:54:47 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_end(t_args *args, t_gen *gen, t_all *all)
{
	int	i;

	i = 0;
	while (i < args->nmb_philos)
	{
		pthread_mutex_destroy(&all->philos->f_c);
		i++;
	}
	pthread_mutex_destroy(&gen->write);
	pthread_mutex_destroy(all->philos->ptr_write);
	free(all->philos);
	free(args);
	free(gen);
	free(all);
	all = NULL;
	return (1);
}

int	ft_atoi(const char *thestring)
{
	int	i;
	int	valeur;
	int	moins;

	i = 0;
	valeur = 0;
	moins = 0;
	while ((thestring[i] >= 9 && thestring[i] <= 13) || thestring[i] == 32)
		i++;
	if (thestring[i] == 43 || thestring[i] == 45)
	{
		if (thestring[i] == 45)
			moins++;
		i++;
	}
	while (thestring[i] && (thestring[i] >= 48 && thestring[i] <= 57))
	{
		valeur = ((valeur * 10) + (thestring[i] - 48));
		i++;
	}
	if (moins)
		valeur = -valeur;
	if (!(thestring[i] >= 48 && thestring[i] <= 57) && valeur == 0)
		return (0);
	return (valeur);
}
