xmalloc (size_t n)
{
  void *p = malloc (n);
  if (!p)
    {
      fprintf (stderr, "t-iobuf: out of core\n");
      abort ();
    }
  return p;
}