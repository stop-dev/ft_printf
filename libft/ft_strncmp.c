/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:31:04 by stopping          #+#    #+#             */
/*   Updated: 2020/11/06 16:18:15 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- != 0 && (*(unsigned char *)s1 || *(unsigned char *)s2))
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
		{
			if (((unsigned char)*--s1 - (unsigned char)*--s2) > 0)
				return (1);
			else
				return (-1);
		}
	return (0);
}
