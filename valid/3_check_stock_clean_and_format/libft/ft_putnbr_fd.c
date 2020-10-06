/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:38:44 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/24 14:38:59 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	long buf;

	buf = nbr;
	if (buf < 0)
	{
		ft_putchar_fd('-', fd);
		buf *= -1;
	}
	if (buf >= 10)
	{
		ft_putnbr_fd(buf / 10, fd);
		ft_putnbr_fd(buf % 10, fd);
	}
	else
		ft_putchar_fd(buf + '0', fd);
}
