/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:02:07 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/01 20:39:12 by gevorg           ###   ########.fr       */
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

# include "fdf_define.h"
# include "fdf_structures.h"
# include "libft.h"
# include "mlx.h"

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
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);




/*path->   ft_config.c*/
void	ft_init_config(t_conf *config);
void	ft_config(t_map *map, t_conf config);
double	ft_deg_to_rad(double angle);





/*path->  ft_projection.c*/
double	ft_deg_to_rad(double angle);
void	ft_isometric(t_point3d *cord, t_conf conf);
void	ft_dimetric(t_point3d *cord, t_conf conf);
void	ft_trimetric(t_point3d *cord, t_conf conf);
void	ft_change_projection(t_map *map, t_conf conf);                   

// ft_bresenham.c
void ft_bresenham(t_line_cord line_cord, t_image *img_data);



// ft_rotate.c
t_point3d ft_rotate_x(t_point3d cord, double angle);
t_point3d ft_rotate_y(t_point3d cord, double angle);
t_point3d ft_rotate_z(t_point3d cord, double angle);


/*
    ! TODO: [Remove this function for fdf projects. ft_print_matrix()]
*/
void	ft_print_arrey(t_add *tab, size_t size);
void	ft_print_matrix(t_matrix *m);



#endif