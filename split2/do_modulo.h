/* do_modulo.h 5735512002 Jatupat Pannoi  */

#ifndef DO_MODULO_H
#define DO_MODULO_H

#include "data_types.h"

/* PRE arg1 and arg2 ave been set to valid integer values, and arg2 is not
   zero
*/

/* POST if anything goes wrong, stop with an error message; otherwise, arg1
        modulo arg2 has been calculated and printed
*/

void do_modulo(integer_pair_t arg_data);

#endif
