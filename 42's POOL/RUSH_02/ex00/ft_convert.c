/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:54:28 by cmassera          #+#    #+#             */
/*   Updated: 2022/09/04 19:18:02 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	ft_convert_tens(char *str, int *size, int *begin, char **tab)
{
	int	i;

	i = 1;
	if (str[i] == '1')
	{
		ft_putstr(tab[(str[i + 1] - '0') + 10], begin);
		*size = 0;
	}
	else
	{
		ft_putstr(tab[str[i] - '0' + 18], begin);
		if (str[i + 1] != '0')
		{
			ft_putstr(tab[str[i + 1] - '0'], begin);
			*size = 0;
		}
	}
}

void	ft_convert_hundreds(char *str, int *begin, char **tab)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (size == 3 && str[i] != '0')
		{
			ft_putstr(tab[str[i] - '0'], begin);
			ft_putstr(tab[28], begin);
		}
		if (size == 2 && str[i] != '0')
		{
			ft_convert_tens(str, &size, begin, tab);
		}
		if (size == 1 && str[i] != '0')
		{
			ft_putstr(tab[str[i] - '0'], begin);
		}
		i++;
		size--;
	}
}

int	ft_max_i(char *str)
{
	int		thing_ion;

	thing_ion = (ft_strlen(str) - 1) / 3;
	if (thing_ion != 0)
		return (thing_ion + 28);
	if (ft_strlen(str) == 3)
		return (28);
	if (ft_strlen(str) == 2)
	{
		if (str[0] == '1')
			return ((str[1] - '0') + 10);
		else
			return (20 + 2 - (str[0] - '0'));
	}
	if (ft_strlen(str) == 1)
		return (str[0] - '0');
	return (0);
}

void	ft_convert_all(char *str, char **tab)
{
	int		thing_ion;
	int		current_num;
	int		begin;
	char	*buff;

	buff = (char *)malloc(3 * sizeof(char));
	thing_ion = (ft_strlen(str) - 1) / 3 + 1;
	current_num = 0;
	begin = 1;
	if (str[0] == '0')
	{
		ft_putstr(tab[0], &begin);
		thing_ion = -1;
	}
	while (--thing_ion > -1)
	{
		ft_strncpy(buff, str, &current_num);
		if (ft_strcmp(buff, "000") != 0)
		{
			ft_convert_hundreds(buff, &begin, tab);
			if (thing_ion != 0)
				ft_putstr(tab[thing_ion + 28], &begin);
		}
	}
	free(buff);
}

void	ft_convert(char *str, char **tab)
{
	if (ft_max_i(str) >= dict_lines(tab))
	{
		write(1, "Dict Error", 10);
		return ;
	}
	ft_convert_all(str, tab);
}
