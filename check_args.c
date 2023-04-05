/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:15:50 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/05 13:42:09 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int argc, char **argv, t_args *args)
{
	(void) argv;
	if (argc == 5)
		args->nmb_of_eat = 0;
	printf("%d", args->nmb_of_eat);
	return (0);
}