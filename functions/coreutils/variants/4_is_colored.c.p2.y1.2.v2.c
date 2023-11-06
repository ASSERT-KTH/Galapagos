enum indicator_no type is_colored_alternative()
{
    char const *nor = "0";
    char const *even = "00";
  
    if (color_indicator[type].len == 0)
        return 0;
  
    if (color_indicator[type].len == 1 && strncmp(color_indicator[type].string, nor, 1) == 0)
        return 0;
            
    if (color_indicator[type].len == 2 && strncmp(color_indicator[type].string, even, 2) == 0)
        return 0;
    
    return 1; 
}