/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:34:10 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/28 19:36:51 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*tab_line(char pnt, int nxt);

char	**ft_malloc(void);

void	ft_free(char **tab);

int	verif_see(char tab[], int up, int down)
{
	int	see1;
	int	see2;
	int	i;
	int	i2;

	see1 = 0;
	see2 = 0;
	i = 0;
	i2 = 0;
	while (i <= 3)
	{
		if (tab[i] > tab[i2])
		{
			i2 = i;
			see1++;
		}
		i++;
	}
	i2 = 3;
	i = 3;
	while (i >= 0)
	{
		if (tab[i] > tab[i2])
		{
			i2 = i;
			see2++;
		}
		i--;
	}
	if (see1 == up && see2 == down)
		return (1);
	return (0);
}

int	verif_same(char tab[])
{
	int	i;
	int	i2;

	i = 0;
	i2 = 1;
	while (i <= 2)
	{
		while (i2 <= 3)
		{
			if (tab[i] == tab[i2])
				return (0);
			i2++;
		}
		i++;
		i2 = i + 1;
	}
	return (1);
}

void	impr(char **tab_to_print)
{
	int	i;
	int	i2;

	while (i < 4)
	{
		while (i2 < 4)
		{
			write(1, &tab_to_print[i][i2], 1);
			i2++;
		}
		i2 = 0;
		i++;
		write(1, "\n", 1);
	}
}

void	rush(char **tab_base)
{
	int		i;
	int		i1;
	int		i2;
	int		i3;
	int		i4;
	char	**tab_impr;

	tab_impr = ft_malloc();
	i = 0;
	i1 = 0;
	i2 = 0;
	i3 = 0;
	i4 = 0;
	while (i < 11)
	{
		tab_impr[0] = tab_line(tab_base[2][0], i);
		while (i1 < 1)
		{
			tab_impr[1] = tab_line(tab_base[2][1], i1);
			while (i2 < 11)
			{
				tab_impr[2] = tab_line(tab_base[2][2], i2);
				while (i3 < 11)
				{
					tab_impr[3] = tab_line(tab_base[2][3], i3);
					while (i4 < 4)
					{
						if (verif_see(tab_impr[i4], (tab_base[0][i4] - 48), (tab_base[1][i4] - 48)) == 1 && verif_same(tab_impr[i4]) == 1)
						{
							if (i4 == 3)
							{
								impr(tab_impr);
								ft_free(tab_impr);
								return ;
							}
						}
						else
							i4 = 6;
						i4++;
					}
					i4 = 0;
					i3++;
				}
				i3 = 0;
				i2++;
			}
			i1++;
			i2 = 0;
		}
		i++;
		i1 = 0;
	}
	write(1, "No posibility", 13);
	ft_free(tab_impr);
}
