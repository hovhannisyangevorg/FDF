/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:02:07 by gehovhan          #+#    #+#             */
/*   Updated: 2023/08/16 18:57:19 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @file fdf.h
* @brief Contains functions for working with the FDF project.
*
* This header file defines functions for the FDF project.
* FDF is a project aimed at creating a wireframe representation of a 3D landscape.
* The functions in this file handle parsing map files, rendering wireframe graphics,
* and managing the 3D landscape representation.
*/
#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "mlx.h"
# include "fdf_structures.h"
# include "libft.h"

# define INVALID_COLOR "Error: Invalid color!\n"
# define INVALID_OVERFLOW "Error: Overflow error\n"
# define DEFAULT_COLOR (0xffffff)  // (255 << 16 | 0 << 8 | 0)

/**
 * File: ft_parse_data.c
 * Description: This file contains the implementation of the following functions.+
 */
void		ft_parse(t_map *map, t_add *tab, int fd);
char		*ft_extract_substring(const char *token, char c, int index);
void		ft_parse_data(char *token, t_matrix *matrix);

/**
 * File: ft_parse_util.c
 * Description: This file contains the implementation of the following functions.+
 */
int			ft_strlen_start(const char *str, int start, char c);
int			ft_setindex(char *token, int c);

/**
 * File: ft_hexdec_check.c 
 * Description: This file contains the implementation of the following functions.+
 */
int			ft_hexdec_check(char **de_token, char **hx_token);

/**
 * File: ft_decimal_check.c
 * Description: This file contains the implementation of the following functions.+
 */
int			ft_decimal_check(char **de_token, char **hx_token);

/**
 * File: ft_free_args.c
 * Description: This file contains the implementation of the following functions.+
 */
void		ft_free_args(char **str, char ***strvec, char ****strthree);
void        ft_free_utils(char *mes, char **de_token, char **hx_token);

/**
 * File: ft_determine.c
 * Description: This file contains the implementation of the following functions.+
 */
int         ft_determine_width(t_add *tab, size_t arr_size);
void	    ft_determine_x_y(t_map *map);

/**
 * File: ft_push_back.c
 * Description: This file contains the implementation of the following functions.+
 */
void		ft_init(t_map *map, size_t size);
void		ft_push_back(t_matrix *m, t_point3d val);

/**
 * File: ft_push_arrey.c
 * Description: This file contains the implementation of the following functions.+
 */
void		ft_init_arrey(t_add *tab, size_t size);
void		ft_push_arrey(t_add *tab, int val);

/**
 * File: ft_drawing.c
 * Description: This file contains the implementation of the following functions.
 */
void	ft_drawing(t_point3d dr_cord);

/**
 * File: ft_draw_line.c
 * Description: This file contains the implementation of the following functions.
 */
void    ft_draw_line(t_line_cord *cord);













/*
    ! TODO: [Remove this function for fdf projects. ft_print_matrix()]
*/
void	ft_print_arrey(t_add *tab, size_t size);
void	ft_print_matrix(t_matrix *m);



#endif