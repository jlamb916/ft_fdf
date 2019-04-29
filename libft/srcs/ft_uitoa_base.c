/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:22:12 by jolam             #+#    #+#             */
/*   Updated: 2019/02/26 11:22:20 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned int n, int base)
{
	int				len;
	char			*s;
	unsigned int	nb;

	len = 1;
	nb = n;
	while (nb >= (unsigned)base)
	{
		len++;
		nb /= base;
	}
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	while (n >= (unsigned)base)
	{
		s[--len] = "0123456789abcdef"[n % base];
		n /= base;
	}
	s[--len] = "0123456789abcdef"[n % base];
	return (s);
}
