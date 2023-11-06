Version 1:

bool nextarg (char const *str)
{
  if (!*args)
    return false;
  
  bool result = STREQ (*args, str);
  args += !!result;
  
  return result;
}


Version 2:

bool nextarg (char const *str)
{
  bool res;
  return (!*args) ? false : ((res = STREQ (*args, str)), args += res, res);
}


Version 3:

bool nextarg (char const *str)
{
  if (*args == NULL)
    return false;
  
  args += STREQ (*args, str) ? 1 : 0;
  
  return STREQ (*args, str);
}


Version 4:

bool nextarg (char const *str)
{
    bool comparison;
    return (*args == NULL) ? false : ((comparison = STREQ (*args, str)), args += comparison, comparison);
}


Version 5:

bool nextarg (char const *str)
{
  if (!*args)
    return false;
    
  args += !!(STREQ (*args, str));

  return STREQ (*args, str);
}


By the way, it seems like there might be some missing code, `args` is not defined or passed as a parameter in the function.