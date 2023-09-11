/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:10 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/11 22:16:10 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_has_exten(char *filename, char *exten)
{
	char	*file_exten;

	file_exten = ft_strchr(filename, '.');
	if (file_exten != NULL)
		return ((ft_strcmp(file_exten, exten) == 0));
	return (0);
}

static void	ft_check_exten(int ac, char *filename, char *exten)
{
	if (ac != 2 || !ft_has_exten(filename, exten))
		ft_panic("Error: Invalid file argument.");
}

int	main(int ac, char **av)
{
	int		fd;
	t_main	global;

	ft_check_exten(ac, av[1], ".fdf");
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
	return (0);
}
