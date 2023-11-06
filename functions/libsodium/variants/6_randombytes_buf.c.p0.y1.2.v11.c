void randombytes_buf(void * const buf, const size_t size)
{
    if (!randombytes_is_initialized()) {
        randombytes_init();
    }
    if (size > 0U) {
        implementation->buf(buf, size);
    }
}