/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:13:56 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:36:02 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_var(t_alg *a, t_mat v1, t_mat v2)
{
	a->deltax = v2.x - v1.x;
	a->deltay = v2.y - v1.y;
	a->x = v1.x;
	a->y = v1.y;
	a->y_inc = (v2.y - v1.y) < 0.0 ? -1.0 : 1.0;
	a->x_inc = (v2.x - v1.x) < 0.0 ? -1.0 : 1.0;
}

static void		plot_line_low(t_fdf *f, t_alg *a, t_mat v1, t_mat v2)
{
	float	y;

	y = a->y;
	set_var(a, v1, v2);
	a->deltay = fabs(v2.y - v1.y);
	a->e = (2.0 * a->deltay) + a->deltax;
	while (a->x <= v2.x)
	{
		f->color = ft_color(f, v1, v2);
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, a->x, a->y, f->color);
		if (a->e > 0.0)
		{
			a->y += a->y_inc;
			a->e = a->e - 2.0 * a->deltax;
		}
		a->e = a->e + 2.0 * a->deltay;
		a->x += 1.0;
	}
}

static void		plot_line_high(t_fdf *f, t_alg *a, t_mat v1, t_mat v2)
{
	float	x;

	x = a->x;
	set_var(a, v1, v2);
	a->deltax = fabs(v2.x - v1.x);
	a->e = (2.0 * a->deltax) + a->deltay;
	while (a->y <= v2.y)
	{
		f->color = ft_color(f, v1, v2);
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, a->x, a->y, f->color);
		if (a->e > 0.0)
		{
			a->x += a->x_inc;
			a->e = a->e - 2.0 * a->deltay;
		}
		a->e += 2.0 * a->deltax;
		a->y += 1.0;
	}
}

static void		draw_line(t_fdf *f, t_alg *a, t_mat v1, t_mat v2)
{
	if (fabs(v2.y - v1.y) < fabs(v2.x - v1.x))
	{
		if (v2.x > v1.x)
			plot_line_low(f, a, v1, v2);
		else
			plot_line_low(f, a, v2, v1);
	}
	else
	{
		if (v2.y > v1.y)
			plot_line_high(f, a, v1, v2);
		else
			plot_line_high(f, a, v2, v1);
	}
}

void			ft_draw(t_fdf *f)
{
	t_alg	a;

	f->y = 0;
	f->x = 0;
	while (f->y < f->height)
	{
		f->x = 0;
		while (f->x < f->width)
		{
			if (f->x < f->width - 1)
				draw_line(f, &a, f->mat[f->y][f->x], f->mat[f->y][f->x + 1]);
			if (f->y < f->height - 1)
				draw_line(f, &a, f->mat[f->y][f->x], f->mat[f->y + 1][f->x]);
			f->x++;
		}
		f->y++;
	}
}
