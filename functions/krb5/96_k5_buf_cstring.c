k5_buf_cstring(struct k5buf *buf)
{
    if (!ensure_space(buf, 1))
        return NULL;
    *endptr(buf) = '\0';
    return buf->data;
}