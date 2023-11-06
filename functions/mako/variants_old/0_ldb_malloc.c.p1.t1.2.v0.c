Here's a modified version of the function. The function now checks if the `size` argument is 0. Some systems may allow `malloc` to be called with a size of 0 and may return either NULL or a unique pointer that can later be successfully passed to `free()`, this isn't allowed under the ANSI standard.


ldb_malloc(size_t size) {
  if (size == 0)
    size = 1;

  void *ptr = malloc(size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


This alteration of the function maintains the original function's purpose of allocating memory and handling if allocation fails but also prevents an allocation size of 0, which isn't allowed in ANSI standard.