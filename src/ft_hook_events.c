/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:32:59 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/05 14:20:04 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_close_win(__attribute_maybe_unused__ t_main* global)
{
	exit(0);
	return (0);
}


int	ft_key_press(int key, t_main *global)
{
	if (key == KEY_ESC)
		ft_close_win(global);
	if (key == KEY_W)
		global->key_conf.w = PRESS;
	if (key == KEY_A)
		global->key_conf.a = PRESS;
	if (key == KEY_S)
		global->key_conf.s = PRESS;
	if (key == KEY_D)
		global->key_conf.d = PRESS;
	if (key == KEY_UP)
		global->key_conf.w = PRESS;
	if (key == KEY_DOWN)
		global->key_conf.a = PRESS;
	if (key == KEY_LEFT)
		global->key_conf.s = PRESS;
	if (key == KEY_RIGHT)
		global->key_conf.d = PRESS;
	return (0);
}

int	ft_key_release(int key, t_main *global)
{
	// printf("key: %d\n", key);
	if (key == KEY_W)
		global->key_conf.w = RELEASE;
	if (key == KEY_A)
		global->key_conf.a = RELEASE;
	if (key == KEY_S)
		global->key_conf.s = RELEASE;
	if (key == KEY_D)
		global->key_conf.d = RELEASE;
	if (key == KEY_UP)
		global->key_conf.w = RELEASE;
	if (key == KEY_DOWN)
		global->key_conf.a = RELEASE;
	if (key == KEY_LEFT)
		global->key_conf.s = RELEASE;
	if (key == KEY_RIGHT)
		global->key_conf.d = RELEASE;
	return (0);
}
// void	ft_key_release(int key, t_main *global){}
// void	ft_mouse_press(int key, int x, int y, t_main* global){}
// void	ft_mouse_release(int key, int x, int y, t_main* global){}
// void	ft_mouse_move(int x, int y, t_main* global){}

int go( __attribute_maybe_unused__ t_main* global)
{
	// printf("1");
	// printf("w is %d\n", global->key_conf.w);
	// printf("a is %d\n", global->key_conf.w);
	// printf("s is %d ", global->key_conf.w);
	// printf("d is %d ", global->key_conf.w);
	return (0);
}

void ft_hook_events(t_main *global)
{
	// mlx_loop_hook(global->mlx_data.mlx_ptr, go, global);


	mlx_hook(global->mlx_data.win_ptr, 17, 1L << 17, ft_close_win,  &global);
	mlx_hook(global->mlx_data.win_ptr, 2, 1L << 2, ft_key_press,  &global);


























	
	// mlx_hook(global.mlx_data.win_ptr, 3, 1L << 3, ft_key_release,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 4, 1L << 4, ft_mouse_press,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 5, 1L << 5, ft_mouse_release,  &global);
	// mlx_hook(global.mlx_data.win_ptr, 6, 1L << 6, ft_mouse_move,  &global);
	
}
