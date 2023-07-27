/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:22:28 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/27 12:18:02 by hyungjpa         ###   ########.fr       */
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


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

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

}   t_info;


char	*get_next_line(int fd);
char	*do_free(char **s);
size_t	gnl_strlen(char *s);
int	    gnl_strchr(char *s, char c);
char	*gnl_strjoin(char **s1, char *s2);

// info_init
int    init_info(t_info *info);

// utils
int ft_sstrlen(char **tmp);
int print_error(void);
void    display(t_info *info);


// info_parse_1
int parse_file(int fd, t_info *info);

// info_parse_2
int parse_info(char *s, t_info *info);
int parse_map(char *s, t_info *info);


// valid_info
int valid_info(t_info *info);

// info_valid_2
int check_map_args(t_info *info);
int check_map_cross(t_info *info);


// free
int free_str(char *s, int res);
char    **free_split_fail(char **s, int n);
int free_split(char **s, int res);
int free_info(t_info *info, int res);


#endif