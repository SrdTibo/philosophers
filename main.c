/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:21:43 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/13 13:26:46 by tserdet          ###   ########.fr       */
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
		printf("\033[0;31mARGS ERROR!\033[0m\n");
		return (1);
	}
	else
		printf("\033[0;32mARGS OK!\033[0m\n");
	if (create_philos(args, philos) == 1)
		return (1);
	free_end(args, philos);
	return (0);
}