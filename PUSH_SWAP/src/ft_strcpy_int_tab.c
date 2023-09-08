/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_int_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:19:34 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 20:19:39 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_strcpy_int_tab(int *dest, int *to_copy, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = to_copy[i];
		i++;
	}
	return (dest);
}
