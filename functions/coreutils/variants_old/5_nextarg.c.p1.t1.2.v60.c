char const* nextarg (char const *str)
{
    bool cond = (*args == nullptr);

    bool r_arg = cond ? false : STREQ (*args, str);

    if(!cond)
       args += r_arg;

    return r_arg;
}