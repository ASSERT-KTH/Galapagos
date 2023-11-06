nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool equality_result = STREQ (*args, str);
      args += equality_result;
      
      if(equality_result)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
}