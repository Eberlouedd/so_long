/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:26:51 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/28 20:03:33 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **error_treatment(int nb_params, char **params)
{
	char	**map_test;

	if (nb_params != 2)
	{
		write(1, "Error\nWrong parameters\n", 23);
		return (NULL);
	}
	check_extension(params[1]);
	map_test = get_map(params[1]);
	if (map_test != NULL)
	{
		if(!(form_rec(map_test) && have_walls(map_test) && check_elements(map_test) && check_way(map_test)))
		{
			free_double_char(map_test);
			return (NULL);
		}
	}
	else
	{
		write(1, "Error\nCan't read file\n", 22);
		return (NULL);
	}
	free_double_char(map_test);
	return (get_map(params[1]));
}

void end_of_game(t_img *game)
{
	printf("Moves : %d\n", game->nb_moves + 1);
	free_double_char(game->map);
	mlx_destroy_image(game->mlx ,game->charater);
	mlx_destroy_image(game->mlx ,game->exit);
	mlx_destroy_image(game->mlx ,game->wall);
	mlx_destroy_image(game->mlx ,game->ground);
	mlx_destroy_image(game->mlx ,game->collectibles);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void close_win(t_img *game)
{
	free_double_char(game->map);
	mlx_destroy_image(game->mlx ,game->charater);
	mlx_destroy_image(game->mlx ,game->exit);
	mlx_destroy_image(game->mlx ,game->wall);
	mlx_destroy_image(game->mlx ,game->ground);
	mlx_destroy_image(game->mlx ,game->collectibles);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}