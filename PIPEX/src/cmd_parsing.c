/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:22:08 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/31 13:22:21 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static void	cmd_null(t_pipex *pipex, char **cmd)
{
	if (cmd[0] == NULL)
	{
		free_close_child_one(pipex);
		exit(2);
	}
}

char	*find_cmd_one(t_pipex *pipex, char **cmd)
{
	int		i;
	int		accessed;
	char	*path_testing;
	char	*cmd_path;

	i = 0;
	cmd_null(pipex, cmd);
	cmd_path = ft_strjoin_free(ft_strdup("/"), cmd[0]);
	while (pipex->path[i])
	{
		path_testing = ft_strjoin(pipex->path[i], cmd_path);
		accessed = access(path_testing, X_OK);
		if (accessed == 0)
		{
			free(cmd_path);
			return (path_testing);
		}
		i++;
		free(path_testing);
	}
	free(cmd_path);
	free_close_child_one(pipex);
	exit(EXIT_FAILURE);
	return (NULL);
}

char	*find_cmd_two(t_pipex *pipex, char **cmd)
{
	int		i;
	int		accessed;
	char	*path_testing;
	char	*cmd_path;

	i = 0;
	cmd_null(pipex, cmd);
	cmd_path = ft_strjoin_free(ft_strdup("/"), cmd[0]);
	while (pipex->path[i])
	{
		path_testing = ft_strjoin(pipex->path[i], cmd_path);
		accessed = access(path_testing, X_OK);
		if (accessed == 0)
		{
			free(cmd_path);
			return (path_testing);
		}
		i++;
		free(path_testing);
	}
	free(cmd_path);
	free_close_child(pipex);
	exit(EXIT_FAILURE);
	return (NULL);
}
