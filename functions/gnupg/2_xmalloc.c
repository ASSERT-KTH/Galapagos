xmalloc (size_t n)
{
  void *p = malloc (n);
  if (!p)
    die ("out of core: %s", strerror (errno));
  return p;
}