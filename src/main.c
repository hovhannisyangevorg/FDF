/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/12 20:46:28 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: [ White or delete ft_strtok function my libft project ]
int main() 
{
	t_map map;
	char *token;
	int flag;
	
	int fd = open("exam.txt", O_RDONLY);
	if (fd == -1)
		return (0);

	ft_init(&map, 0);
	flag = 0;
	map.height = 0;
	map.width = 0;
	while ((token = get_next_word(fd, &map.height)))
	{
		if (map.height == 1 && flag == 0)
		{
			flag = 1;
			map.width = map.matrix.size;
		}
		ft_parse_data(token, map.width, map.height, &map.matrix);
		free(token);
	}
	ft_decide_x(&map);
	ft_print_matrix(&map.matrix);
	printf("Width = %lu\nHeigth = %lu\n", map.width, map.height);
	close(fd);
	return (0);
}







	// printf("%lu %lu\n", map.matrix.capacity, map.matrix.size);
	// printf("%lu %lu\n", map.height, map.width);
	// printf("%lu %lu\n", map.matrix, map.matrix.size);



// int main(int ac, char **av)
// {
// 	(void)av	;
// 	// t_point3d *point = (t_point3d*)malloc();
// 	if (ac > 2)
// 		ft_panic("error: Type <Anasun error.>");
// 	printf("___Start___\n");
// 	// ft_map_parser(av[1]);
// 	return (0);
// }
