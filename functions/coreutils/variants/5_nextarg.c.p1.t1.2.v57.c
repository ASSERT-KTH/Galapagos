bool nextarg (char const *str)
{
    bool r = false;

    if (*args) {
        r = STREQ (*args, str);
        if (r) {
            args++;
        }
    }

    return r;
}