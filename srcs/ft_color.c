/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 21:54:39 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 21:56:27 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_fdf *f, t_mat v1, t_mat v2)
{
	if (f->c_flag)
	{
		if (v1.c != 0)
			return (v1.c);
		else
			return (WHITE);
	}
	else if (v1.rawz || v2.rawz > f->z_min)
	{
		if (v1.rawz == v2.rawz)
			return (WHITE);
		else if (v1.rawz < v2.rawz || v1.rawz > v2.rawz)
			return (RED);
	}
	return (BLUE);
}
