/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:53:32 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/28 19:59:56 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size > 4)
	{
		if (str[size - 1] == 'r' && str[size - 2] == 'e'
			&& str[size - 3] == 'b' && str[size - 4] == '.')
			return ;
	}
	write(1, "Error\n", 6);
	write(1, "Wrong extension\n", 16);
	exit(1);
}

int	have_walls(char **str)
{
	int	i;

	i = 0;
	if (!only_one(str[0]))
		return (0);
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
			return (0);
		i++;
	}
	if (!only_one(str[i - 1]))
	{
		write(1, "Error\nThe map need walls\n", 25);
		return (0);
	}
	return (1);
}

int	check_elements(char **str)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = 0;
	e = 0;
	j = 0;
	c = 0;
	p = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				c = 1;
			else if (str[i][j] == 'P')
				p++;
			else if (str[i][j] == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	if (c < 1 || p != 1 || e != 1)
	{
		write(1, "Error\nYou need to have one exit, one character and at least one collectible\n", 76);
		return (0);
	}
	return (1);
}

int	form_rec(char **str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[i + 1]))
		{
			write(1, "Error\nYour map need to be a rectangle\n", 38);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map(char **str)
{
	if (!str)
		return (0);
	if (form_rec(str) && check_elements(str) && have_walls(str))
		return (1);
	return (0);
}
