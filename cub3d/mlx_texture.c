#include "main.h"

static void set_dir_xpm(t_var *var, int toward)
{
    int     tmp;
    t_text  *tex;

    tex = &var->info->text_arr[toward];
    tex->img = mlx_xpm_file_to_image(var->mlx, var->info->dir[toward], \
                                    &tmp, &tmp);
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_l, \
                                    &tex->endian);
}

void    init_xpm_files(t_var *var)
{
    set_dir_xpm(var, NO);
    set_dir_xpm(var, SO);
    set_dir_xpm(var, WE);
    set_dir_xpm(var, EA);
}
