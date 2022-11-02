/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:43:41 by nabboune          #+#    #+#             */
/*   Updated: 2022/10/26 00:05:00 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;
	size_t	j;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= dlen)
		return (dstsize + slen);
	i = 0;
	j = dlen;
	while (src[i] && i < dstsize - dlen - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
