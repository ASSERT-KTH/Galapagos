Variant 1:

void* ldb_malloc(size_t size) {
   void *ptr = malloc(size);
  
   assert(ptr != NULL); // using assert instead of if and abort
   
   return ptr; 
}


Variant 2:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) // just change comparison form
    abort(); 

  return ptr; 
}


Variant 3:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);    
  
  if (ptr == 0) // Different comparison base
    abort();

  return ptr; 
}


Variant 4:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr)
      return ptr;
  else
      abort();
}


Variant 5:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  // Using putchar to give error msg, still avoiding print & using ASCII for a.
  if (ptr == NULL) {
    putchar(97); putchar(98); putchar(111); putchar(114); putchar(116); 
	abort();
  }

  return ptr;
}
