/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/16 17:54:42 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include <stdint.h>
// #include <math.h>

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



int main() 
{
	int		fd;
	t_map	map;
	t_add	tab;

	fd = open("exam.txt", O_RDONLY);
	if (fd == -1)
		return (0);

	ft_parse(&map, &tab, fd);
	ft_print_arrey(&tab, tab.size);
	ft_print_matrix(&map.matrix);
	
	
	free(tab.arr);
	free(map.matrix.cord);
	close(fd);
	return (0);
}
