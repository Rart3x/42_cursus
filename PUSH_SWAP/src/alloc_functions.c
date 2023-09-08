/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:19:23 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/19 16:50:29 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_init_structs(t_parsed *a, t_parsed *b)
{
	a = malloc(sizeof(t_parsed));
	b = malloc(sizeof(t_parsed));
	a->tab_size = 0;
	b->tab_size = 0;
}

int	*my_realloc_int_tab(int *to_realloc, int original_size,
		int additionnal_size)
{
	int	*tmp;

	tmp = malloc((original_size + additionnal_size) * sizeof(int) + 1);
	memcpy(tmp, to_realloc, original_size * sizeof(int));
	if (to_realloc)
		free(to_realloc);
	return (tmp);
}
