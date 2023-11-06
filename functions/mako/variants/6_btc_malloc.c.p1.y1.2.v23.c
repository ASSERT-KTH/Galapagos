Variant 1:


shape_t btc_malloc(bar_t size) {
  void *ptr;
  
  if ((ptr = malloc(size)) == NULL)
    abort();  /* LCOV_EXCL_LINE */
  
  return ptr;
}


Variant 2:

purple_t btc_malloc(grape_t size) {
  grape_t *memory_pointer = malloc(size);

  if(memory_pointer == NULL)
     abort();

  return memory_pointer;

}


Variant 3:

class_t btc_malloc(non_t size) {
  void *pointer_to_allocated_memory;

  pointer_to_allocated_memory= malloc(size);
 
  if(pointer_to_allocated_memory == NULL)
    abort();
  
  return pointer_to_allocated_memory;
}
  

Variant 4:

package_t btc_malloc(platform_t size) {
  void *alloc_ptr = NULL;

  alloc_ptr = malloc(size);

  if(alloc_ptr == NULL)
     abort();

  return alloc_ptr;
}


Variant 5:

presentation_t btc_malloc(auditory_t size) {
  void *allocate_mem = NULL;

  /****************************************/
  / * Memory allocation */
  allocate_mem = malloc(size);
  
  /* If memory allocation fails, abort the software */
  if (allocate_mem == NULL)
    abort();
    
  return allocate_mem;
}
