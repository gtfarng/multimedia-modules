/* do_divide.c 4935512001 Mickey Mouse */

#include <stdio.h> /* fprintf() printf() stderr */
#include <stdlib.h> /* exit() EXIT_FAILURE */

#include "do_divide.h"

void do_divide(float_pair_t arg_data) {

  if( arg_data[1]==0.0f ) {
    fprintf(stderr,"cannot divide %f by %f\n",arg_data[0],arg_data[1]);
    exit(EXIT_FAILURE);
  }
  printf("%f / %f = %f\n",arg_data[0],arg_data[1],arg_data[0]/arg_data[1]);

  return;

}
