/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopping <stopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:31:17 by stopping          #+#    #+#             */
/*   Updated: 2020/11/17 18:33:33 by stopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordsnum(const char *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static char		**ft_freesplit(char **a, int n)
{
	while (0 <= n)
		free(a[n--]);
	free(a);
	return (0);
}

static char		*ft_makeword(const char *s, char c)
{
	char	*w;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(w = malloc((i + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		w[i] = s[i];
		i++;
	}
	w[i] = 0;
	return (w);
}

char			**ft_split(char const *s, char c)
{
	char	**a;
	int		wn;
	int		j;

	if (!s)
		return (0);
	j = 0;
	wn = ft_wordsnum(s, c);
	if (!(a = (char **)malloc((wn + 1) * sizeof(char *))))
		return (0);
	a[wn] = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(a[j++] = ft_makeword(s, c)))
				return (ft_freesplit(a, j - 1));
			while (*s && *s != c)
				s++;
		}
	}
	return (a);
}
