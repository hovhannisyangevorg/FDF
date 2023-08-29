/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/29 14:13:12 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
TODO: [Remove this function for fdf projects. ft_print_matrix()]
*/

void	ft_print_matrix(t_matrix *m)
{
	size_t	i;
	size_t	print_count;

	i = 0;
	print_count = 0;
	printf("\n--------------------Matrix------------------------\n");
	while (i < m->size)
	{
		printf("%zu). ", ++print_count);
		printf("(%lf, %lf, ", m->cord[i].x, m->cord[i].y);
		printf("%lf, %x)\n", m->cord[i].z, m->cord[i].color);
		i++;
	}
	printf("\n--------------------------------------------------\n");
}

/*
TODO: [Remove this function for fdf projects. ft_print_arrey()]
*/
void	ft_print_arrey(t_add *tab, size_t size)
{
	size_t i;

	i = 0;
	printf("\n--------------------Arrey------------------------\n");
	while (i < size)
	{
		printf("%ld) Arrey arg %d\n", i, tab->arr[i]);
		i++;
	}
	printf("\n-------------------------------------------------\n");
}




void	ft_drow2d(t_mlx *mlx_data, t_map *map)
{
	size_t i = 0;
	size_t j = 0;
	size_t row_index;
	size_t index_x;
	size_t index_y;

	while (i < map->height)
	{
		row_index = i * map->width;
		j = 0;
		while (j < map->width)
		{
			index_x = row_index + j;
			index_y = (i + 1) * map->width + j;
			if (j + 1 < map->width)
				ft_draw_line_DDA((t_line_cord){map->matrix.cord[index_x].x, map->matrix.cord[index_x].y, map->matrix.cord[index_x + 1].x, map->matrix.cord[index_x + 1].y, 0xff0000}, &mlx_data->img_data);
			if (i + 1 < map->height)
				ft_draw_line_DDA((t_line_cord){map->matrix.cord[index_x].x, map->matrix.cord[index_x].y, map->matrix.cord[index_y].x, map->matrix.cord[index_y].y, 0xff0000}, &mlx_data->img_data);
			++j;
		}
		++i;
	} 
}




void	ft_init_mlx(t_mlx *mlx_data)
{
    mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		ft_panic("Minilibx not initialize\n");
    mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	mlx_data->img_data.img_ptr = mlx_new_image(mlx_data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_data->img_data.addr_ptr = mlx_get_data_addr(mlx_data->img_data.img_ptr, &mlx_data->img_data.bits_per_pixel, &mlx_data->img_data.line_length, &mlx_data->img_data.endian);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->img_data.img_ptr, 0, 0);
}

// int closeWin()
// {
// 	exit(0);
// 	return 0;
// }

int main() 
{
	int		fd;
	t_mlx	mlx_data;
	t_map	map;
	t_add	tab;
	t_conf	config;

	ft_init_config(&config);
	fd = open("maps/42.fdf", O_RDONLY);
	if (fd == -1)
		return (0);
	ft_parse(&map, &tab, fd);
	ft_config(&map, config);
	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
		ft_panic("Minilibx not initialize\n");
    mlx_data.win_ptr = mlx_new_window(mlx_data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	mlx_data.img_data.img_ptr = mlx_new_image(mlx_data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_data.img_data.addr_ptr = mlx_get_data_addr(mlx_data.img_data.img_ptr, &mlx_data.img_data.bits_per_pixel, &mlx_data.img_data.line_length, &mlx_data.img_data.endian);
	// ft_init_mlx(&mlx_data);
	ft_print_matrix(&map.matrix);
	ft_to_isometric(&map, config);
	ft_drow2d(&mlx_data, &map);
	mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.win_ptr, mlx_data.img_data.img_ptr, 0, 0);



	mlx_loop(mlx_data.mlx_ptr);
	// mlx_hook(mlx_data.win_ptr, 17, 1L << 17, close_win, 0);
	free(map.matrix.cord);
	close(fd);
	return (0);
}
