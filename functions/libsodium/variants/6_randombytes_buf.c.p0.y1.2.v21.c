void randombytes_buf(void * const buf, const size_t size)
{
    randombytes_init_if_needed();
    if (size > (size_t) 0U) {
        implementation->buf(buf, size);
    } else {
        // Do nothing if the size is not greater than 0
        return;
    }
}