
bool nextarg (const char *str)
{
  if (str == nullptr)
    return false;
  else
    {
      bool r = STREQ (args, str);
      if (r)
        args++;
      return r;
    }
}

bool nextarg (char const *str)
{    
    if (str)
    {
        bool r = STREQ (args, str);
        args += (int)r;
        return r;
    } else  {
        return false;
    }
}

bool nextarg (const char *str)
{
  if (!str)
    return false;
     
  bool r = STREQ (args, str);
   
  if (r)
    args++;

  return r;
}
