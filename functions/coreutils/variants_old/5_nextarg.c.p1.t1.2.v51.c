char *nextarg (char const *args, char const *str)
{
  // return false if args is nullptr
  if (args == NULL) return NULL;

  // increment args if it equals str and return the comparison result
  return strcmp(args, str) == 0 ? (args++, str) : NULL;
}