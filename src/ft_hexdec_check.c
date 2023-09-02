/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdec_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:54:00 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/03 01:07:14 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_strhex(char **de_token, char **hx_token)
{
	int	i;
	int	len;
	int	result;

	i = 0;
	result = 0;
	len = ft_strlen(*hx_token);
	if (!(len > 2 && (*hx_token)[i++] == '0'
		&& (*hx_token)[i++] == 'x') || len > 8)
		ft_free_utils(INVALID_COLOR, de_token, hx_token);
	while (i < len)
	{
		result <<= 4;
		if ((*hx_token)[i] >= '0' && (*hx_token)[i] <= '9')
			result += (*hx_token)[i] - '0';
		else if ((*hx_token)[i] >= 'A' && (*hx_token)[i] <= 'F')
			result += (*hx_token)[i] - 'A' + 10;
		else if ((*hx_token)[i] >= 'a' && (*hx_token)[i] <= 'f')
			result += (*hx_token)[i] - 'a' + 10;
		else
			ft_free_utils(INVALID_COLOR, de_token, hx_token);
		i++;
	}
	return (result);
}

int	ft_hexdec_check(char **de_token, char **hx_token)
{
	int	color;

	color = 0;
	if (!hx_token || !*hx_token || !**hx_token)
	{
		color = DEFAULT_COLOR;
		return (color);
	}
	else
	{
		color = ft_strhex(de_token, hx_token);
		return (color);
	}
}
