#ifndef MLX_STRUCTURES_H
#define MLX_STRUCTURES_H

typedef struct s_mlx t_mlx;
typedef struct s_image t_image;

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
};



#endif