/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:32:38 by kramjatt          #+#    #+#             */
/*   Updated: 2022/09/30 17:30:54 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*swap;
	unsigned char	*swap_dest;

	swap = (unsigned char *)src;
	swap_dest = (unsigned char *)dest;
	if (swap_dest == NULL && swap == NULL)
		return (0);
	if (swap_dest > swap)
	{
		while (n)
		{
			*(swap_dest + n - 1) = *(swap + n - 1);
			n--;
		}
		return (dest);
	}
	while (n)
	{
		*swap_dest++ = *swap++;
		n--;
	}
	return (dest);
}
