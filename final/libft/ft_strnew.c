/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:53:05 by sgirard           #+#    #+#             */
/*   Updated: 2020/01/14 12:11:43 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		c;
	char	*str;

	c = '\0';
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	else
	{
		ft_memset(str, c, (size + 1));
	}
	return (str);
}
