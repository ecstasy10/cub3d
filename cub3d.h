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

# include "libft/libft.h"
# include <limits.h>
# include <math.h>
# include "mlx/mlx.h"
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
# define E_MAP_FILE ANSI_COLOR_YELLOW "Map File not found!\n Map file should have .cub extension." ANSI_COLOR_RESET
# define E_RES_ORDER E_FILE ANSI_COLOR_YELLOW "Resolution must be in the first line." ANSI_COLOR_RESET
# define E_RES ANSI_COLOR_YELLOW "Bad Resolution format, try -> R [WIDTH] [HEIGHT]\n\tMax size: 1920x1080\n" ANSI_COLOR_RESET
# define E_TEX_ORDER E_FILE ANSI_COLOR_YELLOW "Texture must be four lines between resolution and colors." ANSI_COLOR_RESET
# define E_TEX E_FILE ANSI_COLOR_YELLOW "Bad Texture file, files should have .xpm extension" ANSI_COLOR_RESET
# define E_COLOR_ORDER E_FILE ANSI_COLOR_YELLOW " Colors must be in the last two lines." ANSI_COLOR_RESET
# define E_MAP ANSI_COLOR_YELLOW "Map bad formatted" ANSI_COLOR_RESET
# define E_NOT_PLAYER E_FILE ANSI_COLOR_YELLOW "Player not found." ANSI_COLOR_RESET
# define E_PLAYER E_FILE ANSI_COLOR_YELLOW "Player already set." ANSI_COLOR_RESET


typedef	struct		s_dvec
{
    double			x;
    double			y;
}					t_dvec;

typedef struct		s_draw
{
    int				    f_rgb;
    int				    c_rgb;
}					t_draw;

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

typedef struct      s_tex
{
    struct Stack*       path;
    char                *sprite;
}                   t_tex;

typedef struct	    s_main
{
    t_win			    win;
    t_tex               tex;
    t_draw              draw;
    t_map               map;
    t_player            player;
    t_dvec			    dir;
    t_dvec			    plane;
    t_dvec			    *sprite;
}				    t_main;

void	        error(char *errorId);
int				fileExtensionCheck(char *arg, char *ext);
int             fileFlagCheck(char *flagArg, char *flag);
int             fileConfigValidator(t_main *main, char *mapPath);
void            validateResolution(t_main *main, char **resolutionLine);
int             validateTextures(t_main *main, char **texturesLine);
void            validateColors(t_main *main, char **colorLine);
int             validateMap(t_main *main);
void            isPlayer(t_main *main, unsigned int y, unsigned int x);
void            spriteControl(t_main *main, int y, int x);

// Stack import
struct Stack*   createStack(int capacity);
char            **peek(struct Stack* stack);
void            push(struct Stack* stack, char *item);
int             pop(struct Stack* stack);

#endif