/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:45 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/08 15:06:12 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_sign(int start, int end)
{
	if (end >= start)
		return (1);
	return (-1);
}

/**
 * Line slope formula
 * 
 * dx = x2 − x1.
 * dy = y2 - y1.
 */
int	ft_delta(int start, int end)
{
	return (end - start);
}

static void	draw_high(t_calcul_bresen *calcul, t_line_cord line_cord,
	t_image *img_data)
{
	int	i;

	i = -1;
	while (++i <= calcul->dy)
	{
		if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH
			&& calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
			my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
		if (calcul->pk > 0)
		{
			calcul->x += calcul->sx;
			calcul->pk += 2 * (calcul->dx - calcul->dy);
		}
		else
			calcul->pk += 2 * calcul->dx;
		calcul->y += calcul->sy;
	}
}

static void	draw_low(t_calcul_bresen *calcul,
	t_line_cord line_cord, t_image *img_data)
{
	int	i;

	i = -1;
	while (++i <= calcul->dx)
	{
		if (calcul->x >= 0 && calcul->x < SCREEN_WIDTH
			&& calcul->y >= 0 && calcul->y < SCREEN_HEIGHT)
			my_mlx_pixel_put(img_data, calcul->x, calcul->y, line_cord.color);
		if (calcul->pk > 0)
		{
			calcul->y += calcul->sy;
			calcul->pk += 2 * (calcul->dy - calcul->dx);
		}
		else
			calcul->pk += 2 * calcul->dy;
		calcul->x += calcul->sx;
	}
}

void	ft_bresenham(t_line_cord line_cord, t_image *img_data)
{
	t_calcul_bresen	calcul;

	calcul.x = line_cord.x1;
	calcul.y = line_cord.y1;
	calcul.dx = abs(ft_delta(line_cord.x1, line_cord.x2));
	calcul.dy = abs(ft_delta(line_cord.y1, line_cord.y2));
	calcul.sx = ft_get_sign(line_cord.x1, line_cord.x2);
	calcul.sy = ft_get_sign(line_cord.y1, line_cord.y2);
	if (calcul.dx > calcul.dy)
		calcul.pk = 2 * calcul.dy - calcul.dx;
	else
		calcul.pk = 2 * calcul.dx - calcul.dy;
	if (calcul.dx > calcul.dy)
		draw_low(&calcul, line_cord, img_data);
	else
		draw_high(&calcul, line_cord, img_data);
}
