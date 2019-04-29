/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:01:49 by jolam             #+#    #+#             */
/*   Updated: 2018/08/03 14:42:27 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*srcstr;
	char	*dststr;

	i = 0;
	srcstr = (char*)src;
	dststr = (char*)dst;
	if (srcstr < dststr)
		while ((int)(--len) >= 0)
			dststr[len] = srcstr[len];
	else
	{
		while (i < len)
		{
			dststr[i] = srcstr[i];
			i++;
		}
	}
	return (dst);
}
