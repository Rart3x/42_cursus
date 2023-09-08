/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:46:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/31 13:02:10 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid[2];
	char	**path;
	char	*valid_path;
	char	**infile_cmd;
	char	**outfile_cmd;
	int		infile;
	int		outfile;
	int		pipefd[2];

}t_pipex;
/*----------Errors---------*/
void	error_infile(void);
void	error_outfile(void);
/*----------Children---------*/
void	first_child(t_pipex *pipex, char **envp, int status);
void	second_child(t_pipex *pipex, char **envp, int status);
/*----------Free & Close---------*/
void	free_tab_tab(char **tab);
void	free_all(t_pipex *pipex);
void	free_no_path(t_pipex *pipex);
void	free_close_child(t_pipex *pipex);
void	free_close_child_one(t_pipex *pipex);
void	close_all(t_pipex *pipex, int file);
/*----------Parsing---------*/
char	**find_path(char **envp);
char	*find_cmd_one(t_pipex *pipex, char **cmd);
char	*find_cmd_two(t_pipex *pipex, char **cmd);
#endif
