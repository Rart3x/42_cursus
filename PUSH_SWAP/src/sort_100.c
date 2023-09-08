/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:19:54 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/09 17:20:03 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_100_smart_rotate(t_parsed *a, int count)
{
	if (find_i(a, (a->tab_size - (a->tab_size - count)) > (a->tab_size / 2)))
		ra(a);
	else if (find_i(a, (a->tab_size - (a->tab_size - count))
			<= (a->tab_size / 2)))
		rra(a);
}

static int	algo_100_butterfly(t_parsed *a, t_parsed *b,
		int size_divided, int start)
{
	pb(a, b);
	if (b->tab[0] < (size_divided - start) / 2 + start)
		rb(b);
	return (1);
}

int	sort_until_100(t_parsed *a, t_parsed *b)
{
	int			start;
	int			count;
	int			size_divided;
	const int	max_size = a->tab_size;

	start = 0;
	size_divided = (max_size / 5);
	while (size_divided < max_size)
	{
		count = 1;
		while (count < (max_size / 5))
		{
			if (a->tab[0] <= size_divided)
				count += algo_100_butterfly(a, b, size_divided, start);
			else
				algo_100_smart_rotate(a, count);
		}
		size_divided += (max_size / 5);
		start += (max_size / 5);
	}
	while (a->tab_size != 0)
		pb(a, b);
	return (5);
}
