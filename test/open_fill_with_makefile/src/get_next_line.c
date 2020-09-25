#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include "libft.h"



int	get_next_line(const int fd, char **line)
{
  static char *bridge = NULL;
	int size;
	int len_bridge;
	int loop;
	int index;

	char buf[BUFF_SIZE + 1];
	ft_bzero(buf,ft_strlen(buf));
	loop = 0;
	len_bridge = 0;
	while ((size = read(fd, buf, BUFF_SIZE)) > 0) {
		loop++;
	}
  
  index = 0;
  char *dst;
	while(buf[index] != '\0' && buf[index] != '\n') {
		index++;
	}
	printf("after while index: %i\n",index);
	printf("length buffer %zu\n",ft_strlen(buf));
	// buf = ft_strcpy(buffer, s1);
	len_bridge = ft_strlen(buf) - index;
	printf("length bridge %i\n", len_bridge);
	printf("buf:%s\n",buf);
	// dst = malloc(sizeof(char) * (index + 1));
	// dst = malloc(sizeof(char) * 1000);
	// if (!(dst = malloc(sizeof(char) * (index + 1))))
	// 		return (0);
	dst = ft_strdup(r_copy_from_index(buf, 0, index));
	//bridge = ft_strdup(r_copy_from_index(buf, index + 1, ft_strlen(buf)));
	// dst = str_join(dst, buf, index);

	printf("loop: %i\n",loop);
	printf("index: %i\n",index);
  
  
	printf("dst: %s\n",dst);
	printf("bridge: %s\n",bridge);

	

	// printf("%s\n",buf);
	// printf("%s\n",bridge);
	// free(bridge);
	return 0;
	
}
