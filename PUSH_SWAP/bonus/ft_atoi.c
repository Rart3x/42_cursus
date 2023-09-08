/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:16:43 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 20:22:58 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

int	ft_atoi(const char *str, char **parsed, t_parsed *a)
{
	int				i;
	long long int	value;
	int				negative;

	i = 0;
	value = 0;
	negative = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32 || str[i] == '+')
		i++;
	if (str[i] == '-')
		negative *= -1;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + str[i] - 48;
		i++;
		if (value * negative > 2147483647 || value * negative < -2147483648)
		{
			free_tab_tab(parsed);
			free_structs(a, NULL);
			ft_error(NULL, NULL);
		}
	}
	return (value * negative);
}
