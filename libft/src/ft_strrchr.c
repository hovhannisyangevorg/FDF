/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:07:50 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/02 19:38:53 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *string, int searched_char)
{
	char	*str;

	str = string;
	while (str && *str != searched_char && *str != 0)
		str++;
	if (str && *str == searched_char)
		return (str);
	else
		return (NULL);
}
