Here's a program variant that checks if the input "size" is valid:


btc_malloc(size_t size) {
  /* check if size is non-positive */
  if (size <= 0) {
    fprintf(stderr, "Invalid size provided for malloc.\n");
    return NULL;
  } 
  
  void *ptr = malloc(size);
  
  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}

Notice that this variant introduces an additional check of the parameter "size". It will write an error message to stderr and return NULL if the supplied size is less than or equal to zero. An exception will still be raised (via abort()) if malloc() cannot allocate the requested memory like it originally does. So apart from additional validation of input, the original functionality of the function has been maintained and no additional auxiliary or helper functions have been created.