/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:18:55 by nabboune          #+#    #+#             */
/*   Updated: 2022/11/10 02:18:50 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_putadd(unsigned long add);
char	*ft_putlhexa(unsigned int nb);
char	*ft_putuhexa(unsigned int nb);
char	*ft_putunsi(unsigned int n);

#endif
