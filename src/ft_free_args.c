/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:48:23 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/16 16:44:06 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_utils(char *mes, char **de_token, char **hx_token)
{
	ft_free_args(de_token, 0, 0);
	ft_free_args(hx_token, 0, 0);
	ft_panic (mes);
}

void	ft_free_args(char **str, char ***strvec, char ****strthree)
{
	ft_strdel(str);
	ft_vecstrdel(strvec);
	ft_threestrdel(strthree);
}
