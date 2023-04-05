/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:15:50 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/05 14:37:44 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int convert_args(int argc, char **argv, t_args *args)
{
	args->nmb_philos = atoi(argv[1]);
	args->ttd = atoi(argv[2]);
	args->tte = atoi(agrv[3]);
	args->tts = atoi(argv[4]);
	if (args->nmb_of_eat != -1)
		args->nmb_of_eat = atoi(argv[5]);
	return (0);
}

int	check_args(int argc, char **argv, t_args *args)
{
	(void) argv;
	if (argc < 5 || argc > 6)
		return (1);
	if (argc == 5)
		args->nmb_of_eat = -1;
	convert_args(argc, argv, args);
	return (0);
}