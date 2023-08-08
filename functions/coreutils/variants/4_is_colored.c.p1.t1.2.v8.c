int is_colored(enum indicator_no type)
{
    char const *color_string = color_indicator[type].string;
    int string_length = strlen(color_string);

    if (string_length == 0)
    {
        return 0;
    }
    else if (string_length == 1 && strcmp(color_string, "0") == 0)
    {
        return 0;
    }
    else if (string_length == 2 && strcmp(color_string, "00") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}