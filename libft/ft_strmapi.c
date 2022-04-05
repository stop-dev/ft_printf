/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:40:24 by stopping          #+#    #+#             */
/*   Updated: 2020/11/12 17:31:26 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	if (!s)
		return (0);
	if (!(s1 = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	i = -1;
	while (*(s + ++i))
		*(s1 + i) = f(i, *(s + i));
	*(s1 + i) = 0;
	return (s1);
}
