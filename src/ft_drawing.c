/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:22:22 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/18 14:40:36 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawing(t_point3d dr_cord)
{
	printf("(%d, %d, %d, %d)\n", dr_cord.x, dr_cord.y, dr_cord.z, dr_cord.color);
}