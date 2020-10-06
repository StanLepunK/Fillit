/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 08:41:02 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/15 08:41:06 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	len;
	size_t	index;

	if (s1 && s2)
	{
		len = ft_strlen(s1);
		if (len != ft_strlen(s2))
			return (FALSE);
		else
		{
			index = 0;
			while (index < len)
			{
				if (s1[index] != s2[index])
					return (FALSE);
				index++;
			}
			return (TRUE);
		}
	}
	else
		return (FALSE);
}
