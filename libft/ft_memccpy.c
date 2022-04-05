/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:42:28 by stopping          #+#    #+#             */
/*   Updated: 2020/11/15 16:19:31 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	while (n-- != 0)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
		{
			*(unsigned char *)d++ = *(unsigned char *)s;
			return (d);
		}
		*(char *)d++ = *(char *)s++;
	}
	return (0);
}
