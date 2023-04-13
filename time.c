/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:07:49 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/13 15:13:55 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void initialising_time(t_gen *gen)
{
	long int	time;

	time = 0;
	gettimeofday(&gen->tv, NULL);
	time = ((*&gen->tv.tv_sec) * 1000) + ((*&gen->tv.tv_usec) / 1000);
	gen->begin = time;
}

int	get_chrono(t_gen *gen)
{
	long int	time;

	time = 0;
	gettimeofday(&gen->tv, NULL);
	time = ((*&gen->tv.tv_sec) * 1000) + ((*&gen->tv.tv_usec) / 1000);
	return (time - gen->begin);
}

void	ft_usleep(long int time_in_ms, t_gen *gen)
{
	long int	start_time;

	start_time = 0;
	start_time = get_chrono(gen);
	while ((get_chrono(gen) - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
