/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:59:22 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/11 12:59:44 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"
#include <stdio.h>

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	dif;

	dif = 0;
	i = 0;
	while (dif == 0)
	{
		dif = s1[i] - s2[i];
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (dif);
}

static void	what_instructions(t_parsed *a, t_parsed *b, char *instruction)
{
	if (ft_strcmp(instruction, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruction, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(a, b);
	else
		ft_error(a, b);
}

void	check_instructions(t_parsed *a, t_parsed *b)
{
	char	*instructions;
	int		i;

	i = 0;
	instructions = get_next_line(0);
	while (instructions != NULL)
	{
		what_instructions(a, b, instructions);
		free(instructions);
		instructions = get_next_line(0);
	}
	while (i < a->tab_size - 1)
	{
		if (a->tab[i] < a->tab[i + 1] && b->tab_size == 0)
			i++;
		else
			ft_error(a, b);
	}
}
