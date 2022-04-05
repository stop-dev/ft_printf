/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:33:42 by stopping          #+#    #+#             */
/*   Updated: 2020/11/07 18:38:21 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (*(s + ++i))
		if (*(s + i) == (char)c)
			j = i;
	if (j >= 0)
		return ((char *)s + j);
	if (!c)
		return ((char *)s + i);
	return (NULL);
}
