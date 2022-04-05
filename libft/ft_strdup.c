/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:35:32 by stopping          #+#    #+#             */
/*   Updated: 2020/11/10 15:51:04 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s;

	s = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (0 == s)
		return (0);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}
