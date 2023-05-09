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

int get_pixel_color(t_image* img, int x, int y)
{
	char	*addr;

	addr = img->px + (y * img->size_line + x * (img->bits_per_pixel / BYTE_SIZE));
	return *(int*)addr;
}

void draw_square(t_mlx *mlx, int side)
{
	for (int i = 0; i < side; ++i)
	{
		for(int j = 0; j < side; ++j)
		{
			pixel_put(&mlx->square, i, j, rgb(255,0,0));
		}
	}
}

void put_image_to_main(t_image* main, t_image* img, int x, int y)
{
	for (int i = x; i < x + 20; ++i)
	{
		for (int j = y; j < y + 20; ++j)
		{
			pixel_put(main, i, j, get_pixel_color(img, i - x, j - y));
		}
	}
}

void clear_window(t_image* main)
{
	for (int x = 0; x < WIDTH; ++x)
	{
		for (int y = 0; y < HEIGHT; ++y)
		{
			pixel_put(main, x, y, rgb(0,0,0));
		}
	}
}


int render(t_mlx* mlx)
{
	static int i = 0;
	static int j = 0;
	clear_window(&mlx->main);
	draw_square(mlx, 40);
	if (i + 40 >= 640)
		mlx->sidex = -1;
	if (j + 40 >= 480)
		mlx->sidey = -1;
	if (i - 40 <= 0 && mlx->sidex < 0)
		mlx->sidex = 1;
	if (j - 40 <= 0 && mlx->sidey < 0)
		mlx->sidey = 1;
	put_image_to_main(&mlx->main, &mlx->square, i, j);
	i += mlx->sidex;
	j += mlx->sidey;
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->main.ptr, 0, 0);
	return 0;
}


int	main(void)
{
	t_mlx mlx;
	mlx.ptr = mlx_init(); // initialize library starting state
	mlx.window = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "Hello world!");
	mlx.sidex = 1;
	mlx.sidey = 1;
	// create new image
	mlx.main.ptr = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx.square.ptr = mlx_new_image(mlx.ptr, 20, 20);
	// mlx_xpm_file_to_image()
	// get address of
	mlx.main.px = mlx_get_data_addr(mlx.main.ptr, &mlx.main.bits_per_pixel, &mlx.main.size_line, &mlx.main.endian);
	mlx.square.px = mlx_get_data_addr(mlx.square.ptr, &mlx.square.bits_per_pixel, &mlx.square.size_line, &mlx.square.endian);
	printf("bpp: %d\nsize_line: %d\n", mlx.main.bits_per_pixel, mlx.main.size_line);
	// hooks for events
	mlx_hook(mlx.window, EVENT_DESTROY, 0, close_win, &mlx);
	mlx_hook(mlx.window, EVENT_KEYPRESS, 0, keypress, &mlx);
	mlx_hook(mlx.window, EVENT_KEYRELEASE, 0, keyrelease, &mlx);
	

	// draw square in image

	// mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.main.ptr, 0, 0);
	

	// put image to window on (0, 0) coordinates
	mlx_loop_hook(mlx.ptr, render, &mlx);
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