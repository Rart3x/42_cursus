/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:13:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/04 17:13:50 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char *s, int start, int len, int flag)
{
	char	*newchar;
	int		i;

	i = -1;
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
	while (s[start] != '\0' && ++i < len)
	{
		newchar[i] = s[start];
		start++;
	}
	if (flag)
		free(s);
	return (newchar);
}
