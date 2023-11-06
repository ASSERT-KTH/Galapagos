1. Removing explicit "return" function syntax and applying short-circuit evaluation:


enum indicator_no is_colored (enum indicator_no type) 
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    ! (len == 0 || (len == 1 && STRNCMP_LIT (s, "0") == 0) || (len == 2 && STRNCMP_LIT (s, "00") == 0) );
}


2. Informally lifting condition onto its own line with equals check:


enum indicator_no is_colored (enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    int equalsZero = (len == 0);
    int firstStrncmpResult = (len == 1 && STRNCMP_LIT (s, "0") == 0);
    int secondStrncmpResult = (len == 2 && STRNCMP_LIT (s, "00") == 0);
    return !(equalsZero || firstStrncmpResult || secondStrncmpResult);
}


3. Changing order of conditions and applying demorgan's law to the boolean expression:


enum indicator_no is_colored (enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    return len != 0 && (! (len == 1 && STRNCMP_LIT (s, "0") == 0)&& !(len == 2 && STRNCMP_LIT (s, "00") == 0));
}


4. Replacing disjunctions with nested conditionals:


enum indicator_no is_colored (enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    if (len == 0) {
        return false;
    }
    else if (len == 1 && STRNCMP_LIT (s, "0") == 0) {
        return false;
    }
    else if (len == 2 && STRNCMP_LIT (s, "00") == 0) {
        return false;
    }
    else
    return true;
}
