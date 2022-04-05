/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:15:27 by stopping          #+#    #+#             */
/*   Updated: 2020/11/13 21:51:35 by stopping         ###   ########.fr       */
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

static void		ft_result(int n, size_t long_str, int fd)
{
	char	s[long_str + 1];
	int		i;

	i = 1;
	s[long_str] = 0;
	while (n)
	{
		s[long_str - i++] = n % 10 + '0';
		n /= 10;
	}
	ft_putstr_fd(s, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (!n)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_result(n, ft_numchar(n), fd);
}
