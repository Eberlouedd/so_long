
#include "../include/so_long.h"

void init_variables(t_img *game, char **str)
{
    int width;
    int height;

    game->mlx = mlx_init();
	game->wall = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &width, &height);
    game->collectibles = mlx_xpm_file_to_image(game->mlx, "./spectre.xpm", &width, &height);
    game->ground = mlx_xpm_file_to_image(game->mlx, "./ground.xpm", &width, &height);
    game->charater = mlx_xpm_file_to_image(game->mlx, "./character.xpm", &width, &height);
    game->exit = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &width, &height);
    game->map = str;
    game->nb_collectible = count_collectibles(str);
    game->nb_moves = 0;
}

void    put_img(t_img image, char c, int j, int i)
{
    if(c == '1')
        mlx_put_image_to_window(image.mlx, image.mlx_win, image.wall, j * 50, i * 50);
    else if(c == 'C')
        mlx_put_image_to_window(image.mlx, image.mlx_win, image.collectibles, j * 50, i * 50);
    else if(c == '0')
        mlx_put_image_to_window(image.mlx, image.mlx_win, image.ground, j * 50, i * 50);
    else if(c == 'P')
        mlx_put_image_to_window(image.mlx, image.mlx_win, image.charater, j * 50, i * 50);
    else if(c == 'E')
        mlx_put_image_to_window(image.mlx, image.mlx_win, image.exit, j * 50, i * 50);
}

void make_window(char **str, t_img *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    init_variables(game, str);
    while (str[i])
        i++;
    game->mlx_win = mlx_new_window(game->mlx, ft_strlen(str[0]) * 50, i * 50, "so_long");
	if (!game->wall)
		return ;
    i = 0;
    while (str[i])
    {
        while(str[i][j])
        {
            put_img(*game, str[i][j], j, i);
            j++;
        }
        j = 0;
        i++;
    }
}