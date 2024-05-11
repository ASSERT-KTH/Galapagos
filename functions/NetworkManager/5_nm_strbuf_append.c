nm_strbuf_append(char **buf, gsize *len, const char *format, ...)
{
    char   *p = *buf;
    va_list args;
    int     retval;

    if (*len == 0)
        return;

    va_start(args, format);
    retval = g_vsnprintf(p, *len, format, args);
    va_end(args);

    if ((gsize) retval >= *len) {
        *buf = &p[*len];
        *len = 0;
    } else {
        *buf = &p[retval];
        *len -= retval;
    }
}