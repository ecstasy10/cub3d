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

void	player_move(t_main *main, double x, double y)
{
    if (main->map.table[(int)(main->player.x + x * main->player.mspeed)][(int)main->player.y]
        != '1')
        main->player.x += x * main->player.mspeed;
    if (main->map.table[(int)main->player.x][(int)(main->player.y + y * main->player.mspeed)]
        != '1')
        main->player.y += y * main->player.mspeed;
    display(main);
}

void	player_rotate(t_main *main, double speed)
{
    double	olddir_x;
    double	oldplane_x;

    olddir_x = main->dir.x;
    main->dir.x = main->dir.x * cos(speed)
                 - main->dir.y * sin(speed);
    main->dir.y = olddir_x * sin(speed)
                 + main->dir.y * cos(speed);
    oldplane_x = main->plane.x;
    main->plane.x = main->plane.x * cos(speed)
                   - main->plane.y * sin(speed);
    main->plane.y = oldplane_x * sin(speed)
                   + main->plane.y * cos(speed);
    display(main);
}

int		key_core(t_main *main)
{
    if (main->keyboard[W_KEY])
        player_move(main, main->dir.x, main->dir.y);
    if (main->keyboard[LEFT_KEY])
        player_rotate(main, main->player.rspeed);
    if (main->keyboard[D_KEY])
        player_move(main, main->plane.x, main->plane.y);
    if (main->keyboard[S_KEY])
        player_move(main, -main->dir.x, -main->dir.y);
    if (main->keyboard[RIGHT_KEY])
        player_rotate(main, -main->player.rspeed);
    if (main->keyboard[A_KEY])
        player_move(main, -main->plane.x, -main->plane.y);
    if (main->keyboard[ESC_KEY])
        program_exit(main);
    return (0);
}

int		key_release(int keycode, t_main *main)
{
    if (keycode < 125)
        main->keyboard[keycode] = 0;
    return (0);
}

int		key_press(int keycode, t_main *main)
{
    if (keycode < 125)
        main->keyboard[keycode] = 1;
    return (0);
}

