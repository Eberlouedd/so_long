/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:44:50 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/27 21:05:19 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		write(1, "Error\nWrong parameters\n", 23);
		exit(1);
	}
	check_extension(argv[1]);
	map = get_map(argv[1]);
	if (!(map != NULL && check_map(map) && check_way(map)))
	{
		write(1, "Error\nWrong map\n", 16);
		exit(1);
	}
	return (0);
}
