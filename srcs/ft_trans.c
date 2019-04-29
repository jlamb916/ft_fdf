/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:22:01 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:33:01 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat	**ft_zrotate(t_fdf *f, t_mat **mat)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = 0;
	while (i < f->height)
	{
		j = 0;
		while (j < f->width)
		{
			x = mat[i][j].x;
			y = mat[i][j].y;
			mat[i][j].x = x * cos(0.7854) - y * sin(0.7854);
			mat[i][j].y = x * sin(0.7854) + y * cos(0.7854);
			j++;
		}
		i++;
	}
	return (mat);
}

static t_mat	**ft_yrotate(t_fdf *f, t_mat **mat)
{
	float	x;
	float	z;
	int		i;
	int		j;

	i = 0;
	while (i < f->height)
	{
		j = 0;
		while (j < f->width)
		{
			x = mat[i][j].x;
			z = mat[i][j].z;
			mat[i][j].x = x * cos(0.0524) + z * sin(0.0524);
			mat[i][j].z = -(x * sin(0.0524)) + z * cos(0.0524);
			j++;
		}
		i++;
	}
	return (mat);
}

static t_mat	**ft_xrotate(t_fdf *f, t_mat **mat)
{
	float	y;
	float	z;
	int		i;
	int		j;

	i = 0;
	while (i < f->height)
	{
		j = 0;
		while (j < f->width)
		{
			y = mat[i][j].y;
			z = mat[i][j].z;
			f->mat[i][j].y = (y * cos(0.6982) - z * sin(0.6982));
			f->mat[i][j].z = (y * sin(0.6982) + z * cos(0.6982));
			j++;
		}
		i++;
	}
	return (mat);
}

static t_mat	**ft_center(t_fdf *f, t_mat **mat)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = 0;
	while (i < f->height)
	{
		j = 0;
		while (j < f->width)
		{
			x = mat[i][j].x;
			y = mat[i][j].y;
			mat[i][j].x = x + (f->dimx / 2);
			mat[i][j].y = y + (f->dimy / 2);
			j++;
		}
		i++;
	}
	return (mat);
}

void			ft_trans(t_fdf *f)
{
	ft_zrotate(f, f->mat);
	ft_xrotate(f, f->mat);
	ft_yrotate(f, f->mat);
	ft_center(f, f->mat);
}
