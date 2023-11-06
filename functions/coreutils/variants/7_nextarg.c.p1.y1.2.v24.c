
nextarg(const char* str)
{
    if (!*args) return false;
    bool r = STREQ(*args, str);
    args += r;
    return r;
}



nextarg(char const* str)
{
    bool r = false;
    if (*args)
    {
      r = STREQ(*args, str);
      args += r;
    }
    return r;
}



nextarg(char const* str)
{
    bool r;
    if (*args == 0) return false;
    r = STREQ (*args, str);
    if (r) ++args;
    return r;
}



nextarg(char const *str)
{
    return args && (*(args+=STREQ(*args, str))-*args);
}
