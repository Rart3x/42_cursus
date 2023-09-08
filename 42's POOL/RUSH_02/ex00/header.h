/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:24:36 by kramjatt          #+#    #+#             */
/*   Updated: 2022/09/04 20:13:10 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		not_numeric_or_null(char *str);
int		over_limit(char *str);
int		not_numeric_or_null(char *str);
int		over_limit(char *str);
int		ft_strlen(char *str);
int		ft_error(int nb);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_nb_line(char *str);
int		dict_lines(char **tab);
char	*ft_swap(char *str, char *tab);
char	*ft_malloc(int size);
char	**ft_read_file(char *path, int argc);
void	ft_putstr(char *str, int *begin);
void	ft_strncpy(char *dest, char *src, int *n);
void	ft_convert(char *str, char **tab);

#endif
