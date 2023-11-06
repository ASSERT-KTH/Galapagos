// Variant 1:
// Modified Error Handling
size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); 

  return ptr;
}

// Variant 2:
// Adding C99 way to test null pointer
size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort();

  return ptr;
}

// Variant 3:
// Returning NULL pointer instead of calling abort function
size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    return ptr; 

  return ptr;
}

// Variant 4:
// Allocating memory with calloc instead of malloc
size_t btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (!ptr)
    abort();

  return ptr;
}

// Variant 5: 
// Adding memset to fill memory holding structure with zeros
size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort();

  memset(ptr, 0, size);
  return ptr;
}