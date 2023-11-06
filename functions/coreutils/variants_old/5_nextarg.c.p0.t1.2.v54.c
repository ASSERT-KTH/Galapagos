nextarg (char const *str)
{
 if (*args == nullptr)
    return 0;
 if (STREQ (*args, str))
    {
      args++;
      return true; 
    }
 return false;   
}