is_colored(enum indicator_no type)
{
    size_t length = color_indicator[type].len;
    char const *indicator = color_indicator[type].string;

    if (length == 0) 
      return 0;
      
    if (length == 1 && strncmp(indicator, "0", 1) == 0) 
      return 0;
        
    if (length == 2 && strncmp(indicator, "00", 2) == 0) 
      return 0;
    
    return 1;     
}