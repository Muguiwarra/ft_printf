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

static void	ft_do(char	*s, int	**count)
{
	**count += ft_strlen(s);
	ft_putstr_fd(s, 1);
}

static void	ft_options(char	o, void *wut, int *count)
{
	if (o == 'c')
	{
		ft_putchar_fd((char) *wut, 1);
		*count = *count + 1;
	}
	else if (o == 's')
		ft_do((char *) wut, &count);
	else if (o == 'p')
		ft_do(ft_putadd((unsigned long) wut), &count);
	else if (o == 'd' || o == 'i')
		ft_do(ft_itoa((int) *wut), &count);
	else if (o == 'u')
		ft_do(ft_putunsi((unsigned long) wut), &count);
	else if (o == 'x')
		ft_do(ft_putlhexa((unsigned int) *wut), &count);
	else if (o == 'X')
		ft_do(ft_putuhexa((unsigned int) *wut), &count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
				i += 2;
				continue;
			}
			else if (format[i + 1] == 's' || format[i + 1] == 'p' || format[i + 1] == 'd' ||
					format[i + 1] == 'i' || format[i + 1] == 'u' || format[i + 1] == 'x' ||
					format[i + 1] == 'X' || format[i + 1] == 'c')
			{
				ft_options(format[i + 1], va_arg(args, void *), &count);
				i += 2;
				continue;
			}
		}
		count++;
		ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return(count);
}