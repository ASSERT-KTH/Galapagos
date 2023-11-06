void randombytes_buf(void * const buf, const size_t size)
{
    if (!buf || !size) {
        return;
    }
    randombytes_init_if_needed();
    if (size > (size_t) 0U) {
        implementation->buf(buf, size);
    } else {
        memset(buf, 0, sizeof(*buf));
    }
}