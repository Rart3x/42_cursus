/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:28:22 by kramjatt          #+#    #+#             */
/*   Updated: 2022/09/30 22:25:27 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*value;
	int				length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	value = malloc(sizeof(char) * length + 1);
	if (value == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		value[i] = (*f)(i, s[i]);
		i++;
	}
	value[i] = '\0';
	return (value);
}
