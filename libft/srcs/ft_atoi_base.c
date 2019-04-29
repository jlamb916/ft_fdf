/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:58:43 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 15:30:14 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *s, int base)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (ft_check_char(" \t\n\v\r\f", *s))
		++s;
	if (ft_check_char("-+", *s) && base == 10)
	{
		sign = *s == '-' ? -1 : 1;
		s++;
	}
	while (*s && ft_check_char("0123456789abcdefABCDEF", *s))
	{
		if (ft_check_char("0123456789", *s))
			num = (num * base) + *s - '0';
		else if (ft_check_char("ABCDEF", *s))
			num = (num * base) + *s - 55;
		else if (ft_check_char("abcdef", *s))
			num = (num * base) + *s - 87;
		++s;
	}
	return (sign * num);
}
