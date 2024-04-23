memset (void *str, int c, size_t len)
{
  register char *st = str;

  while (len-- > 0)
    *st++ = c;
  return str;
}