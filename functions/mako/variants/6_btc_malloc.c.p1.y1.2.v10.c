
btc_malloc(size_t size) {
  void *ptr = malloc(size);

  while(ptr == NULL){
    ptr = malloc(size);
  }

  return ptr;
}



btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if(!ptr)    
    ptr = malloc(size);

  return ptr;
}



btc_malloc(size_t size) {
  void *ptr = malloc(size);

  while(!ptr)
    ptr = malloc(size);

  return ptr;
}
