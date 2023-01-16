/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:12:26 by kyacini           #+#    #+#             */
/*   Updated: 2023/01/05 12:05:07 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_event(int keycode, t_img *game)
{
	t_loc	localisation;
	int		x;
	int		y;

	localisation = find_p(game->map);
	x = localisation.x;
	y = localisation.y;
	if (keycode == ESC)
		close_win(game);
	else if (keycode == UP)
		move_images(game, x, y, UP);
	else if (keycode == LEFT)
		move_images(game, x, y, LEFT);
	else if (keycode == RIGHT)
		move_images(game, x, y, RIGHT);
	else if (keycode == DOWN)
		move_images(game, x, y, DOWN);
	return (0);
}

void	move_images(t_img *g, int i, int j, int key)
{
	int	new_x;
	int	new_y;
	int	*tab;

	tab = make_new_xy(i, j, key);
	if (!tab)
		close_win(g);
	new_x = tab[0];
	new_y = tab[1];
	free(tab);
	if (g->map[new_x][new_y] == 'C')
		g->nb_collectible--;
	if (g->map[new_x][new_y] == 'E' && g->nb_collectible == 0)
		end_of_game(g);
	else if (g->map[new_x][new_y] == '0' || g->map[new_x][new_y] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->ground,
			j * 50, i * 50);
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->charater, new_y * 50, new_x * 50);
		g->map[i][j] = '0';
		g->map[new_x][new_y] = 'P';
		g->nb_moves++;
		print_moves(g->nb_moves);
	}
}

int	*make_new_xy(int i, int j, int key)
{
	int	*tab;

	tab = malloc(2 * sizeof(int));
	if (!tab)
		return (NULL);
	tab[0] = i;
	tab[1] = j;
	if (key == UP)
		tab[0]--;
	else if (key == DOWN)
		tab[0]++;
	else if (key == LEFT)
		tab[1]--;
	else if (key == RIGHT)
		tab[1]++;
	return (tab);
}
