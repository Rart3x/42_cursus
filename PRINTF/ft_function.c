/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:47:27 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/24 17:07:13 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_strlen_pf(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_pf(char *s)
{
	int		i;

	if (s == NULL)
	{
		ft_putstr_pf("(null)");
		return (6);
	}
	i = 0;
	if (s != 0)
	{
		write(1, s, ft_strlen_pf(s));
	}
	i = ft_strlen_pf(s);
	return (i);
}

int	ft_putnbr_pf(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr_pf(n / 10);
		i += ft_putnbr_pf(n % 10);
	}
	if (n >= 0 && n < 10)
	{
		i += ft_putchar_pf(n + '0');
	}
	return (i);
}

char	*ft_strrchr_pf(const char *s, int c)
{
	int			i;
	char		*point;

	point = (char *)s;
	i = (int)ft_strlen_pf(point);
	if (c == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (point[i] == (unsigned char)c)
			return (point + i);
		i--;
	}
	return (0);
}
