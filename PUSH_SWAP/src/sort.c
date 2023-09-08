/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:04:12 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/19 17:51:22 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_parsed *a, t_parsed *b)
{
	int	divider;

	divider = 0;
	if (a->tab_size == 2)
		sort_2(a);
	else if (a->tab_size == 3)
		sort_3(a);
	else if (a->tab_size == 4)
		sort_4(a, b);
	else if (a->tab_size == 5)
		sort_5(a, b);
	else if (a->tab_size <= 100)
	{
		divider = sort_until_100(a, b);
		return (divider);
	}
	else if (a->tab_size <= 500)
	{
		divider = sort_until_500(a, b);
		return (divider);
	}
	return (0);
}

int	find_i(t_parsed *stack, int to_find)
{
	int	i;

	i = 0;
	while (i < stack->tab_size)
	{
		if (stack->tab[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

static void	sort_smart_rotate(t_parsed *a, t_parsed *b, int max_size, int i)
{			
	if (a->tab_size == 0)
		pa(a, b);
	else if (b->tab[0] > a->tab[a->tab_size - 1]
		|| a->tab[a->tab_size - 1] == max_size)
	{
		pa(a, b);
		ra(a);
	}
	else if (find_i(b, i) <= b->tab_size / 2)
		rb(b);
	else
		rrb(b);
}

static int	sort_push_a(t_parsed *a, t_parsed *b)
{
	pa(a, b);
	return (1);
}

void	sort(t_parsed *a, t_parsed *b)
{
	int			i;
	int			divider;
	int			max_size;

	divider = check_sort(a, b);
	if (divider == 0)
		return ;
	max_size = b->tab_size;
	i = max_size;
	while (i > 0)
	{
		if (find_i(b, i) != -1)
		{
			if (b->tab[0] == i)
				i -= sort_push_a(a, b);
			else
				sort_smart_rotate(a, b, max_size, i);
		}
		else
		{
			rra(a);
			i--;
		}
	}
}
