One possible variant could use if-else statement to organize original behavior differently from checking nullptr first.


nextarg (char const *str)
{
    bool r = false; 

    if(*args != nullptr) {
        r = STREQ (*args, str);
        args += r;
    }

    return r;
}
