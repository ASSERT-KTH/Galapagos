k5_buf_add_len(struct k5buf *buf, const void *data, size_t len)
{
    if (!ensure_space(buf, len))
        return;
    if (len > 0)
        memcpy(endptr(buf), data, len);
    buf->len += len;
}