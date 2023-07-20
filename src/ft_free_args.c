/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:48:23 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/20 16:06:14 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_args(char **str, char ***strvec, char ****strthree)
{
	ft_strdel(str);
	ft_vecstrdel(strvec);
	ft_threestrdel(strthree);
}
