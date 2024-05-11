ascii_strncasecmp (const char *a, const char *b, size_t n)
{
  const unsigned char *p1 = (const unsigned char *)a;
  const unsigned char *p2 = (const unsigned char *)b;
  unsigned char c1, c2;

  if (p1 == p2 || !n )
    return 0;

  do
    {
      c1 = ascii_tolower (*p1);
      c2 = ascii_tolower (*p2);

      if ( !--n || c1 == '\0')
	break;

      ++p1;
      ++p2;
    }
  while (c1 == c2);

  return c1 - c2;
}