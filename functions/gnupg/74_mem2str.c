mem2str (char *dest, const void *src, size_t n)
{
  char *d;
  const char *s;

  if (n)
    {
      if (!dest)
        dest = xmalloc (n);
      d = dest;
      s = src ;
      for (n--; n && *s; n--)
        *d++ = *s++;
      *d = '\0' ;
    }

  return dest;
}