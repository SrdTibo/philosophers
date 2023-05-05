/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:07:49 by tserdet           #+#    #+#             */
/*   Updated: 2023/05/05 11:02:36 by tserdet          ###   ########.fr       */
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
	printf("%dms initialising\n", 0);
	return (time);
}

int	get_chrono(long int begin_all)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time - begin_all);
}

void	ft_usleep(long int time_in_ms, long int begin_all)
{
	long long int	actual_time;
	long long int	end_time;
	int				i;

	actual_time = get_chrono(begin_all);
	end_time = actual_time + time_in_ms;
	i = 0;
	while (get_chrono(begin_all) < end_time)
	{
		i++;
	}
}
