#include "/usr/include/minilibx-linux/mlx.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

int close_window(void *param)
{
    (void)param;
    printf("Window closed!\n");
    exit(0); // Exit the program
    return (0);
}

int main(void)
{
    void    *mlx; // Display
    void    *mlx_win; // Window
    t_data  image; // Image
    Atom    wm_delete_window;

    // Initialize connection to the X server
    mlx = mlx_init();
    if (mlx == NULL) {
        return 1;
    }

    // Create a new window
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    if (mlx_win == NULL) {
        return 1;
    }

    // Create a new image
    image.img = mlx_new_image(mlx, 1920, 1080);
    if (image.img == NULL) {
        return 1;
    }

    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
    mlx_hook(mlx_win, 33, 0, close_window, NULL);
    mlx_loop(mlx);

    return 0;
}