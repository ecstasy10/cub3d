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

int     lineValidator(char *fileLine)
{

    return 0;
}


int     configValidator(char *mapPath)
{
    char    *fileLine;
    int     fileDescriptor;

    fileLine = NULL;
    fileDescriptor = open(mapPath, O_RDONLY);
    if (fileDescriptor)
    {
        while (get_next_line(fileDescriptor, &fileLine))
        {
            lineValidator(fileLine);
            free(fileLine);
        }
    }
    return 0;
}