k5_buf_init_fixed(struct k5buf *buf, void *data, size_t space)
{
    assert(space > 0);
    buf->buftype = K5BUF_FIXED;
    buf->data = data;
    buf->space = space;
    buf->len = 0;
}