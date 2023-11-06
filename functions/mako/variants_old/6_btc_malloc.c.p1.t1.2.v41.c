Here is a program variant that initializing allocated memory to zero:


btc_malloc(size_t size) {
  void *ptr = calloc(1, size); // Change from malloc to calloc

  if (ptr == NULL)
    abort(); 

  return ptr;
}

In this variant, instead of using `malloc` which does not initialize the allocated memory, `calloc` is used which initializes the memory to zero. This may be beneficial in cases where the uninitialized memory could possibly cause issues. But note, the use of `calloc` may be slower than `malloc` due to the extra step of initializing the memory.