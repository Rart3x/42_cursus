/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:01:17 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/11 14:02:48 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	one_philo(t_philo *philo)
{
	print_routine(philo, THINK);
	print_routine(philo, FORK);
	ft_usleep(philo, philo->data->death_time);
}

static int	routine_loop(t_philo *philosoph, int my_end, int my_eat)
{
	while (my_end == 0 && philosoph->eat_count != my_eat)
	{
		if (print_routine(philosoph, THINK))
			return (0);
		if (take_fork(philosoph))
			return (0);
	}
	return (1);
}

void	*routine(void *philo)
{
	t_philo		*philosoph;
	int			my_end;
	int			my_eat;

	philosoph = (t_philo *)philo;
	if (philosoph->data->nb_philo == 1)
	{
		one_philo(philosoph);
		return (NULL);
	}
	if (!(philosoph->n_philo % 2))
		ft_usleep(philosoph, 20);
	pthread_mutex_lock(&philosoph->data->m_end);
	my_end = philosoph->data->end;
	pthread_mutex_unlock(&philosoph->data->m_end);
	pthread_mutex_lock(&philosoph->data->m_meal);
	my_eat = philosoph->data->must_eat;
	pthread_mutex_unlock(&philosoph->data->m_meal);
	routine_loop(philosoph, my_end, my_eat);
	return (NULL);
}

static void	wait_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	open_thread(t_philo *philo)
{
	int			i;
	pthread_t	monitoring;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		if (pthread_create
			(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
		{
			perror("Failed to create thread ");
			destroy_free(philo);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_create(&monitoring, NULL, &check_death, philo) != 0)
	{
		perror("Failed to create thread ");
		destroy_free(philo);
		exit(EXIT_FAILURE);
	}
	wait_thread(philo);
	pthread_join(monitoring, NULL);
}
