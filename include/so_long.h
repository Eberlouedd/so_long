/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:46:27 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/28 19:53:33 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "/usr/include/X11/X.h"
# include <stdio.h>

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct s_img
{
    void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*ground;
	void	*charater;
	void	*exit;
	void	*collectibles;
	char	**map;
	int		nb_collectible;
	int		nb_moves;
}       t_img;

void		check_extension(char *str);
char		**get_map(char *str);
int			only_one(char *str);
int			have_walls(char **str);
int			check_elements(char **str);
int			form_rec(char **str);
int			check_map(char **str);
int 		*find_p(char **str);
void		transform_around(char **str, int x, int y);
char		**new_tab(char **str);
int			check_way(char **str);
void		free_double_char(char **str);
char 		**error_treatment(int nb_params, char **params);
void        make_window(char **str, t_img *game);
void 		init_variables(t_img *game, char **str);
void    	put_img(t_img image, char c, int j, int i);
int 		key_event(int keycode, t_img *game);
int 		count_collectibles(char **str);
int 		*make_new_xy(int i, int j, int key);
void  		move_images(t_img *game, int i, int j, int key);
void 		close_win(t_img *game);
void 		end_of_game(t_img *game);

#endif