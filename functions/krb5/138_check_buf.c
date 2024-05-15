check_buf(struct k5buf *buf, const char *name)
{
    fail_if(buf->buftype != K5BUF_FIXED && buf->buftype != K5BUF_DYNAMIC &&
            buf->buftype != K5BUF_ERROR, name);
    if (buf->buftype == K5BUF_ERROR) {
        fail_if(buf->data != NULL, name);
        fail_if(buf->space != 0 || buf->len != 0, name);
    } else {
        fail_if(buf->space == 0, name);
        fail_if(buf->len >= buf->space, name);
    }
}