/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:32:59 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/10 18:45:54 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_win(t_main *global)
{
	(void)global;
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

void	ft_clear_window(t_image *img_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img_data, i, j, 0x000000);
			++j;
		}
		++i;
	}
}

void	ft_hook_events(t_main *global)
{
	mlx_hook(global->mlx_data.win_ptr, 17, 1L << 17, ft_close_win, global);
	mlx_hook(global->mlx_data.win_ptr, 2, 1L << 0, ft_key_press, global);
	mlx_hook(global->mlx_data.win_ptr, 3, 1L << 1, ft_key_release, global);
	mlx_hook(global->mlx_data.win_ptr, 4, 1L << 2, ft_mouse_press, global);
	mlx_hook(global->mlx_data.win_ptr, 5, 1L << 3, ft_mouse_release, global);
	mlx_hook(global->mlx_data.win_ptr, 6, 1L << 6, ft_mouse_move, global);
}
