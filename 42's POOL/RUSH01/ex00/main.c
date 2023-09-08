/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:38:51 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/28 17:29:43 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		rush(char **tab_base);

char	**ft_put(char *str, char **tab);

int		ft_count(char *c);

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_malloc(void)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc (sizeof(char *) * 4);
	while (i < 4)
	{
		tab[i] = malloc (sizeof(char) * 4);
		if (tab[i] == NULL)
			write (1, "Echec de l'allocation", 22);
		i++;
	}
	if (tab == NULL)
		write (1, "Echec de l'allocation", 22);
	return (tab);
}

int	main(int argc, char *argv[])
{
	int		count;
	char	**tab;

	tab = ft_malloc();
	if (argc != 2)
	{
		write (1, "prend 1 paramètre", 19);
		return (0);
	}
	count = ft_count(argv[1]);
	if (count != 31)
	{
		write (1, "Rentrer 16 valeurs avec un espace entre", 39);
		return (0);
	}
	tab = ft_put(argv[1], tab);
	rush(tab);
	ft_free(tab);
}

char	**ft_put(char *str, char **tab)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (i < 4)
	{
		while (i2 < 4)
		{
			tab[i][i2] = str[(i * 4 + i2) * 2];
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (tab);
}

int	ft_count(char *c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (c[i] != '\0')
	{
		if ((c[i] >= '1' && c[i] <= '4') || c[i] == 32)
			count++;
		else
			return (0);
		i++;
	}
	return (count);
}
