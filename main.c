/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:21:43 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/13 14:33:18 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_args		*args;
	t_philos	*philos;
	t_gen		*gen;

	philos = NULL;
	args = malloc(sizeof(t_args));
	gen = malloc(sizeof(t_gen));

	if (!args || !gen)
	{
		free_end(args, philos, gen);
		return (1);
	}
	if (check_args(argc, argv, args) == 1)
	{
		printf("\033[0;31mARGS ERROR!\033[0m\n");
		return (1);
	}
	else
		printf("\033[0;32mARGS OK!\033[0m\n");
	if (create_philos(args, philos, gen) == 1)
		return (1);
	gettimeofday(&gen->tv, NULL);
	gen->begin = gen->tv.tv_usec;
	free_end(args, philos, gen);
	return (0);
}