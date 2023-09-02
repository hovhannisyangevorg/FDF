/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:16:59 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/01 20:47:29 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3d ft_rotate_x(t_point3d cord, double angle)
{
	double theta = ft_deg_to_rad(angle);
	t_transform matrix[3];

	t_point3d res = cord;
	matrix[0] = (t_transform){1, 0, 0};
	matrix[1] = (t_transform){0, cos(theta), -sin(theta)};
	matrix[2] = (t_transform){0, sin(theta), cos(theta)};

	res.x = (res.x * matrix[0].x) + (res.y * matrix[0].y) + (res.z * matrix[0].z);
	res.y = (res.y * matrix[1].x) + (res.y * matrix[1].y) + (res.z * matrix[1].z);
	res.z = (res.z * matrix[2].x) + (res.y * matrix[2].y) + (res.z * matrix[2].z);
	return (res);
}
t_point3d ft_rotate_y(t_point3d cord, double angle)
{
	double theta = ft_deg_to_rad(angle);
	t_transform matrix[3];

	t_point3d res = cord;
	matrix[0] = (t_transform){cos(theta), 	0, sin(theta)	};
	matrix[1] = (t_transform){0, 			1, 		0		};
	matrix[2] = (t_transform){-sin(theta), 	0, cos(theta)	};

	res.x = (res.x * matrix[0].x) + (res.y * matrix[0].y) + (res.z * matrix[0].z);
	res.y = (res.y * matrix[1].x) + (res.y * matrix[1].y) + (res.z * matrix[1].z);
	res.z = (res.z * matrix[2].x) + (res.y * matrix[2].y) + (res.z * matrix[2].z);
	return (res);
}
t_point3d ft_rotate_z(t_point3d cord, double angle)
{
	double theta = ft_deg_to_rad(angle);
	t_transform matrix[3];

	t_point3d res = cord;
	matrix[0] = (t_transform){cos(theta), 	-sin(theta),  0	};
	matrix[1] = (t_transform){sin(theta), 	cos(theta),	  0	};
	matrix[2] = (t_transform){0,				0,		  1	};

	res.x = (res.x * matrix[0].x) + (res.y * matrix[0].y) + (res.z * matrix[0].z);
	res.y = (res.y * matrix[1].x) + (res.y * matrix[1].y) + (res.z * matrix[1].z);
	res.z = (res.z * matrix[2].x) + (res.y * matrix[2].y) + (res.z * matrix[2].z);
	return (res);
}