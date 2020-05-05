#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantics.h"


int typeChecking(int type1, int type2){
    if(type1 != type2)
    {
      type_error();
    }
    return 1;
}

void type_error() {
  fprintf(stderr, "Type Conflict");
  exit(1);
}
