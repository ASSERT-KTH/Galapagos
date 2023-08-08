
nextarg (char const *str)
{
  if (!(*args)) // Equivalent to if (*args == nullptr)
      return 0; // 0 is equivalent to false
  bool r = STREQ (*args, str);
  if (r != 0)
  {
     // equivalent to args += r;
     args++;
  }
  return r;
}
