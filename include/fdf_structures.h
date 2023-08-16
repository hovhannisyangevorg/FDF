/**
 * @file fdf_structs.h
 * @brief Contains definitions of data structures for the FDF project.
*/

#ifndef MLX_STRUCTURES_H
#define MLX_STRUCTURES_H

typedef struct s_image t_image;

typedef struct s_mlx t_mlx;
typedef struct s_point3d t_point3d;
typedef struct s_vector3d t_vector3d;
typedef struct s_matrix t_matrix;
typedef struct s_map t_map;
typedef struct s_add t_add;
typedef struct 	s_decimal_check t_decimal_check;
// typedef struct s_vector2d t_vector2d;
// typedef struct s_point2d t_point2d;
// typedef struct s_calcul t_calcul;
// typedef enum e_projection t_projection;
// typedef enum e_move t_move;



/**
 * @struct s_image
 * @brief Represents an image with associated properties.
 *
 * This structure defines information about various image properties.+
*/
struct	s_image
{
	void	*ptr;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

/**
 * @struct s_mlx
 * @brief Represents the MLX (MiniLibX) graphics context.
 *
 * This structure defines a graphics context using the MiniLibX library.+
*/
struct s_mlx
{
	void* ptr;
	void* window;
	t_image main;
	int sidex;
	int sidey;
};

/**
 * @struct s_point3d
 * @brief Represents a 3D point with associated properties.
 *
 * This structure defines a 3D point in space along with its coordinates and color.+
*/
struct s_point3d
{
	int x;
	int y;
	int z;
	int color;
};

/**
 * @struct s_vector3d
 * @brief Represents a 3D vector with associated properties.
 * 
 * This structure defines a 3D vector in space with its coordinates and color simply+
 * by using << double >>.
*/
struct s_vector3d
{
	double 	x;
	double 	y;
	double 	z;
	int 	color;
};


/**
 * @struct s_line_cord
 * @brief Represents the coordinates and color of a line +
 * Bresenham Line algorithm.
*/
typedef struct s_line_cord
{
	int x1; 
	int y1;
	int z1;
	int x2; 
	int y2;
	int z2;
	int color;
} t_line_cord;

/**
 * @struct s_distance_formula
 * @brief Represents the coordinates and distances of the distance formula +
 * Bresenham Line algorithm.
*/
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

























struct s_matrix
{
	t_point3d	*cord;
	size_t		capacity;
	size_t		size;
};

struct s_map
{
	t_matrix matrix;
	size_t height;
	size_t width;
};

struct s_calcul
{
	t_point3d 	*math;
	t_vector3d	*vector;
};

/*
*{
*    int *arr;
*    int size;
*    int capacity;
*}
*/
struct s_add
{
    int *arr;
    size_t size;
    size_t capacity;
};

struct s_decimal_check
{
	size_t	i;
	int		res;
	int		sign;
	int		mult;
};
// function (matrix* m, t_point3d)
// if capacity is 0 change capacity and size to 1 and allocate memory for 1 point
// if matrix size grater than it capacity
// allocate memory in size and copy content to it after free previus memory


#endif



// #ifndef MLX_STRUCTURES_H
// #define MLX_STRUCTURES_H

// typedef struct s_image t_image;
// typedef struct s_mlx t_mlx;
// typedef struct s_point2d t_point2d;
// typedef struct s_point3d t_point3d;
// typedef struct s_vector2d t_vector2d;
// typedef struct s_vector3d t_vector3d;
// typedef struct s_calcul t_calcul;
// typedef struct s_map t_map;
// typedef enum e_projection t_projection;
// typedef enum e_move t_move;


// /*
// * BONUS: 
// * Include one extra projection (such as parallel or conic)!
// *
// * enum e_projection
// *{
// *	NONE,
// *	ISOMETRIC,
// *	DIAMETRIC
// *}
// */
// // enum e_projection
// // {
// // 	NONE,
// // 	ISOMETRIC,
// // 	DIAMETRIC
// // };

// // enum e_operation
// // {
// // 	ZOOM,
// // 	SCALE,
// // 	ROTATE
// // };

// // enum e_move
// // {
// // 	MOVEX,
// // 	MOVEY,
// // 	MOVEZ
// // };

// /*
// * struct	s_image
// *
// *{
// *	void	*ptr;
// *	char	*data;
// *	int		bits_per_pixel;
// *	int		size_line;
// *	int		endian;
// *}
// */
// struct	s_image
// {
// 	void	*ptr;
// 	char	*data;
// 	int		bits_per_pixel;
// 	int		size_line;
// 	int		endian;
// };

// /*
// * struct s_mlx
// *
// *{
// *	void* ptr;
// *	void* window;
// *	t_image main;
// *	int sidex;
// *	int sidey;
// }
// */
// struct s_mlx
// {
// 	void* ptr;
// 	void* window;
// 	t_image main;
// 	int sidex;
// 	int sidey;
// };


// /*
// * struct s_point2d
// *{
// *	int x;
// *	int y;
// *};
// */
// struct s_point2d
// {
// 	int x;
// 	int y;
// };


// /*
// * struct s_point3d
// *{
// *	int x;
// *	int y;
// *	int z;
// *}
// */
// struct s_point3d
// {
// 	int x;
// 	int y;
// 	int z;
// };

// /*
// * struct s_vector2d
// *{
// *	double x;
// *	double y;
// *}
// */
// struct s_vector2d
// {
// 	double x;
// 	double y;
// };

// /*
// * struct s_vector3d
// *{
// *	double x;
// *	double y;
// *	double z;
// *}
// */
// struct s_vector3d
// {
// 	double x;
// 	double y;
// 	double z;
// };


// /*
// * struct s_map
// *{
// *	int width;
// *	int height;
// *	t_point3d *matrix;
// *}
// */
// struct s_map
// {
// 	int width;
// 	int height;
// 	t_point3d *matrix;
// };

// /*
// * struct s_calcul
// *{
// *	t_point2d sign;
// *	t_point2d delta;
// *	t_vector3d current;
// *	int delta_error;
// *}
// */
// struct s_calcul
// {
// 	t_point2d sign;
// 	t_point2d delta;
// 	t_vector3d current;
// 	int delta_error;
// }; 

// #endif