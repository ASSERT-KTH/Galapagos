is_colored (enum indicator_no type)
{
    
    if( color_indicator[type].len == 0 )
        return 0; 
    
    if( color_indicator[type].len == 1 && STRNCMP_LIT (color_indicator[type].string, "0") == 0 )
        return 0;

    if( color_indicator[type].len == 2 && STRNCMP_LIT (color_indicator[type].string, "00") == 0 )
        return 0;

    return 1; 
}