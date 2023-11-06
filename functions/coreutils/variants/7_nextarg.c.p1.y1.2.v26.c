1) Use pointer increment and function in if-else conditions

nextarg (char const *str)
{
  if (!*args)
  {
    return false;
  }
  bool res = STREQ (*args, str);
  if (res) { args++; }
  return res;
}


2) Simplify combined increment and equality check

nextarg (char const *str)
{
  if (!*args)
  {
    return false;
  }
  if (STREQ (*args, str)) 
  {
    args++;
    return true;
  }
  return false;
}


3) Use implicit conversion from pointer to bool

nextarg (char const *str)
{
  bool result = false;
  if (*args)
  {
    result = STREQ (*args, str);
    args += result;
  }
  return result;
}


4) Use conditional operator instead of if-else

nextarg (char const *str)
{
  return *args ? (args += STREQ (*args, str), STREQ (*args, str)) : false;
}


5) Use compound logical expression

nextarg (char const *str)
{
  return (*args && (args += STREQ (*args, str)), STREQ (*args, str));
}


Please note: There may be inconsistencies in these examples since the original code snippet is incomplete. 'args' and 'STREQ' aren't defined anywhere still these were attempts to generate diverse yet preserving logic based upon the snippet provided.