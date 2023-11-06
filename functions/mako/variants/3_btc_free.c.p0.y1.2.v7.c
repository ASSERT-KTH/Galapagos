void btc_free(void *ptr) {
  assert(ptr != NULL); // the assert() function terminates the program if the argument is NULL
  
  free(ptr);
}