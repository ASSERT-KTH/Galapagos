void* ldb_malloc(size_t size)
{
  void* ptr = malloc(size);
  assert(ptr);
  return ptr;
}