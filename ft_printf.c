/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:17:41 by marvin            #+#    #+#             */
/*   Updated: 2022/10/30 01:17:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;

	va_start(args, format);
	i = 0;
	while(format[i])
	{
		if (format[i] == '%' && (format[i + 1] == '%' || format[i + 1] == 'c' ||
			format[i + 1] == 's' || format[i + 1] == 'p' || format[i + 1] == 'd' || 
			format[i + 1] == 'i' || format[i + 1] == 'u' || format[i + 1] == 'x' || 
			format[i + 1] == 'X'))
		{
			if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, char), 1);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'p')
			{
				ft_putstr_fd(ft_putadd(va_arg(args, unsigned long)), 1);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				ft_putnbr_fd(va_arg(args, int), 1);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'u')
			{
				ft_putstr_fd(ft_putunsi(va_arg(args, unsigned long)), 1);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'x')
			{
				ft_putstr_fd(ft_putlhexa(va_arg(args, unsigned int)), 1);
				i += 2;
				continue;
			}
			else if (format[i + 1] == 'X')
			{
				ft_putstr_fd(ft_putuhexa(va_arg(args, unsigned int)), 1);
				i += 2;
				continue;
			}
		}
		ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return(i);
}