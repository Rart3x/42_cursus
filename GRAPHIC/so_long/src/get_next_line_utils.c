/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:29:21 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 15:20:06 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strrchr(const char *s, int c)
{
	int			i;
	int			cpt;
	char		*point;

	cpt = -1;
	point = (char *)s;
	i = (int)ft_strlen(point) - 1;
	if (c == '\0')
		return (cpt);
	while (i >= 0)
	{
		if (point[i] == (unsigned char)c)
			cpt++;
		i--;
	}
	return (cpt);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*swap;

	swap = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		swap[i] = c;
		i++;
	}
	return (swap);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;

	if (size == 0 || nmemb == 0)
	{
		memory = malloc(1);
		return (memory);
	}
	if (nmemb * size == 0 || ((nmemb * size) / size != nmemb))
		return (NULL);
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, nmemb * size);
	return (memory);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
	if (s2 == NULL)
		return (NULL);
	value = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (value == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		value[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		value[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (value);
}
