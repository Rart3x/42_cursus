/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:36:00 by arforgea          #+#    #+#             */
/*   Updated: 2022/09/04 18:56:06 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_nb_line(char *str)
{
	int	i;
	int	nb_line;

	i = -1;
	nb_line = 0;
	while (str[++i] != '\0')
		if (str[i] == '\n')
			nb_line++;
	return (nb_line);
}

char	**init_tab(char *buff)
{
	int		i;
	int		j;
	int		nb_line;
	int		nb_char;
	char	**final_tab;

	i = -1;
	j = -1;
	nb_line = ft_nb_line(buff);
	nb_char = 0;
	final_tab = malloc(sizeof(char *) * nb_line);
	i = -1;
	while (buff[++i] != '\0')
	{
		if (buff[i] >= 97 && buff[i] <= 122)
			while (buff[++i] != '\n')
				nb_char++;
		final_tab[++j] = malloc(sizeof(char) * nb_char);
		nb_char = 0;
	}
	final_tab[nb_line] = malloc(sizeof(char));
	final_tab[nb_line][0] = 3;
	return (final_tab);
}

void	set_tab(char **tab, char *buff)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	j = 0;
	w = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] >= 97 && buff[i] <= 122)
		{
			while (buff[i] != '\n')
			{
				tab[j][w] = buff[i];
				w++;
				i++;
			}
			tab[j][w] = '\0';
			w = 0;
			j++;
		}
		i++;
	}
}

char	**ft_read_file(char *path, int argc)
{
	int			fd;
	int			rd;
	char		buff[10000];
	char		**final_tab;

	rd = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1 && argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if (fd == -1 && argc == 3)
		return (NULL);
	if (fd != -1)
	{
		rd = read(fd, buff, 10000);
		buff[rd] = '\0';
		final_tab = init_tab(buff);
		set_tab(final_tab, buff);
		close(fd);
	}
	return (final_tab);
}
