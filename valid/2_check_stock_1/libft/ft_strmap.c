/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 07:49:20 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:09:12 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *src, char (*f)(char))
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
				result[index] = f(src[index]);
				index++;
			}
			result[index] = '\0';
			return (result);
		}
	}
	else
		return (NULL);
}
