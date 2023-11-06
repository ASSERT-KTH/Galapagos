char const* nextarg (char const **str)
{
  bool r = false;

  if (str != nullptr && *str != nullptr) 
  {
    r = STREQ (*str, *args);
    if(r)
      ++args;
  }

  return r;
}