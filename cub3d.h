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

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_mlx
{

}				t_mlx;

typedef struct	s_win
{
    int				width;
    int				height;
    void			*ptr;
}               t_win;

typedef struct s_img
{

}               t_img;

typedef struct s_err
{

}               t_err;

typedef struct	s_main
{
    t_mlx			mlx;
    t_win			win;
    t_img			img;
    t_err			err;
}				t_main;

int				fileExtensionCheck(char *arg, char *ext);
int             fileFlagCheck(char *flagArg, char *flag);

int             fileConfigValidator(t_main *main, char *mapPath);

int             setResolution(t_main *main, char **resolutionLine);

#endif