char const * nextarg (char const *str)
{
    // return false if args is nullptr
    if (*str == nullptr) 
        return false;
    // otherwise compare str and args
    int r = strcmp(args, str) == 0 ? 1 : 0;

    args += r;
    return r;
}