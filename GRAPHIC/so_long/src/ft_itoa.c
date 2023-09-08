/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:49:30 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 15:14:30 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	ft_putchar(char c)
{
	return (c);
}

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i = i + 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_my_putnbr(int n, char *value)
{
	int		i;
	int		negative;

	i = 0;
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = n * -1;
	}
	while (n / 10 > 0)
	{
		value[i] = ft_putchar((n % 10) + '0');
		n = n / 10;
		i++;
	}
	value[i] = n % 10 + '0';
	if (negative == 1)
		value[i + 1] = '-';
	return (value);
}

static void	ft_swap(char *c)
{
	int		i;
	int		length;
	char	swap;

	i = 0;
	length = ft_strlen(c);
	while (i < ((length) / 2))
	{
		swap = c[i];
		c[i] = c[length - i - 1];
		c[length - i - 1] = swap;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*value;	

	if (n == 2147483647)
	{
		value = ft_strdup("2147483647");
		return (value);
	}
	if (n == -2147483648)
	{
		value = ft_strdup("-2147483648");
		return (value);
	}
	if (n > 0)
		value = ft_calloc(ft_len(n) + 1, sizeof(char));
	else
		value = ft_calloc(ft_len(n) + 1, sizeof(char));
	if (value == NULL)
		return (NULL);
	value = ft_my_putnbr(n, value);
	ft_swap(value);
	return (value);
}
