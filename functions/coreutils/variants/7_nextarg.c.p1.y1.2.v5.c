1. If-Else Structure Change to  Conditional Operator (?:):


nextarg (char const *str)
{
  return (*args == nullptr) ? false : ((args += STREQ (*args, str)), STREQ (*args, str));
}


2. Fully Unroll the Variable:


nextarg (char const *str)
{
  if (*args)
  {
    return (*(args += STREQ (*args, str)) == str);
  }
  return false;
}


3. Using Supplemental Variable:


nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool result = STREQ (*args, str);
  
  if (result)
    args++;
   
  return result;
}


4. Check Equality After Altering args Pointer:


nextarg (char const *str)
{
  bool r;
  if(*args != nullptr)
  {
    r = STREQ (*args++, str);
  }
  else
  {
    return false;
  }

  return r;
}


5. Drop "else" Syntax (Unrequired):


nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool r = STREQ (*args, str);
  args += r;
  return r;
}
