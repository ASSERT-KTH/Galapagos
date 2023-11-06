
btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    printf("Memory allocation failed. Aborting...\n");
    exit(EXIT_FAILURE); 
  }
  
  return ptr;
}

This variant still provides the same basic functionality as the original - memory allocation - but modifies behavior in the case of a failure with the allocation process. The change consists in outputting a message via `printf` before terminating the program, offering slightly more informative behavior to someone debugging code using this function. I've used `exit(EXIT_FAILURE)` instead of `abort()` to achieve the same effect.
Sometimes a silent abrupt termination might not be desirable, hence here we introduce an informative message followed by a termination. Do note that redirecting program termination from `abort()` to `exit(EXIT_FAILURE)` might modify the behavior slightly owing to underlying functional differences. It's always safer/frugal/efficacious and standard to notify others with correct debugging information. However, many automated systems/tests/environments expect a program to be completely silent if it operates correctly.