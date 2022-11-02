/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:34:43 by marvin            #+#    #+#             */
/*   Updated: 2022/11/01 05:34:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_ndigit(unsigned int n)
{
	unsigned int	temp;
	int	j;

	j = 1;
	temp = n;
	while (temp / 10 > 9)
	{
		temp = temp / 10;
		j++;
	}
	j++;
	if (temp / 10 == 0)
		j--;
	return (j);
}

static char	*ft_pnbr(char *ptr, unsigned int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_ndigit(n);
	k = j;
	while (n / 10 > 9)
	{
		ptr[j - 1] = n % 10 + '0';
		n = n / 10;
		j--;
	}
	ptr[j - 1] = n % 10 + '0';
	if (n / 10 != 0)
		ptr[j - 2] = n / 10 + '0';
	ptr[k] = '\0';
	return (ptr);
}

static char	*ft_znbr(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_putunsi(unsigned int n)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_ndigit(n);
	k = j;
	if (n == 0)
		ptr = (char *)malloc(2 * sizeof(char));
	else
		ptr = (char *)malloc((j + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (n == 0)
		ptr = ft_znbr(ptr);
	else
		ptr = ft_pnbr(ptr, n);
	return (ptr);
}
