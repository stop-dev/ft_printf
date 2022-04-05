/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:24:01 by stopping          #+#    #+#             */
/*   Updated: 2020/11/04 19:32:25 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (c < 0 || c > 255)
		return (c);
	if (a >= 'a' && a <= 'z')
		a -= ('a' - 'A');
	return ((int)a);
}
