/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:57:29 by gehovhan          #+#    #+#             */
/*   Updated: 2023/01/22 15:59:17 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	c = (unsigned char)c;
	while (n && *ptr != c)
	{
		++ptr;
		--n;
	}
	if (n)
		return ((void *)ptr);
	else
		return (NULL);
}
