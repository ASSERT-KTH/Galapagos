has_leading_option (const char *line, const char *name)
{
  const char *s;
  int n;

  if (name[0] != '-' || name[1] != '-' || !name[2] || spacep (name+2))
    return 0;
  n = strlen (name);
  while ( *line == '-' && line[1] == '-' )
    {
      s = line;
      while (*line && !spacep (line))
        line++;
      if (n == (line - s) && !strncmp (s, name, n))
        return 1;
      while (spacep (line))
        line++;
    }
  return 0;
}