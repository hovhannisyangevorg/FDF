/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:22:22 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/08 17:45:16 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr_ptr + ((y * img_data->line_length) + \
		(x * (img_data->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

static void	ft_util(t_image *img_data, t_map *map, size_t x, size_t y)
{
	ft_bresenham((t_line_cord){map->matrix.cord[x].x, \
		map->matrix.cord[x].y, \
		map->matrix.cord[y].x, \
		map->matrix.cord[y].y, \
		map->matrix.cord[x].color}, \
		img_data);
}

void	ft_drow2d(t_mlx *mlx_data, t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	row_index;
	size_t	index_x;
	size_t	index_y;

	i = -1;
	while (++i < map->height)
	{
		row_index = i * map->width;
		j = -1;
		while (++j < map->width)
		{
			index_x = row_index + j;
			index_y = (i + 1) * map->width + j;
			if (j + 1 < map->width)
				ft_util(&mlx_data->img_data, map, index_x, index_x + 1);
			if (i + 1 < map->height)
				ft_util(&mlx_data->img_data, map, index_x, index_y);
		}
	}
}
