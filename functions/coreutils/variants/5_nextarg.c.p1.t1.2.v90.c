char const* nextarg(char const* str)
{
    if (!*args)
        return nullptr;
    else {
        bool result = STREQ(*args, str);
        if (result) {
            args++;
        }
        return result ? str : nullptr;
    }
}