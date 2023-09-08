/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:37:08 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:38 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

static int	ft_isdigit(int c)
{
	if (c == '-' || c == '+' || c == 32)
		return (1);
	if (!(c >= '0' && c <= '9'))
		ft_error_without_free();
	return (1);
}

static int	ft_number(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 32)
			return (1);
		i++;
	}
	return (0);
}

void	check_args(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0' || ft_spaces(argv[i]) == 0)
			ft_error_without_free();
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
					&& (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
				ft_error_without_free();
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& ft_number(argv[i][j - 1]) == 1
				&& ft_number(argv[i][j + 1]) == 1)
				ft_error_without_free();
			ft_isdigit(argv[i][j]);
			j++;
		}
		i++;
	}
}
