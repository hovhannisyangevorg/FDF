/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:09:01 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/20 18:18:07 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100000000

// void			ft_panic(char *str);
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

// int ft_isspace(int arg) 
// {
//     return (arg == 32 || (arg >= 9 && arg <= 13));
// }

// int ft_strhex(const char *hx_token)
// {
// 	int i;
// 	int len;
// 	int result;

// 	i = 0;
// 	result = 0;
// 	len = ft_strlen(hx_token);
// 	while (hx_token[i] == 32 || (hx_token[i] >= 9 && hx_token[i] <= 13))
// 		i++;
// 	while (i < len) 
// 	{
// 		result <<= 4;

// 		if (hx_token[i] >= '0' && hx_token[i] <= '9')
// 			result += hx_token[i] - '0';
// 		else if (hx_token[i] >= 'A' && hx_token[i] <= 'F')
// 			result += hx_token[i] - 'A' + 10;
// 		else if (hx_token[i] >= 'a' && hx_token[i] <= 'f')
// 			result += hx_token[i] - 'a' + 10;
// 		else
// 		{	
// 			printf("Error: Invalid hexadecimal string!\n");
// 			return(0);
// 		}
// 		i++;
// 	}
// 	return (result);
// }




// void ft_strdel(char **str)	//void (*ft_strdel)(char **str)
// {
// 	if (!str || !*str)
// 		return ;
// 	free(*str);
// 	*str = NULL;
// }


// void	ft_panic(char *str, char *del)
// {
// 	ft_strdel(&del);
// 	printf("%s", del);
// 	write (2, str, ft_strlen(str));
// 	write (2, "\n", 1);
// 	exit (1);
// }

// int main()
// {
// 	int i = 0;
// 	char *ptr = (char *)malloc(sizeof(char) * 11);
// 	if (!ptr)
// 		return (0);
// 	while (i < 10)
// 	{
// 		ptr[i] = 'A';
// 		i++;
// 	}
// 	// printf("%s\n", ptr);
// 	ft_panic("Hello Broo", ptr);
// }





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// void ft_strdel(char **str)	//void (*ft_strdel)(char **str)
// {
// 	if (!str || !*str)
// 		return ;
// 	free(*str);
// 	*str = NULL;
// }


// void	ft_panic(char *str, void (*del)(char **str), int flag)
// {
// 	ft_strdel(&del);
// 	printf("%s", del);
// 	write (2, str, ft_strlen(str));
// 	write (2, "\n", 1);
// 	exit (1);
// }

// int main()
// {
// 	int i = 0;
// 	char *ptr = (char *)malloc(sizeof(char) * 11);
// 	if (!ptr)
// 		return (0);
// 	while (i < 10)
// 	{
// 		ptr[i] = 'A';
// 		i++;
// 	}
// 	// printf("%s\n", ptr);
// 	ft_panic("Hello Broo", ptr);
// }































































































































// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// typedef struct s_free
// {
// 	char *error;
// 	char *str;
// 	char **strvec;
// 	char ***strthree;
// 	int flag;
// }	t_free;


// void 		ft_strdel(char **ptr);
// void 		ft_vecstrdel(char ***vecptr);
// void 		ft_threestrdel(char ****vecptr);
// static void	ft_panic_utils(char *error);
// void		ft_panic(char *error, char *str, char **strvec, char ***strthree);
// char	 	**ft_create_matric(size_t row, size_t col, int c);


// void 		ft_strdel(char **ptr)
// {
// 	if (!ptr || !*ptr)
// 		return ;
// 	free(*ptr);
// 	*ptr = NULL;
// }

// void ft_vecstrdel(char ***vecptr)
// {
// 	int i;
// 	if (!vecptr || !(*vecptr))
// 		return ;
// 	i = -1;
// 	while (vecptr && (*vecptr)[++i])
// 		ft_strdel((*vecptr) + i);
// 	free(*vecptr);
// 	*vecptr = NULL;
// }

// void ft_threestrdel(char ****vecptr)
// {
// 	int i;
// 	if (!vecptr || !(*vecptr))
// 		return ;
// 	i = -1;
// 	while(vecptr && (*vecptr)[++i])
// 		ft_vecstrdel((*vecptr) + i);
// 	free(*vecptr);
// 	*vecptr = NULL;
// }

// static void	ft_panic_utils(char *error)
// {	
// 	write (2, error, ft_strlen(error));
// 	write (2, "\n", 1);
// 	exit (1);
// }

// void	ft_panic(char *error, char *str, char **strvec, char ***strthree)
// {
// 	ft_strdel(&str);
// 	ft_vecstrdel(&strvec);
// 	ft_threestrdel(&strthree);
// 	ft_panic_utils(error);
// }

// char **ft_create_matric(size_t row, size_t col, int c)
// {
// 	size_t i;
// 	size_t j;

// 	if (row < 0 || col < 0)
// 		return(0);
// 	char **new = (char **)malloc(sizeof(char*) * (row + 1));
// 	if (!new || !(*new))
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	while (i < row)
// 	{
// 		j = 0;
// 		new[i] = (char *)malloc(sizeof(char) * (col + 1));
// 		while(j < col)
// 		{
// 			new[i][j] = c;
// 			j++;
// 		}
// 		new[i][j] = '\0';
// 		i++;
// 	}
// 	new[i] = NULL;
// 	return (new);
// }





// int main()
// {
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	size_t row = 5;
// 	size_t columne = 5;
// 	char **matric = ft_create_matric(row, columne, 'F');
// 	char **m = ft_create_matric(row, columne, 'A');
// 	char ***tree = (char ***)malloc(sizeof(char **) * 3);
// 	tree[0] = matric;
// 	tree[1] = m;
// 	tree[2] = NULL;
// 	// ft_threestrdel(&tree);

// 	printf("\n)))))))))))))))))))))))--- 1 ---)))))))))))))))))))))))))))))))))\n");
// 	while (matric && matric[i])
// 	{
// 			printf("%s \n", matric[i]);
// 		++i;
// 	}
// 	printf("\n)))))))))))))))))))))))--- 1 ---)))))))))))))))))))))))))))))))))\n");
	
// 	ft_panic("Error:", NULL, matric, NULL);
// }















































int main()
{
}
















	// printf("\n)))))))))))))))))))))))--- 1 ---)))))))))))))))))))))))))))))))))\n");
	// while (tree && tree[i])
	// {
	// 	j = 0;
	// 	while(tree[i] && tree[i][j])
	// 	{
	// 		k = 0;
	// 		while (tree[i][j] && tree[i][j][k])
	// 		{
	// 			printf("%c ", tree[i][j][k]);
	// 			++k;	
	// 		}
	// 		printf("\n");
	// 		j++;
	// 	}
	// 	printf("\n---------------------------\n");
	// 	++i;
	// }
	// printf("\n)))))))))))))))))))))))--- 1 ---)))))))))))))))))))))))))))))))))\n");















































































































































































































































































































































































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

	if(!str && !(*str))
		return(0);
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

// void	ft_panic(char *str)
// {
// 	write (2, str, ft_strlen(str));
// 	write (2, "\n", 1);
// 	exit (EXIT_FAILURE);
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




































































































































































































































































// static void ft_free_utils(char *mes, char *de_token, char *hx_token)
// {
// 	ft_free_args(de_token, 0, 0);
// 	ft_free_args(hx_token, 0, 0);
// 	ft_panic (mes);
// }

// int	ft_atoi_fdf(char *de_token, char *hx_token)
// {
// 	size_t	i;
// 	int		sign;
// 	int		res;
// 	int		mult;

// 	i = 0;
// 	res = 0;
// 	sign = 1;
// 	mult = 0;
// 	if (!(de_token) || !(*de_token))
// 		return (0);
// 	while (de_token && *de_token && ft_isspace(de_token[i]))
// 		++i;
// 	if (de_token[i] == '-' || de_token[i] == '+')
// 	{
// 		if (de_token[i] == '-')
// 			sign = -1;
// 		++i;
// 	}
// 	while (de_token[i] == '0')
// 		++i;
// 	while ('0' <= de_token[i] && de_token[i] <= '9')
// 	{
// 		if (ft_ismultiply_overflow(res, 10))
// 			ft_free_utils("Error: Overflow error", de_token, hx_token);
// 		mult = res * 10;
// 		if (ft_isadd_overflow(mult, (de_token[i] - '0'), sign))
// 			ft_free_utils("Error: Overflow error", de_token, hx_token);
// 		res = res * 10 + (de_token[i] - '0');
// 		++i;
// 	}
// 	if (ft_ismultiply_overflow(res, sign))
// 		ft_free_utils("Error: Overflow error", de_token, hx_token);
// 	return (sign * res);
// }

// int	ft_decimal_check(char *de_token, char *hx_token)
// {
// 	int i;
// 	int value;
	
// 	if (!de_token || !(*de_token))
// 		return (0);
// 	i = -1;
// 	value = 0;
// 	while (de_token[++i])
// 		if (!ft_isdigit(de_token[i]))
// 			ft_free_utils("Error: Overflow error", de_token, hx_token);
// 	value = ft_atoi_fdf(de_token, hx_token);
// 	return (value);
// }
