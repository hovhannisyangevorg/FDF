/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:32:59 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/05 23:24:04 by gevorg           ###   ########.fr       */
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
	// printf("key press: %d\n", KEY_W);
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
	// printf("key release: %d\n", KEY_W);
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











int	ft_mouse_press(int key, int x, int y, t_main* global)
{
	(void)global;
	printf("Mouse button %d pressed at (%d, %d)\n", key, x, y);
	return(0);
}

int	ft_mouse_release(int key, int x, int y, t_main* global)
{
	(void)global;
	printf("Mouse button %d released at (%d, %d)\n", key, x, y);
	return(0);
}

int	ft_mouse_move(int x, int y, t_main* global)
{
	(void)global;
	(void)(x+y);
	// printf("Mouse moved to (%d, %d)\n", x, y);
	return(0);
}


void ft_clear_window(t_image* img_data)
{
	int i = 0;
	while (i < SCREEN_WIDTH)
	{
		int j = 0;
		while(j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img_data, i, j, 0x000000);
			++j;
		}
		++i;
	}
	
}

// int i = 0;
int go(t_main* global)
{

	ft_config(&global->map_data, global->config);
	ft_change_projection(&global->map_data, global->config);
	ft_drow2d(&global->mlx_data, &global->map_data);
	mlx_put_image_to_window(global->mlx_data.mlx_ptr, global->mlx_data.win_ptr, global->mlx_data.img_data.img_ptr, 0, 0);
	// (void)global;
	// ft_clear_window(&global->mlx_data.img_data);
	// if (global->key_conf.w)
	// {
	// 	// printf("0\n");
	// 	// ++i;
	// 	// printf("\n1: %d\n", global->config.y_move);
	// 	global->config.y_move += 3;
	// 	printf("\n%d\n", global->config.y_move);
	// }
	// else{
	// 	// printf("1\n");
	// }
	// ft_config(&global->map_data, global->config);
	// ft_change_projection(&global->map_data, global->config);
	// ft_drow2d(&global->mlx_data, &global->map_data);
	// mlx_put_image_to_window(global->mlx_data.mlx_ptr, global->mlx_data.win_ptr, global->mlx_data.img_data.img_ptr, 0, 0); //
	// mlx_do_sync(global->mlx_data.mlx_ptr);
	return (0);
}

void ft_hook_events(t_main *global)
{

	mlx_hook(global->mlx_data.win_ptr, 17, 1L << 17, ft_close_win,  global);
	mlx_hook(global->mlx_data.win_ptr, 2, 1L << 0, ft_key_press,  global);
	mlx_hook(global->mlx_data.win_ptr, 3, 1L << 1, ft_key_release,  global);
	mlx_hook(global->mlx_data.win_ptr, 4, 1L << 2, ft_mouse_press,  global);
	mlx_hook(global->mlx_data.win_ptr, 5, 1L << 3, ft_mouse_release,  global);
	mlx_hook(global->mlx_data.win_ptr, 6, 1L << 6, ft_mouse_move,  global);
	mlx_loop_hook(global->mlx_data.mlx_ptr, go, global);
	// mlx_loop(global->mlx_data.mlx_ptr);
}
