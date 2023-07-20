/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:23:40 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/20 15:55:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecstrdel(char ***vecptr)
{
	int	i;

	if (!vecptr || !(*vecptr))
		return ;
	i = -1;
	while (vecptr && (*vecptr)[++i])
		ft_strdel((*vecptr) + i);
	free(*vecptr);
	*vecptr = NULL;
}
