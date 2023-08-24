/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/24 15:55:52 by gevorg           ###   ########.fr       */
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
		printf("(%d, %d, ", m->cord[i].x, m->cord[i].y);
		printf("%d, %x)\n", m->cord[i].z, m->cord[i].color);
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
	size_t	i;
	size_t	j;
	int x;
	int zoom = 30;
	int moveX = 10;
	int moveY = 10;
	int y1;
	// (void)mlx_data;
	int x1;

	i = 0;
	j = 0;
	// printf("%ld\n", map->height);
	// printf("%ld\n", map->width);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i + 1 < map->height)
			{
				x = i * map->width + j;
				x1 = (i) * map->width + (j + 1);
				y1 = (i + 1) * map->width + j;
				printf("(%d %d %d)\n", x, x1, y1);
				// ft_bresenham((t_line_cord){map->matrix.cord[x].x * zoom + moveX, map->matrix.cord[x].y * zoom + moveY, map->matrix.cord[x1].x * zoom + moveX, map->matrix.cord[x1].y * zoom + moveY , map->matrix.cord[x1].color}, &mlx_data->img_data);
				ft_bresenham((t_line_cord){map->matrix.cord[x].x * zoom + moveY, map->matrix.cord[x].y * zoom + moveX, map->matrix.cord[y1].x * zoom + moveY, map->matrix.cord[y1].y * zoom + moveX , 0xff0000}, &mlx_data->img_data);
			}
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

int main() 
{
	int		fd;
	t_mlx	mlx_data;
	t_map	map;
	t_add	tab;

	fd = open("maps/42.fdf", O_RDONLY);
	if (fd == -1)
		return (0);
	ft_parse(&map, &tab, fd);
	ft_print_matrix(&map.matrix);
	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
		ft_panic("Minilibx not initialize\n");
    mlx_data.win_ptr = mlx_new_window(mlx_data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	mlx_data.img_data.img_ptr = mlx_new_image(mlx_data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_data.img_data.addr_ptr = mlx_get_data_addr(mlx_data.img_data.img_ptr, &mlx_data.img_data.bits_per_pixel, &mlx_data.img_data.line_length, &mlx_data.img_data.endian);
	mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.win_ptr, mlx_data.img_data.img_ptr, 0, 0);
	// ft_init_mlx(&mlx_data);

	
	// ft_drow2d(&mlx_data, &map);
	ft_bresenham((t_line_cord){10, 10, 400, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 15, 500, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 20, 600, 10, 0x0000bf}, &mlx_data.img_data);

	
	ft_bresenham((t_line_cord){10, 400, 10, 10,  0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);
	ft_bresenham((t_line_cord){10, 10, 100, 10, 0x0000bf}, &mlx_data.img_data);


	mlx_loop(mlx_data.mlx_ptr);
	free(map.matrix.cord);
	close(fd);
	return (0);
}















































// int main() 
// {
//     t_mlx data;
// 	t_image img;
//     data.mlx_ptr = mlx_init();
// 	if (!data.mlx_ptr)
// 		printf("Minilibx not initialize\n");
//     data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Image Drawing");
// 	img.img_ptr = mlx_new_image(data.mlx_ptr, 800, 600);
// 	img.addr_ptr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	
// 	my_mlx_pixel_put(&img, 400, 300, 0xff0000);
	
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img_ptr, 0, 0);
//     mlx_loop(data.mlx_ptr);
//     return 0;
// }