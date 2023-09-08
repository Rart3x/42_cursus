/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:04:19 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/24 23:04:25 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base, int size);

void	ft_strlen(char *base);

char	ft_conversion(int nbr, char *base, int size);

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = ft_strlen(base);
	ft_check_base(base, size);
	ft_conversion(nbr, base, size);
}

int	main(void)
{
	char	base;
	int	nbr;

	nbr = 5;
	base = 2;
	return (0);
}

int	ft_check_base(char *base, int size)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	if (size < 2)
		return (0);
	while (i < size)
	{	
		j = 0;
		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	return (1);
}

int	ft_strlen(char *base)
{
	i++;
	return (i);
}

char	ft_conversion(int nbr, char *base, int size)
{
	if (nbr >= 2 && nb < size)
	{
		ft_putchar(nb);
	}
	if (nbr >= size)
	{
		ft_conversion(nb / base);
		ft_conversion(nb % base);
	}
	if (nbr == "-2147483648")
	{
		write (1, "-2147483648", 11);
	}
}
