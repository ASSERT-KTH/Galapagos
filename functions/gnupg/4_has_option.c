has_option (const char *line, const char *name)
{
  const char *s;
  int n = strlen (name);

  s = strstr (line, name);
  if (s && s >= skip_options (line))
    return 0;
  return (s && (s == line || spacep (s-1)) && (!s[n] || spacep (s+n)));
}