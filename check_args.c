/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:15:50 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/05 15:03:55 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int only_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] > '9' && argv[i][j] < '0')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int check_converted(t_args *args)
{
	if (args->nmb_philos <= 0 || args->ttd <= 0 || args->tte <= 0)
		return (1);
	if (args->tts <= 0 || args->nmb_of_eat)
		return (1);
	return (0);
}

int convert_args(char **argv, t_args *args)
{
	args->nmb_philos = atoi(argv[1]);
	args->ttd = atoi(argv[2]);
	args->tte = atoi(argv[3]);
	args->tts = atoi(argv[4]);
	if (args->nmb_of_eat != -1)
		args->nmb_of_eat = atoi(argv[5]);
	return (check_converted(args));
}

int	check_args(int argc, char **argv, t_args *args)
{	
	if (only_int(argc, argv) == 1)
		return (1);
	if (argc < 5 || argc > 6)
		return (1);
	if (argc == 5)
		args->nmb_of_eat = -1;
	convert_args(argv, args);
	return (0);
}