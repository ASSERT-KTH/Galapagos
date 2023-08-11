nextarg (char const *str)
{
    if (nullptr == *args) //changed evaluation order
        return false;
    else
    {
        bool r = STREQ (*args, str);
        args++;          // changed pre-increment to post-increment
        return r;
    }    
}