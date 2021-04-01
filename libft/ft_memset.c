/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:28:14 by dbalboa-          #+#    #+#             */
/*   Updated: 2019/11/19 20:31:20 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	j;
	char			*a;

	i = 0;
	j = c;
	a = (void *)b;
	while (i < len)
	{
		a[i] = j;
		i++;
	}
	return (b);
}
