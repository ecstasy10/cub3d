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

int		map_init(t_main *main)
{
    unsigned int		i;

    if (!(main->map.table = (char**)malloc(main->map.rows * sizeof(char*))))
        return (0);
    i = 0;
    while (i < main->map.rows)
    {
        main->map.table[i] = (char*)malloc(main->map.columns * sizeof(char));
        i++;
    }
    return (1);
}