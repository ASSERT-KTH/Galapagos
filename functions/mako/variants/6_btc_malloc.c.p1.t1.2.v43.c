size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("btc_malloc failed: Insufficient memory");
    exit(EXIT_FAILURE);
  }

  return (size_t)ptr;
}
// The variant changes the behaviour of the function by specifying a detailed error message when
// memory allocation fails and uses exit rather an abort(). But its original functionality stays the
// same, i.e., allocating memory of `size` bytes and return head(address) of that space.