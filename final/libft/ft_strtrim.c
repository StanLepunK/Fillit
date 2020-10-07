/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:39:50 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:17:46 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *src)
{
	size_t	index;
	size_t	len;

	if (src)
	{
		index = 0;
		while (src[index] != '\0' && r_space_is((int)src[index]) == TRUE)
			index++;
		len = ft_strlen(src);
		while (index < len && r_space_is((int)src[len - 1]) == TRUE)
			len--;
		if (index == len)
			return (ft_strnew(1));
		len -= index;
		return (ft_strsub(src, index, len));
	}
	else
		return (NULL);
}
