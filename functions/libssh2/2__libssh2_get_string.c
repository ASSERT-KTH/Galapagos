int _libssh2_get_string(struct string_buf *buf, unsigned char **outbuf,
                        size_t *outlen)
{
    uint32_t data_len;
    if(!buf || _libssh2_get_u32(buf, &data_len) != 0) {
        return -1;
    }
    if(!_libssh2_check_length(buf, data_len)) {
        return -1;
    }
    *outbuf = buf->dataptr;
    buf->dataptr += data_len;

    if(outlen)
        *outlen = (size_t)data_len;

    return 0;
}