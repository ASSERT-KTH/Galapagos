char const* nextarg (char const *str)
{
    int r;
  
    if (*args == '\0') {
        return NULL;
    }
    else
    {
        r = STREQ (*args, str);
        args = r>0 ? args++ : args; 
        return (*args) ? str : NULL;
    }
}