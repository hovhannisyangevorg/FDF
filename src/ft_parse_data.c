/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:48:41 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/08 17:44:54 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_extract_substring(const char *token, char c, int index)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen_start(token, index, c);
	if (!token || !(*token) || index < 0)
		return (0);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	i = 0;
	while (token[index] && token[index] != c)
		new[i++] = (char)token[index++];
	new[i] = '\0';
	return (new);
}

void	ft_parse_data(char *token, t_matrix *matrix)
{
	int		de_coord;
	int		hx_color;
	char	*w_token1;
	char	*w_token2;

	if (!token || !*token)
		return ;
	w_token1 = ft_extract_substring(token, ',', 0);
	w_token2 = ft_extract_substring(token, '\0', ft_setindex(token, ','));
	de_coord = ft_decimal_check(&w_token1, &w_token2);
	hx_color = ft_hexdec_check(&w_token1, &w_token2);
	free(w_token1);
	free(w_token2);
	ft_push_back(matrix, (t_point3d){0, 0, de_coord, hx_color});
}

void	ft_parse(t_map *map, t_add *tab, int fd)
{
	size_t	temp;
	char	*token;

	ft_init(map, 0);
	ft_init_arrey(tab, 0);
	temp = 0;
	while (1)
	{
		token = get_next_word(fd, &map->height);
		if (!token)
			break ;
		if (map->height > temp)
		{
			if (map->matrix.size)
				ft_push_arrey(tab, map->matrix.size);
			temp = map->height;
		}
		ft_parse_data(token, &map->matrix);
		free(token);
	}
	ft_push_arrey(tab, map->matrix.size);
	map->width = ft_determine_width(tab, tab->size);
	map->height = tab->size;
	ft_determine_x_y(map);
	free(tab->arr);
}
