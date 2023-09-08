/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:29:21 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 16:57:45 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"
#include <stddef.h>
#include <stdlib.h>

int	ft_strrchr(const char *s, int c)
{
	int			i;
	int			cpt;
	char		*point;

	cpt = -1;
	point = (char *)s;
	i = (int)ft_strlen(point) - 1;
	if (c == '\0')
		return (cpt);
	while (i >= 0)
	{
		if (point[i] == (unsigned char)c)
			cpt++;
		i--;
	}
	return (cpt);
}
