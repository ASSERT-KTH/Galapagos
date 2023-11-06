btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
  }else{
    free(ptr);
    ptr=NULL;
  }
}