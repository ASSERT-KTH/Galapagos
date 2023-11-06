bool nextarg (char const *str)
{
    bool response = false;

    if (*args != nullptr)
    {
        response = STREQ (*args, str);
        args += response;
    }

    return response;
}