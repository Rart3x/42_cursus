/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tab_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:16:52 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/18 18:28:51 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static char	*ft_strlcpy(char *dst, char *src, int size)
{
	int		i;

	i = 0;
	if (size == 0)
		return (NULL);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**copy_tab_tab(char **tab)
{
	size_t	i;
	char	**cpy_tab;

	i = 0;
	cpy_tab = ft_calloc(count_tab(tab) + 1, sizeof(char *) + 1);
	while (tab[i])
	{
		cpy_tab[i] = ft_calloc(ft_strlen(tab[i]), sizeof(char));
		cpy_tab[i] = ft_strlcpy(cpy_tab[i], tab[i], ft_strlen(tab[i]));
		i++;
	}
	cpy_tab[i] = NULL;
	return (cpy_tab);
}
