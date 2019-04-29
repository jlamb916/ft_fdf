/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:16:06 by jolam             #+#    #+#             */
/*   Updated: 2019/02/26 12:18:02 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		main(int ac, char **av)
{
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
	}
	return (0);
}
