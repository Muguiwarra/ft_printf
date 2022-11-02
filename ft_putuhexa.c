/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:37:10 by marvin            #+#    #+#             */
/*   Updated: 2022/10/30 02:37:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_putuhexa(unsigned int nb)
{
	char			*conv;
	int		i;

	i = 0;
	conv = ft_putlhexa(nb);
	while (conv[i])
		conv[i++] = ft_toupper(conv[i]);
	return (conv);
}