/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:31:02 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/31 13:30:51 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pipex, char **envp, int status)
{
	if (pipex->pid[0] == -1)
		exit(2);
	else if (pipex->pid[0] == 0)
	{
		if (access(pipex->infile_cmd[0], X_OK) == 0)
			pipex->valid_path = ft_strjoin("", pipex->infile_cmd[0]);
		else
			pipex->valid_path = find_cmd_one(pipex, pipex->infile_cmd);
		dup2(pipex->infile, 0);
		dup2(pipex->pipefd[1], 1);
		close_all(pipex, pipex->infile);
		execve(pipex->valid_path, pipex->infile_cmd, envp);
		free(pipex->valid_path);
		perror(0);
		exit(2);
	}
}

void	second_child(t_pipex *pipex, char **envp, int status)
{
	if (pipex->pid[1] == -1)
		exit(2);
	else if (pipex->pid[1] == 0)
	{
		if (access(pipex->outfile_cmd[0], X_OK) == 0)
			pipex->valid_path = ft_strjoin("", pipex->outfile_cmd[0]);
		else
			pipex->valid_path = find_cmd_two(pipex, pipex->outfile_cmd);
		dup2(pipex->pipefd[0], 0);
		dup2(pipex->outfile, 1);
		close_all(pipex, pipex->outfile);
		execve(pipex->valid_path, pipex->outfile_cmd, envp);
		free(pipex->valid_path);
		perror(0);
		exit(2);
	}
}
