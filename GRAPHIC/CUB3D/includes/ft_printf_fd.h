/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:33:49 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/15 12:34:40 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf_fd(int fd, const char *format, ...);
size_t	ft_strlen_pf(const char *s);
int		ft_putchar_pf(int fd, int c);
int		ft_putstr_pf(int fd, char *s);
int		ft_putnbr_pf(int fd, int n);
int		ft_put_unsigned_nbr(int fd, unsigned int n);
int		ft_putnbr_base(int fd, long n, char *base);
char	*ft_strrchr_pf(const char *s, int c);

#endif
