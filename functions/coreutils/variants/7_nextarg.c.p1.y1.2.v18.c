1. Transforming magic number into a implied one:


nextarg (char const *str)
{
  if (!*args)
    return false;

  bool matched = STREQ (*args, str);
  args += matched;
  return matched;
}


2. Modifying assignments and if statements:


nextarg (char const *str)
{
  bool matched = false;

  if (*args)
     matched = STREQ (*args, str);

  args += matched;
  return matched;
}


3. Simplifying by returning amount shift of 'args':


nextarg (char const *str)
{
  if(!*args)
    return 0;

  return STREQ(*args, str);
}


4. Replacing if 'args' statement with ternary operator:


nextarg (char const *str)
{
  bool matched = *args ? STREQ (*args, str) : 0;
  args += matched;

  return matched;
}


5. Flipping the if-statement using not-equals operator


nextarg (char const *str)
{
  if (*args != nullptr)
  {
    bool r = STREQ (*args, str);
    args += r;

    return r;
  }
  else
    return false;  
}
