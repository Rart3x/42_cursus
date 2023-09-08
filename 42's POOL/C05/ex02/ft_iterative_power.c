/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:46:06 by kramjatt          #+#    #+#             */
/*   Updated: 2022/08/29 21:46:07 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	stock;

	i = 2;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	stock = nb;
	while (power > 1 && i <= power)
	{
		nb *= stock;
		i++;
	}
	return (nb);
}
