int is_colored (enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    size_t len = strlen(s);
    int isLenZeroOrOne = ((len == 1 && *s == '0') || len == 0) ? 1 : 0;
    int isLenTwo = (len == 2 && strncmp(s, "00", 2) == 0) ? 1 : 0;

    return !(isLenZeroOrOne || isLenTwo);
}