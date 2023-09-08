/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:55:17 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/11 11:06:42 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_array2d(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	destroy_free(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		free(philo[i].m_fork_r);
		free(philo[i].m_eat_c);
		free(philo[i].m_last_m);
		i++;
	}
	pthread_mutex_destroy(&philo->data->m_dead);
	pthread_mutex_destroy(&philo->data->m_end);
	pthread_mutex_destroy(&philo->data->m_meal);
	pthread_mutex_destroy(&philo->data->m_print);
	free(philo->data);
	free(philo);
}
