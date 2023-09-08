/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:11:46 by kramjatt          #+#    #+#             */
/*   Updated: 2022/10/01 03:10:39 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_on_set(char s1_char, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1_char)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_verif_start(char const *s1, char const *set)
{
	int	cpt_start;
	int	i;

	cpt_start = 0;
	i = 0;
	while (s1[i] != '\0' && ft_is_on_set(s1[i], set) == 1)
	{
		cpt_start++;
		i++;
	}
	return (cpt_start);
}

static int	ft_verif_end(char const *s1, char const *set)
{
	int	cpt_end;
	int	i;

	cpt_end = 0;
	i = ft_strlen(s1) - 1;
	while (i > 0 && (ft_is_on_set(s1[i], set) == 1))
	{
		cpt_end++;
		i--;
	}
	return (cpt_end);
}

static char	*ft_strcpy(char const *s1, char *value,
		int cpt_start, int cpt_end)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(s1);
	while (cpt_start < (length - cpt_end))
	{
		value[i] = s1[cpt_start];
		cpt_start++;
		i++;
	}
	value[i] = '\0';
	return (value);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		length;
	int		cpt_start;
	int		cpt_end;
	char	*value;

	if (s1 == NULL || set == NULL)
		return (NULL);
	cpt_start = ft_verif_start(s1, set);
	cpt_end = ft_verif_end(s1, set);
	length = ft_strlen(s1);
	if (cpt_start == length)
		value = malloc(sizeof(char));
	else
		value = malloc(sizeof(char) * (length - (cpt_start + cpt_end) + 1));
	if (value == NULL)
		return (NULL);
	value = ft_strcpy(s1, value, cpt_start, cpt_end);
	return (value);
}
