/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:35:13 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/15 09:35:18 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t len)
{
	size_t index;

	if (len == 0)
		return (TRUE);
	if (s1 && s2)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (FALSE);
		index = 0;
		while (s1[index] != '\0' && s2[index] != '\0' && index < len)
		{
			if (s1[index] != s2[index])
				return (FALSE);
			index++;
		}
		return (TRUE);
	}
	else
		return (FALSE);
}
