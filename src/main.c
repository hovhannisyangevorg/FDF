/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/23 16:54:22 by gevorg           ###   ########.fr       */
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
	int x1;

	i = 0;
	j = 0;
	printf("%ld\n", map->height);
	printf("%ld\n", map->width);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x = i * map->width + j;
			x1 = (i + 1) * map->width + j;
			if (i + 1 < map->height)
				ft_bresenham((t_line_cord){map->matrix.cord[x].x, map->matrix.cord[x].y, map->matrix.cord[x1].x, map->matrix.cord[x1].y , map->matrix.cord[x].color}, mlx_data->img_data.img_ptr);
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

	fd = open("exam.txt", O_RDONLY);
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
	ft_drow2d(&mlx_data, &map);


	// ft_bresenham((t_line_cord){25, 25, 100, 25, 0x0000bf}, &mlx_data.img_data);


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