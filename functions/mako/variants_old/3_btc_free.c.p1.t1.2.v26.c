
btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);  
  } else {
    abort(); /* LCOV_EXCL_LINE */
  }
}

Even though the code implementation might look different, this variant of the original function behaves similarly. If "ptr" is not NULL, the memory space is freed. In case "ptr" is NULL, abort() function is called, terminating the function abruptly.