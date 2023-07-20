/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:12:11 by gehovhan          #+#    #+#             */
/*   Updated: 2023/01/23 16:12:13 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	while (i < (count * size))
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
