/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:42:21 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/08 15:10:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_mlx(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		ft_panic(INVALID_MLX);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	mlx_data->img_data.img_ptr = mlx_new_image(mlx_data->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_data->img_data.addr_ptr = mlx_get_data_addr(mlx_data->img_data.img_ptr,
			&mlx_data->img_data.bits_per_pixel,
			&mlx_data->img_data.line_length, &mlx_data->img_data.endian);
}

void	ft_init_config(t_conf *config)
{
	if (!config)
		return ;
	config->zoom = SCREEN_ZOOM;
	config->x_move = (SCREEN_WIDTH / 2);
	config->y_move = (SCREEN_HEIGHT / 2);
	config->z_mode = SCREEN_ZMOD;
	config->projection = ISOMETRIC;
	config->rotation = (t_transform){0, 0, 0};
}

void	ft_config(t_map *map, t_conf config)
{
	size_t	i;

	i = -1;
	while (++i < map->matrix.size)
	{
		map->matrix.cord[i].x *= config.zoom;
		map->matrix.cord[i].y *= config.zoom;
		map->matrix.cord[i].z *= config.zoom / config.z_mode;
		map->matrix.cord[i].x -= ((double)map->width * config.zoom) / 2.;
		map->matrix.cord[i].y -= ((double)map->height * config.zoom) / 2.;
		map->matrix.cord[i] = ft_rotate_x(map->matrix.cord[i],
				config.rotation.x);
		map->matrix.cord[i] = ft_rotate_y(map->matrix.cord[i],
				config.rotation.y);
		map->matrix.cord[i] = ft_rotate_z(map->matrix.cord[i],
				config.rotation.z);
	}
}
