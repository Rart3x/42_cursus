/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:47:11 by kramjatt          #+#    #+#             */
/*   Updated: 2023/01/24 17:06:07 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen_pf(const char *s);
int		ft_putchar_pf(int c);
int		ft_putstr_pf(char *s);
int		ft_putnbr_pf(int n);
int		ft_put_unsigned_nbr(unsigned int n);
int		ft_putnbr_base(long n, char *base);
char	*ft_strrchr_pf(const char *s, int c);

#endif
