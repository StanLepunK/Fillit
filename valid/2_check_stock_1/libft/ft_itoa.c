/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 10:15:50 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 16:53:31 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	str_len_nbr(long nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static int	len_start(long nbr)
{
	int start;

	start = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		start = 1;
	}
	return (start);
}

char		*ft_itoa(int nbr)
{
	int		len;
	char	*result;
	long	buf_nbr;

	buf_nbr = nbr;
	len = len_start(buf_nbr);
	if (buf_nbr < 0)
		buf_nbr *= -1;
	len += str_len_nbr(buf_nbr);
	result = ft_memalloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (buf_nbr == 0)
		result[0] = '0';
	else
	{
		while (len-- > 0 && buf_nbr > 0)
		{
			result[len] = buf_nbr % 10 + '0';
			buf_nbr /= 10;
		}
		if (len == 0)
			result[len] = '-';
	}
	return (result);
}
