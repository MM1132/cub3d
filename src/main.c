#include <stdio.h>

#include "libft.h"
#include "MLX42.h"

int main()
{
	ft_printf("Hello, World!\n");

	mlx_t *mlx = mlx_init(1000, 600, "cub3D", true);
	mlx_loop(mlx);

	mlx_terminate(mlx);

	return (0);
}
