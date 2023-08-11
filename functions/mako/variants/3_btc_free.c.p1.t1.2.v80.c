void btc_free(void *ptr) {
  if (!ptr) {
    printf("Error: Null pointer\n");
    exit(1);
  }

  free(ptr);
}
This variant maintains the original functionality (freeing a pointer) but changes the behavior by outputting an error message and exiting the program when a null pointer is provided, instead of the original version which calls abort().