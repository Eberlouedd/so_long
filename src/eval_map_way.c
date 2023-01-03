/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_map_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:13:18 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/28 19:56:49 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int *find_p(char **str)
{
	int	i;
	int	j;
	int *tab;
	
	i = 0;
	j = 0;
	tab = malloc(2 * sizeof(int));
	while (str[i])
	{
		while (str[i][j])
		{
			if(str[i][j] == 'P')
			{
				tab[0] = i;
				tab[1] = j;
				return (tab);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
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
	int i;
	int	j;
	int *tab;

	tab = find_p(str);
	i = tab[0];
	j = tab[1];
	transform_around(str, i, j);
	free(tab);
	return (str);
}


int	check_way(char **str)
{
	char **new;
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!check_map(str))
		return (0);
	new = new_tab(str);
	while (new[i])
	{
		while (new[i][j])
		{
			if(new[i][j] == 'E' || new[i][j] == 'C')
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