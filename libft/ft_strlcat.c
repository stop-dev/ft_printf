/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:23:40 by stopping          #+#    #+#             */
/*   Updated: 2020/11/12 17:54:51 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	int		i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = -1;
	if (!src)
		return (0);
	if (d >= dstsize)
		return (s + dstsize);
	while (src[++i])
	{
		if ((d + (size_t)i) < (dstsize - 1))
			dst[d + i] = src[i];
		if (((int)d + i) == ((int)dstsize - 1))
			dst[d + i] = 0;
	}
	if (s < dstsize)
		dst[d + i] = 0;
	return (d + s);
}
