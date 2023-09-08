/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:33:40 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/04 16:13:19 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	verif_nbr_args(int argc)
{
	if (argc != 2)
		return (false);
	return (true);
}

static bool	verif_file_extension(char *file)
{
	char	*substr;
	int		length;

	length = ft_strlen(file);
	substr = ft_substr(file, length - 4, length, 0);
	if (!ft_strncmp(substr, ".cub", ft_strlen(substr)))
	{
		free(substr);
		return (true);
	}
	free(substr);
	return (false);
}

void	verif_args(int argc, char **argv)
{
	if (verif_nbr_args(argc) == true)
	{
		if (verif_file_extension(argv[1]) == true)
			return ;
		else
			error_extension();
	}
	else
		error_nbr_args();
}
