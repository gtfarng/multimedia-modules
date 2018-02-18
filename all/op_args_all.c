/* op_args_all.c 4935512001 Mickey Mouse */

/*
gcc -Wall -o op_args_all op_args_all.c
./op_args_all add 1.2 3.4
*/

#include <stdio.h> /* fprintf() printf() stderr */
#include <stdlib.h> /* atof() atoi() exit() EXIT_FAILURE EXIT_SUCCESS */
#include <string.h> /* strcmp() */

typedef
  float
  float_pair_t [2];

typedef
  struct {
    int first;
    int second;
  } integer_pair_t;

void do_add(float_pair_t arg_data) {

  printf("%f + %f = %f\n",arg_data[0],arg_data[1],arg_data[0]+arg_data[1]);

  return;

}

void do_divide(float_pair_t arg_data) {

  if( arg_data[1]==0.0f ) {
    fprintf(stderr,"cannot divide %f by %f\n",arg_data[0],arg_data[1]);
    exit(EXIT_FAILURE);
  }
  printf("%f / %f = %f\n",arg_data[0],arg_data[1],arg_data[0]/arg_data[1]);

  return;

}

void do_modulo(integer_pair_t arg_data); /* prototype or signature */

int main(int argc,char **argv,char **envp) {
  float_pair_t   floats;
  integer_pair_t integers;

  if( (argc!=4) ||
      ( (strcmp(argv[1],"add"   )!=0) &&
        (strcmp(argv[1],"divide")!=0) &&
        (strcmp(argv[1],"modulo")!=0)
      )
    ) {
    fprintf(stderr,"usage: %s {add|divide|modulo} number number\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  if( strcmp(argv[1],"add")==0 ) {
    floats[0]=atof(argv[2]);
    floats[1]=atof(argv[3]);
    do_add(floats);
  } else if( strcmp(argv[1],"divide")==0 ) {
    floats[0]=atof(argv[2]);
    floats[1]=atof(argv[3]);
    do_divide(floats);
  } else { /* modulo */
    integers.first=atoi(argv[2]);
    integers.second=atoi(argv[3]);
    do_modulo(integers);
  }

  exit(EXIT_SUCCESS);

}

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
