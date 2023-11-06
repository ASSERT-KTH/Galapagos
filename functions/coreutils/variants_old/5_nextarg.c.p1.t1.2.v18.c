bool nextarg (char const *str)
{
    bool r = (*args != nullptr && STREQ (*args, str));
    if (r) { args++; }
    return r;
}