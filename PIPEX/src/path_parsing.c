/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:18:51 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/29 01:44:37 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*remove_path(char *envp)
{
	char	*removed;
	int		i;
	int		j;

	i = 5;
	j = 0;
	removed = malloc(sizeof(char) * ft_strlen(envp) - 4);
	if (!removed)
		return (NULL);
	while (envp[i])
	{
		removed[j] = envp[i];
		i++;
		j++;
	}
	removed[j] = '\0';
	free(envp);
	return (removed);
}

char	**find_path(char **envp)
{
	int		i;
	char	**path_splited;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path_splited = ft_split(envp[i], ':');
	path_splited[0] = remove_path(path_splited[0]);
	return (path_splited);
}
