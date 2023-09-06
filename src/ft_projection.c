/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:26:32 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/05 23:05:26 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


double ft_deg_to_rad(double angle)                  
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
void ft_isometric(t_point3d *cord, t_conf conf)                      
{
	double x;
	double pr_z;
	double T;
	
	x = cord->x;
	pr_z = cord->y;
	T = ft_deg_to_rad(30);
	cord->x = conf.x_move + ((cord->x - pr_z) * cos(T));
	cord->y = (conf.y_move - cord->z) + ((x + pr_z) * sin(T));
}


/**
 * Dimetric projection formula.
 * 
 * T = 15:
 * x′= x + n ⋅ z ⋅ cos(T):
 * y′= y + n ⋅ z ⋅ sin(T):
 */ 
void ft_dimetric(t_point3d *cord, t_conf conf)                         
{
	double T;
	double n;
	double x;
	double pr_z;

	T = ft_deg_to_rad(15);
	n = (double)SCREEN_WIDTH / SCREEN_HEIGHT;
	x = cord->x;
	pr_z = cord->y;
	cord->x = conf.x_move + (cord->x - (n * pr_z) * cos(T));
	cord->y = conf.y_move - cord->z + (x + n * pr_z) * sin(T);
}

/**
 * Trimetric projection formula.
 * T = -45
 * 
 * x' = x * cos(θ) - y * sin(θ)
 * y' = x * sin(θ) + z * cos(θ)
 */ 
void ft_trimetric(t_point3d *cord, t_conf conf)                  
{
	double T;
	double x;
	double pr_z;

	T = ft_deg_to_rad(-45);
	x = cord->x;
	pr_z = cord->y;
	cord->x = conf.x_move + ((cord->x * cos(T)) - (cord->y * sin(T)));
	cord->y = conf.y_move - cord->z + ((x * sin(T)) + (pr_z * cos(T)));
}

void	ft_change_projection(t_map *map, t_conf conf)                      
{
	printf("y_move: %d\n", conf.y_move);
	size_t i;

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

