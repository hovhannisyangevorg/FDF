/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_arrey.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:43:26 by gevorg            #+#    #+#             */
/*   Updated: 2023/08/14 23:29:51 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_tabcpy_util(int *tab1, int *tab2, size_t size)
{
	size_t  i;
	if (!tab1)
		return ;
	if (!tab2)
		return ;
	i = 0;
	while (i < size)
	{
		tab1[i] = tab2[i];
		i++;
    }
}

void ft_init_arrey(t_add *tab, size_t size)
{
	if (!tab)
		return ;
	tab->size = size;
	tab->capacity = size;
	tab->arr = 0;
	if (size)
	{
		tab->arr = (int *)malloc(sizeof(int) * size);
		ft_memset(tab->arr, 0, (sizeof(int)));
		if (!tab->arr)
			return ;
	}
}

static void	ft_update_capacity_arrey(t_add *tab)
{
	int 	*new_tab;
	size_t 	new_cap;
	if (!tab)
		return ;
	new_cap = tab->capacity;
	if (!new_cap)
		new_cap = 1;
	else if (tab->size + 1 >= new_cap)
		new_cap *= 2;
	if (new_cap != tab->capacity)
	{
		new_tab = (int *)malloc(sizeof(int) * new_cap);
		ft_tabcpy_util(new_tab, tab->arr, tab->size);
		if (tab->arr)
			free(tab->arr);
		tab->arr = new_tab;
		tab->capacity = new_cap;
	}
}

void ft_push_arrey(t_add *tab, int val)
{
	if (!tab)
		return ;
	ft_update_capacity_arrey(tab);
	tab->arr[tab->size] = val;
	tab->size++;
}
