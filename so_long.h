/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:46:27 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/27 21:08:15 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

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
#endif