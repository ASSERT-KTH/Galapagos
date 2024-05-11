xrealloc (void *old, size_t n)
{
  void *p = realloc (old, n);
  if (!p)
    die ("out of core");
  return p;
}