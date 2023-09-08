/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:10:08 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/11 14:16:25 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

static int	init_data_mutex(pthread_mutex_t *m_print, pthread_mutex_t *m_meal,
		pthread_mutex_t *m_dead, pthread_mutex_t *m_end)
{
	if (pthread_mutex_init(m_print, NULL) != 0)
		return (0);
	if (pthread_mutex_init(m_meal, NULL) != 0)
		return (0);
	if (pthread_mutex_init(m_dead, NULL) != 0)
		return (0);
	if (pthread_mutex_init(m_end, NULL) != 0)
		return (0);
	return (1);
}

void	init_data(int argc, char **argv, t_data *data, t_philo *philo)
{
	if ((argc == 6 && ft_atoi(argv[5]) == -1)
		|| (ft_atoi(argv[1]) == -1 || ft_atoi(argv[2]) == -1
			|| ft_atoi(argv[3]) == -1 || ft_atoi(argv[4]) == -1))
		error_overflow();
	data->nb_philo = ft_atoi(argv[1]);
	data->nb_forks = data->nb_philo;
	data->death_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->end = 0;
	data->start_time = timestamp();
	if (init_data_mutex(&data->m_print, &data->m_meal,
			&data->m_dead, &data->m_end) == 0)
	{
		free(data);
		free(philo);
		exit(EXIT_FAILURE);
	}
}

static void	init_philo_splitted(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (i != data->nb_philo - 1)
		{
			free(philo[i].m_fork_l);
			philo[i].m_fork_l = philo[i + 1].m_fork_r;
		}
		else
		{
			free(philo[i].m_fork_l);
			philo[i].m_fork_l = philo[0].m_fork_r;
		}
		i++;
	}
}

static int	init_philo_mutex(pthread_mutex_t **m_fork_l,
		pthread_mutex_t **m_fork_r, pthread_mutex_t **m_eat_c,
		pthread_mutex_t **m_last_m)
{
	if (!m_fork_l || !m_fork_r || !m_eat_c || !m_last_m)
		return (0);
	if (pthread_mutex_init(*m_fork_l, NULL) != 0)
		return (0);
	if (pthread_mutex_init(*m_fork_r, NULL) != 0)
		return (0);
	if (pthread_mutex_init(*m_eat_c, NULL) != 0)
		return (0);
	if (pthread_mutex_init(*m_last_m, NULL) != 0)
		return (0);
	return (1);
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].n_philo = i + 1;
		philo[i].is_dead = 0;
		philo[i].last_meal = timestamp();
		philo[i].eat_count = 0;
		philo[i].data = data;
		philo[i].m_fork_l = malloc(sizeof(pthread_mutex_t));
		philo[i].m_fork_r = malloc(sizeof(pthread_mutex_t));
		philo[i].m_eat_c = malloc(sizeof(pthread_mutex_t));
		philo[i].m_last_m = malloc(sizeof(pthread_mutex_t));
		if (init_philo_mutex(&philo[i].m_fork_l, &philo[i].m_fork_r,
				&philo[i].m_eat_c, &philo[i].m_last_m) == 0)
		{
			destroy_free(philo);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	init_philo_splitted(philo, data);
}
