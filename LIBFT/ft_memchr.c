/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:16:49 by kramjatt          #+#    #+#             */
/*   Updated: 2022/09/29 12:38:47 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*swap;

	swap = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (swap[i] == (unsigned char)c)
			return (swap + i);
		i++;
	}
	return (0);
}	
