/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:48:41 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/11 17:32:45 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_extract_substring(const char *token, char c, int index)
{
	int 	i = 0;
	int		len;
	char	*new;
	len		= ft_strlen_start(token, index);
	
	if (!token || !(*token))
		return (0);
	if (index < 0)
		return (0);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	while (token[index] && token[index] != c)
		new[i++] = (char)token[index++];
	new[i] = '\0';
	return(new);
}
//TODO: create function for check if string contains only numbers.
void	ft_parse_data(char *token)
{
	int		hx_color;
	char	*w_token1;
	char	*w_token2;

	if (!token || !*token)
		return ;
	printf("Token---%s-\n", token);
	
	w_token1 = ft_extract_substring(token, ',', 0);
	w_token2 = ft_extract_substring(token, '\0', ft_setindex(token, ','));
	
	// printf("1    ---%s-\n", w_token1);
	// printf("2    ---%s-\n", w_token2);
	/*
		if w_token1 is not contains only numbers
			error
		number = atoi(w_token1)
	*/
	hx_color = ft_set_color(w_token2);
	// printf("------------%X\n", hx_color);
}













	// printf("\n_____________________________________________________________________________________________________________________________________\n");
	// printf("-----------------word ->%s\n", token);
	// printf("1________________%s_____________\n", w_token1);
	// printf("2________________%s_____________\n", w_token2);
	// sleep(1);
