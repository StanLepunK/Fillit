/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:01:35 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/26 10:01:50 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	long buf;

	buf = nbr;
	if (buf < 0)
	{
		ft_putchar('-');
		buf *= -1;
	}
	if (buf >= 10)
	{
		ft_putnbr(buf / 10);
		ft_putnbr(buf % 10);
	}
	else
		ft_putchar(buf + '0');
}
