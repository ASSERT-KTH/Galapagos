
void btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}



void btc_free(void *ptr) {
  if (!ptr) {
    abort();
    return;
  }
  free(ptr);
}



void btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "NULL pointer provided!");
    abort();
    /* The line below is grouped within the brace e.g {} because the indentation gives an illusion that free(ptr) belongs to this if-statment, hence will not be reached but actually ptr is NULL */ -- 
    {}
    return;
  }
  free(ptr);
}



void btc_free(void* ptr) {
    ((!ptr)?abort():free(ptr));
}



void btc_free(void* ptr) {
    if(!ptr) exit(EXIT_FAILURE);
    else free(ptr);
}
