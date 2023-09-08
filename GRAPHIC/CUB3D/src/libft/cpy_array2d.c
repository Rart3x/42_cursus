/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_array2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:56:03 by jduval            #+#    #+#             */
/*   Updated: 2023/03/10 14:56:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**cpy_array2d(char **array)
{
	int		i;
	char	**cpy;

	i = 0;
	if (array == NULL)
		return (NULL);
	cpy = malloc (sizeof(char *) * (count_args2d(array) + 1));
	if (!cpy || !array)
		return (NULL);
	while (array[i])
	{
		cpy[i] = malloc(sizeof(char) * ft_strlen(array[i]) + 1);
		ft_strcpy(cpy[i], array[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
