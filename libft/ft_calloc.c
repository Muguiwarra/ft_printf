/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:43:25 by nabboune          #+#    #+#             */
/*   Updated: 2022/10/23 23:17:51 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	if (size * count == 0)
		return (malloc(0));
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (*(unsigned char *)(ptr + i))
		ft_bzero(ptr, count * size);
	return (ptr);
}
