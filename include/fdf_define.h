#ifndef FDF_DEFINE_H
#define FDF_DEFINE_H

typedef enum	e_projection t_projection;
typedef enum	e_operation t_operation;
typedef enum	e_move t_move;

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
# define DEFAULT_COLOR (255 << 16 | 18 << 8 | 0)

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

enum e_operation
{
	ZOOM,
	SCALE,
	ROTATE
};


enum e_move
{
	MOVEX,
	MOVEY,
	MOVEZ
};

#endif
