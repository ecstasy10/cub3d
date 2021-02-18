/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/4 19:33:07 by dbalboa-           #+#    #+#             */
/*   Updated: 2021/02/4 19:33:10 by dbalboa-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     intersection(int array1[4], int array2[4])
{
    int arrayReturn[sizeof(array1) + sizeof(array2)];
    int count = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(array1[i]==array2[j])
            {
                count = count + 1;
                arrayReturn[count] = array1[i];
            }
        }
    }

}
