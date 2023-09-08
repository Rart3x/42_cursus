/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:47:36 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/14 19:13:34 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

int	ft_putnbr_base(int fd, long n, char *base)
{
	long	i;
	long	n_cpy[16];
	int		z;

	i = 0;
	z = 0;
	if (ft_strlen_pf(base) < 2 || ft_strrchr_pf(base, '-') != 0
		|| ft_strrchr_pf(base, '+') != 0 || n == 0)
		z += ft_putchar_pf(fd, '0');
	while (n)
	{
		n_cpy[i] = n % ft_strlen_pf(base);
		n = n / ft_strlen_pf(base);
		i++;
		z++;
	}
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar_pf(fd, base[n_cpy[i]]);
		i--;
	}
	return (z);
}

int	ft_put_unsigned_nbr(int fd, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_putchar_pf(fd, '0');
	if (n >= 10)
	{
		i += ft_putnbr_pf(fd, n / 10);
		i += ft_putnbr_pf(fd, n % 10);
	}
	if (n > 0 && n < 10)
	{
		i += ft_putchar_pf(fd, n + '0');
	}
	return (i);
}
