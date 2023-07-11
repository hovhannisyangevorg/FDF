/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:09:01 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/11 16:20:54 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100000000

void			ft_panic(char *str);
int				ft_setindex(char *token, int c);
static int	    ft_isupper(int c);
static int	    ft_islower(int c);
int	            ft_isalpha(int c);
int	            ft_isdigit(int vul);
int             ft_stop_point(int vul);
size_t	        ft_strlen(const char *str);
char	        *ft_strdup(const char *str);
static char		*ft_join(char *s1, char const *s2);
char			*ft_strjoin(char const *s1, char const *s2);
size_t	        ft_strlcpy(char *dst, const char *src, size_t size);
size_t	        ft_strlcat(char *dst, const char *src, size_t size);
int             ft_strfind(const char *str, const char *chars);
void	        *ft_memcpy(void *dst, const void *src, size_t n);

// static int	ft_isspace(char c)
// {
// 	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
// 		|| c == '\t' || c == '\v');
// }

// static char	*ft_join(char *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	i = -1;
// 	j = -1;
// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	if (s1 && !s2)
// 		return (ft_strdup(s1));
// 	if (!s1 && s2)
// 		return (ft_strdup(s2));
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!str)
// 		return (0);
// 	while (s1 && s1[++i])
// 		str[++j] = s1[i];
// 	i = -1;
// 	while (s2 && s2[++i])
// 		str[++j] = s2[i];
// 	str[j] = 0;
// 	free(s1);
// 	return (str);
// }

// static char	*get_buffer(char *buff)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*after;

// 	i = 0;
// 	j = 0;
// 	len = ft_strlen(buff);
// 	after = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!after)
// 		return (0);
// 	while (buff && buff[i] && ft_isspace(buff[i]))
// 		i++;
// 	while (buff && buff[i] && !ft_isspace(buff[i]))
// 		i++;
// 	while (buff && buff[i])
// 		after[j++] = buff[i++];
// 	after[j] = '\0';
// 	return (after);
// }

// static char	*get_token(char *buff)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*token;

// 	i = 0;
// 	j = 0;
// 	len = 0;
// 	if (!buff || !*buff)
// 	{
// 		free(buff);
// 		return (0);
// 	}
// 	while (buff && buff[i] && ft_isspace(buff[i]))
// 		i++;
// 	j = i;
// 	while (buff && buff[i] && !ft_isspace(buff[i++]))
// 		len++;
// 	token = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!token)
// 		return (0);
// 	i = 0;
// 	while (buff && buff[j] && !ft_isspace(buff[j]))
// 		token[i++] = buff[j++];
// 	token[i] = '\0';
// 	return (token);
// }

// char *get_next_word(int fd) 
// {
// 	static char *buff;
// 	char		*readed;
// 	char		*token;
// 	int 		res = -1;

// 	readed = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!readed)
// 		return (0);
// 	while (1) 
// 	{
// 		res = read(fd, readed, BUFFER_SIZE);
// 		if (res <= 0)
// 			break ;
// 		readed[res] = '\0';
// 		buff = ft_join(buff, readed);
// 		if (ft_strfind(readed, " \f\n\r\t\v") != -1)
// 			break ;
// 	}
// 	free(readed);
// 	if (res < 0)
// 		return (0);
// 	token = get_token(buff);
// 	buff = get_buffer(buff);
// 	return (token);
// }


// int main() 
// {
//     int fd = open("world.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     char *word;
// 	while((word = get_next_word(fd)))
// 		printf("%s,", word);
//     close(fd);
//     return (0);
// }






// ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????


// int	ft_isxdigit(int num)
// {
// 	if ((num >= '0' && num <= '9') || (num >= 'A' && num <= 'F') \
// 		|| (num >= 'a' && num <= 'f'))
// 		return (1);
// 	else
// 		return (0);
// }

// void	ft_is_xvalue(char *token)
// {
// 	int i;
	
// 	i = -1;

// 	if (!token)
// 		return ;
	
// 	while (token && *token && token[i] != ',')
// 		i++;	
// 	while (token && token[++i] != '\0')
// 	{
// 		if (ft_isxdigit(token[i]))
// 			i++;
// 		else
// 			ft_panic("error: not hexadecimal\n");
// 	}
// 	return ;
// }

int ft_isspace(int arg) 
{
    return (arg == 32 || (arg >= 9 && arg <= 13));
}

int ft_strhex(const char *hx_token)
{
	int i;
	int len;
	int result;

	i = 0;
	result = 0;
	len = ft_strlen(hx_token);
	while (hx_token[i] == 32 || (hx_token[i] >= 9 && hx_token[i] <= 13))
		i++;
	while (i < len) 
	{
		result <<= 4;

		if (hx_token[i] >= '0' && hx_token[i] <= '9')
			result += hx_token[i] - '0';
		else if (hx_token[i] >= 'A' && hx_token[i] <= 'F')
			result += hx_token[i] - 'A' + 10;
		else if (hx_token[i] >= 'a' && hx_token[i] <= 'f')
			result += hx_token[i] - 'a' + 10;
		else
		{	
			printf("Error: Invalid hexadecimal string!\n");
			return(0);
		}
		i++;
	}
	return (result);
}

int main()
{
}

























// ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????

// int ft_is_xvalue(char *token)
// {
// 	int i = 0;

// 	if (!token || !(*token))
// 		return 0;

// 	while (token[i] != '\0')
// 	{
// 		if (!isxdigit(token[i]))
// 		{
// 			printf("error: not hexadecimal\n");
// 			return (0);
//         }
// 		i++;
// 	}
// 	return (1);
// }

// #define F 100

// int main()
// {
// 	// char *str = "";
// 	// char *token1 = ft_extract_substring(str, ',', 0);
// 	// char *token2 = ft_extract_substring(str, '\0', (ft_setindex(str, ',')));

// 	// printf("token 1 =%s-\n", token1);
// 	// printf("token 2 =%s-\n", token2);

// 	char *a = "0x45fffffffdfswfffff";
// 	int color = 0;
	
// 	color = F;
// 	printf("%d\n", color);
// 	return(0);
// }


































































































































































static int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

static int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}

int	ft_isdigit(int vul)
{
	if (vul >= '0' && vul <= '9')
		return (1);
	return (0);
}

int ft_stop_point(int vul)
{
    if (vul == 44)
        return (1);
    return (0);
}









size_t ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (ptr && *ptr)
		ptr++;
	return (ptr - str);
}


char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	len;

	len = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(*new) * len);
	if (!new)
		return(0);
	return ((char *)ft_memcpy(new, str, len));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstc;
	const char	*srccc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dstc = (char *)dst;
	srccc = (const char *)src;
	while (n--)
		dstc[n] = srccc[n];
	return (dst);
}


int	ft_strfind(const char *str, const char *chars)
{
	const char		*result;

	if (!str || !chars)
		return (0);
	result = strpbrk(str, chars);
	if (result != NULL)
		return ((int)(result - str));
	return (-1);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst && dst[i] && i < size)
		i++;
	while (src && src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

void	ft_panic(char *str)
{
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}


// static char	*ft_join(char *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char* str;

// 	i = -1;
// 	j = -1;
// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	if (s1 && !s2)
// 		return (ft_strdup(s1));
// 	if (!s1 && s2)
// 		return (ft_strdup(s2));
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!str)
// 		return (0);
// 	while(s1 && s1[++i])
// 		str[++j] = s1[i];
// 	i = -1;
// 	while(s2 && s2[++i])
// 		str[++j] = s2[i];
// 	str[j] = 0;
// 	free(s1);
// 	return (str);
// }



// char	*ft_join(char *s1, char const *s2)
// {
// 	int i;
// 	int j;
// 	char* str;

// 	i = -1;
// 	j = -1;
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!str)
// 		return (0);
// 	while(s1 && s1[++i])
// 		str[++j] = s1[i];
// 	i = -1;
// 	while(s2 && s2[++i])
// 		str[++j] = s2[i];
// 	str[j] = 0;
// 	free(s1);
// 	return (str);
// }

// static char	*ft_join(char *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char* str;

// 	i = -1;
// 	j = -1;
// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	if (s1 && !s2)
// 		return (ft_strdup(s1));
// 	if (!s1 && s2)
// 		return (ft_strdup(s2));
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!str)
// 		return (0);
// 	while(s1 && s1[++i])
// 		str[++j] = s1[i];
// 	i = -1;
// 	while(s2 && s2[++i])
// 		str[++j] = s2[i];
// 	str[j] = 0;
// 	free(s1);
// 	return (str);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new;
// 	size_t	len1;
// 	size_t	len2;

// 	if (!s1 && !s2)
// 		return (ft_strdup(""));
// 	if (s1 && !s2)
// 		return (ft_strdup(s1));
// 	if (!s1 && s2)
// 		return (ft_strdup(s2));
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
// 	if (!new)
// 		return (NULL);
// 	ft_strlcpy(new, s1, len1 + 1);
// 	ft_strlcat(new, s2, len1 + len2 + 1);
// 	return (new);
// }