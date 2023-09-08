/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:13:13 by kramjatt          #+#    #+#             */
/*   Updated: 2022/10/05 11:26:11 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newchar;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((len + start) <= ft_strlen(s))
		newchar = ft_calloc(len + 1, sizeof(char));
	else if (start + len > ft_strlen(s) && start < ft_strlen(s))
		newchar = ft_calloc((ft_strlen(s) - start) + 1, sizeof(char));
	else
	{
		newchar = ft_calloc(1, sizeof(char));
		return (newchar);
	}
	if (newchar == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		newchar[i] = s[start];
		i++;
		start++;
	}
	return (newchar);
}
