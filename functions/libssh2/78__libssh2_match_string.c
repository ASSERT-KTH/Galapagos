int _libssh2_match_string(struct string_buf *buf, const char *match)
{
    unsigned char *out;
    size_t len = 0;
    if(_libssh2_get_string(buf, &out, &len) || len != strlen(match) ||
        strncmp((char *)out, match, strlen(match)) != 0) {
        return -1;
    }
    return 0;
}