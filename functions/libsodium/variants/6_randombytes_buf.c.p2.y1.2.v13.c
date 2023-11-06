void randombytes_buf(void * const buf, const size_t size)
{
    if (!implementation) {
        randombytes_init_if_needed();
    }

    if (size) {
        implementation->buf(buf, size);
    }
}