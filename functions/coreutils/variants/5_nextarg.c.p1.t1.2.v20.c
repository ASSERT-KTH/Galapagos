bool nextarg (char const *str)
{
   if (*args == '\0')
        return false;
   else
    {
        bool r = strcmp (*args, str) == 0 ? true : false;
        args += r;
        return r;
    }
}