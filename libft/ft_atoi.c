/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:23:29 by stopping          #+#    #+#             */
/*   Updated: 2020/11/04 19:31:00 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sing;
	int	n;

	sing = 1;
	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'\
			|| *str == '\v' || *str == '\f'\
			|| *str == '\n')
		str++;
	if (*str == '-')
		sing = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		n = 10 * n + (*str++ - '0');
	n *= sing;
	return (n);
}
