#include <stdio.h>
#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  // Exception handling can be introduced in this case where in case allocation fails write custom logic. 
  // For simply displaying a comment, the below mentioned tricks can be
  // applied:
  // Either, print a statement describing the abortion of the function 
  // or print an error message.

  //Additionally different error codes/reactive behaviors can be introduced 
  //after understanding exact needs and scenarios of a software plan. 

  if (ptr == NULL) {
    fprintf(stderr, "Insufficient memory. Terminating program.\n");
    exit(1); // exit with non-success condition
  }

  return ptr;
}