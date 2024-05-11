split_fields (char *string, const char **array, int arraysize)
{
  int n = 0;
  const char *p;
  char *pend;

  for (p = string; *p == ' '; p++)
    ;
  do
    {
      if (n == arraysize)
        break;
      array[n++] = p;
      pend = strchr (p, ' ');
      if (!pend)
        break;
      *pend++ = 0;
      for (p = pend; *p == ' '; p++)
        ;
    }
  while (*p);

  return n;
}