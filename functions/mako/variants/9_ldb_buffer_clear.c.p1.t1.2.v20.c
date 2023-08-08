Here is a program variant that changes the behavior subtly by introducing error-checking.


void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL)
  {
    if (z->alloc > 0 && z->data !=NULL)
    {
        ldb_free(z->data);
        z->data = NULL;
    }
  
    z->size = 0;
    z->alloc = 0;
  }
}

This variant doesn't just free memory unwarily, but first check there is something to free and prevent NULL pointer dereference by verifying the pointer isn't NULL.