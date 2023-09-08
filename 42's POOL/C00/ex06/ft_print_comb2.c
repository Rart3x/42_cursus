/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:33:08 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/18 13:33:12 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_conversion(int cnv);

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	second = 0;
	while (first <= 98)
	{
		second = first + 1 ;
		while (second <= 99)
		{
			ft_conversion(first);
			write(1, " ", 1);
			ft_conversion(second);
			if (first != 98)
			{
				write(1, ", ", 1);
			}	
			second++;
		}
		first++;
	}
	write (1, "\n", 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_conversion(int cnv)
{
	ft_putchar(cnv / 10 + 48);
	ft_putchar(cnv % 10 + 48);
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
