/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:23:01 by jolam             #+#    #+#             */
/*   Updated: 2019/03/08 00:42:52 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s)
{
	int		flag;
	size_t	wc;

	wc = 0;
	flag = 0;
	while (*s)
	{
		if (ft_check_spaces(*s))
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			wc++;
		}
		s++;
	}
	return (wc);
}
