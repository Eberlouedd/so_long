/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:18:10 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/27 19:55:31 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	only_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}