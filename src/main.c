#include "mlx.h"
#include "mlx_defines.h"
// #include "mlx_int.h"
#include <libc.h>

#define HEIGHT 500
#define WIDTH 800


int close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx.ptr, mlx.window);
	exit(0);
}

int keypress(int key, void* para)
{
	if (key == KEY_ESC)
		close_win();
	printf("key press: %d\n", key);
	return 0;
}
int keyrelease(int key)
{
	printf("key release: %d\n", key);
	return 0;
}


int	main(void)
{
	t_mlx mlx;
	// void	*mlx;
	// void	*mlx_win;

	mlx.ptr = mlx_init(); // initialize library starting state
	mlx.window = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "Hello world!");

	mlx_hook(mlx.window, EVENT_DESTROY, 0, close_win, &mlx);
	mlx_hook(mlx.window, EVENT_KEYPRESS, 0, keypress, &mlx);
	mlx_hook(mlx.window, EVENT_KEYRELEASE, 0, keyrelease, &mlx);

	mlx_loop(mlx.ptr);
}