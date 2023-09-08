/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:48:09 by kramjatt          #+#    #+#             */
/*   Updated: 2023/08/17 14:52:04 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf_fd.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*--------------Array2D_f-------------*/
char	**cpy_array2d(char **array);
int		count_args2d(char **array);
void	free_array2d(char **array);
void	print_array2d(char **array);

/*--------------Memory_f-------------*/
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);	
/*-----	-----Str_f----------------*/
void	ft_strcpy(char *dst, const char *src);
int		ft_strlen(char *s);
int		ft_strlen_trim(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char *s1, char const *set, int flag);
char	*ft_substr(char *s, int start, int len, int flag);	
void	ft_putstr_fd(int fd, char *s);
char	**ft_split(char const *s, char c);	
int		ft_atoi(const char *str);

#endif
