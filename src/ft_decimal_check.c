/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:49:40 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/11 20:31:21 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_fdf(char *de_token, char *hx_token)
{
	size_t	i;
	int		sign;
	int		res;
	int		mult;

	i = 0;
	res = 0;
	sign = 1;
	mult = 0;
	while (ft_isspace(de_token[i]))
		++i;
	if (de_token[i] == '-' || de_token[i] == '+')
	{
		if (de_token[i] == '-')
			sign = -1;
		++i;
	}
	while (de_token[i] == '0')
		++i;
	while ('0' <= de_token[i] && de_token[i] <= '9')
	{
		if (ft_ismultiply_overflow(res, 10))
		{
			free(de_token);
			free(hx_token);
			ft_panic ("Error: Overflow error");
		}
		mult = res * 10;
		if (ft_isadd_overflow(mult, (de_token[i] - '0'), sign))
			ft_panic ("Error: Overflow error");
		res = res * 10 + (de_token[i] - '0');
		++i;
	}

	if (ft_ismultiply_overflow(res, sign))
	{
		
		ft_panic("Error: Overflow error");
	}
	return (sign * res);
}

int	ft_decimal_check(char *de_token, char *hx_token)
{
	int i;
	int value;
	
	if (!de_token || !(*de_token))
		return (0);
	i = -1;
	value = 0;
	while (de_token[++i])
		if (!ft_isdigit(de_token[i]))
		{
			free(de_token);
			free(hx_token);
			ft_panic("Error: Invalid decimal string");
		}
	value = ft_atoi_fdf(de_token, hx_token);
	return (value);
}