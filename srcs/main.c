/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:53:14 by jolam             #+#    #+#             */
/*   Updated: 2019/03/14 22:23:53 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	f;

	if (ac != 2)
		ft_error("ERROR: invalid argc");
	ft_parse_map(av[1], &f);
	ft_init(&f);
	ft_trans(&f);
	ft_draw(&f);
	ft_loop(&f);
	sleep(100);
	return (0);
}
