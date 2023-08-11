is_colored(enum indicator_no type)
{
    // Retrieve the length and string corresponding to the particular type.
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;

    // Check if the length is non-zero and s is neither '0' nor '00'.
    if((len == 0)||(len == 1 && strncmp(s, "0", len) == 0)||(len == 2 && strncmp(s, "00", len) == 0))
        return 0;
  
    // If the conditions above don't hold, return as colored.
    return 1;
}