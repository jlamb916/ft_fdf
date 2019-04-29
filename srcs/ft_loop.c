/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:37:05 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:25:34 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keycode_exit(int keycode, t_fdf *f)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void		ft_loop(t_fdf *f)
{
	mlx_key_hook(f->win_ptr, keycode_exit, f);
	mlx_loop(f->mlx_ptr);
}
