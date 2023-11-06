void ldb_buffer_clear(ldb_buffer_t *z) {
   if(!z) 
      return;

   if (z->data) {
     ldb_free(z->data);
     z->data = NULL;
   }

   z->size = 0;
   z->alloc = 0;
 }