The function is_colored (enum indicator_no type) checks if a certain type of object from an enumeration of different object types is "colored" or not according to some criteria. Here are some minor modifications without changing the underlying functionality:


is_colored (enum indicator_no type)
{
    // retrieve the color indicator details
    char const *s = color_indicator[type].string;
    size_t len = strlen(s);

    // check if there's a color indicator
    if (len == 0) {
        return 0;
    } else if ((len == 1 && strncmp(s, "0", 1) == 0)
               || (len == 2 && strncmp(s, "00", 2) == 0)) {
        return 0;
    } else {
        return 1;
    }
}

Modified parts are notes/messages in the code base which do not affect the overall function of the program. Code will still behave same for all inputs.