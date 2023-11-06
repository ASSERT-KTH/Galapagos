// Variant 1
void* btc_malloc(size_t size)
{
  void *ptr = malloc(size);
  if (!ptr)
    exit(-1); // ALTERNATIVELY: exit(EXIT_FAILURE);

  return ptr;
}

// Variant 2
void* btc_malloc(size_t size) 
{
  void* ptr = calloc(1, size);
  if (!ptr)
    _Exit(-1); 

  return ptr;
}

// Variant 3
void* btc_malloc(size_t size) 
{
  void * ptr = calloc(size, 1);
  if(ptr == NULL) {
    perror("Memory allocation failed");
    exit(-1);
  }

  return ptr;
}

// Variant 4
void* btc_malloc(size_t size) 
{
  void* ptr = malloc(size);
  if(ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(-1);
  }

  return ptr;
}

// Variant 5
void* btc_malloc(size_t size) 
{
  void* ptr = malloc(size);
  if(ptr == NULL) {
    abort(); 
  }
  memset(ptr, 0, size);

  return ptr;
}