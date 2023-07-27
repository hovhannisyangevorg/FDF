/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:16:15 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/23 14:22:23 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_free()
// {
	
// }

void	ft_init(t_matrix *m, size_t size)
{
	if (!m)
		return ;
	m->size = size;
	m->capacity = size;
	m->cord = 0;
	if (size)
	{
		m->cord = (t_point3d *)malloc(sizeof(t_point3d) * size);
		if (!m->cord)
			return ;
	}
}

void	ft_update_capacity(t_matrix *m, size_t size)
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

// TODO: [Remove this function for fdf projects. ft_print_matrix]
void	ft_print_matrix(t_matrix *m)
{
	size_t	i;
	size_t print_count;

	i = 0;
	print_count = 0;
	while (i < m->size)
	{
		printf ("%zu). ", ++print_count);
		printf ("(%d, %d, ", m->cord[i].x, m->cord[i].y);
		printf ("%d, %x)\n", m->cord[i].z, m->cord[i].color);
		i++;
	}
}
