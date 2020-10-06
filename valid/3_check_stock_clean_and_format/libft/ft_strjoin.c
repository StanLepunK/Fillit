/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:23:52 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:12:08 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*buffer;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		if (!(buffer = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
			return (NULL);
		buffer = ft_strcpy(buffer, s1);
		return (ft_strncat(buffer, s2, len_s2));
	}
	else if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	else if (s1 == NULL && s2)
		return (ft_strdup(s2));
	else
		return (NULL);
}
