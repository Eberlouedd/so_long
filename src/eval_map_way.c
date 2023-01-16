/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_map_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:13:18 by kyacini           #+#    #+#             */
/*   Updated: 2023/01/16 18:41:30 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_loc	find_p(char **str)
{
	int		i;
	int		j;
	t_loc	localisation;

	i = 0;
	j = 0;
	localisation.x = 1;
	localisation.y = 1;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				localisation.x = i;
				localisation.y = j;
				return (localisation);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (localisation);
}

void	transform_around(char **str, int x, int y)
{
	if (str[x][y + 1] != '1' && str[x][y + 1] != 'S' && str[x][y] != 'S')
	{
		str[x][y + 1] = transform_char(str[x][y + 1]);
		transform_around(str, x, y + 1);
	}
	if (str[x][y - 1] != '1' && str[x][y - 1] != 'S' && str[x][y] != 'S')
	{
		str[x][y - 1] = transform_char(str[x][y - 1]);
		transform_around(str, x, y - 1);
	}
	if (str[x + 1][y] != '1' && str[x + 1][y] != 'S' && str[x][y] != 'S')
	{
		str[x + 1][y] = transform_char(str[x + 1][y]);
		transform_around(str, x + 1, y);
	}
	if (str[x - 1][y] != '1' && str[x - 1][y] != 'S' && str[x][y] != 'S')
	{
		str[x - 1][y] = transform_char(str[x - 1][y]);
		transform_around(str, x - 1, y);
	}
	return ;
}

char	**new_tab(char **str)
{
	int		i;
	int		j;
	t_loc	localisation;

	localisation = find_p(str);
	i = localisation.x;
	j = localisation.y;
	transform_around(str, i, j);
	return (str);
}

int	check_way(char **str)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = new_tab(str);
	while (new[i])
	{
		while (new[i][j])
		{
			if (new[i][j] == 'E' || new[i][j] == 'C')
			{
				write(1, "Error\nThere is no way out !\n", 28);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
