#include "mlx.h"
#include "mlx_defines.h"
#include "mlx_structures.h"
// #include "mlx_int.h"
#include <libc.h>

#define HEIGHT 500
#define WIDTH 800
#define BYTE_SIZE 8

int rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
// int rgba(int r, int g, int b, int a)
// {
// 	return (a << 24 | r << 16 | g << 8 | b);
// }


int close_win(t_mlx *mlx) 
{
	mlx_destroy_window(mlx->ptr, mlx->window);
	exit(0);
}



int keypress(int key,  t_mlx *mlx) 
{
	if (key == KEY_ESC)
		close_win(mlx);
	printf("key press: %d\n", key);
	return 0;
}
int keyrelease(int key, t_mlx *mlx) 
{
	(void)mlx;
	printf("key release: %d\n", key);
	return 0;
}

void pixel_put(t_image* img, int x, int y, int color)
{
	char	*addr;

	addr = img->px + (y * img->size_line + x * (img->bits_per_pixel / BYTE_SIZE));
	*(unsigned int*)addr = color;
}

void draw_square(t_mlx *mlx, int side, int x, int y)
{
	for (int i = x; i < x + side; ++i)
	{
		for(int j = y; j < y + side; ++j)
		{
			pixel_put(&mlx->main, i, j, rgb(255,0,0));
		}
	}
}


int	main(void)
{
	t_mlx mlx;
	// void	*mlx;
	// void	*mlx_win;

	mlx.ptr = mlx_init(); // initialize library starting state
	mlx.window = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "Hello world!");

	// create new image
	mlx.main.ptr = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	// get address of
	mlx.main.px = mlx_get_data_addr(mlx.main.ptr, &mlx.main.bits_per_pixel, &mlx.main.size_line, &mlx.main.endian);


	// hooks for events
	mlx_hook(mlx.window, EVENT_DESTROY, 0, close_win, &mlx);
	mlx_hook(mlx.window, EVENT_KEYPRESS, 0, keypress, &mlx);
	mlx_hook(mlx.window, EVENT_KEYRELEASE, 0, keyrelease, &mlx);
	

	// draw square in image
	draw_square(&mlx, 50, 20, 20);
	

	// put image to window on (0, 0) coordinates
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.main.ptr, 0,0); // nkar texadrel 
	mlx_loop(mlx.ptr);
}


#if 0

TODO: read c function attributes
for example __attribute__((unused))

Rendering loop	
glfwWindowShouldClose is true when the close button has been clicked.
while (!glfwWindowShouldClose(window)) {

}

#endif