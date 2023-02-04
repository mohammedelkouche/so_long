#include <mlx.h>
#include <stdlib.h>

int main()
{
    void    *mlx_ptr;
    void    *mlx_win;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 1029, 1090, "so_long");
    mlx_loop(mlx_ptr);
    free(mlx_ptr);
}