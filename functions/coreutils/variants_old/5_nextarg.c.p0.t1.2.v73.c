nextarg (char const *str)
{
    if (*args == nullptr)
        return 0;
    else 
    {
      bool res = (*args == str);
      args += res ? 1 : 0;
      return res;
    }
}