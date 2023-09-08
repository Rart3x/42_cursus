/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gazzopar <gazzopar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:21:07 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/07 15:39:30 by gazzopar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ignore_whitespaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && s[i] != '\t')
			return (i);
		i++;
	}
	return (i);
}

bool	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

int	skip_spaces(char **file, int index)
{
	int	i;

	i = index;
	while (file[i])
	{
		if (only_spaces(file[i]) == false)
			return (i - index);
		i++;
	}
	return (0);
}

bool	is_only_spaces(char **arr, int i)
{
	while (arr[i])
	{
		if (only_spaces(arr[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
