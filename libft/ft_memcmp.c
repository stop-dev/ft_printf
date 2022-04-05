/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:10:25 by stopping          #+#    #+#             */
/*   Updated: 2020/11/04 19:32:14 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- != 0)
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return ((int)(*(unsigned char *)--s1 - *(unsigned char *)--s2));
	return (0);
}
