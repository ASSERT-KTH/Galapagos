char const *nextarg (char const *str)
{
  if (*str == '\0')
    return NULL;
  else
    {
      bool r = strcmp(*str, str);
      *str += r ? 0 : strlen(*str);
      return r ? str : NULL;
    }
}