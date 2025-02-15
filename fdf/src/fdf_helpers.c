#include "fdf.h"

// #include <stdio.h>
// #include "../includes/libft/libft.h"


int v_filename(char *filename)
{
    char *tmp;
    int len;

    len = ft_strlen(filename);
    tmp = ft_strnstr(filename, ".fdf", len);
    if (tmp && tmp[4] == '\0' && len > 4)
        return (1);
    return (0);
}

void    ft_get_display(t_fdf *env)
{
    Display *display;
    display = XOpenDisplay(NULL);
    if (!display)
        ret_error("Cannot open display", env, 1);
    env->screen_width = DisplayWidth(display, DefaultScreen(display));
    env->screen_height = DisplayHeight(display, DefaultScreen(display));
    XCloseDisplay(display);
}

int ft_file_format(t_fdf *env, char *filename)
{
    char *path;
    int fd;
    path = ft_strjoin(CURRENT_DIR, filename);
    if (!path)
        ret_error("malloc error", env, 1);
    if (!(v_filename(filename)))
        ret_error("Invalid file name", env, 1);
    fd = open(path, O_RDONLY);
    free(path);
    if (fd == -1)
        ret_error("open error", env, 1);
    return (fd);
}