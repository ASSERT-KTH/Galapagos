variant 1:

bool nextarg (char const *str)
{
    bool result;
    if (*args == nullptr)
    {
        result = false;
    }
    else
    {
        result = STREQ (*args, str);
        args += result;
    }
   
    return result;
}


variant 2:

bool nextarg (char const *str)
{
    if (*args == nullptr)
    {
        return false;
    }

    bool is_arg_equal = STREQ (*args, str);
    args += is_arg_equal;
      
    return is_arg_equal;
}


variant 3:

bool nextarg (char const *str)
{
    if (*args != nullptr) 
    {
        bool r = STREQ (*args, str);
        args += r;
        return r;
    }
    return false;
}


variant 4:

bool nextarg (char const *str)
{
  if (*args != nullptr && STREQ (*args, str))
  {
    args++;
    return true;
  }

  return false;
}
