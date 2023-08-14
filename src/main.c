/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/15 00:07:45 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_arrey(t_add *tab, size_t size)
{
	size_t i;

	i = -1;

	while (++i < size)
		printf("Arrey arg %d\n", tab->arr[i]);
	
}

int ft_tabcmp(int val1, int val2)
{
	return (val1 - val2);
}

int	ft_set_width(t_add *tab, size_t arr_size)
{
	size_t	i;
	// if (!tab)
	// 	return (0);
	i = 1;
	while (i < arr_size)
	{
		if (ft_tabcmp(tab->arr[i - 1], tab->arr[i]))
		{
			free(tab->arr);
			ft_panic("Error: Map is not square");
		}else
			return (tab->arr[0]);
		i++;
	}
	return (0);
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
	map.height 	= 0;
	temp		= 0;
	map.width 	= 0;
	
	while ((token = get_next_word(fd, &map.height)))
	{
		if (map.height > temp)
		{
			ft_push_arrey(&tab, map.matrix.size);
			temp = map.height;
		}
		ft_parse_data(token, map.width, map.height, &map.matrix);
		free(token);
	}
	// if (tab.arr[tab.size - 1] == (int)tab.size)
	// ft_push_arrey(&tab, map.matrix.size);
		
	ft_decide_x(&map);
	ft_print_arrey(&tab, tab.size);
	// map.width 	= ft_set_width(&tab, map.matrix.size);
	// printf("\n-----------------------|||\n");
	// printf("%ld", map.matrix.size);
	// printf("\n-----------------------|||\n");

	
	// ft_print_matrix(&map.matrix);
	printf("Width = %lu\nHeigth = %lu\n", map.width, map.height);
	free(tab.arr);
	close(fd);
	return (0);
}
