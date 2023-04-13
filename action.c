/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:48:27 by tserdet           #+#    #+#             */
/*   Updated: 2023/04/13 14:32:23 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(int x, t_gen *gen)
{
	pthread_mutex_lock(&gen->write);
	printf("%dms Philo %d is thinking\n", get_chrono(gen), x);
	pthread_mutex_unlock(&gen->write);
}