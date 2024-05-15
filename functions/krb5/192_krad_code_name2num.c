krad_code_name2num(const char *name)
{
    unsigned char i;

    for (i = 0; i < UCHAR_MAX; i++) {
        if (codes[i] == NULL)
            continue;

        if (strcmp(codes[i], name) == 0)
            return ++i;
    }

    return 0;
}