/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:04:07 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/19 22:15:56 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	stock;

	start = 0;
	end = size - 1;
	stock = 0;
	while (start < end)
	{
		stock = tab[start];
		tab[start] = tab[end];
		tab[end] = stock;
		start++;
		end--;
	}
}
