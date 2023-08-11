btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); 
    // Exiting code here after abort()
    exit(1); 
  } else {
    free(ptr);
    // Reset pointer to NULL after free to prevent dangling pointer
    ptr = NULL; 
  }
}