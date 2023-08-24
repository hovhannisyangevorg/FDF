/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:22:22 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/23 19:05:29 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *img_data, int x, int y, int color)
{
	char	*dst;
	
	// printf("x =>[%d] y => [%d] dst =>[%d]\n",x,y,(y * img_data->line_length + x * (img_data->bits_per_pixel / 8)) );
	dst = img_data->addr_ptr + ((y * img_data->line_length) + (x * (img_data->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}
