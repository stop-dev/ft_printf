/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:44:17 by stopping          #+#    #+#             */
/*   Updated: 2020/11/07 18:40:17 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	size;
	int	i;

	size = -1;
	i = 0;
	if (src == 0)
		return (0);
	while (*(src + ++size))
		if ((size_t)i < (dstsize - 1) && dstsize)
		{
			*(dst + i) = *(src + i);
			i++;
		}
	if (dstsize)
		*(dst + i) = 0;
	return ((size_t)size);
}
