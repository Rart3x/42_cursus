/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:31:24 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/10 14:16:31 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*caster;

	caster = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		caster[i] = 0;
		i++;
	}
}
