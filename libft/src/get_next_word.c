/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:23:24 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/15 21:58:23 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	alloc_size;
	char	*str;

	alloc_size = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	str = (char *)malloc((alloc_size + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1 && s1[++i])
		str[++j] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		str[++j] = s2[i];
	str[alloc_size] = '\0';
	free(s1);
	return (str);
}

static char	*get_buffer(char *buff)
{
	int		i;
	int		j;
	int		len;
	char	*after;

	i = 0;
	j = 0;
	len = ft_strlen(buff);
	after = (char *)malloc(sizeof(char) * (len + 1));
	if (!after)
		return (0);
	while (buff && buff[i] && ft_isspace(buff[i]))
		i++;
	while (buff && buff[i] && !ft_isspace(buff[i]))
		i++;
	while (buff && buff[i])
		after[j++] = buff[i++];
	after[j] = '\0';
	free(buff);
	return (after);
}

static char	*get_token(char **buff, size_t*h)
{
	int		i;
	int		j;
	int		len;
	char	*token;

	i = 0;
	j = 0;
	len = 0;
	if (!buff || !*buff)
		return (0);
	if (!**buff)
	{
		free(*buff);
		*buff = 0;
		(*h)++;
		return (0);
	}
	while ((*buff) && (*buff)[i] && ft_isspace((*buff)[i]))
	{
		if ((*buff)[i] == '\n')
			(*h)++;
		i++;
	}
	j = i;
	while ((*buff) && (*buff)[i] && !ft_isspace((*buff)[i++]))
		len++;
	token = (char *)malloc(sizeof(char) * (len + 1));
	if (!token)
		return (0);
	i = 0;
	while ((*buff) && (*buff)[j] && !ft_isspace((*buff)[j]))
		token[i++] = (*buff)[j++];
	token[i] = '\0';
	return (token);
}

char	*get_next_word(int fd, size_t *h)
{
	static char	*buff;
	char		*readed;
	char		*token;
	int			res;

	res = -1;
	readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed)
		return (0);
	while (1)
	{
		res = read(fd, readed, BUFFER_SIZE);
		readed[res] = '\0';
		if (res <= 0)
			break ;
		buff = ft_join(buff, readed);
		if (ft_strfind(readed, " \f\n\r\t\v") != -1)
			break ;
	}
	free(readed);
	if (res < 0)
		return (0);
	token = get_token(&buff, h);
	buff = get_buffer(buff);
	return (token);
}
