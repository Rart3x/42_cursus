/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:56:31 by arforgea          #+#    #+#             */
/*   Updated: 2022/09/04 19:11:38 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_error(int nb)
{
	if (nb == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (nb == 1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (0);
}

int	over_limit(char *str)
{
	const char	int_max[10] = "4294967295";
	const int	char_max = 10;
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i > char_max)
		return (1);
	else if (i < char_max)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == int_max[i])
			i++;
		else if (str[i] > int_max[i])
			return (1);
		else if (str[i] < int_max[i])
			break ;
	}
	return (0);
}

int	not_numeric_or_null(char *str)
{
	int	i;
	int	is_null;

	is_null = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			is_null = 0;
		if (str[i] < '0' || '9' < str[i])
			return (1);
		i++;
	}
	if (is_null)
		return (1);
	return (0);
}

int	dict_lines(char **tab)
{
	int	i;

	i = 0;
	while (tab[i][0] != 3)
		i++;
	return (i);
}
