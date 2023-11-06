btc_free(void *ptr) {
    free(ptr);

    if (ptr == NULL)  {
      exit(EXIT_FAILURE); 
    }
}