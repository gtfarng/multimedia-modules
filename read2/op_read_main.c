/* op_read_main.c 5735512002 Jatupat Pannoi */

/*
gcc -Wall -c do_add.c
gcc -Wall -c do_divide.c
gcc -Wall -c do_modulo.c
gcc -Wall -c op_read_main.c
gcc -Wall -o op_read op_read_main.o do_add.o do_divide.o do_modulo.o
./op_read
*/

#include <stdbool.h> /* true */
#include <stdio.h> /* fprintf() printf() stderr */
#include <stdlib.h> /* exit() EXIT_FAILURE EXIT_SUCCESS */
#include <string.h> /* strcmp() */

#include "do_add.h" /* do_add() */
#include "do_divide.h" /* do_divide() */
#include "do_modulo.h" /* do_modulo() */

int main(int argc,char **argv,char **envp) {
  char           command [6+1+1]; /* "divide" or "modulo" + 1 extra + '\0' */
  float_pair_t   floats;
  integer_pair_t integers;

  if( (argc!=1) ) {
    fprintf(stderr,"usage: %s\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  while( true ) {
    printf("command? ");
    if( scanf("%s",command)!=1 ) { /* reads up to whitespace */
      fprintf(stderr,"error reading a command\n");
      exit(EXIT_FAILURE);
    }

    if( strcmp(command,"add")==0 ) {
      printf("first argument? ");
      if( scanf("%f",&(floats[0]))!=1 ) {
        fprintf(stderr,"bad first argument to add()\n");
        exit(EXIT_FAILURE);
      }
      printf("second argument? ");
      if( scanf("%f",&(floats[1]))!=1 ) {
        fprintf(stderr,"bad second argument to add()\n");
        exit(EXIT_FAILURE);
      }
      do_add(floats);
    } else if( strcmp(command,"divide")==0 ) {
      printf("first argument? ");
      if( scanf("%f",&(floats[0]))!=1 ) {
        fprintf(stderr,"bad first argument to divide()\n");
        exit(EXIT_FAILURE);
      }
      printf("second argument? ");
      if( scanf("%f",&(floats[1]))!=1 ) {
        fprintf(stderr,"bad second argument to divide()\n");
        exit(EXIT_FAILURE);
      }
      do_divide(floats);
    } else if( strcmp(command,"modulo")==0 ) {
      printf("first argument? ");
      if( scanf("%d",&(integers.first))!=1 ) {
        fprintf(stderr,"bad first argument to modulo()\n");
        exit(EXIT_FAILURE);
      }
      printf("second argument? ");
      if( scanf("%d",&(integers.second))!=1 ) {
        fprintf(stderr,"bad second argument to modulo()\n");
        exit(EXIT_FAILURE);
      }
      do_modulo(integers);
    } else if( strcmp(command,"stop")==0 )
      exit(EXIT_SUCCESS);
    else {
      fprintf(stderr,
        "command is not \"add\", \"divide\", \"modulo\" or \"stop\"\n");
      exit(EXIT_FAILURE);
    }
  }

}
