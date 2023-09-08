/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:30:54 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/19 20:30:58 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_line(char a, char b, char c, int y)
{
	int	j;

	j = 1;
	ft_putchar(a);
	while (j <= y - 2)
	{
		ft_putchar(c);
		j++;
	}
	if (y > 1)
		ft_putchar(b);
	ft_putchar('\n');
}

void	rush(int y, int x)
{
	int	i;

	i = 0;
	while (i < x && y > 0 && x > 0)
	{
		if (i == 1)
			ft_line('A', 'A', 'B', y);
		if (i > 1 && i < x)
			ft_line('B', 'B', ' ', y);
		if (i == x && x > 1)
			ft_line('C', 'C', 'B', y);
		i++;
	}
}
