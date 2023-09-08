/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:13:14 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/11 14:05:45 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	verif_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		error_args();
	else
		are_digit(argc, argv);
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;

	verif_args(argc, argv);
	if (!ft_strncmp(argv[1], "0", ft_strlen(argv[1])))
		return (0);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return (0);
	philo->data = malloc(sizeof(t_data));
	if (!philo->data)
	{
		free(philo);
		return (0);
	}
	init_data(argc, argv, philo->data, philo);
	init_philo(philo, philo->data);
	if (philo->data->must_eat != 0)
		open_thread(philo);
	destroy_free(philo);
	return (0);
}
