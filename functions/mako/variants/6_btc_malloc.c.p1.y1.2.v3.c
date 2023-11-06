1)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr != NULL); //Replacing conditional abort() with assertion
  return ptr;
}


2)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (!ptr) {  //Implicit Comparison
    abort();
  }
  return ptr;
}


3)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr)   // Using early return to terminate function if NULL ptr is picked 
    return ptr;
  abort();
}


4)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (0 == ptr) {  //Checking against NULL using integer comparison
    abort();
  }
  return ptr;
}