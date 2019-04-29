/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:29:15 by jolam             #+#    #+#             */
/*   Updated: 2018/08/03 15:58:25 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	int		i;

	if (!s)
		return (NULL);
	string = ft_strnew(ft_strlen(s));
	if (!string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		(string[i] = f(s[i]));
		i++;
	}
	return (string);
}
