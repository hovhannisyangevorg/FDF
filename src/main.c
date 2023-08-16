/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/16 03:08:51 by gevorg           ###   ########.fr       */
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
	while (i < m->size)
	{
		printf("%zu). ", ++print_count);
		printf("(%d, %d, ", m->cord[i].x, m->cord[i].y);
		printf("%d, %x)\n", m->cord[i].z, m->cord[i].color);
		i++;
	}
}

/*
TODO: [Remove this function for fdf projects. ft_print_arrey()]
*/
void	ft_print_arrey(t_add *tab, size_t size)
{
	size_t i;

	i = -1;

	while (++i < size){
		
		printf("%ld) Arrey arg %d\n", i, tab->arr[i]);
	}
	
}
		
// TODO: [ White or delete ft_strtok function my libft project ]
int main() 
{
	t_map map;
	t_add tab;
	size_t temp;
	char *token;
	
	int fd = open("exam.txt", O_RDONLY);
	if (fd == -1)
		return (0);

	ft_init(&map, 0);
	ft_init_arrey(&tab, 0);
	temp		= 0;
	map.height 	= 0;
	map.width 	= 0;
	while ((token = get_next_word(fd, &map.height)))
	{
		if (map.height > temp)
		{
			if (map.matrix.size)
				ft_push_arrey(&tab, map.matrix.size);
			temp = map.height;
		}
		ft_parse_data(token, &map.matrix);
		free(token);
	}
	ft_push_arrey(&tab, map.matrix.size);
	// ft_print_arrey(&tab, tab.size);
	map.width	= ft_determine_width(&tab, tab.size);
	map.height	= tab.size;
	ft_decide_x_y(&map);
	

	
	ft_print_matrix(&map.matrix);
	printf("\n________________________________\nWidth = %lu\nHeigth = %lu\n", map.width, map.height);
	free(tab.arr);
	free(map.matrix.cord);
	close(fd);
	return (0);
}
