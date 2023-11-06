char nextarg (char const *str)
{
    bool result = false;

    if (*args != nullptr)
    {
      result = STREQ (*args, str);

      if(result)
          args += 1;
    }

    return result;
}