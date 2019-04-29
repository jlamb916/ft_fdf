/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:21:17 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:39:33 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat	**ft_load_coord(t_fdf *f, t_mat **m)
{
	int		i;
	int		j;

	i = 0;
	if (!(m = (t_mat**)malloc(sizeof(t_mat*) * f->height)))
		ft_error("Error: mallocing *coord\n");
	while (i < f->height)
	{
		if (!(m[i] = (t_mat*)malloc(sizeof(t_mat) * f->width)))
			ft_error("Error: mallocing **coord\n");
		j = 0;
		while (j < f->width)
		{
			m[i][j] = (t_mat){f->map[i][j].c, (j - f->midx) * f->gap,
				(i - f->midy) * f->gap, f->map[i][j].v * 5, f->map[i][j].v};
			j++;
		}
		i++;
	}
	printf("Transfer complete\n");
	return (m);
}

void			ft_init(t_fdf *f)
{
	f->midx = f->width / 2;
	f->midy = f->height / 2;
	f->size = f->width > f->height ? f->width : f->height;
	f->gap = 600 / f->size;
	f->dimx = 800 + f->gap * f->size;
	f->dimy = f->dimx - 300;
	f->mat = ft_load_coord(f, f->mat);
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, f->dimx, f->dimy, "MLX");
}
