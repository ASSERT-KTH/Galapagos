Sure, here's a variant of the function you provided having the same functionality.

bool nextarg (char const *str)
{
    if (*args != nullptr)
    {
        bool r = STREQ (*args, str);
        if (r)
            ++args;
        return r;
    }

    return false;
}

In this code I reverted the order of checking the pointer, first I checked the positive situation. Also instead of adding r to the pointer directly, in which case if r is false, still it causes the pointer to move forward, I've added a condition check to ensure the pointer is only incremented forward if the current argument matched the given string.