1)

nextarg (char const *str)
{
  if (*args == 0)
    return false;
  else
    {
      bool computeStringEquals = STREQ (*args, str);
      if (computeStringEquals) {
          ++args;
      }
      return computeStringEquals;
    }
}

2)

nextarg (char const *str)
{
  bool r = (*args != nullptr) ? STREQ (*args, str) : false;
  args += r;
  return r;
}

3)

nextarg (char const *str)
{
  if (!(*args))
    return false;
  bool compareResult = STREQ (*args, str);
  if (compareResult)
    args++;
  return compareResult;
}

4)

nextarg (char const *str)
{
  if (*args)
    {
      bool equalsStr = STREQ (*args, str);
      if (equalsStr) {
        args++;
      }
      return equalsStr;
    }
  return false;
}


5)

nextarg (char const *str) 
{
    if (*args == nullptr) 
        return false;

    bool isEq = STREQ (*args, str);

    if (isEq) 
        args++;

    return isEq;
}
