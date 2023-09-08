/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:06:29 by cmassera          #+#    #+#             */
/*   Updated: 2022/09/04 11:11:35 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str, int *begin)
{
	if (*begin == 0)
		write(1, " ", 1);
	write(1, str, ft_strlen(str));
	*begin = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_strncpy(char *dest, char *src, int *n)
{
	if (*n == 0 && (ft_strlen(src) + 3) % 3 != 0)
	{
		if ((ft_strlen(src) + 3) % 3 == 1)
		{
			dest[0] = '0';
			dest[1] = '0';
			dest[2] = src[0];
			*n = 1;
		}
		else if ((ft_strlen(src) + 3) % 3 == 2)
		{
			dest[0] = '0';
			dest[1] = src[0];
			dest[2] = src[1];
			*n = 2;
		}
	}
	else
	{
		dest[0] = src[*n];
		dest[1] = src[*n + 1];
		dest[2] = src[*n + 2];
		*n += 3;
	}
}

char	*ft_swap(char *str, char *tab)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
