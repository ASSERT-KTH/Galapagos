is_colored(enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    size_t len = strlen(s);

    if(len == 0 || strncmp(s, "0", 1) == 0 || strncmp(s, "00", 2) == 0)
        return 0; //the color is null or black

    return 1; // the color isn't null nor black
}