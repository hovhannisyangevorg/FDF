/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:49:40 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/20 18:29:06 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

struct s_decimal_check t_decimal_check;

struct s_decimal_check
{
	size_t	i;
	int		res;
	int		sign;
	int		mult;
};

void	ft_free_utils(char *mes, char **de_token, char **hx_token)
{
	ft_free_args(de_token, 0, 0);
	ft_free_args(hx_token, 0, 0);
	ft_panic (mes);
}

int	ft_atoi_fdf(char **de_token, char **hx_token)
{
	struct s_decimal_check	obj;

	obj = (struct s_decimal_check){0, 0, 1, 0};
	if (!(*de_token) || !(*(*de_token)))
		return (0);
	while (ft_isspace((*de_token)[obj.i]))
		++obj.i;
	if ((*de_token)[obj.i] == '-' || (*de_token)[obj.i] == '+')
	{
		if ((*de_token)[obj.i] == '-')
			obj.sign = -1;
		++obj.i;
	}
	while ((*de_token)[obj.i] == '0')
		++obj.i;
	while ('0' <= (*de_token)[obj.i] && (*de_token)[obj.i] <= '9')
	{
		if (ft_ismultiply_overflow(obj.res, 10))
			ft_free_utils(INVALID_OVERFLOW, de_token, hx_token);
		obj.mult = obj.res * 10;
		if (ft_isadd_overflow(obj.mult, ((*de_token)[obj.i] - '0'), obj.sign))
			ft_free_utils(INVALID_OVERFLOW, de_token, hx_token);
		obj.res = obj.res * 10 + ((*de_token)[obj.i] - '0');
		++obj.i;
	}
	if (ft_ismultiply_overflow(obj.res, obj.sign))
		ft_free_utils(INVALID_OVERFLOW, de_token, hx_token);
	return (obj.sign * obj.res);
}

int	ft_decimal_check(char **de_token, char **hx_token)
{
	int i;
	int value;
	
	if (!de_token || !(*de_token))
		return (0);
	i = -1;
	value = 0;
	while ((*de_token)[++i])
		if (!ft_isdigit((*de_token)[i]))
			ft_free_utils("Error: Invalid coordinate\n", de_token, hx_token);
	value = ft_atoi_fdf(de_token, hx_token);
	return (value);
}









































































































































































// void	ft_free_utils(char *mes, char *de_token, char *hx_token)
// {
// 	ft_free_args(de_token, 0, 0);
// 	ft_free_args(hx_token, 0, 0);
// 	ft_panic (mes);
// }

// int	ft_atoi_fdf(char *de_token, char *hx_token)
// {
	// struct s_decimal_check	obj;

	// obj = (struct s_decimal_check){0, 0, 1, 0};
	// if (!de_token || !(*de_token))
	// 	return (0);
// 	while (de_token && *de_token && ft_isspace(de_token[obj.i]))
// 		++obj.i;
// 	if (de_token[obj.i++] == '-' || de_token[obj.i] == '+')
// 		if (de_token[obj.i] == '-')
// 			obj.sign = -1;
// 	while (de_token[obj.i] == '0')
// 		++obj.i;
// 	while ('0' <= de_token[obj.i] && de_token[obj.i] <= '9')
// 	{
// 		if (ft_ismultiply_overflow(obj.res, 10))
// 			ft_free_utils("Error: Overflow error", de_token, hx_token);
// 		obj.mult = obj.res * 10;
// 		if (ft_isadd_overflow(obj.mult, (de_token[obj.i] - '0'), obj.sign))
// 			ft_free_utils("Error: Overflow error", de_token, hx_token);
// 		obj.res = obj.res * 10 + (de_token[obj.i] - '0');
// 		++obj.i;
// 	}
// 	if (ft_ismultiply_overflow(obj.res, obj.sign))
// 		ft_free_utils("Error: Overflow error", de_token, hx_token);
// 	return (obj.sign * obj.res);
// }

// int	ft_decimal_check(char *de_token, char *hx_token)
// {
// 	int	i;
// 	int	value;

// 	if (!de_token || !(*de_token))
// 		return (0);
// 	i = -1;
// 	value = 0;
// 	while (de_token[++i])
// 		if (!ft_isdigit(de_token[i]))
// 			ft_free_utils("Error: Overflow error", de_token, hx_token);
// 	value = ft_atoi_fdf(de_token, hx_token);
// 	return (value);
// }



