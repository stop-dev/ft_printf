/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:57:05 by stopping          #+#    #+#             */
/*   Updated: 2020/11/04 20:35:20 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		n_len;

	i = 0;
	n_len = 0;
	while (*(needle + n_len++) != 0)
		;
	if (n_len == 1)
		return ((char *)haystack);
	n_len--;
	while (*(haystack + i) != 0 && (i < len))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			if ((i + j) > (len - 1))
				return (0);
			if (j == ((size_t)n_len - 1))
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
