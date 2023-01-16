/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:12:14 by kyacini           #+#    #+#             */
/*   Updated: 2023/01/16 18:29:39 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_variables(t_img *g, char **str)
{
	int	w;
	int	h;

	g->map = str;
	g->mlx = mlx_init();
	if (!g->mlx)
		error_mlx(g);
	g->wall = mlx_xpm_file_to_image(g->mlx, "./img/wall.xpm", &w, &h);
	if (!g->wall)
		error_img_wall(g);
	g->collectibles = mlx_xpm_file_to_image(g->mlx, "./img/item.xpm", &w, &h);
	if (!g->collectibles)
		error_img_collectible(g);
	g->ground = mlx_xpm_file_to_image(g->mlx, "./img/ground.xpm", &w, &h);
	if (!g->ground)
		error_img_ground(g);
	g->charater = mlx_xpm_file_to_image(g->mlx, "./img/perso.xpm", &w, &h);
	if (!g->charater)
		error_img_character(g);
	g->exit = mlx_xpm_file_to_image(g->mlx, "./img/exit.xpm", &w, &h);
	if (!g->exit)
		error_img_exit(g);
	g->nb_collectible = count_collectibles(str);
	g->nb_moves = 0;
}

void	put_img(t_img image, char c, int j, int i)
{
	if (c == '1')
		mlx_put_image_to_window(image.mlx, image.mlx_win,
			image.wall, j * 50, i * 50);
	else if (c == 'C')
		mlx_put_image_to_window(image.mlx, image.mlx_win,
			image.collectibles, j * 50, i * 50);
	else if (c == '0')
		mlx_put_image_to_window(image.mlx, image.mlx_win,
			image.ground, j * 50, i * 50);
	else if (c == 'P')
		mlx_put_image_to_window(image.mlx, image.mlx_win,
			image.charater, j * 50, i * 50);
	else if (c == 'E')
		mlx_put_image_to_window(image.mlx, image.mlx_win,
			image.exit, j * 50, i * 50);
}

void	make_window(char **str, t_img *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_variables(game, str);
	while (str[i])
		i++;
	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(str[0]) * 50,
			i * 50, "so_long");
	if (!game->mlx_win)
		error_mlx_win(game);
	if (!game->wall)
		return ;
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			put_img(*game, str[i][j], j, i);
			j++;
		}
		j = 0;
		i++;
	}
}
