/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:18:17 by sgirard           #+#    #+#             */
/*   Updated: 2020/08/17 14:25:45 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	return (ft_strcpy(dest, s));
}
