/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:48:21 by jolam             #+#    #+#             */
/*   Updated: 2019/03/08 00:41:23 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordsplit(char const *s, char c)
{
	int			i;
	int			wd;

	i = 0;
	wd = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			wd++;
		i++;
	}
	return (wd);
}

static size_t	ft_until(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		i;
	size_t		j;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * (ft_wordsplit(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			split[i] = (char *)malloc(sizeof(char) * ((ft_until(s, c)) + 1));
			while (ft_until(s, c) > 0)
				split[i][j++] = *s++;
			split[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
