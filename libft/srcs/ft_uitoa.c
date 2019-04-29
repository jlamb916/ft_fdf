/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:21:27 by jolam             #+#    #+#             */
/*   Updated: 2019/02/26 11:21:46 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char			*s;
	int				len;
	unsigned int	nb;

	len = 1;
	nb = n;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	s[len] = '\0';
	while (n > 9)
	{
		s[--len] = n % 10 + '0';
		n /= 10;
	}
	s[--len] = n % 10 + '0';
	return (s);
}
