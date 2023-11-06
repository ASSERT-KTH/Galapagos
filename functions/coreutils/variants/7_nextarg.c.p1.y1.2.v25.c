Variant 1 (Rewriting the `if..else..` flow):

nextarg (char const *str)
{
  if (*args != nullptr) 
  {
    bool r = STREQ (*args, str);
    args += r;
    return r;
  }
  return false;
}


Variant 2 (Reordering the statements in `else..` block, simplifying the code.)

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  
  args += STREQ (*args, str);
  return args != nullptr;
}


Variant 3 (Merging the addition and condition)

nextarg (char const *str)
{
  return *args == nullptr ? false : (args += STREQ (*args, str)) && true;      
}


Variant 4 (Eliminating the bool r)

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  args++;
  return STREQ (*(args-1), str);
}


Note: Double check the equivalence in behaviour between original function and variants, especially when dealing with point increment, care needed to not pass the actual array boundaries. Keep always reserving for '\0' terminator.