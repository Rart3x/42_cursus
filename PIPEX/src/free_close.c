/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:56:27 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/31 13:20:57 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_close_child_one(t_pipex *pipex)
{
	free_tab_tab(pipex->infile_cmd);
	free_tab_tab(pipex->outfile_cmd);
	free_tab_tab(pipex->path);
	if (pipex->pipefd[0] > 2)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] > 2)
		close(pipex->pipefd[1]);
	if (pipex->infile > 2)
		close(pipex->infile);
}

void	free_close_child(t_pipex *pipex)
{
	free_tab_tab(pipex->infile_cmd);
	free_tab_tab(pipex->outfile_cmd);
	free_tab_tab(pipex->path);
	if (pipex->pipefd[0] > 2)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] > 2)
		close(pipex->pipefd[1]);
	if (pipex->infile > 2)
		close(pipex->infile);
	if (pipex->outfile > 2)
		close(pipex->outfile);
}

void	free_all(t_pipex *pipex)
{
	if (pipex->pipefd[0] > 2)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] > 2)
		close(pipex->pipefd[1]);
	free_tab_tab(pipex->infile_cmd);
	free_tab_tab(pipex->outfile_cmd);
	free_tab_tab(pipex->path);
}

void	close_all(t_pipex *pipex, int file)
{
	if (file > 2)
		close(file);
	if (pipex->pipefd[0] > 2)
		close(pipex->pipefd[0]);
	if (pipex->pipefd[1] > 2)
		close(pipex->pipefd[1]);
}
