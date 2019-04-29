/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 20:18:52 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:46:58 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_check_valid(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(ft_check_char("-+0123456789,0xABCDEFabcdef ", line[i])))
			ft_error("Error: invalid char");
		if ((line[i] == '-' || line[i] == '+') && (line[i - 1] != ' ' ||
					(!ft_check_dig(line[i + 1]))))
			ft_error("Error: invalid dig");
		i++;
	}
}

static int		ft_get_width(char **line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

static void		ft_check_lines(int fd, t_fdf *f, int first_w)
{
	char	*line;
	char	**array;
	int		t;

	while (get_next_line(fd, &line))
	{
		ft_check_valid(line);
		if (!(array = ft_strsplit(line, ' ')) || !*array)
			ft_error("Error: strsplit failed");
		f->w_len = 0;
		if (!(f->w_len = ft_get_width(array)))
			ft_error("Error: invalid width");
		if (f->w_len != first_w)
			ft_error("Error: uneven width");
		free(line);
		t = -1;
		while (array[++t])
			free(array[t]);
		free(array);
		f->h_len++;
	}
}

static void		ft_check_map(int fd, t_fdf *f)
{
	char	*line;
	char	**array;
	int		first_w;
	int		t;

	f->h_len = 0;
	first_w = 0;
	if ((get_next_line(fd, &line)))
	{
		ft_check_valid(line);
		if (!(array = ft_strsplit(line, ' ')))
			ft_error("Error: strsplit failed");
		if (!(first_w = ft_get_width(array)))
			ft_error("Error: invalid width");
		free(line);
		t = -1;
		while (array[++t])
			free(array[t]);
		free(array);
		f->h_len++;
	}
	ft_check_lines(fd, f, first_w);
}

void			ft_parse_map(char *av, t_fdf *f)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("Error: Opening file");
	printf("file opened\n");
	ft_check_map(fd, f);
	close(fd);
	f->width = f->w_len;
	f->height = f->h_len;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("Error: Opening file");
	f->map = ft_store_map(fd, f, f->map);
	close(fd);
}
