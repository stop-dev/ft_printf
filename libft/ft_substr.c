/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:11:39 by stopping          #+#    #+#             */
/*   Updated: 2020/11/12 19:20:15 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s)
		return (0);
	if (!(sub = (char *)malloc(len + 1)))
		return (0);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
