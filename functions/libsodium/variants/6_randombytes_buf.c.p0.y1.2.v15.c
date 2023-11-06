void randombytes_buf(void * const buf, const size_t size)
{
    randombytes_init_if_needed();
    if (size != 0U) {
        implementation->buf(buf, size);
    }
}