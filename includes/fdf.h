/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:45:56 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:03:21 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

enum			e_color
{
	WHITE = 0xFFFFFF,
	RED = 0xFF0000,
	GREEN = 0x008000,
	BLUE = 0x0000FF
};

typedef	struct	s_mat
{
	int			c;
	float		x;
	float		y;
	float		z;
	float		rawz;
}				t_mat;

typedef struct	s_alg
{
	float		deltax;
	float		deltay;
	float		e;
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		x;
	float		y;
	float		y_inc;
	float		x_inc;
}				t_alg;

typedef struct	s_val
{
	int			c;
	int			v;
}				t_val;

typedef	struct	s_fdf
{
	t_mat		**mat;
	t_val		**map;
	int			c_flag;
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
	float		gap;
	float		z_min;
	float		z_max;
	float		dimy;
	float		dimx;
	int			size;
	int			x_pos;
	int			y_pos;
	int			x;
	int			y;
	int			midx;
	int			midy;
	int			w_len;
	int			h_len;
	int			width;
	int			height;
}				t_fdf;

int				main(int ac, char **av);
int				key_func(int keycode, void *param);
void			ft_draw(t_fdf *f);
void			ft_parse_map(char *av, t_fdf *f);
t_val			**ft_store_map(int fd, t_fdf *f, t_val **map);
int				ft_color(t_fdf *f, t_mat v1, t_mat v2);
void			ft_init(t_fdf *f);
void			ft_trans(t_fdf *f);
void			ft_loop(t_fdf *f);

#endif
