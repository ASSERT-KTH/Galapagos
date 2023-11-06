char const* nextarg (char const* str)
{
  if (*str == '\0')
    return NULL;
  else
    {
      bool isEqual = strcmp(str, *args) == 0;

      str = str + isEqual;
      
      return isEqual ? str : NULL;
    }
}