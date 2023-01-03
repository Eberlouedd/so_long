#include "../include/so_long.h"

void error_img_collectible(t_img *game)
{
    write(1, "Error\nCan't read collectible image\n", 35);
	free_double_char(game->map);
	mlx_destroy_image(game->mlx ,game->wall);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void error_img_wall(t_img *game)
{
    write(1, "Error\nCan't read wall image\n", 28);
	free_double_char(game->map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void error_img_ground(t_img *game)
{
    write(1, "Error\nCan't read ground image\n", 30);
	free_double_char(game->map);
    mlx_destroy_image(game->mlx ,game->wall);
    mlx_destroy_image(game->mlx ,game->collectibles);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}


void error_mlx(t_img *game)
{
	free_double_char(game->map);
	exit(1);
}

void error_mlx_win(t_img *game)
{
	free_double_char(game->map);
	mlx_destroy_image(game->mlx ,game->charater);
	mlx_destroy_image(game->mlx ,game->exit);
	mlx_destroy_image(game->mlx ,game->wall);
	mlx_destroy_image(game->mlx ,game->ground);
	mlx_destroy_image(game->mlx ,game->collectibles);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}