#include "main.h"

static int set_dir_xpm(t_var *var, int toward)
{
    int     tmp;
    t_text  *tex;

    tex = &var->info->text_arr[toward];
    tex->img = mlx_xpm_file_to_image(var->mlx, var->info->dir[toward],\
                                    &tmp, &tmp);
    if (!tex->img)
        return (FAIL);
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_l,\
                                    &tex->endian);
    return (SUCCESS);
}

int    init_xpm_files(t_var *var)
{
    if (set_dir_xpm(var, NO) == FAIL)
        return (FAIL);
    if (set_dir_xpm(var, SO) == FAIL)
        return (FAIL);
    if (set_dir_xpm(var, WE) == FAIL)
        return (FAIL);
    if (set_dir_xpm(var, EA) == FAIL)
        return (FAIL);
    return (SUCCESS);
}
