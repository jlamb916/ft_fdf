/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:19:56 by jolam             #+#    #+#             */
/*   Updated: 2019/02/26 11:20:14 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int		ft_get_len(long n, int len)
{
	long nb;

	nb = n < 0 ? -(long)n : n;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char			*ft_ltoa(long n)
{
	long	nb;
	char	*s;
	int		len;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = 1;
	n < 0 ? len++ : 0;
	nb = n < 0 ? -(long)n : n;
	if (nb > 9)
		len = ft_get_len(n, len);
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	nb = n < 0 ? -(long)n : n;
	n < 0 ? *s = '-' : 0;
	while (nb > 9)
	{
		s[--len] = nb % 10 + '0';
		nb /= 10;
	}
	s[--len] = nb % 10 + '0';
	return (s);
}
