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

int     saveMapLine(t_main *main, char *line)
{
    main->map.table[main->map.rows] = ft_strdup(line);
    main->map.rows++;
    if (ft_strlen(line) > main->map.columns || main->map.rows == 0)
        main->map.columns = ft_strlen(line);
    return 0;
}

int     configLine(t_main *main, char *line)
{
    char **lineSplitted;

    line = ft_str_tab_remove(line);
    line = ft_strtrim(line, " ");
    lineSplitted = ft_split(line, ' ');
    if (!ft_strcmp(lineSplitted[0], "R"))
        validateResolution(main, lineSplitted);
    if (!ft_strcmp(lineSplitted[0], "NO")
        || !ft_strcmp(lineSplitted[0], "SO")
        || !ft_strcmp(lineSplitted[0], "WE")
        || !ft_strcmp(lineSplitted[0], "EA")
        || !ft_strcmp(lineSplitted[0], "S"))
        validateTextures(main, lineSplitted);
    if (!ft_strcmp(lineSplitted[0], "C")
        || !ft_strcmp(lineSplitted[0], "F"))
        validateColors(main, lineSplitted);
    return 0;
}

int     lineValidator(t_main *main, char *line)
{
    if (ft_isalpha(line[0]))
        configLine(main, line);
    else if (line[0] == '1' || line[0] == ' ' || line[0] == '\t')
        saveMapLine(main, line);
    else if (line[0] == '0')
        error(E_MAP);
    return 0;
}


int     fileConfigValidator(t_main *main, char *mapPath)
{
    char    *fileLine;
    int     fileDescriptor;

    fileLine = NULL;
    if ((fileDescriptor = open(mapPath, O_RDONLY)) > 0)
    {
        main->map.table = malloc(sizeof(char *));
        while (get_next_line(fileDescriptor, &fileLine)
            && (main->map.rows == 0 || !ft_only_spaces_line(fileLine)))
        {
            lineValidator(main, fileLine);
            free(fileLine);
        }
    }
    free(fileLine);
    validateMap(main);
    printf("\nrows: %d\n", main->map.rows);
    printf("\ncols: %d\n", main->map.columns);
    unsigned int i = 0;
    while (i < (main->map.rows))
    {
        printf("%s\n", main->map.table[i]);
        i++;
    }
    free(main->map.table);
    return 0;
}