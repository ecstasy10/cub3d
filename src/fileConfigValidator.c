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

int     configLine(t_main *main, char *line)
{
    char **lineSplitted;

    line = ft_str_tab_remove(line);
    line = ft_strtrim(line, " ");
    lineSplitted = ft_split(line, ' ');
    if (!ft_strcmp(lineSplitted[0], "R"))
        setResolution(main, lineSplitted);
    else if (!ft_strcmp(lineSplitted[0], "NO")
        || !ft_strcmp(lineSplitted[0], "SO")
        || !ft_strcmp(lineSplitted[0], "WE")
        || !ft_strcmp(lineSplitted[0], "EA")
        || !ft_strcmp(lineSplitted[0], "S"))
        printf("%s \n", "texturas");
    else if (!ft_strcmp(lineSplitted[0], "C")
        || !ft_strcmp(lineSplitted[0], "F"))
        printf("%s \n", "colores");
    return 0;
}

int     lineValidator(t_main *main, char *line)
{
    if (ft_isalpha(line[0]))
        configLine(main, line);
    else
        printf("%s", "Esto es el mapa\n");
    return 0;
}


int     fileConfigValidator(t_main *main, char *mapPath)
{
    char    *fileLine;
    int     fileDescriptor;

    fileLine = NULL;
    fileDescriptor = open(mapPath, O_RDONLY);
    if (fileDescriptor)
    {
        while (get_next_line(fileDescriptor, &fileLine))
        {
            lineValidator(main, fileLine);
            free(fileLine);
        }
    }
    return 0;
}