/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:18:26 by marvin            #+#    #+#             */
/*   Updated: 2022/10/30 01:18:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

int     ft_printf(const char *format, ...);
char	*ft_putadd(unsigned long add);
char	*ft_putlhexa(int nb);
char	*ft_putuhexa(int nb);
char	*ft_putunsi(unsigned int n);

#endif