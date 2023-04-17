/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:21:43 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/17 13:13:24 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	launch(t_args *args, t_gen *gen, t_all *all)
{
	initialising_time(gen);
	printf("%dms initialising\n", get_chrono(gen));
	if (launch_threads(args, all) == 1)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_args		*args;
	t_gen		*gen;
	t_all		*all;

	args = malloc(sizeof(t_args));
	gen = malloc(sizeof(t_gen));
	all = malloc(sizeof(t_all));
	if (!args || !gen)
		return(free_end(args, gen, all));
	if (check_args(argc, argv, args) == 1)
	{
		printf("\033[0;31mARGS ERROR!\033[0m\n");
		return(free_end(args, gen, all));
	}
	else
		printf("\033[0;32mARGS OK!\033[0m\n");
	if (create_philos(args, gen, all) == 1)
		return(free_end(args, gen, all)); 
	if (launch(args, gen, all) == 1)
		return(free_end(args, gen, all));
	free_end(args, gen, all);
	return (0);
}