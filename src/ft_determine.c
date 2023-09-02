/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:02:42 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/03 01:07:00 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int ft_tabcmp(int val1, int val2)
{
	return (val1 - val2);
}

int	ft_determine_width(t_add *tab, size_t arr_size)
{
	size_t	i;
	int 	val;
	if (arr_size == 1)
		return (tab->arr[0]);
	i = 0;
	while (tab->size && !tab->arr[i])
		++i;
	val = tab->arr[i];
	while (++i < arr_size)
	{
		if (val && ft_tabcmp(tab->arr[i], tab->arr[i - 1]) && val != ft_tabcmp(tab->arr[i], tab->arr[i - 1]))
		{
			free(tab->arr);
			ft_panic(INVALID_MAP);
		}
	}
	return (val);
}

void	ft_determine_x_y(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix.cord[i * map->width + j].x = j;
			map->matrix.cord[i * map->width + j].y = i;
			j++;
		}
		i++;
	}
}