/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:43:25 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/31 19:43:29 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*tab;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	range = max - min;
	tab = malloc(range * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (i < range)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
