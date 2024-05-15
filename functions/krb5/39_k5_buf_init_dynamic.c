k5_buf_init_dynamic(struct k5buf *buf)
{
    buf->buftype = K5BUF_DYNAMIC;
    buf->space = 128;
    buf->data = malloc(buf->space);
    if (buf->data == NULL) {
        set_error(buf);
        return;
    }
    buf->len = 0;
}