
ldb_malloc(size_t size) {
   void *ptr = malloc(size);

   if (!ptr)
     exit(1);

   return ptr;
}

In both the given function and the new solution, the program is exited when malloc fails to allocate memory. Hence, both of them are equivalent. Only difference is the method exited by: abort versus exit(1).