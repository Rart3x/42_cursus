/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:13:07 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/11 14:15:34 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_tab_size(char **parsed)
{
	int	i;

	i = 0;
	while (parsed[i])
		i++;
	return (i);
}

int	*to_parse(int argc, char **argv, t_parsed *a)
{
	int		i;
	int		j;
	int		size_parsed;
	char	**parsed;

	i = 1;
	while (i < argc)
	{
		parsed = ft_split(argv[i], 32);
		size_parsed = get_tab_size(parsed);
		if (a->tab == NULL)
			a->tab = ft_calloc(get_tab_size(parsed), sizeof(int));
		else
			a->tab = my_realloc_int_tab(a->tab, a->tab_size, size_parsed);
		j = 0;
		while (j < size_parsed)
		{
			a->tab[a->tab_size] = ft_atoi(parsed[j], parsed, a);
			a->tab_size++;
			j++;
		}
		i++;
		free_tab_tab(parsed);
	}
	return (a->tab);
}

int	main(int argc, char **argv)
{
	t_parsed		*a;
	t_parsed		*b;

	if (argc < 2)
		return (0);
	check_args(argv);
	a = malloc(sizeof(t_parsed));
	a->tab_size = 0;
	a->tab = NULL;
	a->tab = to_parse(argc, argv, a);
	b = malloc(sizeof(t_parsed));
	b->tab = ft_calloc(a->tab_size, sizeof(int) + 1);
	b->tab_size = 0;
	if (check_dupli_args(a) == 0)
		ft_error(a, b);
	if (check_order(a) == 0)
		ft_error_with_return(a, b);
	a->tab = normalise_int_tab(a);
	sort(a, b);
	free_structs(a, b);
	return (0);
}
