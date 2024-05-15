int _libssh2_copy_string(LIBSSH2_SESSION *session, struct string_buf *buf,
                         unsigned char **outbuf, size_t *outlen)
{
    size_t str_len;
    unsigned char *str;

    if(_libssh2_get_string(buf, &str, &str_len)) {
        return -1;
    }

    if(str_len) {
        *outbuf = LIBSSH2_ALLOC(session, str_len);
        if(*outbuf) {
            memcpy(*outbuf, str, str_len);
        }
        else {
            return -1;
        }
    }
    else {
        *outbuf = NULL;
    }

    if(outlen)
        *outlen = str_len;

    return 0;
}