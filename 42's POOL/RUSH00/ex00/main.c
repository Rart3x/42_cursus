/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:59:09 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/20 17:50:36 by mattandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int y, int x);

int	ft_atoi(char *str)
{
	int	value;
	int	neg;

	value = 0;
	neg = 1;
	while (*str >= '\t' && *str <= '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + *str - 48;
		str++;
	}
	return (value * neg);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
		write (1, "prend 2 paramètres \"x\" \"y\"", 32);
	else
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (x <= 0 || y <= 0)
			write (1, "rentrez des valeurs entre 0 et 2147483647\n", 42);
		else
			rush(x, y);
	}
	return (0);
}
