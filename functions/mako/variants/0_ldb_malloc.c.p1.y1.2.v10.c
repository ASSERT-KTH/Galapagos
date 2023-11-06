
void* ldb_malloc(size_t size) {
  void *memptr;

  memptr = malloc(size);
  if (memptr == NULL) {
    abort();
  }

  return memptr;
}



void* ldb_malloc(size_t size) {
  void *allocated_memory = malloc(size);

  if (!allocated_memory)
    abort();

  return allocated_memory;
}



void* ldb_malloc(size_t size) {
  void *tmp = malloc(size);

  if (!tmp)
    abort();

  return tmp;
}



void* ldb_malloc(size_t size) {
  void *allocatedMemeory;

  allocatedMemeory = malloc(size);
  if (allocatedMemeory == NULL) {
    abort();
  }

  return allocatedMemeory;
}
