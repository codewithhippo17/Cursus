#include "fdf.h"

void ft_free_array(char **array)
{
    int i;

    i = 0;
    if (!array)
        return;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void ft_free_point(t_map *s_map)
{
    int i;

    if (!s_map || !s_map->point)
        return;
    i = 0;
    while (i < s_map->height)
    {
        if (s_map->point[i])
            free(s_map->point[i]);
        i++;
    }
    free(s_map->point);
    s_map->point = NULL;
}

void ft_free_map(t_map *s_map)
{
    if (!s_map)
        return;
    if (s_map->line)
        ft_free_array(s_map->line);
    ft_free_point(s_map);
    free(s_map);
}

void ft_free_env(t_fdf *env)
{
    if (!env)
        return;
        
    if (env->s_map)
    {
        if (env->s_map->line)
            ft_free_array(env->s_map->line);
        ft_free_point(env->s_map);
        free(env->s_map);
    }
    
    if (env->img)
        mlx_destroy_image(env->mlx, env->img);
        
    if (env->win)
        mlx_destroy_window(env->mlx, env->win);
        
    if (env->mlx)
    {
        mlx_destroy_display(env->mlx);
        free(env->mlx);
    }
    free(env);
}

void cleanup_and_exit(t_fdf *env)
{
    if (!env)
        return;
        
    if (env->img)
    {
        mlx_destroy_image(env->mlx, env->img);
        env->img = NULL;
    }
    
    if (env->win)
    {
        mlx_destroy_window(env->mlx, env->win);
        env->win = NULL;
    }
    
    if (env->mlx)
    {
        mlx_destroy_display(env->mlx);
        free(env->mlx);
        env->mlx = NULL;
    }
    ft_free_env(env);
    exit(0);
}