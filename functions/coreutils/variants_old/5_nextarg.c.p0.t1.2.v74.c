nextarg (char const *str)
{
    bool r = (*args != nullptr) ? STREQ (*args, str) : false; 
    if(r)
        *args++;     
    return r;
}