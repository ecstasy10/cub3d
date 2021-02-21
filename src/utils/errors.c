/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileConfig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:45:13 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/29 19:45:14 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error(char *errorId)
{
    ft_putstr_fd(HEADER, 1);
    ft_putstr_fd(TITLE, 1);
    ft_putstr_fd(errorId, 1);
    ft_putstr_fd(FOOTER, 1);
    exit(EXIT_FAILURE);
}

int		program_exit(t_main *main)
{
    mlx_destroy_window(main->mlx.ptr, main->win.ptr);
    system("leaks cub3D");
    exit(EXIT_SUCCESS);
    return (1);
}