/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_FILLIT.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:05:57 by sgirard           #+#    #+#             */
/*   Updated: 2020/09/10 09:09:28 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char	*argv[])
{
	int fd;

	fd = 0;
	if (argc == 1)
	{
		fd = 0;
		ft_putstr("usage : ./fillit argv[1]");
		return (0);
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		close(fd);
	}
	else
	{
		ft_putstr("usage : ./fillit argv[1]");
	}
return (0);
}