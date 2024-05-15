int _libssh2_get_byte(struct string_buf *buf, unsigned char *out)
{
    if(!_libssh2_check_length(buf, 1)) {
        return -1;
    }

    *out = buf->dataptr[0];
    buf->dataptr += 1;
    return 0;
}