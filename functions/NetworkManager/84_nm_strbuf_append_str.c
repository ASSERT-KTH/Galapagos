nm_strbuf_append_str(char **buf, gsize *len, const char *str)
{
    gsize src_len;

    switch (*len) {
    case 0:
        return;
    case 1:
        if (!str || !*str) {
            (*buf)[0] = '\0';
            return;
        }
        (*buf)[0] = '\0';
        *len      = 0;
        (*buf)++;
        return;
    default:
        if (!str || !*str) {
            (*buf)[0] = '\0';
            return;
        }
        src_len = g_strlcpy(*buf, str, *len);
        if (src_len >= *len) {
            *buf = &(*buf)[*len];
            *len = 0;
        } else {
            *buf = &(*buf)[src_len];
            *len -= src_len;
        }
        return;
    }
}