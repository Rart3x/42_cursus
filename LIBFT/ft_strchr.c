/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:36:30 by kramjatt          #+#    #+#             */
/*   Updated: 2022/10/05 03:18:22 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*point;

	point = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (point[i] == (unsigned char)c)
			return ((char *)&point[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&point[i]);
	return (NULL);
}
