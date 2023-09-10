/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:02:07 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/08 22:14:08 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @file fdf.h
* @brief Contains functions for working with the FDF project.
*
* This header file defines functions for the FDF project.
* FDF is a project aimed at creating a wireframe 
* representation of a 3D landscape. The functions in this
* file handle parsing map files, rendering wireframe graphics,
* and managing the 3D landscape representation.
*/
#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "fdf_define.h"
# include "fdf_structures.h"
# include "fdf_keys.h"
# include "mlx.h"

/**
* File: ft_parse_data.c
* Description: This file contains the implementation of the following functions.
*/
void		ft_parse(t_map *map, t_add *tab, int fd);
char		*ft_extract_substring(const char *token, char c, int index);
void		ft_parse_data(char *token, t_matrix *matrix);

/**
 * File: ft_hexdec_check.c 
 * Description: This file contains the implementation of the following functions.
 */
int			ft_hexdec_check(char **de_token, char **hx_token);

/**
 * File: ft_decimal_check.c
 * Description: This file contains the implementation of the following functions.
 */
int			ft_decimal_check(char **de_token, char **hx_token);

/**
* File: ft_determine.c
* Description: This file contains the implementation of the following functions.+
*/
int			ft_determine_width(t_add *tab, size_t arr_size);
void		ft_determine_x_y(t_map *map);

/**
* File: ft_parse_util.c
* Description: This file contains the implementation of the following functions.
*/
int			ft_strlen_start(const char *str, int start, char c);
int			ft_setindex(char *token, int c);

/**
* File: ft_push_back.c
* Description: This file contains the implementation of the following functions.
*/
void		ft_init(t_map *map, size_t size);
void		ft_push_back(t_matrix *m, t_point3d val);

/**
* File: ft_push_arrey.c
* Description: This file contains the implementation of the following functions.
*/
void		ft_init_arrey(t_add *tab, size_t size);
void		ft_push_arrey(t_add *tab, int val);

/**
* File: ft_config.c
* Description: This file contains the implementation of the following functions.
*/
void		ft_init_config(t_conf *config);
void		ft_init_mlx(t_mlx *mlx_data);
void		ft_config(t_map *map, t_conf config);

/**
* File: ft_key_config.c
* Description: This file contains the implementation of the following functions.
*/
void		ft_key_config(t_key_conf *key_conf);

/**
* File: ft_projection.c.
* Description: This file contains the implementation of the following functions.
*/
double		ft_deg_to_rad(double angle);
void		ft_isometric(t_point3d *cord, t_conf conf);
void		ft_dimetric(t_point3d *cord, t_conf conf);
void		ft_trimetric(t_point3d *cord, t_conf conf);
void		ft_change_projection(t_map *map, t_conf conf);

/**
 * File: ft_bresenham.c
 * Description: This file contains the implementation of the following functions.
 */
void		ft_bresenham(t_line_cord line_cord, t_image *img_data);

/**
* File: ft_drawing.c.
* Description: This file contains the implementation of the following functions.+
*/
void		ft_drow2d(t_mlx *mlx_data, t_map *map);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);

/**
* File: ft_free_args.c
* Description: This file contains the implementation of the following functions.+
*/
void		ft_free_args(char **str, char ***strvec, char ****strthree);
void		ft_free_utils(char *mes, char **de_token, char **hx_token);

/************* BONUS *************/

/**
* File: ft_hook_events.c
* Description: This file contains the implementation of the following functions.
*/
void		ft_hook_events(t_main *global);
void		ft_clear_window(t_image *img_data);

/**
* File: ft_rotate.c
* Description: This file contains the implementation of the following functions.
*/
t_point3d	ft_rotate_x(t_point3d cord, double angle);
t_point3d	ft_rotate_y(t_point3d cord, double angle);
t_point3d	ft_rotate_z(t_point3d cord, double angle);

/**
* File: ft_mouse_events.c
* Description: This file contains the implementation of the following functions.
*/
int			ft_mouse_move(int x, int y, t_main *global);
int			ft_mouse_release(int key, int x, int y, t_main *global);
int			ft_mouse_press(int key, int x, int y, t_main *global);

#endif