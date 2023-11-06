nextarg (const char *str)
{
    bool retValue = false;

    if (*args != nullptr) 
    {
        retValue = STREQ (*args, str);
        args += retValue;
    }
    return retValue;
}