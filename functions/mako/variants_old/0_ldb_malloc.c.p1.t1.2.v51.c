#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size){
   void *ptr;
   
   /* Uses calloc function, which allocates a block of memory sufficient size for an 
   array of num elements, each of them size bytes long, and initializes all its bits to zero. */

   ptr = calloc(size, 1);

   if(ptr == NULL){
      fprintf(stderr, "Memory allocation failed!\n");
      exit(1); 
   }
   
   return ptr;
}