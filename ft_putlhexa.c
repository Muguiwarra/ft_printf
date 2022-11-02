/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:50:25 by marvin            #+#    #+#             */
/*   Updated: 2022/10/30 01:50:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_reverse(char *str)
{
	char	*ptr;
	int		slen;
	int		i;

	slen = ft_strlen(str);
	ptr = (char *) malloc(slen + 1);
	i = 0;
	while (slen > 0)
	{
		ptr[i] = str[slen - 1];
		i++;
		slen--;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int ft_div(unsigned int nb)
{
    unsigned int div;

    if (nb < 0)
        div = -nb / 16;
    else
        div = nb / 16;
    return (div);
}

static char *ft_allocation(unsigned int nb, char *ptr)
{
    int i;
    unsigned int div;

    i = 1;
    div = ft_div(nb);
	while (div > 0)
	{
		i++;
		div = div / 16;
	}
    ptr = (char *) malloc(i + 1);
	if (!ptr)
		return (0);
    return (ptr);
}

static int ft_mod(unsigned int nb)
{
    unsigned int mod;

    if (nb < 0)
        mod = -nb % 16;
    else
        mod = nb % 16;
    return (mod);
}

char	*ft_putlhexa(unsigned int nb)
{
	char			*lh;
	char			*conv;
	int				i;
	unsigned int	div;
	unsigned int	mod;

	lh = "0123456789abcdef";
	conv = ft_allocation(nb, conv);
	div = ft_div(nb);
    mod = ft_mod(nb);
    i = 0;
	while(div > 0)
	{
		conv[i++] = lh[mod];
		mod = div % 16;
		div = div / 16;
	}
	conv[i++] = lh[mod];
    if (nb < 0)
	    conv[i++] = '-';
	conv[i] = '\0';
	conv = ft_reverse(conv);
	return (conv);
}