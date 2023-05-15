/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:07:49 by tserdet           #+#    #+#             */
/*   Updated: 2023/05/15 17:31:46 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	initialising_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int	get_chrono(long int begin_all)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) != 0)
		return (1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time - begin_all);
}

void	ft_usleep(long int time_in_ms, long int begin_all)
{
	long int	start_time;

	start_time = 0;
	start_time = get_chrono(begin_all);
	while ((get_chrono(begin_all) - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
