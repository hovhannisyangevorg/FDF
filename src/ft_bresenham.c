/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:01:47 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/24 19:23:46 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void ft_swap(float *dx, float *dy)
{
	float tmp_d;

	tmp_d = *dx;
    *dx = *dy;
    *dy = tmp_d;
}

static void ft_swap_int(int *dx, int *dy)
{
	int tmp_d;

	tmp_d = *dx;
    *dx = *dy;
    *dy = tmp_d;
}

static int ft_abs (int n)
{
    return ((n >= 0) ? n : ( n * (-1)));
}

static int ft_get_sign(float start, float end)
{
	if (start > end)
		return (-1);
	if (start < end)
		return (1);
	return (0);
}

/**
 * Line slope formula
 * 
 * m = (x2−x1) / (y2−y1).
 */
// static float ft_line_slope(float dx, float dy)
// {
// 	printf("%f %f\n", dx, dy);
// 	return (ft_abs(dy) / ft_abs(dx));
// }

/**
 * Line slope formula
 * 
 * dx = x2 − x1.
 * dy = y2 - y1.
 */
static float ft_delta(float start, float end)
{
	return (end - start);
}



static void ft_suport_utils(t_calcul_bresen *calcul, t_line_cord line_cord, t_image *img_data, int is_swap)
{
	if (!is_swap)
	{
		if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH && calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
			my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
	}
	else
	{
		if (calcul->x >= 0 && calcul->x < SCREEN_HEIGHT && calcul->y >= 0 && calcul->y < SCREEN_WIDTH)
			my_mlx_pixel_put(img_data, calcul->y, calcul->x, line_cord.color);
	}
	if (calcul->pk > 0)
	{
		calcul->x += calcul->sx;
		calcul->pk += 2 * (calcul->dx - calcul->dy);
		
		// if (!is_swap)
		// {
			// calcul->x = calcul->x + calcul->sx;
			// if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH && calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
		// }
		// else
		// {
			// calcul->y = calcul->y + calcul->sy;
				// my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
		// }
		// calcul->pk = calcul->pk + 2 * ft_abs(calcul->dy);
	}
	else
	{
			// printf("\nswapped\n");
		// calcul->x = calcul->x + calcul->sx;
		// calcul->y = calcul->y + calcul->sy;
		// if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH && calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
		// 	my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
		// printf("%f, %f\n", calcul->x, calcul->y);
		calcul->pk += 2 * (calcul->dx);
	}
	calcul->y += calcul->sy;
}


static void ft_utils(t_calcul_bresen *calcul, t_line_cord line_cord, t_image *img_data, int is_swap)
{
	int i;

	i = -1;
	printf("(%f %f)\n", calcul->dx, calcul->dy);
	while (++i <= calcul->dy)
	{	
		ft_suport_utils(calcul, line_cord, img_data, is_swap);
	}
}

void ft_bresenham(t_line_cord line_cord, t_image *img_data)
{
	t_calcul_bresen  calcul;
	int			is_swap;

    calcul.x = line_cord.x1;
    calcul.y = line_cord.y1;
	calcul.dx = ft_abs(ft_delta(line_cord.x1, line_cord.x2));
	calcul.dy = ft_abs(ft_delta(line_cord.y1, line_cord.y2));
    calcul.sx = ft_get_sign(line_cord.x1, line_cord.x2);
    calcul.sy = ft_get_sign(line_cord.y1, line_cord.y2);
    is_swap	= 0;
    
	/**
 	* Line slope formula
 	* 
 	* m =  (y2−y1) / (x2−x1).
 	*/
	printf("(%f %f)\n", calcul.dx, calcul.dy);
	if (calcul.dy < calcul.dx)
    {
		ft_swap(&calcul.dx, &calcul.dy);
		ft_swap(&calcul.x, &calcul.y);
		ft_swap_int(&calcul.sx, &calcul.sy);
        is_swap = 1;
    }
    calcul.pk = 2 * calcul.dx - calcul.dy;
	// if (calcul.x >= 0 && calcul.x < SCREEN_WIDTH && calcul.y >= 0 && calcul.y < SCREEN_HEIGHT)
	// 	my_mlx_pixel_put(img_data, calcul.x, calcul.y, line_cord.color);
	ft_utils(&calcul, line_cord, img_data, is_swap);
}
