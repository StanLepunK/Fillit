/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_copy_from_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:24:42 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 16:52:09 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*r_copy_from_char(const char *src, int c)
{
	int	len;
	int	start;

	len = 0;
	start = -1;
	while (src[len] != '\0')
	{
		if (start == -1 && src[len] == c)
			start = len;
		len++;
	}
	if (start == -1 || c < 0)
		return (r_copy_from_index(src, 0, ft_strlen(src)));
	else
		return (r_copy_from_index(src, start, len));
}
