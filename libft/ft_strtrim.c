/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:30:13 by stopping          #+#    #+#             */
/*   Updated: 2020/11/15 16:14:04 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	trim;
	size_t	len_s;
	size_t	len_set;

	if (!s1)
		return (0);
	if (!set)
	{
		s = ft_strdup(s1);
		return (s);
	}
	trim = 0;
	len_set = ft_strlen(set);
	len_s = ft_strlen(s1);
	while (ft_memchr(set, *(s1 + trim), len_set))
		trim++;
	if (trim < len_s)
		while (ft_memchr(set, *(s1 + len_s), len_set + 1))
			len_s--;
	s = ft_substr(s1, trim, len_s - trim + 1);
	return (s);
}
