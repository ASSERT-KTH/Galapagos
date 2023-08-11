size_t ldb_malloc(const size_t size) {
   void *ptr = malloc(size + 1);

   if (ptr == NULL) {
       fprintf(stderr, "Unable to allocate memory\n");
       exit(EXIT_FAILURE);
   }

   return ptr;
}