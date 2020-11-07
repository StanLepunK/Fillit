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




