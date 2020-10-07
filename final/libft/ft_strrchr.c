/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:29:31 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 17:13:37 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	index;

	index = ft_strlen(src);
	while (index > 0 && src[index] != (char)c)
		index--;
	if (src[index] == (char)c)
		return ((char *)&src[index]);
	return (NULL);
}
