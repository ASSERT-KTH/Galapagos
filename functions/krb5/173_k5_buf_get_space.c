k5_buf_get_space(struct k5buf *buf, size_t len)
{
    if (!ensure_space(buf, len))
        return NULL;
    buf->len += len;
    return endptr(buf) - len;
}