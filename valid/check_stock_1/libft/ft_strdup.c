/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:56:36 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/07 07:35:50 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(src);
	copy = (char*)malloc(sizeof(char) * (len + 1));
	if (copy == (char*)NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		copy[len] = src[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}
