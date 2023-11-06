
void* btc_malloc(size_t size) {
  void *ptr;
  ptr = (void *)malloc(size);

  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}



void* btc_malloc(size_t size) {
  void *ptr;
  
  do{
    ptr = malloc(size); 
  } while(ptr == NULL);
  
  if(ptr == NULL) 
    abort(); /*LCOV_EXCL_LINE*/ 
  
  return ptr;
}


void* btc_malloc(size_t size) {
  void *ptr = calloc(size, 1);

  if(ptr == NULL) 
    abort(); /*LCOV_EXCL_LINE*/ 

  return ptr;
}



void* btc_malloc(size_t size) {
  void *ptr = realloc(NULL, size);

  if (ptr == NULL) 
    abort(); /*LCOV_EXCL_LINE*/ 

  return ptr;
}


void* btc_malloc(size_t size_btc) {
  
  void *prt_btc = malloc(size_btc);

  if (prt_btc == NULL){
      exit(EXIT_FAILURE); 
  }

  return prt_btc;

}



void* btc_malloc(size_t another_size) {

  void *capacity_var = malloc(another_size);
  
  exit(capacity_var == NULL ? -1 : 0);

  return capacity_var;
}
