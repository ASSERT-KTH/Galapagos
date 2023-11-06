
bool is_colored(enum indicator_no type) 
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;

    bool is_len_0 = (len != 0);
    bool is_len_1_and_str_0 = (len != 1 || strcmp (s, "0") != 0);
    bool is_len_2_and_str_00 = (len != 2 || strcmp (s, "00") != 0);
    
    return is_len_0 && is_len_1_and_str_0 && is_len_2_and_str_00;
}



bool is_colored(enum indicator_no type) 
{
    size_t len = color_indicator[type].len;
    
    if(len == 0) 
    {
        return false;
    }
    else if (len == 1) 
    {
        char const *s = color_indicator[type].string;
        return STRNCMP_LIT(s, "0") != 0;
    }
    else if (len == 2) 
    {
        char const *s = color_indicator[type].string;
        return STRNCMP_LIT(s, "00") != 0;
    }
    else 
    {
        return true;
    }
}



bool is_colored(enum indicator_no type) 
{
    Discriminant disc = color_indicator[type];
    
    if (disc.len > 2) 
    {
        return true;
    }
    else if (disc.len == 0 || STRNCMP_LIT(disc.string, disc.len == 1 ? "0" : "00") == 0) 
    {
        return false;
    }
    else 
    {
        return true;
    }
}
