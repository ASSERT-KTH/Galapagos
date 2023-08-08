char const* nextarg (char const *str)
{
    if (*str == '\0')
        return NULL;

    bool isFound = (strcmp (str, "required_string") == 0); 

    str += isFound ? strlen(str) : 0;

    return isFound ? str : NULL;
}