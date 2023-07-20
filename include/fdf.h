# ifndef FDF_H
# define FDF_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "mlx.h"
#include "fdf_defines.h"
#include "fdf_structures.h"
#include "libft.h"

#define INVALID_COLOR "Error: Invalid color!\n"
#define INVALID_OVERFLOW "Error: Overflow error\n"
#define DEFAULT_COLOR (0xffffff)  // (255 << 16 | 0 << 8 | 0)

/* ft_hexdec_check.c */
int		ft_strhex(char **de_token, char **hx_token);
int		ft_hexdec_check(char **de_token, char **hx_token);

/* ft_parse_data.c */
char	*ft_extract_substring(const char *token, char c, int index);
void	ft_parse_data(char *token);

/* ft_parse_util.c */
int		ft_strlen_start(const char *str, int start, char c);
int		ft_setindex(char *token, int c);

/*ft_decimal_check.c*/
int		ft_decimal_check(char **de_token, char **hx_token);
void	ft_free_utils(char *mes, char **de_token, char **hx_token);

/*ft_free_args.c*/
void	ft_free_args(char **str, char ***strvec, char ****strthree);

#endif