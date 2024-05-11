snext (unsigned char const **buf)
{
  const unsigned char *s;
  int n;

  s = *buf;
  for (n=0; *s && *s != ':' && (*s >= '0' && *s <= '9'); s++)
    n = n*10 + (*s - '0');
  if (!n || *s != ':')
    return 0; /* we don't allow empty lengths */
  *buf = s+1;
  return n;
}