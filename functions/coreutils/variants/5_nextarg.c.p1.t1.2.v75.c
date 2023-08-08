bool nextarg (char const *str)
{
    bool r = false;

    if (*args != nullptr)
    {
      r = STREQ (*args, str);
      args += r;
    }

    return r;
}