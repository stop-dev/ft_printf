/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:20:15 by stopping          #+#    #+#             */
/*   Updated: 2021/01/08 16:46:17 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_list2
{
	char		flag;
	int			width;
	int			pre;
	char		type;
}				t_format;

int				ft_putchr(char c);
int				putstr_chr(char c, int k);
int				putstr(char *s, int begin, int slong);
int				strdiu(long int i, int last, char s[last], t_format *lst);
void			rec_x(unsigned int i, t_format *lst, int *num, char s[8]);
int				print_c(t_format *lst, va_list p_va, char flag);
int				print_s(t_format *lst, va_list p_va);
int				print_p(t_format *lst, va_list p_va);
int				print_diu(t_format *lst, va_list p_va, char f);
int				print_x(t_format *lst, va_list p_va);
int				ft_printf(const char *s, ...);

#endif
