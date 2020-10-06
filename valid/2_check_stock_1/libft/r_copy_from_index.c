/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_copy_from_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:24:42 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 16:52:09 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*r_copy_from_index(const char *src, int start, int len)
{
	char	*copy;
	int		index;

	index = 0;
	len -= start;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == (char *)NULL)
		return (NULL);
	while (src[start + index] != '\0')
	{
		copy[index] = src[start + index];
		index++;
	}
	copy[len] = '\0';
	return (copy);
}
