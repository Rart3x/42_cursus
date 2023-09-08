/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:09:58 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/06 23:26:17 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	mini_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->m_print);
	printf("%06ld %d %s\n", (timestamp() - philo->data->start_time),
		philo->n_philo, str);
	pthread_mutex_unlock(&philo->data->m_print);
}

int	print_routine(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->m_end);
	if (philo->data->end && !ft_strncmp(str, "died 💀", 6))
	{
		pthread_mutex_unlock(&philo->data->m_end);
		mini_print(philo, str);
		return (1);
	}
	if (philo->data->end)
	{
		pthread_mutex_unlock(&philo->data->m_end);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_end);
	mini_print(philo, str);
	return (0);
}
