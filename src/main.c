/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/08 22:19:30 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_main	global;

	if (ac == 2)
	{
			fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		ft_parse(&global.map_data, &global.tab_data, fd);
		ft_init_mlx(&global.mlx_data);
		ft_init_config(&global.config);
		ft_key_config(&global.key_conf);
		ft_config(&global.map_data, global.config);
		ft_change_projection(&global.map_data, global.config);
		ft_drow2d(&global.mlx_data, &global.map_data);
		mlx_put_image_to_window(global.mlx_data.mlx_ptr, \
			global.mlx_data.win_ptr, global.mlx_data.img_data.img_ptr, 0, 0);
		ft_hook_events(&global);
		mlx_loop(global.mlx_data.mlx_ptr);
		free(global.map_data.matrix.cord);
		close(fd);
	}
	return (0);
}
