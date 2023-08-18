/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/18 14:52:17 by gehovhan         ###   ########.fr       */
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

	i = -1;
	printf("\n--------------------Arrey------------------------\n");
	while (++i < size){
		
		printf("%ld) Arrey arg %d\n", i, tab->arr[i]);
	}
	printf("\n-------------------------------------------------\n");
}


// int main() 
// {
// 	int		fd;
// 	t_map	map;
// 	t_add	tab;
// 	// t_line_cord d_line = (t_line_cord){10, 10, 0, 10, 55, 0, 0xFFFF};

// 	fd = open("exam.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);

// 	ft_parse(&map, &tab, fd);
// 	// ft_drawing((t_point3d){map.matrix.cord->x, map.matrix.cord->y, map.matrix.cord->z, map.matrix.cord->color});
	
	
// 	// ft_print_arrey(&tab, tab.size);
// 	ft_print_matrix(&map.matrix);
// 	free(map.matrix.cord);
// 	close(fd);
// 	return (0);
// }












#include <mlx.h>

typedef struct	s_data {
    void	*mlx;
    void	*win;
}				t_data;

void ft_drawing_img(t_data *data, int x, int y) {
    mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
}

int main() 
{
    t_data data;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Image Drawing");

    ft_drawing_img(&data, 100, 50);

    mlx_loop(data.mlx);

    return 0;
}