/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:04:18 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/23 19:18:35 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <limits.h>
# include <math.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define HEADER ANSI_COLOR_CYAN "\n############# 42-CUB3D by @dbalboa- ##############\n\n" ANSI_COLOR_RESET
# define FOOTER ANSI_COLOR_CYAN "\n\n##################################################\n" ANSI_COLOR_RESET
# define TITLE ANSI_COLOR_BLUE "There were some errors:\n" ANSI_COLOR_RESET
# define E_FILE ANSI_COLOR_YELLOW "Bad Map file format,\n\t" ANSI_COLOR_RESET

# define E_ARGS ANSI_COLOR_YELLOW "Wrong arguments, try -> ./cub3d [map] [--save]" ANSI_COLOR_RESET
# define E_FLAG ANSI_COLOR_YELLOW "Wrong flag, try -> ./cub3d [map] [--save]" ANSI_COLOR_RESET
# define E_MAP_FILE ANSI_COLOR_YELLOW "Map file not found!" ANSI_COLOR_RESET
# define E_MAP_FILE_EXT E_MAP_FILE ANSI_COLOR_YELLOW "\n Map file should have .cub extension." ANSI_COLOR_RESET
# define E_RES_ORDER E_FILE ANSI_COLOR_YELLOW "Resolution must be in the first line." ANSI_COLOR_RESET
# define E_RES ANSI_COLOR_YELLOW "Bad Resolution format, try -> R [WIDTH] [HEIGHT]\n\tMax size: 1920x1080\n" ANSI_COLOR_RESET
# define E_TEX_ORDER E_FILE ANSI_COLOR_YELLOW "Texture must be four lines between resolution and colors." ANSI_COLOR_RESET
# define E_TEX E_FILE ANSI_COLOR_YELLOW "Bad Texture file, files should have .xpm extension" ANSI_COLOR_RESET
# define E_COLOR_ORDER E_FILE ANSI_COLOR_YELLOW " Colors must be in the last two lines." ANSI_COLOR_RESET
# define E_MAP ANSI_COLOR_YELLOW "Map bad formatted" ANSI_COLOR_RESET
# define E_NOT_PLAYER E_FILE ANSI_COLOR_YELLOW "Player not found." ANSI_COLOR_RESET
# define E_PLAYER E_FILE ANSI_COLOR_YELLOW "Player already set." ANSI_COLOR_RESET
# define E_SPRITE E_FILE ANSI_COLOR_YELLOW "Sprite error." ANSI_COLOR_RESET

# define ESC_KEY	53
# define W_KEY		13
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define LEFT_KEY	123
# define RIGHT_KEY	124

typedef	struct		s_dvec
{
    double			x;
    double			y;
}					t_dvec;

typedef struct		s_ivec
{
    int				x;
    int				y;
}					t_ivec;

typedef struct	    s_win
{
    int				    width;
    int				    height;
    void			    *ptr;
}                   t_win;

typedef struct      s_map
{
    unsigned int        rows;
    unsigned int        columns;
    char                **table;
    int                 spritesLength;
}                   t_map;

typedef struct      s_player
{
    double			    x;
    double			    y;
    double			    mspeed;
    double			    rspeed;
}                   t_player;

typedef struct		s_img
{
    void			    *ptr;
    char			    *buffer;
    int				    *buff;
    int				    bits_per_pixel;
    int				    size_line;
    int				    endian;
}					t_img;

typedef struct      s_tex
{
    char                *path;
    int                 is_sprite;
    int				    x;
    int				    y;
    double			    step;
    double			    pos;
    t_img			    *img;
    int				    width;
    int				    height;
}                   t_tex;

typedef struct		s_sprite
{
    t_ivec			    start;
    t_ivec			    end;
    int				    width;
    int				    height;
    double		    	x;
    double		    	y;
    double		    	inver;
    t_dvec		    	transform;
    int			    	win;
}					t_sprite;

typedef struct		s_draw
{
    int				    height;
    int				    start;
    int				    end;
    int				    f_rgb;
    int				    c_rgb;
    double			    *z_buffer;
    t_sprite		    sprite;
}					t_draw;

typedef struct		s_mlx
{
    void			    *ptr;
}					t_mlx;

typedef	struct		s_cam
{
    double			    x;
}					t_cam;

typedef struct		s_side
{
    t_dvec			    dist;
}					t_side;

typedef struct		s_wall
{
    double			    dist;
    int				    hit;
    int				    side;
    double			    x;
}					t_wall;

typedef struct		s_ray
{
    int				    x;
    t_dvec			    dir;
    t_cam			    cam;
    t_side			    side;
    t_dvec			    delta;
    t_wall			    wall;
    t_ivec			    step;
}					t_ray;

typedef struct	    s_main
{
    t_win			    win;
    t_tex               tex[5];
    t_draw              draw;
    t_map               map;
    t_player            player;
    t_dvec			    dir;
    t_dvec			    plane;
    t_dvec			    *sprite;
    t_mlx			    mlx;
    t_ray			    ray;
    t_img			    img;
    t_ivec			    maze;
    int                 tex_it;
    int				    *sprite_order;
    int				    sprite_count;
    double			    *sprite_dist;
    int			    	keyboard[125];
}				    t_main;

// File Validation
void	        error(char *errorId);
int				fileExtensionCheck(char *arg, char *ext);
int             fileFlagCheck(char *flagArg, char *flag);
int             fileConfigValidator(t_main *main, char *mapPath);
void            validateResolution(t_main *main, char **resolutionLine);
int             validateTextures(t_main *main, char **texturesLine);
void            validateColors(t_main *main, char **colorLine);
int             validateMap(t_main *main);
void            isPlayer(t_main *main, unsigned int y, unsigned int x);
void            sprite_control(t_main *main, int y, int x);
void	        sprite_init(t_main *main, int count);

// Graphics
int		        map_init(t_main *main);
void            window_initialize(t_main *main);
void	        texture_initialize(t_main *main);
int		        texture_sort(t_main *main);
void	        texture_calculate(t_main *main, int i);
void		    wall_raycast(t_main *main);
void		    sprite_raycast(t_main *main);
void		    vertical_draw(t_main *main, int x, int i);
void		    sprite_draw(t_main *main);
int		        display(t_main *main);
int		        bitmap_save(t_main *main);
void	        image_render(t_main *main);
void        	speed_initialize(t_main *main);

// Utils
double	        dist(double x1, double x2);
int		        key_press(int keycode, t_main *main);
int		        key_release(int keycode, t_main *main);
int		        key_core(t_main *main);
int		        program_exit(t_main *main);

// Stack import
struct Stack*   createStack(int capacity);
char            *peek(struct Stack* stack, int index);
void            push(struct Stack* stack, char *item);
int             pop(struct Stack* stack);
int             isFull(struct Stack* stack);

#endif