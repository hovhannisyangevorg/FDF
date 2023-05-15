#ifndef MLX_STRUCTURES_H
#define MLX_STRUCTURES_H

typedef struct s_mlx t_mlx;
typedef struct s_image t_image;
typedef struct s_point t_point;
typedef	struct s_coord t_coord;


struct s_point
{
	int x;
	int y;
	int z;
};

struct s_coord
{
	double x;
	double y;
	double z;
};






struct	s_image
{
	void	*ptr;
	char	*px;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_mlx
{
	void* ptr;
	void* window;
	t_image main;
	t_image square;
	int sidex;
	int sidey;
};



#endif