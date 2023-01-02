
#include "../include/so_long.h"

int key_event(int keycode, t_img *game)
{
  int *tab;
  int x;
  int y;

  tab = find_p(game->map);
  x = tab[0];
  y = tab[1];
  free(tab);
  if (keycode == ESC)
    close_win(game);
  else if(keycode == UP)
    move_images(game, x, y, UP);
  else if(keycode == LEFT)
    move_images(game, x, y, LEFT);
  else if(keycode == RIGHT)
    move_images(game, x, y, RIGHT);
  else if(keycode == DOWN)
    move_images(game, x, y, DOWN);
  return 0;
}

void  move_images(t_img *game, int i, int j, int key)
{
  int place_x;
  int place_y;
  int *tab;

  tab = make_new_xy(i,j,key);
  place_x = tab[0];
  place_y = tab[1];
  free(tab);
  if (game->map[place_x][place_y] == 'C')
    game->nb_collectible--;
  if (game->map[place_x][place_y] == 'E' && game->nb_collectible == 0)
    end_of_game(game);
  else if (game->map[place_x][place_y] == '0' || game->map[place_x][place_y] == 'C')
  {
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->ground, j * 50, i * 50);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->charater, place_y * 50, place_x * 50);
    game->map[i][j] = '0';
    game->map[place_x][place_y] = 'P';
    game->nb_moves++;
    printf("Mooves : %d\n", game->nb_moves);
  }
}

int *make_new_xy(int i, int j, int key)
{
  int *tab;

  tab = malloc(2 * sizeof(int));
  if(key == UP)
  {
    tab[0] = i - 1;
    tab[1] = j;
  }
  else if(key == DOWN)
  {
    tab[0] = i + 1;
    tab[1] = j;
  }
  else if(key == LEFT)
  {
    tab[0] = i;
    tab[1] = j - 1;
  }
  else if(key == RIGHT)
  {
    tab[0] = i;
    tab[1] = j + 1;
  }
  return (tab);
}