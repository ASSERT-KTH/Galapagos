1)

void btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


2) 

void btc_free(void *ptr) {
  if (!ptr) {
    abort();
  }
  free(ptr);
}


3) 

void btc_free(void *ptr) {
  if (ptr) {
    free(ptr); 
  } else {
    abort();
  }
}


4) 

void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Null pointer passed to free function\n");
    abort();
  }
  free(ptr);
}


5)

void btc_free(void *ptr) {
  if(ptr)
    free(ptr);
  else
    exit(EXIT_FAILURE);
}


6)

void btc_free(void *ptr) {
  if (!ptr) {
    printf("Error: Null Pointer Given For Freeing\n"); 
    exit(1);
  }

  free(ptr); 
}
 

7) 

void btc_free(void *ptr) {
  if(!ptr)
  {
    perror("Attempt to free NULL Pointer");
    abort();
  }
  free(ptr);
}
