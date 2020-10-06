/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:49:16 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:14:43 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *src, unsigned int start, size_t len)
{
	size_t			index;
	int				len_src;
	char			*result;

	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (src)
	{
		index = start;
		len_src = ft_strlen(src);
		if (start >= (unsigned int)len_src)
			return (NULL);
		while (src[index] != '\0' && index < len + start)
		{
			result[index - start] = src[index];
			index++;
		}
		result[index - start] = '\0';
		return (result);
	}
	else
		return (NULL);
}
