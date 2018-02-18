/* do_modulo.c 4935512001 Mickey Mouse */

#include <stdio.h> /* fprintf() printf() stderr */
#include <stdlib.h> /* exit() EXIT_FAILURE */

#include "do_modulo.h"

void do_modulo(integer_pair_t arg_data) {

  if( arg_data.second==0 ) {
    fprintf(stderr,"cannot take %d modulo %d\n",arg_data.first,
      arg_data.second);
    exit(EXIT_FAILURE);
  }
  printf("%d modulo %d = %d\n",arg_data.first,arg_data.second,
    arg_data.first%arg_data.second);

  return;

}
