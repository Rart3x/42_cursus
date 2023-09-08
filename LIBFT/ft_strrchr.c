/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:57:46 by kramjatt          #+#    #+#             */
/*   Updated: 2022/10/04 23:20:23 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*point;

	point = (char *)s;
	i = (int)ft_strlen(point);
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
