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


void	ft_is_xvalue(char *token);
void	ft_parse_data(char *token);
void	ft_panic(char *str);

#endif