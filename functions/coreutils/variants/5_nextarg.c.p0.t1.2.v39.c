Such transformations could involve altering the logic without changing the fundamental meaning and order of operations. We could also optionally introduce minor changes in variable names. Here is one variant of the aforementioned function, with changes in processing order and nomenclature.

nextarg (char const *str)
{
  bool result;
    
  if (*args != nullptr)
  {
    result = STREQ (*args, str);
    args += result;
  }
  else
  {
    return false;
  }

  return result;
}