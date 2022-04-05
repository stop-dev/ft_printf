/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:47:04 by stopping          #+#    #+#             */
/*   Updated: 2020/11/04 19:32:24 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (c < 0 || c > 255)
		return (c);
	if (a >= 'A' && a <= 'Z')
		a += ('a' - 'A');
	return ((int)a);
}
