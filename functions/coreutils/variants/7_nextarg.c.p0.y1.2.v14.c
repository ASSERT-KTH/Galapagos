
nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  return ((*(args++)=STREQ (*args, str))!=0 ? 1 : 0);
}
