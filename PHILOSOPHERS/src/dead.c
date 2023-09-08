/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:08:12 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/11 14:09:31 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	death_loop_if(t_philo *phi, int i, int my_death)
{
	if (timestamp() - phi[i].last_meal >= my_death)
	{
		pthread_mutex_unlock(phi[i].m_last_m);
		pthread_mutex_lock(&(phi[i].data->m_end));
		phi[i].data->end = 1;
		pthread_mutex_unlock(&(phi[i].data->m_end));
		if (print_routine(&phi[i], DEATH) == 1)
			return (0);
		return (0);
	}
	return (1);
}

int	check_eat_c(t_philo *phi)
{
	int	i;

	i = 0;
	while (i < phi->data->nb_philo)
	{
		pthread_mutex_lock(phi[i].m_eat_c);
		if (phi[i].eat_count < phi[i].data->must_eat)
		{
			pthread_mutex_unlock(phi[i].m_eat_c);
			return (0);
		}
		pthread_mutex_unlock(phi[i].m_eat_c);
		i++;
	}
	return (1);
}

static int	death_loop(t_philo *phi)
{
	int		my_eat;
	int		my_death;
	int		eat_c;
	int		i;

	i = -1;
	while (++i < phi->data->nb_philo)
	{
		pthread_mutex_lock(&phi[i].data->m_meal);
		my_eat = phi[i].data->must_eat;
		pthread_mutex_unlock(&phi[i].data->m_meal);
		pthread_mutex_lock(phi[i].m_eat_c);
		eat_c = phi[i].eat_count;
		pthread_mutex_unlock(phi[i].m_eat_c);
		if (phi->data->must_eat != -1 && check_eat_c(phi) == 1)
			return (0);
		pthread_mutex_lock(&phi[i].data->m_dead);
		my_death = phi[i].data->death_time;
		pthread_mutex_unlock(&phi[i].data->m_dead);
		pthread_mutex_lock(phi[i].m_last_m);
		if (death_loop_if(phi, i, my_death) == 0)
			return (0);
		pthread_mutex_unlock(phi[i].m_last_m);
	}
	return (1);
}

void	*check_death(void *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	while (42)
	{
		if (!death_loop(phi))
			return (NULL);
		usleep(100);
	}
}
