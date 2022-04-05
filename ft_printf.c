/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:35:14 by stopping          #+#    #+#             */
/*   Updated: 2021/01/10 20:41:18 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Write flag, width and precision in lst
*/

static void		notype(const char *s, t_format *lst, va_list p_va, char *flag)
{
	if (lst->flag == '?' || (lst->flag == '0' && *s == '-'))
		lst->flag = (*s == '-' || *s == '0') ? *s : '1';
	if (ft_isdigit(*s) && *flag == 0 && !(lst->width))
		lst->width = ft_atoi(s);
	if (*s == '*' && *flag == 0)
		if ((lst->width = va_arg(p_va, int)) < 0)
		{
			lst->flag = '-';
			lst->width *= -1;
		}
	if (ft_isdigit(*s) && *flag == '.')
	{
		lst->pre = ft_atoi(s);
		*flag = '1';
	}
	if (*s == '*' && *flag == '.')
		lst->pre = va_arg(p_va, int);
	if (*s == '.')
	{
		*flag = '.';
		lst->pre = 0;
	}
}

/*
** Make lst of format
*/

static t_format	*new_format(const char *s, va_list p_va)
{
	t_format	*lst;
	char		flag;
	int			i;

	i = -1;
	flag = 0;
	if (!(lst = malloc(sizeof(t_format))))
		return (0);
	lst->flag = '?';
	lst->width = 0;
	lst->pre = -1;
	while (s[++i] != '\0')
		if (ft_isalpha(s[i]) || s[i] == '%')
			break ;
		else
			notype(&(s[i]), lst, p_va, &flag);
	lst->type = s[i];
	return (lst);
}

static int		ft_placeholder(const char *s, va_list p_va)
{
	t_format	*lst;
	int			num;

	num = 0;
	if (!(lst = new_format(s, p_va)))
		return (num);
	if (lst->type == 'c')
		num += print_c(lst, p_va, 0);
	if (lst->type == 's')
		num += print_s(lst, p_va);
	if (lst->type == 'p')
		num += print_p(lst, p_va);
	if (lst->type == 'd' || lst->type == 'i')
		num += print_diu(lst, p_va, 'd');
	if (lst->type == 'u')
		num += print_diu(lst, p_va, 'u');
	if (lst->type == 'x' || lst->type == 'X')
		num += print_x(lst, p_va);
	if (lst->type == '%')
		num += print_c(lst, p_va, '%');
	free(lst);
	lst = NULL;
	return (num);
}

int				ft_printf(const char *s, ...)
{
	va_list		p_va;
	int			num;
	int			i;

	num = 0;
	i = -1;
	va_start(p_va, s);
	while (s[++i])
		if (s[i] != '%')
			num += ft_putchr(s[i]);
		else
		{
			num += ft_placeholder(&(s[++i]), p_va);
			while (!ft_isalpha(s[i]) && s[i] != '%')
				i++;
		}
	va_end(p_va);
	return (num);
}
