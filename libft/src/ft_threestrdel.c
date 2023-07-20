/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threestrdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:27:05 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/13 19:28:59 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_threestrdel(char ****vecptr)
{
	int	i;

	if (!vecptr || !(*vecptr))
		return ;
	i = -1;
	while (vecptr && (*vecptr)[++i])
		ft_vecstrdel((*vecptr) + i);
	free(*vecptr);
	*vecptr = NULL;
}
