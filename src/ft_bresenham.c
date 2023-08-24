/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:01:47 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/24 16:24:43 by gevorg           ###   ########.fr       */
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

static int ft_abs (int n)
{
    return ((n > 0) ? n : ( n * (-1)));
}

static int ft_get_sign(float delta)
{
	if (delta >= 0)
		return (1);
	else if(delta < 0)
		return (-1);
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
	if (calcul->pk < 0)
	{
		if (!is_swap)
		{
			calcul->x = calcul->x + calcul->sx;
			if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH && calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
				my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
		}
		else
		{
			calcul->y = calcul->y + calcul->sy;
			if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH && calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
				my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
		}
		calcul->pk = calcul->pk + 2 * ft_abs(calcul->dy);
	}
	else
	{
		calcul->x = calcul->x + calcul->sx;
		calcul->y = calcul->y + calcul->sy;
		if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH && calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
			my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
		// printf("%f, %f\n", calcul->x, calcul->y);
		calcul->pk = calcul->pk + 2 * (ft_abs(calcul->dy) - ft_abs(calcul->dx));
	}
}


static void ft_utils(t_calcul_bresen *calcul, t_line_cord line_cord, t_image *img_data, int is_swap)
{
	int i;

	i = -1;
	while (++i <= ft_abs(calcul->dx))
		ft_suport_utils(calcul, line_cord, img_data, is_swap);
}

void ft_bresenham(t_line_cord line_cord, t_image *img_data)
{
	t_calcul_bresen  calcul;
	int			is_swap;

    calcul.x = line_cord.x1;
    calcul.y = line_cord.y1;
	calcul.dx = ft_delta(line_cord.x1, line_cord.x2);
	calcul.dy = ft_delta(line_cord.y1, line_cord.y2);
    calcul.sx = ft_get_sign(calcul.dx);
    calcul.sy = ft_get_sign(calcul.dy);
	// calcul.m =	ft_line_slope(calcul.dx, calcul.dy);
    is_swap	= 0;

	printf("___________________________(%d %d)\n", calcul.sx, calcul.sy);
	printf("___________________________(%d %d)\n", line_cord.x1, line_cord.x2);
    
	if (ft_abs(calcul.dy) > ft_abs(calcul.dx))
    {
		ft_swap(&calcul.dx, &calcul.dy);
        is_swap = 1;
    }
    calcul.pk = 2 * ft_abs(calcul.y) - ft_abs(calcul.dx);
	if (calcul.x >= 0 && calcul.x < SCREEN_WIDTH && calcul.y >= 0 && calcul.y < SCREEN_HEIGHT)
		my_mlx_pixel_put(img_data, calcul.x, calcul.y, line_cord.color);
	ft_utils(&calcul, line_cord, img_data, is_swap);
}
