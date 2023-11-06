is_colored(enum indicator_no type) 
{
    char const *s = color_indicator[type].string;
    
    if(strlen(s) == 0 || (!strcmp(s, "0")) || (!strcmp(s, "00"))) 
    {
        return false;
    } 
    else 
    {
        return true;
    }
}