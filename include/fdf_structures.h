#ifndef MLX_STRUCTURES_H
#define MLX_STRUCTURES_H

typedef struct s_image t_image;
typedef struct s_mlx t_mlx;
typedef struct s_point2d t_point2d;
typedef struct s_point3d t_point3d;
typedef struct s_vector2d t_vector2d;
typedef struct s_vector3d t_vector3d;
typedef struct s_calcul t_calcul;
typedef struct s_map t_map;
typedef enum e_projection t_projection;
typedef enum e_move t_move;


/*
* BONUS: 
* Include one extra projection (such as parallel or conic)!
*
* enum e_projection
*{
*	NONE,
*	ISOMETRIC,
*	DIAMETRIC
*}
*/
// enum e_projection
// {
// 	NONE,
// 	ISOMETRIC,
// 	DIAMETRIC
// };

// enum e_operation
// {
// 	ZOOM,
// 	SCALE,
// 	ROTATE
// };

// enum e_move
// {
// 	MOVEX,
// 	MOVEY,
// 	MOVEZ
// };

/*
* struct	s_image
*
*{
*	void	*ptr;
*	char	*data;
*	int		bits_per_pixel;
*	int		size_line;
*	int		endian;
*}
*/
struct	s_image
{
	void	*ptr;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

/*
* struct s_mlx
*
*{
*	void* ptr;
*	void* window;
*	t_image main;
*	int sidex;
*	int sidey;
}
*/
struct s_mlx
{
	void* ptr;
	void* window;
	t_image main;
	int sidex;
	int sidey;
};


/*
* struct s_point2d
*{
*	int x;
*	int y;
*};
*/
struct s_point2d
{
	int x;
	int y;
};


/*
* struct s_point3d
*{
*	int x;
*	int y;
*	int z;
*}
*/
struct s_point3d
{
	int x;
	int y;
	int z;
};

/*
* struct s_vector2d
*{
*	double x;
*	double y;
*}
*/
struct s_vector2d
{
	double x;
	double y;
};

/*
* struct s_vector3d
*{
*	double x;
*	double y;
*	double z;
*}
*/
struct s_vector3d
{
	double x;
	double y;
	double z;
};


/*
* struct s_map
*{
*	int width;
*	int height;
*	t_point3d *matrix;
*}
*/
struct s_map
{
	int width;
	int height;
	t_point3d *matrix;
};

/*
* struct s_calcul
*{
*	t_point2d sign;
*	t_point2d delta;
*	t_vector3d current;
*	int delta_error;
*}
*/
struct s_calcul
{
	t_point2d sign;
	t_point2d delta;
	t_vector3d current;
	int delta_error;
}; 

#endif