/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:32:59 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/03 02:40:11 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_close_win(__attribute_maybe_unused__ t_main* global)
{
	// if (global->mlx_data.mlx_ptr && global->mlx_data.img_data.img_ptr)
		// mlx_destroy_image(global->mlx_data.mlx_ptr, global->mlx_data.img_data.img_ptr);
	// if (global->mlx_data.mlx_ptr && global->mlx_data.win_ptr)
		// mlx_destroy_window(global->mlx_data.mlx_ptr, global->mlx_data.win_ptr);
	exit(0);
	return (0);
}


// void	ft_key_press(int key, t_main *global){}
// void	ft_key_release(int key, t_main *global){}
// void	ft_mouse_press(int key, int x, int y, t_main* global){}
// void	ft_mouse_release(int key, int x, int y, t_main* global){}
// void	ft_mouse_move(int x, int y, t_main* global){}


void ft_hook_events(t_main *global)
{
	// mlx_loop_hook(global->mlx_data.mlx_ptr, draw, global);
	mlx_hook(global->mlx_data.win_ptr, 17, 1L << 17, ft_close_win,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 2, 1L << 2, ft_key_press,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 3, 1L << 3, ft_key_release,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 4, 1L << 4, ft_mouse_press,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 5, 1L << 5, ft_mouse_release,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 6, 1L << 6, ft_mouse_move,  &global);
	
}
