/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:22:28 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/08/08 17:25:28 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# define WIDTH 600
# define HEIGHT 400

# define WHEEL_UP 4
# define WHEEL_DOWN 5

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define ESC 53

# define ROT_SPEED 0.10
# define MOV_SPEED 0.10

typedef enum e_flag
{
    SUCCESS,
    FAIL
}   t_flag;

typedef struct s_info
{
    
    int     *dir_flags; // n, s, w, e, f, c

    int     map_flag;

    char    **dir; // 4
    
    char    **fc; //6
    
    int     *fc_num; // 6

    char    *map_before;

    char    **map;
    char    **map_test;

    int     height;
    int     width;

    char    player_dir;

    int     player_x;
    int     player_y;

}   t_info;

typedef struct s_var
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_l;
    int     endian;


    double  cameraX;

    int  mapX;
    int  mapY;


    int     side;

    double  posX;
    double  posY;

    double  dirX;
    double  dirY;

    double  planeX;
    double  planeY;

    double  rayDirX;
    double  rayDirY;

    int     stepX;
    int     stepY;


    double  sideDistX;
    double  sideDistY;

    double  deltaDistX;
    double  deltaDistY;

    double  perpWallDist;


    t_info  *info;
}       t_var;


char	*get_next_line(int fd);
char	*do_free(char **s);
size_t	gnl_strlen(char *s);
int	    gnl_strchr(char *s, char c);
char	*gnl_strjoin(char **s1, char *s2);

// args_check
t_flag  check_arg(int ac, char **av);

// info_init
t_flag  init_info(t_info *info);
void    var_init(t_var *var, t_info *info);

// utils
int     ft_sstrlen(char **tmp);
t_flag  print_error(char *msg);
void    display(t_info *info);


// info_parse_1
t_flag  parse_file(int fd, t_info *info);

// info_parse_2
t_flag  parse_info(char *s, t_info *info);
t_flag  parse_map(char *s, t_info *info);


// valid_info
t_flag  valid_info(t_info *info);

// info_valid_2
t_flag  check_map_args(t_info *info);
t_flag  check_map_cross(t_info *info);


// free
int free_str(char *s, int res);
char    **free_split_fail(char **s, int n);
int free_split(char **s, int res);
int free_info(t_info *info, int res);



// cub3d_mlx
void	my_mlx_pixel_put(t_var *var, int x, int y, int color);
void    start_mlx(t_var *var);

//draw
void    draw_fc(t_var *var);

//key hook
void    key_hook_main(t_var *var);
void    key_move_left(t_var *var);
void    key_move_right(t_var *var);
void    key_move_forward(t_var *var);
void    key_move_backward(t_var *var);
void    key_rotate_left(t_var *var);
void    key_rotate_right(t_var *var);

#endif