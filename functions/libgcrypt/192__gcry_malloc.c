_gcry_malloc (size_t n)
{
  void *mem = NULL;

  do_malloc (n, 0, &mem);

  return mem;
}