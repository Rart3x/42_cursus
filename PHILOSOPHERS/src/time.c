/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:49:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/06 19:49:43 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	timestamp(void)
{
	struct timeval	timev;

	gettimeofday(&timev, NULL);
	return ((timev.tv_sec * 1000) + (timev.tv_usec / 1000));
}

void	ft_usleep(t_philo *philo, int ms_time)
{
	if (philo->data->eat_time + philo->data->sleep_time
		> philo->data->death_time)
		usleep(philo->data->death_time * 1000);
	else
		usleep(ms_time * 1000);
}
