/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:20:43 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:46:56 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_move_colors(t_fdf *f, char *array, t_val **map)
{
	int		i;
	char	*tmp;

	i = 0;
	f->c_flag = 1;
	if (!*array)
		ft_error("Error: empty line");
	while (array[i])
	{
		if (array[i] == ',' && array[i + 1] == '0' && array[i + 2] == 'x')
		{
			i += 3;
			tmp = ft_strsub(array, i, ft_strlen(array) - i);
			map[f->y_pos][f->x_pos].c = ft_atoi_base(tmp, 16);
			free(tmp);
			break ;
		}
		i++;
	}
}

static void		ft_move(t_fdf *f, char **array, t_val **map)
{
	int		i;

	i = 0;
	if (!(map[f->y_pos] = (t_val*)ft_memalloc(sizeof(t_val) * f->width)))
		ft_error("Error Mallocing array[1]");
	f->x_pos = 0;
	while (array[i])
	{
		map[f->y_pos][f->x_pos].v = ft_atoi(array[i]);
		f->z_min = (map[f->y_pos][f->x_pos].v < f->z_min) ?
			map[f->y_pos][f->x_pos].v : f->z_min;
		f->z_max = (map[f->y_pos][f->x_pos].v > f->z_max) ?
			map[f->y_pos][f->x_pos].v : f->z_max;
		if (ft_strstr(array[i], ",0x"))
			ft_move_colors(f, array[i], map);
		i++;
		f->x_pos++;
	}
	f->y_pos++;
}

t_val			**ft_store_map(int fd, t_fdf *f, t_val **map)
{
	char	*line;
	char	**array;
	int		t;

	f->c_flag = 0;
	f->z_max = 0.0;
	f->z_min = 0.0;
	f->y_pos = 0;
	f->x_pos = 0;
	if (!(map = (t_val**)ft_memalloc(sizeof(t_val*) * f->height)))
		ft_error("Error Mallocing array");
	while (get_next_line(fd, &line) > 0)
	{
		if ((array = ft_strsplit(line, ' ')))
			ft_move(f, array, map);
		free(line);
		t = -1;
		while (array[++t])
			free(array[t]);
		free(array);
	}
	return (map);
}
