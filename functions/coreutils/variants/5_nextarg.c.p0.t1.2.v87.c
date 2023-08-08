nextarg (char const *str)
{
  if (*(args) == nullptr)
    return false;
  else
    {
      bool is_equal = STREQ (*args, str);
      if(is_equal) args ++;
      return is_equal;
    }
}