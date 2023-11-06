Here is a program variant that ensures the memory returned is initialized to zero:


ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


This variant uses 'calloc' instead of 'malloc' to initialize the memory allocated, which ensures that all bytes in the memory block that it returns are zeroed. Regardless of this change, the function preserves the same functionality and maintains consistent with the behavior of the original function including the error handling via abort(). The function signature hasn't been changed either.