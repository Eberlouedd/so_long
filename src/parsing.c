/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:48:08 by kyacini           #+#    #+#             */
/*   Updated: 2023/01/04 20:08:30 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *str)
{
	char	*buff;
	char	*stock;
	char	**result;
	int		fd;

	stock = NULL;
	fd = open(str, O_RDONLY);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		stock = ft_strjoin(stock, buff);
		free(buff);
		buff = NULL;
	}
	close(fd);
	if (stock)
	{
		result = ft_split(stock, '\n');
		free(stock);
		return (result);
	}
	return (NULL);
}

int	check_c(char **str)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	c = 0;
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				c = 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (c != 1)
	{
		write(1, "Error\nThere is a problem with the collectibles\n", 48);
		return (0);
	}
	return (1);
}

int	check_p(char **str)
{
	int	i;
	int	j;
	int	p;

	j = 0;
	p = 0;
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (p != 1)
	{
		write(1, "Error\nOne character please\n", 27);
		return (0);
	}
	return (1);
}

int	check_e(char **str)
{
	int	i;
	int	j;
	int	e;

	j = 0;
	e = 0;
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	if (e != 1)
	{
		write(1, "Error\nOne escape please\n", 24);
		return (0);
	}
	return (1);
}
