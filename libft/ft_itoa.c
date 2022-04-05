/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:03:00 by stopping          #+#    #+#             */
/*   Updated: 2020/11/12 20:20:12 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numchar(int n)
{
	size_t	num;

	num = 0;
	while (n)
	{
		n /= 10;
		num++;
	}
	return (num);
}

static char		*ft_makestr(char *s, unsigned long int n_copy, size_t k)
{
	*(s + k) = 0;
	if (n_copy == 0)
		*s = '0';
	else
		while (n_copy > 0)
		{
			*(s + --k) = n_copy % 10 + '0';
			n_copy /= 10;
		}
	return (s);
}

char			*ft_itoa(int n)
{
	char				*s;
	size_t				k;
	unsigned long int	n_copy;

	k = 0;
	if (n <= 0)
	{
		n_copy = -1 * (n + 1);
		n_copy++;
		k++;
	}
	else
		n_copy = n;
	k += ft_numchar(n_copy);
	if (!(s = (char *)malloc(k + 1)))
		return (0);
	if (n < 0)
		*s = '-';
	return (ft_makestr(s, n_copy, k));
}
