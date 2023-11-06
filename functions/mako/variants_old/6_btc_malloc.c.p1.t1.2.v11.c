btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* 
  This part is where the functionality changes. Instead of having the 
  program die instantly when "ptr" can't be allocated, it'll add a sleep 
  of one second and then try to allocate the memory again. If after 3 
  attempts it's still impossible to allocate, then the code should abort.
  This might be practical in situations in which failing is less acceptable 
  and retrying is feasible (but not forever, to prevent endless loops).
  */

  int attempts = 0;
  while (ptr == NULL && attempts < 3) {
    sleep(1);
    ptr = malloc(size);
    attempts++;
  }

  if (ptr == NULL)
    abort();

  return ptr;
}