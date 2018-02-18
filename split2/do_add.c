/* do_add.c 5735512002 Jatupat Pannoi  */

#include <stdio.h> /* printf() */

#include "do_add.h"

void do_add(float_pair_t arg_data) {

  printf("%f + %f = %f\n",arg_data[0],arg_data[1],arg_data[0]+arg_data[1]);

  return;

}
