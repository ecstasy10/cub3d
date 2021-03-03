/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapconfigValidator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:33:07 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/28 19:33:10 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	image_render(t_main *main)
{
    main->img.ptr = mlx_new_image(main->mlx.ptr, main->win.width, main->win.height);
    main->img.buffer = mlx_get_data_addr(main->img.ptr, &main->img.bits_per_pixel,
                                        &main->img.size_line, &main->img.endian);
    wall_raycast(main);
    sprite_raycast(main);
}

int		display(t_main *main)
{
    image_render(main);
    mlx_clear_window(main->mlx.ptr, main->win.ptr);
    mlx_put_image_to_window(main->mlx.ptr, main->win.ptr, main->img.ptr, 0, 0);
    mlx_destroy_image(main->mlx.ptr, main->img.ptr);
    return (1);
}


void	speed_initialize(t_main *main)
{
    main->draw.z_buffer = (double*)malloc(main->win.width * sizeof(double));
    main->player.mspeed = 0.20;
    main->player.rspeed = 0.05;
}

void        window_initialize(t_main *main)
{
    printf("\nnose loko\n");
    main->mlx.ptr = ft_strdup("test");
    main->mlx.ptr = mlx_init();
    printf("\nnose loko 2\n");
    main->win.ptr = mlx_new_window(main->mlx.ptr, main->win.width,
                                  main->win.height, "cub3D");
    speed_initialize(main);
    texture_initialize(main);
    display(main);
    mlx_hook(main->win.ptr, 2, 0, &key_press, main);
	mlx_hook(main->win.ptr, 3, 0, &key_release, main);
	mlx_hook(main->win.ptr, 17, 0, &program_exit, main);
	mlx_loop_hook(main->mlx.ptr, &key_core, main);
	mlx_loop(main->mlx.ptr);
}
