/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:29 by smarcais          #+#    #+#             */
/*   Updated: 2020/09/14 11:15:59 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	(void)argc;

	int fd = open(argv[1], O_RDONLY);
	int count = 0;
	char *line;
	// int ret;

	line = NULL;
	
	printf("lTest %s\n", argv[1]);

	while (get_next_line(fd, &line) > 0)
	{
		printf("ligne %i %s\n", count, line);
		free(line);
		count++;
	}
	printf("---------------\n");
	// printf("fd=%d\n", fd);
	// ret = get_next_line(fd, &line);
	// printf("ret=%d\n", ret);
	// free(line);
	close(fd);
	return (0);
}