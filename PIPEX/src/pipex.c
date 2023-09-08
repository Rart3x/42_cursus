/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:26:31 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/31 13:03:35 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <string.h>

static int	verif_args(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		return (2);
	else
		close(pipex->infile);
	return (0);
}

static void	stock_args(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		perror(0);
	pipex->infile_cmd = ft_split(argv[2], ' ');
	pipex->outfile_cmd = ft_split(argv[3], ' ');
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;
	int		nb_children;

	status = 0;
	nb_children = verif_args(&pipex, argv);
	stock_args(&pipex, argv);
	pipe(pipex.pipefd);
	pipex.path = find_path(envp);
	pipex.pid[0] = fork();
	if (nb_children != 2)
		first_child(&pipex, envp, status);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex.outfile == -1)
		perror(0);
	if (pipex.pipefd[1] > 2)
		close(pipex.pipefd[1]);
	if (pipex.infile > 2)
		close(pipex.infile);
	pipex.pid[1] = fork();
	second_child(&pipex, envp, status);
	if (pipex.outfile > 2)
		close(pipex.outfile);
	waitpid(pipex.pid[0], &status, 0);
	waitpid(pipex.pid[1], &status, 0);
	free_all(&pipex);
	return (status);
}
