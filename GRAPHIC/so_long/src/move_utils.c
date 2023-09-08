/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:51:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/17 17:21:29 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*move_count(int movements)
{
	char	*move_count;
	char	*move;

	move = ft_itoa(movements);
	move_count = ft_strjoin("Movement number : ", move);
	free(move);
	return (move_count);
}

void	move_print(t_vars *struc)
{
	char	*moves;

	moves = move_count(struc->movements);
	mlx_string_put(struc->mlx, struc->win, 32, 32, 0x000000,
		moves);
	struc->movements++;
	free(moves);
	moves = move_count(struc->movements);
	ft_printf("Movement number : %d\n", struc->movements);
	mlx_string_put(struc->mlx, struc->win, 32, 32, 0xFFFFFF,
		moves);
	free(moves);
}
