#include "../includes/tetro.h"

int sqrt_ceil(float value) {
  int arg;
  int max;

	arg = 0;
  max = 46341; // max for the int value
  if(value < 0) {
    return(0);
  }

  while(arg * arg < value && arg * arg < max) {
    arg++;
  }
  return arg;
}


char	*strcpy_from_to(const char *src, int start, int end)
{
	char	*copy;
	int		index;
  int len;

	index = 0;
	len = end - start;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == (char *)NULL)
		return (NULL);
	while (src[start + index] != '\0' && index < end)
	{
		copy[index] = src[start + index];
		index++;
	}
	copy[len] = '\0';
	return (copy);
}




