/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:20:20 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/29 16:48:19 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	index;
	size_t	max;

	max = 0;
	while (dst[max] && max < len)
		max++;
	index = max;
	while (src[max - index] && max + 1 < len)
	{
		dst[max] = src[max - index];
		max++;
	}
	if (index < len)
		dst[max] = '\0';
	return (index + ft_strlen(src));
}
