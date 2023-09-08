/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:55:02 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/17 18:14:13 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char first_cpy, char second_cpy, char third_cpy);

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0';
	while (first <= '7')
	{
		second = first + 1;
		while (second <= '8')
		{
			third = second + 1;
			while (third <= '9')
			{
				ft_putchar(first, second, third);
				if (first != '7')
					write(1, ", ", 2);
				third++;
			}
			second++;
		}
		first++;
	}
}

void	ft_putchar(char first_cpy, char second_cpy, char third_cpy)
{
	write(1, &first_cpy, 1);
	write(1, &second_cpy, 1);
	write(1, &third_cpy, 1);
}
