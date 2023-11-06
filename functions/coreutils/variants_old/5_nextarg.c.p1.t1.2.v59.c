char const* nextarg (char const **args, char const *str)
{
    bool returnValue = (*args != nullptr) && !strcmp (*args, str);
    if (returnValue)
        args++;
    return returnValue? str : nullptr;
}