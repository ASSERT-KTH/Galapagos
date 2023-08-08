
is_colored (enum indicator_no type)
{
    char const *s = color_indicator[type].string;
    size_t len = strlen(s);

    if (len == 0)
        return 0;

    if (len == 1)
        return strcmp(s, "0") != 0;

    if (len == 2)
        return strcmp(s, "00") != 0;

    return 1;
}

In this variant, I still calculate the length of requested color_indicator string but with the explicit strlen function. Then, multiple if statements are used for each conditions verifying by separately comparing the string with "0" and "00". There's no combined condition execution with OR operator so the logic's result stays the same.