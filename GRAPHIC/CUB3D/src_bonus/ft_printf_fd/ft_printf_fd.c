/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <kramjatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:48:01 by kramjatt          #+#    #+#             */
/*   Updated: 2023/07/15 12:48:02 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

static int	ft_check_char(int fd, const char *format, int i)
{
	int	z;

	z = 0;
	if (format[i] != '%')
	{
		if (format[i - 1] != '%')
			z += ft_putchar_pf(fd, format[i]);
		else if (format[i - 1] == '%')
		{
			if (format[i - 2] == '%')
				z += ft_putchar_pf(fd, format[i]);
		}
	}
	return (z);
}

static int	ft_check_print_nbr(int fd, va_list list, int type)
{
	unsigned long	verif;
	int				i;

	i = 0;
	if (type == 'p')
	{
		verif = va_arg(list, unsigned long);
		if (verif != 0)
		{
			i += ft_putstr_pf(fd, "0x");
			i += ft_putnbr_base(fd, verif, "0123456789abcdef");
		}
		else
			i += ft_putstr_pf(fd, "(nil)");
	}
	else if (type == 'd' || type == 'i')
		i += ft_putnbr_pf(fd, va_arg(list, int));
	else if (type == 'u')
		i += ft_put_unsigned_nbr(fd, va_arg(list, unsigned int));
	else if (type == 'x')
		i += ft_putnbr_base(fd, va_arg(list, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		i += ft_putnbr_base(fd, va_arg(list, unsigned int), "0123456789ABCDEF");
	return (i);
}

static int	ft_check_print(int fd, va_list list, int type)
{
	int				i;

	i = 0;
	if (type == 'c')
		i += ft_putchar_pf(fd, va_arg(list, int));
	else if (type == 's')
		i += ft_putstr_pf(fd, va_arg(list, char *));
	else if (type == 'p' || type == 'd' || type == 'i'
		|| type == 'u' || type == 'x' || type == 'X')
		i += ft_check_print_nbr(fd, list, type);
	else if (type == '%')
		i += ft_putchar_pf(fd, '%');
	return (i);
}

static int	ft_find_print(int fd, const char *format, va_list list)
{
	int	type;
	int	i;
	int	count;

	count = 0;
	i = 0;
	type = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			type = format[i + 1];
			count += ft_check_print(fd, list, type);
			i++;
		}
		else
		{
			count += ft_check_char(fd, format, i);
		}
		i++;
	}
	return (count);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	list;
	int		cpt;

	cpt = 0;
	va_start(list, format);
	cpt += ft_find_print(fd, format, list);
	va_end(list);
	return (cpt);
}
