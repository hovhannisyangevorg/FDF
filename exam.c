/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:09:01 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/15 01:54:06 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
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
int				ft_isadd_overflow(int a, int b, int sign);
int				ft_ismultiply_overflow(int a, int b);
void			ft_panic(char *error);

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
// 	printf("heloo");
// 	return (0);
// }




















































































//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// #include <math.h>

// typedef struct	s_line_cord
// {
// 	int x1; 
// 	int x2; 
// 	int y1;
// 	int y2;
// } t_line_cord;

// typedef struct	s_distance_formula
// {
// 	int x;
//     int y;
//     int dx;
//     int dy;
//     int d;		
// } t_distance_formula;

// // Calculating distance
// int ft_distance(t_line_cord *cord, int dx, int dy)
// {
//     return (int)sqrt(dx * dx + dy * dy);
// }

// void ft_drawline(t_line_cord *cord)
// {
// 	t_distance_formula dist;
//     int x_end;
//     int i1;
//     int i2;

//     dist.dx = cord->x2 - cord->x1;   				// Calculate the change in x (delta x)
//     dist.dy = cord->y2 - cord->y1;   				// Calculate the change in y (delta y)
// 	dist.d = ft_distance(cord, dist.dx, dist.dy);				// Initialize the decision parameter d using the "Distance formula"
//     i1 = 2 * dist.dy;    							// Calculate the increments for diagonally moving pixels
//     i2 = 2 * (dist.dy - dist.dx); 						// Calculate the increments for vertically moving pixels

//     /* 
// 		Determine the starting point and x_end 
// 	*/
//     if (dist.dx < 0)
//     {
//         dist.x = cord->x2;
//         dist.y = cord->y2;
//         x_end = cord->x1;
//     }
//     else
//     {
//         dist.x = cord->x1;
//         dist.y = cord->y1;
//         x_end = cord->x2;
//     }

//     /* Print the starting point */
//     printf("(%d, %d)\n", dist.x, dist.y);
    
//     /* Draw the line using Bresenham's algorithm */
//     while (dist.x < x_end)
//     {
//         if (dist.d < 0)
//             dist.d += i1; // Move diagonally
//         else
//         {
//             dist.d += i2; // Move vertically and diagonally
//             dist.y++;
//         }
//         dist.x++;
//         printf("(%d, %d)\n", dist.x, dist.y); // Print the current pixel coordinates
//     }
// }

// int main()
// {
// 	t_line_cord cord;
// 	cord.x1 = 1;
// 	cord.y1 = 5;
// 	cord.x2 = 8;
// 	cord.y2 = 15;
//     ft_drawline(&cord);

//     return 0;
// }


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||













//////////////////////////////////irakan|||||||||||||||||||||||||
/*
#include <stdio.h>
#include <math.h>

typedef struct s_line_cord
{
	int x1; 
	int y1;
	int z1;
	int x2; 
	int y2;
	int z2;
} t_line_cord;

typedef struct s_distance_formula
{
	int x;
	int y;
	int z;
	int dx;
	int dy;
	int dz;
	int d;
} t_distance_formula;


int ft_distance(t_distance_formula *dist)
{
    return ((int)sqrt(pow(dist->dx, 2) + pow(dist->dy, 2) + pow(dist->dz, 2)));
}

void ft_drawline(t_line_cord *cord)
{
	t_distance_formula dist;
	int x_end;
	int i1;
	int i2;

	dist.dx = (cord->x2 - cord->x1);
	dist.dy = (cord->y2 - cord->y1);
	dist.dz = (cord->z2 - cord->z1);
	dist.d  = ft_distance(&dist);
	i1 = (2 * dist.dy);
	i2 = (2 * (dist.dy - dist.dx));

	if (dist.dx < 0)
	{
		dist.x = cord->x2;
		dist.y = cord->y2;
		dist.z = cord->z2;
		x_end = cord->x1;
	}
	else
	{
		dist.x = cord->x1;
		dist.y = cord->y1;
		dist.z = cord->z1;
		x_end = cord->x2;
	}
	// printf("(%d, %d, %d)\n", dist.x, dist.y, dist.z);
	while (dist.x < x_end)
	{
		if (dist.d < 0)
			dist.d += i1;
		else
		{
			dist.d += i2;
			dist.y++;
		}
		dist.x++;
		dist.z++;
		printf("(%d, %d, %d)\n", dist.x, dist.y, dist.z);
	}
}

int main()
{
    t_line_cord cord;
    cord.x1 = 21;
    cord.y1 = 5;
    cord.z1 = 2;
    cord.x2 = 8;
    cord.y2 = 15;
    cord.z2 = 10;

    ft_drawline(&cord);

    return 0;
}
*/




// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_add
// {
// 	int *arr;
// 	int size;
// 	int capacity;
// 	int elem;	
// } t_add;

// void ft_init_arrey(t_add *tab, size_t size)
// {
// 	if (!tab)
// 		return ;

// 	tab->size = size;
// 	tab->capacity = size;
// 	tab->elem = 0;
// 	if (size)
// 	{
// 		tab->arr = (int *)malloc(sizeof(int) * size);
// 		if (!tab->arr)
// 			return ;
// 	}
// }

// void	ft_update_capacity_arrey(t_add *tab, size_t size)
// {
// 	size_t 	i;
// 	size_t 	new_cap;
// 	int 	*arr;
// 	if (!tab)
// 		return (NULL);

// 	if (!tab->capacity)
// 		new_cap = size;
// 	else if (tab->capacity <= size)
// 		new_cap *= 2;
// 	i = 0;
// 	if (new_cap != tab->capacity)
// 	{
// 		arr = (int *)malloc(sizeof(int) * new_cap);
// 		if (!arr)
// 			return ;
// 		while (i < tab->size)
// 		{
// 			arr[i] = tab->arr[i];
// 			i++;
// 		}
// 		tab->capacity = new_cap;
// 		tab.
// 	}	
// }

// void	ft_push_back(t_matrix *m, t_point3d val)
// {
// 	if (!m)
// 		return ;
// 	ft_update_capacity(m, m->size + 1);
// 	m->cord[m->size] = val;
// 	++m->size;
// }

// int main()
// {
// 	t_add tab;

// 	ft_init_arrey(&tab, 0);
// 	printf("%d, %d, %d,", tab.capacity, tab.size, tab.elem);
// }
 




// ??????????????????//????????????????????????????????????????????????????????????????????????????????????????????????????//

#include <stdio.h>
#include <stdlib.h>

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_add
// {
//     int *arr;
//     size_t size;
//     size_t capacity;
// } t_add;

// void	ft_tabcpy(int *tab1, int *tab2, size_t size)
// {
// 	int i;
// 	if (!tab1)
// 		return ;
// 	if (!tab2)
// 		return ;
// 	i = 0;
// 	while (i < size)
// 	{
// 		tab1[i] = tab2[i];
// 		i++;
//     }
// }

// void	*ft_memset(void *str, int c, size_t n)
// {
// 	unsigned char	*ptr;

// 	ptr = (unsigned char *)str;
// 	while (n--)
// 		*ptr++ = (unsigned char)c;
// 	return (str);
// }


// void ft_init(t_add *tab, size_t size)
// {
// 	if (!tab)
// 		return ;
// 	tab->size = size;
// 	tab->capacity = size;
// 	tab->arr = 0;
// 	if (size)
// 	{
// 		tab->arr = (int *)malloc(sizeof(int) * size);
// 		ft_memset(tab->arr, 0, (sizeof(int)));
// 		if (!tab->arr)
// 			return ;
// 	}
// }

// void	ft_update_capacity(t_add *tab)
// {
// 	int 	*new_tab;
// 	size_t 	new_cap;
// 	if (!tab)
// 		return ;
// 	new_cap = tab->capacity;
// 	if (!new_cap)
// 		new_cap = 1;
// 	else if (tab->size + 1 >= new_cap)
// 		new_cap *= 2;
// 	if (new_cap != tab->capacity)
// 	{
// 		new_tab = (int *)malloc(sizeof(int) * new_cap);
// 		ft_tabcpy(new_tab, tab->arr, tab->size);
// 		if (tab->arr)
// 			free(tab->arr);
// 		tab->arr = new_tab;
// 		tab->capacity = new_cap;
// 	}
// }

// void ft_push_back(t_add *tab, int val)
// {
// 	if (!tab)
// 		return ;
// 	ft_update_capacity(tab);
// 	tab->arr[tab->size] = val;
// 	tab->size++;
// }

// int main()
// {
//     t_add my_tab;
    
//     ft_init(&my_tab, 10);
// 	// ft_push_back(&my_tab, 1);	
// 	// ft_push_back(&my_tab, 8);	
// 	// ft_push_back(&my_tab, 10);	
// 	// ft_push_back(&my_tab, 15);	
// 	// ft_push_back(&my_tab, 20);	
// 	// ft_push_back(&my_tab, 320);	
// 	// ft_push_back(&my_tab, 255);	
	
    
// 	for (int i = 0; i < 25; i++)
//         ft_push_back(&my_tab, i);


//     for (int i = 0; i < my_tab.size; i++)
//         printf("%d ", my_tab.arr[i]);
//     printf("\n");

//     free(my_tab.arr);

//     return 0;
// }
// ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????













































































































































































/////////////////////////////////////////////////////////////////////////* ft_push_back() *////////////////////////////////////////////////////////////////////////////////////////

// typedef struct s_matrix t_matrix;
// typedef struct s_point3d t_point3d;

// struct s_point3d
// {
// 	int x;
// 	int y;
// 	int z;
// 	int color;
// };

// struct s_matrix
// {
// 	t_point3d	*cord;
// 	size_t		capacity;
// 	size_t		size;
// };

// t_point3d	*ft_init_point3d(t_point3d vulue, size_t size, size_t capacity)
// {
// 	int i;

// 	if (capacity == 0)
// 		capacity++;
// 	if (size == capacity)
// 		capacity *= 2;

// 	t_point3d	*new_point = (t_point3d *)malloc(sizeof(t_point3d) * capacity);
// 	if (!new_point)
// 		return(0);
// 	i = 0;
// 	while(i < size)
// 	{
// 		new_point[i].x = vulue.x;
// 		new_point[i].y = vulue.y;
// 		new_point[i].z = vulue.z;
// 		new_point[i].color = vulue.color;
// 		i++;
// 	}
// 	return(new_point);
// }

// void ft_init(t_matrix* m, size_t size)
// {
// 	if (!m)
// 		return;
// 	m->size = size;
// 	m->capacity = size;
// 	m->cord = 0;
// 	if (size)
// 		m->cord = malloc(sizeof(t_point3d) * size);
// }

// void ft_update_capacity(t_matrix *m, size_t size)
// {
// 	t_point3d* tmp;
// 	size_t new_cap;

// 	new_cap = m->capacity;
// 	if (!m->capacity)
// 		new_cap = size;
// 	else if (m->capacity <= size)
// 		new_cap *= 2;
// 	if (new_cap != m->capacity)
// 	{
// 		tmp = (t_point3d *)malloc(sizeof(t_point3d) * new_cap);
// 		if (!tmp)
// 			return;
// 		for(size_t i = 0; i < m->size; ++i)
// 		{
// 			tmp[i] = m->cord[i];
// 		}
// 		if (m->cord)
// 			free(m->cord);
// 		m->cord = tmp;
// 		m->capacity = new_cap;
// 	}
// }

// void ft_push_back(t_matrix *m, t_point3d val)
// {
// 	if(!m) 
// 		return;
// 	ft_update_capacity(m, m->size + 1);
// 	m->cord[m->size] = val;
// 	++m->size;
// }

// void ft_print_matrix(t_matrix* m)
// {
// 	for(size_t i = 0; i < m->size; ++i)
// 		printf("(%d %d %d %x) ", m->cord[i].x, m->cord[i].y, m->cord[i].z, m->cord[i].color);
// 	printf("\n");
// }

// int main()
// {
// 	t_matrix m;
// 	ft_init(&m, 0);
// 	ft_push_back(&m, (t_point3d){1,2,3,0xff});
// 	ft_push_back(&m, (t_point3d){0,2,6,0x00});
// 	ft_push_back(&m, (t_point3d){1,2,3,0xff});
// 	ft_push_back(&m, (t_point3d){0,2,6,0x00});
// 	ft_push_back(&m, (t_point3d){1,2,3,0xff});
// 	ft_push_back(&m, (t_point3d){0,2,6,0x00});
// 	ft_push_back(&m, (t_point3d){1,2,3,0xff});
// 	ft_push_back(&m, (t_point3d){0,2,6,0x00});
// 	print(&m);
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





















































































































































































// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

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

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
























































































































































































































































































































































































































































































































































































































































































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


int	ft_ismultiply_overflow(int a, int b)
{
	int	result;

	if (a == 0 || b == 0)
		return (0);
	result = a * b;
	if (a == result || a == result / b)
		return (0);
	return (1);
}

int	ft_isadd_overflow(int a, int b, int sign)
{
	int	result;

	result = a + b;
	if (sign < 0 && result == INT_MIN)
		return (0);
	if (a > 0 && b > 0 && result < 0)
		return (1);
	if (a < 0 && b < 0 && result > 0)
		return (1);
	return (0);
}

void	ft_panic(char *error)
{
	write (2, error, ft_strlen(error));
	write (2, "\n", 1);
	exit (1);
}