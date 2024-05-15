krad_attr_name2num(const char *name)
{
    unsigned char i;

    for (i = 0; i < UCHAR_MAX; i++) {
        if (attributes[i].name == NULL)
            continue;

        if (strcmp(attributes[i].name, name) == 0)
            return i + 1;
    }

    return 0;
}