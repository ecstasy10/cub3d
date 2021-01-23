/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:24:34 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/01/23 19:24:36 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_flagCheck(char *flagArg, char *flag)
{
    return !ft_strcmp(flagArg, flag);
}

int		ft_fileExtensionCheck(char *fileArg, char *ext)
{
//    int	i;
//
//    i = 0;
//    while (fileArg[i] != '\0')
//        i++;
//    if ((i > 4 && fileArg[i - 1] == ext[2] && fileArg[i - 2] == ext[1])
//        && (fileArg[i - 3] == ext[0] && fileArg[i - 4] == '.'))
//        return (1);
//    return (0);
    char **str;

    str = ft_strlen(ft_split(fileArg, '.'));

    return !ft_strcmp(, ext);
}