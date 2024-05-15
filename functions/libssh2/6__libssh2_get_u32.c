int _libssh2_get_u32(struct string_buf *buf, uint32_t *out)
{
    if(!_libssh2_check_length(buf, 4)) {
        return -1;
    }

    *out = _libssh2_ntohu32(buf->dataptr);
    buf->dataptr += 4;
    return 0;
}