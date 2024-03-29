/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:57:11 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/08 15:54:48 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

/**
 * @file fdf_structs.h
 * @brief Contains definitions of data structures for the FDF project.
 */
typedef struct s_mlx			t_mlx;
typedef struct s_image			t_image;
typedef struct s_point3d		t_point3d;
typedef struct s_matrix			t_matrix;
typedef struct s_map			t_map;
typedef struct s_transform		t_transform;
typedef struct s_add			t_add;
typedef struct s_line_cord		t_line_cord;
typedef struct s_calcul_bresen	t_calcul_bresen;
typedef struct s_conf			t_conf;
typedef struct s_decimal_check	t_decimal_check;
typedef struct s_main			t_main;
typedef struct s_key_conf		t_key_conf;

/**
 * @struct s_image
 * @brief Represents an image with associated properties.
 *
 */
struct	s_image
{
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

/**
 * @struct s_mlx
 * @brief Represents the MLX (MiniLibX) graphics context.
 *
 */
struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img_data;
	int		side_x;
	int		side_y;
};

/**
 * @struct s_point3d
 * @brief Represents a 3D point with associated properties.
 *
 */
struct s_point3d
{
	double		x;
	double		y;
	double		z;
	int			color;
};

/**
 * @struct s_matrix
 * @brief Represents a matrix of 3D points with associated properties.
 *
 */
struct s_matrix
{
	t_point3d	*cord;
	size_t		capacity;
	size_t		size;
};

/**
 * @struct s_map
 * @brief Represents a map with associated properties.
 *
 */
struct s_map
{
	t_matrix	matrix;
	size_t		height;
	size_t		width;
};

/**
 * @struct s_add
 * @brief Represents a dynamic array with associated properties.
 * 
 */
struct s_add
{
	int			*arr;
	size_t		size;
	size_t		capacity;
};

/**
 * @struct s_decimal_check
 * @brief Represents information for a supported decimal check operation.
 * 
 */
struct s_decimal_check
{
	size_t		i;
	int			res;
	int			sign;
	int			mult;
};

/**
 * @struct s_line_cord
 * @brief Represents the coordinates and color of a line segment.
 * 
 */
struct s_line_cord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				color;
};

/**
 * @struct s_calcul_bresen
 * @brief Represents parameters for the Bresenham line drawing algorithm.
 * 
 */
struct s_calcul_bresen
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				pk;
};

struct s_transform
{
	double			x;
	double			y;
	double			z;
};

/**
 * @struct s_conf
 * @brief Represents configuration parameters for a 3D transformation.
 */
struct s_conf
{
	int				x_move;
	int				y_move;
	double			z_mode;
	double			zoom;
	t_projection	projection;
	t_transform		rotation;
};

/**
 * @struct s_key_conf
 * @brief Keyboard configuration struct.
 */
struct s_key_conf
{
	t_key_event		w;
	t_key_event		a;
	t_key_event		s;
	t_key_event		d;
	t_key_event		up;
	t_key_event		down;
	t_key_event		left;
	t_key_event		right;
};

/**
* @struct s_main
* @brief Main data structure for the application.
*/
struct s_main
{
	t_mlx			mlx_data;
	t_map			map_data;
	t_add			tab_data;
	t_conf			config;
	t_key_conf		key_conf;
};

#endif
