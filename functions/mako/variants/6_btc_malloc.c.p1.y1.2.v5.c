1. Using assert to abort the program when malloc fails:

btc_malloc(size_t size) {
   void *ptr = malloc(size);

   assert(ptr != NULL);

   return ptr;
}

2. Error checking with exit function:

btc_malloc(size_t size) {
   void *ptr = malloc(size);

   if (ptr == NULL) {
     fprintf(stderr, "Out of memory\n");
     exit(1);
   }

   return ptr;
}

3. Avoiding the one line IF by using a ternary operation:

btc_malloc(size_t size) {
    void *ptr = malloc(size);

    return ptr != NULL ? ptr : exit(1);
}

4. Reporting the error message to STDERR and then abort:

btc_malloc(size_t size) {  
     void *ptr = malloc(size);

     if (ptr == NULL) {
         perror("Failed to allocate memory");
         abort();
     }

     return ptr;
}
