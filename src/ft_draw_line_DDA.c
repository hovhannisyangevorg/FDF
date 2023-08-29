/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_DDA.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:01:47 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/27 13:00:02 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

/**
 * Draws a line using the Digital Differential Analyzer (DDA) algorithm.
 *
 * This function draws a line between two endpoints specified in the `line_cord` struct
 * on the image data provided by `img_data`.
 * The line is drawn using the DDA algorithm, ensuring a smooth representation.
 *
 * @param line_cord  A struct containing the line's coordinates (x1, y1) and (x2, y2),
 *                   and the line's color.
 * @param img_data   A pointer to the image data where the line will be drawn.
 *
 * @warning This function does not perform input validation, so ensure that the provided
 *          endpoint coordinates are within the bounds of the image data.
 */
void	ft_draw_line_DDA(t_line_cord line_cord, t_image *img_data)
{
	int i;
	t_dda calcul;
	float x_increment;
	float y_increment;

	calcul.x = line_cord.x1;
	calcul.y = line_cord.y1;
	calcul.dx = ft_delta(line_cord.x1, line_cord.x2);
	calcul.dy = ft_delta(line_cord.y1, line_cord.y2);
	if (abs(calcul.dx) > abs(calcul.dy))
		calcul.steps = abs(calcul.dx);
	else
		calcul.steps = abs(calcul.dy);
	x_increment = (float)calcul.dx / calcul.steps;
	y_increment = (float)calcul.dy / calcul.steps;
	i = -1;
	while (++i <= calcul.steps)
	{
		if ((calcul.x >= 0 && calcul.x < SCREEN_WIDTH) && (calcul.y >= 0 && calcul.y < SCREEN_HEIGHT))
		my_mlx_pixel_put(img_data, calcul.x, calcul.y, line_cord.color);
		calcul.x += x_increment;
		calcul.y += y_increment;
	}
}


