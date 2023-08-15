/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:26 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/15 22:34:44 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen_start(const char *str, int start, char c)
{
	int	len;

	len = 0;
	while (str && str[start] != '\0' && str[start] != c)
	{
		++start;
		len++;
	}
	return (len);
}

int	ft_setindex(char *token, int c)
{
	int	i;

	i = 0;
	if (!token)
		return (0);
	while (token && token[i] && token[i] != c)
		i++;
	if (token[i] != '\0')
		++i;
	return (i);
}
