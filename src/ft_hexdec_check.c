/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdec_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:54:00 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/10 20:18:39 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_strhex(const char *hx_token)
{
	int i;
	int len;
	int result;

	i = 0;
	result = 0;
	len = ft_strlen(hx_token);
	while (hx_token[i] == 32 || (hx_token[i] >= 9 && hx_token[i] <= 13))
		i++;

	while (i < len) 
	{
		result <<= 4;

		if (hx_token[i] >= '0' && hx_token[i] <= '9')
			result += hx_token[i] - '0';
		else if (hx_token[i] >= 'A' && hx_token[i] <= 'F')
			result += hx_token[i] - 'A' + 10;
		else if (hx_token[i] >= 'a' && hx_token[i] <= 'f')
			result += hx_token[i] - 'a' + 10;
		else
			ft_panic("Error: Invalid hexadecimal string!\n");
		i++;
	}
	return (result);
}

int	ft_set_color(char *hx_token)
{
	int color;

	color = 0;
	if (!hx_token || !*hx_token)
	{
		color = DEFAULT_COLOR;
		return(color);
	}
	else
	{
		color = ft_strhex(hx_token);
		return (color);
	}
}