/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:26:32 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/08 15:15:26 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_deg_to_rad(double angle)
{
	return ((M_PI / 180) * angle);
}

/**
 * Isometric projection formula.
 * 
 * T = 30:
 * x′ = (x − z) * cos(T):
 * y′ = y + (x + z) * sin(T):
 * */
void	ft_isometric(t_point3d *cord, t_conf conf)
{
	double	x;
	double	pr_z;
	double	t;

	x = cord->x;
	pr_z = cord->y;
	t = ft_deg_to_rad(30);
	cord->x = conf.x_move + ((cord->x - pr_z) * cos(t));
	cord->y = (conf.y_move - cord->z) + ((x + pr_z) * sin(t));
}

/**
 * Dimetric projection formula.
 * 
 * T = 15:
 * x′= x + n ⋅ z ⋅ cos(T):
 * y′= y + n ⋅ z ⋅ sin(T):
 */
void	ft_dimetric(t_point3d *cord, t_conf conf)
{
	double	t;
	double	n;
	double	x;
	double	pr_z;

	t = ft_deg_to_rad(15);
	n = (double)SCREEN_WIDTH / SCREEN_HEIGHT;
	x = cord->x;
	pr_z = cord->y;
	cord->x = conf.x_move + (cord->x - (n * pr_z) * cos(t));
	cord->y = conf.y_move - cord->z + (x + n * pr_z) * sin(t);
}

/**
 * Trimetric projection formula.
 * T = -45
 * 
 * x' = x * cos(θ) - y * sin(θ)
 * y' = x * sin(θ) + z * cos(θ)
 */
void	ft_trimetric(t_point3d *cord, t_conf conf)
{
	double	t;
	double	x;
	double	pr_z;

	t = ft_deg_to_rad(-45);
	x = cord->x;
	pr_z = cord->y;
	cord->x = conf.x_move + ((cord->x * cos(t)) - (cord->y * sin(t)));
	cord->y = conf.y_move - cord->z + ((x * sin(t)) + (pr_z * cos(t)));
}

void	ft_change_projection(t_map *map, t_conf conf)
{
	size_t	i;

	i = -1;
	while (++i < map->matrix.size)
	{
		if (conf.projection == ISOMETRIC)
			ft_isometric(&map->matrix.cord[i], conf);
		else if (conf.projection == DIAMETRIC)
			ft_dimetric(&map->matrix.cord[i], conf);
		else if (conf.projection == TRIMETRIC)
			ft_trimetric(&map->matrix.cord[i], conf);
	}
}
