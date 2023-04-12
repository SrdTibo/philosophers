/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:21:43 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/12 11:55:12 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_args		*args;
	t_philos	*philos;

	philos = NULL;
	args = malloc(sizeof(t_args));
	if (!args)
	{
		free_end(args, philos);
		return (1);
	}
	if (check_args(argc, argv, args) == 1)
	{
		printf("\033[1;31mARGS ERROR!\n");
		return (1);
	}
	else
		printf("\033[1;32mARGS OK!\n");
	if (create_philos(args, philos) == 1)
		return (1);
	free_end(args, philos);
	return (0);
}