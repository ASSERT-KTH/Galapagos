int is_colored (enum indicator_no type)
{
    // Extracting color indicator's both length and corresponding string
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    
    // Check for distinct scenarios to determine the color's emptiness
    if(len == 0)
      return 0;
    else if (len == 1 && STRNCMP_LIT(s, "0") == 0)
      return 0;
    else if (len == 2 && STRNCMP_LIT (s, "00") == 0)
      return 0;

    // If reached till here means not an empty color
    return 1;
}