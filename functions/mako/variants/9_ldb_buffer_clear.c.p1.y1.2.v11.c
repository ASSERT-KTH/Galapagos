//Variant 1
/*
In this variant we add an early return in case the allocated memory is zero.
Although there is a performance gain, it slightly reduces the readability of the function.
*/
ldb_buffer_clear(ldb_buffer_t *z) {
  if (!(z->alloc > 0))  
    return;     
  ldb_free(z->data);  
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}

//Variant 2
/*
In this variant, instead of checking if z->alloc > 0 we use function that free might allow for NULL pointers.
Again, it slightly reduces the readability of the code.
*/
ldb_buffer_clear(ldb_buffer_t *z) {
  ldb_free(z->data);  
  z->data = NULL;
  z->size = z->alloc = 0;
}

//Variant 3
/*
In this variant we use a nested operation to clear z->size and z->alloc in one line.
This strategy prioritizes conciseness over readability.
*/
ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0)
    ldb_free(z->data);

  z->data = NULL;
  z->size = (z->alloc = 0);
}

//Variant 4
/*
Slight modification in the order of assignments
Allowing a more readable version but with the same functionality
*/
ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
    z->alloc = 0;
  }
  z->size = 0;
}