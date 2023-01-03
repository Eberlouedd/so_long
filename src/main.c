/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:44:50 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/28 19:55:20 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_img 	game;

	map = error_treatment(argc, argv);
	if (map == NULL)
		exit (1);
	make_window(map, &game);
	mlx_key_hook(game.mlx_win, key_event, &game);
	mlx_hook(game.mlx_win, 33, 0, close_win, &game);
	mlx_loop(game.mlx);
	return (0);
}
