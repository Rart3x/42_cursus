/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:10:03 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/06 20:43:11 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	print_fork_two(t_philo *philo)
{
	if (print_routine(philo, FORK) == 1)
	{
		pthread_mutex_unlock(philo->m_fork_l);
		pthread_mutex_unlock(philo->m_fork_r);
		return (1);
	}
	return (0);
}

static int	print_fork_one(t_philo *philo)
{
	if (print_routine(philo, FORK) == 1)
	{
		pthread_mutex_unlock(philo->m_fork_r);
		return (1);
	}
	return (0);
}

int	take_fork(t_philo *philo)
{
	int		i;

	i = 0;
	pthread_mutex_lock(philo->m_fork_r);
	if (print_fork_one(philo))
		return (1);
	pthread_mutex_lock(philo->m_fork_l);
	if (print_fork_two(philo))
		return (1);
	if (eat(philo))
	{
		pthread_mutex_unlock(philo->m_fork_l);
		pthread_mutex_unlock(philo->m_fork_r);
		return (1);
	}
	pthread_mutex_unlock(philo->m_fork_l);
	pthread_mutex_unlock(philo->m_fork_r);
	if (print_routine(philo, SLEEP) == 1)
		return (1);
	ft_usleep(philo, philo->data->sleep_time);
	return (0);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_meal);
	if (print_routine(philo, EAT) == 1)
	{
		pthread_mutex_unlock(&philo->data->m_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_meal);
	pthread_mutex_lock(philo->m_last_m);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(philo->m_last_m);
	pthread_mutex_lock(philo->m_eat_c);
	philo->eat_count++;
	pthread_mutex_unlock(philo->m_eat_c);
	ft_usleep(philo, philo->data->eat_time);
	return (0);
}
