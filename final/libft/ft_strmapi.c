/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 08:20:42 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:09:44 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	int		index;
	char	*result;
	int		len;

	if (src)
	{
		len = ft_strlen(src);
		if (!(result = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		{
			index = 0;
			while (src[index] != '\0')
			{
				result[index] = f(index, src[index]);
				index++;
			}
			result[index] = '\0';
			return (result);
		}
	}
	else
		return (NULL);
}
