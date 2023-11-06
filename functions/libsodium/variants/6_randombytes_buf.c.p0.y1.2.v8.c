void randombytes_buf(void * const buf, const size_t size)
{
    if (!randombytes_is_initialised()) {
        randombytes_init();
    }
    if (size > 0) {
        implementation->buf(buf, size);
    }
}