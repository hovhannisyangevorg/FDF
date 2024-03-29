/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:49:40 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/11 22:16:31 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_atoi_fdf(char **de_token, char **hx_token)
{
	struct s_decimal_check	obj;

	obj = (struct s_decimal_check){0, 0, 1, 0};
	if (!(*de_token) || !(*(*de_token)))
		return (0);
	while (ft_isspace((*de_token)[obj.i]))
		++obj.i;
	if ((*de_token)[obj.i] == '-' || (*de_token)[obj.i] == '+')
		if ((*de_token)[obj.i++] == '-')
			obj.sign = -1;
	while ((*de_token)[obj.i] == '0')
		++obj.i;
	while ('0' <= (*de_token)[obj.i] && (*de_token)[obj.i] <= '9')
	{
		if (ft_ismultiply_overflow(obj.res, 10))
			ft_free_utils(INVALID_OVERFLOW, de_token, hx_token);
		obj.mult = obj.res * 10;
		if (ft_isadd_overflow(obj.mult, ((*de_token)[obj.i] - '0'), obj.sign))
			ft_free_utils(INVALID_OVERFLOW, de_token, hx_token);
		obj.res = obj.res * 10 + ((*de_token)[obj.i++] - '0');
	}
	if (ft_ismultiply_overflow(obj.res, obj.sign))
		ft_free_utils(INVALID_OVERFLOW, de_token, hx_token);
	return (obj.sign * obj.res);
}

int	ft_decimal_check(char **de_token, char **hx_token)
{
	int	i;
	int	value;

	if (!de_token || !(*de_token))
		return (0);
	i = -1;
	value = 0;
	if ((*de_token)[++i] == '-')
		;
	while ((*de_token)[++i])
		if (!ft_isdigit((*de_token)[i]))
			ft_free_utils("Error: Invalid coordinate\n", de_token, hx_token);
	value = ft_atoi_fdf(de_token, hx_token);
	return (value);
}
