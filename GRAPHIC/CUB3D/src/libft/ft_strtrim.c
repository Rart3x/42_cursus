/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:43:53 by gazzopar          #+#    #+#             */
/*   Updated: 2023/08/17 14:51:55 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_set(char const s1, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1 == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set, int flag)
{
	size_t		start;
	size_t		end;
	char		*trim;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen_trim(s1) - 1;
	while (ft_set(s1[start], set) == 1)
			start++;
	while (ft_set(s1[end], set) == 1)
			end--;
	trim = ft_substr(s1, start, (end - start) + 1, 0);
	if (flag == 1)
		free(s1);
	return (trim);
}
