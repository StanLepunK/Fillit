/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:09:59 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/13 17:16:04 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t		index;
	size_t		index_src;

	index = 0;
	index_src = 0;
	while (s1[index] != '\0')
		index++;
	while (s2[index_src] != '\0' && index_src < len)
	{
		s1[index + index_src] = s2[index_src];
		index_src++;
	}
	s1[index + index_src] = '\0';
	return (s1);
}
