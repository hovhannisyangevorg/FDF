/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:42:21 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/29 14:22:18 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_config(t_conf *config)
{
	if (!config)
		return ;	
	config->zoom = SCREEN_ZOOM;
	config->x_move = (SCREEN_WIDTH / 2);
	config->y_move = (SCREEN_HEIGHT / 2);
	config->z_mode = SCREEN_ZMOD;
}

void	ft_config(t_map *map, t_conf config)
{
	size_t i;
	if (!map)
		return ;	
	i = -1;
	printf("%lf %lf\n", (map->width * config.zoom) / 2, (map->height * config.zoom) / 2);
	while (++i < map->matrix.size)
	{
		map->matrix.cord[i].x *= config.zoom;
		map->matrix.cord[i].y *= config.zoom;
		// map->matrix.cord[i].z *= config.zoom / config.z_mode;
		map->matrix.cord[i].x -= (map->width * config.zoom) / 2;
		map->matrix.cord[i].y -= (map->height * config.zoom) / 2;
		// map->matrix.cord[i].x += config.x_move;
		// map->matrix.cord[i].y += config.y_move;
	}
	
}

float ft_deg_to_rad(float angle)
{
	return ((M_PI / 180) * angle);
}

// angle is 'T'
// x′ = (x − z) * cos(T) 
// y′ = y + (x + z) * sin(T)
void ft_isometric(t_point3d *cord, t_conf conf)
{
	double x;
	float T;
	
	x = cord->x;
	T = ft_deg_to_rad(35);
	cord->x = conf.x_move + ((cord->x - cord->y) * cos(T));
	cord->y = conf.y_move + ((x + cord->y) * sin(T));
}

void	ft_to_isometric(t_map *map, t_conf conf)
{
	size_t i;

	i = -1;
	while (++i < map->matrix.size)
		ft_isometric(&map->matrix.cord[i], conf);
}























































































// angle is 'T'
// x′= x + n ⋅ z ⋅ cos(T)
// y′= y + n ⋅ z ⋅ sin(T)
// void ft_dimetric(t_point3d *cord)
// {
// 	float T;
// 	float n;

// 	T = ft_deg_to_rad(35);
// 	n = 0.6;
// 	cord->x = cord.x + n * cord->z * cos(T);
// 	cord->y = cord.y + n * cord->z * sin(T);
// }