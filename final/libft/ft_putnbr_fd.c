/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:18:26 by sgirard           #+#    #+#             */
/*   Updated: 2020/01/24 19:19:17 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long i;

	i = (long)n;
	if (i < 0)
	{
		i = i * (-1);
		ft_putchar_fd('-', fd);
	}
	if (i >= 0 && i < 10)
		ft_putchar_fd((i + '0'), fd);
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	return ;
}
