char *strdup(const char *str)
{
  size_t len;
  char *newstr;

  if(!str)
    return (char *)NULL;

  len = strlen(str) + 1;

  newstr = malloc(len);
  if(!newstr)
    return (char *)NULL;

  memcpy(newstr, str, len);
  return newstr;
}