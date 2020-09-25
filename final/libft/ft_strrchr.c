/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:36:00 by sgirard           #+#    #+#             */
/*   Updated: 2020/02/05 11:44:55 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)s + len);
	while (len--)
		if (*(s + len) == (char)c)
			return ((char*)s + len);
	return (NULL);
}
