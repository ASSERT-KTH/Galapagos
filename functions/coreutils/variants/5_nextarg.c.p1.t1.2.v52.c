
nextarg (char const *str)
{
    bool r = false;
    if (*args != nullptr)
    {
         r = STREQ(*args,str);
         if(r)
             args++;
    }
    return r;
}
