/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_DDA.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:01:47 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/24 20:54:27 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// static void ft_swap(float *dx, float *dy)
// {
// 	float tmp_d;

// 	tmp_d = *dx;
//     *dx = *dy;
//     *dy = tmp_d;
// }

// static void ft_swap_int(int *dx, int *dy)
// {
// 	int tmp_d;

// 	tmp_d = *dx;
//     *dx = *dy;
//     *dy = tmp_d;
// }

// static int ft_abs (int n)
// {
//     return ((n >= 0) ? n : ( n * (-1)));
// }

// static int ft_get_sign(float start, float end)
// {
// 	if (start > end)
// 		return (-1);
// 	if (start < end)
// 		return (1);
// 	return (0);
// }

// /**
//  * Line slope formula
//  * 
//  * m = (x2−x1) / (y2−y1).
//  */
// // static float ft_line_slope(float dx, float dy)
// // {
// // 	printf("%f %f\n", dx, dy);
// // 	return (ft_abs(dy) / ft_abs(dx));
// // }




/**
 * Line slope formula
 * 
 * dx = x2 − x1.
 * dy = y2 - y1.
 */
// static float ft_delta(float start, float end)
// {
// 	return (end - start);
// }

void	ft_draw_line_DDA(t_line_cord line_cord, t_image *img_data)
{
	int i = -1;
    int dx = line_cord.x2 - line_cord.x1;
    int dy = line_cord.y2 - line_cord.y1;
    
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = line_cord.x1;
    float y = line_cord.y1;

    while (++i <= steps) 
	{
		my_mlx_pixel_put(img_data, x, y, 0xff0000);
        x += xIncrement;
        y += yIncrement;
    }
}


