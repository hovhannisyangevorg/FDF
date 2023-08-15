/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/15 19:23:50 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	ft_print_arrey(t_add *tab, size_t size)
{
	size_t i;

	i = -1;

	while (++i < size){
		
		printf("%ld) Arrey arg %d\n", i, tab->arr[i]);
	}
	
}

int ft_tabcmp(int val1, int val2)
{
	return (val1 - val2);
}

int	ft_set_width(t_add *tab, size_t arr_size)
{
	size_t	i;
	int 	val;
	if (arr_size == 1)
		return(tab->arr[0]);
	i = 0;
	while (tab->size && !tab->arr[i])
		++i;
	val = tab->arr[i];
	while (++i < arr_size)
	{
		if (val && ft_tabcmp(tab->arr[i], tab->arr[i - 1]) && val != ft_tabcmp(tab->arr[i], tab->arr[i - 1]))
		{
			free(tab->arr);
			ft_panic("Error: Invalid map is not square.");
		}
	}
	return (val);
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
	map.width	= ft_set_width(&tab, tab.size);
	map.height	= tab.size;
	ft_decide_x_y(&map);
	

	
	ft_print_matrix(&map.matrix);
	printf("\n________________________________\nWidth = %lu\nHeigth = %lu\n", map.width, map.height);
	free(tab.arr);
	free(map.matrix.cord);
	close(fd);
	return (0);
}




	// printf("\n-----------------------|||\n");
	// printf("%ld", map.matrix.size);
	// printf("\n-----------------------|||\n");



// void	ft_count_line(char *file_name)
// {
// 	int 	fd;
// 	size_t 	line;
	
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		return (0);
	
	
// }