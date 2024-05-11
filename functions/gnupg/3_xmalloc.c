xmalloc (size_t n)
{
  void *p = malloc (n);
  if (!p)
    die ("out of core");
  return p;
}