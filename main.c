/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:21:43 by tserdet           #+#    #+#             */
/*   Updated: 2023/05/17 18:09:47 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	launch(t_args *args, t_gen *gen, t_all *all)
{
	all->args = args;
	all->gen = gen;
	all->args->stop = 0;
	if (launch_threads(args, gen, all) == 1)
		return (1);
	return (0);
}

int	first_exec(t_args *args, t_gen *gen, t_all *all)
{
	printf("\033[0;31mARGS ERROR!\033[0m\n");
	free(args);
	free(gen);
	free(all);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args		*args;
	t_gen		*gen;
	t_all		*all;

	args = malloc(sizeof(t_args));
	gen = malloc(sizeof(t_gen));
	all = malloc(sizeof(t_all));
	if (check_args(argc, argv, args) == 1)
		return (first_exec(args, gen, all));
	else
		printf("\033[0;32mARGS OK!\033[0m\n");
	if (!args || !gen || !all)
		return (free_end(args, gen, all));
	if (create_philos(args, gen, all) == 1)
		return (free_end(args, gen, all));
	if (launch(args, gen, all) == 1)
		return (free_end(args, gen, all));
	free_end(args, gen, all);
	return (0);
}
