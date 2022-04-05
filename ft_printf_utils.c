/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:47:09 by stopping          #+#    #+#             */
/*   Updated: 2021/01/07 19:23:32 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int		putstr_chr(char c, int k)
{
	int num;

	num = 0;
	while (k-- > 0)
		num += ft_putchr(c);
	return (num);
}

int		putstr(char *s, int begin, int slong)
{
	int num;
	int	i;

	num = 0;
	i = 0;
	while (i < slong)
		num += ft_putchr(s[begin + i++]);
	return (num);
}

int		strdiu(long int i, int last, char s[last], t_format *lst)
{
	int		i_size;

	i_size = 1;
	if (i < 0)
		i = -i;
	if (i == 0 && lst->pre == 0)
		return (0);
	s[last - 1] = i % 10 + '0';
	while ((i /= 10) > 0)
		s[last - 1 - i_size++] = i % 10 + '0';
	return (i_size);
}

void	rec_x(unsigned int i, t_format *lst, int *num, char s[8])
{
	if (i < 16)
	{
		if (lst->type == 'X')
			s[(*num)++] = "0123456789ABCDEF"[i];
		else
			s[(*num)++] = "0123456789abcdef"[i];
		return ;
	}
	rec_x((i / 16), lst, num, s);
	if (lst->type == 'X')
		s[(*num)++] = "0123456789ABCDEF"[i % 16];
	else
		s[(*num)++] = "0123456789abcdef"[i % 16];
}
