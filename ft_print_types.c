/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:44:01 by stopping          #+#    #+#             */
/*   Updated: 2022/04/06 00:24:18 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_c(t_format *lst, va_list p_va, char flag)
{
	int		num;
	char	c;

	num = 0;
	c = (flag == '%') ? '%' : va_arg(p_va, int);
	if (lst->flag == '-')
	{
		num += ft_putchr(c);
		num += putstr_chr(' ', lst->width - 1);
	}
	else
	{
		num += putstr_chr((lst->flag == '0') ? '0' : ' ', lst->width - 1);
		num += ft_putchr(c);
	}
	return (num);
}

int		print_s(t_format *lst, va_list p_va)
{
	int			num;
	char		*s;
	int			s_len;

	num = 0;
	s = va_arg(p_va, char *);
	s_len = (s != NULL) ? (int)ft_strlen(s) : (int)ft_strlen("(null)");
	if (lst->pre >= 0 && lst->pre < s_len)
		s_len = lst->pre;
	if (lst->flag == '-')
	{
		num += putstr((s == NULL) ? "(null)" : s, 0, s_len);
		num += putstr_chr(' ', lst->width - s_len);
	}
	else
	{
		num += putstr_chr(' ', lst->width - s_len);
		num += putstr((s == NULL) ? "(null)" : s, 0, s_len);
	}
	return (num);
}

int		print_p(t_format *lst, va_list p_va)
{
	int						num;
	unsigned long long int	p;
	char					s[16];
	int						j;

	j = 0;
	num = 0;
	if ((p = va_arg(p_va, unsigned long long int)) == 0)
		s[16 - ++j] = '0';
	p *= 16;
	while ((p /= 16) > 0)
		(s[16 - ++j] = "0123456789abcdef"[p % 16]);
	if (lst->flag == '-')
	{
		num += putstr("0x", 0, 2);
		num += putstr(s, 16 - j, j);
		num += putstr_chr(' ', lst->width - num);
	}
	else
	{
		num += putstr_chr(' ', lst->width - (j + 2));
		num += putstr("0x", 0, 2);
		num += putstr(s, 16 - j, j);
	}
	return (num);
}

int		print_diu(t_format *lst, va_list p_va, char f)
{
	int		num;
	int		i;
	int		is;
	char	s[5];

	num = 0;
	i = va_arg(p_va, long int);
	is = (f == 'u') ? strdiu((unsigned int)i, 5, s, lst) : strdiu(i, 5, s, lst);
	if (lst->flag == '-' || (lst->flag == '0' && lst->pre < 0))
	{
		num += (i < 0 && f != 'u') ? ft_putchr('-') : 0;
		num += (lst->flag == '-') ? putstr_chr('0', lst->pre - is) : 0;
		if (lst->flag == '0')
			num += putstr_chr('0',
				lst->width - ((lst->pre < is) ? is : lst->pre) - num);
		num += putstr(s, 5 - is, is);
		num += putstr_chr(' ', lst->width - num);
		return (num);
	}
	num += putstr_chr(' ',
		lst->width - ((lst->pre < is) ? is : lst->pre) - (i < 0 && f != 'u'));
	num += (i < 0 && f != 'u') ? ft_putchr('-') : 0;
	num += putstr_chr('0', lst->pre - is);
	num += putstr(s, 5 - is, is);
	return (num);
}

int		print_x(t_format *lst, va_list p_va)
{
	int				num;
	int				is;
	unsigned int	i;
	char			s[8];

	is = 0;
	num = 0;
	i = va_arg(p_va, unsigned int);
	rec_x(i, lst, &is, s);
	if (lst->pre >= 0 && is == 1 && s[0] == '0')
		is = 0;
	if (lst->flag == '-')
	{
		num += putstr_chr('0', lst->pre - is);
		num += putstr(s, 0, is);
		num += putstr_chr(' ', lst->width - num);
	}
	else
	{
		num += putstr_chr((lst->flag == '0' && lst->pre < 0) ? '0' : ' ',
			lst->width - (lst->pre < is ? is : lst->pre));
		num += putstr_chr('0', lst->pre - is);
		num += putstr(s, 0, is);
	}
	return (num);
}
