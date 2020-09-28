/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:04:20 by smarcais          #+#    #+#             */
/*   Updated: 2019/12/04 15:04:10 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	ix;

	ix = 0;
	while (*(s1 + ix) && *(s1 + ix) == *(s2 + ix) && ix < len - 1)
		ix++;
	if (len)
		return (*((unsigned char *)s1 + ix) - *((unsigned char *)s2 + ix));
	return (0);
}
