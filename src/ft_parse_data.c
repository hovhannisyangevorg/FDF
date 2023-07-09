/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:48:41 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/09 21:37:42 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_is_xvalue(char *token)
// {
// 	int i;
	
// 	i = -1;

// 	// if (!token && *token)
// 	// 	return ;
	
// 	// while (token[i] != ',')
// 	// 	i++;
// 	// while (token && token[++i] != '\0')
// 	// {
// 	// 	if (ft_isxdigit(token[i]))
// 	// 		i++;
// 	// 	else
// 	// 		ft_panic("error: not hexadecimal \n-> ft_is_xvalue()\n");
// 	// }
// 	return ;
// }


void	ft_token(char *token)
{
	int 	len1 = 0;
	int 	len2 = 0;
	char	*token1;
	char	*token2;

	if (token && *token)
		return ;

	while (token[len1] != ',')
		len1++;
	while ()
	{
		
	}
	
}


void	ft_parse_data(char *token)
{
	int i = 0;
	ft_is_xvalue(token);
	// printf("%s, ", token);
	// while (token[i] != '\0')
	// {
	// 	write(1, &token[i], 1);
	// 	i++;
	// }
	// write(1, ",", 1);
	sleep(1);
}
