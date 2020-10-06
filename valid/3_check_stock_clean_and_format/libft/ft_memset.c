/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:57:41 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/13 16:29:38 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*start;
	int		index;

	start = b;
	index = 0;
	while (len)
	{
		start[index] = c;
		index++;
		len--;
	}
	return (b);
}
