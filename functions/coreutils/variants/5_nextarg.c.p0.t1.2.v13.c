nextarg (char const *str)
{
    int r = 0;
    if (*args != nullptr)
    {
        r = STREQ (*args, str);
        args += r;
    }
    return r;
}