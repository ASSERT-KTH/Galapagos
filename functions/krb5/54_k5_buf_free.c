k5_buf_free(struct k5buf *buf)
{
    if (buf->buftype == K5BUF_ERROR)
        return;
    assert(buf->buftype == K5BUF_DYNAMIC || buf->buftype == K5BUF_DYNAMIC_ZAP);
    if (buf->buftype == K5BUF_DYNAMIC_ZAP)
        zap(buf->data, buf->len);
    free(buf->data);
    set_error(buf);
}