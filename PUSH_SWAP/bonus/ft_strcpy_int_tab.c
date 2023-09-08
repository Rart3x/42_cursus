/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_int_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:15:42 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 14:15:46 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

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
