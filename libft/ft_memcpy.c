/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:46:18 by stopping          #+#    #+#             */
/*   Updated: 2020/11/05 19:53:51 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL && d == NULL && n)
		n = 0;
	while (i < n)
		*(unsigned char *)(d + i++) = *(unsigned char *)s++;
	return ((void *)d);
}
