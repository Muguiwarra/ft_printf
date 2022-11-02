/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:37:30 by marvin            #+#    #+#             */
/*   Updated: 2022/10/30 01:37:30 by marvin           ###   ########.fr       */
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

static void ft_divmod(unsigned long nb, unsigned long *div, unsigned long *mod)
{
    if (nb < 0)
	{
		*mod = -nb % 16;
        *div = -nb / 16;
	}
	else
	{
		*mod = nb % 16;
        *div = nb / 16;
	}
}

static char *ft_allocation(unsigned long nb, char *ptr)
{
    int i;
    unsigned long div;
	unsigned long mod;

    i = 1;
    ft_divmod(nb, &div, &mod);
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

static char	*ft_hexa(unsigned long nb)
{
	char			*lh;
	char			*conv;
	int				i;
	unsigned long	div;
	unsigned long	mod;

	lh = "0123456789abcdef";
	conv = ft_allocation(nb, conv);
	ft_divmod(nb, &div, &mod);
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

char	*ft_putadd(unsigned long add)
{
	char	*s1;
	char	*s2;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	s1 = ft_hexa(add);
	l = ft_strlen(s1) + 3;
	s2 = (char *) malloc(l * sizeof(char));
	s2[i++] = '0';
	s2[i++] = 'x';
	while (i < l)
		s2[i++] = s1[j++];
	return (s2);
}