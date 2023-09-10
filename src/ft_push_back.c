/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:16:15 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/08 17:44:33 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_map *map, size_t size)
{
	if (!map)
		return ;
	map->height = 0;
	map->width = 0;
	map->matrix.size = size;
	map->matrix.capacity = size;
	map->matrix.cord = 0;
	if (size)
	{
		map->matrix.cord = (t_point3d *)malloc(sizeof(t_point3d) * size);
		if (!map->matrix.cord)
			return ;
	}
}

static void	ft_update_capacity(t_matrix *m, size_t size)
{
	size_t		i;
	size_t		new_cap;
	t_point3d	*tmp;

	new_cap = m->capacity;
	if (!m->capacity)
		new_cap = size;
	else if (m->capacity <= size)
		new_cap *= 2;
	i = 0;
	if (new_cap != m->capacity)
	{
		tmp = (t_point3d *)malloc(sizeof(t_point3d) * new_cap);
		if (!tmp)
			return ;
		while (i < m->size)
		{
			tmp[i] = m->cord[i];
			i++;
		}
		if (m->cord)
			free(m->cord);
		m->cord = tmp;
		m->capacity = new_cap;
	}
}

void	ft_push_back(t_matrix *m, t_point3d val)
{
	if (!m)
		return ;
	ft_update_capacity(m, m->size + 1);
	m->cord[m->size] = val;
	++m->size;
}
