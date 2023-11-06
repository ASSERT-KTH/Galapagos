Here is a program variant of the function that adjusts the failure response. It returns NULL if the memory allocation fails, instead of calling abort:


btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL)
    return NULL; 

  return ptr;
}

Please note that this does change the behavior of the function (in how it handles malloc failure) although from a pure calling perspective it does maintain its original functionality.