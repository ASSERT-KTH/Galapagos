1. It's possible to modify this function to operate in a switch-like manner. This isn't a huge change and mostly cleans up readability:


is_colored (enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;

    return len != 0 && (
        (len != 1 || STRNCMP_LIT (s, "0") != 0) &&
        (len != 2 || STRNCMP_LIT (s, "00") != 0)
    );
}


2. The function could also be modified to use if...else... control structures:


is_colored (enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    
    if (len == 0)
        return 0;
    else if (len == 1 && STRNCMP_LIT (s, "0") == 0)
        return 0;
    else if (len == 2 && STRNCMP_LIT (s, "00") == 0)
        return 0;
    else
        return 1;
}


3. The function could be rewritten using explicit true and false return values:


is_colored (enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    
    if (len == 0
            || (len == 1 && STRNCMP_LIT (s, "0") == 0)
            || (len == 2 && STRNCMP_LIT (s, "00") == 0)) 
    {
        return false;
    }
    return true;
}


Note: This implementation heavily depends on your need to either stick to C style types (like using explicit 1 and 0 for boolean values) or to switch to types specified in `<stdbool.h>`. Do be careful of what style guide or older C code requirements you may have if you opt for the latter - it does often improve readability, but that might not always be a good enough reason to introduce stdbool-dependant code into a pre-existing project.