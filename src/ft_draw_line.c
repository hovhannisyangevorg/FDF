/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:01:47 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/16 03:27:42 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_drawing(t_point3d dr_cord)
// {
// 	printf("(%d, %d, %d, %d)\n", dr_cord.x, dr_cord.y, dr_cord.z, dr_cord.color);
// }

static int ft_distance(t_distance_formula *dist)
{
    return ((int)sqrt(pow(dist->dx, 2) + pow(dist->dy, 2) + pow(dist->dz, 2)));
}

void ft_draw_line(t_line_cord *cord)
{
	t_distance_formula dist;
	int x_end;
	int i1;
	int i2;

	dist.dx = (cord->x2 - cord->x1);
	dist.dy = (cord->y2 - cord->y1);
	dist.dz = (cord->z2 - cord->z1);
	dist.d  = ft_distance(&dist);
	i1 = (2 * dist.dy);
	i2 = (2 * (dist.dy - dist.dx));

	if (dist.dx < 0)
	{
		dist.x = cord->x2;
		dist.y = cord->y2;
		dist.z = cord->z2;
		x_end = cord->x1;
	}
	else
	{
		dist.x = cord->x1;
		dist.y = cord->y1;
		dist.z = cord->z1;
		x_end = cord->x2;
	}
	while (dist.x < x_end)
	{
		if (dist.d < 0)
			dist.d += i1;
		else
		{
			dist.d += i2;
			dist.y++;
		}
		dist.x++;
		dist.z++;
		ft_drawing((t_point3d){dist.x, dist.y, dist.z, cord->color});
	}
}
