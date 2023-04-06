/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:21:43 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/06 15:56:48 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
	{
		free_end(args);
		return (0);
	}
	if (check_args(argc, argv, args) == 1)
		return (1);
	else
		printf("\033[1;32mARGS OK!\n");
	free_end(args);
	return (0);
}