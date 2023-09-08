/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:51:14 by arforgea          #+#    #+#             */
/*   Updated: 2022/09/04 20:13:32 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_proto(int argc, char **argv, int *count)
{
	int	error;

	if (argc != 2 && argc != 3)
		return (0);
	if (argc == 2)
		*count = 1;
	error = not_numeric_or_null(argv[*count]);
	if (error == 1)
		return (0);
	error = over_limit(argv[*count]);
	if (error == 1)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		size;
	int		count;
	char	*tab;
	char	*path;
	char	**final_tab;

	if (argc == 3)
	{
		size = ft_strlen(argv[1]);
		path = malloc (sizeof (char) * size);
		path = argv[1];
		count = 2;
	}
	if (ft_proto(argc, argv, &count) == 0)
		return (ft_error(0));
	size = 0;
	size = ft_strlen(argv[count]);
	tab = malloc (sizeof (char) * size);
	tab = ft_swap(argv[count], tab);
	final_tab = ft_read_file(path, argc);
	if (final_tab == NULL)
		return (ft_error(1));
	ft_convert(tab, final_tab);
	write (1, "\n", 1);
	return (0);
}
