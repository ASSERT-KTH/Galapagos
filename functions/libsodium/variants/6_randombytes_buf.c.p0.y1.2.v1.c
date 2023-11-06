void randombytes_buf(void *buf, size_t size)
{
    if (!randombytes_initialized) {
        randombytes_startup();
    }

    if (size != 0) {
        __implementation->buf(buf, size);
    }
}