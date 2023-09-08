/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_linux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:14:26 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/11 14:52:18 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_LINUX_H
# define CHECKER_LINUX_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_parsed
{
	int	tab_size;
	int	*tab;
}t_parsed;
/*---------------------------CHECKER_LINUX----------------------------*/
char	*get_next_line(int fd);
int		ft_strrchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	check_instructions(t_parsed *a, t_parsed *b);
/*------------------------Structs-----------------------------*/
/*-------------------------Exceptions----------------------------*/
void	check_args(char **argv);
int		check_dupli_args(t_parsed *a);
int		check_order(t_parsed *a);
/*------------------------Errors----------------------------*/
void	ft_check_error(char **parsed);
void	ft_error(t_parsed *a, t_parsed *b);
void	ft_error_without_free(void);
void	ft_error_with_return(t_parsed *a, t_parsed *b);
/*-------------------------Parsing----------------------------*/
int		*to_parse(int argc, char **argv, t_parsed *a);
int		*ft_sort_int_tab(int	*tab, int size);
int		*normalise_int_tab(t_parsed *a);
void	print_stack(int *tab, int tab_size);

/*---------------------Alloc functions-------------------------*/
int		*my_realloc_int_tab(int *to_realloc, int original_size,
			int additionnal_size);
/*---------------------Free functions-------------------------*/
void	free_tab_tab(char **tab);
void	free_structs(t_parsed *a, t_parsed *b);
/*---------------------Stack movements functions--------------*/
void	sa(t_parsed *a);
void	sb(t_parsed *b);
void	ss(t_parsed *a, t_parsed *b);
void	pa(t_parsed *a, t_parsed *b);
void	pb(t_parsed *a, t_parsed *b);
void	rra(t_parsed *a);
void	rrb(t_parsed *b);
void	rrr(t_parsed *a, t_parsed *b);
void	ra(t_parsed *a);
void	rb(t_parsed *b);
void	rr(t_parsed *a, t_parsed *b);
/*-----------------------------------LIBFT-----------------------------------*/
/*--------------Char------------------*/
char	**ft_split(char const *s, char c);
/*--------------Int------------------*/
int		ft_atoi(const char *str, char **parsed, t_parsed *a);
size_t	ft_strlen(const char *s);
int		*ft_strcpy_int_tab(int *dest, int *to_copy, int size);
/*--------------Void------------------*/
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif
