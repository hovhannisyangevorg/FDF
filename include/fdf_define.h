/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:37:21 by gehovhan          #+#    #+#             */
/*   Updated: 2023/09/08 16:37:42 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_H
# define FDF_DEFINE_H

typedef enum e_projection	t_projection;
typedef enum e_operation	t_operation;
typedef enum e_move			t_move;
typedef enum e_key_event	t_key_event;

/**
 * @struct Screen Settings
 * @brief Represents settings for the screen dimensions and zoom.
 */
# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 800
# define SCREEN_ZOOM 20

/**
 * @def DEFAULT_COLOR
 * @brief Coordinate default color represented as an RGB value.
 */
# define DEFAULT_COLOR	0xff0000

/**
 * @struct Error Messages
 * @brief Constants for error messages.
 */
# define INVALID_COLOR		"Error: Invalid color !"
# define INVALID_OVERFLOW	"Error: Overflow error !"
# define INVALID_MAP		"Error: Invalid map is not square !"
# define INVALID_MLX		"Minilibx not initialize !"

/** 
* @def SCREEN ZMOD
* @brief Screen zoom mode for <Z> coordinate.
*/
# define SCREEN_ZMOD 11

enum e_projection
{
	ISOMETRIC,
	DIAMETRIC,
	TRIMETRIC,
	NONE
};

/**
 * @enum e_key_event
 * @brief Enumeration representing keyboard events.
 */
enum e_key_event
{
	RELEASE,
	PRESS
};

#endif
